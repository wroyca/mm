// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/appinfo.hxx>
#include <libmm/gio/appinfo_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/file.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/vectorutils.hxx>

namespace
{

  struct TypeTraits_AppInfo
  {
    using T = gio::AppInfo;
    using CppType = glib::RefPtr<T>;
    using CType = typename T::BaseObjectType*;
    using CTypeNonConst = typename T::BaseObjectType*;

    static auto
    to_c_type (const CppType& ptr) -> CType
    {
      return glib::unwrap (ptr);
    }

    static auto
    to_c_type (const CType ptr) -> CType
    {
      return ptr;
    }

    static auto
    to_cpp_type (const CType ptr) -> CppType
    {
      return glib::wrap (ptr, true);
    }

    static auto
    release_c_type (const CType ptr) -> void
    {
      GLIBMM_DEBUG_UNREFERENCE (nullptr, ptr);
      g_object_unref (ptr);
    }
  };
} // namespace

namespace gio
{

  auto
  AppInfo::create_from_commandline (const std::string& commandline,
                                    const std::string& application_name,
                                    CreateFlags flags) -> glib::RefPtr<AppInfo>
  {
    GAppInfo* capp_info = nullptr;
    GError* gerror = nullptr;

    capp_info = g_app_info_create_from_commandline (
        commandline.c_str (),
        application_name.c_str (),
        static_cast<GAppInfoCreateFlags> (flags),
        &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);

    return glib::wrap (capp_info);
  }

  auto
  AppInfo::create_duplicate () const -> glib::RefPtr<AppInfo>
  {
    return glib::wrap (g_app_info_dup (const_cast<GAppInfo*> (gobj ())));
  }

  auto
  AppInfo::launch (const glib::RefPtr<File>& file,
                   const glib::RefPtr<AppLaunchContext>& launch_context) -> bool
  {
    const std::vector<glib::RefPtr<File>> vec = {file};

    GError* gerror = nullptr;
    const bool retvalue = g_app_info_launch (
        gobj (),
        glib::ListHandler<glib::RefPtr<File>>::vector_to_list (vec).data (),
        glib::unwrap (launch_context),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  AppInfo::launch (const glib::RefPtr<File>& file) -> bool
  {
    const std::vector<glib::RefPtr<File>> vec = {file};

    GError* gerror = nullptr;
    const bool retvalue = g_app_info_launch (
        gobj (),
        glib::ListHandler<glib::RefPtr<File>>::vector_to_list (vec).data (),
        nullptr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  AppInfo::launch_uri (const std::string& uri,
                       const glib::RefPtr<AppLaunchContext>& launch_context) -> bool
  {
    const std::vector<std::string> vec = {uri};

    GError* gerror = nullptr;
    const bool retvalue = g_app_info_launch_uris (
        gobj (),
        glib::ListHandler<std::string>::vector_to_list (vec).data (),
        glib::unwrap (launch_context),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  AppInfo::launch_uri (const std::string& uri) -> bool
  {
    const std::vector<std::string> vec = {uri};

    GError* gerror = nullptr;
    const bool retvalue = g_app_info_launch_uris (
        gobj (),
        glib::ListHandler<std::string>::vector_to_list (vec).data (),
        nullptr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GAppInfo* object, const bool take_copy) -> RefPtr<gio::AppInfo>
  {
    return glib::make_refptr_for_instance<gio::AppInfo> (
        glib::wrap_auto_interface<gio::AppInfo> ((GObject*) object, take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  AppInfo_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AppInfo_Class::iface_init_function;

      gtype_ = g_app_info_get_type ();
    }

    return *this;
  }

  auto
  AppInfo_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  AppInfo_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new AppInfo ((GAppInfo*) object);
  }

  AppInfo::AppInfo ()
    : Interface (appinfo_class_.init ())
  {
  }

  AppInfo::AppInfo (GAppInfo* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  AppInfo::AppInfo (const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  AppInfo::AppInfo (AppInfo&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  AppInfo::operator= (AppInfo&& src) noexcept -> AppInfo&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  AppInfo::~AppInfo () noexcept = default;

  auto
  AppInfo::add_interface (const GType gtype_implementer) -> void
  {
    appinfo_class_.init ().add_interface (gtype_implementer);
  }

  AppInfo::CppClassType AppInfo::appinfo_class_;

  auto
  AppInfo::get_type () -> GType
  {
    return appinfo_class_.init ().get_type ();
  }

  auto
  AppInfo::get_base_type () -> GType
  {
    return g_app_info_get_type ();
  }

  auto
  AppInfo::equal (const glib::RefPtr<AppInfo>& other) const -> bool
  {
    return g_app_info_equal (const_cast<GAppInfo*> (gobj ()),
                             glib::unwrap (other));
  }

  auto
  AppInfo::get_id () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_app_info_get_id (const_cast<GAppInfo*> (gobj ())));
  }

  auto
  AppInfo::get_name () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_app_info_get_name (const_cast<GAppInfo*> (gobj ())));
  }

  auto
  AppInfo::get_display_name () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_app_info_get_display_name (const_cast<GAppInfo*> (gobj ())));
  }

  auto
  AppInfo::get_description () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_app_info_get_description (const_cast<GAppInfo*> (gobj ())));
  }

  auto
  AppInfo::get_executable () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_app_info_get_executable (const_cast<GAppInfo*> (gobj ())));
  }

