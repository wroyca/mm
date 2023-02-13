
#ifndef _GIOMM_DBUSMESSAGE_H
#define _GIOMM_DBUSMESSAGE_H

#include <libmm-gio/gioconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The giomm Development Team
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
#include <libmm-glib/variant.hpp>
#include <libmm-glib/utility.hpp>

#ifdef G_OS_UNIX
#include <libmm-gio/unixfdlist.hpp>
#endif


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusMessage = struct _GDBusMessage;
using GDBusMessageClass = struct _GDBusMessageClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API Message_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{

/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var MessageType INVALID
 * Message is of invalid type.
 *
 *  @var MessageType METHOD_CALL
 * Method call.
 *
 *  @var MessageType METHOD_RETURN
 * Method reply.
 *
 *  @var MessageType ERROR
 * Error reply.
 *
 *  @var MessageType SIGNAL
 * Signal emission.
 *
 *  @enum MessageType
 *
 * Message types used in Gio::DBus::Message.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 */
enum class MessageType
{
  INVALID,
  METHOD_CALL,
  METHOD_RETURN,
  ERROR,
  SIGNAL
};


/**
 *  @var MessageFlags NONE
 * No flags set.
 *
 *  @var MessageFlags NO_REPLY_EXPECTED
 * A reply is not expected.
 *
 *  @var MessageFlags NO_AUTO_START
 * The bus must not launch an
 * owner for the destination name in response to this message.
 *
 *  @var MessageFlags ALLOW_INTERACTIVE_AUTHORIZATION
 * If set on a method
 * call, this flag means that the caller is prepared to wait for interactive
 * authorization. @newin{2,46}
 *
 *  @enum MessageFlags
 *
 * Message flags used in Gio::DBus::Message.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>MessageFlags operator|(MessageFlags, MessageFlags)</tt><br>
 * <tt>MessageFlags operator&(MessageFlags, MessageFlags)</tt><br>
 * <tt>MessageFlags operator^(MessageFlags, MessageFlags)</tt><br>
 * <tt>MessageFlags operator~(MessageFlags)</tt><br>
 * <tt>MessageFlags& operator|=(MessageFlags&, MessageFlags)</tt><br>
 * <tt>MessageFlags& operator&=(MessageFlags&, MessageFlags)</tt><br>
 * <tt>MessageFlags& operator^=(MessageFlags&, MessageFlags)</tt><br>
 */
enum class MessageFlags
{
  NONE = 0x0,
  NO_REPLY_EXPECTED = (1<<0),
  NO_AUTO_START = (1<<1),
  ALLOW_INTERACTIVE_AUTHORIZATION = (1<<2)
};

/** @ingroup giommEnums */
inline auto operator|(MessageFlags lhs, MessageFlags rhs) -> MessageFlags
  { return static_cast<MessageFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(MessageFlags lhs, MessageFlags rhs) -> MessageFlags
  { return static_cast<MessageFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(MessageFlags lhs, MessageFlags rhs) -> MessageFlags
  { return static_cast<MessageFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(MessageFlags flags) -> MessageFlags
  { return static_cast<MessageFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(MessageFlags& lhs, MessageFlags rhs) -> MessageFlags&
  { return (lhs = static_cast<MessageFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(MessageFlags& lhs, MessageFlags rhs) -> MessageFlags&
  { return (lhs = static_cast<MessageFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(MessageFlags& lhs, MessageFlags rhs) -> MessageFlags&
  { return (lhs = static_cast<MessageFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**
 *  @var MessageHeaderField INVALID
 * Not a valid header field.
 *
 *  @var MessageHeaderField PATH
 * The object path.
 *
 *  @var MessageHeaderField INTERFACE
 * The interface name.
 *
 *  @var MessageHeaderField MEMBER
 * The method or signal name.
 *
 *  @var MessageHeaderField ERROR_NAME
 * The name of the error that occurred.
 *
 *  @var MessageHeaderField REPLY_SERIAL
 * The serial number the message is a reply to.
 *
 *  @var MessageHeaderField DESTINATION
 * The name the message is intended for.
 *
 *  @var MessageHeaderField SENDER
 * Unique name of the sender of the message (filled in by the bus).
 *
 *  @var MessageHeaderField SIGNATURE
 * The signature of the message body.
 *
 *  @var MessageHeaderField NUM_UNIX_FDS
 * The number of UNIX file descriptors that accompany the message.
 *
 *  @enum MessageHeaderField
 *
 * Header fields used in Gio::DBus::Message.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 */
enum class MessageHeaderField
{
  INVALID,
  PATH,
  INTERFACE,
  MEMBER,
  ERROR_NAME,
  REPLY_SERIAL,
  DESTINATION,
  SENDER,
  SIGNATURE,
  NUM_UNIX_FDS
};


/**
 *  @var CapabilityFlags NONE
 * No flags set.
 *
 *  @var CapabilityFlags UNIX_FD_PASSING
 * The connection
 * supports exchanging UNIX file descriptors with the remote peer.
 *
 *  @enum CapabilityFlags
 *
 * Capabilities negotiated with the remote peer.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>CapabilityFlags operator|(CapabilityFlags, CapabilityFlags)</tt><br>
 * <tt>CapabilityFlags operator&(CapabilityFlags, CapabilityFlags)</tt><br>
 * <tt>CapabilityFlags operator^(CapabilityFlags, CapabilityFlags)</tt><br>
 * <tt>CapabilityFlags operator~(CapabilityFlags)</tt><br>
 * <tt>CapabilityFlags& operator|=(CapabilityFlags&, CapabilityFlags)</tt><br>
 * <tt>CapabilityFlags& operator&=(CapabilityFlags&, CapabilityFlags)</tt><br>
 * <tt>CapabilityFlags& operator^=(CapabilityFlags&, CapabilityFlags)</tt><br>
 */
enum class CapabilityFlags
{
  NONE = 0x0,
  UNIX_FD_PASSING = (1<<0)
};

/** @ingroup giommEnums */
inline auto operator|(CapabilityFlags lhs, CapabilityFlags rhs) -> CapabilityFlags
  { return static_cast<CapabilityFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(CapabilityFlags lhs, CapabilityFlags rhs) -> CapabilityFlags
  { return static_cast<CapabilityFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(CapabilityFlags lhs, CapabilityFlags rhs) -> CapabilityFlags
  { return static_cast<CapabilityFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(CapabilityFlags flags) -> CapabilityFlags
  { return static_cast<CapabilityFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(CapabilityFlags& lhs, CapabilityFlags rhs) -> CapabilityFlags&
  { return (lhs = static_cast<CapabilityFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(CapabilityFlags& lhs, CapabilityFlags rhs) -> CapabilityFlags&
  { return (lhs = static_cast<CapabilityFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(CapabilityFlags& lhs, CapabilityFlags rhs) -> CapabilityFlags&
  { return (lhs = static_cast<CapabilityFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::DBus::CapabilityFlags> : public Glib::Value_Flags<Gio::DBus::CapabilityFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio::DBus
{


/** A type for representing D-Bus messages that can be sent or received on a
 * Connection.
 *
 * @newin{2,28}
 * @ingroup DBus
 */

class GIOMM_API Message : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Message;
  using CppClassType = Message_Class;
  using BaseObjectType = GDBusMessage;
  using BaseClassType = GDBusMessageClass;

  // noncopyable
  Message(const Message&) = delete;
  auto operator=(const Message&) -> Message& = delete;

private:  friend class Message_Class;
  static CppClassType message_class_;

protected:
  explicit Message(const Glib::ConstructParams& construct_params);
  explicit Message(GDBusMessage* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Message(Message&& src) noexcept;
  auto operator=(Message&& src) noexcept -> Message&;

  ~Message() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusMessage*       { return reinterpret_cast<GDBusMessage*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusMessage* { return reinterpret_cast<GDBusMessage*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusMessage*;

private:


protected:
  Message();


public:

  /** Creates a new empty Gio::DBus::Message.
   *
   * @newin{2,26}
   *
   * @return A Gio::DBus::Message. Free with Glib::object_unref().
   */


  static auto create() -> Glib::RefPtr<Message>;


  // Note that we can't use _WRAP_CTOR() and _WRAP_CREATE() because the C functions do more than just call g_object_new():
  // See http://bugzilla.gnome.org/show_bug.cgi?id=624977

  // See here about whether the parameters should be ustring or std::string:
  // http://dbus.freedesktop.org/doc/dbus-specification.html#message-protocol-names
  // They are generally UTF-8 that can only contain the ASCII subset,
  // so ustring still seems preferrable to std::string, which generally implies an unknown encoding for us.

  // The parameter name 'interface' can cause compilation errors with MinGW.
  // See https://bugzilla.gnome.org/show_bug.cgi?id=735137
  // The parameter name in glib is 'interface_'.

  /** Creates a new Gio::DBus::Message for a signal emission.
   *
   * @newin{2,26}
   *
   * @param path A valid object path.
   * @param iface A valid D-Bus interface name.
   * @param signal A valid signal name.
   * @return A Gio::DBus::Message. Free with Glib::object_unref().
   */
  static auto create_signal(const Glib::ustring& path, const Glib::ustring& iface, const Glib::ustring& signal) -> Glib::RefPtr<Message>;

  /** Creates a new Gio::DBus::Message for a method call.
   *
   * @newin{2,26}
   *
   * @param name A valid D-Bus name or <tt>nullptr</tt>.
   * @param path A valid object path.
   * @param iface A valid D-Bus interface name or <tt>nullptr</tt>.
   * @param method A valid method name.
   * @return A Gio::DBus::Message. Free with Glib::object_unref().
   */
  static auto create_method_call(const Glib::ustring& name, const Glib::ustring& path, const Glib::ustring& iface, const Glib::ustring& method) -> Glib::RefPtr<Message>;

  /** Creates a new Gio::DBus::Message that is a reply to @a method_call_message.
   *
   * @newin{2,26}
   *
   * @param method_call_message A message of type Gio::DBus::MessageType::METHOD_CALL to
   * create a reply message to.
   * @return Gio::DBus::Message. Free with Glib::object_unref().
   */
  static auto create_method_reply(const Glib::RefPtr<Message>& method_call_message) -> Glib::RefPtr<Message>;

  /** Creates a new Gio::DBus::Message that is an error reply to @a method_call_message.
   *
   * @newin{2,26}
   *
   * @param method_call_message A message of type Gio::DBus::MessageType::METHOD_CALL to
   * create a reply message to.
   * @param error_name A valid D-Bus error name.
   * @param error_message The D-Bus error message.
   * @return A Gio::DBus::Message. Free with Glib::object_unref().
   */
  static auto create_method_error_literal(const Glib::RefPtr<const Message>& method_call_message, const Glib::ustring& error_name, const Glib::ustring& error_message) -> Glib::RefPtr<Message>;

  // Ignore variable argument functions.


  /** Creates a new Gio::DBus::Message from the data stored at @a blob. The byte
   * order that the message was in can be retrieved using
   * g_dbus_message_get_byte_order().
   *
   * If the @a blob cannot be parsed, contains invalid fields, or contains invalid
   * headers, Gio::Error::INVALID_ARGUMENT will be returned.
   *
   * @newin{2,26}
   *
   * @param blob A blob representing a binary D-Bus message.
   * @param blob_len The length of @a blob.
   * @param capabilities A DBusCapabilityFlags describing what protocol features are supported.
   * @return A new Gio::DBus::Message or <tt>nullptr</tt> if @a error is set. Free with
   * Glib::object_unref().
   *
   * @throws Gio::Error
   */
  static auto create_from_blob(const guchar* blob, gsize blob_len, CapabilityFlags capabilities =  CapabilityFlags::NONE) -> Glib::RefPtr<Message>;


  /** Produces a human-readable multi-line description of @a message.
   *
   * The contents of the description has no ABI guarantees, the contents
   * and formatting is subject to change at any time. Typical output
   * looks something like this:
   *
   * [C example ellipted]
   * or
   *
   * [C example ellipted]
   *
   * @newin{2,26}
   *
   * @param indent Indentation level.
   * @return A string.
   */
  auto print(guint indent) -> Glib::ustring;


  /** Checks whether @a message is locked. To monitor changes to this
   * value, conncet to the Object::signal_notify() signal to listen for changes
   * on the Gio::DBus::Message::property_locked() property.
   *
   * @newin{2,26}
   *
   * @return <tt>true</tt> if @a message is locked, <tt>false</tt> otherwise.
   */
  auto get_locked() const -> bool;

  /** If @a message is locked, does nothing. Otherwise locks the message.
   *
   * @newin{2,26}
   */
  void lock();

  /** Copies @a message. The copy is a deep copy and the returned
   * Gio::DBus::Message is completely identical except that it is guaranteed
   * to not be locked.
   *
   * This operation can fail if e.g. @a message contains file descriptors
   * and the per-process or system-wide open files limit is reached.
   *
   * @newin{2,26}
   *
   * @return A new Gio::DBus::Message or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   *
   * @throws Gio::Error
   */
  auto copy() const -> Glib::RefPtr<Message>;


  /** Gets the type of @a message.
   *
   * @newin{2,26}
   *
   * @return A 8-bit unsigned integer (typically a value from the DBusMessageType enumeration).
   */
  auto get_message_type() const -> MessageType;

  /** Sets @a message to be of @a type.
   *
   * @newin{2,26}
   *
   * @param type A 8-bit unsigned integer (typically a value from the DBusMessageType enumeration).
   */
  void set_message_type(MessageType type);

  // BIG_ENDIAN and LITTLE_ENDIAN are defined as preprocessor macros somewhere.
  /**
   *  @var ByteOrder BIG_ENDIAN_ORDER
   * The byte order is big endian.
   *
   *  @var ByteOrder LITTLE_ENDIAN_ORDER
   * The byte order is little endian.
   *
   *  @enum ByteOrder
   *
   * Enumeration used to describe the byte order of a D-Bus message.
   *
   * @newin{2,26}
   *
   * @ingroup giommEnums
   */
  enum class ByteOrder
  {
    BIG_ENDIAN_ORDER = 'B',
    LITTLE_ENDIAN_ORDER = 'l'
  };


  /** Gets the byte order of @a message.
   *
   * @return The byte order.
   */
  auto get_byte_order() const -> ByteOrder;

  /** Sets the byte order of @a message.
   *
   * @param byte_order The byte order.
   */
  void set_byte_order(ByteOrder byte_order);


  /** Gets the serial for @a message.
   *
   * @newin{2,26}
   *
   * @return A #guint32.
   */
  auto get_serial() const -> guint32;

  /** Sets the serial for @a message.
   *
   * @newin{2,26}
   *
   * @param serial A #guint32.
   */
  void set_serial(guint32 serial);


  /** Gets the flags for @a message.
   *
   * @newin{2,26}
   *
   * @return Flags that are set (typically values from the DBusMessageFlags enumeration bitwise ORed together).
   */
  auto get_flags() const -> MessageFlags;

  /** Sets the flags to set on @a message.
   *
   * @newin{2,26}
   *
   * @param flags Flags for @a message that are set (typically values from the DBusMessageFlags
   * enumeration bitwise ORed together).
   */
  void set_flags(MessageFlags flags);

  /** Gets the body of a message.  The body is returned in @a value.
   * @param value Location in which to store the header.
   */
  void get_body(Glib::VariantBase& value) const;


  /** Sets the body @a message. As a side-effect the
   * Gio::DBus::MessageHeaderField::SIGNATURE header field is set to the
   * type string of @a body (or cleared if @a body is <tt>nullptr</tt>).
   *
   * If @a body is floating, @a message assumes ownership of @a body.
   *
   * @newin{2,26}
   *
   * @param body Either <tt>nullptr</tt> or a Variant that is a tuple.
   */
  void set_body(const Glib::VariantBase& body);


#ifdef  G_OS_UNIX

  /** Gets the UNIX file descriptors associated with @a message, if any.
   *
   * This method is only available on UNIX.
   *
   * The file descriptors normally correspond to G_VARIANT_TYPE_HANDLE
   * values in the body of the message. For example,
   * if Glib::variant_get_handle() returns 5, that is intended to be a reference
   * to the file descriptor that can be accessed by
   * `g_unix_fd_list_get (list, 5, ...)`.
   *
   * @newin{2,26}
   *
   * @return A UnixFDList or <tt>nullptr</tt> if no file descriptors are
   * associated. Do not free, this object is owned by @a message.
   */
  auto get_unix_fd_list() -> Glib::RefPtr<UnixFDList>;
#endif //  G_OS_UNIX


#ifdef  G_OS_UNIX

  /** Gets the UNIX file descriptors associated with @a message, if any.
   *
   * This method is only available on UNIX.
   *
   * The file descriptors normally correspond to G_VARIANT_TYPE_HANDLE
   * values in the body of the message. For example,
   * if Glib::variant_get_handle() returns 5, that is intended to be a reference
   * to the file descriptor that can be accessed by
   * `g_unix_fd_list_get (list, 5, ...)`.
   *
   * @newin{2,26}
   *
   * @return A UnixFDList or <tt>nullptr</tt> if no file descriptors are
   * associated. Do not free, this object is owned by @a message.
   */
  auto get_unix_fd_list() const -> Glib::RefPtr<const UnixFDList>;
#endif //  G_OS_UNIX


#ifdef  G_OS_UNIX

  /** Sets the UNIX file descriptors associated with @a message. As a
   * side-effect the Gio::DBus::MessageHeaderField::NUM_UNIX_FDS header
   * field is set to the number of fds in @a fd_list (or cleared if
   *  @a fd_list is <tt>nullptr</tt>).
   *
   * This method is only available on UNIX.
   *
   * When designing D-Bus APIs that are intended to be interoperable,
   * please note that non-GDBus implementations of D-Bus can usually only
   * access file descriptors if they are referenced by a value of type
   * G_VARIANT_TYPE_HANDLE in the body of the message.
   *
   * @newin{2,26}
   *
   * @param fd_list A UnixFDList or <tt>nullptr</tt>.
   */
  void set_unix_fd_list(const Glib::RefPtr<UnixFDList>& fd_list);
#endif //  G_OS_UNIX


#ifdef G_OS_UNIX
  /** Clears the existing UNIX file descriptor list.
   */
  void unset_unix_fd_list();
#endif //G_OS_UNIX


  /** Convenience getter for the Gio::DBus::MessageHeaderField::NUM_UNIX_FDS header field.
   *
   * @newin{2,26}
   *
   * @return The value.
   */
  auto get_num_unix_fds() const -> guint32;

  /** Convenience setter for the Gio::DBus::MessageHeaderField::NUM_UNIX_FDS header field.
   *
   * @newin{2,26}
   *
   * @param value The value to set.
   */
  void set_num_unix_fds(guint32 value);

  /** Gets a header field on the message.  The header is returned in @a value.
   * @param value Location in which to store the header.
   * @param header_field The header field type.
   */
  void get_header(Glib::VariantBase& value, MessageHeaderField header_field) const;


  /** Sets a header field on @a message.
   *
   * If @a value is floating, @a message assumes ownership of @a value.
   *
   * @newin{2,26}
   *
   * @param header_field A 8-bit unsigned integer (typically a value from the DBusMessageHeaderField enumeration).
   * @param value A Variant to set the header field or <tt>nullptr</tt> to clear the header field.
   */
  void set_header(MessageHeaderField header_field, const Glib::VariantBase& value);


  /** Gets an array of all header fields on @a message that are set.
   *
   * @newin{2,26}
   *
   * @return An array of header fields
   * terminated by Gio::DBus::MessageHeaderField::INVALID.  Each element
   * is a #guchar.
   */
  auto get_header_fields() const -> std::vector<guchar>;


  /** Convenience getter for the Gio::DBus::MessageHeaderField::DESTINATION header field.
   *
   * @newin{2,26}
   *
   * @return The value.
   */
  auto get_destination() const -> Glib::ustring;

  /** Convenience setter for the Gio::DBus::MessageHeaderField::DESTINATION header field.
   *
   * @newin{2,26}
   *
   * @param value The value to set.
   */
  void set_destination(const Glib::ustring& value);


  /** Convenience getter for the Gio::DBus::MessageHeaderField::ERROR_NAME header field.
   *
   * @newin{2,26}
   *
   * @return The value.
   */
  auto get_error_name() const -> Glib::ustring;

  /** Convenience setter for the Gio::DBus::MessageHeaderField::ERROR_NAME header field.
   *
   * @newin{2,26}
   *
   * @param value The value to set.
   */
  void set_error_name(const Glib::ustring& value);


  /** Convenience getter for the Gio::DBus::MessageHeaderField::INTERFACE header field.
   *
   * @newin{2,26}
   *
   * @return The value.
   */
  auto get_interface() const -> Glib::ustring;

  /** Convenience setter for the Gio::DBus::MessageHeaderField::INTERFACE header field.
   *
   * @newin{2,26}
   *
   * @param value The value to set.
   */
  void set_interface(const Glib::ustring& value);


  /** Convenience getter for the Gio::DBus::MessageHeaderField::MEMBER header field.
   *
   * @newin{2,26}
   *
   * @return The value.
   */
  auto get_member() const -> Glib::ustring;

  /** Convenience setter for the Gio::DBus::MessageHeaderField::MEMBER header field.
   *
   * @newin{2,26}
   *
   * @param value The value to set.
   */
  void set_member(const Glib::ustring& value);


  /** Convenience getter for the Gio::DBus::MessageHeaderField::PATH header field.
   *
   * @newin{2,26}
   *
   * @return The value.
   */
  auto get_path() const -> Glib::ustring;

  /** Convenience setter for the Gio::DBus::MessageHeaderField::PATH header field.
   *
   * @newin{2,26}
   *
   * @param value The value to set.
   */
  void set_path(const Glib::ustring& value);


  /** Convenience getter for the Gio::DBus::MessageHeaderField::REPLY_SERIAL header field.
   *
   * @newin{2,26}
   *
   * @return The value.
   */
  auto get_reply_serial() const -> guint32;

  /** Convenience setter for the Gio::DBus::MessageHeaderField::REPLY_SERIAL header field.
   *
   * @newin{2,26}
   *
   * @param value The value to set.
   */
  void set_reply_serial(guint32 value);


  /** Convenience getter for the Gio::DBus::MessageHeaderField::SENDER header field.
   *
   * @newin{2,26}
   *
   * @return The value.
   */
  auto get_sender() const -> Glib::ustring;

  /** Convenience setter for the Gio::DBus::MessageHeaderField::SENDER header field.
   *
   * @newin{2,26}
   *
   * @param value The value to set.
   */
  void set_sender(const Glib::ustring& value);


  /** Convenience getter for the Gio::DBus::MessageHeaderField::SIGNATURE header field.
   *
   * This will always be non-<tt>nullptr</tt>, but may be an empty string.
   *
   * @newin{2,26}
   *
   * @return The value.
   */
  auto get_signature() const -> Glib::ustring;

  /** Convenience setter for the Gio::DBus::MessageHeaderField::SIGNATURE header field.
   *
   * @newin{2,26}
   *
   * @param value The value to set.
   */
  void set_signature(const Glib::ustring& value);


  /** Convenience to get the first item in the body of @a message.
   *
   * @newin{2,26}
   *
   * @return The string item or <tt>nullptr</tt> if the first item in the body of
   *  @a message is not a string.
   */
  auto get_arg0() const -> Glib::ustring;


  /** Utility function to calculate how many bytes are needed to
   * completely deserialize the D-Bus message stored at @a blob.
   *
   * @newin{2,26}
   *
   * @param blob A blob representing a binary D-Bus message.
   * @param blob_len The length of @a blob (must be at least 16).
   * @return Number of bytes needed or -1 if @a error is set (e.g. if
   *  @a blob contains invalid data or not enough data is available to
   * determine the size).
   *
   * @throws Gio::Error
   */
  static auto bytes_needed(const guchar* blob, gsize blob_len) -> gssize;


  /** Serializes @a message to a blob. The byte order returned by
   * g_dbus_message_get_byte_order() will be used.
   *
   * @newin{2,26}
   *
   * @param out_size Return location for size of generated blob.
   * @param capabilities A DBusCapabilityFlags describing what protocol features are supported.
   * @return A pointer to a
   * valid binary D-Bus message of @a out_size bytes generated by @a message
   * or <tt>nullptr</tt> if @a error is set.
   *
   * @throws Gio::Error
   */
  auto to_blob(gsize& out_size, CapabilityFlags capabilities =  CapabilityFlags::NONE) -> guchar*;


  /** If @a message is not of type Gio::DBus::MessageType::ERROR does
   * nothing and returns <tt>false</tt>.
   *
   * Otherwise this method encodes the error in @a message as a Error
   * using g_dbus_error_set_dbus_error() using the information in the
   * Gio::DBus::MessageHeaderField::ERROR_NAME header field of @a message as
   * well as the first string item in @a message's body.
   *
   * @newin{2,26}
   *
   *
   * @throws Glib::Error
   */
  void to_exception();

  /** Whether the message is locked.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_locked() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gio::DBus::Message
   */
  GIOMM_API
  auto wrap(GDBusMessage* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Message>;
}


#endif /* _GIOMM_DBUSMESSAGE_H */

