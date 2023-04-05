// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/socketconnectable.hxx>
#include <libmm/gio/socketconnectable_p.hxx>

#include <gio/gio.h>

namespace gio
{
}

namespace
{
}

namespace glib
{

  auto
  wrap (GSocketConnectable* object, const bool take_copy) -> RefPtr<gio::SocketConnectable>
  {
    return glib::make_refptr_for_instance<gio::SocketConnectable> (
        glib::wrap_auto_interface<gio::SocketConnectable> ((GObject*) object,
                                                           take_copy));
  }

} // namespace glib

namespace gio
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
  SocketConnectable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::Interface_Class& interface_class)
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
  SocketConnectable::enumerate () -> glib::RefPtr<SocketAddressEnumerator>
  {
    return glib::wrap (g_socket_connectable_enumerate (gobj ()));
  }

  auto
  SocketConnectable::enumerate () const -> glib::RefPtr<const SocketAddressEnumerator>
  {
    return const_cast<SocketConnectable*> (this)->enumerate ();
  }

  auto
  SocketConnectable::proxy_enumerate () -> glib::RefPtr<SocketAddressEnumerator>
  {
    return glib::wrap (g_socket_connectable_proxy_enumerate (gobj ()));
  }

  auto
  SocketConnectable::proxy_enumerate () const -> glib::RefPtr<const SocketAddressEnumerator>
  {
    return const_cast<SocketConnectable*> (this)->proxy_enumerate ();
  }

  auto
  SocketConnectable::to_string () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_socket_connectable_to_string (
            const_cast<GSocketConnectable*> (gobj ())));
  }

} // namespace gio
