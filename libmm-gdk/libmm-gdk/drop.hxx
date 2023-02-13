
#ifndef _GDKMM_DROP_H
#define _GDKMM_DROP_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2018 The gtkmm Development Team
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

#include <libmm-glib/object.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gdk/enums.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDrop = struct _GdkDrop;
using GdkDropClass = struct _GdkDropClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Drop_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class GDKMM_API Cancellable;
class GDKMM_API InputStream;
}

namespace Gdk
{
class GDKMM_API ContentFormats;
class GDKMM_API Device;
class GDKMM_API Drag;
class GDKMM_API Display;
class GDKMM_API Surface;

/** A %Gdk::Drop object represents the target of an ongoing DND operation.
 *
 * Possible drop sites get informed about the status of the ongoing drag
 * operation with events of type Gdk::Event::Type::DRAG_ENTER,
 * Gdk::Event::Type::DRAG_LEAVE, Gdk::Event::Type::DRAG_MOTION and
 * Gdk::Event::Type::DROP_START. The %Gdk::Drop object can be obtained
 * from a DND event using Gdk::Event::get_dnd_drop().
 *
 * The actual data transfer is initiated from the target side via an async
 * read, using one of the %Gdk::Drop methods for this purpose:
 * read_async() or read_value_async().
 *
 * GTK provides a higher level abstraction based on top of these functions,
 * and so they are not normally needed in GTK applications.
 *
 * @newin{3,94}
 */

class GDKMM_API Drop : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Drop;
  using CppClassType = Drop_Class;
  using BaseObjectType = GdkDrop;
  using BaseClassType = GdkDropClass;

