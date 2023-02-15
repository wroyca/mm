// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/socketaddressenumerator.hxx>
#include <libmm-gio/socketaddressenumerator_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/slot_async.hxx>
#include <libmm-gio/socketaddress.hxx>
#include <libmm-glib/error.hxx>

namespace Gio
{

  auto
  SocketAddressEnumerator::next_async (
      const Glib::RefPtr<Cancellable>& cancellable,
      const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_address_enumerator_next_async (gobj (),
                                            Glib::unwrap (cancellable),
                                            &SignalProxy_async_callback,
                                            slot_copy);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GSocketAddressEnumerator* object, const bool take_copy) -> RefPtr<Gio::SocketAddressEnumerator>
  {
    return Glib::make_refptr_for_instance<Gio::SocketAddressEnumerator> (
        dynamic_cast<Gio::SocketAddressEnumerator*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  SocketAddressEnumerator_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SocketAddressEnumerator_Class::class_init_function;

      register_derived_type (g_socket_address_enumerator_get_type ());
    }

    return *this;
  }

  auto
  SocketAddressEnumerator_Class::class_init_function (void* g_class,
                                                      void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SocketAddressEnumerator_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SocketAddressEnumerator ((GSocketAddressEnumerator*) object);
  }

  auto
  SocketAddressEnumerator::gobj_copy () -> GSocketAddressEnumerator*
  {
    reference ();
    return gobj ();
  }

  SocketAddressEnumerator::SocketAddressEnumerator (
      const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  SocketAddressEnumerator::SocketAddressEnumerator (
      GSocketAddressEnumerator* castitem)
    : Object ((GObject*) castitem)
  {
  }

  SocketAddressEnumerator::SocketAddressEnumerator (
      SocketAddressEnumerator&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  SocketAddressEnumerator::operator= (SocketAddressEnumerator&& src) noexcept -> SocketAddressEnumerator&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  SocketAddressEnumerator::~SocketAddressEnumerator () noexcept = default;

  SocketAddressEnumerator::CppClassType
      SocketAddressEnumerator::socketaddressenumerator_class_;

  auto
  SocketAddressEnumerator::get_type () -> GType
  {
    return socketaddressenumerator_class_.init ().get_type ();
  }

  auto
  SocketAddressEnumerator::get_base_type () -> GType
  {
    return g_socket_address_enumerator_get_type ();
  }

  auto
  SocketAddressEnumerator::next (const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_socket_address_enumerator_next (gobj (),
                                          Glib::unwrap (cancellable),
                                          &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketAddressEnumerator::next () -> Glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_socket_address_enumerator_next (gobj (), nullptr, &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketAddressEnumerator::next_finish (const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_socket_address_enumerator_next_finish (gobj (),
                                                 Glib::unwrap (result),
                                                 &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

} // namespace Gio
