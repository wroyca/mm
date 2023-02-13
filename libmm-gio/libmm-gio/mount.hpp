
#ifndef _GIOMM_MOUNT_H
#define _GIOMM_MOUNT_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

//#include <libmm-gio/drive.hpp>
//#include <libmm-gio/file.hpp>
//#include <libmm-gio/volume.hpp>
#include <libmm-glib/interface.hpp>
#include <libmm-gio/asyncresult.hpp>
#include <libmm-gio/cancellable.hpp>
#include <libmm-gio/mountoperation.hpp>
#include <libmm-gio/icon.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GMountIface GMountIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMount = struct _GMount;
using GMountClass = struct _GMountClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Mount_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{


class GIOMM_API File;
class GIOMM_API Drive;
class GIOMM_API Volume;

/** The Mount interface represents user-visible mounts.
 * Mount is a "mounted" filesystem that you can access. Mounted is in quotes because it's not the same as a unix mount:
 * it might be a gvfs mount, but you can still access the files on it if you use GIO. It might or might not be related to a volume object.
 *
 * Unmounting a Mount instance is an asynchronous operation. For more information about asynchronous operations, see AsyncReady.
 * To unmount a Mount instance, first call unmount(). The callback slot will be called when the operation has resolved (either with success or failure),
 * and a AsyncReady structure will be passed to the callback. That callback should then call unmount_finish() with the AsyncReady data to see if the operation was completed successfully.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API Mount : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Mount;
  using CppClassType = Mount_Class;
  using BaseObjectType = GMount;
  using BaseClassType = GMountIface;

  // noncopyable
  Mount(const Mount&) = delete;
  auto operator=(const Mount&) -> Mount& = delete;

private:
  friend class Mount_Class;
  static CppClassType mount_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Mount();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Mount(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Mount(GMount* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Mount(Mount&& src) noexcept;
  auto operator=(Mount&& src) noexcept -> Mount&;

  ~Mount() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GMount*       { return reinterpret_cast<GMount*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GMount* { return reinterpret_cast<GMount*>(gobject_); }

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var UnmountFlags NONE
   * No flags set.
   *
   *  @var UnmountFlags FORCE
   * Unmount even if there are outstanding
   * file operations on the mount.
   *
   *  @enum UnmountFlags
   *
   * Flags used when an unmounting a mount.
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>Mount::UnmountFlags operator|(Mount::UnmountFlags, Mount::UnmountFlags)</tt><br>
   * <tt>Mount::UnmountFlags operator&(Mount::UnmountFlags, Mount::UnmountFlags)</tt><br>
   * <tt>Mount::UnmountFlags operator^(Mount::UnmountFlags, Mount::UnmountFlags)</tt><br>
   * <tt>Mount::UnmountFlags operator~(Mount::UnmountFlags)</tt><br>
   * <tt>Mount::UnmountFlags& operator|=(Mount::UnmountFlags&, Mount::UnmountFlags)</tt><br>
   * <tt>Mount::UnmountFlags& operator&=(Mount::UnmountFlags&, Mount::UnmountFlags)</tt><br>
   * <tt>Mount::UnmountFlags& operator^=(Mount::UnmountFlags&, Mount::UnmountFlags)</tt><br>
   */
  enum class UnmountFlags
  {
    NONE = 0x0,
    FORCE = (1 << 0)
  };


  /**
   *  @var MountFlags NONE
   * No flags set.
   *
   *  @enum MountFlags
   *
   * Flags used when mounting a mount.
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>Mount::MountFlags operator|(Mount::MountFlags, Mount::MountFlags)</tt><br>
   * <tt>Mount::MountFlags operator&(Mount::MountFlags, Mount::MountFlags)</tt><br>
   * <tt>Mount::MountFlags operator^(Mount::MountFlags, Mount::MountFlags)</tt><br>
   * <tt>Mount::MountFlags operator~(Mount::MountFlags)</tt><br>
   * <tt>Mount::MountFlags& operator|=(Mount::MountFlags&, Mount::MountFlags)</tt><br>
   * <tt>Mount::MountFlags& operator&=(Mount::MountFlags&, Mount::MountFlags)</tt><br>
   * <tt>Mount::MountFlags& operator^=(Mount::MountFlags&, Mount::MountFlags)</tt><br>
   */
  enum class MountFlags
  {
    NONE = 0x0
  };


  /** Gets the root directory on @a mount.
   *
   * @return A File.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_root() -> Glib::RefPtr<File>;

  /** Gets the root directory on @a mount.
   *
   * @return A File.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_root() const -> Glib::RefPtr<const File>;


  /** Gets the name of @a mount.
   *
   * @return The name for the given @a mount.
   */
  auto get_name() const -> std::string;


  /** Gets the icon for @a mount.
   *
   * @return A Icon.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_icon() -> Glib::RefPtr<Icon>;

  /** Gets the icon for @a mount.
   *
   * @return A Icon.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_icon() const -> Glib::RefPtr<const Icon>;


  /** Gets the symbolic icon for @a mount.
   *
   * @newin{2,34}
   *
   * @return A Icon.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_symbolic_icon() -> Glib::RefPtr<Icon>;

  /** Gets the symbolic icon for @a mount.
   *
   * @newin{2,34}
   *
   * @return A Icon.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_symbolic_icon() const -> Glib::RefPtr<const Icon>;


  /** Gets the UUID for the @a mount. The reference is typically based on
   * the file system UUID for the mount in question and should be
   * considered an opaque string. Returns <tt>nullptr</tt> if there is no UUID
   * available.
   *
   * @return The UUID for @a mount or <tt>nullptr</tt> if no UUID
   * can be computed.
   */
  auto get_uuid() const -> std::string;


  /** Gets the volume for the @a mount.
   *
   * @return A Volume or <tt>nullptr</tt> if @a mount is not
   * associated with a volume.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_volume() -> Glib::RefPtr<Volume>;

  /** Gets the volume for the @a mount.
   *
   * @return A Volume or <tt>nullptr</tt> if @a mount is not
   * associated with a volume.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_volume() const -> Glib::RefPtr<const Volume>;


  /** Gets the drive for the @a mount.
   *
   * This is a convenience method for getting the Volume and then
   * using that object to get the Drive.
   *
   * @return A Drive or <tt>nullptr</tt> if @a mount is not
   * associated with a volume or a drive.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_drive() -> Glib::RefPtr<Drive>;

  /** Gets the drive for the @a mount.
   *
   * This is a convenience method for getting the Volume and then
   * using that object to get the Drive.
   *
   * @return A Drive or <tt>nullptr</tt> if @a mount is not
   * associated with a volume or a drive.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_drive() const -> Glib::RefPtr<const Drive>;


  /** Checks if @a mount can be unmounted.
   *
   * @return <tt>true</tt> if the @a mount can be unmounted.
   */
  auto can_unmount() const -> bool;

  /** Checks if @a mount can be ejected.
   *
   * @return <tt>true</tt> if the @a mount can be ejected.
   */
  auto can_eject() const -> bool;

  void unmount(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, UnmountFlags flags = UnmountFlags::NONE);
  void unmount(const SlotAsyncReady& slot, UnmountFlags flags = UnmountFlags::NONE);
  void unmount(UnmountFlags flags = UnmountFlags::NONE);
  void unmount(const Glib::RefPtr<MountOperation>& mount_operation, UnmountFlags flags = UnmountFlags::NONE);
  void unmount(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, UnmountFlags flags = UnmountFlags::NONE);
  void unmount(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, UnmountFlags flags = UnmountFlags::NONE);


  /** Finishes unmounting a mount. If any errors occurred during the operation,
   *  @a error will be set to contain the errors and <tt>false</tt> will be returned.
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the mount was successfully unmounted. <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto unmount_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Remounts a mount.
   * This is an asynchronous operation, and is finished by calling mount_finish() with the AsyncResult data returned in the callback slot.
   *
   * Remounting is useful when some setting affecting the operation of the volume has been changed, as this may need a remount
   * to take affect. While this is semantically equivalent with unmounting and then remounting, not all backends might need to
   * actually be unmounted.
   *
   * @param operation A mount operation.
   * @param slot A callback which will be called when the operation is completed or canceled.
   * @param cancellable A cancellable object which can be used to cancel the operation.
   * @param flags Flags affecting the operation.
   */
  void remount(const Glib::RefPtr<MountOperation>& operation, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, MountFlags flags = MountFlags::NONE);

  /** Remounts a mount.
   * This is an asynchronous operation, and is finished by calling mount_finish() with the AsyncResult data returned in the callback slot.
   *
   * Remounting is useful when some setting affecting the operation of the volume has been changed, as this may need a remount
   * to take affect. While this is semantically equivalent with unmounting and then remounting, not all backends might need to
   * actually be unmounted.
   *
   * @param operation A mount operation.
   * @param slot A callback which will be called when the operation is completed or canceled.
   * @param flags Flags affecting the operation.
   */
  void remount(const Glib::RefPtr<MountOperation>& operation, const SlotAsyncReady& slot, MountFlags flags = MountFlags::NONE);

  /** Remounts a mount.
   *
   * Remounting is useful when some setting affecting the operation of the volume has been changed, as this may need a remount
   * to take affect. While this is semantically equivalent with unmounting and then remounting, not all backends might need to
   * actually be unmounted.
   *
   * @param operation A mount operation.
   * @param flags Flags affecting the operation.
   */
  void remount(const Glib::RefPtr<MountOperation>& operation, MountFlags flags = MountFlags::NONE);

  /** Remounts a mount, without user interaction.
   *
   * Remounting is useful when some setting affecting the operation of the volume has been changed, as this may need a remount
   * to take affect. While this is semantically equivalent with unmounting and then remounting, not all backends might need to
   * actually be unmounted.
   *
   * @param flags Flags affecting the operation.
   */
  void remount(MountFlags flags = MountFlags::NONE);


  /** Finishes remounting a mount. If any errors occurred during the operation,
   *  @a error will be set to contain the errors and <tt>false</tt> will be returned.
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the mount was successfully remounted. <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto remount_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;

  void eject(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, UnmountFlags flags = UnmountFlags::NONE);
  void eject(const SlotAsyncReady& slot, UnmountFlags flags = UnmountFlags::NONE);
  void eject(UnmountFlags flags = UnmountFlags::NONE);
  void eject(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, UnmountFlags flags = UnmountFlags::NONE);
  void eject(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, UnmountFlags flags = UnmountFlags::NONE);
  void eject(const Glib::RefPtr<MountOperation>& mount_operation, UnmountFlags flags = UnmountFlags::NONE);


  /** Finishes ejecting a mount. If any errors occurred during the operation,
   *  @a error will be set to contain the errors and <tt>false</tt> will be returned.
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the mount was successfully ejected. <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto eject_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Tries to guess the type of content stored on the mount.
   * Returns one or more textual identifiers of well-known content types (typically
   * prefixed with "x-content/"), e.g. x-content/image-dcf for camera
   * memory cards. See the <a href="http://www.freedesktop.org/wiki/Specifications/shared-mime-info-spec">shared-mime-info</a> specification for more on x-content types.
   *
   * This is an asynchronous operation, and is finished by calling
   * guess_content_type_finish().
   *
   * @param slot A callback which will be called when the operation is completed or canceled.
   * @param cancellable A cancellable object which can be used to cancel the operation.
   * @param force_rescan Whether to force a rescan of the content. Otherwise a cached result will be used if available.
   *
   * @newin{2,18}
   */
  void guess_content_type(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, bool force_rescan = true);

  /** Tries to guess the type of content stored on the mount.
   * Returns one or more textual identifiers of well-known content types (typically
   * prefixed with "x-content/"), e.g. x-content/image-dcf for camera
   * memory cards. See the <a href="http://www.freedesktop.org/wiki/Specifications/shared-mime-info-spec">shared-mime-info</a> specification for more on x-content types.
   *
   * This is an asynchronous operation, and is finished by calling
   * guess_content_type_finish().
   *
   * @param slot A callback which will be called when the operation is completed or canceled.
   * @param force_rescan Whether to force a rescan of the content. Otherwise a cached result will be used if available.
   *
   * @newin{2,18}
   */
  void guess_content_type(const SlotAsyncReady& slot, bool force_rescan = true);

  /** Tries to guess the type of content stored on the mount.
   * Returns one or more textual identifiers of well-known content types (typically
   * prefixed with "x-content/"), e.g. x-content/image-dcf for camera
   * memory cards. See the <a href="http://www.freedesktop.org/wiki/Specifications/shared-mime-info-spec">shared-mime-info</a> specification for more on x-content types.
   *
   * @param force_rescan Whether to force a rescan of the content. Otherwise a cached result will be used if available.
   *
   * @newin{2,18}
   */
  void guess_content_type(bool force_rescan = true);


  void guess_content_type_sync(const Glib::RefPtr<Cancellable>& cancellable, bool force_rescan = true);
  void guess_content_type_sync(bool force_rescan = true);


  /** Finishes guessing content types of the Mount.
   * If any errors occurred during the operation, an exception will be thrown.
   * In particular, you may get a Gio::Error::NOT_SUPPORTED if the mount
   * does not support content guessing.
   *
   * @newin{2,18}
   *
   * @param result An AsyncResult.
   * @return An array of content types.
   * @throw Glib::Error
   */
  auto guess_content_type_finish(const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::ustring>;


  /** Determines if @a mount is shadowed. Applications or libraries should
   * avoid displaying @a mount in the user interface if it is shadowed.
   *
   * A mount is said to be shadowed if there exists one or more user
   * visible objects (currently Mount objects) with a root that is
   * inside the root of @a mount.
   *
   * One application of shadow mounts is when exposing a single file
   * system that is used to address several logical volumes. In this
   * situation, a VolumeMonitor implementation would create two
   * Volume objects (for example, one for the camera functionality of
   * the device and one for a SD card reader on the device) with
   * activation URIs `gphoto2://[usb:001,002]/store1/`
   * and `gphoto2://[usb:001,002]/store2/`. When the
   * underlying mount (with root
   * `gphoto2://[usb:001,002]/`) is mounted, said
   * VolumeMonitor implementation would create two Mount objects
   * (each with their root matching the corresponding volume activation
   * root) that would shadow the original mount.
   *
   * The proxy monitor in GVfs 2.26 and later, automatically creates and
   * manage shadow mounts (and shadows the underlying mount) if the
   * activation root on a Volume is set.
   *
   * @newin{2,20}
   *
   * @return <tt>true</tt> if @a mount is shadowed.
   */
  auto is_shadowed() const -> bool;

  /** Increments the shadow count on @a mount. Usually used by
   * VolumeMonitor implementations when creating a shadow mount for
   *  @a mount, see g_mount_is_shadowed() for more information. The caller
   * will need to emit the Mount::signal_changed() signal on @a mount manually.
   *
   * @newin{2,20}
   */
  void shadow();

  /** Decrements the shadow count on @a mount. Usually used by
   * VolumeMonitor implementations when destroying a shadow mount for
   *  @a mount, see g_mount_is_shadowed() for more information. The caller
   * will need to emit the Mount::signal_changed() signal on @a mount manually.
   *
   * @newin{2,20}
   */
  void unshadow();


  /** Gets the default location of @a mount. The default location of the given
   *  @a mount is a path that reflects the main entry point for the user (e.g.
   * the home directory, or the root of the volume).
   *
   * @return A File.
   * The returned object should be unreffed with
   * Glib::object_unref() when no longer needed.
   */
  auto get_default_location() const -> Glib::RefPtr<File>;


  /** Gets the sort key for @a mount, if any.
   *
   * @newin{2,32}
   *
   * @return Sorting key for @a mount or <tt>nullptr</tt> if no such key is available.
   */
  auto get_sort_key() const -> Glib::ustring;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the mount has been changed.
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%unmounted()</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when the Mount have been
   * unmounted. If the recipient is holding references to the
   * object they should release them so the object can be
   * finalized.
   */

  auto signal_unmounted() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%pre_unmount()</tt>
   *
   * Flags: Run Last
   *
   * This signal may be emitted when the Mount is about to be
   * unmounted.
   *
   * This signal depends on the backend and is only emitted if
   * GIO was used to unmount.
   *
   * @newin{2,22}
   */

  auto signal_pre_unmount() -> Glib::SignalProxy<void()>;


  //There are no properties.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed();
  /// This is a default handler for the signal signal_unmounted().
  virtual void on_unmounted();
  /// This is a default handler for the signal signal_pre_unmount().
  virtual void on_pre_unmount();


};

} // namespace Gio

