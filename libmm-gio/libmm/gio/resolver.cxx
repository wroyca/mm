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
    using CppType = gio::SrvTarget;
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

namespace gio
{

  auto
  Resolver::get_default () -> glib::RefPtr<Resolver>
  {
    return glib::wrap (g_resolver_get_default ());
  }

  auto
  Resolver::set_default (const glib::RefPtr<Resolver>& resolver) -> void
  {
    g_resolver_set_default (glib::unwrap (resolver));
  }

  auto
  Resolver::lookup_by_name_async (const glib::ustring& hostname,
                                  const SlotAsyncReady& slot,
                                  const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_by_name_async (gobj (),
                                     hostname.c_str (),
                                     glib::unwrap (cancellable),
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  Resolver::lookup_by_name_async (const glib::ustring& hostname,
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
      const glib::RefPtr<InetAddress>& address,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_by_address_async (gobj (),
                                        glib::unwrap (address),
                                        glib::unwrap (cancellable),
                                        &SignalProxy_async_callback,
                                        slot_copy);
  }

  auto
  Resolver::lookup_by_address_async (const glib::RefPtr<InetAddress>& address,
                                     const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_by_address_async (gobj (),
                                        glib::unwrap (address),
                                        nullptr,
                                        &SignalProxy_async_callback,
                                        slot_copy);
  }

  auto
  Resolver::lookup_service_async (const glib::ustring& service,
                                  const glib::ustring& protocol,
                                  const glib::ustring& domain,
                                  const SlotAsyncReady& slot,
                                  const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_service_async (gobj (),
                                     service.c_str (),
                                     protocol.c_str (),
                                     domain.c_str (),
                                     glib::unwrap (cancellable),
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  Resolver::lookup_service_async (const glib::ustring& service,
                                  const glib::ustring& protocol,
                                  const glib::ustring& domain,
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
  Resolver::lookup_records_async (const glib::ustring& rrname,
                                  RecordType record_type,
                                  const SlotAsyncReady& slot,
                                  const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_records_async (
        gobj (),
        c_str_or_nullptr (rrname),
        static_cast<GResolverRecordType> (record_type),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Resolver::lookup_records_async (const glib::ustring& rrname,
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
  hostname_to_ascii (const glib::ustring& hostname) -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_hostname_to_ascii (hostname.c_str ()));
  }

  auto
  hostname_to_unicode (const glib::ustring& hostname) -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_hostname_to_unicode (hostname.c_str ()));
  }

  auto
  hostname_is_non_ascii (const glib::ustring& hostname) -> bool
  {
    return g_hostname_is_non_ascii (hostname.c_str ());
  }

  auto
  hostname_is_ascii_encoded (const glib::ustring& hostname) -> bool
  {
    return g_hostname_is_ascii_encoded (hostname.c_str ());
  }

  auto
  hostname_is_ip_address (const glib::ustring& hostname) -> bool
  {
    return g_hostname_is_ip_address (hostname.c_str ());
  }

} // namespace gio

namespace
{

  const glib::SignalProxyInfo Resolver_signal_reload_info = {
      "reload",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

auto
glib::Value<gio::Resolver::RecordType>::value_type () -> GType
{
  return g_resolver_record_type_get_type ();
}

auto
glib::Value<gio::Resolver::NameLookupFlags>::value_type () -> GType
{
  return g_resolver_name_lookup_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GResolver* object, const bool take_copy) -> RefPtr<gio::Resolver>
  {
    return glib::make_refptr_for_instance<gio::Resolver> (
        dynamic_cast<gio::Resolver*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->reload)
      (*base->reload) (self);
  }

  auto
  Resolver_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Resolver ((GResolver*) object);
  }

  auto
  Resolver::gobj_copy () -> GResolver*
  {
    reference ();
    return gobj ();
  }

  Resolver::Resolver (const glib::ConstructParams& construct_params)
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
  Resolver::lookup_by_name (const glib::ustring& hostname,
                            const glib::RefPtr<Cancellable>& cancellable) -> std::vector<glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name (gobj (),
                                       hostname.c_str (),
                                       glib::unwrap (cancellable),
                                       &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_name (const glib::ustring& hostname) -> std::vector<glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name (gobj (),
                                       hostname.c_str (),
                                       nullptr,
                                       &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_name_finish (const glib::RefPtr<AsyncResult>& result) -> std::vector<glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name_finish (gobj (),
                                              glib::unwrap (result),
                                              &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_name_with_flags (
      const glib::ustring& hostname,
      NameLookupFlags flags,
      const glib::RefPtr<Cancellable>& cancellable) -> std::vector<glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name_with_flags (
                gobj (),
                hostname.c_str (),
                static_cast<GResolverNameLookupFlags> (flags),
                glib::unwrap (cancellable),
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_name_with_flags_async (
      const glib::ustring& hostname,
      NameLookupFlags flags,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_resolver_lookup_by_name_with_flags_async (
        gobj (),
        hostname.c_str (),
        static_cast<GResolverNameLookupFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Resolver::lookup_by_name_with_flags_finish (
      const glib::RefPtr<AsyncResult>& result) -> std::vector<glib::RefPtr<InetAddress>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<InetAddress>>::list_to_vector (
            g_resolver_lookup_by_name_with_flags_finish (gobj (),
                                                         glib::unwrap (result),
                                                         &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_address (const glib::RefPtr<InetAddress>& address,
                               const glib::RefPtr<Cancellable>& cancellable) -> glib::ustring
  {
    GError* gerror = nullptr;
    auto retvalue = glib::convert_return_gchar_ptr_to_ustring (
        g_resolver_lookup_by_address (gobj (),
                                      glib::unwrap (address),
                                      glib::unwrap (cancellable),
                                      &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_address (const glib::RefPtr<InetAddress>& address) -> glib::ustring
  {
    GError* gerror = nullptr;
    auto retvalue = glib::convert_return_gchar_ptr_to_ustring (
        g_resolver_lookup_by_address (gobj (),
                                      glib::unwrap (address),
                                      nullptr,
                                      &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_by_address_finish (const glib::RefPtr<AsyncResult>& result) -> glib::ustring
  {
    GError* gerror = nullptr;
    auto retvalue = glib::convert_return_gchar_ptr_to_ustring (
        g_resolver_lookup_by_address_finish (gobj (),
                                             glib::unwrap (result),
                                             &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_service (const glib::ustring& service,
                            const glib::ustring& protocol,
                            const glib::ustring& domain,
                            const glib::RefPtr<Cancellable>& cancellable) -> std::vector<SrvTarget>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<SrvTarget, SrvTargetListTraits>::list_to_vector (
            g_resolver_lookup_service (gobj (),
                                       service.c_str (),
                                       protocol.c_str (),
                                       domain.c_str (),
                                       glib::unwrap (cancellable),
                                       &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_service (const glib::ustring& service,
                            const glib::ustring& protocol,
                            const glib::ustring& domain) -> std::vector<SrvTarget>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<SrvTarget, SrvTargetListTraits>::list_to_vector (
            g_resolver_lookup_service (gobj (),
                                       service.c_str (),
                                       protocol.c_str (),
                                       domain.c_str (),
                                       nullptr,
                                       &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_service_finish (const glib::RefPtr<AsyncResult>& result) -> std::vector<SrvTarget>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<SrvTarget, SrvTargetListTraits>::list_to_vector (
            g_resolver_lookup_service_finish (gobj (),
                                              glib::unwrap (result),
                                              &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_records (const glib::ustring& rrname,
                            RecordType record_type,
                            const glib::RefPtr<Cancellable>& cancellable) -> std::vector<glib::VariantContainerBase>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::VariantContainerBase>::list_to_vector (
            g_resolver_lookup_records (
                gobj (),
                rrname.c_str (),
                static_cast<GResolverRecordType> (record_type),
                glib::unwrap (cancellable),
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_records (const glib::ustring& rrname, RecordType record_type) -> std::vector<glib::VariantContainerBase>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::VariantContainerBase>::list_to_vector (
            g_resolver_lookup_records (
                gobj (),
                rrname.c_str (),
                static_cast<GResolverRecordType> (record_type),
                nullptr,
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::lookup_records_finish (const glib::RefPtr<AsyncResult>& result) -> std::vector<glib::VariantContainerBase>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::VariantContainerBase>::list_to_vector (
            g_resolver_lookup_records_finish (gobj (),
                                              glib::unwrap (result),
                                              &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Resolver::signal_reload () -> glib::SignalProxy<void ()>
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

} // namespace gio
