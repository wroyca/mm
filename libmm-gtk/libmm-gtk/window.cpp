


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/window.hpp>
#include <libmm-gtk/window_p.hpp>


/*
 * Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-glib/vectorutils.hpp>
#include <libmm-gio/listmodel.hpp>
#include <libmm-gdk/monitor.hpp>
#include <libmm-gtk/application.hpp>
#include <gtk/gtk.h>

namespace Gtk
{

// All constructors are hand-coded, because they connect a signal handler
// that removes the window from its application when the window is closed (hidden).
Window::Window(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  signal_hide().connect(mem_fun(*this, &Window::on_window_hide));
}

Window::Window(GtkWindow* castitem)
: Widget((GtkWidget*)castitem)
{
  signal_hide().connect(mem_fun(*this, &Window::on_window_hide));
}

Window::Window(Window&& src) noexcept
: Widget(std::move(src))
  , Native(std::move(src))
  , Root(std::move(src))
{
  try
  {
    signal_hide().connect(mem_fun(*this, &Window::on_window_hide));
  }
  catch (...)
  {
    // Ignore exceptions.
    // The move ctor shall be noexcept. It can be called from a move ctor
    // in a subclass, such as Gtk::Dialog.
  }
}

// The move assignment is identical to the one that gmmproc can generate.
// _CUSTOM_MOVE_OPERATIONS() suppresses both move contructor and move assignment.
auto Window::operator=(Window&& src) noexcept -> Window&
{
  Widget::operator=(std::move(src));
  Native::operator=(std::move(src));
  Root::operator=(std::move(src));
  return *this;
}

Window::Window()
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(window_class_.init()))
{
  signal_hide().connect(mem_fun(*this, &Window::on_window_hide));
}

auto Window::on_window_hide () -> void
{
  #ifdef GLIBMM_DEBUG_REFCOUNTING
  g_warning("Gtk::Window::on_window_hide() gobject_=%p\n", (void*) gobject_);
  #endif

  const auto appl = get_application();
  if (appl)
  {
    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Gtk::Window::on_window_hide(): before remove_window().");
    #endif

    // Tell GtkApplication to forget the window.
    // This can cause Application::run() to return, if it is the last window.
    // Otherwise, GtkApplication waits for the window to be _destroyed_,
    // which is just not something that it should care about.
    // See https://bugzilla.gnome.org/show_bug.cgi?id=639931
    appl->remove_window(*this);
  }
}

auto Window::set_manage () -> void
{
  // This C++ wrapper is deleted by Gtk::Object::destroy_notify_() when the
  // underlying C instance is destroyed.
  referenced_ = false; // Managed
}

auto Window::destroy_ () -> void
{
  //Called from destructors.
  //overridden so that the correct _release_c_instance() ends up being called by the destructor.
  //The destructors that call destroy_() are virtual, but _release_c_instance() is not.

  //GTKMM_LIFECYCLE

  #ifdef GLIBMM_DEBUG_REFCOUNTING
  g_warning("Gtk::Window::destroy_(): gobject_: %p\n", (void*) gobject_);
  if(gobject_)
   g_warning("  gtypename: %s\n", G_OBJECT_TYPE_NAME(gobject_));
  #endif

  if ( !cpp_destruction_in_progress_ )
  {
    cpp_destruction_in_progress_ = true;

    //destroy the C instance:
    _release_c_instance();
  }

  //The C++ destructor will be reached later. This function was called by a destructor.
}

auto Window::_release_c_instance () -> void
{
  //We override this, (though it's not virtual - we just call it from this class),
  //because top-level windows can only be destroyed with gtk_window_destroy, according to Owen Taylor. murrayc.
  #ifdef GLIBMM_DEBUG_REFCOUNTING
  g_warning("Gtk::Window::_release_c_instance() gobject_=%p\n", (void*) gobject_);
  #endif

  cpp_destruction_in_progress_ = true;

  // remove our hook.
  if (gobj())
  {
    //Windows can not be unrefed. They are "self-owning".
    gtk_window_destroy(gobj());

    //If the GObject still exists, disconnect the C++ wrapper from it.
    //The C++ wrapper is being deleted right now.
    disconnect_cpp_wrapper();

    //Glib::Object::~Object() will not g_object_unref() it too, because gobject_ is now 0.
  }
}

auto Window_Class::dispose_vfunc_callback (GObject *self) -> void
{
  #ifdef GLIBMM_DEBUG_REFCOUNTING
  g_warning("Window_Class::dispose_vfunc_callback(): gobject_: %p\n", (void*)self);
  #endif

  const auto obj = dynamic_cast<Widget*>(
      Glib::ObjectBase::_get_current_wrapper(self));

  // This function might be invoked recursively because we're triggering
  // several signal emissions, particularly signal_hide().  Therefore we
  // have to test for cpp_destruction_in_progress_ at this point.

  if(obj && !obj->_cpp_destruction_is_in_progress()) //When it should really be destroyed, we zero gobj_.
  {
    const auto pWidget = obj->gobj();
    g_return_if_fail(pWidget == GTK_WIDGET(self));

    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Window_Class::dispose_vfunc_callback(): before gtk_widget_hide().");
    #endif

    // The window may have been hidden with a call to the static (i.e. private)
    // gtk_window_hide(), which does not send the "hide" signal.
    // In that case gtk_widget_hide() has no effect, and on_window_hide()
    // won't be called indirectly from gtk_widget_hide().
    const auto win = dynamic_cast<Window*>(obj);
    if (win)
      win->on_window_hide();

    // Now hide the widget.  The C++ object must _not_ be accessed anymore
    // after this call, because a signal_hide() handler might delete it.
    gtk_widget_hide(pWidget);

    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Window_Class::dispose_vfunc_callback(): after gtk_widget_hide().");
    #endif
  }

  // The "dispose" vfunc in GtkWindow does much more in gtk4 than in gtk3.
  // It would be difficult to make the deletion of windows work without letting
  // the gtk4 dispose vfunc do its job. /Kjell 2020-05-19
  // GTKMM_LIFECYCLE

  const auto base = static_cast<GObjectClass*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)));

  #ifdef GLIBMM_DEBUG_REFCOUNTING
  g_warning("Window_Class::dispose_vfunc_callback(): before calling base->dispose.");
  #endif

  if(base->dispose)
    (*base->dispose)(self);

  #ifdef GLIBMM_DEBUG_REFCOUNTING
  g_warning("Window_Class::dispose_vfunc_callback(): after calling base->dispose.");
  #endif
}

auto Window::destroy () -> void
{
  // Don't crash if destroy() is called twice.
  // gobj() can be nullptr after the first call to destroy().
  if (gobj())
    gtk_window_destroy(gobj());
}

auto Window::unset_focus () -> void
{
  gtk_window_set_focus(gobj(), nullptr /* See GTK+ docs */);
}

