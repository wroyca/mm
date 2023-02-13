
#ifndef _GDKMM_TOPLEVEL_H
#define _GDKMM_TOPLEVEL_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-glib/interface.hpp>
#include <libmm-gdk/surface.hpp>
#include <libmm-gdk/texture.hpp>
#include <libmm-gdk/toplevellayout.hpp>
#include <libmm-gdk/toplevelsize.hpp>
#include <vector>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GdkToplevelInterface GdkToplevelInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkToplevel = struct _GdkToplevel;
using GdkToplevelClass = struct _GdkToplevelClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Toplevel_Class; } // namespace Gdk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 *  @var SurfaceEdge NORTH_WEST
 * The top left corner.
 *
 *  @var SurfaceEdge NORTH
 * The top edge.
 *
 *  @var SurfaceEdge NORTH_EAST
 * The top right corner.
 *
 *  @var SurfaceEdge WEST
 * The left edge.
 *
 *  @var SurfaceEdge EAST
 * The right edge.
 *
 *  @var SurfaceEdge SOUTH_WEST
 * The lower left corner.
 *
 *  @var SurfaceEdge SOUTH
 * The lower edge.
 *
 *  @var SurfaceEdge SOUTH_EAST
 * The lower right corner.
 *
 *  @enum SurfaceEdge
 *
 * Determines a surface edge or corner.
 *
 * @ingroup gdkmmEnums
 */
enum class SurfaceEdge
{
  NORTH_WEST,
  NORTH,
  NORTH_EAST,
  WEST,
  EAST,
  SOUTH_WEST,
  SOUTH,
  SOUTH_EAST
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::SurfaceEdge> : public Glib::Value_Enum<Gdk::SurfaceEdge>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var FullscreenMode ON_CURRENT_MONITOR
 * Fullscreen on current monitor only.
 *
 *  @var FullscreenMode ON_ALL_MONITORS
 * Span across all monitors when fullscreen.
 *
 *  @enum FullscreenMode
 *
 * Indicates which monitor a surface should span over when in fullscreen mode.
 *
 * @ingroup gdkmmEnums
 */
enum class FullscreenMode
{
  ON_CURRENT_MONITOR,
  ON_ALL_MONITORS
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::FullscreenMode> : public Glib::Value_Enum<Gdk::FullscreenMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


/** Interface for toplevel surfaces.
 *
 * A %Gdk::Toplevel is a freestanding toplevel surface.
 *
 * The %Gdk::Toplevel interface provides useful APIs for
 * interacting with the windowing system, such as controlling
 * maximization and size of the surface, setting icons and
 * transient parents for dialogs.
 *
 * @see Gdk::Surface, Gdk::Popup
 * @newin{3,98}
 */

class GDKMM_API Toplevel : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Toplevel;
  using CppClassType = Toplevel_Class;
  using BaseObjectType = GdkToplevel;
  using BaseClassType = GdkToplevelInterface;

