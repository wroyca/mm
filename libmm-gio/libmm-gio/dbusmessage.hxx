
#ifndef _GIOMM_DBUSMESSAGE_H
#define _GIOMM_DBUSMESSAGE_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <libmm-glib/utility.hxx>
#include <libmm-glib/variant.hxx>

#ifdef G_OS_UNIX
  #include <libmm-gio/unixfdlist.hxx>
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusMessage = struct _GDBusMessage;
using GDBusMessageClass = struct _GDBusMessageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class GIOMM_API Message_Class;
}
#endif

namespace Gio::DBus
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

} // namespace Gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::DBus::CapabilityFlags>
    : public Glib::Value_Flags<Gio::DBus::CapabilityFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio::DBus
{

  class GIOMM_API Message : public Glib::Object
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
    explicit Message (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<Message>;

    static auto
    create_signal (const Glib::ustring& path,
                   const Glib::ustring& iface,
                   const Glib::ustring& signal) -> Glib::RefPtr<Message>;

    static auto
    create_method_call (const Glib::ustring& name,
                        const Glib::ustring& path,
                        const Glib::ustring& iface,
                        const Glib::ustring& method) -> Glib::RefPtr<Message>;

    static auto
    create_method_reply (const Glib::RefPtr<Message>& method_call_message)
        -> Glib::RefPtr<Message>;

    static auto
    create_method_error_literal (
        const Glib::RefPtr<const Message>& method_call_message,
        const Glib::ustring& error_name,
        const Glib::ustring& error_message) -> Glib::RefPtr<Message>;

    static auto
    create_from_blob (const guchar* blob,
                      gsize blob_len,
                      CapabilityFlags capabilities = CapabilityFlags::NONE)
        -> Glib::RefPtr<Message>;

    auto
    print (guint indent) -> Glib::ustring;

    auto
    get_locked () const -> bool;

    void
    lock ();

    auto
    copy () const -> Glib::RefPtr<Message>;

    auto
    get_message_type () const -> MessageType;

    void
    set_message_type (MessageType type);

    enum class ByteOrder
    {
      BIG_ENDIAN_ORDER = 'B',
      LITTLE_ENDIAN_ORDER = 'l'
    };

    auto
    get_byte_order () const -> ByteOrder;

    void
    set_byte_order (ByteOrder byte_order);

    auto
    get_serial () const -> guint32;

    void
    set_serial (guint32 serial);

    auto
    get_flags () const -> MessageFlags;

    void
    set_flags (MessageFlags flags);

    void
    get_body (Glib::VariantBase& value) const;

    void
    set_body (const Glib::VariantBase& body);

#ifdef G_OS_UNIX

    auto
    get_unix_fd_list () -> Glib::RefPtr<UnixFDList>;
#endif

#ifdef G_OS_UNIX

    auto
    get_unix_fd_list () const -> Glib::RefPtr<const UnixFDList>;
#endif

#ifdef G_OS_UNIX

    void
    set_unix_fd_list (const Glib::RefPtr<UnixFDList>& fd_list);
#endif

#ifdef G_OS_UNIX

    void
    unset_unix_fd_list ();
#endif

    auto
    get_num_unix_fds () const -> guint32;

    void
    set_num_unix_fds (guint32 value);

    void
    get_header (Glib::VariantBase& value,
                MessageHeaderField header_field) const;

    void
    set_header (MessageHeaderField header_field,
                const Glib::VariantBase& value);

    auto
    get_header_fields () const -> std::vector<guchar>;

    auto
    get_destination () const -> Glib::ustring;

    void
    set_destination (const Glib::ustring& value);

    auto
    get_error_name () const -> Glib::ustring;

    void
    set_error_name (const Glib::ustring& value);

    auto
    get_interface () const -> Glib::ustring;

    void
    set_interface (const Glib::ustring& value);

    auto
    get_member () const -> Glib::ustring;

    void
    set_member (const Glib::ustring& value);

    auto
    get_path () const -> Glib::ustring;

    void
    set_path (const Glib::ustring& value);

    auto
    get_reply_serial () const -> guint32;

    void
    set_reply_serial (guint32 value);

    auto
    get_sender () const -> Glib::ustring;

    void
    set_sender (const Glib::ustring& value);

    auto
    get_signature () const -> Glib::ustring;

    void
    set_signature (const Glib::ustring& value);

    auto
    get_arg0 () const -> Glib::ustring;

    static auto
    bytes_needed (const guchar* blob, gsize blob_len) -> gssize;

    auto
    to_blob (gsize& out_size,
             CapabilityFlags capabilities = CapabilityFlags::NONE) -> guchar*;

    void
    to_exception ();

    auto
    property_locked () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gio::DBus

namespace Glib
{

  GIOMM_API
  auto
  wrap (GDBusMessage* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Message>;
} // namespace Glib

#endif