auto Window::unset_default_widget () -> void
{
  gtk_window_set_default_widget(gobj(), nullptr /* See GTK+ docs */);
}

auto Window::unset_transient_for () -> void
{
  gtk_window_set_transient_for(gobj(), nullptr /* See GTK+ docs */);
}

auto Window::unset_child () -> void
{
  gtk_window_set_child(gobj(), nullptr);
}

auto Window::unset_application () -> void
{
  gtk_window_set_application(gobj(), nullptr /* See GTK+ docs */);
}

auto Window::unset_titlebar () -> void
{
  gtk_window_set_titlebar(gobj(), nullptr);
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo Window_signal_keys_changed_info =
{
  "keys_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto Window_signal_close_request_callback(GtkWindow* self, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool()>;

  const auto obj = dynamic_cast<Window*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))();
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto Window_signal_close_request_notify_callback(GtkWindow* self,  void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void()>;

  const auto obj = dynamic_cast<Window*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))();
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo Window_signal_close_request_info =
{
  "close-request",
  (GCallback) &Window_signal_close_request_callback,
  (GCallback) &Window_signal_close_request_notify_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkWindow* object, const bool take_copy) -> Gtk::Window*
{
  return dynamic_cast<Gtk::Window *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Window_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Window_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_window_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Native::add_interface(get_type());
  ShortcutManager::add_interface(get_type());
  Root::add_interface(get_type());

  }

  return *this;
}


auto Window_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

    reinterpret_cast<GObjectClass*>(klass)->dispose = &dispose_vfunc_callback;

  klass->keys_changed = &keys_changed_callback;
  klass->close_request = &close_request_callback;
}


auto Window_Class::keys_changed_callback (GtkWindow *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_keys_changed();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->keys_changed)
    (*base->keys_changed)(self);
}
auto Window_Class::close_request_callback(GtkWindow* self) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->on_close_request();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->close_request)
    return (*base->close_request)(self);

  using RType = gboolean;
  return RType();
}


auto Window_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new Window((GtkWindow*)o); //top-level windows can not be manage()ed.

}


/* The implementation: */


