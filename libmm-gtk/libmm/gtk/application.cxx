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
      Glib::init ();
      Gio::init ();

      Pango::wrap_init ();
      Gdk::wrap_init ();
      Gtk::wrap_init ();

      if (!Glib::get_init_to_users_preferred_locale ())
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

namespace Gtk
{

  auto
  Application::custom_class_init () -> const Glib::Class&
  {
    init_gtkmm_internals ();
    return application_class_.init ();
  }

  Application::Application (const Glib::ustring& application_id,
                            Gio::Application::Flags flags)
    : Glib::ObjectBase (nullptr),
      Gio::Application (
          Glib::ConstructParams (custom_class_init (),
                                 "application_id",
                                 Glib::c_str_or_nullptr (application_id),
                                 "flags",
                                 static_cast<GApplicationFlags> (flags),
                                 nullptr))
  {
    gtk_init ();
    set_cxx_locale_to_c_locale ();
  }

  auto
  Application::create (const Glib::ustring& application_id,
                       Gio::Application::Flags flags) -> Glib::RefPtr<Application>
  {
    return Glib::RefPtr<Application> (new Application (application_id, flags));
  }

  auto
  Application::run (int argc, char** argv) -> int
  {
    return Gio::Application::run (argc, argv);
  }

  auto
  Application::run () -> int
  {
    return Gio::Application::run (0, nullptr);
  }

  auto
  Application::set_accel_for_action (const Glib::ustring& detailed_action_name,
                                     const Glib::ustring& accel) -> void
  {
    std::vector<Glib::ustring> vec;
    vec.push_back (accel);
    set_accels_for_action (detailed_action_name, vec);
  }

  auto
  Application::unset_accels_for_action (
      const Glib::ustring& detailed_action_name) -> void
  {
    std::vector<Glib::ustring> vec;
    set_accels_for_action (detailed_action_name, vec);
  }

} // namespace Gtk

namespace
{

  static auto
  Application_signal_window_added_callback (GtkApplication* self,
                                            GtkWindow* p0,
                                            void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Window*)>;

    auto obj = dynamic_cast<Application*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Application_signal_window_added_info = {
      "window-added",
      (GCallback) &Application_signal_window_added_callback,
      (GCallback) &Application_signal_window_added_callback};

  static auto
  Application_signal_window_removed_callback (GtkApplication* self,
                                              GtkWindow* p0,
                                              void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Window*)>;

    auto obj = dynamic_cast<Application*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Application_signal_window_removed_info = {
      "window-removed",
      (GCallback) &Application_signal_window_removed_callback,
      (GCallback) &Application_signal_window_removed_callback};

  static const Glib::SignalProxyInfo Application_signal_query_end_info = {
      "query-end",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
Glib::Value<Gtk::Application::InhibitFlags>::value_type () -> GType
{
  return gtk_application_inhibit_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkApplication* object, bool take_copy) -> Glib::RefPtr<Gtk::Application>
  {
    return Glib::make_refptr_for_instance<Gtk::Application> (
        dynamic_cast<Gtk::Application*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Application_Class::init () -> const Glib::Class&
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_window_added (Glib::wrap (p0));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_window_removed (Glib::wrap (p0));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->window_removed)
      (*base->window_removed) (self, p0);
  }

  auto
  Application_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Application ((GtkApplication*) object);
  }

  auto
  Application::gobj_copy () -> GtkApplication*
  {
    reference ();
    return gobj ();
  }

  Application::Application (const Glib::ConstructParams& construct_params)
    : Gio::Application (construct_params)
  {
  }

  Application::Application (GtkApplication* castitem)
    : Gio::Application ((GApplication*) (castitem))
  {
  }

  Application::Application (Application&& src) noexcept
    : Gio::Application (std::move (src))
  {
  }

