// SPDX-License-Identifier: LGPL-2.1-or-later

typedef struct _GtkWindow GtkWindow;

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/application.hxx>
#include <libmm/gtk/application_p.hxx>

#include <libmm/glib/vectorutils.hxx>

#include <clocale>
#include <gtk/gtk.h>
#include <libmm/gdk/wrap_init.hxx>
#include <libmm/gio/init.hxx>
#include <libmm/glib/init.hxx>
#include <libmm/gtk/window.hxx>
#include <libmm/gtk/wrap_init.hxx>
#include <libmm/pango/wrap_init.hxx>
#include <locale>
#include <stdexcept>

namespace
{

  static auto
  init_gtkmm_internals () -> void
  {
    static bool init_done = false;

    if (!init_done)
    {
      glib::init ();
      gio::init ();

      pango::wrap_init ();
      gdk::wrap_init ();
      gtk::wrap_init ();

      if (!glib::get_init_to_users_preferred_locale ())
        gtk_disable_setlocale ();

      init_done = true;
    }
  }

  static auto
  set_cxx_locale_to_c_locale () -> void
  {
    try
    {
      std::locale::global (std::locale (std::setlocale (LC_ALL, nullptr)));
    }
    catch (const std::runtime_error& ex)
    {
      g_warning ("Can't make the global C++ locale equal to the C locale.\n"
                 "   %s\n   C locale = %s\n",
                 ex.what (),
                 std::setlocale (LC_ALL, nullptr));
    }
  }

} // namespace

namespace gtk
{

  auto
  Application::custom_class_init () -> const glib::Class&
  {
    init_gtkmm_internals ();
    return application_class_.init ();
  }

  Application::Application (const glib::ustring& application_id,
                            gio::Application::Flags flags)
    : glib::ObjectBase (nullptr),
      gio::Application (
          glib::ConstructParams (custom_class_init (),
                                 "application_id",
                                 glib::c_str_or_nullptr (application_id),
                                 "flags",
                                 static_cast<GApplicationFlags> (flags),
                                 nullptr))
  {
    gtk_init ();
    set_cxx_locale_to_c_locale ();
  }

  auto
  Application::create (const glib::ustring& application_id,
                       gio::Application::Flags flags) -> glib::RefPtr<Application>
  {
    return glib::RefPtr<Application> (new Application (application_id, flags));
  }

  auto
  Application::run (int argc, char** argv) -> int
  {
    return gio::Application::run (argc, argv);
  }

  auto
  Application::run () -> int
  {
    return gio::Application::run (0, nullptr);
  }

  auto
  Application::set_accel_for_action (const glib::ustring& detailed_action_name,
                                     const glib::ustring& accel) -> void
  {
    std::vector<glib::ustring> vec;
    vec.push_back (accel);
    set_accels_for_action (detailed_action_name, vec);
  }

  auto
  Application::unset_accels_for_action (
      const glib::ustring& detailed_action_name) -> void
  {
    std::vector<glib::ustring> vec;
    set_accels_for_action (detailed_action_name, vec);
  }

} // namespace gtk

namespace
{

  static auto
  Application_signal_window_added_callback (GtkApplication* self,
                                            GtkWindow* p0,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Window*)>;

    auto obj = dynamic_cast<Application*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Application_signal_window_added_info = {
      "window-added",
      (GCallback) &Application_signal_window_added_callback,
      (GCallback) &Application_signal_window_added_callback};

  static auto
  Application_signal_window_removed_callback (GtkApplication* self,
                                              GtkWindow* p0,
                                              void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Window*)>;

    auto obj = dynamic_cast<Application*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Application_signal_window_removed_info = {
      "window-removed",
      (GCallback) &Application_signal_window_removed_callback,
      (GCallback) &Application_signal_window_removed_callback};

  static const glib::SignalProxyInfo Application_signal_query_end_info = {
      "query-end",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
glib::Value<gtk::Application::InhibitFlags>::value_type () -> GType
{
  return gtk_application_inhibit_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GtkApplication* object, bool take_copy) -> glib::RefPtr<gtk::Application>
  {
    return glib::make_refptr_for_instance<gtk::Application> (
        dynamic_cast<gtk::Application*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Application_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Application_Class::class_init_function;

      register_derived_type (gtk_application_get_type ());
    }

    return *this;
  }

  auto
  Application_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->window_added = &window_added_callback;
    klass->window_removed = &window_removed_callback;
  }