Window::~Window() noexcept
{
  destroy_();
}

Window::CppClassType Window::window_class_; // initialize static member

auto Window::get_type() -> GType
{
  return window_class_.init().get_type();
}


auto Window::get_base_type() -> GType
{
  return gtk_window_get_type();
}


auto Window::set_title (const Glib::ustring &title) -> void
{
  gtk_window_set_title(gobj(), title.c_str());
}

auto Window::get_title() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_window_get_title(const_cast<GtkWindow*>(gobj())));
}

auto Window::set_startup_id (const Glib::ustring &startup_id) -> void
{
  gtk_window_set_startup_id(gobj(), startup_id.c_str());
}

auto Window::set_focus (
  Widget &focus) -> void
{
  gtk_window_set_focus(gobj(), focus.gobj());
}

auto Window::get_focus() -> Widget*
{
  return Glib::wrap(gtk_window_get_focus(gobj()));
}

auto Window::get_focus() const -> const Widget*
{
  return const_cast<Window*>(this)->get_focus();
}

auto Window::set_default_widget (
  Widget &default_widget) -> void
{
  gtk_window_set_default_widget(gobj(), default_widget.gobj());
}

auto Window::get_default_widget() -> Widget*
{
  return Glib::wrap(gtk_window_get_default_widget(gobj()));
}

auto Window::get_default_widget() const -> const Widget*
{
  return const_cast<Window*>(this)->get_default_widget();
}

auto Window::set_transient_for (Window &parent) -> void
{
  gtk_window_set_transient_for(gobj(), parent.gobj());
}

auto Window::get_transient_for() -> Window*
{
  return Glib::wrap(gtk_window_get_transient_for(gobj()));
}

auto Window::get_transient_for() const -> const Window*
{
  return const_cast<Window*>(this)->get_transient_for();
}

auto Window::set_destroy_with_parent (
  const bool setting) -> void
{
  gtk_window_set_destroy_with_parent(gobj(), setting);
}

auto Window::get_destroy_with_parent() const -> bool
{
  return gtk_window_get_destroy_with_parent(const_cast<GtkWindow*>(gobj()));
}

auto Window::set_hide_on_close (
  const bool setting) -> void
{
  gtk_window_set_hide_on_close(gobj(), setting);
}

auto Window::get_hide_on_close() const -> bool
{
  return gtk_window_get_hide_on_close(const_cast<GtkWindow*>(gobj()));
}

auto Window::set_mnemonics_visible (
  const bool setting) -> void
{
  gtk_window_set_mnemonics_visible(gobj(), setting);
}

auto Window::get_mnemonics_visible() const -> bool
{
  return gtk_window_get_mnemonics_visible(const_cast<GtkWindow*>(gobj()));
}

auto Window::set_focus_visible (
  const bool setting) -> void
{
  gtk_window_set_focus_visible(gobj(), setting);
}

auto Window::get_focus_visible() const -> bool
{
  return gtk_window_get_focus_visible(const_cast<GtkWindow*>(gobj()));
}

auto Window::set_resizable (
  const bool resizable) -> void
{
  gtk_window_set_resizable(gobj(), resizable);
}

auto Window::get_resizable() const -> bool
{
  return gtk_window_get_resizable(const_cast<GtkWindow*>(gobj()));
}

auto Window::set_display (const Glib::RefPtr <Gdk::Display> &display) -> void
{
  gtk_window_set_display(gobj(), Glib::unwrap(display));
}

auto Window::is_active() const -> bool
{
  return gtk_window_is_active(const_cast<GtkWindow*>(gobj()));
}

auto Window::set_decorated (
  const bool setting) -> void
{
  gtk_window_set_decorated(gobj(), setting);
}

auto Window::get_decorated() const -> bool
{
  return gtk_window_get_decorated(const_cast<GtkWindow*>(gobj()));
}

auto Window::set_deletable (
  const bool setting) -> void
{
  gtk_window_set_deletable(gobj(), setting);
}

auto Window::get_deletable() const -> bool
{
  return gtk_window_get_deletable(const_cast<GtkWindow*>(gobj()));
}

auto Window::set_icon_name (const Glib::ustring &name) -> void
{
  gtk_window_set_icon_name(gobj(), name.c_str());
}

auto Window::get_icon_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_window_get_icon_name(const_cast<GtkWindow*>(gobj())));
}

auto Window::set_default_icon_name (const Glib::ustring &name) -> void
{
  gtk_window_set_default_icon_name(name.c_str());
}

