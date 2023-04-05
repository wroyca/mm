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
namespace gio
{
  class LIBMM_GIO_SYMEXPORT DesktopAppInfo_Class;
}
#endif

namespace glib
{

  class LIBMM_GLIB_SYMEXPORT KeyFile;

}

namespace gio
{

  class LIBMM_GIO_SYMEXPORT DesktopAppInfo : public glib::Object,
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
    explicit DesktopAppInfo (const glib::ConstructParams& construct_params);
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
    create (const std::string& desktop_id) -> glib::RefPtr<DesktopAppInfo>;

    static auto
    create_from_keyfile (const glib::RefPtr<glib::KeyFile>& key_file)
        -> glib::RefPtr<DesktopAppInfo>;

    static auto
    create_from_filename (const std::string& filename)
        -> glib::RefPtr<DesktopAppInfo>;

    auto
    get_filename () const -> std::string;

    auto
    is_hidden () const -> bool;

    auto
    get_keywords () const -> std::vector<glib::ustring>;

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
    has_key (const glib::ustring& key) const -> bool;

    auto
    get_string (const glib::ustring& key) -> glib::ustring;

    auto
    get_locale_string (const glib::ustring& key) -> glib::ustring;

    auto
    get_boolean (const glib::ustring& key) const -> bool;

    auto
    list_actions () const -> std::vector<glib::ustring>;

    auto
    launch_action (const glib::ustring& action_name,
                   const glib::RefPtr<AppLaunchContext>& launch_context)
        -> void;

    auto
    launch_action (const glib::ustring& action_name) -> void;

    auto
    get_action_name (const glib::ustring& action_name) const -> glib::ustring;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDesktopAppInfo* object, bool take_copy = false) -> glib::RefPtr<gio::DesktopAppInfo>;
} // namespace glib

#endif
