
#ifndef _GTKMM_DROPTARGETASYNC_H
#define _GTKMM_DROPTARGETASYNC_H


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

#include <libmm-gdk/contentformats.hpp>
#include <libmm-gdk/drop.hpp>
#include <libmm-gdk/enums.hpp>
#include <libmm-gtk/eventcontroller.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDropTargetAsync = struct _GtkDropTargetAsync;
using GtkDropTargetAsyncClass = struct _GtkDropTargetAsyncClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API DropTargetAsync_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Event controller to receive DND drops.
 *
 * %Gtk::DropTargetAsync is an auxiliary object that can be used to receive
 * Drag-and-Drop operations.
 * It is the more complete but also more complex method of handling drop
 * operations compared to Gtk::DropTarget and you should only use it if
 * Gtk::DropTarget doesn't provide all the features you need.
 *
 * To use a %Gtk::DropTargetAsync to receive drops on a widget, you create
 * a %Gtk::DropTargetAsync object, configure which data formats and actions
 * you support, connect to its signals, and then attach
 * it to the widget with Gtk::Widget::add_controller().
 *
 * During a drag operation, the first signal that a %Gtk::DropTargetAsync
 * emits is signal_accept(), which is meant to determine
 * whether the target is a possible drop site for the ongoing drop.
 * The default handler for the accept signal accepts the drop
 * if it finds a compatible data format and an action that is supported
 * on both sides.
 *
 * If it is, and the widget becomes a target, you will receive a
 * signal_drag_enter(), followed by signal_drag_motion() as the pointer moves,
 * optionally a signal_drop() when a drop happens, and finally a
 * signal_drag_leave() when the pointer moves off the widget.
 *
 * The ::drag-enter and ::drag-motion handler return a Gdk::DragAction
 * to update the status of the ongoing operation. The ::drop handler
 * should decide if it ultimately accepts the drop and if it does, it
 * should initiate the data transfer and finish the operation by calling
 * Gdk::Drop::finish().
 *
 * Between the ::drag-enter and ::drag-leave signals the widget is a
 * current drop target, and will receive the Gtk::StateFlags::DROP_ACTIVE
 * state, which can be used by themes to style the widget as a drop target.
 *
 * @newin{3,98}
 *
 * @ingroup Gestures
 */

class GTKMM_API DropTargetAsync : public EventController
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DropTargetAsync;
  using CppClassType = DropTargetAsync_Class;
  using BaseObjectType = GtkDropTargetAsync;
  using BaseClassType = GtkDropTargetAsyncClass;

  // noncopyable
  DropTargetAsync(const DropTargetAsync&) = delete;
  auto operator=(const DropTargetAsync&) -> DropTargetAsync& = delete;

private:  friend class DropTargetAsync_Class;
  static CppClassType droptargetasync_class_;

