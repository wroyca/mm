// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/window.hxx>
#include <libmm/gtk/window_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gdk/monitor.hxx>
#include <libmm/gio/listmodel.hxx>
#include <libmm/glib/vectorutils.hxx>
#include <libmm/gtk/application.hxx>

namespace gtk
{

  Window::Window (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
    signal_hide ().connect (sigc::mem_fun (*this, &Window::on_window_hide));
  }

  Window::Window (GtkWindow* castitem)
    : gtk::Widget ((GtkWidget*) castitem)
  {
    signal_hide ().connect (sigc::mem_fun (*this, &Window::on_window_hide));
  }

  Window::Window (Window&& src) noexcept
    : gtk::Widget (std::move (src)),
      Native (std::move (src)),
      Root (std::move (src))
  {
    try
    {
      signal_hide ().connect (sigc::mem_fun (*this, &Window::on_window_hide));
    }
    catch (...)
    {
    }
  }

  auto
  Window::operator= (Window&& src) noexcept -> Window&
  {
    gtk::Widget::operator= (std::move (src));
    Native::operator= (std::move (src));
    Root::operator= (std::move (src));
    return *this;
  }

  Window::Window ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (window_class_.init ()))
  {
    signal_hide ().connect (sigc::mem_fun (*this, &Window::on_window_hide));
  }

  auto
  Window::on_window_hide () -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("gtk::Window::on_window_hide() gobject_=%p\n", (void*) gobject_);
#endif

    auto appl = get_application ();
    if (appl)
    {
#ifdef GLIBMM_DEBUG_REFCOUNTING
      g_warning ("gtk::Window::on_window_hide(): before remove_window().");
#endif

      appl->remove_window (*this);
    }
  }

  auto
  Window::set_manage () -> void
  {
    referenced_ = false;
  }

  auto
  Window::destroy_ () -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("gtk::Window::destroy_(): gobject_: %p\n", (void*) gobject_);
    if (gobject_)
      g_warning ("  gtypename: %s\n", G_OBJECT_TYPE_NAME (gobject_));
#endif

    if (!cpp_destruction_in_progress_)
    {
      cpp_destruction_in_progress_ = true;

      _release_c_instance ();
    }
  }

  auto
  Window::_release_c_instance () -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("gtk::Window::_release_c_instance() gobject_=%p\n",
               (void*) gobject_);
#endif

    cpp_destruction_in_progress_ = true;

    if (gobj ())
    {
      gtk_window_destroy (gobj ());

      disconnect_cpp_wrapper ();
    }
  }

  auto
  Window_Class::dispose_vfunc_callback (GObject* self) -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Window_Class::dispose_vfunc_callback(): gobject_: %p\n",
               (void*) self);
#endif

    const auto obj =
        dynamic_cast<Widget*> (glib::ObjectBase::_get_current_wrapper (self));

    if (obj && !obj->_cpp_destruction_is_in_progress ())
    {
      const auto pWidget = obj->gobj ();
      g_return_if_fail (pWidget == GTK_WIDGET (self));

#ifdef GLIBMM_DEBUG_REFCOUNTING
      g_warning ("Window_Class::dispose_vfunc_callback(): before "
                 "gtk_widget_set_visible(pWidget, false).");
#endif

      const auto win = dynamic_cast<Window*> (obj);
      if (win)
        win->on_window_hide ();

      gtk_widget_set_visible (pWidget, false);

#ifdef GLIBMM_DEBUG_REFCOUNTING
      g_warning ("Window_Class::dispose_vfunc_callback(): after "
                 "gtk_widget_set_visible(pWidget, false).");
#endif
    }

    const auto base = static_cast<GObjectClass*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Window_Class::dispose_vfunc_callback(): before calling "
               "base->dispose.");
#endif

    if (base->dispose)
      (*base->dispose) (self);

#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning (
        "Window_Class::dispose_vfunc_callback(): after calling base->dispose.");
#endif
  }

  auto
  Window::destroy () -> void
  {
    if (gobj ())
      gtk_window_destroy (gobj ());
  }

  auto
  Window::unset_focus () -> void
  {
    gtk_window_set_focus (gobj (), nullptr);
  }

  auto
  Window::unset_default_widget () -> void
  {
    gtk_window_set_default_widget (gobj (), nullptr);
  }

  auto
  Window::unset_transient_for () -> void
  {
    gtk_window_set_transient_for (gobj (), nullptr);
  }

  auto
  Window::unset_child () -> void
  {
    gtk_window_set_child (gobj (), nullptr);
  }

  auto
  Window::unset_application () -> void
  {
    gtk_window_set_application (gobj (), nullptr);
  }

  auto
  Window::unset_titlebar () -> void
  {
    gtk_window_set_titlebar (gobj (), nullptr);
  }

} // namespace gtk

namespace
{

#ifndef GTKMM_DISABLE_DEPRECATED

