// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DESKTOPAPPINFO_H
#define _GIOMM_DESKTOPAPPINFO_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/appinfo.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDesktopAppInfo = struct _GDesktopAppInfo;
using GDesktopAppInfoClass = struct _GDesktopAppInfoClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT DesktopAppInfo_Class;
}
#endif

namespace Glib
{

  class LIBMM_GLIB_SYMEXPORT KeyFile;

}

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT DesktopAppInfo : public Glib::Object,
                                   public AppInfo
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DesktopAppInfo;
    using CppClassType = DesktopAppInfo_Class;
    using BaseObjectType = GDesktopAppInfo;
    using BaseClassType = GDesktopAppInfoClass;

    DesktopAppInfo (const DesktopAppInfo&) = delete;
    auto
    operator= (const DesktopAppInfo&) -> DesktopAppInfo& = delete;

  private:
    friend class DesktopAppInfo_Class;
    static CppClassType desktopappinfo_class_;

  protected:
    explicit DesktopAppInfo (const Glib::ConstructParams& construct_params);
    explicit DesktopAppInfo (GDesktopAppInfo* castitem);

#endif

  public:
    DesktopAppInfo (DesktopAppInfo&& src) noexcept;
    auto
    operator= (DesktopAppInfo&& src) noexcept -> DesktopAppInfo&;

    ~DesktopAppInfo () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDesktopAppInfo*
    {
      return reinterpret_cast<GDesktopAppInfo*> (gobject_);
    }

    auto
    gobj () const -> const GDesktopAppInfo*
    {
      return reinterpret_cast<GDesktopAppInfo*> (gobject_);
    }

    auto
    gobj_copy () -> GDesktopAppInfo*;

  private:
  public:
    static auto
    create (const std::string& desktop_id) -> Glib::RefPtr<DesktopAppInfo>;

    static auto
    create_from_keyfile (const Glib::RefPtr<Glib::KeyFile>& key_file)
        -> Glib::RefPtr<DesktopAppInfo>;

    static auto
    create_from_filename (const std::string& filename)
        -> Glib::RefPtr<DesktopAppInfo>;

    auto
    get_filename () const -> std::string;

    auto
    is_hidden () const -> bool;

    auto
    get_keywords () const -> std::vector<Glib::ustring>;

    auto
    get_startup_wm_class () const -> std::string;

    auto
    get_nodisplay () const -> bool;

    auto
    get_show_in (const std::string& desktop_env) const -> bool;

    auto
    get_generic_name () const -> std::string;

    auto
    get_categories () const -> std::string;

    auto
    has_key (const Glib::ustring& key) const -> bool;

    auto
    get_string (const Glib::ustring& key) -> Glib::ustring;

    auto
    get_locale_string (const Glib::ustring& key) -> Glib::ustring;

    auto
    get_boolean (const Glib::ustring& key) const -> bool;

    auto
    list_actions () const -> std::vector<Glib::ustring>;

    auto
    launch_action (const Glib::ustring& action_name,
                   const Glib::RefPtr<AppLaunchContext>& launch_context)
        -> void;

    auto
    launch_action (const Glib::ustring& action_name) -> void;

    auto
    get_action_name (const Glib::ustring& action_name) const -> Glib::ustring;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDesktopAppInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DesktopAppInfo>;
} // namespace Glib

#endif
