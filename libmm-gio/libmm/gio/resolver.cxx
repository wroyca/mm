// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/resolver.hxx>
#include <libmm/gio/resolver_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>

namespace
{

  struct SrvTargetListTraits
  {
    using CppType = Gio::SrvTarget;
    using CType = const GSrvTarget*;
    using CTypeNonConst = GSrvTarget*;

    static auto
    to_c_type (const CppType& item) -> CType
    {
      return item.gobj ();
    }

    static auto
    to_c_type (const CType ptr) -> CType
    {
      return ptr;
    }

    static auto
    to_cpp_type (const CType item) -> CppType
    {
      return CppType (const_cast<CTypeNonConst> (item), true);
    }

    static auto
    release_c_type (const CType item) -> void
    {
      g_srv_target_free (const_cast<CTypeNonConst> (item));
    }
  };

} // namespace

namespace Gio
{

  auto
  Resolver::get_default () -> Glib::RefPtr<Resolver>
  {
    return Glib::wrap (g_resolver_get_default ());
  }

  auto
  Resolver::set_default (const Glib::RefPtr<Resolver>& resolver) -> void
  {
    g_resolver_set_default (Glib::unwrap (resolver));
  }

  auto
  Resolver::lookup_by_name_async (const Glib::ustring& hostname,
                                  const SlotAsyncReady& slot,
                                  const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_by_name_async (gobj (),
                                     hostname.c_str (),
                                     Glib::unwrap (cancellable),
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  Resolver::lookup_by_name_async (const Glib::ustring& hostname,
                                  const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_by_name_async (gobj (),
                                     hostname.c_str (),
                                     nullptr,
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  Resolver::lookup_by_address_async (
      const Glib::RefPtr<InetAddress>& address,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_by_address_async (gobj (),
                                        Glib::unwrap (address),
                                        Glib::unwrap (cancellable),
                                        &SignalProxy_async_callback,
                                        slot_copy);
  }

  auto
  Resolver::lookup_by_address_async (const Glib::RefPtr<InetAddress>& address,
                                     const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_by_address_async (gobj (),
                                        Glib::unwrap (address),
                                        nullptr,
                                        &SignalProxy_async_callback,
                                        slot_copy);
  }

  auto
  Resolver::lookup_service_async (const Glib::ustring& service,
                                  const Glib::ustring& protocol,
                                  const Glib::ustring& domain,
                                  const SlotAsyncReady& slot,
                                  const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_service_async (gobj (),
                                     service.c_str (),
                                     protocol.c_str (),
                                     domain.c_str (),
                                     Glib::unwrap (cancellable),
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  Resolver::lookup_service_async (const Glib::ustring& service,
                                  const Glib::ustring& protocol,
                                  const Glib::ustring& domain,
                                  const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_service_async (gobj (),
                                     service.c_str (),
                                     protocol.c_str (),
                                     domain.c_str (),
                                     nullptr,
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  Resolver::lookup_records_async (const Glib::ustring& rrname,
                                  RecordType record_type,
                                  const SlotAsyncReady& slot,
                                  const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_records_async (
        gobj (),
        c_str_or_nullptr (rrname),
        static_cast<GResolverRecordType> (record_type),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Resolver::lookup_records_async (const Glib::ustring& rrname,
                                  RecordType record_type,
                                  const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_records_async (
        gobj (),
        c_str_or_nullptr (rrname),
        static_cast<GResolverRecordType> (record_type),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  hostname_to_ascii (const Glib::ustring& hostname) -> std::string
  {
    return Glib::convert_return_gchar_ptr_to_stdstring (
        g_hostname_to_ascii (hostname.c_str ()));
  }

  auto
  hostname_to_unicode (const Glib::ustring& hostname) -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_hostname_to_unicode (hostname.c_str ()));
  }

  auto
  hostname_is_non_ascii (const Glib::ustring& hostname) -> bool
  {
    return g_hostname_is_non_ascii (hostname.c_str ());
  }

  auto
  hostname_is_ascii_encoded (const Glib::ustring& hostname) -> bool
  {
    return g_hostname_is_ascii_encoded (hostname.c_str ());
  }

  auto
  hostname_is_ip_address (const Glib::ustring& hostname) -> bool
  {
    return g_hostname_is_ip_address (hostname.c_str ());
  }

} // namespace Gio

namespace
{

  const Glib::SignalProxyInfo Resolver_signal_reload_info = {
      "reload",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

auto
Glib::Value<Gio::Resolver::RecordType>::value_type () -> GType
{
  return g_resolver_record_type_get_type ();
}

auto
Glib::Value<Gio::Resolver::NameLookupFlags>::value_type () -> GType
{
  return g_resolver_name_lookup_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GResolver* object, const bool take_copy) -> RefPtr<Gio::Resolver>
  {
    return Glib::make_refptr_for_instance<Gio::Resolver> (
        dynamic_cast<Gio::Resolver*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  Resolver_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Resolver_Class::class_init_function;

      register_derived_type (g_resolver_get_type ());
    }

    return *this;
  }

  auto
  Resolver_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->reload = &reload_callback;
  }

  auto
  Resolver_Class::reload_callback (GResolver* self) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_reload ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->reload)
      (*base->reload) (self);
  }

  auto
  Resolver_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Resolver ((GResolver*) object);
  }

  auto
  Resolver::gobj_copy () -> GResolver*
  {
    reference ();
    return gobj ();
  }

  Resolver::Resolver (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Resolver::Resolver (GResolver* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Resolver::Resolver (Resolver&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Resolver::operator= (Resolver&& src) noexcept -> Resolver&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Resolver::~Resolver () noexcept = default;

  Resolver::CppClassType Resolver::resolver_class_;

  auto
  Resolver::get_type () -> GType
  {
    return resolver_class_.init ().get_type ();
  }

  auto
  Resolver::get_base_type () -> GType
  {
    return g_resolver_get_type ();
  }

  auto
  Resolver::lookup_by_name (const Glib::ustring& hostname,
                            const Glib::RefPtr<Cancellable>& cancellable) -> std::vector<Glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name (gobj (),
                                       hostname.c_str (),
                                       Glib::unwrap (cancellable),
                                       &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_name (const Glib::ustring& hostname) -> std::vector<Glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name (gobj (),
                                       hostname.c_str (),
                                       nullptr,
                                       &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_name_finish (const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name_finish (gobj (),
                                              Glib::unwrap (result),
                                              &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_name_with_flags (
      const Glib::ustring& hostname,
      NameLookupFlags flags,
      const Glib::RefPtr<Cancellable>& cancellable) -> std::vector<Glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name_with_flags (
                gobj (),
                hostname.c_str (),
                static_cast<GResolverNameLookupFlags> (flags),
                Glib::unwrap (cancellable),
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_name_with_flags_async (
      const Glib::ustring& hostname,
      NameLookupFlags flags,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_by_name_with_flags_async (
        gobj (),
        hostname.c_str (),
        static_cast<GResolverNameLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Resolver::lookup_by_name_with_flags_finish (
      const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name_with_flags_finish (gobj (),
                                                         Glib::unwrap (result),
                                                         &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_address (const Glib::RefPtr<InetAddress>& address,
                               const Glib::RefPtr<Cancellable>& cancellable) -> Glib::ustring
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::convert_return_gchar_ptr_to_ustring (
        g_resolver_lookup_by_address (gobj (),
                                      Glib::unwrap (address),
                                      Glib::unwrap (cancellable),
                                      &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_address (const Glib::RefPtr<InetAddress>& address) -> Glib::ustring
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::convert_return_gchar_ptr_to_ustring (
        g_resolver_lookup_by_address (gobj (),
                                      Glib::unwrap (address),
                                      nullptr,
                                      &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_address_finish (const Glib::RefPtr<AsyncResult>& result) -> Glib::ustring
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::convert_return_gchar_ptr_to_ustring (
        g_resolver_lookup_by_address_finish (gobj (),
                                             Glib::unwrap (result),
                                             &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_service (const Glib::ustring& service,
                            const Glib::ustring& protocol,
                            const Glib::ustring& domain,
                            const Glib::RefPtr<Cancellable>& cancellable) -> std::vector<SrvTarget>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<SrvTarget, SrvTargetListTraits>::list_to_vector (
            g_resolver_lookup_service (gobj (),
                                       service.c_str (),
                                       protocol.c_str (),
                                       domain.c_str (),
                                       Glib::unwrap (cancellable),
                                       &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_service (const Glib::ustring& service,
                            const Glib::ustring& protocol,
                            const Glib::ustring& domain) -> std::vector<SrvTarget>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<SrvTarget, SrvTargetListTraits>::list_to_vector (
            g_resolver_lookup_service (gobj (),
                                       service.c_str (),
                                       protocol.c_str (),
                                       domain.c_str (),
                                       nullptr,
                                       &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_service_finish (const Glib::RefPtr<AsyncResult>& result) -> std::vector<SrvTarget>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<SrvTarget, SrvTargetListTraits>::list_to_vector (
            g_resolver_lookup_service_finish (gobj (),
                                              Glib::unwrap (result),
                                              &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_records (const Glib::ustring& rrname,
                            RecordType record_type,
                            const Glib::RefPtr<Cancellable>& cancellable) -> std::vector<Glib::VariantContainerBase>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::VariantContainerBase>::list_to_vector (
            g_resolver_lookup_records (
                gobj (),
                rrname.c_str (),
                static_cast<GResolverRecordType> (record_type),
                Glib::unwrap (cancellable),
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_records (const Glib::ustring& rrname, RecordType record_type) -> std::vector<Glib::VariantContainerBase>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::VariantContainerBase>::list_to_vector (
            g_resolver_lookup_records (
                gobj (),
                rrname.c_str (),
                static_cast<GResolverRecordType> (record_type),
                nullptr,
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_records_finish (const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::VariantContainerBase>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::VariantContainerBase>::list_to_vector (
            g_resolver_lookup_records_finish (gobj (),
                                              Glib::unwrap (result),
                                              &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::signal_reload () -> Glib::SignalProxy<void ()>
  {
    return {this, &Resolver_signal_reload_info};
  }

  auto
  Resolver::on_reload () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->reload)
      (*base->reload) (gobj ());
  }

} // namespace Gio