  static const glib::SignalProxyInfo Window_signal_keys_changed_info = {
      "keys_changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

#endif

  static auto
  Window_signal_close_request_callback (GtkWindow* self, void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool ()>;

    auto obj = dynamic_cast<Window*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) ());
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  Window_signal_close_request_notify_callback (GtkWindow* self, void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void ()>;

    auto obj = dynamic_cast<Window*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo Window_signal_close_request_info = {
      "close-request",
      (GCallback) &Window_signal_close_request_callback,
      (GCallback) &Window_signal_close_request_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkWindow* object, bool take_copy) -> gtk::Window*
  {
    return dynamic_cast<gtk::Window*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Window_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Window_Class::class_init_function;

      register_derived_type (gtk_window_get_type ());

      Native::add_interface (get_type ());
      ShortcutManager::add_interface (get_type ());
      Root::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Window_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    reinterpret_cast<GObjectClass*> (klass)->dispose = &dispose_vfunc_callback;

#ifndef GTKMM_DISABLE_DEPRECATED

    klass->keys_changed = &keys_changed_callback;
#endif

    klass->close_request = &close_request_callback;
  }

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  Window_Class::keys_changed_callback (GtkWindow* self) -> void
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
          obj->on_keys_changed ();
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

    if (base && base->keys_changed)
      (*base->keys_changed) (self);
  }
#endif

