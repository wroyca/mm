
#ifndef _GTKMM_DROPTARGET_H
#define _GTKMM_DROPTARGET_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gdk/contentformats.hxx>
#include <libmm-gdk/drop.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gtk/eventcontroller.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDropTarget = struct _GtkDropTarget;
using GtkDropTargetClass = struct _GtkDropTargetClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API DropTarget_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Event controller to receive DND drops.
 *
 * %Gtk::DropTarget is an event controller implementing a simple way to
 * receive Drag-and-Drop operations.
 *
 * The most basic way to use a %Gtk::DropTarget to receive drops on a
 * widget is to create it via create() passing in the
 * GType of the data you want to receive and connect to signal_drop()
 * to receive the data.
 *
 * %Gtk::DropTarget supports more options, such as:
 *
 *  * rejecting potential drops via signal_accept() and the reject() method
 *    to let other drop targets handle the drop
 *  * tracking an ongoing drag operation before the drop via
 *    signal_enter(), signal_motion() and signal_leave()
 *  * configuring how to receive data by setting property_preload() and
 *    listening for its availability via property_value()
 *
 * However, %Gtk::DropTarget is ultimately modeled in a synchronous way
 * and only supports data transferred via GType.
 * If you want full control over an ongoing drop, the Gtk::DropTargetAsync
 * object gives you this ability.
 *
 * While a pointer is dragged over the drop target's widget and the drop
 * has not been rejected, that widget will receive the
 * Gtk::StateFlags::DROP_ACTIVE state, which can be used to style the widget.
 *
 * @newin{3,96}
 *
 * @ingroup Gestures
 */

class GTKMM_API DropTarget : public EventController
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DropTarget;
  using CppClassType = DropTarget_Class;
  using BaseObjectType = GtkDropTarget;
  using BaseClassType = GtkDropTargetClass;

  // noncopyable
  DropTarget(const DropTarget&) = delete;
  auto operator=(const DropTarget&) -> DropTarget& = delete;

private:  friend class DropTarget_Class;
  static CppClassType droptarget_class_;

