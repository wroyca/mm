


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/dbusmessage.hpp>
#include <mm/gio/private/dbusmessage_p.hpp>


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

#include <gio/gio.h>
#include <mm/glib/error.hpp>

#ifdef G_OS_UNIX
#include <mm/gio/unixfdlist.hpp>
#endif // G_OS_UNIX

namespace Gio::DBus
{

using ByteOrder = Message::ByteOrder;

auto Message::get_body (Glib::VariantBase &value) const -> void
{
  const GVariant* const g_value = g_dbus_message_get_body(const_cast<GDBusMessage*>(gobj()));

  if (!g_value)
    return;

  value.init(g_value, true /* take a reference */);
}

auto Message::get_header (Glib::VariantBase &value, MessageHeaderField header_field) const -> void
{
  const GVariant* const g_value = g_dbus_message_get_header(
    const_cast<GDBusMessage*>(gobj()), (GDBusMessageHeaderField)header_field);

  if (!g_value)
    return;

  value.init(g_value, true /* take a reference */);
}

#ifdef G_OS_UNIX
void
Message::unset_unix_fd_list()
{
  g_dbus_message_set_unix_fd_list(gobj(), nullptr);
}
#endif // G_OS_UNIX

} // namespace Gio

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gio::DBus::CapabilityFlags>::value_type() -> GType
{
  return g_dbus_capability_flags_get_type();
}