  // noncopyable
  Toplevel(const Toplevel&) = delete;
  auto operator=(const Toplevel&) -> Toplevel& = delete;

private:
  friend class Toplevel_Class;
  static CppClassType toplevel_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Toplevel();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Toplevel(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Toplevel(GdkToplevel* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Toplevel(Toplevel&& src) noexcept;
  auto operator=(Toplevel&& src) noexcept -> Toplevel&;

  ~Toplevel() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkToplevel*       { return reinterpret_cast<GdkToplevel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkToplevel* { return reinterpret_cast<GdkToplevel*>(gobject_); }

private:


public:
  /**
   *  @var State MINIMIZED
   * The surface is minimized.
   *
   *  @var State MAXIMIZED
   * The surface is maximized.
   *
   *  @var State STICKY
   * The surface is sticky.
   *
   *  @var State FULLSCREEN
   * The surface is maximized without decorations.
   *
   *  @var State ABOVE
   * The surface is kept above other surfaces.
   *
   *  @var State BELOW
   * The surface is kept below other surfaces.
   *
   *  @var State FOCUSED
   * The surface is presented as focused (with active decorations).
   *
   *  @var State TILED
   * The surface is in a tiled state.
   *
   *  @var State TOP_TILED
   * Whether the top edge is tiled.
   *
   *  @var State TOP_RESIZABLE
   * Whether the top edge is resizable.
   *
   *  @var State RIGHT_TILED
   * Whether the right edge is tiled.
   *
   *  @var State RIGHT_RESIZABLE
   * Whether the right edge is resizable.
   *
   *  @var State BOTTOM_TILED
   * Whether the bottom edge is tiled.
   *
   *  @var State BOTTOM_RESIZABLE
   * Whether the bottom edge is resizable.
   *
   *  @var State LEFT_TILED
   * Whether the left edge is tiled.
   *
   *  @var State LEFT_RESIZABLE
   * Whether the left edge is resizable.
   *
   *  @enum State
   *
   * Specifies the state of a toplevel surface.
   *
   * On platforms that support information about individual edges, the
   * Gdk::Toplevel::State::TILED state will be set whenever any of the individual
   * tiled states is set. On platforms that lack that support, the tiled state
   * will give an indication of tiledness without any of the per-edge states
   * being set.
   *
   * @ingroup gdkmmEnums
   * @par Bitwise operators:
   * <tt>Toplevel::State operator|(Toplevel::State, Toplevel::State)</tt><br>
   * <tt>Toplevel::State operator&(Toplevel::State, Toplevel::State)</tt><br>
   * <tt>Toplevel::State operator^(Toplevel::State, Toplevel::State)</tt><br>
   * <tt>Toplevel::State operator~(Toplevel::State)</tt><br>
   * <tt>Toplevel::State& operator|=(Toplevel::State&, Toplevel::State)</tt><br>
   * <tt>Toplevel::State& operator&=(Toplevel::State&, Toplevel::State)</tt><br>
   * <tt>Toplevel::State& operator^=(Toplevel::State&, Toplevel::State)</tt><br>
   */
  enum class State
  {
    MINIMIZED = 1 << 0,
    MAXIMIZED = 1 << 1,
    STICKY = 1 << 2,
    FULLSCREEN = 1 << 3,
    ABOVE = 1 << 4,
    BELOW = 1 << 5,
    FOCUSED = 1 << 6,
    TILED = 1 << 7,
    TOP_TILED = 1 << 8,
    TOP_RESIZABLE = 1 << 9,
    RIGHT_TILED = 1 << 10,
    RIGHT_RESIZABLE = 1 << 11,
    BOTTOM_TILED = 1 << 12,
    BOTTOM_RESIZABLE = 1 << 13,
    LEFT_TILED = 1 << 14,
    LEFT_RESIZABLE = 1 << 15
  };


  /** Present @a toplevel after having processed the `Gdk::ToplevelLayout` rules.
   *
   * If the toplevel was previously not showing, it will be showed,
   * otherwise it will change layout according to @a layout.
   *
   * GDK may emit the signal_compute_size() signal to let
   * the user of this toplevel compute the preferred size of the toplevel
   * surface.
   *
   * Presenting is asynchronous and the specified layout parameters are not
   * guaranteed to be respected.
   *
   * @param layout The `Gdk::ToplevelLayout` object used to layout.
   */
  void present(const Glib::RefPtr<ToplevelLayout>& layout);

  /** Asks to minimize the @a toplevel.
   *
   * The windowing system may choose to ignore the request.
   *
   * @return <tt>true</tt> if the surface was minimized.
   */
  auto minimize() -> bool;

  /** Asks to lower the @a toplevel below other windows.
   *
   * The windowing system may choose to ignore the request.
   *
   * @return <tt>true</tt> if the surface was lowered.
   */
  auto lower() -> bool;

  /** Sets keyboard focus to @a surface.
   *
   * In most cases, Gtk::Window::present_with_time() should be
   * used on a Gtk::Window, rather than calling this function.
   *
   * @param timestamp Timestamp of the event triggering the surface focus.
   */
  void focus(guint32 timestamp);

  /** Gets the bitwise or of the currently active surface state flags,
   * from the `Gdk::Toplevel::State` enumeration.
   *
   * @return Surface state bitfield.
   */
  auto get_state() const -> State;

  /** Sets the title of a toplevel surface.
   *
   * The title maybe be displayed in the titlebar,
   * in lists of windows, etc.
   *
   * @param title Title of @a surface.
   */
  void set_title(const Glib::ustring& title);

  /** Sets the startup notification ID.
   *
   * When using GTK, typically you should use
   * Gtk::Window::set_startup_id() instead of this
   * low-level function.
   *
   * @param startup_id A string with startup-notification identifier.
   */
  void set_startup_id(const Glib::ustring& startup_id);

  /** Sets a transient-for parent.
   *
   * Indicates to the window manager that @a surface is a transient
   * dialog associated with the application surface @a parent. This
   * allows the window manager to do things like center @a surface
   * on @a parent and keep @a surface above @a parent.
   *
   * See Gtk::Window::set_transient_for() if you’re using
   * Gtk::Window or Gtk::Dialog.
   *
   * @param parent Another toplevel `Gdk::Surface`.
   */
  void set_transient_for(const Glib::RefPtr<Surface>& parent);

  /** Sets the toplevel to be modal.
   *
   * The application can use this hint to tell the
   * window manager that a certain surface has modal
   * behaviour. The window manager can use this information
   * to handle modal surfaces in a special way.
   *
   * You should only use this on surfaces for which you have
   * previously called set_transient_for().
   *
   * @param modal <tt>true</tt> if the surface is modal, <tt>false</tt> otherwise.
   */
  void set_modal(bool modal =  true);


  /** Sets a list of icons for the surface.
   *
   * One of these will be used to represent the surface in iconic form.
   * The icon may be shown in window lists or task bars. Which icon
   * size is shown depends on the window manager. The window manager
   * can scale the icon but setting several size icons can give better
   * image quality.
   *
   * Note that some platforms don't support surface icons.
   *
   * @param surfaces A list of textures to use as icon, of different sizes.
   */
  void set_icon_list(const std::vector<Glib::RefPtr<Texture>>& surfaces);


  /** Asks the windowing system to show the window menu.
   *
   * The window menu is the menu shown when right-clicking the titlebar
   * on traditional windows managed by the window manager. This is useful
   * for windows using client-side decorations, activating it with a
   * right-click on the window decorations.
   *
   * @param event A `Gdk::Event` to show the menu for.
   * @return <tt>true</tt> if the window menu was shown and <tt>false</tt> otherwise.
   */
  auto show_window_menu(const Glib::RefPtr<Event>& event) -> bool;

  /** Sets the toplevel to be decorated.
   *
   * Setting @a decorated to <tt>false</tt> hints the desktop environment
   * that the surface has its own, client-side decorations and
   * does not need to have window decorations added.
   *
   * @param decorated <tt>true</tt> to request decorations.
   */
  void set_decorated(bool decorated =  true);

  /** Sets the toplevel to be deletable.
   *
   * Setting @a deletable to <tt>true</tt> hints the desktop environment
   * that it should offer the user a way to close the surface.
   *
   * @param deletable <tt>true</tt> to request a delete button.
   */
  void set_deletable(bool deletable =  true);

  /** Returns whether the desktop environment supports
   * tiled window states.
   *
   * @return <tt>true</tt> if the desktop environment supports tiled window states.
   */
  auto supports_edge_constraints() const -> bool;


  /** Requests that the @a toplevel inhibit the system shortcuts.
   *
   * This is asking the desktop environment/windowing system to let all
   * keyboard events reach the surface, as long as it is focused, instead
   * of triggering system actions.
   *
   * If granted, the rerouting remains active until the default shortcuts
   * processing is restored with restore_system_shortcuts(),
   * or the request is revoked by the desktop environment, windowing system
   * or the user.
   *
   * A typical use case for this API is remote desktop or virtual machine
   * viewers which need to inhibit the default system keyboard shortcuts
   * so that the remote session or virtual host gets those instead of the
   * local environment.
   *
   * The windowing system or desktop environment may ask the user to grant
   * or deny the request or even choose to ignore the request entirely.
   *
   * The caller can be notified whenever the request is granted or revoked
   * by listening to the property_shortcuts_inhibited() property.
   *
   * @param event The `Gdk::Event` that is triggering the inhibit
   * request, or <tt>nullptr</tt> if none is available.
   */
  void inhibit_system_shortcuts(const Glib::RefPtr<Event>& event);

  /** Restore default system keyboard shortcuts which were previously
   * inhibited.
   *
   * This undoes the effect of inhibit_system_shortcuts().
   */
  void restore_system_shortcuts();


  /** Begins an interactive resize operation.
   *
   * You might use this function to implement a “window resize grip.”
   *
   * @param edge The edge or corner from which the drag is started.
   * @param device The device used for the operation.
   * @param button The button being used to drag, or 0 for a keyboard-initiated drag.
   * @param x Surface X coordinate of mouse click that began the drag.
   * @param y Surface Y coordinate of mouse click that began the drag.
   * @param timestamp Timestamp of mouse click that began the drag (use
   * Gdk::Event::get_time()).
   */
  void begin_resize(SurfaceEdge edge, const Glib::RefPtr<Device>& device, int button, double x, double y, guint32 timestamp);

  /** Begins an interactive move operation.
   *
   * You might use this function to implement draggable titlebars.
   *
   * @param device The device used for the operation.
   * @param button The button being used to drag, or 0 for a keyboard-initiated drag.
   * @param x Surface X coordinate of mouse click that began the drag.
   * @param y Surface Y coordinate of mouse click that began the drag.
   * @param timestamp Timestamp of mouse click that began the drag (use
   * Gdk::Event::get_time()).
   */
  void begin_move(const Glib::RefPtr<Device>& device, int button, double x, double y, guint32 timestamp);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%compute_size(ToplevelSize& size)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the size for the surface needs to be computed, when
   * it is present.
   *
   * It will normally be emitted during or after Gdk::Toplevel::present(),
   * depending on the configuration received by the windowing system.
   * It may also be emitted at any other point in time, in response
   * to the windowing system spontaneously changing the configuration.
   *
   * It is the responsibility of the toplevel user to handle this signal
   * and compute the desired size of the toplevel, given the information
   * passed via the Gdk::ToplevelSize object. Failing to do so
   * will result in an arbitrary size being used as a result.
   *
   * @param size A `Gdk::ToplevelSize`.
   */

  auto signal_compute_size() -> Glib::SignalProxy<void(ToplevelSize&)>;


  /** The state of the toplevel.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_state() const -> Glib::PropertyProxy_ReadOnly< State >;


  /** The title of the surface.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** The title of the surface.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The startup ID of the surface.
   *
   * See Gdk::AppLaunchContext for more information about
   * startup feedback.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_startup_id() -> Glib::PropertyProxy< Glib::ustring > ;

/** The startup ID of the surface.
   *
   * See Gdk::AppLaunchContext for more information about
   * startup feedback.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_startup_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The transient parent of the surface.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_transient_for() -> Glib::PropertyProxy< Glib::RefPtr<Surface> > ;

/** The transient parent of the surface.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_transient_for() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Surface> >;

  /** Whether the surface is modal.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() -> Glib::PropertyProxy< bool > ;

/** Whether the surface is modal.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >;

  //TODO: _WRAP_PROPERTY("icon-list", std::vector<Glib::RefPtr<Texture>>)
  /** Whether the window manager should add decorations.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_decorated() -> Glib::PropertyProxy< bool > ;

/** Whether the window manager should add decorations.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_decorated() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the window manager should allow to close the surface.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_deletable() -> Glib::PropertyProxy< bool > ;

/** Whether the window manager should allow to close the surface.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_deletable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The fullscreen mode of the surface.
   *
   * Default value: Gdk::FullscreenMode::ON_CURRENT_MONITOR
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fullscreen_mode() -> Glib::PropertyProxy< FullscreenMode > ;

/** The fullscreen mode of the surface.
   *
   * Default value: Gdk::FullscreenMode::ON_CURRENT_MONITOR
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fullscreen_mode() const -> Glib::PropertyProxy_ReadOnly< FullscreenMode >;

  /** Whether the surface should inhibit keyboard shortcuts.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_shortcuts_inhibited() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk

namespace Gdk
{

/** @ingroup gdkmmEnums */
inline auto operator|(Toplevel::State lhs, Toplevel::State rhs) -> Toplevel::State
  { return static_cast<Toplevel::State>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(Toplevel::State lhs, Toplevel::State rhs) -> Toplevel::State
  { return static_cast<Toplevel::State>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(Toplevel::State lhs, Toplevel::State rhs) -> Toplevel::State
  { return static_cast<Toplevel::State>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(Toplevel::State flags) -> Toplevel::State
  { return static_cast<Toplevel::State>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(Toplevel::State& lhs, Toplevel::State rhs) -> Toplevel::State&
  { return (lhs = static_cast<Toplevel::State>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(Toplevel::State& lhs, Toplevel::State rhs) -> Toplevel::State&
  { return (lhs = static_cast<Toplevel::State>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(Toplevel::State& lhs, Toplevel::State rhs) -> Toplevel::State&
  { return (lhs = static_cast<Toplevel::State>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::Toplevel::State> : public Glib::Value_Flags<Gdk::Toplevel::State>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Toplevel
   */
  GDKMM_API
  auto wrap(GdkToplevel* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Toplevel>;

} // namespace Glib


#endif /* _GDKMM_TOPLEVEL_H */