  auto
  AppInfo::get_commandline () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_app_info_get_commandline (const_cast<GAppInfo*> (gobj ())));
  }

  auto
  AppInfo::get_icon () -> glib::RefPtr<Icon>
  {
    auto retvalue = glib::wrap (g_app_info_get_icon (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  AppInfo::get_icon () const -> const glib::RefPtr<const Icon>
  {
    return const_cast<AppInfo*> (this)->get_icon ();
  }

  auto
  AppInfo::launch (const std::vector<glib::RefPtr<File>>& files,
                   const glib::RefPtr<AppLaunchContext>& context) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_launch (
        gobj (),
        glib::ListHandler<glib::RefPtr<File>>::vector_to_list (files).data (),
        glib::unwrap (context),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::launch (const std::vector<glib::RefPtr<File>>& files) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_launch (
        gobj (),
        glib::ListHandler<glib::RefPtr<File>>::vector_to_list (files).data (),
        nullptr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::supports_uris () const -> bool
  {
    return g_app_info_supports_uris (const_cast<GAppInfo*> (gobj ()));
  }

  auto
  AppInfo::supports_files () const -> bool
  {
    return g_app_info_supports_files (const_cast<GAppInfo*> (gobj ()));
  }

  auto
  AppInfo::launch_uris (const std::vector<std::string>& uris,
                        const glib::RefPtr<AppLaunchContext>& context) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_launch_uris (
        gobj (),
        glib::ListHandler<std::string>::vector_to_list (uris).data (),
        glib::unwrap (context),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::launch_uris (const std::vector<std::string>& uris) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_launch_uris (
        gobj (),
        glib::ListHandler<std::string>::vector_to_list (uris).data (),
        nullptr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::launch_uris_async (const std::vector<std::string>& uris,
                              const glib::RefPtr<AppLaunchContext>& context,
                              const SlotAsyncReady& slot,
                              const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_app_info_launch_uris_async (
        gobj (),
        glib::ListHandler<std::string>::vector_to_list (uris).data (),
        glib::unwrap (context),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  AppInfo::launch_uris_async (const std::vector<std::string>& uris,
                              const glib::RefPtr<AppLaunchContext>& context,
                              const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    g_app_info_launch_uris_async (
        gobj (),
        glib::ListHandler<std::string>::vector_to_list (uris).data (),
        glib::unwrap (context),
        glib::unwrap (cancellable),
        nullptr,
        nullptr);
  }

  auto
  AppInfo::launch_uris_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_app_info_launch_uris_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::should_show () const -> bool
  {
    return g_app_info_should_show (const_cast<GAppInfo*> (gobj ()));
  }

  auto
  AppInfo::can_delete () const -> bool
  {
    return g_app_info_can_delete (const_cast<GAppInfo*> (gobj ()));
  }

  auto
  AppInfo::do_delete () -> bool
  {
    return g_app_info_delete (gobj ());
  }

  auto
  AppInfo::set_as_default_for_type (const std::string& content_type) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_set_as_default_for_type (
        gobj (),
        content_type.c_str (),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::set_as_default_for_extension (const std::string& extension) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_set_as_default_for_extension (
        gobj (),
        extension.c_str (),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::add_supports_type (const std::string& content_type) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_app_info_add_supports_type (gobj (), content_type.c_str (), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::can_remove_supports_type () const -> bool
  {
    return g_app_info_can_remove_supports_type (
        const_cast<GAppInfo*> (gobj ()));
  }

  auto
  AppInfo::remove_supports_type (const std::string& content_type) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_remove_supports_type (
        gobj (),
        content_type.c_str (),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::get_supported_types () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_app_info_get_supported_types (const_cast<GAppInfo*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  AppInfo::set_as_last_used_for_type (const std::string& content_type) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_set_as_last_used_for_type (
        gobj (),
        content_type.c_str (),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::get_all () -> std::vector<glib::RefPtr<AppInfo>>
  {
    return glib::ListHandler<glib::RefPtr<AppInfo>, TypeTraits_AppInfo>::
        list_to_vector (g_app_info_get_all (), glib::OWNERSHIP_DEEP);
  }

  auto
  AppInfo::get_all_for_type (const std::string& content_type) -> std::vector<glib::RefPtr<AppInfo>>
  {
    return glib::ListHandler<glib::RefPtr<AppInfo>, TypeTraits_AppInfo>::
        list_to_vector (g_app_info_get_all_for_type (content_type.c_str ()),
                        glib::OWNERSHIP_DEEP);
  }

  auto
  AppInfo::get_default_for_type (const std::string& content_type,
                                 const bool must_support_uris) -> glib::RefPtr<AppInfo>
  {
    return glib::wrap (g_app_info_get_default_for_type (content_type.c_str (),
                                                        must_support_uris));
  }

  auto
  AppInfo::get_default_for_type_async (
      const std::string& content_type,
      const bool must_support_uris,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_app_info_get_default_for_type_async (content_type.c_str (),
                                           must_support_uris,
                                           glib::unwrap (cancellable),
                                           &SignalProxy_async_callback,
                                           slot_copy);
  }

  auto
  AppInfo::get_default_for_type_async (
      const std::string& content_type,
      const bool must_support_uris,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    g_app_info_get_default_for_type_async (content_type.c_str (),
                                           must_support_uris,
                                           glib::unwrap (cancellable),
                                           nullptr,
                                           nullptr);
  }

  auto
  AppInfo::get_default_for_type_finish (const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<AppInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_app_info_get_default_for_type_finish (glib::unwrap (result),
                                                &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::get_default_for_uri_scheme (const std::string& uri_scheme) -> glib::RefPtr<AppInfo>
  {
    return glib::wrap (
        g_app_info_get_default_for_uri_scheme (uri_scheme.c_str ()));
  }

  auto
  AppInfo::get_default_for_uri_scheme_async (
      const std::string& content_type,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_app_info_get_default_for_uri_scheme_async (content_type.c_str (),
                                                 glib::unwrap (cancellable),
                                                 &SignalProxy_async_callback,
                                                 slot_copy);
  }

  auto
  AppInfo::get_default_for_uri_scheme_async (
      const std::string& content_type,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    g_app_info_get_default_for_uri_scheme_async (content_type.c_str (),
                                                 glib::unwrap (cancellable),
                                                 nullptr,
                                                 nullptr);
  }

  auto
  AppInfo::get_default_for_uri_scheme_finish (
      const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<AppInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_app_info_get_default_for_uri_scheme_finish (glib::unwrap (result),
                                                      &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::reset_type_associations (const std::string& content_type) -> void
  {
    g_app_info_reset_type_associations (content_type.c_str ());
  }

  auto
  AppInfo::launch_default_for_uri (
      const std::string& uri,
      const glib::RefPtr<AppLaunchContext>& context) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_launch_default_for_uri (
        uri.c_str (),
        glib::unwrap (context),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::launch_default_for_uri (const std::string& uri) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_app_info_launch_default_for_uri (uri.c_str (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AppInfo::launch_default_for_uri_async (
      const std::string& uri,
      const glib::RefPtr<AppLaunchContext>& context,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_app_info_launch_default_for_uri_async (uri.c_str (),
                                             glib::unwrap (context),
                                             glib::unwrap (cancellable),
                                             &SignalProxy_async_callback,
                                             slot_copy);
  }

  auto
  AppInfo::launch_default_for_uri_async (
      const std::string& uri,
      const glib::RefPtr<AppLaunchContext>& context,
      const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_app_info_launch_default_for_uri_async (uri.c_str (),
                                             glib::unwrap (context),
                                             nullptr,
                                             &SignalProxy_async_callback,
                                             slot_copy);
  }

  auto
  AppInfo::launch_default_for_uri_async (
      const std::string& uri,
      const glib::RefPtr<AppLaunchContext>& context,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    g_app_info_launch_default_for_uri_async (uri.c_str (),
                                             glib::unwrap (context),
                                             glib::unwrap (cancellable),
                                             nullptr,
                                             nullptr);
  }

  auto
  AppInfo::launch_default_for_uri_async (
      const std::string& uri,
      const glib::RefPtr<AppLaunchContext>& context) -> void
  {
    g_app_info_launch_default_for_uri_async (uri.c_str (),
                                             glib::unwrap (context),
                                             nullptr,
                                             nullptr,
                                             nullptr);
  }

  auto
  AppInfo::launch_default_for_uri_async (
      const std::string& uri,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_app_info_launch_default_for_uri_async (uri.c_str (),
                                             nullptr,
                                             glib::unwrap (cancellable),
                                             &SignalProxy_async_callback,
                                             slot_copy);
  }

  auto
  AppInfo::launch_default_for_uri_async (const std::string& uri,
                                         const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_app_info_launch_default_for_uri_async (uri.c_str (),
                                             nullptr,
                                             nullptr,
                                             &SignalProxy_async_callback,
                                             slot_copy);
  }

  auto
  AppInfo::launch_default_for_uri_async (
      const std::string& uri,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    g_app_info_launch_default_for_uri_async (uri.c_str (),
                                             nullptr,
                                             glib::unwrap (cancellable),
                                             nullptr,
                                             nullptr);
  }

  auto
  AppInfo::launch_default_for_uri_async (const std::string& uri) -> void
  {
    g_app_info_launch_default_for_uri_async (uri.c_str (),
                                             nullptr,
                                             nullptr,
                                             nullptr,
                                             nullptr);
  }

  auto
  AppInfo::launch_default_for_uri_finish (
      const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_app_info_launch_default_for_uri_finish (
        glib::unwrap (result),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

} // namespace gio
