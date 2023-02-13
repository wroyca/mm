
#ifndef _GDKMM_DRAG_H
#define _GDKMM_DRAG_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gdk/enums.hpp>
#include <mm/glib/object.hpp>
#include <gdk/gdk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDrag = struct _GdkDrag;
using GdkDragClass = struct _GdkDragClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Drag_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GDKMM_API ContentFormats;
class GDKMM_API ContentProvider;
class GDKMM_API Device;
class GDKMM_API Display;
class GDKMM_API Surface;

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 *  @var DragCancelReason NO_TARGET
 * There is no suitable drop target.
 *
 *  @var DragCancelReason USER_CANCELLED
 * Drag cancelled by the user.
 *
 *  @var DragCancelReason ERROR
 * Unspecified error.
 *
 *  @enum DragCancelReason
 *
 * Used in `Gdk::Drag` to the reason of a cancelled DND operation.
 *
 * @ingroup gdkmmEnums
 */
enum class DragCancelReason
{
  NO_TARGET,
  USER_CANCELLED,
  ERROR
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::DragCancelReason> : public Glib::Value_Enum<Gdk::DragCancelReason>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


/** A %Gdk::Drag object represents the source of an ongoing DND operation.
 *
 * A %Gdk::Drag is created when a drag is started, and stays alive for the
 * duration of the DND operation. After a drag has been started with
 * Gdk::Surface::drag_begin_from_point(), the caller gets informed about the
 * status of the ongoing drag operation with signals on the %Gdk::Drag object.
 *
 * GTK provides a higher level abstraction based on top of these functions,
 * and so they are not normally needed in GTK applications.
 */

class GDKMM_API Drag : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Drag;
  using CppClassType = Drag_Class;
  using BaseObjectType = GdkDrag;
  using BaseClassType = GdkDragClass;

