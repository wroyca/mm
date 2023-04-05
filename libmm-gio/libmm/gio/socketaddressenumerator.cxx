// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/socketaddressenumerator.hxx>
#include <libmm/gio/socketaddressenumerator_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/gio/socketaddress.hxx>
#include <libmm/glib/error.hxx>

namespace gio
{

  auto
  SocketAddressEnumerator::next_async (
      const glib::RefPtr<Cancellable>& cancellable,
      const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_address_enumerator_next_async (gobj (),
                                            glib::unwrap (cancellable),
                                            &SignalProxy_async_callback,
                                            slot_copy);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GSocketAddressEnumerator* object, const bool take_copy) -> RefPtr<gio::SocketAddressEnumerator>
  {
    return glib::make_refptr_for_instance<gio::SocketAddressEnumerator> (
        dynamic_cast<gio::SocketAddressEnumerator*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
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
  SocketAddressEnumerator_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
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
  SocketAddressEnumerator::next (const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_socket_address_enumerator_next (gobj (),
                                          glib::unwrap (cancellable),
                                          &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketAddressEnumerator::next () -> glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_socket_address_enumerator_next (gobj (), nullptr, &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketAddressEnumerator::next_finish (const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_socket_address_enumerator_next_finish (gobj (),
                                                 glib::unwrap (result),
                                                 &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

} // namespace gio