  auto
  Application::operator= (Application&& src) noexcept -> Application&
  {
    Gio::Application::operator= (std::move (src));
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
    return Glib::ListHandler<Window*>::list_to_vector (
        gtk_application_get_windows (gobj ()),
        Glib::OWNERSHIP_NONE);
  }

  auto
  Application::get_windows () const -> std::vector<const Window*>
  {
    return Glib::ListHandler<const Window*>::list_to_vector (
        gtk_application_get_windows (const_cast<GtkApplication*> (gobj ())),
        Glib::OWNERSHIP_NONE);
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
  Application::get_menubar () -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (gtk_application_get_menubar (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Application::get_menubar () const -> Glib::RefPtr<const Gio::MenuModel>
  {
    return const_cast<Application*> (this)->get_menubar ();
  }

  auto
  Application::set_menubar (const Glib::RefPtr<Gio::MenuModel>& menubar) -> void
  {
    gtk_application_set_menubar (gobj (), Glib::unwrap (menubar));
  }

  auto
  Application::inhibit (Window& window,
                        InhibitFlags flags,
                        const Glib::ustring& reason) -> guint
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
    auto retvalue = Glib::wrap (gtk_application_get_window_by_id (gobj (), id));
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
    auto retvalue = Glib::wrap (gtk_application_get_active_window (gobj ()));
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
  Application::list_action_descriptions () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        gtk_application_list_action_descriptions (
            const_cast<GtkApplication*> (gobj ())),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  Application::get_accels_for_action (const Glib::ustring& detailed_action_name)
      const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        gtk_application_get_accels_for_action (
            const_cast<GtkApplication*> (gobj ()),
            detailed_action_name.c_str ()),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  Application::get_actions_for_accel (const Glib::ustring& accel) const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        gtk_application_get_actions_for_accel (
            const_cast<GtkApplication*> (gobj ()),
            accel.c_str ()),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  Application::set_accels_for_action (const Glib::ustring& detailed_action_name,
                                      const std::vector<Glib::ustring>& accels) -> void
  {
    gtk_application_set_accels_for_action (
        gobj (),
        detailed_action_name.c_str (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (accels).data ());
  }

  auto
  Application::get_menu_by_id (const Glib::ustring& id) -> Glib::RefPtr<Gio::Menu>
  {
    auto retvalue =
        Glib::wrap (gtk_application_get_menu_by_id (gobj (), id.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Application::get_menu_by_id (const Glib::ustring& id) const -> Glib::RefPtr<const Gio::Menu>
  {
    return const_cast<Application*> (this)->get_menu_by_id (id);
  }

  auto
  Application::signal_window_added () -> Glib::SignalProxy<void (Window*)>
  {
    return Glib::SignalProxy<void (Window*)> (
        this,
        &Application_signal_window_added_info);
  }

  auto
  Application::signal_window_removed () -> Glib::SignalProxy<void (Window*)>
  {
    return Glib::SignalProxy<void (Window*)> (
        this,
        &Application_signal_window_removed_info);
  }

  auto
  Application::signal_query_end () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &Application_signal_query_end_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Application::property_menubar () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>> (this, "menubar");
  }

  auto
  Application::property_menubar () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>> (
        this,
        "menubar");
  }

  auto
  Application::property_register_session () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "register-session");
  }

  auto
  Application::property_register_session () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "register-session");
  }

  auto
  Application::property_screensaver_active () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "screensaver-active");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Window*>::value,
      "Type Window* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Application::property_active_window () const -> Glib::PropertyProxy_ReadOnly<Window*>
  {
    return Glib::PropertyProxy_ReadOnly<Window*> (this, "active-window");
  }

  auto
  Gtk::Application::on_window_added (Window* window) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->window_added)
      (*base->window_added) (gobj (), (GtkWindow*) Glib::unwrap (window));
  }

  auto
  Gtk::Application::on_window_removed (Window* window) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->window_removed)
      (*base->window_removed) (gobj (), (GtkWindow*) Glib::unwrap (window));
  }

} // namespace Gtk