  // noncopyable
  Drop(const Drop&) = delete;
  auto operator=(const Drop&) -> Drop& = delete;

private:  friend class Drop_Class;
  static CppClassType drop_class_;

protected:
  explicit Drop(const Glib::ConstructParams& construct_params);
  explicit Drop(GdkDrop* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Drop(Drop&& src) noexcept;
  auto operator=(Drop&& src) noexcept -> Drop&;

  ~Drop() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkDrop*       { return reinterpret_cast<GdkDrop*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkDrop* { return reinterpret_cast<GdkDrop*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkDrop*;

private:


public:

  /** Gets the `Gdk::Display` that @a self was created for.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Gets the `Gdk::Display` that @a self was created for.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;


  /** Returns the `Gdk::Device` performing the drop.
   *
   * @return The `Gdk::Device` performing the drop.
   */
  auto get_device() -> Glib::RefPtr<Device>;

  /** Returns the `Gdk::Device` performing the drop.
   *
   * @return The `Gdk::Device` performing the drop.
   */
  auto get_device() const -> Glib::RefPtr<const Device>;


  /** Returns the `Gdk::Surface` performing the drop.
   *
   * @return The `Gdk::Surface` performing the drop.
   */
  auto get_surface() -> Glib::RefPtr<Surface>;

  /** Returns the `Gdk::Surface` performing the drop.
   *
   * @return The `Gdk::Surface` performing the drop.
   */
  auto get_surface() const -> Glib::RefPtr<const Surface>;


  /** Returns the `Gdk::ContentFormats` that the drop offers the data
   * to be read in.
   *
   * @return The possible `Gdk::ContentFormats`.
   */
  auto get_formats() -> Glib::RefPtr<ContentFormats>;

  /** Returns the `Gdk::ContentFormats` that the drop offers the data
   * to be read in.
   *
   * @return The possible `Gdk::ContentFormats`.
   */
  auto get_formats() const -> Glib::RefPtr<const ContentFormats>;


  /** Returns the possible actions for this `Gdk::Drop`.
   *
   * If this value contains multiple actions - i.e.
   * Gdk::Drag::action_is_unique() returns <tt>false</tt> for the result -
   * finish() must choose the action to use when
   * accepting the drop. This will only happen if you passed
   * Gdk::DragAction::ASK as one of the possible actions in
   * status(). Gdk::DragAction::ASK itself will not
   * be included in the actions returned by this function.
   *
   * This value may change over the lifetime of the Gdk::Drop
   * both as a response to source side actions as well as to calls to
   * status() or finish(). The source
   * side will not change this value anymore once a drop has started.
   *
   * @return The possible `Gdk::DragActions`.
   */
  auto get_actions() const -> DragAction;


  /** If this is an in-app drag-and-drop operation, returns the `Gdk::Drag`
   * that corresponds to this drop.
   *
   * If it is not, <tt>nullptr</tt> is returned.
   *
   * @return The corresponding `Gdk::Drag`.
   */
  auto get_drag() -> Glib::RefPtr<Drag>;

  /** If this is an in-app drag-and-drop operation, returns the `Gdk::Drag`
   * that corresponds to this drop.
   *
   * If it is not, <tt>nullptr</tt> is returned.
   *
   * @return The corresponding `Gdk::Drag`.
   */
  auto get_drag() const -> Glib::RefPtr<const Drag>;


  /** Selects all actions that are potentially supported by the destination.
   *
   * When calling this function, do not restrict the passed in actions to
   * the ones provided by get_actions(). Those actions may
   * change in the future, even depending on the actions you provide here.
   *
   * The @a preferred action is a hint to the drag-and-drop mechanism about which
   * action to use when multiple actions are possible.
   *
   * This function should be called by drag destinations in response to
   * Gdk::Event::Type::DRAG_ENTER or Gdk::Event::Type::DRAG_MOTION events. If the destination does
   * not yet know the exact actions it supports, it should set any possible
   * actions first and then later call this function again.
   *
   * @param actions Supported actions of the destination, or 0 to indicate
   * that a drop will not be accepted.
   * @param preferred A unique action that's a member of @a actions indicating the
   * preferred action.
   */
  void status(DragAction actions, DragAction preferred);
  /** Indicates that a drop will not be accepted.
   * This function may be called by the drag destination in response to
   * Gdk::Event::Type::DRAG_ENTER or Gdk::Event::Type::DRAG_MOTION events.
   * Alternatively, call status() to indicate which drag actions will be accepted.
   */
  void refuse();


  /** Ends the drag operation after a drop.
   *
   * The @a action must be a single action selected from the actions
   * available via get_actions().
   *
   * @param action The action performed by the destination or 0 if the drop failed.
   */
  void finish(DragAction action);
  /** Ends the drag operation and indicates that the operation failed.
   * Alternatively, call finish() to indicate which drag action was performed.
   */
  void failed();


  /** Asynchronously read the dropped data from a `Gdk::Drop`
   * in a format that complies with one of the mime types.
   *
   * @param mime_types Pointer to an array of mime types.
   * @param io_priority The I/O priority for the read operation.
   * @param cancellable Optional `Gio::Cancellable` object.
   * @param slot A `SlotAsyncReady` to call when
   * the request is satisfied.
   */
  void read_async(const std::vector<Glib::ustring>& mime_types, int io_priority, const Gio::SlotAsyncReady& slot, const Glib::RefPtr<Gio::Cancellable>& cancellable);

  /// A read_async() convenience overload.
  void read_async(const std::vector<Glib::ustring>& mime_types, int io_priority, const Gio::SlotAsyncReady& slot);


  /** Finishes an async drop read operation.
   *
   * Note that you must not use blocking read calls on the returned stream
   * in the GTK thread, since some platforms might require communication with
   * GTK to complete the data transfer. You can use async APIs such as
   * Glib::input_stream_read_bytes_async().
   *
   * See read_async().
   *
   * @param result A `Gio::AsyncResult`.
   * @param out_mime_type Return location for the used mime type.
   * @return The `Gio::InputStream`.
   *
   * @throws Glib::Error
   */
  auto read_finish(const Glib::RefPtr<Gio::AsyncResult>& result, Glib::ustring& out_mime_type) -> Glib::RefPtr<Gio::InputStream>;


  /** Asynchronously request the drag operation's contents converted
   * to the given @a type.
   *
   * When the operation is finished @a slot will be called. You must
   * then call read_value_finish() to get the resulting
   * `Glib::Value`.
   *
   * For local drag-and-drop operations that are available in the given
   * `GType`, the value will be copied directly. Otherwise, GDK will
   * try to use gdk_content_deserialize_async() to convert the data.
   *
   * @param type A `GType` to read.
   * @param io_priority The I/O priority of the request.
   * @param cancellable Optional `Gio::Cancellable` object, <tt>nullptr</tt> to ignore.
   * @param slot Callback to call when the request is satisfied.
   */
  void read_value_async(GType type, int io_priority, const Gio::SlotAsyncReady& slot, const Glib::RefPtr<Gio::Cancellable>& cancellable);

  /// A read_value_async() convenience overload.
  void read_value_async(GType type, int io_priority, const Gio::SlotAsyncReady& slot);

  /** Finishes an async drop read.
   *
   * See read_value_async().
   *
   * @param result A `Gio::AsyncResult`.
   * @return A `Glib::Value` containing the result.
   */

  auto read_value_finish(const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::ValueBase;

  /** The possible actions for this drop
   *
   * Default value: Gdk::DragAction::COPY | Gdk::DragAction::MOVE | Gdk::DragAction::LINK
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_actions() const -> Glib::PropertyProxy_ReadOnly< DragAction >;


  /** The `Gdk::Device` performing the drop
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_device() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Device> >;


  /** The `Gdk::Display` that the drop belongs to.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >;


  /** The `Gdk::Drag` that initiated this drop
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_drag() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Drag> >;


  /** The possible formats that the drop can provide its data in.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_formats() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ContentFormats> >;


  /** The `Gdk::Surface` the drop happens on
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_surface() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Surface> >;


  // There are no signals or public vfuncs.


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
   * @relates Gdk::Drop
   */
  GDKMM_API
  auto wrap(GdkDrop* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Drop>;
}


#endif /* _GDKMM_DROP_H */

