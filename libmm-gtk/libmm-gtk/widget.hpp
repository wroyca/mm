
#ifndef _GTKMM_WIDGET_H
#define _GTKMM_WIDGET_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2002, 2003 The gtkmm Development Team
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

#include <libmm-pango/context.hpp>
#include <libmm-pango/layout.hpp>

#include <libmm-gtk/object.hpp>
#include <libmm-gtk/accessible.hpp>
#include <libmm-gtk/buildable.hpp>
#include <libmm-gtk/constrainttarget.hpp>
#include <libmm-gtk/enums.hpp>
#include <libmm-gdk/display.hpp>
#include <libmm-gdk/clipboard.hpp>
#include <libmm-gdk/cursor.hpp>
#include <libmm-gdk/rectangle.hpp>
#include <libmm-gtk/requisition.hpp>
#include <libmm-gtk/stylecontext.hpp>
#include <libmm-gio/actiongroup.hpp>
#include <libmm-cairo/region.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkWidget = struct _GtkWidget;
using GtkWidgetClass = struct _GtkWidgetClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Widget_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class GTKMM_API ListModel;
}

namespace Gdk
{
class GTKMM_API FrameClock;
class GTKMM_API Paintable;
}

namespace Gtk
{


class GTKMM_API Adjustment;
class GTKMM_API Window;
class GTKMM_API Root;
class GTKMM_API Native;
class GTKMM_API EventController;
class GTKMM_API LayoutManager;
class GTKMM_API Settings;
class GTKMM_API Snapshot;
class GTKMM_API Tooltip;

// Gtk::Allocation is a typedef of Gdk::Rectangle because GtkAllocation is
// a typedef of GdkRectangle.
typedef Gdk::Rectangle Allocation;

/** @defgroup Widgets Widgets
 */

/** @defgroup Containers Container Widgets
 * These widgets can be used to group other widgets together.
 */

//TODO: Deal with the GtkObject->GObject change:
/** Abstract %Widget (Base class for all widgets)
 *
 * As the base class of all widgets this contains all of the properties
 * and methods common to all widgets. It manages the widget lifecycle, layout,
 * states and style. It is an abstract class that cannot be instantiated.
 *
 * An important part of widgets are events that can be trapped by adding
 * event controllers with add_controller(). Those are events coming directly
 * from gdk. By using event controllers you can trap everything a widget
 * can ever do.
 */

class GTKMM_API Widget
: public Object,
  public Accessible,
  public Buildable,
  public ConstraintTarget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Widget CppObjectType;
  typedef Widget_Class CppClassType;
  typedef GtkWidget BaseObjectType;
  typedef GtkWidgetClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Widget(Widget&& src) noexcept;
  auto operator=(Widget&& src) noexcept -> Widget&;

  // noncopyable
  Widget(const Widget&) = delete;
  auto operator=(const Widget&) -> Widget& = delete;

