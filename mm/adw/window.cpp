// SPDX-License-Identifier: GPL-3.0-or-later
//

#include <mm/adw/window.hpp>
#include <mm/adw/private/window_p.hpp>

namespace Adw
{
  Window::CppClassType Window::window_class_;

  // All constructors are hand-coded, because they connect a signal handler
  // that removes the window from its application when the window is closed (hidden).
  //
  Window::Window(const Glib::ConstructParams &construct_params)
    : Gtk::Window(construct_params)
  {
    signal_hide().connect(mem_fun(*this, &Window::on_window_hide));
  }

  Window::Window(AdwWindow *castitem)
    : Gtk::Window(std::bit_cast<GtkWindow *>(castitem))
  {
    signal_hide().connect(mem_fun(*this, &Window::on_window_hide));
  }

  Window::Window(Window &&src) noexcept
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
  auto Window::operator=(Window &&src) noexcept -> Window&
  {
    Widget::operator=(std::move(src));
    Native::operator=(std::move(src));
    Root::operator=(std::move(src));
    return *this;
  }

  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Window::Window()
    : ObjectBase(nullptr),
      Gtk::Window(Glib::ConstructParams(window_class_.init()))
  {
    signal_hide().connect(mem_fun(*this, &Window::on_window_hide));
  }

  auto Window::get_type() -> GType
  {
    return window_class_.init().get_type();
  }

  auto Window::get_base_type() -> GType
  {
    return adw_window_get_type();
  }

  /* The *_Class implementation: */
  auto Window_Class::init() -> const Class&
  {
    // create the GType if necessary
    if (!gtype_)
    {
      // Glib::Class has to know the class init function to clone custom types.
      class_init_func_ = &Window_Class::class_init_function;

      // Create the wrapper type, with the same class/instance size as the base type.
      register_derived_type(adw_window_get_type());

      // Add derived versions of interfaces, if the C type implements any interfaces:
      Gtk::Native::add_interface(get_type());
      Gtk::ShortcutManager::add_interface(get_type());
      Gtk::Root::add_interface(get_type());
    }
    return *this;
  }

  auto Window_Class::class_init_function(void *g_class, void *class_data) -> void
  {
    const auto klass = static_cast<BaseClassType *>(g_class);
    // CppClassParent::class_init_function(klass, class_data);
    reinterpret_cast<GObjectClass *>(klass)->dispose = &dispose_vfunc_callback;

    //klass->keys_changed = &keys_changed_callback;
    //klass->close_request = &close_request_callback;
  }

  auto Window_Class::dispose_vfunc_callback(GObject *self) -> void
  {
    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Window_Class::dispose_vfunc_callback(): gobject_: %p\n", (void *)self);
    #endif

    // This function might be invoked recursively because we're triggering
    // several signal emissions, particularly signal_hide().  Therefore we
    // have to test for cpp_destruction_in_progress_ at this point.

    if (const auto obj = dynamic_cast<Gtk::Widget *>(Glib::ObjectBase::_get_current_wrapper(self)); obj && !obj->_cpp_destruction_is_in_progress())
    // When it should really be destroyed, we zero gobj_.
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
      if (const auto win = dynamic_cast<Window *>(obj))
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

    const auto base = static_cast<GObjectClass *>(g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)));

    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Window_Class::dispose_vfunc_callback(): before calling base->dispose.");
    #endif

    if (base->dispose)
      (*base->dispose)(self);

    #ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning("Window_Class::dispose_vfunc_callback(): after calling base->dispose.");
    #endif
  }
} // namespace Adw
