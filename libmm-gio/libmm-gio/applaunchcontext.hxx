// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_APPLAUNCHCONTEXT_H
#define _GIOMM_APPLAUNCHCONTEXT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <exception>

#include <string>

#include <libmm-glib/interface.hxx>
#include <libmm-glib/object.hxx>

#include <libmm-gio/icon.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAppLaunchContext = struct _GAppLaunchContext;
using GAppLaunchContextClass = struct _GAppLaunchContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT AppLaunchContext_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT AppInfo;
  class LIBMM_GIO_SYMEXPORT File;

  class LIBMM_GIO_SYMEXPORT AppLaunchContext : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AppLaunchContext;
    using CppClassType = AppLaunchContext_Class;
    using BaseObjectType = GAppLaunchContext;
    using BaseClassType = GAppLaunchContextClass;

    AppLaunchContext (const AppLaunchContext&) = delete;
    auto
    operator= (const AppLaunchContext&) -> AppLaunchContext& = delete;

  private:
    friend class AppLaunchContext_Class;
    static CppClassType applaunchcontext_class_;

  protected:
    explicit AppLaunchContext (const Glib::ConstructParams& construct_params);
    explicit AppLaunchContext (GAppLaunchContext* castitem);

#endif

  public:
    AppLaunchContext (AppLaunchContext&& src) noexcept;
    auto
    operator= (AppLaunchContext&& src) noexcept -> AppLaunchContext&;

    ~AppLaunchContext () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GAppLaunchContext*
    {
      return reinterpret_cast<GAppLaunchContext*> (gobject_);
    }

    auto
    gobj () const -> const GAppLaunchContext*
    {
      return reinterpret_cast<GAppLaunchContext*> (gobject_);
    }

    auto
    gobj_copy () -> GAppLaunchContext*;

  private:
  protected:
    AppLaunchContext ();

  public:
    static auto
    create () -> Glib::RefPtr<AppLaunchContext>;

    auto
    setenv (const Glib::ustring& variable, const Glib::ustring& value) -> void;

    auto
    unsetenv (const Glib::ustring& variable) -> void;

    auto
    get_environment () const -> std::vector<Glib::ustring>;

    auto
    get_display (const Glib::RefPtr<AppInfo>& info,
                 const std::vector<Glib::RefPtr<Gio::File>>& files)
        -> std::string;

    auto
    get_startup_notify_id (const Glib::RefPtr<AppInfo>& info,
                           const std::vector<Glib::RefPtr<Gio::File>>& files)
        -> std::string;

    auto
    launch_failed (const std::string& startup_notify_id) -> void;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GAppLaunchContext* object, bool take_copy = false) -> Glib::RefPtr<Gio::AppLaunchContext>;
} // namespace Glib

#endif