  auto
  Application_Class::window_added_callback (GtkApplication* self, GtkWindow* p0) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_window_added (glib::wrap (p0));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->window_added)
      (*base->window_added) (self, p0);
  }

  auto
  Application_Class::window_removed_callback (GtkApplication* self,
                                              GtkWindow* p0) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_window_removed (glib::wrap (p0));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->window_removed)
      (*base->window_removed) (self, p0);
  }

  auto
  Application_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Application ((GtkApplication*) object);
  }

  auto
  Application::gobj_copy () -> GtkApplication*
  {
    reference ();
    return gobj ();
  }

  Application::Application (const glib::ConstructParams& construct_params)
    : gio::Application (construct_params)
  {
  }

  Application::Application (GtkApplication* castitem)
    : gio::Application ((GApplication*) (castitem))
  {
  }

  Application::Application (Application&& src) noexcept
    : gio::Application (std::move (src))
  {
  }

  auto
  Application::operator= (Application&& src) noexcept -> Application&
  {
    gio::Application::operator= (std::move (src));
    return *this;
  }

  Application::~Application () noexcept {}

  Application::CppClassType Application::application_class_;

  auto
  Application::get_type () -> GType
  {
    return application_class_.init ().get_type ();
  }

  auto
  Application::get_base_type () -> GType
  {
    return gtk_application_get_type ();
  }

  auto
  Application::get_windows () -> std::vector<Window*>
  {
    return glib::ListHandler<Window*>::list_to_vector (
        gtk_application_get_windows (gobj ()),
        glib::OWNERSHIP_NONE);
  }

  auto
  Application::get_windows () const -> std::vector<const Window*>
  {
    return glib::ListHandler<const Window*>::list_to_vector (
        gtk_application_get_windows (const_cast<GtkApplication*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  Application::add_window (Window& window) -> void
  {
    gtk_application_add_window (gobj (), (window).gobj ());
  }

  auto
  Application::remove_window (Window& window) -> void
  {
    gtk_application_remove_window (gobj (), (window).gobj ());
  }

  auto
  Application::get_menubar () -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (gtk_application_get_menubar (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Application::get_menubar () const -> glib::RefPtr<const gio::MenuModel>
  {
    return const_cast<Application*> (this)->get_menubar ();
  }

  auto
  Application::set_menubar (const glib::RefPtr<gio::MenuModel>& menubar) -> void
  {
    gtk_application_set_menubar (gobj (), glib::unwrap (menubar));
  }

  auto
  Application::inhibit (Window& window,
                        InhibitFlags flags,
                        const glib::ustring& reason) -> guint
  {
    return gtk_application_inhibit (
        gobj (),
        (window).gobj (),
        static_cast<GtkApplicationInhibitFlags> (flags),
        reason.c_str ());
  }

  auto
  Application::uninhibit (guint cookie) -> void
  {
    gtk_application_uninhibit (gobj (), cookie);
  }

  auto
  Application::get_window_by_id (guint id) -> Window*
  {
    auto retvalue = glib::wrap (gtk_application_get_window_by_id (gobj (), id));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Application::get_window_by_id (guint id) const -> const Window*
  {
    return const_cast<Application*> (this)->get_window_by_id (id);
  }

  auto
  Application::get_active_window () -> Window*
  {
    auto retvalue = glib::wrap (gtk_application_get_active_window (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Application::get_active_window () const -> const Window*
  {
    return const_cast<Application*> (this)->get_active_window ();
  }

  auto
  Application::list_action_descriptions () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gtk_application_list_action_descriptions (
            const_cast<GtkApplication*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Application::get_accels_for_action (const glib::ustring& detailed_action_name)
      const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gtk_application_get_accels_for_action (
            const_cast<GtkApplication*> (gobj ()),
            detailed_action_name.c_str ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Application::get_actions_for_accel (const glib::ustring& accel) const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gtk_application_get_actions_for_accel (
            const_cast<GtkApplication*> (gobj ()),
            accel.c_str ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Application::set_accels_for_action (const glib::ustring& detailed_action_name,
                                      const std::vector<glib::ustring>& accels) -> void
  {
    gtk_application_set_accels_for_action (
        gobj (),
        detailed_action_name.c_str (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (accels).data ());
  }

  auto
  Application::get_menu_by_id (const glib::ustring& id) -> glib::RefPtr<gio::Menu>
  {
    auto retvalue =
        glib::wrap (gtk_application_get_menu_by_id (gobj (), id.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Application::get_menu_by_id (const glib::ustring& id) const -> glib::RefPtr<const gio::Menu>
  {
    return const_cast<Application*> (this)->get_menu_by_id (id);
  }

  auto
  Application::signal_window_added () -> glib::SignalProxy<void (Window*)>
  {
    return glib::SignalProxy<void (Window*)> (
        this,
        &Application_signal_window_added_info);
  }

  auto
  Application::signal_window_removed () -> glib::SignalProxy<void (Window*)>
  {
    return glib::SignalProxy<void (Window*)> (
        this,
        &Application_signal_window_removed_info);
  }

  auto
  Application::signal_query_end () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &Application_signal_query_end_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Application::property_menubar () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this, "menubar");
  }

  auto
  Application::property_menubar () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "menubar");
  }

  auto
  Application::property_register_session () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "register-session");
  }

  auto
  Application::property_register_session () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "register-session");
  }

  auto
  Application::property_screensaver_active () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "screensaver-active");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Window*>::value,
      "Type Window* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Application::property_active_window () const -> glib::PropertyProxy_ReadOnly<Window*>
  {
    return glib::PropertyProxy_ReadOnly<Window*> (this, "active-window");
  }

  auto
  gtk::Application::on_window_added (Window* window) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->window_added)
      (*base->window_added) (gobj (), (GtkWindow*) glib::unwrap (window));
  }

  auto
  gtk::Application::on_window_removed (Window* window) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->window_removed)
      (*base->window_removed) (gobj (), (GtkWindow*) glib::unwrap (window));
  }

} // namespace gtk