protected:
  explicit DropTarget(const Glib::ConstructParams& construct_params);
  explicit DropTarget(GtkDropTarget* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DropTarget(DropTarget&& src) noexcept;
  auto operator=(DropTarget&& src) noexcept -> DropTarget&;

  ~DropTarget() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkDropTarget*       { return reinterpret_cast<GtkDropTarget*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkDropTarget* { return reinterpret_cast<GtkDropTarget*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkDropTarget*;

private:


public:
  // gtk_drop_target_new() does more than call g_object_new().
  // GdkDropTarget has no "type" property.

  /** Creates a new `Gtk::DropTarget` object.
   *
   * If the drop target should support more than 1 type, pass
   * G_TYPE_INVALID for @a type and then call
   * set_gtypes().
   *
   * @param type The supported type or G_TYPE_INVALID.
   * @param actions The supported actions.
   * @return The new `Gtk::DropTarget`.
   */
  static auto create(GType type, Gdk::DragAction actions) -> Glib::RefPtr<DropTarget>;

  /** Sets the supported Types for this drop target.
   *
   * @param types All supported Types that can be dropped.
   */
  void set_gtypes(const std::vector<GType>& types);


  /** Gets a vector of supported Types. If no type have been set,
   * an empty vector will be returned.
   *
   * @return Vector of types.
   */
  auto get_gtypes() const -> std::vector<GType>;


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


  /** Sets whether data should be preloaded on hover.
   *
   * @param preload <tt>true</tt> to preload drop data.
   */
  void set_preload(bool preload =  true);

  /** Gets whether data should be preloaded on hover.
   *
   * @return <tt>true</tt> if drop data should be preloaded.
   */
  auto get_preload() const -> bool;


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Gets the currently handled drop operation.
   *
   * If no drop operation is going on, <tt>nullptr</tt> is returned.
   *
   * Deprecated: 4.4: Use get_current_drop() instead
   *
   * @deprecated Use get_current_drop() instead.
   *
   * @return The current drop.
   */
  auto get_drop() -> Glib::RefPtr<Gdk::Drop>;
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Gets the currently handled drop operation.
   *
   * If no drop operation is going on, <tt>nullptr</tt> is returned.
   *
   * Deprecated: 4.4: Use get_current_drop() instead
   *
   * @deprecated Use get_current_drop() instead.
   *
   * @return The current drop.
   */
  auto get_drop() const -> Glib::RefPtr<const Gdk::Drop>;
#endif // GTKMM_DISABLE_DEPRECATED


  /** Gets the currently handled drop operation.
   *
   * If no drop operation is going on, <tt>nullptr</tt> is returned.
   *
   * @newin{4,4}
   *
   * @return The current drop.
   */
  auto get_current_drop() -> Glib::RefPtr<Gdk::Drop>;

  /** Gets the currently handled drop operation.
   *
   * If no drop operation is going on, <tt>nullptr</tt> is returned.
   *
   * @newin{4,4}
   *
   * @return The current drop.
   */
  auto get_current_drop() const -> Glib::RefPtr<const Gdk::Drop>;


  /** Gets the current drop data, as a `Glib::Value`.
   *
   * @return The current drop data.
   */

  auto get_value() const -> Glib::ValueBase;


  /** Rejects the ongoing drop operation.
   *
   * If no drop operation is ongoing, i.e when property_current_drop()
   * is <tt>nullptr</tt>, this function does nothing.
   *
   * This function should be used when delaying the decision
   * on whether to accept a drag or not until after reading
   * the data.
   */
  void reject();

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


#ifndef GTKMM_DISABLE_DEPRECATED

/** The `Gdk::Drop` that is currently being performed.
   *
   * Deprecated: 4.4: Use property_current_drop() instead
   *
   * @deprecated Use property_current_drop() instead.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_drop() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Drop> >;


#endif // GTKMM_DISABLE_DEPRECATED

  /** The `Gdk::Drop` that is currently being performed.
   *
   * @newin{4,4}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_current_drop() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Drop> >;


  /** The `Gdk::ContentFormats` that determine the supported data formats.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_formats() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::ContentFormats> >;


  /** Whether the drop data should be preloaded when the pointer is only
   * hovering over the widget but has not been released.
   *
   * Setting this property allows finer grained reaction to an ongoing
   * drop at the cost of loading more data.
   *
   * The default value for this property is <tt>false</tt> to avoid downloading
   * huge amounts of data by accident.
   *
   * For example, if somebody drags a full document of gigabytes of text
   * from a text editor across a widget with a preloading drop target,
   * this data will be downloaded, even if the data is ultimately dropped
   * elsewhere.
   *
   * For a lot of data formats, the amount of data is very small (like
   * GDK_TYPE_RGBA), so enabling this property does not hurt at all.
   * And for local-only Drag-and-Drop operations, no data transfer is done,
   * so enabling it there is free.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_preload() -> Glib::PropertyProxy< bool > ;

/** Whether the drop data should be preloaded when the pointer is only
   * hovering over the widget but has not been released.
   *
   * Setting this property allows finer grained reaction to an ongoing
   * drop at the cost of loading more data.
   *
   * The default value for this property is <tt>false</tt> to avoid downloading
   * huge amounts of data by accident.
   *
   * For example, if somebody drags a full document of gigabytes of text
   * from a text editor across a widget with a preloading drop target,
   * this data will be downloaded, even if the data is ultimately dropped
   * elsewhere.
   *
   * For a lot of data formats, the amount of data is very small (like
   * GDK_TYPE_RGBA), so enabling this property does not hurt at all.
   * And for local-only Drag-and-Drop operations, no data transfer is done,
   * so enabling it there is free.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_preload() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The value for this drop operation.
   *
   * This is <tt>nullptr</tt> if the data has not been loaded yet or no drop
   * operation is going on.
   *
   * Data may be available before the signal_drop()
   * signal gets emitted - for example when the property_preload()
   * property is set. You can use the signal_notify() signal to be notified
   * of available data.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value() const -> Glib::PropertyProxy_ReadOnly< GValue* >;


  // no_default_handler because GtkDropTargetClass is private.
  // All C signals except "leave" use g_signal_accumulator_first_wins().

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
   * but may be rejected later via a call to Gtk::DropTarget::reject()
   * or ultimately by returning <tt>false</tt> from a signal_drop()
   * handler.
   *
   * The default handler for this signal decides whether to accept the drop
   * based on the formats provided by the @a drop.
   *
   * If the decision whether the drop will be accepted or rejected depends
   * on the data, this function should return <tt>true</tt>, the
   * property_preload() property should be set and the value
   * should be inspected via the ::notify:value signal, calling
   * Gtk::DropTarget::reject() if required.
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
   * <tt>Gdk::DragAction on_my_%enter(double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drop site when the pointer enters the widget.
   *
   * It can be used to set up custom highlighting.
   *
   * @param x The x coordinate of the current pointer position.
   * @param y The y coordinate of the current pointer position.
   * @return Preferred action for this drag operation or 0 if
   * dropping is not supported at the current @a x, @a y location.
   */

  auto signal_enter() -> Glib::SignalProxy<Gdk::DragAction(double, double)>;


  /** Only one signal handler is called. If you connect a handler, it must be
   * called before (instead of) the default handler, otherwise it won't be called.
   * Set the @a after parameter in connect() to <tt>false</tt>.
   *
   * @par Slot Prototype:
   * <tt>Gdk::DragAction on_my_%motion(double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted while the pointer is moving over the drop target.
   *
   * @param x The x coordinate of the current pointer position.
   * @param y The y coordinate of the current pointer position.
   * @return Preferred action for this drag operation or 0 if
   * dropping is not supported at the current @a x, @a y location.
   */

  auto signal_motion() -> Glib::SignalProxy<Gdk::DragAction(double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%leave()</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drop site when the pointer leaves the widget.
   *
   * Its main purpose it to undo things done in
   * signal_enter().
   */

  auto signal_leave() -> Glib::SignalProxy<void()>;


  /** Only one signal handler is called. If you connect a handler, it must be
   * called before (instead of) the default handler, otherwise it won't be called.
   * Set the @a after parameter in connect() to <tt>false</tt>.
   *
   * @par Slot Prototype:
   * <tt>bool on_my_%drop(const Glib::ValueBase& value, double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drop site when the user drops the data onto the widget.
   *
   * The signal handler must determine whether the pointer position is in
   * a drop zone or not. If it is not in a drop zone, it returns <tt>false</tt>
   * and no further processing is necessary.
   *
   * Otherwise, the handler returns <tt>true</tt>. In this case, this handler will
   * accept the drop. The handler is responsible for using the given @a value
   * and performing the drop operation.
   *
   * @param value The `Glib::Value` being dropped.
   * @param x The x coordinate of the current pointer position.
   * @param y The y coordinate of the current pointer position.
   * @return Whether the drop was accepted at the given pointer position.
   */

  auto signal_drop() -> Glib::SignalProxy<bool(const Glib::ValueBase&, double, double)>;


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
   * @relates Gtk::DropTarget
   */
  GTKMM_API
  auto wrap(GtkDropTarget* object, bool take_copy = false) -> Glib::RefPtr<Gtk::DropTarget>;
}


#endif /* _GTKMM_DROPTARGET_H */

