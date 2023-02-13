
#ifndef _GDKMM_DISPLAY_H
#define _GDKMM_DISPLAY_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <vector>

#include <libmm-gdk/applaunchcontext.hxx>
#include <libmm-gdk/event.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDisplay = struct _GdkDisplay;
using GdkDisplayClass = struct _GdkDisplayClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Display_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class GDKMM_API ListModel;
}

namespace Gdk
{


class GDKMM_API Clipboard;
class GDKMM_API Device;
class GDKMM_API GLContext;
class GDKMM_API Seat;
class GDKMM_API Monitor;
class GDKMM_API Surface;

 /** Gdk::Display object's purpose is two fold:
 *   To grab/ungrab keyboard focus and mouse pointer
 *   To manage and provide information about the Gdk::Monitor(s) available for this Gdk::Display
 *
 * Gdk::Display objects are the GDK representation of the X Display which can be described as a workstation consisting
 * of a keyboard a pointing device (such as a mouse) and one or more screens. It is used to open and keep track of
 * various Gdk::Monitor objects currently instantiated by the application. It is also used to grab and release the keyboard
 * and the mouse pointer.
 */

class GDKMM_API Display : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Display;
  using CppClassType = Display_Class;
  using BaseObjectType = GdkDisplay;
  using BaseClassType = GdkDisplayClass;

