

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/unixcredentialsmessage.hxx>
#include <libmm-gio/unixcredentialsmessage_p.hxx>

#include <gio/gunixcredentialsmessage.h>
#include <libmm-gio/credentials.hxx>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GUnixCredentialsMessage* object, const bool take_copy) -> RefPtr<Gio::UnixCredentialsMessage>
  {
    return Glib::make_refptr_for_instance<Gio::UnixCredentialsMessage> (
        dynamic_cast<Gio::UnixCredentialsMessage*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
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
  UnixCredentialsMessage_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
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
          Glib::ConstructParams (unixcredentialsmessage_class_.init ()))
  {
  }

  UnixCredentialsMessage::UnixCredentialsMessage (
      const Glib::RefPtr<Credentials>& credentials)
    : ObjectBase (nullptr),
      SocketControlMessage (
          Glib::ConstructParams (unixcredentialsmessage_class_.init (),
                                 "credentials",
                                 Glib::unwrap<Credentials> (credentials),
                                 nullptr))
  {
  }

  auto
  UnixCredentialsMessage::create () -> Glib::RefPtr<UnixCredentialsMessage>
  {
    return Glib::make_refptr_for_instance<UnixCredentialsMessage> (
        new UnixCredentialsMessage ());
  }

  auto
  UnixCredentialsMessage::create (const Glib::RefPtr<Credentials>& credentials) -> Glib::RefPtr<UnixCredentialsMessage>
  {
    return Glib::make_refptr_for_instance<UnixCredentialsMessage> (
        new UnixCredentialsMessage (credentials));
  }

  auto
  UnixCredentialsMessage::get_credentials () -> Glib::RefPtr<Credentials>
  {
    return Glib::wrap (g_unix_credentials_message_get_credentials (gobj ()));
  }

  auto
  UnixCredentialsMessage::get_credentials () const -> Glib::RefPtr<const Credentials>
  {
    return const_cast<UnixCredentialsMessage*> (this)->get_credentials ();
  }

  auto
  UnixCredentialsMessage::is_supported () -> bool
  {
    return g_unix_credentials_message_is_supported ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Credentials>>::value,
      "Type Glib::RefPtr<Credentials> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  UnixCredentialsMessage::property_credentials () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Credentials>>
  {
    return {this, "credentials"};
  }

} // namespace Gio
