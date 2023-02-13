
#ifndef _GTKMM_DRAGSOURCE_H
#define _GTKMM_DRAGSOURCE_H


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

#include <libmm-gdk/contentprovider.hxx>
#include <libmm-gdk/drag.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/paintable.hxx>
#include <libmm-gtk/gesturesingle.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDragSource = struct _GtkDragSource;
using GtkDragSourceClass = struct _GtkDragSourceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API DragSource_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Event controller to initiate DND operations.
 *
 * %Gtk::DragSource is an auxiliary object that is used to initiate
 * Drag-And-Drop operations. It can be set up with the necessary
 * ingredients for a DND operation ahead of time. This includes
 * the source for the data that is being transferred, in the form
 * of a Gdk::ContentProvider, the desired action, and the icon to
 * use during the drag operation. After setting it up, the drag
 * source must be added to a widget as an event controller, using
 * Gtk::Widget::add_controller().
 *
 * Setting up the content provider and icon ahead of time only
 * makes sense when the data does not change. More commonly, you
 * will want to set them up just in time. To do so, %Gtk::DragSource
 * has signal_prepare() and signal_drag_begin().
 * The prepare signal is emitted before a drag is started, and
 * can be used to set the content provider and actions that the
 * drag should be started with. The drag-begin signal is emitted
 * after the Gdk::Drag object has been created, and can be used
 * to set up the drag icon.
 *
 * During the DND operation, %Gtk::DragSource emits signals that
 * can be used to obtain updates about the status of the operation,
 * but it is not normally necessary to connect to any signals,
 * except for one case: when the supported actions include
 * Gdk::DragAction::MOVE, you need to listen for signal_drag_end() and
 * delete the data after it has been transferred.
 *
 * @newin{3,96}
 *
 * @ingroup Gestures
 */

class GTKMM_API DragSource : public GestureSingle
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DragSource;
  using CppClassType = DragSource_Class;
  using BaseObjectType = GtkDragSource;
  using BaseClassType = GtkDragSourceClass;

  // noncopyable
  DragSource(const DragSource&) = delete;
  auto operator=(const DragSource&) -> DragSource& = delete;

private:  friend class DragSource_Class;
  static CppClassType dragsource_class_;

