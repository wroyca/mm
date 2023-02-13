
#ifndef _GIOMM_MOUNTOPERATION_H
#define _GIOMM_MOUNTOPERATION_H

#include <libmm-gio/gioconfig.hpp>


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


#include <libmm-glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMountOperation = struct _GMountOperation;
using GMountOperationClass = struct _GMountOperationClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API MountOperation_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var AskPasswordFlags NEED_PASSWORD
 * Operation requires a password.
 *
 *  @var AskPasswordFlags NEED_USERNAME
 * Operation requires a username.
 *
 *  @var AskPasswordFlags NEED_DOMAIN
 * Operation requires a domain.
 *
 *  @var AskPasswordFlags SAVING_SUPPORTED
 * Operation supports saving settings.
 *
 *  @var AskPasswordFlags ANONYMOUS_SUPPORTED
 * Operation supports anonymous users.
 *
 *  @var AskPasswordFlags TCRYPT
 * Operation takes TCRYPT parameters (Since: 2.58).
 *
 *  @enum AskPasswordFlags
 *
 * AskPasswordFlags are used to request specific information from the
 * user, or to notify the user of their choices in an authentication
 * situation.
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>AskPasswordFlags operator|(AskPasswordFlags, AskPasswordFlags)</tt><br>
 * <tt>AskPasswordFlags operator&(AskPasswordFlags, AskPasswordFlags)</tt><br>
 * <tt>AskPasswordFlags operator^(AskPasswordFlags, AskPasswordFlags)</tt><br>
 * <tt>AskPasswordFlags operator~(AskPasswordFlags)</tt><br>
 * <tt>AskPasswordFlags& operator|=(AskPasswordFlags&, AskPasswordFlags)</tt><br>
 * <tt>AskPasswordFlags& operator&=(AskPasswordFlags&, AskPasswordFlags)</tt><br>
 * <tt>AskPasswordFlags& operator^=(AskPasswordFlags&, AskPasswordFlags)</tt><br>
 */
enum class AskPasswordFlags
{
  NEED_PASSWORD = (1 << 0),
  NEED_USERNAME = (1 << 1),
  NEED_DOMAIN = (1 << 2),
  SAVING_SUPPORTED = (1 << 3),
  ANONYMOUS_SUPPORTED = (1 << 4),
  TCRYPT = (1 << 5)
};

