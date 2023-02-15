// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_APPINFO_H
#define _GIOMM_APPINFO_H

#include <libmm-gio/mm-gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/applaunchcontext.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>

#include <exception>

#include <string>

#include <libmm-glib/interface.hxx>
#include <libmm-glib/object.hxx>

#include <libmm-gio/icon.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GAppInfoIface GAppInfoIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAppInfo = struct _GAppInfo;
using GAppInfoClass = struct _GAppInfoClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT AppInfo_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT File;

  class LIBMM_GIO_SYMEXPORT AppInfo : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AppInfo;
    using CppClassType = AppInfo_Class;
    using BaseObjectType = GAppInfo;
    using BaseClassType = GAppInfoIface;

    AppInfo (const AppInfo&) = delete;
    auto
    operator= (const AppInfo&) -> AppInfo& = delete;

  private:
    friend class AppInfo_Class;
    static CppClassType appinfo_class_;

#endif
  protected:
    AppInfo ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit AppInfo (const Glib::Interface_Class& interface_class);

  public:
    explicit AppInfo (GAppInfo* castitem);

  protected:
#endif

  public:
    AppInfo (AppInfo&& src) noexcept;
    auto
    operator= (AppInfo&& src) noexcept -> AppInfo&;

    ~AppInfo () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GAppInfo*
    {
      return reinterpret_cast<GAppInfo*> (gobject_);
    }

    auto
    gobj () const -> const GAppInfo*
    {
      return reinterpret_cast<GAppInfo*> (gobject_);
    }

  private:
  public:
    enum class CreateFlags
    {
      NONE = 0x0,
      NEEDS_TERMINAL = (1 << 0),
      SUPPORTS_URIS = (1 << 1),
      SUPPORTS_STARTUP_NOTIFICATION = (1 << 2)
    };

    static auto
    create_from_commandline (const std::string& commandline,
                             const std::string& application_name,
                             CreateFlags flags) -> Glib::RefPtr<AppInfo>;

    auto
    create_duplicate () const -> Glib::RefPtr<AppInfo>;

    auto
    equal (const Glib::RefPtr<AppInfo>& other) const -> bool;

    auto
    get_id () const -> std::string;

    auto
    get_name () const -> std::string;

    auto
    get_display_name () const -> std::string;

    auto
    get_description () const -> std::string;

    auto
    get_executable () const -> std::string;

    auto
    get_commandline () const -> std::string;

    auto
    get_icon () -> Glib::RefPtr<Icon>;

    auto
    get_icon () const -> const Glib::RefPtr<const Icon>;

    auto
    launch (const Glib::RefPtr<Gio::File>& file,
            const Glib::RefPtr<AppLaunchContext>& context) -> bool;

    auto
    launch (const Glib::RefPtr<Gio::File>& file) -> bool;

    auto
    launch (const std::vector<Glib::RefPtr<Gio::File>>& files,
            const Glib::RefPtr<AppLaunchContext>& context) -> bool;

    auto
    launch (const std::vector<Glib::RefPtr<Gio::File>>& files) -> bool;

    auto
    supports_uris () const -> bool;

    auto
    supports_files () const -> bool;

    auto
    launch_uris (const std::vector<std::string>& uris,
                 const Glib::RefPtr<AppLaunchContext>& context) -> bool;

    auto
    launch_uris (const std::vector<std::string>& uris) -> bool;

    auto
    launch_uri (const std::string& uri,
                const Glib::RefPtr<AppLaunchContext>& context) -> bool;

    auto
    launch_uri (const std::string& uris) -> bool;

    auto
    launch_uris_async (const std::vector<std::string>& uris,
                       const Glib::RefPtr<AppLaunchContext>& context,
                       const SlotAsyncReady& slot,
                       const Glib::RefPtr<Cancellable>& cancellable = {})
        -> void;

    auto
    launch_uris_async (const std::vector<std::string>& uris,
                       const Glib::RefPtr<AppLaunchContext>& context,
                       const Glib::RefPtr<Cancellable>& cancellable = {})
        -> void;

    auto
    launch_uris_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    should_show () const -> bool;

    auto
    can_delete () const -> bool;

    auto
    do_delete () -> bool;

    auto
    set_as_default_for_type (const std::string& content_type) -> bool;

    auto
    set_as_default_for_extension (const std::string& extension) -> bool;

    auto
    add_supports_type (const std::string& content_type) -> bool;

    auto
    can_remove_supports_type () const -> bool;

    auto
    remove_supports_type (const std::string& content_type) -> bool;

    auto
    get_supported_types () const -> std::vector<Glib::ustring>;

    auto
    set_as_last_used_for_type (const std::string& content_type) -> bool;

    static auto
    get_all () -> std::vector<Glib::RefPtr<AppInfo>>;

    static auto
    get_all_for_type (const std::string& content_type)
        -> std::vector<Glib::RefPtr<AppInfo>>;

    static auto
    get_default_for_type (const std::string& content_type,
                          bool must_support_uris = true)
        -> Glib::RefPtr<AppInfo>;

    static auto
    get_default_for_type_async (
        const std::string& content_type,
        bool must_support_uris,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable = {}) -> void;

    static auto
    get_default_for_type_async (
        const std::string& content_type,
        bool must_support_uris,
        const Glib::RefPtr<Cancellable>& cancellable = {}) -> void;

    static auto
    get_default_for_type_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<AppInfo>;

    static auto
    get_default_for_uri_scheme (const std::string& uri_scheme)
        -> Glib::RefPtr<AppInfo>;

    static auto
    get_default_for_uri_scheme_async (
        const std::string& content_type,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable = {}) -> void;

    static auto
    get_default_for_uri_scheme_async (
        const std::string& content_type,
        const Glib::RefPtr<Cancellable>& cancellable = {}) -> void;

    static auto
    get_default_for_uri_scheme_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<AppInfo>;

    static auto
    reset_type_associations (const std::string& content_type) -> void;

    static auto
    launch_default_for_uri (const std::string& uri,
                            const Glib::RefPtr<AppLaunchContext>& context)
        -> bool;

    static auto
    launch_default_for_uri (const std::string& uri) -> bool;

    static auto
    launch_default_for_uri_async (const std::string& uri,
                                  const Glib::RefPtr<AppLaunchContext>& context,
                                  const SlotAsyncReady& slot,
                                  const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    static auto
    launch_default_for_uri_async (const std::string& uri,
                                  const Glib::RefPtr<AppLaunchContext>& context,
                                  const SlotAsyncReady& slot) -> void;

    static auto
    launch_default_for_uri_async (const std::string& uri,
                                  const Glib::RefPtr<AppLaunchContext>& context,
                                  const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    static auto
    launch_default_for_uri_async (const std::string& uri,
                                  const Glib::RefPtr<AppLaunchContext>& context)
        -> void;

    static auto
    launch_default_for_uri_async (const std::string& uri,
                                  const SlotAsyncReady& slot,
                                  const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    static auto
    launch_default_for_uri_async (const std::string& uri,
                                  const SlotAsyncReady& slot) -> void;

    static auto
    launch_default_for_uri_async (const std::string& uri,
                                  const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    static auto
    launch_default_for_uri_async (const std::string& uri) -> void;

    static auto
    launch_default_for_uri_finish (const Glib::RefPtr<AsyncResult>& result)
        -> bool;

  protected:
  public:
  public:
  protected:
  };

} // namespace Gio

namespace Gio
{

  inline auto
  operator| (AppInfo::CreateFlags lhs, AppInfo::CreateFlags rhs) -> AppInfo::CreateFlags
  {
    return static_cast<AppInfo::CreateFlags> (static_cast<unsigned> (lhs) |
                                              static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (AppInfo::CreateFlags lhs, AppInfo::CreateFlags rhs) -> AppInfo::CreateFlags
  {
    return static_cast<AppInfo::CreateFlags> (static_cast<unsigned> (lhs) &
                                              static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (AppInfo::CreateFlags lhs, AppInfo::CreateFlags rhs) -> AppInfo::CreateFlags
  {
    return static_cast<AppInfo::CreateFlags> (static_cast<unsigned> (lhs) ^
                                              static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(AppInfo::CreateFlags flags) -> AppInfo::CreateFlags
  {
    return static_cast<AppInfo::CreateFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (AppInfo::CreateFlags& lhs, AppInfo::CreateFlags rhs) -> AppInfo::CreateFlags&
  {
    return (lhs = static_cast<AppInfo::CreateFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (AppInfo::CreateFlags& lhs, AppInfo::CreateFlags rhs) -> AppInfo::CreateFlags&
  {
    return (lhs = static_cast<AppInfo::CreateFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (AppInfo::CreateFlags& lhs, AppInfo::CreateFlags rhs) -> AppInfo::CreateFlags&
  {
    return (lhs = static_cast<AppInfo::CreateFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GAppInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::AppInfo>;

} // namespace Glib

#endif
