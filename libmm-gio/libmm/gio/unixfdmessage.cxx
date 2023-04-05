// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/unixfdmessage.hxx>
#include <libmm/gio/unixfdmessage_p.hxx>

#ifndef _WIN32

  #include <gio/gunixfdmessage.h>
  #include <libmm/gio/unixfdlist.hxx>
  #include <libmm/glib/error.hxx>

namespace gio
{

  auto
  UnixFDMessage::steal_fds () -> std::vector<int>
  {
    int length = 0;
    const auto fds = g_unix_fd_message_steal_fds (gobj (), &length);

    return glib::ArrayHandler<int>::array_to_vector (fds,
                                                     length,
                                                     glib::OWNERSHIP_DEEP);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GUnixFDMessage* object, bool take_copy) -> glib::RefPtr<gio::UnixFDMessage>
  {
    return glib::make_refptr_for_instance<gio::UnixFDMessage> (
        dynamic_cast<gio::UnixFDMessage*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  UnixFDMessage_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &UnixFDMessage_Class::class_init_function;

      register_derived_type (g_unix_fd_message_get_type ());
    }

    return *this;
  }

  void
  UnixFDMessage_Class::class_init_function (void* g_class, void* class_data)
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  UnixFDMessage_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new UnixFDMessage ((GUnixFDMessage*) object);
  }

  auto
  UnixFDMessage::gobj_copy () -> GUnixFDMessage*
  {
    reference ();
    return gobj ();
  }

  UnixFDMessage::UnixFDMessage (const glib::ConstructParams& construct_params)
    : gio::SocketControlMessage (construct_params)
  {
  }

  UnixFDMessage::UnixFDMessage (GUnixFDMessage* castitem)
    : gio::SocketControlMessage ((GSocketControlMessage*) (castitem))
  {
  }

  UnixFDMessage::UnixFDMessage (UnixFDMessage&& src) noexcept
    : gio::SocketControlMessage (std::move (src))
  {
  }

  auto
  UnixFDMessage::operator= (UnixFDMessage&& src) noexcept -> UnixFDMessage&
  {
    gio::SocketControlMessage::operator= (std::move (src));
    return *this;
  }

  UnixFDMessage::~UnixFDMessage () noexcept {}

  UnixFDMessage::CppClassType UnixFDMessage::unixfdmessage_class_;

  auto
  UnixFDMessage::get_type () -> GType
  {
    return unixfdmessage_class_.init ().get_type ();
  }

  auto
  UnixFDMessage::get_base_type () -> GType
  {
    return g_unix_fd_message_get_type ();
  }

  UnixFDMessage::UnixFDMessage ()
    : glib::ObjectBase (nullptr),
      gio::SocketControlMessage (
          glib::ConstructParams (unixfdmessage_class_.init ()))
  {
  }

  UnixFDMessage::UnixFDMessage (const glib::RefPtr<UnixFDList>& fd_list)
    : glib::ObjectBase (nullptr),
      gio::SocketControlMessage (
          glib::ConstructParams (unixfdmessage_class_.init (),
                                 "fd_list",
                                 glib::unwrap (fd_list),
                                 nullptr))
  {
  }

  auto
  UnixFDMessage::create () -> glib::RefPtr<UnixFDMessage>
  {
    return glib::make_refptr_for_instance<UnixFDMessage> (new UnixFDMessage ());
  }

  auto
  UnixFDMessage::create (const glib::RefPtr<UnixFDList>& fd_list) -> glib::RefPtr<UnixFDMessage>
  {
    return glib::make_refptr_for_instance<UnixFDMessage> (
        new UnixFDMessage (fd_list));
  }

  auto
  UnixFDMessage::get_fd_list () -> glib::RefPtr<UnixFDList>
  {
    auto retvalue = glib::wrap (g_unix_fd_message_get_fd_list (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  UnixFDMessage::get_fd_list () const -> glib::RefPtr<const UnixFDList>
  {
    return const_cast<UnixFDMessage*> (this)->get_fd_list ();
  }

  auto
  UnixFDMessage::append_fd (int fd) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = g_unix_fd_message_append_fd (gobj (), fd, &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<UnixFDList>>::value,
      "Type glib::RefPtr<UnixFDList> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  UnixFDMessage::property_fd_list () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<UnixFDList>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<UnixFDList>> (this,
                                                                   "fd-list");
  }

} // namespace gio

#endif