  // noncopyable
  Display(const Display&) = delete;
  auto operator=(const Display&) -> Display& = delete;

private:  friend class Display_Class;
  static CppClassType display_class_;

protected:
  explicit Display(const Glib::ConstructParams& construct_params);
  explicit Display(GdkDisplay* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Display(Display&& src) noexcept;
  auto operator=(Display&& src) noexcept -> Display&;

  ~Display() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkDisplay*       { return reinterpret_cast<GdkDisplay*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkDisplay* { return reinterpret_cast<GdkDisplay*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkDisplay*;

private:

protected:
  Display();

public:

  /** Opens a display.
   *
   * If opening the display fails, <tt>nullptr</tt> is returned.
   *
   * @param display_name The name of the display to open.
   * @return A `Gdk::Display`.
   */
  static auto open(const Glib::ustring& display_name) -> Glib::RefPtr<Display>;


  /** Gets the name of the display.
   *
   * @return A string representing the display name. This string is owned
   * by GDK and should not be modified or freed.
   */
  auto get_name() const -> Glib::ustring;


  /** Returns <tt>true</tt> if there is an ongoing grab on @a device for @a display.
   *
   * @param device A `Gdk::Device`.
   * @return <tt>true</tt> if there is a grab in effect for @a device.
   */
  auto device_is_grabbed(const Glib::RefPtr<const Gdk::Device>& device) const -> bool;

  /** Emits a short beep on @a display
   */
  void beep();

  /** Flushes any requests queued for the windowing system and waits until all
   * requests have been handled.
   *
   * This is often used for making sure that the display is synchronized
   * with the current state of the program. Calling sync()
   * before GdkX11::Display::error_trap_pop() makes sure that any errors
   * generated from earlier requests are handled before the error trap is removed.
   *
   * This is most useful for X11. On windowing systems where requests are
   * handled synchronously, this function will do nothing.
   */
  void sync();

  /** Closes the connection to the windowing system for the given display.
   *
   * This cleans up associated resources.
   */
  void close();

  /** Finds out if the display has been closed.
   *
   * @return <tt>true</tt> if the display is closed.
   */
  auto is_closed() const -> bool;

  /** Returns whether surfaces can reasonably be expected to have
   * their alpha channel drawn correctly on the screen.
   *
   * Check is_rgba() for whether the display
   * supports an alpha channel.
   *
   * On X11 this function returns whether a compositing manager is
   * compositing on @a display.
   *
   * On modern displays, this value is always <tt>true</tt>.
   *
   * @return Whether surfaces with RGBA visuals can reasonably
   * be expected to have their alpha channels drawn correctly
   * on the screen.
   */
  auto is_composited() const -> bool;

  /** Returns whether surfaces on this @a display are created with an
   * alpha channel.
   *
   * Even if a <tt>true</tt> is returned, it is possible that the
   * surface’s alpha channel won’t be honored when displaying the
   * surface on the screen: in particular, for X an appropriate
   * windowing manager and compositing manager must be running to
   * provide appropriate display. Use is_composited()
   * to check if that is the case.
   *
   * On modern displays, this value is always <tt>true</tt>.
   *
   * @return <tt>true</tt> if surfaces are created with an alpha channel or
   * <tt>false</tt> if the display does not support this functionality.
   */
  auto is_rgba() const -> bool;


  /** Appends the given event onto the front of the event
   * queue for @a display.
   *
   * This function is only useful in very special situations
   * and should not be used by applications.
   *
   * @param event A `Gdk::Event`.
   */
  void put_event(const Glib::RefPtr<const Event>& event);


  /** Gets the default `Gdk::Display`.
   *
   * This is a convenience function for:
   *
   * gdk_display_manager_get_default_display (Gdk::DisplayManager::get())
   *
   * @return A `Gdk::Display`, or <tt>nullptr</tt> if
   * there is no default display.
   */
  static auto get_default() -> Glib::RefPtr<Display>;


  /** Flushes any requests queued for the windowing system.
   *
   * This happens automatically when the main loop blocks waiting for new events,
   * but if your application is drawing without returning control to the main loop,
   * you may need to call this function explicitly. A common case where this function
   * needs to be called is when an application is executing drawing commands
   * from a thread other than the thread where the main loop is running.
   *
   * This is most useful for X11. On windowing systems where requests are
   * handled synchronously, this function will do nothing.
   */
  void flush();


  /** Gets the clipboard used for copy/paste operations.
   *
   * @return The display's clipboard.
   */
  auto get_clipboard() -> Glib::RefPtr<Clipboard>;

  /** Gets the clipboard used for copy/paste operations.
   *
   * @return The display's clipboard.
   */
  auto get_clipboard() const -> Glib::RefPtr<const Clipboard>;

  /** Gets the clipboard used for the primary selection.
   *
   * On backends where the primary clipboard is not supported natively,
   * GDK emulates this clipboard locally.
   *
   * @return The primary clipboard.
   */
  auto get_primary_clipboard() -> Glib::RefPtr<Clipboard>;

  /** Gets the clipboard used for the primary selection.
   *
   * On backends where the primary clipboard is not supported natively,
   * GDK emulates this clipboard locally.
   *
   * @return The primary clipboard.
   */
  auto get_primary_clipboard() const -> Glib::RefPtr<const Clipboard>;


  /** Returns <tt>true</tt> if the display supports input shapes.
   *
   * This means that Gdk::Surface::set_input_region() can
   * be used to modify the input shape of surfaces on @a display.
   *
   * On modern displays, this value is always <tt>true</tt>.
   *
   * @return <tt>true</tt> if surfaces with modified input shape are supported.
   */
  auto supports_input_shapes() const -> bool;


  /** Checks that OpenGL is available for this display and ensures that it is
   * properly initialized.
   *
   * When this fails, an exception will be thrown describing the error.
   *
   * Note that even if this function succeeds, creating a `Gdk::GLContext`
   * may still fail.
   *
   * This function is idempotent. Calling it multiple times will just
   * return the same value or error.
   *
   * You never need to call this function, GDK will call it automatically
   * as needed. But you can use it as a check when setting up code that
   * might make use of OpenGL.
   *
   * @newin{4,4}
   *
   * @throws Glib::Error
   */
  void prepare_gl();


  /** Creates a new `Gdk::GLContext` for the `Gdk::Display`.
   *
   * The context is disconnected from any particular surface or surface
   * and cannot be used to draw to any surface. It can only be used to
   * draw to non-surface framebuffers like textures.
   *
   * If the creation of the `Gdk::GLContext` failed, @a error will be set.
   * Before using the returned `Gdk::GLContext`, you will need to
   * call Gdk::GLContext::make_current() or Gdk::GLContext::realize().
   *
   * @newin{4,6}
   *
   * @return The newly created `Gdk::GLContext`.
   *
   * @throws Glib::Error
   */
  auto create_gl_context() -> Glib::RefPtr<GLContext>;


  /** Indicates to the GUI environment that the application has
   * finished loading, using a given identifier.
   *
   * GTK will call this function automatically for Gtk::Window
   * with custom startup-notification identifier unless
   * Gtk::Window::set_auto_startup_notification()
   * is called to disable that feature.
   *
   * @param startup_id A startup-notification identifier, for which
   * notification process should be completed.
   */
  void notify_startup_complete(const Glib::ustring& startup_id);

  /** Gets the startup notification ID for a Wayland display, or <tt>nullptr</tt>
   * if no ID has been defined.
   *
   * @return The startup notification ID for @a display.
   */
  auto get_startup_notification_id() const -> Glib::ustring;


  /** Returns a `Gdk::AppLaunchContext` suitable for launching
   * applications on the given display.
   *
   * @return A new `Gdk::AppLaunchContext` for @a display.
   */
  auto get_app_launch_context() -> Glib::RefPtr<AppLaunchContext>;

  /** Returns a `Gdk::AppLaunchContext` suitable for launching
   * applications on the given display.
   *
   * @return A new `Gdk::AppLaunchContext` for @a display.
   */
  auto get_app_launch_context() const -> Glib::RefPtr<const AppLaunchContext>;


  /** Returns the default `Gdk::Seat` for this display.
   *
   * Note that a display may not have a seat. In this case,
   * this function will return <tt>nullptr</tt>.
   *
   * @return The default seat.
   */
  auto get_default_seat() -> Glib::RefPtr<Seat>;

  /** Returns the default `Gdk::Seat` for this display.
   *
   * Note that a display may not have a seat. In this case,
   * this function will return <tt>nullptr</tt>.
   *
   * @return The default seat.
   */
  auto get_default_seat() const -> Glib::RefPtr<const Seat>;


  /** Returns the list of seats known to @a display.
   *
   * @return The
   * list of seats known to the `Gdk::Display`.
   */
  auto list_seats() -> std::vector<Glib::RefPtr<Seat>>;


  /** Returns the list of seats known to @a display.
   *
   * @return The
   * list of seats known to the `Gdk::Display`.
   */
  auto list_seats() const -> std::vector<Glib::RefPtr<const Seat>>;


  /** Gets the list of monitors associated with this display.
   *
   * Subsequent calls to this function will always return the
   * same list for the same display.
   *
   * You can listen to the GListModel::items-changed signal on
   * this list to monitor changes to the monitor of this display.
   *
   * @return A `Gio::ListModel` of `Gdk::Monitor`.
   */
  auto get_monitors() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets the list of monitors associated with this display.
   *
   * Subsequent calls to this function will always return the
   * same list for the same display.
   *
   * You can listen to the GListModel::items-changed signal on
   * this list to monitor changes to the monitor of this display.
   *
   * @return A `Gio::ListModel` of `Gdk::Monitor`.
   */
  auto get_monitors() const -> Glib::RefPtr<const Gio::ListModel>;


  /** Gets the monitor in which the largest area of @a surface
   * resides.
   *
   * @param surface A `Gdk::Surface`.
   * @return The monitor with the largest
   * overlap with @a surface.
   */
  auto get_monitor_at_surface(const Glib::RefPtr<Surface>& surface) -> Glib::RefPtr<Monitor>;

  /** Gets the monitor in which the largest area of @a surface
   * resides.
   *
   * @param surface A `Gdk::Surface`.
   * @return The monitor with the largest
   * overlap with @a surface.
   */
  auto get_monitor_at_surface(const Glib::RefPtr<Surface>& surface) const -> Glib::RefPtr<const Monitor>;


  template <class ValueType>
  auto get_setting(const Glib::ustring& name, ValueType& value) const -> bool;


  //We use no_default_handler because GdkDisplayClass is private.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%closed(bool is_error)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the connection to the windowing system for @a display is closed.
   *
   * @param is_error <tt>true</tt> if the display was closed due to an error.
   */

  auto signal_closed() -> Glib::SignalProxy<void(bool)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%opened()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the connection to the windowing system for @a display is opened.
   */

  auto signal_opened() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%seat_added(const Glib::RefPtr<Seat>& seat)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a new seat is made known to the windowing system.
   *
   * @param seat The seat that was just added.
   */

  auto signal_seat_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Seat>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%seat_removed(const Glib::RefPtr<Seat>& seat)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a seat is removed by the windowing system.
   *
   * @param seat The seat that was just removed.
   */

  auto signal_seat_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Seat>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%setting_changed(const Glib::ustring& setting)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a setting changes its value.
   *
   * @param setting The name of the setting that changed.
   */

  auto signal_setting_changed() -> Glib::SignalProxy<void(const Glib::ustring&)>;


  /** <tt>true</tt> if the display properly composites the alpha channel.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_composited() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** <tt>true</tt> if the display supports an alpha channel.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rgba() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** <tt>true</tt> if the display supports input shapes.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_shapes() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // We don't wrap the vfuncs because GdkDisplayClass is private.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

template <class ValueType>
auto Display::get_setting(const Glib::ustring& name, ValueType& value) const -> bool
{
  Glib::Value<ValueType> glibmmvalue;
  glibmmvalue.init(Glib::Value<ValueType>::value_type());

  gboolean result = gdk_display_get_setting(const_cast<GdkDisplay*>(gobj()), name.c_str(), glibmmvalue.gobj());

  value = glibmmvalue.get();
  return result;
}


} // namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Display
   */
  GDKMM_API
  auto wrap(GdkDisplay* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Display>;
}


#endif /* _GDKMM_DISPLAY_H */