  auto
  Window_Class::close_request_callback (GtkWindow* self) -> gboolean
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
          return static_cast<int> (obj->on_close_request ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->close_request)
      return (*base->close_request) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  Window_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new Window ((GtkWindow*) (o));
  }

  Window::~Window () noexcept
  {
    destroy_ ();
  }

  Window::CppClassType Window::window_class_;

  auto
  Window::get_type () -> GType
  {
    return window_class_.init ().get_type ();
  }

  auto
  Window::get_base_type () -> GType
  {
    return gtk_window_get_type ();
  }

  auto
  Window::set_title (const glib::ustring& title) -> void
  {
    gtk_window_set_title (gobj (), title.c_str ());
  }

  auto
  Window::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_window_get_title (const_cast<GtkWindow*> (gobj ())));
  }

  auto
  Window::set_startup_id (const glib::ustring& startup_id) -> void
  {
    gtk_window_set_startup_id (gobj (), startup_id.c_str ());
  }

  auto
  Window::set_focus (gtk::Widget& focus) -> void
  {
    gtk_window_set_focus (gobj (), (focus).gobj ());
  }

  auto
  Window::get_focus () -> Widget*
  {
    return glib::wrap (gtk_window_get_focus (gobj ()));
  }

  auto
  Window::get_focus () const -> const Widget*
  {
    return const_cast<Window*> (this)->get_focus ();
  }

  auto
  Window::set_default_widget (gtk::Widget& default_widget) -> void
  {
    gtk_window_set_default_widget (gobj (), (default_widget).gobj ());
  }

  auto
  Window::get_default_widget () -> Widget*
  {
    return glib::wrap (gtk_window_get_default_widget (gobj ()));
  }

  auto
  Window::get_default_widget () const -> const Widget*
  {
    return const_cast<Window*> (this)->get_default_widget ();
  }

  auto
  Window::set_transient_for (Window& parent) -> void
  {
    gtk_window_set_transient_for (gobj (), (parent).gobj ());
  }

  auto
  Window::get_transient_for () -> Window*
  {
    return glib::wrap (gtk_window_get_transient_for (gobj ()));
  }

  auto
  Window::get_transient_for () const -> const Window*
  {
    return const_cast<Window*> (this)->get_transient_for ();
  }

  auto
  Window::set_destroy_with_parent (bool setting) -> void
  {
    gtk_window_set_destroy_with_parent (gobj (), static_cast<int> (setting));
  }

  auto
  Window::get_destroy_with_parent () const -> bool
  {
    return gtk_window_get_destroy_with_parent (
        const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::set_hide_on_close (bool setting) -> void
  {
    gtk_window_set_hide_on_close (gobj (), static_cast<int> (setting));
  }

  auto
  Window::get_hide_on_close () const -> bool
  {
    return gtk_window_get_hide_on_close (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::set_mnemonics_visible (bool setting) -> void
  {
    gtk_window_set_mnemonics_visible (gobj (), static_cast<int> (setting));
  }

  auto
  Window::get_mnemonics_visible () const -> bool
  {
    return gtk_window_get_mnemonics_visible (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::set_focus_visible (bool setting) -> void
  {
    gtk_window_set_focus_visible (gobj (), static_cast<int> (setting));
  }

  auto
  Window::get_focus_visible () const -> bool
  {
    return gtk_window_get_focus_visible (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::set_resizable (bool resizable) -> void
  {
    gtk_window_set_resizable (gobj (), static_cast<int> (resizable));
  }

  auto
  Window::get_resizable () const -> bool
  {
    return gtk_window_get_resizable (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::set_display (const glib::RefPtr<gdk::Display>& display) -> void
  {
    gtk_window_set_display (gobj (), glib::unwrap (display));
  }

  auto
  Window::is_active () const -> bool
  {
    return gtk_window_is_active (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::set_decorated (bool setting) -> void
  {
    gtk_window_set_decorated (gobj (), static_cast<int> (setting));
  }

  auto
  Window::get_decorated () const -> bool
  {
    return gtk_window_get_decorated (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::set_deletable (bool setting) -> void
  {
    gtk_window_set_deletable (gobj (), static_cast<int> (setting));
  }

  auto
  Window::get_deletable () const -> bool
  {
    return gtk_window_get_deletable (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::set_icon_name (const glib::ustring& name) -> void
  {
    gtk_window_set_icon_name (gobj (), name.c_str ());
  }

  auto
  Window::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_window_get_icon_name (const_cast<GtkWindow*> (gobj ())));
  }

  auto
  Window::set_default_icon_name (const glib::ustring& name) -> void
  {
    gtk_window_set_default_icon_name (name.c_str ());
  }

  auto
  Window::get_default_icon_name () -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_window_get_default_icon_name ());
  }

  auto
  Window::set_auto_startup_notification (bool setting) -> void
  {
    gtk_window_set_auto_startup_notification (static_cast<int> (setting));
  }

  auto
  Window::set_modal (bool modal) -> void
  {
    gtk_window_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  Window::get_modal () const -> bool
  {
    return gtk_window_get_modal (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::get_toplevels () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_window_get_toplevels ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Window::list_toplevels () -> std::vector<Window*>
  {
    return glib::ListHandler<Window*>::list_to_vector (
        gtk_window_list_toplevels (),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Window::present () -> void
  {
    gtk_window_present (gobj ());
  }

  auto
  Window::present (guint32 timestamp) -> void
  {
    gtk_window_present_with_time (gobj (), timestamp);
  }

  auto
  Window::minimize () -> void
  {
    gtk_window_minimize (gobj ());
  }

  auto
  Window::unminimize () -> void
  {
    gtk_window_unminimize (gobj ());
  }

  auto
  Window::maximize () -> void
  {
    gtk_window_maximize (gobj ());
  }

  auto
  Window::unmaximize () -> void
  {
    gtk_window_unmaximize (gobj ());
  }

  auto
  Window::fullscreen () -> void
  {
    gtk_window_fullscreen (gobj ());
  }

  auto
  Window::unfullscreen () -> void
  {
    gtk_window_unfullscreen (gobj ());
  }

  auto
  Window::fullscreen_on_monitor (const glib::RefPtr<gdk::Monitor>& monitor) -> void
  {
    gtk_window_fullscreen_on_monitor (gobj (), glib::unwrap (monitor));
  }

  auto
  Window::close () -> void
  {
    gtk_window_close (gobj ());
  }

  auto
  Window::set_default_size (int width, int height) -> void
  {
    gtk_window_set_default_size (gobj (), width, height);
  }

  auto
  Window::get_default_size (int& width, int& height) const -> void
  {
    gtk_window_get_default_size (const_cast<GtkWindow*> (gobj ()),
                                 &(width),
                                 &(height));
  }

  auto
  Window::get_group () -> glib::RefPtr<WindowGroup>
  {
    auto retvalue = glib::wrap (gtk_window_get_group (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Window::get_group () const -> glib::RefPtr<const WindowGroup>
  {
    return const_cast<Window*> (this)->get_group ();
  }

  auto
  Window::has_group () const -> bool
  {
    return gtk_window_has_group (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::get_application () -> glib::RefPtr<Application>
  {
    auto retvalue = glib::wrap (gtk_window_get_application (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Window::get_application () const -> glib::RefPtr<const Application>
  {
    auto retvalue = glib::wrap (
        gtk_window_get_application (const_cast<GtkWindow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Window::set_application (const glib::RefPtr<Application>& application) -> void
  {
    gtk_window_set_application (gobj (), glib::unwrap (application));
  }

  auto
  Window::set_child (Widget& child) -> void
  {
    gtk_window_set_child (gobj (), (child).gobj ());
  }

  auto
  Window::get_child () -> Widget*
  {
    return glib::wrap (gtk_window_get_child (gobj ()));
  }

  auto
  Window::get_child () const -> const Widget*
  {
    return const_cast<Window*> (this)->get_child ();
  }

  auto
  Window::set_titlebar (Widget& titlebar) -> void
  {
    gtk_window_set_titlebar (gobj (), (titlebar).gobj ());
  }

  auto
  Window::get_titlebar () -> Widget*
  {
    return glib::wrap (gtk_window_get_titlebar (gobj ()));
  }

  auto
  Window::get_titlebar () const -> const Widget*
  {
    return const_cast<Window*> (this)->get_titlebar ();
  }

  auto
  Window::is_maximized () const -> bool
  {
    return gtk_window_is_maximized (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::is_fullscreen () const -> bool
  {
    return gtk_window_is_fullscreen (const_cast<GtkWindow*> (gobj ()));
  }

  auto
  Window::set_handle_menubar_accel (bool handle_menubar_accel) -> void
  {
    gtk_window_set_handle_menubar_accel (
        gobj (),
        static_cast<int> (handle_menubar_accel));
  }

  auto
  Window::get_handle_menubar_accel () const -> bool
  {
    return gtk_window_get_handle_menubar_accel (
        const_cast<GtkWindow*> (gobj ()));
  }

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  Window::signal_keys_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Window_signal_keys_changed_info);
  }
#endif

  auto
  Window::signal_close_request () -> glib::SignalProxy<bool ()>
  {
    return glib::SignalProxy<bool ()> (this, &Window_signal_close_request_info);
  }

  auto
  Window::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  Window::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  Window::property_startup_id () -> glib::PropertyProxy_WriteOnly<glib::ustring>
  {
    return glib::PropertyProxy_WriteOnly<glib::ustring> (this, "startup-id");
  }

  auto
  Window::property_resizable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "resizable");
  }

  auto
  Window::property_resizable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "resizable");
  }

  auto
  Window::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  Window::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  Window::property_default_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "default-width");
  }

  auto
  Window::property_default_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "default-width");
  }

  auto
  Window::property_default_height () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "default-height");
  }

  auto
  Window::property_default_height () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "default-height");
  }

  auto
  Window::property_destroy_with_parent () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "destroy-with-parent");
  }

  auto
  Window::property_destroy_with_parent () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "destroy-with-parent");
  }

  auto
  Window::property_hide_on_close () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "hide-on-close");
  }

  auto
  Window::property_hide_on_close () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "hide-on-close");
  }

  auto
  Window::property_mnemonics_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "mnemonics-visible");
  }

  auto
  Window::property_mnemonics_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "mnemonics-visible");
  }

  auto
  Window::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "icon-name");
  }

  auto
  Window::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Display>>::value,
      "Type glib::RefPtr<gdk::Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Window::property_display () -> glib::PropertyProxy<glib::RefPtr<gdk::Display>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Display>> (this, "display");
  }

  auto
  Window::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>> (this,
                                                                     "display");
  }

  auto
  Window::property_is_active () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "is-active");
  }

  auto
  Window::property_decorated () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "decorated");
  }

  auto
  Window::property_decorated () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "decorated");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Window*>::value,
      "Type Window* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Window::property_transient_for () -> glib::PropertyProxy<Window*>
  {
    return glib::PropertyProxy<Window*> (this, "transient-for");
  }

  auto
  Window::property_transient_for () const -> glib::PropertyProxy_ReadOnly<Window*>
  {
    return glib::PropertyProxy_ReadOnly<Window*> (this, "transient-for");
  }

  auto
  Window::property_deletable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "deletable");
  }

  auto
  Window::property_deletable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "deletable");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Application>>::value,
      "Type glib::RefPtr<Application> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Window::property_application () -> glib::PropertyProxy<glib::RefPtr<Application>>
  {
    return glib::PropertyProxy<glib::RefPtr<Application>> (this, "application");
  }

  auto
  Window::property_application () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Application>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Application>> (
        this,
        "application");
  }

  auto
  Window::property_focus_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "focus-visible");
  }

  auto
  Window::property_focus_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "focus-visible");
  }

  auto
  Window::property_maximized () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "maximized");
  }

  auto
  Window::property_maximized () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "maximized");
  }

  auto
  Window::property_fullscreened () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "fullscreened");
  }

  auto
  Window::property_fullscreened () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "fullscreened");
  }

  auto
  Window::property_default_widget () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "default-widget");
  }

  auto
  Window::property_default_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "default-widget");
  }

  auto
  Window::property_focus_widget () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "focus-widget");
  }

  auto
  Window::property_focus_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "focus-widget");
  }

  auto
  Window::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  Window::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  Window::property_titlebar () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "titlebar");
  }

  auto
  Window::property_titlebar () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "titlebar");
  }

  auto
  Window::property_handle_menubar_accel () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "handle-menubar-accel");
  }

  auto
  Window::property_handle_menubar_accel () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "handle-menubar-accel");
  }

  auto
  gtk::Window::on_keys_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->keys_changed)
      (*base->keys_changed) (gobj ());
  }

  auto
  gtk::Window::on_close_request () -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->close_request)
      return (*base->close_request) (gobj ());

    using RType = bool;
    return RType ();
  }

} // namespace gtk
