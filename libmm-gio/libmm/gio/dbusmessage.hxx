// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSMESSAGE_H
#define _GIOMM_DBUSMESSAGE_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/glib/utility.hxx>
#include <libmm/glib/variant.hxx>

#ifdef G_OS_UNIX
  #include <libmm/gio/unixfdlist.hxx>
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusMessage = struct _GDBusMessage;
using GDBusMessageClass = struct _GDBusMessageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT Message_Class;
}
#endif

namespace gio::DBus
{

  enum class MessageType
  {
    INVALID,
    METHOD_CALL,
    METHOD_RETURN,
    ERROR,
    SIGNAL
  };

  enum class MessageFlags
  {
    NONE = 0x0,
    NO_REPLY_EXPECTED = (1 << 0),
    NO_AUTO_START = (1 << 1),
    ALLOW_INTERACTIVE_AUTHORIZATION = (1 << 2)
  };

  inline auto
  operator| (MessageFlags lhs, MessageFlags rhs) -> MessageFlags
  {
    return static_cast<MessageFlags> (static_cast<unsigned> (lhs) |
                                      static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (MessageFlags lhs, MessageFlags rhs) -> MessageFlags
  {
    return static_cast<MessageFlags> (static_cast<unsigned> (lhs) &
                                      static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (MessageFlags lhs, MessageFlags rhs) -> MessageFlags
  {
    return static_cast<MessageFlags> (static_cast<unsigned> (lhs) ^
                                      static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(MessageFlags flags) -> MessageFlags
  {
    return static_cast<MessageFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (MessageFlags& lhs, MessageFlags rhs) -> MessageFlags&
  {
    return (lhs = static_cast<MessageFlags> (static_cast<unsigned> (lhs) |
                                             static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (MessageFlags& lhs, MessageFlags rhs) -> MessageFlags&
  {
    return (lhs = static_cast<MessageFlags> (static_cast<unsigned> (lhs) &
                                             static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (MessageFlags& lhs, MessageFlags rhs) -> MessageFlags&
  {
    return (lhs = static_cast<MessageFlags> (static_cast<unsigned> (lhs) ^
                                             static_cast<unsigned> (rhs)));
  }

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

  enum class CapabilityFlags
  {
    NONE = 0x0,
    UNIX_FD_PASSING = (1 << 0)
  };

  inline auto
  operator| (CapabilityFlags lhs, CapabilityFlags rhs) -> CapabilityFlags
  {
    return static_cast<CapabilityFlags> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (CapabilityFlags lhs, CapabilityFlags rhs) -> CapabilityFlags
  {
    return static_cast<CapabilityFlags> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (CapabilityFlags lhs, CapabilityFlags rhs) -> CapabilityFlags
  {
    return static_cast<CapabilityFlags> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(CapabilityFlags flags) -> CapabilityFlags
  {
    return static_cast<CapabilityFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (CapabilityFlags& lhs, CapabilityFlags rhs) -> CapabilityFlags&
  {
    return (lhs = static_cast<CapabilityFlags> (static_cast<unsigned> (lhs) |
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (CapabilityFlags& lhs, CapabilityFlags rhs) -> CapabilityFlags&
  {
    return (lhs = static_cast<CapabilityFlags> (static_cast<unsigned> (lhs) &
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (CapabilityFlags& lhs, CapabilityFlags rhs) -> CapabilityFlags&
  {
    return (lhs = static_cast<CapabilityFlags> (static_cast<unsigned> (lhs) ^
                                                static_cast<unsigned> (rhs)));
  }

} // namespace gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DBus::CapabilityFlags>
    : public glib::Value_Flags<gio::DBus::CapabilityFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT Message : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Message;
    using CppClassType = Message_Class;
    using BaseObjectType = GDBusMessage;
    using BaseClassType = GDBusMessageClass;

    Message (const Message&) = delete;
    auto
    operator= (const Message&) -> Message& = delete;

  private:
    friend class Message_Class;
    static CppClassType message_class_;

  protected:
    explicit Message (const glib::ConstructParams& construct_params);
    explicit Message (GDBusMessage* castitem);

#endif

  public:
    Message (Message&& src) noexcept;
    auto
    operator= (Message&& src) noexcept -> Message&;

    ~Message () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusMessage*
    {
      return reinterpret_cast<GDBusMessage*> (gobject_);
    }

    auto
    gobj () const -> const GDBusMessage*
    {
      return reinterpret_cast<GDBusMessage*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusMessage*;

  private:
  protected:
    Message ();

  public:
    static auto
    create () -> glib::RefPtr<Message>;

    static auto
    create_signal (const glib::ustring& path,
                   const glib::ustring& iface,
                   const glib::ustring& signal) -> glib::RefPtr<Message>;

    static auto
    create_method_call (const glib::ustring& name,
                        const glib::ustring& path,
                        const glib::ustring& iface,
                        const glib::ustring& method) -> glib::RefPtr<Message>;

    static auto
    create_method_reply (const glib::RefPtr<Message>& method_call_message)
        -> glib::RefPtr<Message>;

    static auto
    create_method_error_literal (
        const glib::RefPtr<const Message>& method_call_message,
        const glib::ustring& error_name,
        const glib::ustring& error_message) -> glib::RefPtr<Message>;

    static auto
    create_from_blob (const guchar* blob,
                      gsize blob_len,
                      CapabilityFlags capabilities = CapabilityFlags::NONE)
        -> glib::RefPtr<Message>;

    auto
    print (guint indent) -> glib::ustring;

    auto
    get_locked () const -> bool;

    auto
    lock () -> void;

    auto
    copy () const -> glib::RefPtr<Message>;

    auto
    get_message_type () const -> MessageType;

    auto
    set_message_type (MessageType type) -> void;

    enum class ByteOrder
    {
      BIG_ENDIAN_ORDER = 'B',
      LITTLE_ENDIAN_ORDER = 'l'
    };

    auto
    get_byte_order () const -> ByteOrder;

    auto
    set_byte_order (ByteOrder byte_order) -> void;

    auto
    get_serial () const -> guint32;

    auto
    set_serial (guint32 serial) -> void;

    auto
    get_flags () const -> MessageFlags;

    auto
    set_flags (MessageFlags flags) -> void;

    auto
    get_body (glib::VariantBase& value) const -> void;

    auto
    set_body (const glib::VariantBase& body) -> void;

#ifdef G_OS_UNIX

    auto
    get_unix_fd_list () -> glib::RefPtr<UnixFDList>;
#endif

#ifdef G_OS_UNIX

    auto
    get_unix_fd_list () const -> glib::RefPtr<const UnixFDList>;
#endif

#ifdef G_OS_UNIX

    void
    set_unix_fd_list (const glib::RefPtr<UnixFDList>& fd_list);
#endif

#ifdef G_OS_UNIX

    void
    unset_unix_fd_list ();
#endif

    auto
    get_num_unix_fds () const -> guint32;

    auto
    set_num_unix_fds (guint32 value) -> void;

    auto
    get_header (glib::VariantBase& value, MessageHeaderField header_field) const
        -> void;

    auto
    set_header (MessageHeaderField header_field, const glib::VariantBase& value)
        -> void;

    auto
    get_header_fields () const -> std::vector<guchar>;

    auto
    get_destination () const -> glib::ustring;

    auto
    set_destination (const glib::ustring& value) -> void;

    auto
    get_error_name () const -> glib::ustring;

    auto
    set_error_name (const glib::ustring& value) -> void;

    auto
    get_interface () const -> glib::ustring;

    auto
    set_interface (const glib::ustring& value) -> void;

    auto
    get_member () const -> glib::ustring;

    auto
    set_member (const glib::ustring& value) -> void;

    auto
    get_path () const -> glib::ustring;

    auto
    set_path (const glib::ustring& value) -> void;

    auto
    get_reply_serial () const -> guint32;

    auto
    set_reply_serial (guint32 value) -> void;

    auto
    get_sender () const -> glib::ustring;

    auto
    set_sender (const glib::ustring& value) -> void;

    auto
    get_signature () const -> glib::ustring;

    auto
    set_signature (const glib::ustring& value) -> void;

    auto
    get_arg0 () const -> glib::ustring;

    static auto
    bytes_needed (const guchar* blob, gsize blob_len) -> gssize;

    auto
    to_blob (gsize& out_size,
             CapabilityFlags capabilities = CapabilityFlags::NONE) -> guchar*;

    auto
    to_exception () -> void;

    auto
    property_locked () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusMessage* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::Message>;
} // namespace glib

#endif