protected:
  explicit DropTargetAsync(const Glib::ConstructParams& construct_params);
  explicit DropTargetAsync(GtkDropTargetAsync* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DropTargetAsync(DropTargetAsync&& src) noexcept;
  auto operator=(DropTargetAsync&& src) noexcept -> DropTargetAsync&;

  ~DropTargetAsync() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkDropTargetAsync*       { return reinterpret_cast<GtkDropTargetAsync*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkDropTargetAsync* { return reinterpret_cast<GtkDropTargetAsync*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkDropTargetAsync*;

private:


public:
  // Gdk::ContentFormats is an immutable object. It can be declared const
  // in input parameters. No one can change it.
  static auto create(const Glib::RefPtr<const Gdk::ContentFormats>& formats,
    Gdk::DragAction actions = static_cast<Gdk::DragAction>(0)) -> Glib::RefPtr<DropTargetAsync>;
  static auto create(Gdk::DragAction actions = static_cast<Gdk::DragAction>(0)) -> Glib::RefPtr<DropTargetAsync>;


  /** Sets the data formats that this drop target will accept.
   *
   * @param formats The supported data formats or <tt>nullptr</tt> for any format.
   */
  void set_formats(const Glib::RefPtr<const Gdk::ContentFormats>& formats);

  /** Gets the data formats that this drop target accepts.
   *
   * If the result is <tt>nullptr</tt>, all formats are expected to be supported.
   *
   * @return The supported data formats.
   */
  auto get_formats() -> Glib::RefPtr<Gdk::ContentFormats>;

  /** Gets the data formats that this drop target accepts.
   *
   * If the result is <tt>nullptr</tt>, all formats are expected to be supported.
   *
   * @return The supported data formats.
   */
  auto get_formats() const -> Glib::RefPtr<const Gdk::ContentFormats>;


  /** Sets the actions that this drop target supports.
   *
   * @param actions The supported actions.
   */
  void set_actions(Gdk::DragAction actions);

  /** Gets the actions that this drop target supports.
   *
   * @return The actions that this drop target supports.
   */
  auto get_actions() const -> Gdk::DragAction;


  /** Sets the @a drop as not accepted on this drag site.
   *
   * This function should be used when delaying the decision
   * on whether to accept a drag or not until after reading
   * the data.
   *
   * @param drop The `Gdk::Drop` of an ongoing drag operation.
   */
  void reject_drop(const Glib::RefPtr<Gdk::Drop>& drop);

  /** The `Gdk::DragActions` that this drop target supports.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_actions() -> Glib::PropertyProxy< Gdk::DragAction > ;

/** The `Gdk::DragActions` that this drop target supports.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_actions() const -> Glib::PropertyProxy_ReadOnly< Gdk::DragAction >;

  /** The `Gdk::ContentFormats` that determines the supported data formats.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_formats() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::ContentFormats> > ;

/** The `Gdk::ContentFormats` that determines the supported data formats.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_formats() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::ContentFormats> >;


  // no_default_handler because GtkDropTargetAsyncClass is private.
  // All C signals except "drag-leave" use g_signal_accumulator_first_wins().

  /** Only one signal handler is called. If you connect a handler, it must be
   * called before (instead of) the default handler, otherwise it won't be called.
   * Set the @a after parameter in connect() to <tt>false</tt>.
   *
   * @par Slot Prototype:
   * <tt>bool on_my_%accept(const Glib::RefPtr<Gdk::Drop>& drop)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drop site when a drop operation is about to begin.
   *
   * If the drop is not accepted, <tt>false</tt> will be returned and the drop target
   * will ignore the drop. If <tt>true</tt> is returned, the drop is accepted for now
   * but may be rejected later via a call to Gtk::DropTargetAsync::reject_drop()
   * or ultimately by returning <tt>false</tt> from a signal_drop()
   * handler.
   *
   * The default handler for this signal decides whether to accept the drop
   * based on the formats provided by the @a drop.
   *
   * If the decision whether the drop will be accepted or rejected needs
   * further processing, such as inspecting the data, this function should
   * return <tt>true</tt> and proceed as is @a drop was accepted and if it decides to
   * reject the drop later, it should call Gtk::DropTargetAsync::reject_drop().
   *
   * @param drop The `Gdk::Drop`.
   * @return <tt>true</tt> if @a drop is accepted.
   */

  auto signal_accept() -> Glib::SignalProxy<bool(const Glib::RefPtr<Gdk::Drop>&)>;


  /** Only one signal handler is called. If you connect a handler, it must be
   * called before (instead of) the default handler, otherwise it won't be called.
   * Set the @a after parameter in connect() to <tt>false</tt>.
   *
   * @par Slot Prototype:
   * <tt>Gdk::DragAction on_my_%drag_enter(const Glib::RefPtr<Gdk::Drop>& drop, double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drop site when the pointer enters the widget.
   *
   * It can be used to set up custom highlighting.
   *
   * @param drop The `Gdk::Drop`.
   * @param x The x coordinate of the current pointer position.
   * @param y The y coordinate of the current pointer position.
   * @return Preferred action for this drag operation.
   */

  auto signal_drag_enter() -> Glib::SignalProxy<Gdk::DragAction(const Glib::RefPtr<Gdk::Drop>&, double, double)>;


  /** Only one signal handler is called. If you connect a handler, it must be
   * called before (instead of) the default handler, otherwise it won't be called.
   * Set the @a after parameter in connect() to <tt>false</tt>.
   *
   * @par Slot Prototype:
   * <tt>Gdk::DragAction on_my_%drag_motion(const Glib::RefPtr<Gdk::Drop>& drop, double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted while the pointer is moving over the drop target.
   *
   * @param drop The `Gdk::Drop`.
   * @param x The x coordinate of the current pointer position.
   * @param y The y coordinate of the current pointer position.
   * @return Preferred action for this drag operation.
   */

  auto signal_drag_motion() -> Glib::SignalProxy<Gdk::DragAction(const Glib::RefPtr<Gdk::Drop>&, double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%drag_leave(const Glib::RefPtr<Gdk::Drop>& drop)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drop site when the pointer leaves the widget.
   *
   * Its main purpose it to undo things done in
   * `Gtk::DropTargetAsync`::drag-enter.
   *
   * @param drop The `Gdk::Drop`.
   */

  auto signal_drag_leave() -> Glib::SignalProxy<void(const Glib::RefPtr<Gdk::Drop>&)>;


  /** Only one signal handler is called. If you connect a handler, it must be
   * called before (instead of) the default handler, otherwise it won't be called.
   * Set the @a after parameter in connect() to <tt>false</tt>.
   *
   * @par Slot Prototype:
   * <tt>bool on_my_%drop(const Glib::RefPtr<Gdk::Drop>& drop, double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drop site when the user drops the data onto the widget.
   *
   * The signal handler must determine whether the pointer position is in a
   * drop zone or not. If it is not in a drop zone, it returns <tt>false</tt> and no
   * further processing is necessary.
   *
   * Otherwise, the handler returns <tt>true</tt>. In this case, this handler will
   * accept the drop. The handler must ensure that Gdk::Drop::finish()
   * is called to let the source know that the drop is done. The call to
   * Gdk::Drop::finish() must only be done when all data has been received.
   *
   * To receive the data, use one of the read functions provided by
   * Gdk::Drop such as Gdk::Drop::read_async() or
   * Gdk::Drop::read_value_async().
   *
   * @param drop The `Gdk::Drop`.
   * @param x The x coordinate of the current pointer position.
   * @param y The y coordinate of the current pointer position.
   * @return Whether the drop is accepted at the given pointer position.
   */

  auto signal_drop() -> Glib::SignalProxy<bool(const Glib::RefPtr<Gdk::Drop>&, double, double)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gtk::DropTargetAsync
   */
  GTKMM_API
  auto wrap(GtkDropTargetAsync* object, bool take_copy = false) -> Glib::RefPtr<Gtk::DropTargetAsync>;
}


#endif /* _GTKMM_DROPTARGETASYNC_H */