  /** Destroys the widget. The widget will be automatically removed from the parent container.
   */
  ~Widget() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Widget_Class;
  static CppClassType widget_class_;

protected:
  explicit Widget(const Glib::ConstructParams& construct_params);
  explicit Widget(GtkWidget* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkWidget*       { return reinterpret_cast<GtkWidget*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkWidget* { return reinterpret_cast<GtkWidget*>(gobject_); }

private:


public:


  /** Converts this widget to a reference counted Gtk::ConstraintTarget.
   * Useful in calls to Gtk::Constraint::create().
   */
  auto make_refptr_constrainttarget() -> Glib::RefPtr<ConstraintTarget>;

  /** Converts this widget to a reference counted Gtk::ConstraintTarget.
   */
  auto make_refptr_constrainttarget() const -> Glib::RefPtr<const ConstraintTarget>;


  /** Flags a widget to be displayed.
   *
   * Any widget that isn’t shown will not appear on the screen.
   *
   * Remember that you have to show the containers containing a widget,
   * in addition to the widget itself, before it will appear onscreen.
   *
   * When a toplevel container is shown, it is immediately realized and
   * mapped; other shown widgets are realized and mapped when their
   * toplevel container is realized and mapped.
   */
  void show();

  /** Reverses the effects of show().
   *
   * This is causing the widget to be hidden (invisible to the user).
   */
  void hide();

/* QUEUE DRAWS */


  /** Schedules this widget to be redrawn in the paint phase
   * of the current or the next frame.
   *
   * This means @a widget's snapshot_vfunc()
   * implementation will be called.
   */
  void queue_draw();

  /** Flags a widget to have its size renegotiated.
   *
   * This should be called when a widget for some reason has a new
   * size request. For example, when you change the text in a
   * Gtk::Label, the label queues a resize to ensure there’s
   * enough space for the new text.
   *
   * Note that you cannot call queue_resize() on a widget
   * from inside its implementation of the size_allocate_vfunc()
   * virtual method. Calls to queue_resize() from inside
   * size_allocate_vfunc() will be silently ignored.
   *
   * This function is only for use in widget implementations.
   */
  void queue_resize();

  /** Flags the widget for a rerun of the size_allocate_vfunc()
   * function.
   *
   * Use this function instead of queue_resize()
   * when the @a widget's size request didn't change but it wants to
   * reposition its contents.
   *
   * An example user of this function is set_halign().
   *
   * This function is only for use in widget implementations.
   */
  void queue_allocate();


  /** Allocates widget with a transformation that translates
   * the origin to the position in @a allocation.
   *
   * This is a simple form of allocate().
   *
   * @param allocation Position and size to be allocated to @a widget.
   * @param baseline The baseline of the child, or -1.
   */
  void size_allocate(const Allocation& allocation, int baseline);


  /** Gets whether the widget prefers a height-for-width layout
   * or a width-for-height layout.
   *
   * Single-child widgets generally propagate the preference of
   * their child, more complex widgets need to request something
   * either in context of their children or in context of their
   * allocation capabilities.
   *
   * @return The `Gtk::SizeRequestMode` preferred by @a widget.
   */
  auto get_request_mode() const -> SizeRequestMode;

  /** Measures @a widget in the orientation @a orientation and for the given @a for_size.
   *
   * As an example, if @a orientation is Gtk::Orientation::HORIZONTAL and @a for_size
   * is 300, this functions will compute the minimum and natural width of @a widget
   * if it is allocated at a height of 300 pixels.
   *
   * See [GtkWidget’s geometry management section](class.Widget.html#height-for-width-geometry-management) for
   * a more details on implementing `GtkWidgetClass.measure()`.
   *
   * @param orientation The orientation to measure.
   * @param for_size Size for the opposite of @a orientation, i.e.
   * if @a orientation is Gtk::Orientation::HORIZONTAL, this is
   * the height the widget should be measured with. The Gtk::Orientation::VERTICAL
   * case is analogous. This way, both height-for-width and width-for-height
   * requests can be implemented. If no size is known, -1 can be passed.
   * @param minimum Location to store the minimum size.
   * @param natural Location to store the natural size.
   * @param minimum_baseline Location to store the baseline
   * position for the minimum size, or -1 to report no baseline.
   * @param natural_baseline Location to store the baseline
   * position for the natural size, or -1 to report no baseline.
   */
  void measure(Orientation orientation, int for_size, int& minimum, int& natural, int& minimum_baseline, int& natural_baseline) const;

  /** Retrieves the minimum and natural size of a widget, taking
   * into account the widget’s preference for height-for-width management.
   *
   * This is used to retrieve a suitable size by container widgets which do
   * not impose any restrictions on the child placement. It can be used
   * to deduce toplevel window and menu sizes as well as child widgets in
   * free-form containers such as `Gtk::Fixed`.
   *
   * Handle with care. Note that the natural height of a height-for-width
   * widget will generally be a smaller size than the minimum height, since
   * the required height for the natural width is generally smaller than the
   * required height for the minimum width.
   *
   * Use measure() if you want to support baseline alignment.
   *
   * @param minimum_size Location for storing the minimum size.
   * @param natural_size Location for storing the natural size.
   */
  void get_preferred_size(Requisition& minimum_size, Requisition& natural_size) const;


  /** Sets the layout manager delegate instance that provides an
   * implementation for measuring and allocating the children of @a widget.
   *
   * @param layout_manager A `Gtk::LayoutManager`.
   */

  void set_layout_manager(const Glib::RefPtr<LayoutManager>& layout_manager);
  /** Undoes the effect of a previous call to set_layout_manager().
   */
  void unset_layout_manager();

  /** Retrieves the layout manager used by @a widget.
   *
   * See set_layout_manager().
   *
   * @return A `Gtk::LayoutManager`.
   */
  auto get_layout_manager() -> Glib::RefPtr<LayoutManager>;

  /** Retrieves the layout manager used by @a widget.
   *
   * See set_layout_manager().
   *
   * @return A `Gtk::LayoutManager`.
   */
  auto get_layout_manager() const -> Glib::RefPtr<const LayoutManager>;


  /** Emits the signal_mnemonic_activate() signal.
   *
   * See signal_mnemonic_activate().
   *
   * @param group_cycling <tt>true</tt> if there are other widgets with the same mnemonic.
   * @return <tt>true</tt> if the signal has been handled.
   */
  auto mnemonic_activate(bool group_cycling) -> bool;


  /** For widgets that can be “activated” (buttons, menu items, etc.)
   * this function activates them.
   *
   * The activation will emit the signal set using
   * gtk_widget_class_set_activate_signal() during class initialization.
   *
   * Activation is what happens when you press Enter on a widget during
   * key navigation.
   *
   * If you wish to handle the activation keybinding yourself, it is
   * recommended to use gtk_widget_class_add_shortcut() with an action
   * created with Gtk::SignalAction::create().
   *
   * @return <tt>true</tt> if the widget was activatable, else <tt>false</tt>.
   */
  auto activate() -> bool;


  /** Specifies whether the input focus can enter the widget
   * or any of its children.
   *
   * Applications should set @a can_focus to <tt>false</tt> to mark a
   * widget as for pointer/touch use only.
   *
   * Note that having @a can_focus be <tt>true</tt> is only one of the
   * necessary conditions for being focusable. A widget must
   * also be sensitive and focusable and not have an ancestor
   * that is marked as not can-focus in order to receive input
   * focus.
   *
   * See grab_focus() for actually setting
   * the input focus on a widget.
   *
   * @param can_focus Whether or not the input focus can enter
   * the widget or any of its children.
   */
  void set_can_focus(bool can_focus =  true);

  /** Determines whether the input focus can enter @a widget or any
   * of its children.
   *
   * See set_focusable().
   *
   * @return <tt>true</tt> if the input focus can enter @a widget, <tt>false</tt> otherwise.
   */
  auto get_can_focus() const -> bool;

  /** Specifies whether @a widget can own the input focus.
   *
   * Widget implementations should set @a focusable to <tt>true</tt> in
   * their init() function if they want to receive keyboard input.
   *
   * Note that having @a focusable be <tt>true</tt> is only one of the
   * necessary conditions for being focusable. A widget must
   * also be sensitive and can-focus and not have an ancestor
   * that is marked as not can-focus in order to receive input
   * focus.
   *
   * See grab_focus() for actually setting
   * the input focus on a widget.
   *
   * @param focusable Whether or not @a widget can own the input focus.
   */
  void set_focusable(bool focusable =  true);

  /** Determines whether @a widget can own the input focus.
   *
   * See set_focusable().
   *
   * @return <tt>true</tt> if @a widget can own the input focus, <tt>false</tt> otherwise.
   */
  auto get_focusable() const -> bool;

  /** Determines if the widget has the global input focus.
   *
   * See is_focus() for the difference between
   * having the global input focus, and only having the focus
   * within a toplevel.
   *
   * @return <tt>true</tt> if the widget has the global input focus.
   */
  auto has_focus() const -> bool;


  /** Determines if the widget is the focus widget within its
   * toplevel.
   *
   * This does not mean that the property_has_focus()
   * property is necessarily set; property_has_focus()
   * will only be set if the toplevel widget additionally has the
   * global input focus.
   *
   * @return <tt>true</tt> if the widget is the focus widget.
   */
  auto is_focus() const -> bool;

  /** Determines if the widget should show a visible indication that
   * it has the global input focus.
   *
   * This is a convenience function that takes into account whether
   * focus indication should currently be shown in the toplevel window
   * of @a widget. See Gtk::Window::get_focus_visible() for more
   * information about focus indication.
   *
   * To find out if the widget has the global input focus, use
   * has_focus().
   *
   * @return <tt>true</tt> if the widget should display a “focus rectangle”.
   */
  auto has_visible_focus() const -> bool;

  /** Causes @a widget to have the keyboard focus for the `Gtk::Window` it's inside.
   *
   * If @a widget is not focusable, or its grab_focus_vfunc()
   * implementation cannot transfer the focus to a descendant of @a widget
   * that is focusable, it will not take focus and <tt>false</tt> will be returned.
   *
   * Calling grab_focus() on an already focused widget
   * is allowed, should not have an effect, and return <tt>true</tt>.
   *
   * @return <tt>true</tt> if focus is now inside @a widget.
   */
  auto grab_focus() -> bool;

  /** Sets whether the widget should grab focus when it is clicked
   * with the mouse.
   *
   * Making mouse clicks not grab focus is useful in places like
   * toolbars where you don’t want the keyboard focus removed from
   * the main area of the application.
   *
   * @param focus_on_click Whether the widget should grab focus when clicked
   * with the mouse.
   */
  void set_focus_on_click(bool focus_on_click =  true);

  /** Returns whether the widget should grab focus when it is clicked
   * with the mouse.
   *
   * See set_focus_on_click().
   *
   * @return <tt>true</tt> if the widget should grab focus when it is
   * clicked with the mouse.
   */
  auto get_focus_on_click() const -> bool;

  /** Sets whether @a widget can be the target of pointer events.
   *
   * @param can_target Whether this widget should be able to
   * receive pointer events.
   */
  void set_can_target(bool can_target =  true);

  /** Queries whether @a widget can be the target of pointer events.
   *
   * @return <tt>true</tt> if @a widget can receive pointer events.
   */
  auto get_can_target() const -> bool;

  /** Determines whether @a widget is the current default widget
   * within its toplevel.
   *
   * @return <tt>true</tt> if @a widget is the current default widget
   * within its toplevel, <tt>false</tt> otherwise.
   */
  auto has_default() const -> bool;

  /** Specifies whether @a widget will be treated as the default
   * widget within its toplevel when it has the focus, even if
   * another widget is the default.
   *
   * @param receives_default Whether or not @a widget can be a default widget.
   */
  void set_receives_default(bool receives_default =  true);

  /** Determines whether @a widget is always treated as the default widget
   * within its toplevel when it has the focus, even if another widget
   * is the default.
   *
   * See set_receives_default().
   *
   * @return <tt>true</tt> if @a widget acts as the default widget when focused,
   * <tt>false</tt> otherwise.
   */
  auto get_receives_default() const -> bool;


  /** Sets a widgets name.
   *
   * Setting a name allows you to refer to the widget from a
   * CSS file. You can apply a style to widgets with a particular name
   * in the CSS file. See the documentation for the CSS syntax (on the
   * same page as the docs for Gtk::StyleContext.
   *
   * Note that the CSS syntax has certain special characters to delimit
   * and represent elements in a selector (period, #, >, *...), so using
   * these will make your widget impossible to match by name. Any combination
   * of alphanumeric symbols, dashes and underscores will suffice.
   *
   * @param name Name for the widget.
   */
  void set_name(const Glib::ustring& name);
  void unset_name();

  /** Retrieves the name of a widget.
   *
   * See set_name() for the significance of widget names.
   *
   * @return Name of the widget. This string is owned by GTK and
   * should not be modified or freed.
   */
  auto get_name() const -> Glib::ustring;


  /** Turns on flag values in the current widget state.
   *
   * Typical widget states are insensitive, prelighted, etc.
   *
   * This function accepts the values Gtk::StateFlags::DIR_LTR and
   * Gtk::StateFlags::DIR_RTL but ignores them. If you want to set
   * the widget's direction, use set_direction().
   *
   * This function is for use in widget implementations.
   *
   * @param flags State flags to turn on.
   * @param clear Whether to clear state before turning on @a flags.
   */
  void set_state_flags(StateFlags flags, bool clear =  true);

  /** Turns off flag values for the current widget state.
   *
   * See set_state_flags().
   *
   * This function is for use in widget implementations.
   *
   * @param flags State flags to turn off.
   */
  void unset_state_flags(StateFlags flags);

  /** Returns the widget state as a flag set.
   *
   * It is worth mentioning that the effective Gtk::StateFlags::INSENSITIVE
   * state will be returned, that is, also based on parent insensitivity,
   * even if @a widget itself is sensitive.
   *
   * Also note that if you are looking for a way to obtain the
   * Gtk::StateFlags to pass to a Gtk::StyleContext
   * method, you should look at Gtk::StyleContext::get_state().
   *
   * @return The state flags for widget.
   */
  auto get_state_flags() const -> StateFlags;


  /** Sets the sensitivity of a widget.
   *
   * A widget is sensitive if the user can interact with it.
   * Insensitive widgets are “grayed out” and the user can’t
   * interact with them. Insensitive widgets are known as
   * “inactive”, “disabled”, or “ghosted” in some other toolkits.
   *
   * @param sensitive <tt>true</tt> to make the widget sensitive.
   */
  void set_sensitive(bool sensitive =  true);

  /** Returns the widget’s sensitivity.
   *
   * This function returns the value that has been set using
   * set_sensitive()).
   *
   * The effective sensitivity of a widget is however determined
   * by both its own and its parent widget’s sensitivity.
   * See is_sensitive().
   *
   * @return <tt>true</tt> if the widget is sensitive.
   */
  auto get_sensitive() const -> bool;

  /** Returns the widget’s effective sensitivity.
   *
   * This means it is sensitive itself and also its
   * parent widget is sensitive.
   *
   * @return <tt>true</tt> if the widget is effectively sensitive.
   */
  auto is_sensitive() const -> bool;

  /** Sets the visibility state of @a widget.
   *
   * Note that setting this to <tt>true</tt> doesn’t mean the widget is
   * actually viewable, see get_visible().
   *
   * This function simply calls show() or
   * hide() but is nicer to use when the
   * visibility of the widget depends on some condition.
   *
   * @param visible Whether the widget should be shown or not.
   */
  void set_visible(bool visible =  true);

  /** Determines whether the widget is visible.
   *
   * If you want to take into account whether the widget’s
   * parent is also marked as visible, use
   * is_visible() instead.
   *
   * This function does not check if the widget is
   * obscured in any way.
   *
   * See set_visible().
   *
   * @return <tt>true</tt> if the widget is visible.
   */
  auto get_visible() const -> bool;

  /** Determines whether the widget and all its parents are marked as
   * visible.
   *
   * This function does not check if the widget is obscured in any way.
   *
   * See also get_visible() and
   * set_visible().
   *
   * @return <tt>true</tt> if the widget and all its parents are visible.
   */
  auto is_visible() const -> bool;

  /** Determines whether @a widget can be drawn to.
   *
   * A widget can be drawn if it is mapped and visible.
   *
   * @return <tt>true</tt> if @a widget is drawable, <tt>false</tt> otherwise.
   */
  auto is_drawable() const -> bool;

  /** Determines whether @a widget is realized.
   *
   * @return <tt>true</tt> if @a widget is realized, <tt>false</tt> otherwise.
   */
  auto get_realized() const -> bool;

  /** Whether the widget is mapped.
   *
   * @return <tt>true</tt> if the widget is mapped, <tt>false</tt> otherwise.
   */
  auto get_mapped() const -> bool;


  /** Sets whether @a widget should be mapped along with its parent.
   *
   * The child visibility can be set for widget before it is added
   * to a container with set_parent(), to avoid
   * mapping children unnecessary before immediately unmapping them.
   * However it will be reset to its default state of <tt>true</tt> when the
   * widget is removed from a container.
   *
   * Note that changing the child visibility of a widget does not
   * queue a resize on the widget. Most of the time, the size of
   * a widget is computed from all visible children, whether or
   * not they are mapped. If this is not the case, the container
   * can queue a resize itself.
   *
   * This function is only useful for container implementations
   * and should never be called by an application.
   *
   * @param visible If <tt>true</tt>, @a widget should be mapped along
   * with its parent.
   */
  void set_child_visible(bool visible =  true);

  /** Gets the value set with set_child_visible().
   *
   * If you feel a need to use this function, your code probably
   * needs reorganization.
   *
   * This function is only useful for container implementations
   * and should never be called by an application.
   *
   * @return <tt>true</tt> if the widget is mapped with the parent.
   */
  auto get_child_visible() const -> bool;


  /** Returns the width that has currently been allocated to @a widget.
   *
   * @return The width of the @a widget.
   */
  auto get_allocated_width() const -> int;

  /** Returns the height that has currently been allocated to @a widget.
   *
   * @return The height of the @a widget.
   */
  auto get_allocated_height() const -> int;

  /** Returns the baseline that has currently been allocated to @a widget.
   *
   * This function is intended to be used when implementing handlers
   * for the `Gtk::Widget`Class.snapshot() function, and when allocating
   * child widgets in `Gtk::Widget`Class.size_allocate().
   *
   * @return The baseline of the @a widget, or -1 if none.
   */
  auto get_allocated_baseline() const -> int;

  /** Retrieves the widget’s location.
   * Note, when implementing a layout container: a widget’s allocation will be its “adjusted” allocation,
   * that is, the widget’s parent container typically calls size_allocate() with an allocation,
   * and that allocation is then adjusted (to handle margin and alignment for example) before
   * assignment to the widget. get_allocation() returns the adjusted allocation that was actually
   * assigned to the widget. The adjusted allocation is guaranteed to be completely contained
   * within the size_allocate() allocation, however.
   *
   * So a layout container is guaranteed that its children stay inside the assigned bounds, but not that
   * they have exactly the bounds the container assigned.
   *
   * @return The widget’s allocated area.
   */
  auto get_allocation() const -> Allocation;


  /** Returns the content width of the widget.
   *
   * This function returns the width passed to its
   * size-allocate implementation, which is the width you
   * should be using in snapshot_vfunc().
   *
   * For pointer events, see contains().
   *
   * @return The width of @a widget.
   */
  auto get_width() const -> int;

  /** Returns the content height of the widget.
   *
   * This function returns the height passed to its
   * size-allocate implementation, which is the height you
   * should be using in snapshot_vfunc().
   *
   * For pointer events, see contains().
   *
   * @return The height of @a widget.
   */
  auto get_height() const -> int;

  /** Returns the content width or height of the widget.
   *
   * Which dimension is returned depends on @a orientation.
   *
   * This is equivalent to calling get_width()
   * for Gtk::Orientation::HORIZONTAL or get_height()
   * for Gtk::Orientation::VERTICAL, but can be used when
   * writing orientation-independent code, such as when
   * implementing Gtk::Orientable widgets.
   *
   * @param orientation The orientation to query.
   * @return The size of @a widget in @a orientation.
   */
  auto get_size(Orientation orientation) const -> int;


  /** Returns the parent widget of @a widget.
   *
   * @return The parent widget of @a widget.
   */
  auto get_parent() -> Widget*;

  /** Returns the parent widget of @a widget.
   *
   * @return The parent widget of @a widget.
   */
  auto get_parent() const -> const Widget*;


  /** Returns the `Gtk::Root` widget of @a widget.
   *
   * This function will return <tt>nullptr</tt> if the widget is not contained
   * inside a widget tree with a root widget.
   *
   * `Gtk::Root` widgets will return themselves here.
   *
   * @return The root widget of @a widget.
   */
  auto get_root() -> Root*;

  /** Returns the `Gtk::Root` widget of @a widget.
   *
   * This function will return <tt>nullptr</tt> if the widget is not contained
   * inside a widget tree with a root widget.
   *
   * `Gtk::Root` widgets will return themselves here.
   *
   * @return The root widget of @a widget.
   */
  auto get_root() const -> const Root*;


  /** Returns the nearest `Gtk::Native` ancestor of @a widget.
   *
   * This function will return <tt>nullptr</tt> if the widget is not
   * contained inside a widget tree with a native ancestor.
   *
   * `Gtk::Native` widgets will return themselves here.
   *
   * @return The `Gtk::Native` ancestor of @a widget.
   */
  auto get_native() -> Native*;

  /** Returns the nearest `Gtk::Native` ancestor of @a widget.
   *
   * This function will return <tt>nullptr</tt> if the widget is not
   * contained inside a widget tree with a native ancestor.
   *
   * `Gtk::Native` widgets will return themselves here.
   *
   * @return The `Gtk::Native` ancestor of @a widget.
   */
  auto get_native() const -> const Native*;


  /** Called by widgets as the user moves around the window using
   * keyboard shortcuts.
   *
   * The @a direction argument indicates what kind of motion is taking place (up,
   * down, left, right, tab forward, tab backward).
   *
   * This function calls the focus_vfunc() virtual function; widgets
   * can override the virtual function in order to implement appropriate focus
   * behavior.
   *
   * The default `focus()` virtual function for a widget should return <tt>true</tt> if
   * moving in @a direction left the focus on a focusable location inside that
   * widget, and <tt>false</tt> if moving in @a direction moved the focus outside the
   * widget. When returning <tt>true</tt>, widgets normally call grab_focus()
   * to place the focus accordingly; when returning <tt>false</tt>, they don’t modify
   * the current focus location.
   *
   * This function is used by custom widget implementations; if you're
   * writing an app, you’d use grab_focus() to move
   * the focus to a particular widget.
   *
   * @param direction Direction of focus movement.
   * @return <tt>true</tt> if focus ended up inside @a widget.
   */
  auto child_focus(DirectionType direction) -> bool;


  /** Emits the `::keynav-failed` signal on the widget.
   *
   * This function should be called whenever keyboard navigation
   * within a single widget hits a boundary.
   *
   * The return value of this function should be interpreted
   * in a way similar to the return value of
   * child_focus(). When <tt>true</tt> is returned,
   * stay in the widget, the failed keyboard  navigation is OK
   * and/or there is nowhere we can/should move the focus to.
   * When <tt>false</tt> is returned, the caller should continue with
   * keyboard navigation outside the widget, e.g. by calling
   * child_focus() on the widget’s toplevel.
   *
   * The default signal_keynav_failed() handler returns
   * <tt>false</tt> for Gtk::DirectionType::TAB_FORWARD and Gtk::DirectionType::TAB_BACKWARD.
   * For the other values of `Gtk::DirectionType` it returns <tt>true</tt>.
   *
   * Whenever the default handler returns <tt>true</tt>, it also calls
   * error_bell() to notify the user of the
   * failed keyboard navigation.
   *
   * A use case for providing an own implementation of signal_keynav_failed()
   * (either by connecting to it or by overriding it) would be a row of
   * Gtk::Entry widgets where the user should be able to navigate
   * the entire row with the cursor keys, as e.g. known from user
   * interfaces that require entering license keys.
   *
   * @param direction Direction of focus movement.
   * @return <tt>true</tt> if stopping keyboard navigation is fine, <tt>false</tt>
   * if the emitting widget should try to handle the keyboard
   * navigation attempt in its parent container(s).
   */
  auto keynav_failed(DirectionType direction) -> bool;

  /** Notifies the user about an input-related error on this widget.
   * If the Gtk::Settings gtk-error-bell property is true, it calls
   * Gdk::Surface::beep(), otherwise it does nothing.
   *
   * Note that the effect of Gdk::Surface::beep() can be configured in many
   * ways, depending on the windowing backend and the desktop environment
   * or window manager that is used.
   *
   * @newin{2,12}
   */
  void error_bell();


  /** Sets the minimum size of a widget.
   *
   * That is, the widget’s size request will be at least @a width
   * by @a height. You can use this function to force a widget to
   * be larger than it normally would be.
   *
   * In most cases, Gtk::Window::set_default_size() is a better
   * choice for toplevel windows than this function; setting the default
   * size will still allow users to shrink the window. Setting the size
   * request will force them to leave the window at least as large as
   * the size request.
   *
   * Note the inherent danger of setting any fixed size - themes,
   * translations into other languages, different fonts, and user action
   * can all change the appropriate size for a given widget. So, it's
   * basically impossible to hardcode a size that will always be
   * correct.
   *
   * The size request of a widget is the smallest size a widget can
   * accept while still functioning well and drawing itself correctly.
   * However in some strange cases a widget may be allocated less than
   * its requested size, and in many cases a widget may be allocated more
   * space than it requested.
   *
   * If the size request in a given direction is -1 (unset), then
   * the “natural” size request of the widget will be used instead.
   *
   * The size request set here does not include any margin from the
   * properties
   * property_margin_start(),
   * property_margin_end(),
   * property_margin_top(), and
   * property_margin_bottom(), but it does include pretty
   * much all other padding or border properties set by any subclass
   * of `Gtk::Widget`.
   *
   * @param width Width @a widget should request, or -1 to unset.
   * @param height Height @a widget should request, or -1 to unset.
   */
  void set_size_request(int width =  -1, int height =  -1);

  /** Gets the size request that was explicitly set for the widget using
   * set_size_request().
   *
   * A value of -1 stored in @a width or @a height indicates that that
   * dimension has not been set explicitly and the natural requisition
   * of the widget will be used instead. See
   * set_size_request(). To get the size a widget will
   * actually request, call measure() instead of
   * this function.
   *
   * @param width Return location for width.
   * @param height Return location for height.
   */
  void get_size_request(int& width, int& height) const;


  /** Request the @a widget to be rendered partially transparent.
   *
   * An opacity of 0 is fully transparent and an opacity of 1
   * is fully opaque.
   *
   * Opacity works on both toplevel widgets and child widgets, although
   * there are some limitations: For toplevel widgets, applying opacity
   * depends on the capabilities of the windowing system. On X11, this
   * has any effect only on X displays with a compositing manager,
   * see gdk_display_is_composited(). On Windows and Wayland it should
   * always work, although setting a window’s opacity after the window
   * has been shown may cause some flicker.
   *
   * Note that the opacity is inherited through inclusion — if you set
   * a toplevel to be partially translucent, all of its content will
   * appear translucent, since it is ultimatively rendered on that
   * toplevel. The opacity value itself is not inherited by child
   * widgets (since that would make widgets deeper in the hierarchy
   * progressively more translucent). As a consequence, Gtk::Popovers
   * and other Gtk::Native widgets with their own surface will use their
   * own opacity value, and thus by default appear non-translucent,
   * even if they are attached to a toplevel that is translucent.
   *
   * @param opacity Desired opacity, between 0 and 1.
   */
  void set_opacity(double opacity);

  /** #Fetches the requested opacity for this widget.
   *
   * See set_opacity().
   *
   * @return The requested opacity for this widget.
   */
  auto get_opacity() const -> double;


  /** Sets how @a widget treats content that is drawn outside the
   * widget's content area.
   *
   * See the definition of Gtk::Overflow for details.
   *
   * This setting is provided for widget implementations and
   * should not be used by application code.
   *
   * The default value is Gtk::Overflow::VISIBLE.
   *
   * @newin{3,96}
   *
   * @param overflow Desired overflow.
   */
  void set_overflow(Overflow overflow);

  /** Returns the widgets overflow value.
   *
   * @newin{3,96}
   *
   * @return The widget's overflow.
   */
  auto get_overflow() const -> Overflow;


  /** Gets the first ancestor of @a widget with type @a widget_type.
   *
   * For example, `gtk_widget_get_ancestor (widget, GTK_TYPE_BOX)`
   * gets the first `Gtk::Box` that’s an ancestor of @a widget. No
   * reference will be added to the returned widget; it should
   * not be unreferenced.
   *
   * Note that unlike is_ancestor(), this function
   * considers @a widget to be an ancestor of itself.
   *
   * @param widget_type Ancestor type.
   * @return The ancestor widget.
   */
  auto get_ancestor(GType widget_type) -> Widget*;

  /** Gets the first ancestor of @a widget with type @a widget_type.
   *
   * For example, `gtk_widget_get_ancestor (widget, GTK_TYPE_BOX)`
   * gets the first `Gtk::Box` that’s an ancestor of @a widget. No
   * reference will be added to the returned widget; it should
   * not be unreferenced.
   *
   * Note that unlike is_ancestor(), this function
   * considers @a widget to be an ancestor of itself.
   *
   * @param widget_type Ancestor type.
   * @return The ancestor widget.
   */
  auto get_ancestor(GType widget_type) const -> const Widget*;


  /** Retrieves the internal scale factor that maps from window
   * coordinates to the actual device pixels.
   *
   * On traditional systems this is 1, on high density outputs,
   * it can be a higher value (typically 2).
   *
   * See Gdk::Surface::get_scale_factor().
   *
   * @return The scale factor for @a widget.
   */
  auto get_scale_factor() const -> int;


  /** Get the `Gdk::Display` for the toplevel window associated with
   * this widget.
   *
   * This function can only be called after the widget has been
   * added to a widget hierarchy with a `Gtk::Window` at the top.
   *
   * In general, you should only create display specific
   * resources when a widget has been realized, and you should
   * free those resources when the widget is unrealized.
   *
   * @return The `Gdk::Display` for the toplevel
   * for this widget.
   */
  auto get_display() -> Glib::RefPtr<Gdk::Display>;

  /** Get the `Gdk::Display` for the toplevel window associated with
   * this widget.
   *
   * This function can only be called after the widget has been
   * added to a widget hierarchy with a `Gtk::Window` at the top.
   *
   * In general, you should only create display specific
   * resources when a widget has been realized, and you should
   * free those resources when the widget is unrealized.
   *
   * @return The `Gdk::Display` for the toplevel
   * for this widget.
   */
  auto get_display() const -> Glib::RefPtr<const Gdk::Display>;


  /** Gets the settings object holding the settings used for this widget.
   *
   * Note that this function can only be called when the `Gtk::Widget`
   * is attached to a toplevel, since the settings object is specific
   * to a particular `Gdk::Display`. If you want to monitor the widget for
   * changes in its settings, connect to the `notify::display` signal.
   *
   * @return The relevant `Gtk::Settings` object.
   */
  auto get_settings() -> Glib::RefPtr<Settings>;


  /** Gets the clipboard object for @a widget.
   *
   * This is a utility function to get the clipboard object for the
   * `Gdk::Display` that @a widget is using.
   *
   * Note that this function always works, even when @a widget is not
   * realized yet.
   *
   * @return The appropriate clipboard object.
   */
  auto get_clipboard() -> Glib::RefPtr<Gdk::Clipboard>;

  /** Gets the clipboard object for @a widget.
   *
   * This is a utility function to get the clipboard object for the
   * `Gdk::Display` that @a widget is using.
   *
   * Note that this function always works, even when @a widget is not
   * realized yet.
   *
   * @return The appropriate clipboard object.
   */
  auto get_clipboard() const -> Glib::RefPtr<const Gdk::Clipboard>;

  /** Gets the primary clipboard of @a widget.
   *
   * This is a utility function to get the primary clipboard object
   * for the `Gdk::Display` that @a widget is using.
   *
   * Note that this function always works, even when @a widget is not
   * realized yet.
   *
   * @return The appropriate clipboard object.
   */
  auto get_primary_clipboard() -> Glib::RefPtr<Gdk::Clipboard>;

  /** Gets the primary clipboard of @a widget.
   *
   * This is a utility function to get the primary clipboard object
   * for the `Gdk::Display` that @a widget is using.
   *
   * Note that this function always works, even when @a widget is not
   * realized yet.
   *
   * @return The appropriate clipboard object.
   */
  auto get_primary_clipboard() const -> Glib::RefPtr<const Gdk::Clipboard>;


  /** Gets whether the widget would like any available extra horizontal
   * space.
   *
   * When a user resizes a `Gtk::Window`, widgets with expand=<tt>true</tt>
   * generally receive the extra space. For example, a list or
   * scrollable area or document in your window would often be set to
   * expand.
   *
   * Containers should use compute_expand() rather
   * than this function, to see whether a widget, or any of its children,
   * has the expand flag set. If any child of a widget wants to
   * expand, the parent may ask to expand also.
   *
   * This function only looks at the widget’s own hexpand flag, rather
   * than computing whether the entire widget tree rooted at this widget
   * wants to expand.
   *
   * @return Whether hexpand flag is set.
   */
  auto get_hexpand() const -> bool;

  /** Sets whether the widget would like any available extra horizontal
   * space.
   *
   * When a user resizes a `Gtk::Window`, widgets with expand=<tt>true</tt>
   * generally receive the extra space. For example, a list or
   * scrollable area or document in your window would often be set to
   * expand.
   *
   * Call this function to set the expand flag if you would like your
   * widget to become larger horizontally when the window has extra
   * room.
   *
   * By default, widgets automatically expand if any of their children
   * want to expand. (To see if a widget will automatically expand given
   * its current children and state, call compute_expand().
   * A container can decide how the expandability of children affects the
   * expansion of the container by overriding the compute_expand virtual
   * method on `Gtk::Widget`.).
   *
   * Setting hexpand explicitly with this function will override the
   * automatic expand behavior.
   *
   * This function forces the widget to expand or not to expand,
   * regardless of children.  The override occurs because
   * set_hexpand() sets the hexpand-set property (see
   * set_hexpand_set()) which causes the widget’s hexpand
   * value to be used, rather than looking at children and widget state.
   *
   * @param expand Whether to expand.
   */
  void set_hexpand(bool expand =  true);

  /** Gets whether set_hexpand() has been used
   * to explicitly set the expand flag on this widget.
   *
   * If property_hexpand() property is set, then it
   * overrides any computed expand value based on child widgets.
   * If `hexpand` is not set, then the expand value depends on
   * whether any children of the widget would like to expand.
   *
   * There are few reasons to use this function, but it’s here
   * for completeness and consistency.
   *
   * @return Whether hexpand has been explicitly set.
   */
  auto get_hexpand_set() const -> bool;

  /** Sets whether the hexpand flag will be used.
   *
   * The property_hexpand_set() property will be set
   * automatically when you call set_hexpand()
   * to set hexpand, so the most likely reason to use this function
   * would be to unset an explicit expand flag.
   *
   * If hexpand is set, then it overrides any computed
   * expand value based on child widgets. If hexpand is not
   * set, then the expand value depends on whether any
   * children of the widget would like to expand.
   *
   * There are few reasons to use this function, but it’s here
   * for completeness and consistency.
   *
   * @param set Value for hexpand-set property.
   */
  void set_hexpand_set(bool set =  true);

  /** Gets whether the widget would like any available extra vertical
   * space.
   *
   * See get_hexpand() for more detail.
   *
   * @return Whether vexpand flag is set.
   */
  auto get_vexpand() const -> bool;

  /** Sets whether the widget would like any available extra vertical
   * space.
   *
   * See set_hexpand() for more detail.
   *
   * @param expand Whether to expand.
   */
  void set_vexpand(bool expand =  true);

  /** Gets whether set_vexpand() has been used to
   * explicitly set the expand flag on this widget.
   *
   * See get_hexpand_set() for more detail.
   *
   * @return Whether vexpand has been explicitly set.
   */
  auto get_vexpand_set() const -> bool;

  /** Sets whether the vexpand flag will be used.
   *
   * See set_hexpand_set() for more detail.
   *
   * @param set Value for vexpand-set property.
   */
  void set_vexpand_set(bool set =  true);

  /** Computes whether a container should give this widget
   * extra space when possible.
   *
   * Containers should check this, rather than looking at
   * get_hexpand() or get_vexpand().
   *
   * This function already checks whether the widget is visible, so
   * visibility does not need to be checked separately. Non-visible
   * widgets are not expanded.
   *
   * The computed expand value uses either the expand setting explicitly
   * set on the widget itself, or, if none has been explicitly set,
   * the widget may expand if some of its children do.
   *
   * @param orientation Expand direction.
   * @return Whether widget tree rooted here should be expanded.
   */
  auto compute_expand(Orientation orientation) -> bool;

  /** Sets whether the widget would like any available extra space in both directions.
   *
   * @see set_hexpand() for more detail.
   * @param expand Whether to expand in horizontal and vertical direction.
   */
  void set_expand(bool expand = true);


  /** Gets the horizontal alignment of @a widget.
   *
   * For backwards compatibility reasons this method will never return
   * Gtk::Align::BASELINE, but instead it will convert it to
   * Gtk::Align::FILL. Baselines are not supported for horizontal
   * alignment.
   *
   * @return The horizontal alignment of @a widget.
   */
  auto get_halign() const -> Align;

  /** Sets the horizontal alignment of @a widget.
   *
   * @param align The horizontal alignment.
   */
  void set_halign(Align align);

  /** Gets the vertical alignment of @a widget.
   *
   * @return The vertical alignment of @a widget.
   */
  auto get_valign() const -> Align;

  /** Sets the vertical alignment of @a widget.
   *
   * @param align The vertical alignment.
   */
  void set_valign(Align align);

  /** Gets the start margin of @a widget.
   *
   * @return The start margin of @a widget.
   */
  auto get_margin_start() const -> int;

  /** Sets the start margin of @a widget.
   *
   * @param margin The start margin.
   */
  void set_margin_start(int margin);

  /** Gets the end margin of @a widget.
   *
   * @return The end margin of @a widget.
   */
  auto get_margin_end() const -> int;

  /** Sets the end margin of @a widget.
   *
   * @param margin The end margin.
   */
  void set_margin_end(int margin);

  /** Gets the top margin of @a widget.
   *
   * @return The top margin of @a widget.
   */
  auto get_margin_top() const -> int;

  /** Sets the top margin of @a widget.
   *
   * @param margin The top margin.
   */
  void set_margin_top(int margin);

  /** Gets the bottom margin of @a widget.
   *
   * @return The bottom margin of @a widget.
   */
  auto get_margin_bottom() const -> int;

  /** Sets the bottom margin of @a widget.
   *
   * @param margin The bottom margin.
   */
  void set_margin_bottom(int margin);

  /** Set all 4 margins to the same value.
   * @param margin The start, end, top, and bottom margin.
   */
  void set_margin(int margin);


  /** Determines whether @a widget is somewhere inside @a ancestor,
   * possibly with intermediate containers.
   *
   * @param ancestor Another `Gtk::Widget`.
   * @return <tt>true</tt> if @a ancestor contains @a widget as a child,
   * grandchild, great grandchild, etc.
   */
  auto is_ancestor(Widget & ancestor) const -> bool;


  /** Translate coordinates relative to @a src_widget’s allocation
   * to coordinates relative to @a dest_widget’s allocations.
   *
   * In order to perform this operation, both widget must share
   * a common ancestor.
   *
   * @param dest_widget A `Gtk::Widget`.
   * @param src_x X position relative to @a src_widget.
   * @param src_y Y position relative to @a src_widget.
   * @param dest_x Location to store X position relative to @a dest_widget.
   * @param dest_y Location to store Y position relative to @a dest_widget.
   * @return <tt>false</tt> if @a src_widget and @a dest_widget have no common
   * ancestor. In this case, 0 is stored in * @a dest_x and * @a dest_y.
   * Otherwise <tt>true</tt>.
   */
  auto translate_coordinates(Widget& dest_widget, double src_x, double src_y, double& dest_x, double& dest_y) -> bool;


  /** Tests if the point at ( @a x, @a y) is contained in @a widget.
   *
   * The coordinates for ( @a x, @a y) must be in widget coordinates, so
   * (0, 0) is assumed to be the top left of @a widget's content area.
   *
   * @param x X coordinate to test, relative to @a widget's origin.
   * @param y Y coordinate to test, relative to @a widget's origin.
   * @return <tt>true</tt> if @a widget contains ( @a x, @a y).
   */
  auto contains(double x, double y) const -> bool;

  /** Finds the descendant of @a widget closest to the point ( @a x, @a y).
   *
   * The point must be given in widget coordinates, so (0, 0) is assumed
   * to be the top left of @a widget's content area.
   *
   * Usually widgets will return <tt>nullptr</tt> if the given coordinate is not
   * contained in @a widget checked via contains().
   * Otherwise they will recursively try to find a child that does
   * not return <tt>nullptr</tt>. Widgets are however free to customize their
   * picking algorithm.
   *
   * This function is used on the toplevel to determine the widget
   * below the mouse cursor for purposes of hover highlighting and
   * delivering events.
   *
   * @param x X coordinate to test, relative to @a widget's origin.
   * @param y Y coordinate to test, relative to @a widget's origin.
   * @param flags Flags to influence what is picked.
   * @return The widget descendant at
   * the given point.
   */
  auto pick(double x, double y, PickFlags flags =  PickFlags::DEFAULT) -> Widget*;

  /** Finds the descendant of @a widget closest to the point ( @a x, @a y).
   *
   * The point must be given in widget coordinates, so (0, 0) is assumed
   * to be the top left of @a widget's content area.
   *
   * Usually widgets will return <tt>nullptr</tt> if the given coordinate is not
   * contained in @a widget checked via contains().
   * Otherwise they will recursively try to find a child that does
   * not return <tt>nullptr</tt>. Widgets are however free to customize their
   * picking algorithm.
   *
   * This function is used on the toplevel to determine the widget
   * below the mouse cursor for purposes of hover highlighting and
   * delivering events.
   *
   * @param x X coordinate to test, relative to @a widget's origin.
   * @param y Y coordinate to test, relative to @a widget's origin.
   * @param flags Flags to influence what is picked.
   * @return The widget descendant at
   * the given point.
   */
  auto pick(double x, double y, PickFlags flags =  PickFlags::DEFAULT) const -> const Widget*;


  /** Adds @a controller to @a widget so that it will receive events.
   *
   * You will usually want to call this function right after
   * creating any kind of Gtk::EventController.
   *
   * @param controller A `Gtk::EventController` that hasn't been
   * added to a widget yet.
   */

  void add_controller(const Glib::RefPtr<EventController>& controller);

  /** Removes @a controller from @a widget, so that it doesn't process
   * events anymore.
   *
   * It should not be used again.
   *
   * Widgets will remove all event controllers automatically when they
   * are destroyed, there is normally no need to call this function.
   *
   * @param controller A `Gtk::EventController`.
   */
  void remove_controller(const Glib::RefPtr<EventController>& controller);


  /** Creates a new `Pango::Context` with the appropriate font map,
   * font options, font description, and base direction for drawing
   * text for this widget.
   *
   * See also get_pango_context().
   *
   * @return The new `Pango::Context`.
   */
  auto create_pango_context() -> Glib::RefPtr<Pango::Context>;

  /** Gets a `Pango::Context` with the appropriate font map, font description,
   * and base direction for this widget.
   *
   * Unlike the context returned by create_pango_context(),
   * this context is owned by the widget (it can be used until the screen
   * for the widget changes or the widget is removed from its toplevel),
   * and will be updated to match any changes to the widget’s attributes.
   * This can be tracked by listening to changes of the
   * property_root() property on the widget.
   *
   * @return The `Pango::Context` for the widget.
   */
  auto get_pango_context() -> Glib::RefPtr<Pango::Context>;


  /** Sets the `cairo_font_options_t` used for Pango rendering
   * in this widget.
   *
   * When not set, the default font options for the `Gdk::Display`
   * will be used.
   *
   * @param options A `cairo_font_options_t`
   * to unset any previously set default font options.
   */
  void set_font_options(const Cairo::FontOptions& options);
  /** Undoes the effect of previous calls to set_font_options().
   *
   * @newin{3,20}
   */
  void unset_font_options();
  // This returns a const, so we assume that we must copy it:


  /** Returns the `cairo_font_options_t` of widget.
   *
   * Seee set_font_options().
   *
   * @return The `cairo_font_options_t`
   * of widget.
   */
  auto get_font_options() const -> Cairo::FontOptions;


  /** Creates a new `Pango::Layout` with the appropriate font map,
   * font description, and base direction for drawing text for
   * this widget.
   *
   * If you keep a `Pango::Layout` created in this way around,
   * you need to re-create it when the widget `Pango::Context`
   * is replaced. This can be tracked by listening to changes
   * of the property_root() property on the widget.
   *
   * @param text Text to set on the layout.
   * @return The new `Pango::Layout`.
   */
  auto create_pango_layout(const Glib::ustring& text) -> Glib::RefPtr<Pango::Layout>;

/* Directionality of Text */


  /** Sets the reading direction on a particular widget.
   *
   * This direction controls the primary direction for widgets
   * containing text, and also the direction in which the children
   * of a container are packed. The ability to set the direction is
   * present in order so that correct localization into languages with
   * right-to-left reading directions can be done. Generally, applications
   * will let the default reading direction present, except for containers
   * where the containers are arranged in an order that is explicitly
   * visual rather than logical (such as buttons for text justification).
   *
   * If the direction is set to Gtk::TextDirection::NONE, then the value
   * set by set_default_direction() will be used.
   *
   * @param dir The new direction.
   */
  void set_direction(TextDirection dir);

  /** Gets the reading direction for a particular widget.
   *
   * See set_direction().
   *
   * @return The reading direction for the widget.
   */
  auto get_direction() const -> TextDirection;


  /** Sets the default reading direction for widgets.
   *
   * See set_direction().
   *
   * @param dir The new default direction. This cannot be Gtk::TextDirection::NONE.
   */
  static void set_default_direction(TextDirection dir);

  /** Obtains the current default reading direction.
   *
   * See set_default_direction().
   *
   * @return The current default direction.
   */
  static auto get_default_direction() -> TextDirection;


  /** Sets the cursor to be shown when pointer devices point
   * towards @a widget.
   *
   * If the @a cursor is <tt>nullptr</tt>, @a widget will use the cursor
   * inherited from the parent widget.
   *
   * @param cursor The new cursor.
   */
  void set_cursor(const Glib::RefPtr<Gdk::Cursor>& cursor);


  /** Sets a named cursor to be shown when pointer devices point towards the widget.
   *
   * This is a utility function that creates a cursor and then sets it on the widget.
   *
   * If the @a name is an empty string, the widget will use the cursor specified via CSS
   * or the parent widget. If neither specifies a cursor, the default cursor
   * will be shown. This is the default behavior.
   *
   * @newin{3,94}
   *
   * @param name The name of the cursor, or an empty string to use the default cursor.
   */
  void set_cursor(const Glib::ustring& name =  {});

  /** Queries the cursor set on @a widget.
   *
   * See set_cursor() for details.
   *
   * @return The cursor
   * currently in use or <tt>nullptr</tt> if the cursor is inherited.
   */
  auto get_cursor() -> Glib::RefPtr<Gdk::Cursor>;

  /** Queries the cursor set on @a widget.
   *
   * See set_cursor() for details.
   *
   * @return The cursor
   * currently in use or <tt>nullptr</tt> if the cursor is inherited.
   */
  auto get_cursor() const -> Glib::RefPtr<const Gdk::Cursor>;


  /** Returns the widgets for which this widget is the target of a
   * mnemonic.
   *
   * Typically, these widgets will be labels. See, for example,
   * Gtk::Label::set_mnemonic_widget().
   *
   * The widgets in the list are not individually referenced.
   * If you want to iterate through the list and perform actions
   * involving callbacks that might destroy the widgets, you
   * must call `g_list_foreach (result, (GFunc)g_object_ref, <tt>nullptr</tt>)`
   * first, and then unref all the widgets afterwards.
   *
   * @return The list
   * of mnemonic labels; free this list with Glib::list_free() when you
   * are done with it.
   */
  auto list_mnemonic_labels() -> std::vector<Widget*>;


  /** Returns the widgets for which this widget is the target of a
   * mnemonic.
   *
   * Typically, these widgets will be labels. See, for example,
   * Gtk::Label::set_mnemonic_widget().
   *
   * The widgets in the list are not individually referenced.
   * If you want to iterate through the list and perform actions
   * involving callbacks that might destroy the widgets, you
   * must call `g_list_foreach (result, (GFunc)g_object_ref, <tt>nullptr</tt>)`
   * first, and then unref all the widgets afterwards.
   *
   * @return The list
   * of mnemonic labels; free this list with Glib::list_free() when you
   * are done with it.
   */
  auto list_mnemonic_labels() const -> std::vector<const Widget*>;

  /** Adds a widget to the list of mnemonic labels for
   * this widget. (See list_mnemonic_labels()). Note the
   * list of mnemonic labels for the widget is cleared when the
   * widget is destroyed, so the caller must make sure to update
   * its internal state at this point as well.
   *
   * @newin{2,4}
   *
   * @param label A `Gtk::Widget` that acts as a mnemonic label for @a widget.
   */
  void add_mnemonic_label(Widget& label);

  /** Removes a widget from the list of mnemonic labels for this widget.
   *
   * See list_mnemonic_labels(). The widget must
   * have previously been added to the list with
   * add_mnemonic_label().
   *
   * @param label A `Gtk::Widget` that was previously set as a mnemonic
   * label for @a widget with add_mnemonic_label().
   */
  void remove_mnemonic_label(Widget& label);


  /** Checks to see if a drag movement has passed the GTK drag threshold.
   *
   * @param start_x X coordinate of start of drag.
   * @param start_y Y coordinate of start of drag.
   * @param current_x Current X coordinate.
   * @param current_y Current Y coordinate.
   * @return <tt>true</tt> if the drag threshold has been passed.
   */
  auto drag_check_threshold(int start_x, int start_y, int current_x, int current_y) -> bool;


  /** Obtains the frame clock for a widget.
   *
   * The frame clock is a global “ticker” that can be used to drive
   * animations and repaints. The most common reason to get the frame
   * clock is to call Gdk::FrameClock::get_frame_time(), in order
   * to get a time to use for animating. For example you might record
   * the start of the animation with an initial value from
   * Gdk::FrameClock::get_frame_time(), and then update the animation
   * by calling Gdk::FrameClock::get_frame_time() again during each repaint.
   *
   * Gdk::FrameClock::request_phase() will result in a new frame on the
   * clock, but won’t necessarily repaint any widgets. To repaint a
   * widget, you have to use queue_draw() which invalidates
   * the widget (thus scheduling it to receive a draw on the next
   * frame). queue_draw() will also end up requesting a frame
   * on the appropriate frame clock.
   *
   * A widget’s frame clock will not change while the widget is
   * mapped. Reparenting a widget (which implies a temporary unmap) can
   * change the widget’s frame clock.
   *
   * Unrealized widgets do not have a frame clock.
   *
   * @newin{3,24}
   *
   * @return A `Gdk::FrameClock`.
   */
  auto get_frame_clock() -> Glib::RefPtr<Gdk::FrameClock>;

  /** Obtains the frame clock for a widget.
   *
   * The frame clock is a global “ticker” that can be used to drive
   * animations and repaints. The most common reason to get the frame
   * clock is to call Gdk::FrameClock::get_frame_time(), in order
   * to get a time to use for animating. For example you might record
   * the start of the animation with an initial value from
   * Gdk::FrameClock::get_frame_time(), and then update the animation
   * by calling Gdk::FrameClock::get_frame_time() again during each repaint.
   *
   * Gdk::FrameClock::request_phase() will result in a new frame on the
   * clock, but won’t necessarily repaint any widgets. To repaint a
   * widget, you have to use queue_draw() which invalidates
   * the widget (thus scheduling it to receive a draw on the next
   * frame). queue_draw() will also end up requesting a frame
   * on the appropriate frame clock.
   *
   * A widget’s frame clock will not change while the widget is
   * mapped. Reparenting a widget (which implies a temporary unmap) can
   * change the widget’s frame clock.
   *
   * Unrealized widgets do not have a frame clock.
   *
   * @newin{3,24}
   *
   * @return A `Gdk::FrameClock`.
   */
  auto get_frame_clock() const -> Glib::RefPtr<const Gdk::FrameClock>;

  //Used when implementing containers:

  /** Sets @a parent as the parent widget of @a widget.
   *
   * This takes care of details such as updating the state and style
   * of the child to reflect its new location and resizing the parent.
   * The opposite function is unparent().
   *
   * This function is useful only when implementing subclasses of
   * `Gtk::Widget`.
   *
   * @param parent Parent widget.
   */
  void set_parent(Widget& parent);

  /** Dissociate @a widget from its parent.
   *
   * This function is only for use in widget implementations,
   * typically in dispose.
   */
  void unparent();

  //TODO: When exactly do we need to custom containers need to call map() on the child widgets?
  //Most containers that derive from GtkContainer do not need to, but GtkNotebook does.

  /** Causes a widget to be mapped if it isn’t already.
   *
   * This function is only for use in widget implementations.
   */
  void map();

  /** Causes a widget to be unmapped if it’s currently mapped.
   *
   * This function is only for use in widget implementations.
   */
  void unmap();

  // Gtk+ 2.12 tooltip API

  /** Triggers a tooltip query on the display where the toplevel
   * of @a widget is located.
   */
  void trigger_tooltip_query();

  /** Sets @a text as the contents of the tooltip.
   *
   * If @a text contains any markup, it will be escaped.
   *
   * This function will take care of setting
   * property_has_tooltip() as a side effect,
   * and of the default handler for the
   * signal_query_tooltip() signal.
   *
   * See also Gtk::Tooltip::set_text().
   *
   * @param text The contents of the tooltip for @a widget.
   */
  void set_tooltip_text(const Glib::ustring& text);

  /** Gets the contents of the tooltip for @a widget.
   *
   * If the @a widget's tooltip was set using
   * set_tooltip_markup(),
   * this function will return the escaped text.
   *
   * @return The tooltip text.
   */
  auto get_tooltip_text() const -> Glib::ustring;

  /** Sets @a markup as the contents of the tooltip, which is marked up with
   * the Pango text markup language.
   *
   * This function will take care of setting GtkWidget:has-tooltip to <tt>true</tt>
   * and of the default handler for the GtkWidget::query-tooltip signal.
   *
   * See also the GtkWidget:tooltip-markup property and
   * Gtk::Tooltip::set_markup().
   *
   * @newin{2,12}
   *
   * @param markup The contents of the tooltip for @a widget.
   */
  void set_tooltip_markup(const Glib::ustring& markup);

  /** Gets the contents of the tooltip for @a widget.
   *
   * If the tooltip has not been set using
   * set_tooltip_markup(), this
   * function returns <tt>nullptr</tt>.
   *
   * @return The tooltip text.
   */
  auto get_tooltip_markup() const -> Glib::ustring;

  /** Sets the `has-tooltip` property on @a widget to @a has_tooltip.
   *
   * @param has_tooltip Whether or not @a widget has a tooltip.
   */
  void set_has_tooltip(bool has_tooltip =  TRUE);

  /** Returns the current value of the `has-tooltip` property.
   *
   * @return Current value of `has-tooltip` on @a widget.
   */
  auto get_has_tooltip() const -> bool;


  /** Returns whether the widget is currently being destroyed.
   *
   * This information can sometimes be used to avoid doing
   * unnecessary work.
   *
   * @return <tt>true</tt> if @a widget is being destroyed.
   */
  auto in_destruction() const -> bool;


  /** Returns the style context associated to @a widget.
   *
   * The returned object is guaranteed to be the same
   * for the lifetime of @a widget.
   *
   * @return The widgets `Gtk::StyleContext`.
   */
  auto get_style_context() -> Glib::RefPtr<StyleContext>;

  /** Returns the style context associated to @a widget.
   *
   * The returned object is guaranteed to be the same
   * for the lifetime of @a widget.
   *
   * @return The widgets `Gtk::StyleContext`.
   */
  auto get_style_context() const -> Glib::RefPtr<const StyleContext>;

  /** Callback type for adding a function to update animations. See add_tick_callback().
   *
   * For instance:
   * @code
   * bool on_tick(const Glib::RefPtr<Gdk::FrameClock>& frame_clock);
   * @endcode
   *
   * @param frame_clock The frame clock for the widget (same as calling get_frame_clock()).
   * @return <tt>true</tt> if the tick callback should continue to be called,
   *         <tt>false</tt> if the tick callback should be removed.
   *
   * @newin{3,24}
   */
  using SlotTick = sigc::slot<bool(const Glib::RefPtr<Gdk::FrameClock>&)>;

  /** Queues an animation frame update and adds a callback to be called
   * before each frame.
   *
   * Until the tick callback is removed, it will be
   * called frequently (usually at the frame rate of the output device
   * or as quickly as the application can be repainted, whichever is
   * slower). For this reason, is most suitable for handling graphics
   * that change every frame or every few frames. The tick callback does
   * not automatically imply a relayout or repaint. If you want a
   * repaint or relayout, and aren’t changing widget properties that
   * would trigger that (for example, changing the text of a Gtk::Label),
   * then you will have to call queue_resize() or queue_draw_area() yourself.
   *
   * Gdk::FrameClock::get_frame_time() should generally be used for timing
   * continuous animations and
   * Gdk::FrameTimings::get_predicted_presentation_time() if you are
   * trying to display isolated frames at particular times.
   *
   * This is a more convenient alternative to connecting directly to the
   * Gdk::FrameClock::signal_update() signal of Gdk::FrameClock, since you don't
   * have to worry about when a Gdk::FrameClock is assigned to a widget.
   *
   * @newin{3,24}
   *
   * @param slot Slot to call for updating animations.
   * @return An id for the connection of this callback. Remove the callback
   *         by passing it to remove_tick_callback().
   */
  auto add_tick_callback(const SlotTick& slot) -> guint;


  /** Removes a tick callback previously registered with
   * add_tick_callback().
   *
   * @newin{3,24}
   *
   * @param id An id returned by add_tick_callback().
   */
  void remove_tick_callback(guint id);

  //This is mostly only needed by the class itself, so it could be protected,
  //but it is sometimes helpful to call it from outside:

  /** Inserts @a group into @a widget.
   *
   * Children of @a widget that implement Gtk::Actionable can
   * then be associated with actions in @a group by setting their
   * “action-name” to @a prefix.`action-name`.
   *
   * Note that inheritance is defined for individual actions. I.e.
   * even if you insert a group with prefix @a prefix, actions with
   * the same prefix will still be inherited from the parent, unless
   * the group contains an action with the same name.
   *
   * If @a group is <tt>nullptr</tt>, a previously inserted group for @a name is
   * removed from @a widget.
   *
   * @param name The prefix for actions in @a group.
   * @param group A `Gio::ActionGroup`, or <tt>nullptr</tt> to remove
   * the previously inserted group for @a name.
   */
  void insert_action_group(const Glib::ustring& name, const Glib::RefPtr<Gio::ActionGroup>& group);

  /** Removes a group from the widget.
   * See insert_action_group().
   *
   * @param name The prefix for actions.
   *
   * @newin{3,10}
   */
  void remove_action_group(const Glib::ustring& name);


  /** Looks up the action in the action groups associated
   * with the widget and its ancestors, and activates it.
   *
   * If the action is in an action group added with
   * insert_action_group(), the @a name is
   * expected to be prefixed with the prefix that was
   * used when the group was inserted.
   *
   * The arguments must match the action's expected parameter
   * type, as returned by Gio::Action::get_parameter_type().
   *
   * @param name The name of the action to activate.
   * @param args Parameters to use, or an empty (invalid) Glib::VariantBase
   *             if the action does not expect parameters.
   * @return <tt>true</tt> if the action was activated, <tt>false</tt> if the
   *         action does not exist.
   */
  auto activate_action(const Glib::ustring& name, const Glib::VariantBase& args =  {}) -> bool;


  /** Activates the `default.activate` action from @a widget.
   */
  void activate_default();


  /** Sets the font map to use for Pango rendering.
   *
   * The font map is the object that is used to look up fonts.
   * Setting a custom font map can be useful in special situations,
   * e.g. when you need to add application-specific fonts to the set
   * of available fonts.
   *
   * When not set, the widget will inherit the font map from its parent.
   *
   * @param font_map A `Pango::FontMap`, or <tt>nullptr</tt> to unset any
   * previously set font map.
   */
  void set_font_map(const Glib::RefPtr<Pango::FontMap>& font_map);

  /** Gets the font map of @a widget.
   *
   * See set_font_map().
   *
   * @return A `Pango::FontMap`.
   */
  auto get_font_map() -> Glib::RefPtr<Pango::FontMap>;

  /** Gets the font map of @a widget.
   *
   * See set_font_map().
   *
   * @return A `Pango::FontMap`.
   */
  auto get_font_map() const -> Glib::RefPtr<const Pango::FontMap>;


  /** Returns the widgets first child.
   *
   * This API is primarily meant for widget implementations.
   *
   * @return The widget's first child.
   */
  auto get_first_child() -> Widget*;

  /** Returns the widgets first child.
   *
   * This API is primarily meant for widget implementations.
   *
   * @return The widget's first child.
   */
  auto get_first_child() const -> const Widget*;

  /** Returns the widgets last child.
   *
   * This API is primarily meant for widget implementations.
   *
   * @return The widget's last child.
   */
  auto get_last_child() -> Widget*;

  /** Returns the widgets last child.
   *
   * This API is primarily meant for widget implementations.
   *
   * @return The widget's last child.
   */
  auto get_last_child() const -> const Widget*;

  /** Returns the widgets next sibling.
   *
   * This API is primarily meant for widget implementations.
   *
   * @return The widget's next sibling.
   */
  auto get_next_sibling() -> Widget*;

  /** Returns the widgets next sibling.
   *
   * This API is primarily meant for widget implementations.
   *
   * @return The widget's next sibling.
   */
  auto get_next_sibling() const -> const Widget*;

  /** Returns the widgets previous sibling.
   *
   * This API is primarily meant for widget implementations.
   *
   * @return The widget's previous sibling.
   */
  auto get_prev_sibling() -> Widget*;

  /** Returns the widgets previous sibling.
   *
   * This API is primarily meant for widget implementations.
   *
   * @return The widget's previous sibling.
   */
  auto get_prev_sibling() const -> const Widget*;


  /** Returns a `Gio::ListModel` to track the children of @a widget.
   *
   * Calling this function will enable extra internal bookkeeping
   * to track children and emit signals on the returned listmodel.
   * It may slow down operations a lot.
   *
   * Applications should try hard to avoid calling this function
   * because of the slowdowns.
   *
   * @return A `Gio::ListModel` tracking @a widget's children.
   */
  auto observe_children() -> Glib::RefPtr<Gio::ListModel>;

  /** Returns a `Gio::ListModel` to track the children of @a widget.
   *
   * Calling this function will enable extra internal bookkeeping
   * to track children and emit signals on the returned listmodel.
   * It may slow down operations a lot.
   *
   * Applications should try hard to avoid calling this function
   * because of the slowdowns.
   *
   * @return A `Gio::ListModel` tracking @a widget's children.
   */
  auto observe_children() const -> Glib::RefPtr<const Gio::ListModel>;

  /** Returns a `Gio::ListModel` to track the Gtk::EventControllers
   * of @a widget.
   *
   * Calling this function will enable extra internal bookkeeping
   * to track controllers and emit signals on the returned listmodel.
   * It may slow down operations a lot.
   *
   * Applications should try hard to avoid calling this function
   * because of the slowdowns.
   *
   * @return A `Gio::ListModel` tracking @a widget's controllers.
   */
  auto observe_controllers() -> Glib::RefPtr<Gio::ListModel>;

  /** Returns a `Gio::ListModel` to track the Gtk::EventControllers
   * of @a widget.
   *
   * Calling this function will enable extra internal bookkeeping
   * to track controllers and emit signals on the returned listmodel.
   * It may slow down operations a lot.
   *
   * Applications should try hard to avoid calling this function
   * because of the slowdowns.
   *
   * @return A `Gio::ListModel` tracking @a widget's controllers.
   */
  auto observe_controllers() const -> Glib::RefPtr<const Gio::ListModel>;


  /** Inserts the %Widget into the child widget list of @a parent after @a previous_sibling.
   *
   * After calling this function, get_prev_sibling() will return @a previous_sibling.
   *
   * If @a parent is already set as the parent widget of the %Widget, this function can also be used
   * to reorder the %Widget in the child widget list of @a parent.
   *
   * @param parent The parent Gtk::Widget to insert the %Widget into.
   * @param previous_sibling The new previous sibling of the %Widget.
   */
  void insert_after(Widget& parent, const Widget& previous_sibling);


  /** Inserts the %Widget into the child widget list of @a parent before @a next_sibling.
   *
   * After calling this function, get_next_sibling() will return @a next_sibling.
   *
   * If @a parent is already set as the parent widget of the %Widget, this function can also be used
   * to reorder the %Widget in the child widget list of @a parent.
   *
   * @param parent The parent Gtk::Widget to insert the %Widget into.
   * @param next_sibling The new next sibling of the %Widget.
   */
  void insert_before(Widget& parent, const Widget& next_sibling);

  /** Inserts the %Widget at the beginning of the child widget list of @a parent.
   *
   * After calling this function, get_prev_sibling() will return <tt>nullptr</tt>.
   *
   * If @a parent is already set as the parent of the %Widget, this function can also be used
   * to reorder the %Widget in the child widget list of @a parent.
   *
   * @param parent The parent Gtk::Widget to insert the %Widget into.
   */
  void insert_at_start(Widget& parent);

  /** Inserts the %Widget at the end of the child widget list of @a parent.
   *
   * After calling this function, get_next_sibling() will return <tt>nullptr</tt>.
   *
   * If @a parent is already set as the parent of the %Widget, this function can also be used
   * to reorder the %Widget in the child widget list of @a parent.
   *
   * @param parent The parent Gtk::Widget to insert the %Widget into.
   */
  void insert_at_end(Widget& parent);


  /** Snapshot the a child of @a widget.
   *
   * When a widget receives a call to the snapshot function,
   * it must send synthetic snapshot_vfunc() calls
   * to all children. This function provides a convenient way
   * of doing this. A widget, when it receives a call to its
   * snapshot_vfunc() function, calls
   * snapshot_child() once for each child, passing in
   * the @a snapshot the widget received.
   *
   * snapshot_child() takes care of translating the origin of
   *  @a snapshot, and deciding whether the child needs to be snapshot.
   *
   * This function does nothing for children that implement `Gtk::Native`.
   *
   * @param child A child of @a widget.
   * @param snapshot `Gtk::Snapshot` as passed to the widget. In particular, no
   * calls to Gtk::Snapshot::translate() or other transform calls should
   * have been made.
   */
  void snapshot_child(Widget& child, const Glib::RefPtr<Gtk::Snapshot>& snapshot);


  /** Returns whether @a widget should contribute to
   * the measuring and allocation of its parent.
   *
   * This is <tt>false</tt> for invisible children, but also
   * for children that have their own surface.
   *
   * @return <tt>true</tt> if child should be included in
   * measuring and allocating.
   */
  auto should_layout() const -> bool;


  /** Returns the CSS name that is used for @a self.
   *
   * @return The CSS name.
   */
  auto get_css_name() const -> Glib::ustring;

  /** Adds a style class to @a widget.
   *
   * After calling this function, the widgets style will match
   * for @a css_class, according to CSS matching rules.
   *
   * Use remove_css_class() to remove the
   * style again.
   *
   * @param css_class The style class to add to @a widget, without
   * the leading '.' used for notation of style classes.
   */
  void add_css_class(const Glib::ustring& css_class);

  /** Removes a style from @a widget.
   *
   * After this, the style of @a widget will stop matching for @a css_class.
   *
   * @param css_class The style class to remove from @a widget, without
   * the leading '.' used for notation of style classes.
   */
  void remove_css_class(const Glib::ustring& css_class);

  /** Returns whether @a css_class is currently applied to @a widget.
   *
   * @param css_class A style class, without the leading '.'
   * used for notation of style classes.
   * @return <tt>true</tt> if @a css_class is currently applied to @a widget,
   * <tt>false</tt> otherwise.
   */
  auto has_css_class(const Glib::ustring& css_class) const -> bool;


  /** Returns the list of style classes applied to @a widget.
   *
   * @return A <tt>nullptr</tt>-terminated list of
   * css classes currently applied to @a widget.
   */
  auto get_css_classes() const -> std::vector<Glib::ustring>;


  /** Clear all style classes applied to @a widget
   * and replace them with @a classes.
   *
   * @param classes <tt>nullptr</tt>-terminated list of style classes to apply to @a widget.
   */
  void set_css_classes(const std::vector<Glib::ustring>& classes);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%show()</tt>
   *
   * Flags: Run First
   *
   * Emitted when @a widget is shown.
   */

  auto signal_show() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%hide()</tt>
   *
   * Flags: Run First
   *
   * Emitted when @a widget is hidden.
   */

  auto signal_hide() -> Glib::SignalProxy<void()>;


  /// Emitted on mapping of a widget to the screen.
  //- See {flags.mapped}.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%map()</tt>
   *
   * Flags: Run First
   *
   * Emitted when @a widget is going to be mapped.
   *
   * A widget is mapped when the widget is visible (which is controlled with
   * property_visible()) and all its parents up to the toplevel widget
   * are also visible.
   *
   * The signal_map() signal can be used to determine whether a widget will be drawn,
   * for instance it can resume an animation that was stopped during the
   * emission of signal_unmap().
   */

  auto signal_map() -> Glib::SignalProxy<void()>;


  //- See {flags.mapped}.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%unmap()</tt>
   *
   * Flags: Run First
   *
   * Emitted when @a widget is going to be unmapped.
   *
   * A widget is unmapped when either it or any of its parents up to the
   * toplevel widget have been set as hidden.
   *
   * As signal_unmap() indicates that a widget will not be shown any longer,
   * it can be used to, for example, stop an animation on the widget.
   */

  auto signal_unmap() -> Glib::SignalProxy<void()>;


  /// Emitted on realization of a widget.
  //- See {flags.realized}.  This is also responsible for
  //- setting {flags.realized} when it is done.  Therefore,
  //- when overriding the impl method, you should call the
  //- default realize method.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%realize()</tt>
   *
   * Flags: Run First
   *
   * Emitted when @a widget is associated with a `Gdk::Surface`.
   *
   * This means that Gtk::Widget::realize() has been called
   * or the widget has been mapped (that is, it is going to be drawn).
   */

  auto signal_realize() -> Glib::SignalProxy<void()>;


  //- See {flags.realized}.  This should not be called by the user.
  //__WRAP(meth|sig|impl,void unrealize_(),gtk_widget_unrealize,"unrealize")

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%unrealize()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the `Gdk::Surface` associated with @a widget is destroyed.
   *
   * This means that Gtk::Widget::unrealize() has been called
   * or the widget has been unmapped (that is, it is going to be hidden).
   */

  auto signal_unrealize() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%state_flags_changed(Gtk::StateFlags previous_state_flags)</tt>
   *
   * Flags: Run First
   *
   * Emitted when the widget state changes.
   *
   * See Gtk::Widget::get_state_flags().
   *
   * @param previous_state_flags The previous state flags.
   */

  auto signal_state_flags_changed() -> Glib::SignalProxy<void(Gtk::StateFlags)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%direction_changed(TextDirection direction)</tt>
   *
   * Flags: Run First
   *
   * Emitted when the text direction of a widget changes.
   *
   * @param direction The previous text direction of @a widget.
   */

  auto signal_direction_changed() -> Glib::SignalProxy<void(TextDirection)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%mnemonic_activate(bool group_cycling)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a widget is activated via a mnemonic.
   *
   * The default handler for this signal activates @a widget if @a group_cycling
   * is <tt>false</tt>, or just makes @a widget grab focus if @a group_cycling is <tt>true</tt>.
   *
   * @param group_cycling <tt>true</tt> if there are other widgets with the same mnemonic.
   * @return <tt>true</tt> to stop other handlers from being invoked for the event.
   * <tt>false</tt> to propagate the event further.
   */

  auto signal_mnemonic_activate() -> Glib::SignalProxy<bool(bool)>;


  /** Emitted during the dispose phase.
   *
   * You need to connect to this signal only if you are implementing a widget, which
   * 1. is a direct descendant of %Gtk::Widget,
   * 2. contains other widgets (is a container widget), and
   * 3. shall work well as a managed object.
   *
   * The children of the object need to be unparented *both* from the handler
   * of this signal *and* from the destructor. Reason: when your class is used
   * as a managed object, then the C++ destructor is called too late, but when
   * your class is managed via the standard C++ manner, then this signal is not
   * emitted at all.
   *
   * When your class inherits from a container widget, such as Gtk::Box, you
   * do not need to handle this signal. When your widget does not have child
   * widgets, then you also do not need to handle this signal.
   *
   * This signal is emitted by %Gtk::Widget during the dispose phase of object
   * destruction. See the <a href="https://docs.gtk.org/gobject/concepts.html#reference-count">
   * Reference count</a> section in the GObject concepts documentation
   * for the specification of the dispose and the finalize phases of object
   * destruction. After dispose, the object is not supposed to hold any reference
   * to other member objects.
   *
   * Dispose may be called multiple times, so your implementation of this
   * signal must tolerate that.
   *
   * @par Slot Prototype:
   * <tt>void on_my_%destroy()</tt>
   *
   * Flags: Run Cleanup, No Recurse, No Hooks
   *
   * Signals that all holders of a reference to the widget should release
   * the reference that they hold.
   *
   * May result in finalization of the widget if all references are released.
   *
   * This signal is not suitable for saving widget state.
   *
   * @newin{4,8}
   */

  auto signal_destroy() -> Glib::SignalProxy<void()>;


  //Keybinding signals:


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%query_tooltip(int x, int y, bool keyboard_tooltip, const Glib::RefPtr<Tooltip>& tooltip)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the widgets tooltip is about to be shown.
   *
   * This happens when the property_has_tooltip() property
   * is <tt>true</tt> and the hover timeout has expired with the cursor hovering
   * "above" @a widget; or emitted when @a widget got focus in keyboard mode.
   *
   * Using the given coordinates, the signal handler should determine
   * whether a tooltip should be shown for @a widget. If this is the case
   * <tt>true</tt> should be returned, <tt>false</tt> otherwise.  Note that if
   *  @a keyboard_tooltip is <tt>true</tt>, the values of @a x and @a y are undefined and
   * should not be used.
   *
   * The signal handler is free to manipulate @a tooltip with the therefore
   * destined function calls.
   *
   * @param x The x coordinate of the cursor position where the request has
   * been emitted, relative to @a widget's left side.
   * @param y The y coordinate of the cursor position where the request has
   * been emitted, relative to @a widget's top.
   * @param keyboard_tooltip <tt>true</tt> if the tooltip was triggered using the keyboard.
   * @param tooltip A `Gtk::Tooltip`.
   * @return <tt>true</tt> if @a tooltip should be shown right now, <tt>false</tt> otherwise.
   */

  auto signal_query_tooltip() -> Glib::SignalProxy<bool(int, int, bool, const Glib::RefPtr<Tooltip>&)>;


  /** The name of the widget.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The name of the widget.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The parent widget of this widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_parent() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


  /** The `Gtk::Root` widget of the widget tree containing this widget.
   *
   * This will be <tt>nullptr</tt> if the widget is not contained in a root widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_root() const -> Glib::PropertyProxy_ReadOnly< Root* >;


  /** Override for width request of the widget.
   *
   * If this is -1, the natural request will be used.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width_request() -> Glib::PropertyProxy< int > ;

/** Override for width request of the widget.
   *
   * If this is -1, the natural request will be used.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width_request() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Override for height request of the widget.
   *
   * If this is -1, the natural request will be used.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_height_request() -> Glib::PropertyProxy< int > ;

/** Override for height request of the widget.
   *
   * If this is -1, the natural request will be used.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_height_request() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the widget is visible.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible() -> Glib::PropertyProxy< bool > ;

/** Whether the widget is visible.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the widget responds to input.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sensitive() -> Glib::PropertyProxy< bool > ;

/** Whether the widget responds to input.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sensitive() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the widget or any of its descendents can accept
   * the input focus.
   *
   * This property is meant to be set by widget implementations,
   * typically in their instance init function.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_focus() -> Glib::PropertyProxy< bool > ;

/** Whether the widget or any of its descendents can accept
   * the input focus.
   *
   * This property is meant to be set by widget implementations,
   * typically in their instance init function.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_focus() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the widget has the input focus.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_focus() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether the widget can receive pointer events.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_target() -> Glib::PropertyProxy< bool > ;

/** Whether the widget can receive pointer events.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_target() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the widget should grab focus when it is clicked with the mouse.
   *
   * This property is only relevant for widgets that can take focus.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focus_on_click() -> Glib::PropertyProxy< bool > ;

/** Whether the widget should grab focus when it is clicked with the mouse.
   *
   * This property is only relevant for widgets that can take focus.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focus_on_click() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether this widget itself will accept the input focus.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focusable() -> Glib::PropertyProxy< bool > ;

/** Whether this widget itself will accept the input focus.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focusable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the widget is the default widget.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_default() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether the widget will receive the default action when it is focused.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_receives_default() -> Glib::PropertyProxy< bool > ;

/** Whether the widget will receive the default action when it is focused.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_receives_default() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The cursor used by @a widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cursor() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Cursor> > ;

/** The cursor used by @a widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cursor() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Cursor> >;

  /** Enables or disables the emission of the signal_query_tooltip() signal on @a widget.
   *
   * A value of <tt>true</tt> indicates that @a widget can have a tooltip, in this case
   * the widget will be queried using signal_query_tooltip() to
   * determine whether it will provide a tooltip or not.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_tooltip() -> Glib::PropertyProxy< bool > ;

/** Enables or disables the emission of the signal_query_tooltip() signal on @a widget.
   *
   * A value of <tt>true</tt> indicates that @a widget can have a tooltip, in this case
   * the widget will be queried using signal_query_tooltip() to
   * determine whether it will provide a tooltip or not.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_tooltip() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Sets the text of tooltip to be the given string, which is marked up
   * with Pango markup.
   *
   * Also see Gtk::Tooltip::set_markup().
   *
   * This is a convenience property which will take care of getting the
   * tooltip shown if the given string is not <tt>nullptr</tt>:
   * property_has_tooltip() will automatically be set to <tt>true</tt>
   * and there will be taken care of signal_query_tooltip() in
   * the default signal handler.
   *
   * Note that if both property_tooltip_text() and
   * property_tooltip_markup() are set, the last one wins.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tooltip_markup() -> Glib::PropertyProxy< Glib::ustring > ;

/** Sets the text of tooltip to be the given string, which is marked up
   * with Pango markup.
   *
   * Also see Gtk::Tooltip::set_markup().
   *
   * This is a convenience property which will take care of getting the
   * tooltip shown if the given string is not <tt>nullptr</tt>:
   * property_has_tooltip() will automatically be set to <tt>true</tt>
   * and there will be taken care of signal_query_tooltip() in
   * the default signal handler.
   *
   * Note that if both property_tooltip_text() and
   * property_tooltip_markup() are set, the last one wins.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tooltip_markup() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Sets the text of tooltip to be the given string.
   *
   * Also see Gtk::Tooltip::set_text().
   *
   * This is a convenience property which will take care of getting the
   * tooltip shown if the given string is not <tt>nullptr</tt>:
   * property_has_tooltip() will automatically be set to <tt>true</tt>
   * and there will be taken care of signal_query_tooltip() in
   * the default signal handler.
   *
   * Note that if both property_tooltip_text() and
   * property_tooltip_markup() are set, the last one wins.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tooltip_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** Sets the text of tooltip to be the given string.
   *
   * Also see Gtk::Tooltip::set_text().
   *
   * This is a convenience property which will take care of getting the
   * tooltip shown if the given string is not <tt>nullptr</tt>:
   * property_has_tooltip() will automatically be set to <tt>true</tt>
   * and there will be taken care of signal_query_tooltip() in
   * the default signal handler.
   *
   * Note that if both property_tooltip_text() and
   * property_tooltip_markup() are set, the last one wins.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tooltip_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** How to distribute horizontal space if widget gets extra space.
   *
   * Default value: Gtk::Align::FILL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_halign() -> Glib::PropertyProxy< Align > ;

/** How to distribute horizontal space if widget gets extra space.
   *
   * Default value: Gtk::Align::FILL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_halign() const -> Glib::PropertyProxy_ReadOnly< Align >;

  /** How to distribute vertical space if widget gets extra space.
   *
   * Default value: Gtk::Align::FILL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_valign() -> Glib::PropertyProxy< Align > ;

/** How to distribute vertical space if widget gets extra space.
   *
   * Default value: Gtk::Align::FILL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_valign() const -> Glib::PropertyProxy_ReadOnly< Align >;

  /** Margin on start of widget, horizontally.
   *
   * This property supports left-to-right and right-to-left text
   * directions.
   *
   * This property adds margin outside of the widget's normal size
   * request, the margin will be added in addition to the size from
   * Gtk::Widget::set_size_request() for example.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin_start() -> Glib::PropertyProxy< int > ;

/** Margin on start of widget, horizontally.
   *
   * This property supports left-to-right and right-to-left text
   * directions.
   *
   * This property adds margin outside of the widget's normal size
   * request, the margin will be added in addition to the size from
   * Gtk::Widget::set_size_request() for example.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin_start() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Margin on end of widget, horizontally.
   *
   * This property supports left-to-right and right-to-left text
   * directions.
   *
   * This property adds margin outside of the widget's normal size
   * request, the margin will be added in addition to the size from
   * Gtk::Widget::set_size_request() for example.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin_end() -> Glib::PropertyProxy< int > ;

/** Margin on end of widget, horizontally.
   *
   * This property supports left-to-right and right-to-left text
   * directions.
   *
   * This property adds margin outside of the widget's normal size
   * request, the margin will be added in addition to the size from
   * Gtk::Widget::set_size_request() for example.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin_end() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Margin on top side of widget.
   *
   * This property adds margin outside of the widget's normal size
   * request, the margin will be added in addition to the size from
   * Gtk::Widget::set_size_request() for example.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin_top() -> Glib::PropertyProxy< int > ;

/** Margin on top side of widget.
   *
   * This property adds margin outside of the widget's normal size
   * request, the margin will be added in addition to the size from
   * Gtk::Widget::set_size_request() for example.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin_top() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Margin on bottom side of widget.
   *
   * This property adds margin outside of the widget's normal size
   * request, the margin will be added in addition to the size from
   * Gtk::Widget::set_size_request() for example.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin_bottom() -> Glib::PropertyProxy< int > ;

/** Margin on bottom side of widget.
   *
   * This property adds margin outside of the widget's normal size
   * request, the margin will be added in addition to the size from
   * Gtk::Widget::set_size_request() for example.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin_bottom() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether to expand horizontally.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hexpand() -> Glib::PropertyProxy< bool > ;

/** Whether to expand horizontally.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hexpand() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether to use the `hexpand` property.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hexpand_set() -> Glib::PropertyProxy< bool > ;

/** Whether to use the `hexpand` property.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hexpand_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether to expand vertically.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vexpand() -> Glib::PropertyProxy< bool > ;

/** Whether to expand vertically.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vexpand() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether to use the `vexpand` property.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vexpand_set() -> Glib::PropertyProxy< bool > ;

/** Whether to use the `vexpand` property.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vexpand_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The requested opacity of the widget.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_opacity() -> Glib::PropertyProxy< double > ;

/** The requested opacity of the widget.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_opacity() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** How content outside the widget's content area is treated.
   *
   * This property is meant to be set by widget implementations,
   * typically in their instance init function.
   *
   * @newin{3,96}
   *
   * Default value: Gtk::Overflow::VISIBLE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overflow() -> Glib::PropertyProxy< Overflow > ;

/** How content outside the widget's content area is treated.
   *
   * This property is meant to be set by widget implementations,
   * typically in their instance init function.
   *
   * @newin{3,96}
   *
   * Default value: Gtk::Overflow::VISIBLE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overflow() const -> Glib::PropertyProxy_ReadOnly< Overflow >;

  /** The scale factor of the widget.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale_factor() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** The name of this widget in the CSS tree.
   *
   * This property is meant to be set by widget implementations,
   * typically in their instance init function.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_css_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** A list of css classes applied to this widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_css_classes() -> Glib::PropertyProxy< std::vector<Glib::ustring> > ;

/** A list of css classes applied to this widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_css_classes() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >;

  /** The `Gtk::LayoutManager` instance to use to compute the preferred size
   * of the widget, and allocate its children.
   *
   * This property is meant to be set by widget implementations,
   * typically in their instance init function.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_layout_manager() -> Glib::PropertyProxy< Glib::RefPtr<LayoutManager> > ;

/** The `Gtk::LayoutManager` instance to use to compute the preferred size
   * of the widget, and allocate its children.
   *
   * This property is meant to be set by widget implementations,
   * typically in their instance init function.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_layout_manager() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<LayoutManager> >;


protected:
    virtual void root_vfunc();

    virtual void unroot_vfunc();

    virtual void size_allocate_vfunc(int width, int height, int baseline);

    virtual auto get_request_mode_vfunc() const -> SizeRequestMode;

    virtual void measure_vfunc(Orientation orientation, int for_size, int& minimum, int& natural, int& minimum_baseline, int& natural_baseline) const;

    virtual auto grab_focus_vfunc() -> bool;

  /** Sets the focused child of widget.
   *
   * @param child The child widget.
   */
    virtual void set_focus_child_vfunc(Widget* child);


    virtual void compute_expand_vfunc(bool& hexpand_p, bool& vexpand_p);

    virtual auto contains_vfunc(double x, double y) const -> bool;


    virtual void snapshot_vfunc(const Glib::RefPtr<Gtk::Snapshot>& snapshot);


protected:
  Widget();


  /** Creates the GDK resources associated with a widget.
   *
   * Normally realization happens implicitly; if you show a widget
   * and all its parent containers, then the widget will be realized
   * and mapped automatically.
   *
   * Realizing a widget requires all the widget’s parent widgets to be
   * realized; calling this function realizes the widget’s parents
   * in addition to @a widget itself. If a widget is not yet inside a
   * toplevel window when you realize it, bad things will happen.
   *
   * This function is primarily used in widget implementations, and
   * isn’t very useful otherwise. Many times when you think you might
   * need it, a better approach is to connect to a signal that will be
   * called after the widget is realized automatically, such as
   * signal_realize().
   */
  void realize();

  /** Causes a widget to be unrealized (frees all GDK resources
   * associated with the widget).
   *
   * This function is only useful in widget implementations.
   */
  void unrealize();

  void realize_if_needed();


  /** Set @a child as the current focus child of @a widget.
   *
   * This function is only suitable for widget implementations.
   * If you want a certain widget to get the input focus, call
   * grab_focus() on it.
   *
   * @param child A direct child widget of @a widget or <tt>nullptr</tt>
   * to unset the focus child of @a widget.
   */
  void set_focus_child(Widget& child);
  /** Unsets the focus child of the widget.
   *
   * The previous focus child will be unset.
   *
   * This function is only suitable for widget implementations.
   */
  void unset_focus_child();


  /** Returns the current focus child of @a widget.
   *
   * @return The current focus
   * child of @a widget.
   */
  auto get_focus_child() -> Widget*;

  /** Returns the current focus child of @a widget.
   *
   * @return The current focus
   * child of @a widget.
   */
  auto get_focus_child() const -> const Widget*;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_show().
  virtual void on_show();
  /// This is a default handler for the signal signal_hide().
  virtual void on_hide();
  /// This is a default handler for the signal signal_map().
  virtual void on_map();
  /// This is a default handler for the signal signal_unmap().
  virtual void on_unmap();
  /// This is a default handler for the signal signal_realize().
  virtual void on_realize();
  /// This is a default handler for the signal signal_unrealize().
  virtual void on_unrealize();
  /// This is a default handler for the signal signal_state_flags_changed().
  virtual void on_state_flags_changed(Gtk::StateFlags previous_state_flags);
  /// This is a default handler for the signal signal_direction_changed().
  virtual void on_direction_changed(TextDirection direction);
  /// This is a default handler for the signal signal_mnemonic_activate().
  virtual auto on_mnemonic_activate(bool group_cycling) -> bool;
  /// This is a default handler for the signal signal_query_tooltip().
  virtual auto on_query_tooltip(int x, int y, bool keyboard_tooltip, const Glib::RefPtr<Tooltip>& tooltip) -> bool;


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Widget
   */
  GTKMM_API
  auto wrap(GtkWidget* object, bool take_copy = false) -> Gtk::Widget*;
} //namespace Glib


#endif /* _GTKMM_WIDGET_H */

