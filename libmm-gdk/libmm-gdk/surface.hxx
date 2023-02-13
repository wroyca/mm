
#ifndef _GDKMM_SURFACE_H
#define _GDKMM_SURFACE_H

#include <libmm-gdk/mm-gdkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright(C) 1998-2010 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License or(at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <libmm-glib/object.hxx>
#include <libmm-gdk/drag.hxx>
#include <libmm-cairo/region.hxx>
#include <libmm-gdk/device.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/event.hxx>
#include <libmm-gdk/popuplayout.hxx>
#include <libmm-cairo/context.hxx>
#include <gdk/gdk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Surface_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

class GDKMM_API ContentProvider;
class GDKMM_API Cursor;
class GDKMM_API CairoContext;
class GDKMM_API GLContext;
class GDKMM_API FrameClock;
class GDKMM_API Monitor;

/** Onscreen display areas in the target window system.
 *
 * A %Gdk::Surface is a (usually) rectangular region on the screen.
 * It’s a low-level object, used to implement high-level objects
 * such as Gtk::Window or Gtk::Dialog in GTK.
 *
 * The surfaces you see in practice are either Gdk::Toplevel or
 * Gdk::Popup, and those interfaces provide much of the required
 * API to interact with these surfaces. Other, more specialized
 * surface types exist, but you will rarely interact with them
 * directly.
 *
 * @see Gdk::Toplevel, Gdk::Popup
 */

class GDKMM_API Surface : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Surface;
  using CppClassType = Surface_Class;
  using BaseObjectType = GdkSurface;
  using BaseClassType = GdkSurfaceClass;

  // noncopyable
  Surface(const Surface&) = delete;
  auto operator=(const Surface&) -> Surface& = delete;

private:  friend class Surface_Class;
  static CppClassType surface_class_;

