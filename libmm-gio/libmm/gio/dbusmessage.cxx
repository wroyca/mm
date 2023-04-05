// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusmessage.hxx>
#include <libmm/gio/dbusmessage_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/error.hxx>

#ifdef G_OS_UNIX
  #include <libmm/gio/unixfdlist.hxx>
#endif

namespace gio::DBus
{

  using ByteOrder = Message::ByteOrder;

  auto
  Message::get_body (glib::VariantBase& value) const -> void
  {
    const GVariant* const g_value =
        g_dbus_message_get_body (const_cast<GDBusMessage*> (gobj ()));

    if (!g_value)
      return;

    value.init (g_value, true);
  }

  auto
  Message::get_header (glib::VariantBase& value,
                       MessageHeaderField header_field) const -> void
  {
    const GVariant* const g_value = g_dbus_message_get_header (
        const_cast<GDBusMessage*> (gobj ()),
        (GDBusMessageHeaderField) header_field);

    if (!g_value)
      return;

    value.init (g_value, true);
  }

#ifdef G_OS_UNIX
  void
  Message::unset_unix_fd_list ()
  {
    g_dbus_message_set_unix_fd_list (gobj (), nullptr);
  }
#endif

} // namespace gio::DBus

namespace
{
}

auto
glib::Value<gio::DBus::CapabilityFlags>::value_type () -> GType
{
  return g_dbus_capability_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GDBusMessage* object, const bool take_copy) -> RefPtr<gio::DBus::Message>
  {
    return glib::make_refptr_for_instance<gio::DBus::Message> (
        dynamic_cast<gio::DBus::Message*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  Message_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Message_Class::class_init_function;

      register_derived_type (g_dbus_message_get_type ());
    }

    return *this;
  }

  auto
  Message_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Message_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Message ((GDBusMessage*) object);
  }

  auto
  Message::gobj_copy () -> GDBusMessage*
  {
    reference ();
    return gobj ();
  }

  Message::Message (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Message::Message (GDBusMessage* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Message::Message (Message&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Message::operator= (Message&& src) noexcept -> Message&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Message::~Message () noexcept = default;

  Message::CppClassType Message::message_class_;

  auto
  Message::get_type () -> GType
  {
    return message_class_.init ().get_type ();
  }

  auto
  Message::get_base_type () -> GType
  {
    return g_dbus_message_get_type ();
  }

  Message::Message ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (message_class_.init ()))
  {
  }

  auto
  Message::create () -> glib::RefPtr<Message>
  {
    return glib::make_refptr_for_instance<Message> (new Message ());
  }

  auto
  Message::create_signal (const glib::ustring& path,
                          const glib::ustring& iface,
                          const glib::ustring& signal) -> glib::RefPtr<Message>
  {
    return glib::wrap (g_dbus_message_new_signal (path.c_str (),
                                                  iface.c_str (),
                                                  signal.c_str ()));
  }

  auto
  Message::create_method_call (const glib::ustring& name,
                               const glib::ustring& path,
                               const glib::ustring& iface,
                               const glib::ustring& method) -> glib::RefPtr<Message>
  {
    return glib::wrap (g_dbus_message_new_method_call (name.c_str (),
                                                       path.c_str (),
                                                       iface.c_str (),
                                                       method.c_str ()));
  }

  auto
  Message::create_method_reply (
      const glib::RefPtr<Message>& method_call_message) -> glib::RefPtr<Message>
  {
    return glib::wrap (
        g_dbus_message_new_method_reply (glib::unwrap (method_call_message)));
  }

  auto
  Message::create_method_error_literal (
      const glib::RefPtr<const Message>& method_call_message,
      const glib::ustring& error_name,
      const glib::ustring& error_message) -> glib::RefPtr<Message>
  {
    return glib::wrap (g_dbus_message_new_method_error_literal (
        const_cast<GDBusMessage*> (glib::unwrap (method_call_message)),
        error_name.c_str (),
        error_message.c_str ()));
  }

  auto
  Message::create_from_blob (const guchar* blob,
                             const gsize blob_len,
                             CapabilityFlags capabilities) -> glib::RefPtr<Message>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_dbus_message_new_from_blob (
        const_cast<guchar*> (blob),
        blob_len,
        static_cast<GDBusCapabilityFlags> (capabilities),
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Message::print (const guint indent) -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_dbus_message_print (gobj (), indent));
  }

  auto
  Message::get_locked () const -> bool
  {
    return g_dbus_message_get_locked (const_cast<GDBusMessage*> (gobj ()));
  }

  auto
  Message::lock () -> void
  {
    g_dbus_message_lock (gobj ());
  }

  auto
  Message::copy () const -> glib::RefPtr<Message>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_dbus_message_copy (const_cast<GDBusMessage*> (gobj ()), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Message::get_message_type () const -> MessageType
  {
    return static_cast<MessageType> (
        g_dbus_message_get_message_type (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_message_type (MessageType type) -> void
  {
    g_dbus_message_set_message_type (gobj (),
                                     static_cast<GDBusMessageType> (type));
  }

  auto
  Message::get_byte_order () const -> ByteOrder
  {
    return static_cast<ByteOrder> (
        g_dbus_message_get_byte_order (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_byte_order (ByteOrder byte_order) -> void
  {
    g_dbus_message_set_byte_order (
        gobj (),
        static_cast<GDBusMessageByteOrder> (byte_order));
  }

  auto
  Message::get_serial () const -> guint32
  {
    return g_dbus_message_get_serial (const_cast<GDBusMessage*> (gobj ()));
  }

  auto
  Message::set_serial (const guint32 serial) -> void
  {
    g_dbus_message_set_serial (gobj (), serial);
  }

  auto
  Message::get_flags () const -> MessageFlags
  {
    return static_cast<MessageFlags> (
        g_dbus_message_get_flags (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_flags (MessageFlags flags) -> void
  {
    g_dbus_message_set_flags (gobj (), static_cast<GDBusMessageFlags> (flags));
  }

  auto
  Message::set_body (const glib::VariantBase& body) -> void
  {
    g_dbus_message_set_body (gobj (), const_cast<GVariant*> (body.gobj ()));
  }

#ifdef G_OS_UNIX
  auto
  Message::get_unix_fd_list () -> glib::RefPtr<UnixFDList>
  {
    auto retvalue = glib::wrap (g_dbus_message_get_unix_fd_list (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }
#endif

#ifdef G_OS_UNIX
  auto
  Message::get_unix_fd_list () const -> glib::RefPtr<const UnixFDList>
  {
    return const_cast<Message*> (this)->get_unix_fd_list ();
  }
#endif

#ifdef G_OS_UNIX
  void
  Message::set_unix_fd_list (const glib::RefPtr<UnixFDList>& fd_list)
  {
    g_dbus_message_set_unix_fd_list (gobj (), glib::unwrap (fd_list));
  }
#endif

  auto
  Message::get_num_unix_fds () const -> guint32
  {
    return g_dbus_message_get_num_unix_fds (
        const_cast<GDBusMessage*> (gobj ()));
  }

  auto
  Message::set_num_unix_fds (const guint32 value) -> void
  {
    g_dbus_message_set_num_unix_fds (gobj (), value);
  }

  auto
  Message::set_header (MessageHeaderField header_field,
                       const glib::VariantBase& value) -> void
  {
    g_dbus_message_set_header (
        gobj (),
        static_cast<GDBusMessageHeaderField> (header_field),
        const_cast<GVariant*> (value.gobj ()));
  }

  auto
  Message::get_header_fields () const -> std::vector<guchar>
  {
    return glib::ArrayHandler<guchar>::array_to_vector (
        g_dbus_message_get_header_fields (const_cast<GDBusMessage*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Message::get_destination () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_message_get_destination (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_destination (const glib::ustring& value) -> void
  {
    g_dbus_message_set_destination (gobj (), value.c_str ());
  }

  auto
  Message::get_error_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_message_get_error_name (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_error_name (const glib::ustring& value) -> void
  {
    g_dbus_message_set_error_name (gobj (), value.c_str ());
  }

  auto
  Message::get_interface () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_message_get_interface (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_interface (const glib::ustring& value) -> void
  {
    g_dbus_message_set_interface (gobj (), value.c_str ());
  }

  auto
  Message::get_member () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_message_get_member (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_member (const glib::ustring& value) -> void
  {
    g_dbus_message_set_member (gobj (), value.c_str ());
  }

  auto
  Message::get_path () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_message_get_path (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_path (const glib::ustring& value) -> void
  {
    g_dbus_message_set_path (gobj (), value.c_str ());
  }

  auto
  Message::get_reply_serial () const -> guint32
  {
    return g_dbus_message_get_reply_serial (
        const_cast<GDBusMessage*> (gobj ()));
  }

  auto
  Message::set_reply_serial (const guint32 value) -> void
  {
    g_dbus_message_set_reply_serial (gobj (), value);
  }

  auto
  Message::get_sender () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_message_get_sender (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_sender (const glib::ustring& value) -> void
  {
    g_dbus_message_set_sender (gobj (), value.c_str ());
  }

  auto
  Message::get_signature () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_message_get_signature (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::set_signature (const glib::ustring& value) -> void
  {
    g_dbus_message_set_signature (gobj (), value.c_str ());
  }

  auto
  Message::get_arg0 () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_message_get_arg0 (const_cast<GDBusMessage*> (gobj ())));
  }

  auto
  Message::bytes_needed (const guchar* blob, const gsize blob_len) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_dbus_message_bytes_needed (
        const_cast<guchar*> (blob),
        blob_len,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Message::to_blob (gsize& out_size, CapabilityFlags capabilities) -> guchar*
  {
    GError* gerror = nullptr;
    const auto retvalue = g_dbus_message_to_blob (
        gobj (),
        &out_size,
        static_cast<GDBusCapabilityFlags> (capabilities),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Message::to_exception () -> void
  {
    GError* gerror = nullptr;
    g_dbus_message_to_gerror (gobj (), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Message::property_locked () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "locked"};
  }

} // namespace gio::DBus