namespace Glib
{

//Pre-declare this so we can use it in TypeTrait:
GIOMM_API
auto wrap(GMount* object, bool take_copy) -> Glib::RefPtr<Gio::Mount>;

namespace Container_Helpers
{

/** This specialization of TypeTraits exists
 * because the default use of Glib::wrap(GObject*),
 * instead of a specific Glib::wrap(GSomeInterface*),
 * would not return a wrapper for an interface.
 */
template <>
struct TypeTraits< Glib::RefPtr<Gio::Mount> >
{
  using CppType = Glib::RefPtr<Gio::Mount>;
  using CType = GMount*;
  using CTypeNonConst = GMount*;

  static auto   to_c_type      (const CppType& item) -> CType
  { return Glib::unwrap (item); }

  static auto to_cpp_type    (const CType& item) -> CppType
  {
    //Use a specific Glib::wrap() function,
    //because CType has the specific type (not just GObject):
    return Glib::wrap(item, true /* take_copy */);
  }

  static void    release_c_type (CType item)
  {
    GLIBMM_DEBUG_UNREFERENCE(nullptr, item);
    g_object_unref(item);
  }
};

} // Container_Helpers
} // Glib

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(Mount::UnmountFlags lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags
  { return static_cast<Mount::UnmountFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(Mount::UnmountFlags lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags
  { return static_cast<Mount::UnmountFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(Mount::UnmountFlags lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags
  { return static_cast<Mount::UnmountFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(Mount::UnmountFlags flags) -> Mount::UnmountFlags
  { return static_cast<Mount::UnmountFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(Mount::UnmountFlags& lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags&
  { return (lhs = static_cast<Mount::UnmountFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(Mount::UnmountFlags& lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags&
  { return (lhs = static_cast<Mount::UnmountFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(Mount::UnmountFlags& lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags&
  { return (lhs = static_cast<Mount::UnmountFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio
namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(Mount::MountFlags lhs, Mount::MountFlags rhs) -> Mount::MountFlags
  { return static_cast<Mount::MountFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(Mount::MountFlags lhs, Mount::MountFlags rhs) -> Mount::MountFlags
  { return static_cast<Mount::MountFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(Mount::MountFlags lhs, Mount::MountFlags rhs) -> Mount::MountFlags
  { return static_cast<Mount::MountFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(Mount::MountFlags flags) -> Mount::MountFlags
  { return static_cast<Mount::MountFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(Mount::MountFlags& lhs, Mount::MountFlags rhs) -> Mount::MountFlags&
  { return (lhs = static_cast<Mount::MountFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(Mount::MountFlags& lhs, Mount::MountFlags rhs) -> Mount::MountFlags&
  { return (lhs = static_cast<Mount::MountFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(Mount::MountFlags& lhs, Mount::MountFlags rhs) -> Mount::MountFlags&
  { return (lhs = static_cast<Mount::MountFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::Mount
   */
  GIOMM_API
  auto wrap(GMount* object, bool take_copy = false) -> Glib::RefPtr<Gio::Mount>;

} // namespace Glib


#endif /* _GIOMM_MOUNT_H */