namespace Glib
{

auto wrap(GDBusMessage* object, const bool take_copy) -> RefPtr<Gio::DBus::Message>
{
  return Glib::make_refptr_for_instance<Gio::DBus::Message>( dynamic_cast<Gio::DBus::Message*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio::DBus
{


/* The *_Class implementation: */

auto Message_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Message_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_message_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Message_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Message_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Message((GDBusMessage*)object);
}


/* The implementation: */

auto Message::gobj_copy() -> GDBusMessage*
{
  reference();
  return gobj();
}

Message::Message(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Message::Message(GDBusMessage* castitem)
: Object((GObject*)castitem)
{}


Message::Message(Message&& src) noexcept
: Object(std::move(src))
{}

auto Message::operator=(Message&& src) noexcept -> Message&
{
  Object::operator=(std::move(src));
  return *this;
}


Message::~Message() noexcept = default;

Message::CppClassType Message::message_class_; // initialize static member

auto Message::get_type() -> GType
{
  return message_class_.init().get_type();
}


auto Message::get_base_type() -> GType
{
  return g_dbus_message_get_type();
}


Message::Message()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(message_class_.init()))
{


}

auto Message::create() -> Glib::RefPtr<Message>
{
  return Glib::make_refptr_for_instance<Message>( new Message() );
}

auto Message::create_signal(const Glib::ustring& path, const Glib::ustring& iface, const Glib::ustring& signal) -> Glib::RefPtr<Message>
{
  return Glib::wrap(g_dbus_message_new_signal(path.c_str(), iface.c_str(), signal.c_str()));
}

auto Message::create_method_call(const Glib::ustring& name, const Glib::ustring& path, const Glib::ustring& iface, const Glib::ustring& method) -> Glib::RefPtr<Message>
{
  return Glib::wrap(g_dbus_message_new_method_call(name.c_str(), path.c_str(), iface.c_str(), method.c_str()));
}

auto Message::create_method_reply(const Glib::RefPtr<Message>& method_call_message) -> Glib::RefPtr<Message>
{
  return Glib::wrap(g_dbus_message_new_method_reply(Glib::unwrap(method_call_message)));
}

auto Message::create_method_error_literal(const Glib::RefPtr<const Message>& method_call_message, const Glib::ustring& error_name, const Glib::ustring& error_message) -> Glib::RefPtr<Message>
{
  return Glib::wrap(g_dbus_message_new_method_error_literal(const_cast<GDBusMessage*>(Glib::unwrap(method_call_message)), error_name.c_str(), error_message.c_str()));
}

auto Message::create_from_blob(const guchar* blob, const gsize blob_len, CapabilityFlags capabilities) -> Glib::RefPtr<Message>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_dbus_message_new_from_blob(const_cast<guchar*>(blob), blob_len, static_cast<GDBusCapabilityFlags>(capabilities), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Message::print(
  const guint indent) -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_dbus_message_print(gobj(), indent));
}

auto Message::get_locked() const -> bool
{
  return g_dbus_message_get_locked(const_cast<GDBusMessage*>(gobj()));
}

auto Message::lock () -> void
{
  g_dbus_message_lock(gobj());
}

auto Message::copy() const -> Glib::RefPtr<Message>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_dbus_message_copy(const_cast<GDBusMessage*>(gobj()), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Message::get_message_type() const -> MessageType
{
  return static_cast<MessageType>(g_dbus_message_get_message_type(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_message_type (MessageType type) -> void
{
  g_dbus_message_set_message_type(gobj(), static_cast<GDBusMessageType>(type));
}

auto Message::get_byte_order() const -> ByteOrder
{
  return static_cast<ByteOrder>(g_dbus_message_get_byte_order(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_byte_order (ByteOrder byte_order) -> void
{
  g_dbus_message_set_byte_order(gobj(), static_cast<GDBusMessageByteOrder>(byte_order));
}

auto Message::get_serial() const -> guint32
{
  return g_dbus_message_get_serial(const_cast<GDBusMessage*>(gobj()));
}

auto Message::set_serial (
  const guint32 serial) -> void
{
  g_dbus_message_set_serial(gobj(), serial);
}

auto Message::get_flags() const -> MessageFlags
{
  return static_cast<MessageFlags>(g_dbus_message_get_flags(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_flags (MessageFlags flags) -> void
{
  g_dbus_message_set_flags(gobj(), static_cast<GDBusMessageFlags>(flags));
}

auto Message::set_body (const Glib::VariantBase &body) -> void
{
  g_dbus_message_set_body(gobj(), const_cast<GVariant*>(body.gobj()));
}

#ifdef G_OS_UNIX
auto Message::get_unix_fd_list() -> Glib::RefPtr<UnixFDList>
{
  auto retvalue = Glib::wrap(g_dbus_message_get_unix_fd_list(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
auto Message::get_unix_fd_list() const -> Glib::RefPtr<const UnixFDList>
{
  return const_cast<Message*>(this)->get_unix_fd_list();
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
void Message::set_unix_fd_list(const Glib::RefPtr<UnixFDList>& fd_list)
{
  g_dbus_message_set_unix_fd_list(gobj(), Glib::unwrap(fd_list));
}
#endif // G_OS_UNIX

auto Message::get_num_unix_fds() const -> guint32
{
  return g_dbus_message_get_num_unix_fds(const_cast<GDBusMessage*>(gobj()));
}

auto Message::set_num_unix_fds (
  const guint32 value) -> void
{
  g_dbus_message_set_num_unix_fds(gobj(), value);
}

auto Message::set_header (MessageHeaderField header_field, const Glib::VariantBase &value) -> void
{
  g_dbus_message_set_header(gobj(), static_cast<GDBusMessageHeaderField>(header_field), const_cast<GVariant*>(value.gobj()));
}

auto Message::get_header_fields() const -> std::vector<guchar>
{
  return Glib::ArrayHandler<guchar>::array_to_vector(g_dbus_message_get_header_fields(const_cast<GDBusMessage*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

auto Message::get_destination() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_message_get_destination(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_destination (const Glib::ustring &value) -> void
{
  g_dbus_message_set_destination(gobj(), value.c_str());
}

auto Message::get_error_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_message_get_error_name(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_error_name (const Glib::ustring &value) -> void
{
  g_dbus_message_set_error_name(gobj(), value.c_str());
}

auto Message::get_interface() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_message_get_interface(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_interface (const Glib::ustring &value) -> void
{
  g_dbus_message_set_interface(gobj(), value.c_str());
}

auto Message::get_member() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_message_get_member(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_member (const Glib::ustring &value) -> void
{
  g_dbus_message_set_member(gobj(), value.c_str());
}

auto Message::get_path() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_message_get_path(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_path (const Glib::ustring &value) -> void
{
  g_dbus_message_set_path(gobj(), value.c_str());
}

auto Message::get_reply_serial() const -> guint32
{
  return g_dbus_message_get_reply_serial(const_cast<GDBusMessage*>(gobj()));
}

auto Message::set_reply_serial (
  const guint32 value) -> void
{
  g_dbus_message_set_reply_serial(gobj(), value);
}

auto Message::get_sender() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_message_get_sender(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_sender (const Glib::ustring &value) -> void
{
  g_dbus_message_set_sender(gobj(), value.c_str());
}

auto Message::get_signature() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_message_get_signature(const_cast<GDBusMessage*>(gobj())));
}

auto Message::set_signature (const Glib::ustring &value) -> void
{
  g_dbus_message_set_signature(gobj(), value.c_str());
}

auto Message::get_arg0() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_message_get_arg0(const_cast<GDBusMessage*>(gobj())));
}

auto Message::bytes_needed(const guchar* blob, const gsize blob_len) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_dbus_message_bytes_needed(const_cast<guchar*>(blob), blob_len, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Message::to_blob(gsize& out_size, CapabilityFlags capabilities) -> guchar*
{
  GError* gerror = nullptr;
  const auto retvalue = g_dbus_message_to_blob(gobj(), &out_size, static_cast<GDBusCapabilityFlags>(capabilities), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Message::to_exception () -> void
{
  GError* gerror = nullptr;
  g_dbus_message_to_gerror(gobj(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}


auto Message::property_locked() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "locked"};
}


} // namespace Gio