  // noncopyable
  Drag(const Drag&) = delete;
  auto operator=(const Drag&) -> Drag& = delete;

private:  friend class Drag_Class;
  static CppClassType drag_class_;

protected:
  explicit Drag(const Glib::ConstructParams& construct_params);
  explicit Drag(GdkDrag* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Drag(Drag&& src) noexcept;
  auto operator=(Drag&& src) noexcept -> Drag&;

  ~Drag() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkDrag*       { return reinterpret_cast<GdkDrag*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkDrag* { return reinterpret_cast<GdkDrag*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkDrag*;

private:


public:
  // The Gtk::DnD namespace contains functions that logically are Gdk::Drag methods.
  // However, they can't be members of Gdk::Drag, because they depend on code in
  // the gtk part of gtk+. Such a dependency is not allowed in a Gdk class.


  /** Gets the `Gdk::Display` that the drag object was created for.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Gets the `Gdk::Display` that the drag object was created for.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;


  /** Returns the `Gdk::Device` associated to the `Gdk::Drag` object.
   *
   * @return The `Gdk::Device` associated to @a drag.
   */
  auto get_device() -> Glib::RefPtr<Device>;

  /** Returns the `Gdk::Device` associated to the `Gdk::Drag` object.
   *
   * @return The `Gdk::Device` associated to @a drag.
   */
  auto get_device() const -> Glib::RefPtr<const Device>;


  /** Retrieves the formats supported by this `Gdk::Drag` object.
   *
   * @return A `Gdk::ContentFormats`.
   */
  auto get_formats() -> Glib::RefPtr<ContentFormats>;

  /** Retrieves the formats supported by this `Gdk::Drag` object.
   *
   * @return A `Gdk::ContentFormats`.
   */
  auto get_formats() const -> Glib::RefPtr<const ContentFormats>;


  /** Determines the bitmask of possible actions proposed by the source.
   *
   * @return The `Gdk::DragAction` flags.
   */
  auto get_actions() const -> DragAction;

  /** Determines the action chosen by the drag destination.
   *
   * @return A `Gdk::DragAction` value.
   */
  auto get_selected_action() const -> DragAction;

  /** Checks if @a action represents a single action or includes
   * multiple actions.
   *
   * When @a action is 0 - ie no action was given, <tt>true</tt>
   * is returned.
   *
   * @param action A `Gdk::DragAction`.
   * @return <tt>true</tt> if exactly one action was given.
   */
  static auto action_is_unique(DragAction action) -> bool;


  /** Informs GDK that the drop ended.
   *
   * Passing <tt>false</tt> for @a success may trigger a drag cancellation
   * animation.
   *
   * This function is called by the drag source, and should be the
   * last call before dropping the reference to the @a drag.
   *
   * The `Gdk::Drag` will only take the first drop_done()
   * call as effective, if this function is called multiple times,
   * all subsequent calls will be ignored.
   *
   * @param success Whether the drag was ultimatively successful.
   */
  void drag_drop_done(bool success);


  /** Returns the surface on which the drag icon should be rendered
   * during the drag operation. Note that the surface may not be
   * available until the drag operation has begun. GDK will move
   * the surface in accordance with the ongoing drag operation.
   * The surface will be destroyed when the drag operation is over.
   *
   * The returned surface is usually a subclass of Gdk::Surface that implements
   * the Gdk::DragSurface interface. To use drag surface API, do something like
   * @code
   * auto surface = drag->get_drag_surface();
   * auto drag_surface = std::dynamic_pointer_cast<Gdk::DragSurfaceImpl>(surface);
   * if (drag_surface)
   *   drag_surface->do_something();
   * @endcode
   *
   * @return The drag surface, or an empty RefPtr.
   */
  auto get_drag_surface() -> Glib::RefPtr<Surface>;

  /** See the non-const version.
   */
  auto get_drag_surface() const -> Glib::RefPtr<const Surface>;


  /** Sets the position of the drag surface that will be kept
   * under the cursor hotspot.
   *
   * Initially, the hotspot is at the top left corner of the drag surface.
   *
   * @param hot_x X coordinate of the drag surface hotspot.
   * @param hot_y Y coordinate of the drag surface hotspot.
   */
  void set_hotspot(int hot_x, int hot_y);


  /** Returns the `Gdk::ContentProvider` associated to the `Gdk::Drag` object.
   *
   * @return The `Gdk::ContentProvider` associated to @a drag.
   */
  auto get_content() -> Glib::RefPtr<ContentProvider>;

  /** Returns the `Gdk::ContentProvider` associated to the `Gdk::Drag` object.
   *
   * @return The `Gdk::ContentProvider` associated to @a drag.
   */
  auto get_content() const -> Glib::RefPtr<const ContentProvider>;


  /** Returns the `Gdk::Surface` where the drag originates.
   *
   * @return The `Gdk::Surface` where the drag originates.
   */
  auto get_surface() -> Glib::RefPtr<Surface>;

  /** Returns the `Gdk::Surface` where the drag originates.
   *
   * @return The `Gdk::Surface` where the drag originates.
   */
  auto get_surface() const -> Glib::RefPtr<const Surface>;

  /** The `Gdk::ContentProvider`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ContentProvider> >;


  /** The `Gdk::Device` that is performing the drag.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_device() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Device> >;


  /** The `Gdk::Display` that the drag belongs to.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >;


  /** The possible formats that the drag can provide its data in.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_formats() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ContentFormats> >;


  /** The currently selected action of the drag.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selected_action() -> Glib::PropertyProxy< DragAction > ;

/** The currently selected action of the drag.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selected_action() const -> Glib::PropertyProxy_ReadOnly< DragAction >;

  /** The possible actions of this drag.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_actions() -> Glib::PropertyProxy< DragAction > ;

/** The possible actions of this drag.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_actions() const -> Glib::PropertyProxy_ReadOnly< DragAction >;

  /** The surface where the drag originates.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_surface() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Surface> >;


  // no_default_handler because GdkDragClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%cancel(DragCancelReason reason)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the drag operation is cancelled.
   *
   * @param reason The reason the drag was cancelled.
   */

  auto signal_cancel() -> Glib::SignalProxy<void(DragCancelReason)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%drop_performed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the drop operation is performed on an accepting client.
   */

  auto signal_drop_performed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%dnd_finished()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the destination side has finished reading all data.
   *
   * The drag object can now free all miscellaneous data.
   */

  auto signal_dnd_finished() -> Glib::SignalProxy<void()>;


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
   * @relates Gdk::Drag
   */
  GDKMM_API
  auto wrap(GdkDrag* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Drag>;
}


#endif /* _GDKMM_DRAG_H */

