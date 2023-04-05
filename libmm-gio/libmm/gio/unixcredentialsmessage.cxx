// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/unixcredentialsmessage.hxx>
#include <libmm/gio/unixcredentialsmessage_p.hxx>

#include <gio/gunixcredentialsmessage.h>
#include <libmm/gio/credentials.hxx>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GUnixCredentialsMessage* object, const bool take_copy) -> RefPtr<gio::UnixCredentialsMessage>
  {
    return glib::make_refptr_for_instance<gio::UnixCredentialsMessage> (
        dynamic_cast<gio::UnixCredentialsMessage*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  UnixCredentialsMessage_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &UnixCredentialsMessage_Class::class_init_function;

      register_derived_type (g_unix_credentials_message_get_type ());
    }

    return *this;
  }

  auto
  UnixCredentialsMessage_Class::class_init_function (void* g_class,
                                                     void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  UnixCredentialsMessage_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new UnixCredentialsMessage ((GUnixCredentialsMessage*) object);
  }

  auto
  UnixCredentialsMessage::gobj_copy () -> GUnixCredentialsMessage*
  {
    reference ();
    return gobj ();
  }

  UnixCredentialsMessage::UnixCredentialsMessage (
      const glib::ConstructParams& construct_params)
    : SocketControlMessage (construct_params)
  {
  }

  UnixCredentialsMessage::UnixCredentialsMessage (
      GUnixCredentialsMessage* castitem)
    : SocketControlMessage ((GSocketControlMessage*) castitem)
  {
  }

  UnixCredentialsMessage::UnixCredentialsMessage (
      UnixCredentialsMessage&& src) noexcept
    : SocketControlMessage (std::move (src))
  {
  }

  auto
  UnixCredentialsMessage::operator= (UnixCredentialsMessage&& src) noexcept -> UnixCredentialsMessage&
  {
    SocketControlMessage::operator= (std::move (src));
    return *this;
  }

  UnixCredentialsMessage::~UnixCredentialsMessage () noexcept = default;

  UnixCredentialsMessage::CppClassType
      UnixCredentialsMessage::unixcredentialsmessage_class_;

  auto
  UnixCredentialsMessage::get_type () -> GType
  {
    return unixcredentialsmessage_class_.init ().get_type ();
  }

  auto
  UnixCredentialsMessage::get_base_type () -> GType
  {
    return g_unix_credentials_message_get_type ();
  }

  UnixCredentialsMessage::UnixCredentialsMessage ()
    : ObjectBase (nullptr),
      SocketControlMessage (
          glib::ConstructParams (unixcredentialsmessage_class_.init ()))
  {
  }

  UnixCredentialsMessage::UnixCredentialsMessage (
      const glib::RefPtr<Credentials>& credentials)
    : ObjectBase (nullptr),
      SocketControlMessage (
          glib::ConstructParams (unixcredentialsmessage_class_.init (),
                                 "credentials",
                                 glib::unwrap<Credentials> (credentials),
                                 nullptr))
  {
  }

  auto
  UnixCredentialsMessage::create () -> glib::RefPtr<UnixCredentialsMessage>
  {
    return glib::make_refptr_for_instance<UnixCredentialsMessage> (
        new UnixCredentialsMessage ());
  }

  auto
  UnixCredentialsMessage::create (const glib::RefPtr<Credentials>& credentials) -> glib::RefPtr<UnixCredentialsMessage>
  {
    return glib::make_refptr_for_instance<UnixCredentialsMessage> (
        new UnixCredentialsMessage (credentials));
  }

  auto
  UnixCredentialsMessage::get_credentials () -> glib::RefPtr<Credentials>
  {
    return glib::wrap (g_unix_credentials_message_get_credentials (gobj ()));
  }

  auto
  UnixCredentialsMessage::get_credentials () const -> glib::RefPtr<const Credentials>
  {
    return const_cast<UnixCredentialsMessage*> (this)->get_credentials ();
  }

  auto
  UnixCredentialsMessage::is_supported () -> bool
  {
    return g_unix_credentials_message_is_supported ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Credentials>>::value,
      "Type glib::RefPtr<Credentials> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  UnixCredentialsMessage::property_credentials () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Credentials>>
  {
    return {this, "credentials"};
  }

} // namespace gio
