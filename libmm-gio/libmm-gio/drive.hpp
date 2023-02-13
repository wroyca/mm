
#ifndef _GIOMM_DRIVE_H
#define _GIOMM_DRIVE_H


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

#include <libmm-gio/mount.hpp>
#include <libmm-gio/icon.hpp>
//#include <libmm-gio/volume.hpp>
//#include <libmm-gio/mountoperation.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDriveIface GDriveIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDrive = struct _GDrive;
using GDriveClass = struct _GDriveClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Drive_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Virtual File System drive management.
 *
 * This represent a piece of hardware connected to the machine. It's generally only created for removable hardware or hardware with removable media.
 * Gio::Drive is a container class for Gio::Volume objects that stem from the same piece of media. As such, Gio::Drive abstracts a drive with
 * (or without) removable media and provides operations for querying whether media is available, determing whether media change is automatically
 * detected and ejecting the media.
 *
 * If the Gio::Drive reports that media isn't automatically detected, one can poll for media; typically one should not do this periodically as a
 * poll for media operation is potententially expensive and may spin up the drive, creating noise.
 *
 * @newin{2,16}
 */

class GIOMM_API Drive : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Drive;
  using CppClassType = Drive_Class;
  using BaseObjectType = GDrive;
  using BaseClassType = GDriveIface;

  // noncopyable
  Drive(const Drive&) = delete;
  auto operator=(const Drive&) -> Drive& = delete;