auto Window::get_default_icon_name() -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_window_get_default_icon_name());
}

auto Window::set_auto_startup_notification (
  const bool setting) -> void
{
  gtk_window_set_auto_startup_notification(setting);
}

auto Window::set_modal (
  const bool modal) -> void
{
  gtk_window_set_modal(gobj(), modal);
}

auto Window::get_modal() const -> bool
{
  return gtk_window_get_modal(const_cast<GtkWindow*>(gobj()));
}

auto Window::get_toplevels() -> Glib::RefPtr<Gio::ListModel>
{

  auto retvalue = Glib::wrap(gtk_window_get_toplevels());
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

auto Window::list_toplevels() -> std::vector<Window*>
{
  return Glib::ListHandler<Window*>::list_to_vector(gtk_window_list_toplevels(), Glib::OWNERSHIP_SHALLOW);
}

auto Window::present () -> void
{
  gtk_window_present(gobj());
}

auto Window::present (
  const guint32 timestamp) -> void
{
  gtk_window_present_with_time(gobj(), timestamp);
}

auto Window::minimize () -> void
{
  gtk_window_minimize(gobj());
}

auto Window::unminimize () -> void
{
  gtk_window_unminimize(gobj());
}

auto Window::maximize () -> void
{
  gtk_window_maximize(gobj());
}

auto Window::unmaximize () -> void
{
  gtk_window_unmaximize(gobj());
}

auto Window::fullscreen () -> void
{
  gtk_window_fullscreen(gobj());
}

auto Window::unfullscreen () -> void
{
  gtk_window_unfullscreen(gobj());
}

auto Window::fullscreen_on_monitor (const Glib::RefPtr <Gdk::Monitor> &monitor) -> void
{
  gtk_window_fullscreen_on_monitor(gobj(), Glib::unwrap(monitor));
}

auto Window::close () -> void
{
  gtk_window_close(gobj());
}

auto Window::set_default_size (
  const int width, const int height) -> void
{
  gtk_window_set_default_size(gobj(), width, height);
}

auto Window::get_default_size (int &width, int &height) const -> void
{
  gtk_window_get_default_size(const_cast<GtkWindow*>(gobj()), &width, &height);
}

auto Window::get_group() -> Glib::RefPtr<WindowGroup>
{
  auto retvalue = Glib::wrap(gtk_window_get_group(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Window::get_group() const -> Glib::RefPtr<const WindowGroup>
{
  return const_cast<Window*>(this)->get_group();
}

auto Window::has_group() const -> bool
{
  return gtk_window_has_group(const_cast<GtkWindow*>(gobj()));
}

auto Window::get_application() -> Glib::RefPtr<Application>
{
  auto retvalue = Glib::wrap(gtk_window_get_application(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Window::get_application() const -> Glib::RefPtr<const Application>
{
  auto retvalue = Glib::wrap(gtk_window_get_application(const_cast<GtkWindow*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Window::set_application (const Glib::RefPtr <Application> &application) -> void
{
  gtk_window_set_application(gobj(), Glib::unwrap(application));
}

auto Window::set_child (Widget &child) -> void
{
  gtk_window_set_child(gobj(), child.gobj());
}

auto Window::get_child() -> Widget*
{
  return Glib::wrap(gtk_window_get_child(gobj()));
}

auto Window::get_child() const -> const Widget*
{
  return const_cast<Window*>(this)->get_child();
}

auto Window::set_titlebar (Widget &titlebar) -> void
{
  gtk_window_set_titlebar(gobj(), titlebar.gobj());
}

auto Window::get_titlebar() -> Widget*
{
  return Glib::wrap(gtk_window_get_titlebar(gobj()));
}

auto Window::get_titlebar() const -> const Widget*
{
  return const_cast<Window*>(this)->get_titlebar();
}

auto Window::is_maximized() const -> bool
{
  return gtk_window_is_maximized(const_cast<GtkWindow*>(gobj()));
}

auto Window::is_fullscreen() const -> bool
{
  return gtk_window_is_fullscreen(const_cast<GtkWindow*>(gobj()));
}

auto Window::set_handle_menubar_accel (
  const bool handle_menubar_accel) -> void
{
  gtk_window_set_handle_menubar_accel(gobj(), handle_menubar_accel);
}

auto Window::get_handle_menubar_accel() const -> bool
{
  return gtk_window_get_handle_menubar_accel(const_cast<GtkWindow*>(gobj()));
}


auto Window::signal_keys_changed() -> Glib::SignalProxy<void()>
{
  return {this, &Window_signal_keys_changed_info};
}


auto Window::signal_close_request() -> Glib::SignalProxy<bool()>
{
  return {this, &Window_signal_close_request_info};
}


auto Window::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "title"};
}

auto Window::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "title"};
}

auto Window::property_startup_id() -> Glib::PropertyProxy_WriteOnly< Glib::ustring >
{
  return {this, "startup-id"};
}

auto Window::property_resizable() -> Glib::PropertyProxy< bool >
{
  return {this, "resizable"};
}

auto Window::property_resizable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "resizable"};
}

auto Window::property_modal() -> Glib::PropertyProxy< bool >
{
  return {this, "modal"};
}

auto Window::property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "modal"};
}

auto Window::property_default_width() -> Glib::PropertyProxy< int >
{
  return {this, "default-width"};
}

auto Window::property_default_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "default-width"};
}

