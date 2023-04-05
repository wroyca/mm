// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_RECENTINFO_H
#define _GTKMM_RECENTINFO_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gio/appinfo.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/glib/datetime.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkRecentInfo GtkRecentInfo;
  auto
  gtk_recent_info_unref (GtkRecentInfo* info) -> void;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT RecentInfo final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = RecentInfo;
    using BaseObjectType = GtkRecentInfo;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GtkRecentInfo*;

    auto
    gobj () const -> const GtkRecentInfo*;

    auto
    gobj_copy () const -> GtkRecentInfo*;

    RecentInfo () = delete;

    RecentInfo (const RecentInfo&) = delete;
    auto
    operator= (const RecentInfo&) -> RecentInfo& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    auto
    get_uri () const -> glib::ustring;

    auto
    get_display_name () const -> glib::ustring;

    auto
    get_description () const -> glib::ustring;

    auto
    get_mime_type () const -> glib::ustring;

    auto
    get_added () const -> glib::DateTime;

    auto
    get_modified () const -> glib::DateTime;

    auto
    get_visited () const -> glib::DateTime;

    auto
    get_private_hint () const -> bool;

    auto
    create_app_info (const glib::ustring& app_name)
        -> glib::RefPtr<gio::AppInfo>;

    auto
    get_application_info (const glib::ustring& app_name,
                          std::string& app_exec,
                          guint& count,
                          glib::DateTime& stamp) const -> bool;

    auto
    get_applications () const -> std::vector<glib::ustring>;

    auto
    last_application () const -> glib::ustring;

    auto
    has_application (const glib::ustring& app_name) const -> bool;

    auto
    get_groups () const -> std::vector<glib::ustring>;

    auto
    has_group (const glib::ustring& group_name) const -> bool;

    auto
    get_gicon () -> glib::RefPtr<gio::Icon>;

    auto
    get_gicon () const -> glib::RefPtr<const gio::Icon>;

    auto
    get_short_name () const -> glib::ustring;

    auto
    get_uri_display () const -> glib::ustring;

    auto
    get_age () const -> int;

    auto
    is_local () const -> bool;

    auto
    exists () const -> bool;

    auto
    equal (const glib::RefPtr<const RecentInfo>& info_b) const -> bool;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  struct RecentInfoTraits
  {
    typedef glib::RefPtr<RecentInfo> CppType;
    typedef const GtkRecentInfo* CType;
    typedef GtkRecentInfo* CTypeNonConst;

    static inline auto
    to_c_type (const CppType& obj) -> CType
    {
      return glib::unwrap (obj);
    }

    static inline auto
    to_c_type (const CType& obj) -> CType
    {
      return obj;
    }

    static auto
    to_cpp_type (const CType& obj) -> CppType;

    static inline auto
    release_c_type (const CType& obj) -> void
    {
      gtk_recent_info_unref (const_cast<CTypeNonConst> (obj));
    }
  };
#endif

  inline auto
  operator== (const glib::RefPtr<const RecentInfo>& lhs,
              const glib::RefPtr<const RecentInfo>& rhs) -> bool
  {
    return lhs->equal (rhs);
  }

  inline auto
  operator!= (const glib::RefPtr<const RecentInfo>& lhs,
              const glib::RefPtr<const RecentInfo>& rhs) -> bool
  {
    return !lhs->equal (rhs);
  }

} // namespace gtk

namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<glib::RefPtr<gtk::RecentInfo>> : public ValueBase_Boxed
  {
  public:
    typedef glib::RefPtr<gtk::RecentInfo> CppType;
    typedef GtkRecentInfo* CType;

    static auto
    value_type () -> GType;

    auto
    set (const CppType& data) -> void;
    auto
    get () const -> CppType;
  };

} // namespace glib

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkRecentInfo* object, bool take_copy = false) -> glib::RefPtr<gtk::RecentInfo>;

} // namespace glib

#endif