protected:
  explicit DragSource(const Glib::ConstructParams& construct_params);
  explicit DragSource(GtkDragSource* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DragSource(DragSource&& src) noexcept;
  auto operator=(DragSource&& src) noexcept -> DragSource&;

  ~DragSource() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkDragSource*       { return reinterpret_cast<GtkDragSource*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkDragSource* { return reinterpret_cast<GtkDragSource*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkDragSource*;

private:


protected:
  DragSource();

public:

  static auto create() -> Glib::RefPtr<DragSource>;


  /** Sets a content provider on a `Gtk::DragSource`.
   *
   * When the data is requested in the cause of a DND operation,
   * it will be obtained from the content provider.
   *
   * This function can be called before a drag is started,
   * or in a handler for the signal_prepare() signal.
   *
   * You may consider setting the content provider back to
   * <tt>nullptr</tt> in a signal_drag_end() signal handler.
   *
   * @param content A `Gdk::ContentProvider`.
   */
  void set_content(const Glib::RefPtr<Gdk::ContentProvider>& content);

  /** Gets the current content provider of a `Gtk::DragSource`.
   *
   * @return The `Gdk::ContentProvider` of @a source.
   */
  auto get_content() -> Glib::RefPtr<Gdk::ContentProvider>;

  /** Gets the current content provider of a `Gtk::DragSource`.
   *
   * @return The `Gdk::ContentProvider` of @a source.
   */
  auto get_content() const -> Glib::RefPtr<const Gdk::ContentProvider>;


  /** Sets the actions on the `Gtk::DragSource`.
   *
   * During a DND operation, the actions are offered to potential
   * drop targets. If @a actions include Gdk::DragAction::MOVE, you need
   * to listen to the signal_drag_end() signal and
   * handle @a delete_data being <tt>true</tt>.
   *
   * This function can be called before a drag is started,
   * or in a handler for the signal_prepare() signal.
   *
   * @param actions The actions to offer.
   */
  void set_actions(Gdk::DragAction actions);

  /** Gets the actions that are currently set on the `Gtk::DragSource`.
   *
   * @return The actions set on @a source.
   */
  auto get_actions() const -> Gdk::DragAction;


  /** Sets a paintable to use as icon during DND operations.
   *
   * The hotspot coordinates determine the point on the icon
   * that gets aligned with the hotspot of the cursor.
   *
   * If @a paintable is <tt>nullptr</tt>, a default icon is used.
   *
   * This function can be called before a drag is started, or in
   * a signal_prepare() or
   * signal_drag_begin() signal handler.
   *
   * @param paintable The `Gdk::Paintable` to use as icon.
   * @param hot_x The hotspot X coordinate on the icon.
   * @param hot_y The hotspot Y coordinate on the icon.
   */
  void set_icon(const Glib::RefPtr<const Gdk::Paintable>& paintable, int hot_x, int hot_y);

  /** Cancels a currently ongoing drag operation.
   */
  void drag_cancel();

  /** Returns the underlying `Gdk::Drag` object for an ongoing drag.
   *
   * @return The `Gdk::Drag` of the current
   * drag operation.
   */
  auto get_drag() -> Glib::RefPtr<Gdk::Drag>;

  /** Returns the underlying `Gdk::Drag` object for an ongoing drag.
   *
   * @return The `Gdk::Drag` of the current
   * drag operation.
   */
  auto get_drag() const -> Glib::RefPtr<const Gdk::Drag>;

  /** The data that is offered by drag operations from this source.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::ContentProvider> > ;

/** The data that is offered by drag operations from this source.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::ContentProvider> >;

  /** The actions that are supported by drag operations from the source.
   *
   * Note that you must handle the signal_drag_end() signal
   * if the actions include Gdk::DragAction::MOVE.
   *
   * Default value: Gdk::DragAction::COPY
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_actions() -> Glib::PropertyProxy< Gdk::DragAction > ;

/** The actions that are supported by drag operations from the source.
   *
   * Note that you must handle the signal_drag_end() signal
   * if the actions include Gdk::DragAction::MOVE.
   *
   * Default value: Gdk::DragAction::COPY
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_actions() const -> Glib::PropertyProxy_ReadOnly< Gdk::DragAction >;


  // no_default_handler because GtkDragSourceClass is private.

  /** Only one signal handler is called. If you connect a handler, it must be
   * called before (instead of) the default handler, otherwise it won't be called.
   * Set the @a after parameter in connect() to <tt>false</tt>.
   *
   * @par Slot Prototype:
   * <tt>Glib::RefPtr<Gdk::ContentProvider> on_my_%prepare(double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a drag is about to be initiated.
   *
   * It returns the `Gdk::ContentProvider` to use for the drag that is about
   * to start. The default handler for this signal returns the value of
   * the property_content() property, so if you set up that
   * property ahead of time, you don't need to connect to this signal.
   *
   * @param x The X coordinate of the drag starting point.
   * @param y The Y coordinate fo the drag starting point.
   * @return A `Gdk::ContentProvider`.
   */

  auto signal_prepare() -> Glib::SignalProxy<Glib::RefPtr<Gdk::ContentProvider>(double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%drag_begin(const Glib::RefPtr<Gdk::Drag>& drag)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drag source when a drag is started.
   *
   * It can be used to e.g. set a custom drag icon with
   * Gtk::DragSource::set_icon().
   *
   * @param drag The `Gdk::Drag` object.
   */

  auto signal_drag_begin() -> Glib::SignalProxy<void(const Glib::RefPtr<Gdk::Drag>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%drag_end(const Glib::RefPtr<Gdk::Drag>& drag, bool delete_data)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drag source when a drag is finished.
   *
   * A typical reason to connect to this signal is to undo
   * things done in signal_prepare() or
   * signal_drag_begin() handlers.
   *
   * @param drag The `Gdk::Drag` object.
   * @param delete_data <tt>true</tt> if the drag was performing Gdk::DragAction::MOVE,
   * and the data should be deleted.
   */

  auto signal_drag_end() -> Glib::SignalProxy<void(const Glib::RefPtr<Gdk::Drag>&, bool)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%drag_cancel(const Glib::RefPtr<Gdk::Drag>& drag, Gdk::DragCancelReason reason)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the drag source when a drag has failed.
   *
   * The signal handler may handle a failed drag operation based on
   * the type of error. It should return <tt>true</tt> if the failure has been handled
   * and the default "drag operation failed" animation should not be shown.
   *
   * @param drag The `Gdk::Drag` object.
   * @param reason Information on why the drag failed.
   * @return <tt>true</tt> if the failed drag operation has been already handled.
   */

  auto signal_drag_cancel() -> Glib::SignalProxy<bool(const Glib::RefPtr<Gdk::Drag>&, Gdk::DragCancelReason)>;


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
   * @relates Gtk::DragSource
   */
  GTKMM_API
  auto wrap(GtkDragSource* object, bool take_copy = false) -> Glib::RefPtr<Gtk::DragSource>;
}


#endif /* _GTKMM_DRAGSOURCE_H */