auto Window::property_default_height() -> Glib::PropertyProxy< int >
{
  return {this, "default-height"};
}

auto Window::property_default_height() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "default-height"};
}

auto Window::property_destroy_with_parent() -> Glib::PropertyProxy< bool >
{
  return {this, "destroy-with-parent"};
}

auto Window::property_destroy_with_parent() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "destroy-with-parent"};
}

auto Window::property_hide_on_close() -> Glib::PropertyProxy< bool >
{
  return {this, "hide-on-close"};
}

auto Window::property_hide_on_close() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "hide-on-close"};
}

auto Window::property_mnemonics_visible() -> Glib::PropertyProxy< bool >
{
  return {this, "mnemonics-visible"};
}

auto Window::property_mnemonics_visible() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "mnemonics-visible"};
}

auto Window::property_icon_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "icon-name"};
}

auto Window::property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "icon-name"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Display>>::value,
  "Type Glib::RefPtr<Gdk::Display> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Window::property_display() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Display> >
{
  return {this, "display"};
}

auto Window::property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Display> >
{
  return {this, "display"};
}

auto Window::property_is_active() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "is-active"};
}

auto Window::property_decorated() -> Glib::PropertyProxy< bool >
{
  return {this, "decorated"};
}

auto Window::property_decorated() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "decorated"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Window*>::value,
  "Type Window* cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Window::property_transient_for() -> Glib::PropertyProxy< Window* >
{
  return {this, "transient-for"};
}

auto Window::property_transient_for() const -> Glib::PropertyProxy_ReadOnly< Window* >
{
  return {this, "transient-for"};
}

auto Window::property_deletable() -> Glib::PropertyProxy< bool >
{
  return {this, "deletable"};
}

auto Window::property_deletable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "deletable"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Application>>::value,
  "Type Glib::RefPtr<Application> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Window::property_application() -> Glib::PropertyProxy< Glib::RefPtr<Application> >
{
  return {this, "application"};
}

auto Window::property_application() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Application> >
{
  return {this, "application"};
}

auto Window::property_focus_visible() -> Glib::PropertyProxy< bool >
{
  return {this, "focus-visible"};
}

auto Window::property_focus_visible() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "focus-visible"};
}

auto Window::property_maximized() -> Glib::PropertyProxy< bool >
{
  return {this, "maximized"};
}

auto Window::property_maximized() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "maximized"};
}

auto Window::property_fullscreened() -> Glib::PropertyProxy< bool >
{
  return {this, "fullscreened"};
}

auto Window::property_fullscreened() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "fullscreened"};
}

auto Window::property_default_widget() -> Glib::PropertyProxy< Widget* >
{
  return {this, "default-widget"};
}

auto Window::property_default_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "default-widget"};
}

auto Window::property_focus_widget() -> Glib::PropertyProxy< Widget* >
{
  return {this, "focus-widget"};
}

auto Window::property_focus_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "focus-widget"};
}

auto Window::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto Window::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}

auto Window::property_titlebar() -> Glib::PropertyProxy< Widget* >
{
  return {this, "titlebar"};
}

auto Window::property_titlebar() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "titlebar"};
}

auto Window::property_handle_menubar_accel() -> Glib::PropertyProxy< bool >
{
  return {this, "handle-menubar-accel"};
}

auto Window::property_handle_menubar_accel() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "handle-menubar-accel"};
}


auto Window::on_keys_changed () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->keys_changed)
    (*base->keys_changed)(gobj());
}
auto Window::on_close_request() -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->close_request)
    return (*base->close_request)(gobj());

  using RType = bool;
  return RType();
}


} // namespace Gtk


