
#ifndef _GDKMM_APPLAUNCHCONTEXT_H
#define _GDKMM_APPLAUNCHCONTEXT_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/appinfo.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkAppLaunchContext = struct _GdkAppLaunchContext;
using GdkAppLaunchContextClass = struct _GdkAppLaunchContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API AppLaunchContext_Class;
}
#endif

namespace Gdk
{
  class GDKMM_API Display;

  class GDKMM_API AppLaunchContext : public Gio::AppLaunchContext
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
    explicit AppLaunchContext (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<AppLaunchContext>;

    auto
    get_display () -> Glib::RefPtr<Display>;

    auto
    get_display () const -> Glib::RefPtr<const Display>;

    void
    set_desktop (int desktop);

    void
    set_timestamp (guint32 timestamp);

    void
    set_icon (const Glib::RefPtr<Gio::Icon>& icon);

    void
    set_icon_name (const Glib::ustring& icon_name);

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkAppLaunchContext* object, bool take_copy = false) -> Glib::RefPtr<Gdk::AppLaunchContext>;
} // namespace Glib

#endif