protected:
  explicit Surface(const Glib::ConstructParams& construct_params);
  explicit Surface(GdkSurface* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Surface(Surface&& src) noexcept;
  auto operator=(Surface&& src) noexcept -> Surface&;

  ~Surface() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkSurface*       { return reinterpret_cast<GdkSurface*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkSurface* { return reinterpret_cast<GdkSurface*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkSurface*;

private:


public:
  // _WRAP_CREATE() would not be very useful here.
  // The gdk_surface_new_*() functions do more than call g_object_new().


  /** Creates a new toplevel surface.
   *
   * The created surface is usually a subclass of Gdk::Surface that implements
   * the Gdk::Toplevel interface. To use toplevel API, do something like
   * @code
   * auto surface = Gdk::Surface::create_toplevel(display);
   * auto toplevel = std::dynamic_pointer_cast<Gdk::ToplevelSurfaceImpl>(surface);
   * if (toplevel)
   *   toplevel->do_something();
   * @endcode
   *
   * @param display The display to create the surface on.
   * @return The new %Gdk::Surface.
   */
  static auto create_toplevel(const Glib::RefPtr<Display>& display) -> Glib::RefPtr<Surface>;


  /** Create a new popup surface.
   *
   * The surface will be attached to @a parent and can be positioned
   * relative to it using Gdk::Popup::present().
   *
   * The created surface is usually a subclass of Gdk::Surface that implements
   * the Gdk::Popup interface. To use popup API, do something like
   * @code
   * auto surface = Gdk::Surface::create_popup(parent, autohide);
   * auto popup = std::dynamic_pointer_cast<Gdk::PopupSurfaceImpl>(surface);
   * if (popup)
   *   popup->do_something();
   * @endcode
   *
   * @param parent The parent surface to attach the surface to.
   * @param autohide Whether to hide the surface on outside clicks.
   * @return A new %Gdk::Surface.
   */
  static auto create_popup(const Glib::RefPtr<Surface>& parent, bool autohide) -> Glib::RefPtr<Surface>;


  /** Gets the `Gdk::Display` associated with a `Gdk::Surface`.
   *
   * @return The `Gdk::Display` associated with @a surface.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Gets the `Gdk::Display` associated with a `Gdk::Surface`.
   *
   * @return The `Gdk::Display` associated with @a surface.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;


  /** Hide the surface.
   *
   * For toplevel surfaces, withdraws them, so they will no longer be
   * known to the window manager; for all surfaces, unmaps them, so
   * they won’t be displayed. Normally done automatically as
   * part of Gtk::Widget::hide().
   */
  void hide();


  /** Apply the region to the surface for the purpose of event
   * handling.
   *
   * Mouse events which happen while the pointer position corresponds
   * to an unset bit in the mask will be passed on the surface below
   *  @a surface.
   *
   * An input region is typically used with RGBA surfaces. The alpha
   * channel of the surface defines which pixels are invisible and
   * allows for nicely antialiased borders, and the input region
   * controls where the surface is “clickable”.
   *
   * Use Gdk::Display::supports_input_shapes() to find out if
   * a particular backend supports input regions.
   *
   * @param region Region of surface to be reactive.
   */
  void set_input_region(const ::Cairo::RefPtr< ::Cairo::Region>& region);


  /** Checks whether the surface has been mapped.
   *
   * A surface is mapped with Gdk::Toplevel::present()
   * or Gdk::Popup::present().
   *
   * @return <tt>true</tt> if the surface is mapped.
   */
  auto get_mapped() const -> bool;


  /** Sets the default mouse pointer for a `Gdk::Surface`.
   *
   * Passing <tt>nullptr</tt> for the @a cursor argument means that @a surface will use
   * the cursor of its parent surface. Most surfaces should use this default.
   * Note that @a cursor must be for the same display as @a surface.
   *
   * Use Gdk::Cursor::new_from_name() or Gdk::Cursor::new_from_texture()
   * to create the cursor. To make the cursor invisible, use Gdk::Cursor::Type::BLANK_CURSOR.
   *
   * @param cursor A `Gdk::Cursor`.
   */
  void set_cursor(const Glib::RefPtr<Cursor>& cursor);

  /** Use the parent surface's cursor.
   * For top-level windows this means that it will use the default cursor for the ROOT window.
   */
  void set_cursor();


  /** Sets a specific `Gdk::Cursor` for a given device when it gets inside @a surface.
   *
   * Passing <tt>nullptr</tt> for the @a cursor argument means that @a surface will use the
   * cursor of its parent surface. Most surfaces should use this default.
   *
   * Use Gdk::Cursor::new_from_name() or Gdk::Cursor::new_from_texture()
   * to create the cursor. To make the cursor invisible, use Gdk::Cursor::Type::BLANK_CURSOR.
   *
   * @param device A pointer `Gdk::Device`.
   * @param cursor A `Gdk::Cursor`.
   */
  void set_device_cursor(const Glib::RefPtr<Device>& device, const Glib::RefPtr<Cursor>& cursor);


  /** Retrieves a `Gdk::Cursor` pointer for the @a device currently set on the
   * specified `Gdk::Surface`.
   *
   * If the return value is <tt>nullptr</tt> then there is no custom cursor set on the
   * specified surface, and it is using the cursor for its parent surface.
   *
   * Use set_cursor() to unset the cursor of the surface.
   *
   * @param device A pointer `Gdk::Device`.
   * @return A `Gdk::Cursor`.
   */
  auto get_device_cursor(const Glib::RefPtr<Device>& device) -> Glib::RefPtr<Cursor>;

  /** Retrieves a `Gdk::Cursor` pointer for the @a device currently set on the
   * specified `Gdk::Surface`.
   *
   * If the return value is <tt>nullptr</tt> then there is no custom cursor set on the
   * specified surface, and it is using the cursor for its parent surface.
   *
   * Use set_cursor() to unset the cursor of the surface.
   *
   * @param device A pointer `Gdk::Device`.
   * @return A `Gdk::Cursor`.
   */
  auto get_device_cursor(const Glib::RefPtr<const Device>& device) const -> Glib::RefPtr<const Cursor>;


  /** Retrieves a `Gdk::Cursor` pointer for the cursor currently set on the
   * `Gdk::Surface`.
   *
   * If the return value is <tt>nullptr</tt> then there is no custom cursor set on
   * the surface, and it is using the cursor for its parent surface.
   *
   * Use set_cursor() to unset the cursor of the surface.
   *
   * @return A `Gdk::Cursor`.
   */
  auto get_cursor() -> Glib::RefPtr<Cursor>;

  /** Retrieves a `Gdk::Cursor` pointer for the cursor currently set on the
   * `Gdk::Surface`.
   *
   * If the return value is <tt>nullptr</tt> then there is no custom cursor set on
   * the surface, and it is using the cursor for its parent surface.
   *
   * Use set_cursor() to unset the cursor of the surface.
   *
   * @return A `Gdk::Cursor`.
   */
  auto get_cursor() const -> Glib::RefPtr<const Cursor>;


  /** Returns the width of the given @a surface.
   *
   * Surface size is reported in ”application pixels”, not
   * ”device pixels” (see get_scale_factor()).
   *
   * @return The width of @a surface.
   */
  auto get_width() const -> int;

  /** Returns the height of the given @a surface.
   *
   * Surface size is reported in ”application pixels”, not
   * ”device pixels” (see get_scale_factor()).
   *
   * @return The height of @a surface.
   */
  auto get_height() const -> int;


  /** Returns the internal scale factor that maps from surface coordinates
   * to the actual device pixels.
   *
   * On traditional systems this is 1, but on very high density outputs
   * this can be a higher value (often 2). A higher value means that drawing
   * is automatically scaled up to a higher resolution, so any code doing
   * drawing will automatically look nicer. However, if you are supplying
   * pixel-based data the scale value can be used to determine whether to
   * use a pixel resource with higher resolution data.
   *
   * The scale of a surface may change during runtime.
   *
   * @return The scale factor.
   */
  auto get_scale_factor() const -> int;


  /** Obtains the current device position and modifier state.
   *
   * The position is given in coordinates relative to the upper
   * left corner of @a surface.
   *
   * Return: <tt>true</tt> if the device is over the surface
   *
   * @param device Pointer `Gdk::Device` to query to.
   * @param x Return location for the X coordinate of @a device.
   * @param y Return location for the Y coordinate of @a device.
   * @param mask Return location for the modifier mask.
   */
  auto get_device_position(const Glib::RefPtr<const Device>& device, double& x, double& y, ModifierType& mask) const -> bool;


  /** Create a new Cairo surface that is as compatible as possible with the
   * given @a surface.
   *
   * For example the new surface will have the same fallback resolution
   * and font options as @a surface. Generally, the new surface will also
   * use the same backend as @a surface, unless that is not possible for
   * some reason. The type of the returned surface may be examined with
   * cairo_surface_get_type().
   *
   * Initially the surface contents are all 0 (transparent if contents
   * have transparency, black otherwise.)
   *
   * This function always returns a valid pointer, but it will return a
   * pointer to a “nil” surface if @a other is already in an error state
   * or any other error occurs.
   *
   * @param content The content for the new surface.
   * @param width Width of the new surface.
   * @param height Height of the new surface.
   * @return A pointer to the newly allocated surface. The caller
   * owns the surface and should call cairo_surface_destroy() when done
   * with it.
   */
  auto create_similar_surface(::Cairo::Content content, int width, int height) -> ::Cairo::RefPtr< ::Cairo::Surface>;


  /** Emits a short beep associated to @a surface.
   *
   * If the display of @a surface does not support per-surface beeps,
   * emits a short beep on the display just as Gdk::Display::beep().
   */
  void beep();


  /** Starts a drag and creates a new drag context for it.
   *
   * This function is called by the drag source. After this call, you
   * probably want to set up the drag icon using the surface returned
   * by get_drag_surface().
   *
   * This function returns a reference to the Gdk::Drag object,
   * but GTK keeps its own reference as well, as long as the DND operation
   * is going on.
   *
   * @note if @a actions include Gdk::DragAction::MOVE, you need to listen for
   * the Gdk::Drag::signal_dnd_finished() signal and delete the data at
   * the source if get_selected_action() returns
   * Gdk::DragAction::MOVE.
   *
   * @param device The device that controls this drag.
   * @param content The offered content.
   * @param actions The actions supported by this drag.
   * @param dx The x offset to @a device's position where the drag nominally started.
   * @param dy The y offset to @a device's position where the drag nominally started.
   * @return A newly created `Gdk::Drag`.
   */
  auto drag_begin_from_point(const Glib::RefPtr<Device>& device, const Glib::RefPtr<ContentProvider>& content, DragAction actions, double dx, double dy) -> Glib::RefPtr<Drag>;


  /** Forces a signal_render() signal emission for @a surface
   * to be scheduled.
   *
   * This function is useful for implementations that track invalid
   * regions on their own.
   */
  void queue_render();

  /** Request a layout phase from the surface's frame clock.
   *
   * See Gdk::FrameClock::request_phase().
   */
  void request_layout();


  /** Gets the frame clock for the surface.
   *
   * The frame clock for a surface never changes unless the surface is
   * reparented to a new toplevel surface.
   *
   * @newin{3,24}
   *
   * @return The frame clock.
   */
  auto get_frame_clock() -> Glib::RefPtr<FrameClock>;

  /** Gets the frame clock for the surface.
   *
   * The frame clock for a surface never changes unless the surface is
   * reparented to a new toplevel surface.
   *
   * @newin{3,24}
   *
   * @return The frame clock.
   */
  auto get_frame_clock() const -> Glib::RefPtr<const FrameClock>;


  /** Marks a region of the `Gdk::Surface` as opaque.
   *
   * For optimisation purposes, compositing window managers may
   * like to not draw obscured regions of surfaces, or turn off blending
   * during for these regions. With RGB windows with no transparency,
   * this is just the shape of the window, but with ARGB32 windows, the
   * compositor does not know what regions of the window are transparent
   * or not.
   *
   * This function only works for toplevel surfaces.
   *
   * GTK will update this property automatically if the @a surface background
   * is opaque, as we know where the opaque regions are. If your surface
   * background is not opaque, please update this property in your
   * Gtk::Widget::css_changed_vfunc() handler.
   *
   * @param region A region, or <tt>nullptr</tt> to make the entire
   * surface opaque.
   */
  void set_opaque_region(const ::Cairo::RefPtr<const ::Cairo::Region>& region);


  /** Creates a new GLContext matching the framebuffer format to the visual of the
   * Surface. The context is disconnected from any particular surface.
   *
   * If the creation of the GLContext failed an error will be thrown.
   *
   * Before using the returned GLContext, you will need to call
   * GLContext::make_current() or GLContext::realize().
   *
   * @newin{3,18}
   *
   * @return GLContext The newly created context.
   *
   * @throws GLError On missing GL implementation or extension required for context creation.
   */
  auto create_gl_context() -> Glib::RefPtr<Gdk::GLContext>;


  /** Creates a new `Gdk::CairoContext` for rendering on @a surface.
   *
   * @return The newly created `Gdk::CairoContext`.
   */
  auto create_cairo_context() -> Glib::RefPtr<Gdk::CairoContext>;

  // no_default_handler because the wrapped C signals have no default handlers.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%layout(int width, int height)</tt>
   *
   * Flags: Run First
   *
   * Emitted when the size of @a surface is changed, or when relayout should
   * be performed.
   *
   * Surface size is reported in ”application pixels”, not
   * ”device pixels” (see Gdk::Surface::get_scale_factor()).
   *
   * @param width The current width.
   * @param height The current height.
   */

  auto signal_layout() -> Glib::SignalProxy<void(int, int)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%render(const ::Cairo::RefPtr<const ::Cairo::Region>& expose_region)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when part of the surface needs to be redrawn.
   *
   * @param expose_region The region that needs to be redrawn.
   * @return <tt>true</tt> to indicate that the signal has been handled.
   */

  auto signal_render() -> Glib::SignalProxy<bool(const ::Cairo::RefPtr<const ::Cairo::Region>&)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%event(const Glib::RefPtr<const Event>& event)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when GDK receives an input event for @a surface.
   *
   * @param event An input event.
   * @return <tt>true</tt> to indicate that the event has been handled.
   */

  auto signal_event() -> Glib::SignalProxy<bool(const Glib::RefPtr<const Event>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%enter_monitor(const Glib::RefPtr<Monitor>& monitor)</tt>
   *
   * Flags: Run First
   *
   * Emitted when @a surface starts being present on the monitor.
   *
   * @param monitor The monitor.
   */

  auto signal_enter_monitor() -> Glib::SignalProxy<void(const Glib::RefPtr<Monitor>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%leave_monitor(const Glib::RefPtr<Monitor>& monitor)</tt>
   *
   * Flags: Run First
   *
   * Emitted when @a surface stops being present on the monitor.
   *
   * @param monitor The monitor.
   */

  auto signal_leave_monitor() -> Glib::SignalProxy<void(const Glib::RefPtr<Monitor>&)>;


  /** The mouse pointer for the `Gdk::Surface`.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cursor() -> Glib::PropertyProxy< Glib::RefPtr<Cursor> > ;

/** The mouse pointer for the `Gdk::Surface`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cursor() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Cursor> >;

  /** The `Gdk::Display` connection of the surface.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >;


  /** The `Gdk::FrameClock` of the surface.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_frame_clock() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<FrameClock> >;


  /** Whether the surface is mapped.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mapped() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The width of the surface in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** The height of the surface, in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_height() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** The scale factor of the surface.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale_factor() const -> Glib::PropertyProxy_ReadOnly< int >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Surface
   */
  GDKMM_API
  auto wrap(GdkSurface* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Surface>;
}


#endif /* _GDKMM_SURFACE_H */