/** @ingroup giommEnums */
inline auto operator|(AskPasswordFlags lhs, AskPasswordFlags rhs) -> AskPasswordFlags
  { return static_cast<AskPasswordFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(AskPasswordFlags lhs, AskPasswordFlags rhs) -> AskPasswordFlags
  { return static_cast<AskPasswordFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(AskPasswordFlags lhs, AskPasswordFlags rhs) -> AskPasswordFlags
  { return static_cast<AskPasswordFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(AskPasswordFlags flags) -> AskPasswordFlags
  { return static_cast<AskPasswordFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(AskPasswordFlags& lhs, AskPasswordFlags rhs) -> AskPasswordFlags&
  { return (lhs = static_cast<AskPasswordFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(AskPasswordFlags& lhs, AskPasswordFlags rhs) -> AskPasswordFlags&
  { return (lhs = static_cast<AskPasswordFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(AskPasswordFlags& lhs, AskPasswordFlags rhs) -> AskPasswordFlags&
  { return (lhs = static_cast<AskPasswordFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**
 *  @var PasswordSave NEVER
 * Never save a password.
 *
 *  @var PasswordSave FOR_SESSION
 * Save a password for the session.
 *
 *  @var PasswordSave PERMANENTLY
 * Save a password permanently.
 *
 *  @enum PasswordSave
 *
 * PasswordSave is used to indicate the lifespan of a saved password.
 *
 * #Gvfs stores passwords in the Gnome keyring when this flag allows it
 * to, and later retrieves it again from there.
 *
 * @ingroup giommEnums
 */
enum class PasswordSave
{
  NEVER,
  FOR_SESSION,
  PERMANENTLY
};


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::PasswordSave> : public Glib::Value_Enum<Gio::PasswordSave>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/**
 *  @var MountOperationResult HANDLED
 * The request was fulfilled and the
 * user specified data is now available.
 *
 *  @var MountOperationResult ABORTED
 * The user requested the mount operation
 * to be aborted.
 *
 *  @var MountOperationResult UNHANDLED
 * The request was unhandled (i.e. not
 * implemented).
 *
 *  @enum MountOperationResult
 *
 * MountOperationResult is returned as a result when a request for
 * information is send by the mounting operation.
 *
 * @ingroup giommEnums
 */
enum class MountOperationResult
{
  HANDLED,
  ABORTED,
  UNHANDLED
};


/** Authentication methods for mountable locations.
 *
 * MountOperation provides a mechanism for authenticating mountable operations, such as loop mounting files, hard drive partitions or server locations.
 *
 * Mounting operations are handed a MountOperation that they can use if they require any privileges or authentication for their volumes to be mounted (e.g.
 * a hard disk partition or an encrypted filesystem), or if they are implementing a remote server protocol which requires user credentials such as FTP or
 * WebDAV.
 *
 * Developers should instantiate a subclass of this that implements all the various callbacks to show the required dialogs.
 *
 * @newin{2,16}
 */

class GIOMM_API MountOperation : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MountOperation;
  using CppClassType = MountOperation_Class;
  using BaseObjectType = GMountOperation;
  using BaseClassType = GMountOperationClass;

  // noncopyable
  MountOperation(const MountOperation&) = delete;
  auto operator=(const MountOperation&) -> MountOperation& = delete;

private:  friend class MountOperation_Class;
  static CppClassType mountoperation_class_;

protected:
  explicit MountOperation(const Glib::ConstructParams& construct_params);
  explicit MountOperation(GMountOperation* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MountOperation(MountOperation&& src) noexcept;
  auto operator=(MountOperation&& src) noexcept -> MountOperation&;

  ~MountOperation() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GMountOperation*       { return reinterpret_cast<GMountOperation*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GMountOperation* { return reinterpret_cast<GMountOperation*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GMountOperation*;

private:


protected:
  MountOperation();

public:

  static auto create() -> Glib::RefPtr<MountOperation>;


  /** Get the user name from the mount operation.
   *
   * @return A string containing the user name.
   */
  auto get_username() const -> Glib::ustring;

  /** Sets the user name within @a op to @a username.
   *
   * @param username Input username.
   */
  void set_username(const Glib::ustring& username);

  /** Gets a password from the mount operation.
   *
   * @return A string containing the password within @a op.
   */
  auto get_password() const -> Glib::ustring;

  /** Sets the mount operation's password to @a password.
   *
   * @param password Password to set.
   */
  void set_password(const Glib::ustring& password);

  /** Check to see whether the mount operation is being used
   * for an anonymous user.
   *
   * @return <tt>true</tt> if mount operation is anonymous.
   */
  auto get_anonymous() const -> bool;

  /** Sets the mount operation to use an anonymous user if @a anonymous is <tt>true</tt>.
   *
   * @param anonymous Boolean value.
   */
  void set_anonymous(bool anonymous =  true);

  /** Gets the domain of the mount operation.
   *
   * @return A string set to the domain.
   */
  auto get_domain() const -> Glib::ustring;

  /** Sets the mount operation's domain.
   *
   * @param domain The domain to set.
   */
  void set_domain(const Glib::ustring& domain);

  /** Gets the state of saving passwords for the mount operation.
   *
   * @return A PasswordSave flag.
   */
  auto get_password_save() const -> PasswordSave;

  /** Sets the state of saving passwords for the mount operation.
   *
   * @param save A set of PasswordSave flags.
   */
  void set_password_save(PasswordSave save);

  /** Gets a choice from the mount operation.
   *
   * @return An integer containing an index of the user's choice from
   * the choice's list, or `0`.
   */
  auto get_choice() const -> int;

  /** Sets a default choice for the mount operation.
   *
   * @param choice An integer.
   */
  void set_choice(int choice);

  /** Emits the MountOperation::signal_reply() signal.
   *
   * @param result A MountOperationResult.
   */
  void reply(MountOperationResult result);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%ask_password(const Glib::ustring& message, const Glib::ustring& default_user, const Glib::ustring& default_domain, AskPasswordFlags flags)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a mount operation asks the user for a password.
   *
   * If the message contains a line break, the first line should be
   * presented as a heading. For example, it may be used as the
   * primary text in a Gtk::MessageDialog.
   *
   * @param message String containing a message to display to the user.
   * @param default_user String containing the default user name.
   * @param default_domain String containing the default domain.
   * @param flags A set of AskPasswordFlags.
   */

  auto signal_ask_password() -> Glib::SignalProxy<void(const Glib::ustring&, const Glib::ustring&, const Glib::ustring&, AskPasswordFlags)>;


  //TODO: We really need some test to make sure that our use of ArrayHandler is correct. murrayc.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%ask_question(const Glib::ustring& message, const std::vector<Glib::ustring>& choices)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when asking the user a question and gives a list of
   * choices for the user to choose from.
   *
   * If the message contains a line break, the first line should be
   * presented as a heading. For example, it may be used as the
   * primary text in a Gtk::MessageDialog.
   *
   * @param message String containing a message to display to the user.
   * @param choices An array of strings for each possible choice.
   */

  auto signal_ask_question() -> Glib::SignalProxy<void(const Glib::ustring&, const std::vector<Glib::ustring>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%reply(MountOperationResult result)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the user has replied to the mount operation.
   *
   * @param result A MountOperationResult indicating how the request was handled.
   */

  auto signal_reply() -> Glib::SignalProxy<void(MountOperationResult)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%aborted()</tt>
   *
   * Flags: Run Last
   *
   * Emitted by the backend when e.g.\ a device becomes unavailable
   * while a mount operation is in progress.
   *
   * Implementations of GMountOperation should handle this signal
   * by dismissing open password dialogs.
   *
   * @newin{2,20}
   */

  auto signal_aborted() -> Glib::SignalProxy<void()>;


  //TODO: The array of char* is not very pleasant to wrap:
  //_WRAP_SIGNAL( void show_processes(const Glib::ustring& message, GArray* processes, const gchar *choices[]);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%show_unmount_progress(const Glib::ustring& message, gint64 time_left, gint64 bytes_left)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when an unmount operation has been busy for more than some time
   * (typically 1.5 seconds).
   *
   * When unmounting or ejecting a volume, the kernel might need to flush
   * pending data in its buffers to the volume stable storage, and this operation
   * can take a considerable amount of time. This signal may be emitted several
   * times as long as the unmount operation is outstanding, and then one
   * last time when the operation is completed, with @a bytes_left set to zero.
   *
   * Implementations of GMountOperation should handle this signal by
   * showing an UI notification, and then dismiss it, or show another notification
   * of completion, when @a bytes_left reaches zero.
   *
   * If the message contains a line break, the first line should be
   * presented as a heading. For example, it may be used as the
   * primary text in a Gtk::MessageDialog.
   *
   * @newin{2,34}
   *
   * @param message String containing a message to display to the user.
   * @param time_left The estimated time left before the operation completes,
   * in microseconds, or -1.
   * @param bytes_left The amount of bytes to be written before the operation
   * completes (or -1 if such amount is not known), or zero if the operation
   * is completed.
   */

  auto signal_show_unmount_progress() -> Glib::SignalProxy<void(const Glib::ustring&, gint64, gint64)>;


  /** The user name that is used for authentication when carrying out
   * the mount operation.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_username() -> Glib::PropertyProxy< Glib::ustring > ;

/** The user name that is used for authentication when carrying out
   * the mount operation.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_username() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The password that is used for authentication when carrying out
   * the mount operation.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_password() -> Glib::PropertyProxy< Glib::ustring > ;

/** The password that is used for authentication when carrying out
   * the mount operation.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_password() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether to use an anonymous user when authenticating.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_anonymous() -> Glib::PropertyProxy< bool > ;

/** Whether to use an anonymous user when authenticating.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_anonymous() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The domain to use for the mount operation.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_domain() -> Glib::PropertyProxy< Glib::ustring > ;

/** The domain to use for the mount operation.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_domain() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Determines if and how the password information should be saved.
   *
   * Default value: Gio::PasswordSave::NEVER
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_password_save() -> Glib::PropertyProxy< PasswordSave > ;

/** Determines if and how the password information should be saved.
   *
   * Default value: Gio::PasswordSave::NEVER
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_password_save() const -> Glib::PropertyProxy_ReadOnly< PasswordSave >;

  /** The index of the user's choice when a question is asked during the
   * mount operation. See the MountOperation::signal_ask_question() signal.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_choice() -> Glib::PropertyProxy< int > ;

/** The index of the user's choice when a question is asked during the
   * mount operation. See the MountOperation::signal_ask_question() signal.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_choice() const -> Glib::PropertyProxy_ReadOnly< int >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_ask_password().
  virtual void on_ask_password(const Glib::ustring& message, const Glib::ustring& default_user, const Glib::ustring& default_domain, AskPasswordFlags flags);
  /// This is a default handler for the signal signal_ask_question().
  virtual void on_ask_question(const Glib::ustring& message, const std::vector<Glib::ustring>& choices);
  /// This is a default handler for the signal signal_reply().
  virtual void on_reply(MountOperationResult result);
  /// This is a default handler for the signal signal_aborted().
  virtual void on_aborted();
  /// This is a default handler for the signal signal_show_unmount_progress().
  virtual void on_show_unmount_progress(const Glib::ustring& message, gint64 time_left, gint64 bytes_left);


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::MountOperation
   */
  GIOMM_API
  auto wrap(GMountOperation* object, bool take_copy = false) -> Glib::RefPtr<Gio::MountOperation>;
}


#endif /* _GIOMM_MOUNTOPERATION_H */

