// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_APPLAUNCHCONTEXT_H
#define _GDKMM_APPLAUNCHCONTEXT_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/appinfo.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkAppLaunchContext = struct _GdkAppLaunchContext;
using GdkAppLaunchContextClass = struct _GdkAppLaunchContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT AppLaunchContext_Class;
}
#endif

namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Display;

  class LIBMM_GDK_SYMEXPORT AppLaunchContext : public gio::AppLaunchContext
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AppLaunchContext;
    using CppClassType = AppLaunchContext_Class;
    using BaseObjectType = GdkAppLaunchContext;
    using BaseClassType = GdkAppLaunchContextClass;

    AppLaunchContext (const AppLaunchContext&) = delete;
    auto
    operator= (const AppLaunchContext&) -> AppLaunchContext& = delete;

  private:
    friend class AppLaunchContext_Class;
    static CppClassType applaunchcontext_class_;

  protected:
    explicit AppLaunchContext (const glib::ConstructParams& construct_params);
    explicit AppLaunchContext (GdkAppLaunchContext* castitem);

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
    gobj () -> GdkAppLaunchContext*
    {
      return reinterpret_cast<GdkAppLaunchContext*> (gobject_);
    }

    auto
    gobj () const -> const GdkAppLaunchContext*
    {
      return reinterpret_cast<GdkAppLaunchContext*> (gobject_);
    }

    auto
    gobj_copy () -> GdkAppLaunchContext*;

  private:
  protected:
    AppLaunchContext ();

  public:
    static auto
    create () -> glib::RefPtr<AppLaunchContext>;

    auto
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    set_desktop (int desktop) -> void;

    auto
    set_timestamp (guint32 timestamp) -> void;

    auto
    set_icon (const glib::RefPtr<gio::Icon>& icon) -> void;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkAppLaunchContext* object, bool take_copy = false) -> glib::RefPtr<gdk::AppLaunchContext>;
} // namespace glib

#endif
