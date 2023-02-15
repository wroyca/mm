// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/socketconnectable.hxx>
#include <libmm-gio/socketconnectable_p.hxx>

#include <gio/gio.h>

namespace Gio
{
}

namespace
{
}

namespace Glib
{

  auto
  wrap (GSocketConnectable* object, const bool take_copy) -> RefPtr<Gio::SocketConnectable>
  {
    return Glib::make_refptr_for_instance<Gio::SocketConnectable> (
        Glib::wrap_auto_interface<Gio::SocketConnectable> ((GObject*) object,
                                                           take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  SocketConnectable_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SocketConnectable_Class::iface_init_function;

      gtype_ = g_socket_connectable_get_type ();
    }

    return *this;
  }

  auto
  SocketConnectable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  SocketConnectable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SocketConnectable ((GSocketConnectable*) object);
  }

  SocketConnectable::SocketConnectable ()
    : Interface (socketconnectable_class_.init ())
  {
  }

  SocketConnectable::SocketConnectable (GSocketConnectable* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  SocketConnectable::SocketConnectable (
      const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  SocketConnectable::SocketConnectable (SocketConnectable&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  SocketConnectable::operator= (SocketConnectable&& src) noexcept -> SocketConnectable&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  SocketConnectable::~SocketConnectable () noexcept = default;

  auto
  SocketConnectable::add_interface (const GType gtype_implementer) -> void
  {
    socketconnectable_class_.init ().add_interface (gtype_implementer);
  }

  SocketConnectable::CppClassType SocketConnectable::socketconnectable_class_;

  auto
  SocketConnectable::get_type () -> GType
  {
    return socketconnectable_class_.init ().get_type ();
  }

  auto
  SocketConnectable::get_base_type () -> GType
  {
    return g_socket_connectable_get_type ();
  }

  auto
  SocketConnectable::enumerate () -> Glib::RefPtr<SocketAddressEnumerator>
  {
    return Glib::wrap (g_socket_connectable_enumerate (gobj ()));
  }

  auto
  SocketConnectable::enumerate () const -> Glib::RefPtr<const SocketAddressEnumerator>
  {
    return const_cast<SocketConnectable*> (this)->enumerate ();
  }

  auto
  SocketConnectable::proxy_enumerate () -> Glib::RefPtr<SocketAddressEnumerator>
  {
    return Glib::wrap (g_socket_connectable_proxy_enumerate (gobj ()));
  }

  auto
  SocketConnectable::proxy_enumerate () const -> Glib::RefPtr<const SocketAddressEnumerator>
  {
    return const_cast<SocketConnectable*> (this)->proxy_enumerate ();
  }

  auto
  SocketConnectable::to_string () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_socket_connectable_to_string (
            const_cast<GSocketConnectable*> (gobj ())));
  }

} // namespace Gio