private:
  friend class Drive_Class;
  static CppClassType drive_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Drive();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Drive(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Drive(GDrive* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Drive(Drive&& src) noexcept;
  auto operator=(Drive&& src) noexcept -> Drive&;

  ~Drive() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDrive*       { return reinterpret_cast<GDrive*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDrive* { return reinterpret_cast<GDrive*>(gobject_); }

private:

public:

  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var StartFlags NONE
   * No flags set.
   *
   *  @enum StartFlags
   *
   * Flags used when starting a drive.
   *
   * @newin{2,22}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>Drive::StartFlags operator|(Drive::StartFlags, Drive::StartFlags)</tt><br>
   * <tt>Drive::StartFlags operator&(Drive::StartFlags, Drive::StartFlags)</tt><br>
   * <tt>Drive::StartFlags operator^(Drive::StartFlags, Drive::StartFlags)</tt><br>
   * <tt>Drive::StartFlags operator~(Drive::StartFlags)</tt><br>
   * <tt>Drive::StartFlags& operator|=(Drive::StartFlags&, Drive::StartFlags)</tt><br>
   * <tt>Drive::StartFlags& operator&=(Drive::StartFlags&, Drive::StartFlags)</tt><br>
   * <tt>Drive::StartFlags& operator^=(Drive::StartFlags&, Drive::StartFlags)</tt><br>
   */
  enum class StartFlags
  {
    NONE = 0x0
  };


  /**
   *  @var StartStopType UNKNOWN
   * Unknown or drive doesn't support
   * start/stop.
   *
   *  @var StartStopType SHUTDOWN
   * The stop method will physically
   * shut down the drive and e.g. power down the port the drive is
   * attached to.
   *
   *  @var StartStopType NETWORK
   * The start/stop methods are used
   * for connecting/disconnect to the drive over the network.
   *
   *  @var StartStopType MULTIDISK
   * The start/stop methods will
   * assemble/disassemble a virtual drive from several physical
   * drives.
   *
   *  @var StartStopType PASSWORD
   * The start/stop methods will
   * unlock/lock the disk (for example using the ATA <quote>SECURITY
   * UNLOCK DEVICE</quote> command).
   *
   *  @enum StartStopType
   *
   * Enumeration describing how a drive can be started/stopped.
   *
   * @newin{2,22}
   *
   * @ingroup giommEnums
   */
  enum class StartStopType
  {
    UNKNOWN,
    SHUTDOWN,
    NETWORK,
    MULTIDISK,
    PASSWORD
  };


  /** Gets the name of @a drive.
   *
   * @return A string containing @a drive's name. The returned
   * string should be freed when no longer needed.
   */
  auto get_name() const -> Glib::ustring;


  /** Gets the icon for @a drive.
   *
   * @return Icon for the @a drive.
   * Free the returned object with Glib::object_unref().
   */
  auto get_icon() -> Glib::RefPtr<Icon>;

  /** Gets the icon for @a drive.
   *
   * @return Icon for the @a drive.
   * Free the returned object with Glib::object_unref().
   */
  auto get_icon() const -> Glib::RefPtr<const Icon>;


  /** Gets the icon for @a drive.
   *
   * @newin{2,34}
   *
   * @return Symbolic Icon for the @a drive.
   * Free the returned object with Glib::object_unref().
   */
  auto get_symbolic_icon() -> Glib::RefPtr<Icon>;

  /** Gets the icon for @a drive.
   *
   * @newin{2,34}
   *
   * @return Symbolic Icon for the @a drive.
   * Free the returned object with Glib::object_unref().
   */
  auto get_symbolic_icon() const -> Glib::RefPtr<const Icon>;


  /** Check if @a drive has any mountable volumes.
   *
   * @return <tt>true</tt> if the @a drive contains volumes, <tt>false</tt> otherwise.
   */
  auto has_volumes() const -> bool;


  /** Get a list of mountable volumes for @a drive.
   *
   * @return List containing any Volume objects on the given @a drive.
   */
  auto get_volumes() -> std::vector<Glib::RefPtr<Volume>>;


  /** Checks if the @a drive supports removable media.
   *
   * @return <tt>true</tt> if @a drive supports removable media, <tt>false</tt> otherwise.
   */
  auto is_media_removable() const -> bool;

  /** Checks if the Drive and/or its media is considered removable by the user.
   * See g_drive_is_media_removable().
   *
   * @newin{2,50}
   *
   * @return <tt>true</tt> if @a drive and/or its media is considered removable, <tt>false</tt> otherwise.
   */
  auto is_removable() const -> bool;

  /** Checks if the @a drive has media. Note that the OS may not be polling
   * the drive for media changes; see g_drive_is_media_check_automatic()
   * for more details.
   *
   * @return <tt>true</tt> if @a drive has media, <tt>false</tt> otherwise.
   */
  auto has_media() const -> bool;

  /** Checks if @a drive is capable of automatically detecting media changes.
   *
   * @return <tt>true</tt> if the @a drive is capable of automatically detecting
   * media changes, <tt>false</tt> otherwise.
   */
  auto is_media_check_automatic() const -> bool;

  /** Checks if a drive can be polled for media changes.
   *
   * @return <tt>true</tt> if the @a drive can be polled for media changes,
   * <tt>false</tt> otherwise.
   */
  auto can_poll_for_media() const -> bool;

  /** Checks if a drive can be ejected.
   *
   * @return <tt>true</tt> if the @a drive can be ejected, <tt>false</tt> otherwise.
   */
  auto can_eject() const -> bool;

  /** Ejects the drive.
   * @param slot A callback which will be called when the eject is completed or canceled.
   * @param flags Flags affecting the unmount if required for eject.
   * @param cancellable A cancellable object which can be used to cancel the eject.
   */
  void eject(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Ejects the drive.
   * @param slot A callback which will be called when the eject is completed.
   * @param flags Flags affecting the unmount if required for eject.
   */
  void eject(const SlotAsyncReady& slot, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);
  void eject(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);
  void eject(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Ejects the drive.
   * @param flags Flags affecting the unmount if required for eject.
   */
  void eject(Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);
  void eject(const Glib::RefPtr<MountOperation>& mount_operation, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);


  // eject_finish() is deprecated in favor of eject_with_operation_finish(), and
  // since all of our eject() overloads are implemented by
  // eject_with_operation(), we implement the _finish() with
  // eject_with_operation_finish and ignore the deprecated one

  /** Finishes ejecting a drive. If any errors occurred during the operation,
   *  @a error will be set to contain the errors and <tt>false</tt> will be returned.
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the drive was successfully ejected. <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto eject_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Polls drive to see if media has been inserted or removed.
   * @param slot A callback which will be called when the poll is completed.
   * @param cancellable A cancellable object which can be used to cancel the operation.
   */
  void poll_for_media(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /** Polls drive to see if media has been inserted or removed.
   * @param slot A callback which will be called when the poll is completed.
   */
  void poll_for_media(const SlotAsyncReady& slot);

  /** Polls drive to see if media has been inserted or removed.
   */
  void poll_for_media();


  /** Finishes an operation started with g_drive_poll_for_media() on a drive.
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the drive has been poll_for_mediaed successfully,
   * <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto poll_for_media_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Gets the identifier of the given kind for @a drive. The only
   * identifier currently available is
   * G_DRIVE_IDENTIFIER_KIND_UNIX_DEVICE.
   *
   * @param kind The kind of identifier to return.
   * @return A newly allocated string containing the
   * requested identifier, or <tt>nullptr</tt> if the Drive
   * doesn't have this kind of identifier.
   */
  auto get_identifier(const std::string& kind) const -> std::string;


  /** Gets the kinds of identifiers that @a drive has.
   * Use g_drive_get_identifier() to obtain the identifiers
   * themselves.
   *
   * @return A <tt>nullptr</tt>-terminated
   * array of strings containing kinds of identifiers.
   */
  auto enumerate_identifiers() const -> std::vector<Glib::ustring>;

  /** @newin{2,22} */
  void start(const Glib::RefPtr<MountOperation>& mount_operation, const Glib::RefPtr<Cancellable>& cancellable, const SlotAsyncReady& slot, StartFlags flags = StartFlags::NONE);
  /** @newin{2,22} */
  void start(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, StartFlags flags = StartFlags::NONE);


  /** Finishes starting a drive.
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the drive has been started successfully,
   * <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto start_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;

  /** @newin{2,22}
   */
  auto can_start() const -> bool;

  /** @newin{2,22}
   */
  auto can_start_degraded() const -> bool;

  /** @newin{2,22} */
  void stop(const Glib::RefPtr<MountOperation>& mount_operation, const Glib::RefPtr<Cancellable>& cancellable, const SlotAsyncReady& slot, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);
  /** @newin{2,22} */
  void stop(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);


  /** Finishes stopping a drive.
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the drive has been stopped successfully,
   * <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto stop_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;

  /** @newin{2,22}
   */
  auto can_stop() const -> bool;


  /** Gets a hint about how a drive can be started/stopped.
   *
   * @newin{2,22}
   *
   * @return A value from the Gio::Drive::StartStopType enumeration.
   */
  auto get_start_stop_type() const -> StartStopType;


  /** Gets the sort key for @a drive, if any.
   *
   * @newin{2,32}
   *
   * @return Sorting key for @a drive or <tt>nullptr</tt> if no such key is available.
   */
  auto get_sort_key() const -> Glib::ustring;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the drive's state has changed.
   *
   * @newin{2,20}
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%disconnected()</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when the Drive have been
   * disconnected. If the recipient is holding references to the
   * object they should release them so the object can be
   * finalized.
   *
   * @newin{2,20}
   */

  auto signal_disconnected() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%eject_button()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the physical eject button (if any) of a drive has
   * been pressed.
   *
   * @newin{2,20}
   */

  auto signal_eject_button() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%stop_button()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the physical stop button (if any) of a drive has
   * been pressed.
   *
   * @newin{2,22}
   */

  auto signal_stop_button() -> Glib::SignalProxy<void()>;


protected:
  //_WRAP_VFUNC(Glib::ustring get_name() const, get_name)
  //Careful of ref-counting: //_WRAP_VFUNC(Glib::RefPtr<Icon> get_icon() const, get_icon)
  //_WRAP_VFUNC(bool has_volumes() const, has_volumes)


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed();
  /// This is a default handler for the signal signal_disconnected().
  virtual void on_disconnected();
  /// This is a default handler for the signal signal_eject_button().
  virtual void on_eject_button();
  /// This is a default handler for the signal signal_stop_button().
  virtual void on_stop_button();


};

} // namespace Gio

namespace Glib
{

//Pre-declare this so we can use it in TypeTrait:
GIOMM_API
auto wrap(GDrive* object, bool take_copy) -> Glib::RefPtr<Gio::Drive>;

namespace Container_Helpers
{

/** This specialization of TypeTraits exists
 * because the default use of Glib::wrap(GObject*),
 * instead of a specific Glib::wrap(GSomeInterface*),
 * would not return a wrapper for an interface.
 */
template <>
struct TypeTraits< Glib::RefPtr<Gio::Drive> >
{
  using CppType = Glib::RefPtr<Gio::Drive>;
  using CType = GDrive*;
  using CTypeNonConst = GDrive*;

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
inline auto operator|(Drive::StartFlags lhs, Drive::StartFlags rhs) -> Drive::StartFlags
  { return static_cast<Drive::StartFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(Drive::StartFlags lhs, Drive::StartFlags rhs) -> Drive::StartFlags
  { return static_cast<Drive::StartFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(Drive::StartFlags lhs, Drive::StartFlags rhs) -> Drive::StartFlags
  { return static_cast<Drive::StartFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(Drive::StartFlags flags) -> Drive::StartFlags
  { return static_cast<Drive::StartFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(Drive::StartFlags& lhs, Drive::StartFlags rhs) -> Drive::StartFlags&
  { return (lhs = static_cast<Drive::StartFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(Drive::StartFlags& lhs, Drive::StartFlags rhs) -> Drive::StartFlags&
  { return (lhs = static_cast<Drive::StartFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(Drive::StartFlags& lhs, Drive::StartFlags rhs) -> Drive::StartFlags&
  { return (lhs = static_cast<Drive::StartFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Drive::StartFlags> : public Glib::Value_Flags<Gio::Drive::StartFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Drive::StartStopType> : public Glib::Value_Enum<Gio::Drive::StartStopType>
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
   * @relates Gio::Drive
   */
  GIOMM_API
  auto wrap(GDrive* object, bool take_copy = false) -> Glib::RefPtr<Gio::Drive>;

} // namespace Glib


#endif /* _GIOMM_DRIVE_H */

