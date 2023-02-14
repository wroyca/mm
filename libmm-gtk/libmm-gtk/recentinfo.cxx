

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/recentinfo.hxx>
#include <libmm-gtk/recentinfo_p.hxx>

#include <libmm-glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  RecentInfo::get_applications () const -> std::vector<Glib::ustring>
  {
    gsize length = 0;
    char** const applications = gtk_recent_info_get_applications (
        const_cast<GtkRecentInfo*> (gobj ()),
        &length);

    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        applications,
        length,
        Glib::OWNERSHIP_DEEP);
  }

  auto
  RecentInfo::get_application_info (const Glib::ustring& app_name,
                                    std::string& app_exec,
                                    guint& count,
                                    Glib::DateTime& stamp) const -> bool
  {
    const char* app_exec_cstr = nullptr;
    GDateTime* date_time = nullptr;
    const int found = gtk_recent_info_get_application_info (
        const_cast<GtkRecentInfo*> (gobj ()),
        app_name.c_str (),
        &app_exec_cstr,
        &count,
        &date_time);
    stamp = Glib::wrap (date_time);

    if (app_exec_cstr)
      app_exec = app_exec_cstr;
    else
      app_exec.erase ();

    return found != 0;
  }

  auto
  RecentInfo::get_groups () const -> std::vector<Glib::ustring>
  {
    gsize length = 0;
    char** const groups = gtk_recent_info_get_groups (
        const_cast<GtkRecentInfo*> (gobj ()),
        &length);

    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        groups,
        length,
        Glib::OWNERSHIP_DEEP);
  }

  auto
  RecentInfoTraits::to_cpp_type (const CType& obj) -> CppType
  {
    return Glib::wrap (const_cast<CTypeNonConst> (obj), true);
  }

} // namespace Gtk

namespace Glib
{

  auto
  Value<RefPtr<Gtk::RecentInfo>>::value_type () -> GType
  {
    return gtk_recent_info_get_type ();
  }

  auto
  Value<RefPtr<Gtk::RecentInfo>>::set (const CppType& data) -> void
  {
    set_boxed (unwrap (data));
  }

  auto
  Value<RefPtr<Gtk::RecentInfo>>::get () const -> CppType
  {
    return wrap (static_cast<CType> (get_boxed ()), true);
  }

} // namespace Glib

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkRecentInfo* object, const bool take_copy) -> RefPtr<Gtk::RecentInfo>
  {
    if (take_copy && object)
      gtk_recent_info_ref (object);

    return Glib::make_refptr_for_instance<Gtk::RecentInfo> (
        reinterpret_cast<Gtk::RecentInfo*> (object));
  }

} // namespace Glib

namespace Gtk
{

  auto
  RecentInfo::reference () const -> void
  {
    gtk_recent_info_ref (
        reinterpret_cast<GtkRecentInfo*> (const_cast<RecentInfo*> (this)));
  }

  auto
  RecentInfo::unreference () const -> void
  {
    gtk_recent_info_unref (
        reinterpret_cast<GtkRecentInfo*> (const_cast<RecentInfo*> (this)));
  }

  auto
  RecentInfo::gobj () -> GtkRecentInfo*
  {
    return reinterpret_cast<GtkRecentInfo*> (this);
  }

  auto
  RecentInfo::gobj () const -> const GtkRecentInfo*
  {
    return reinterpret_cast<const GtkRecentInfo*> (this);
  }

  auto
  RecentInfo::gobj_copy () const -> GtkRecentInfo*
  {
    const auto gobject =
        reinterpret_cast<GtkRecentInfo*> (const_cast<RecentInfo*> (this));
    gtk_recent_info_ref (gobject);
    return gobject;
  }

  auto
  RecentInfo::get_uri () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_recent_info_get_uri (const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::get_display_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_recent_info_get_display_name (
            const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::get_description () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_recent_info_get_description (const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::get_mime_type () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_recent_info_get_mime_type (const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::get_added () const -> Glib::DateTime
  {
    return Glib::wrap (
        gtk_recent_info_get_added (const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::get_modified () const -> Glib::DateTime
  {
    return Glib::wrap (
        gtk_recent_info_get_modified (const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::get_visited () const -> Glib::DateTime
  {
    return Glib::wrap (
        gtk_recent_info_get_visited (const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::get_private_hint () const -> bool
  {
    return gtk_recent_info_get_private_hint (
        const_cast<GtkRecentInfo*> (gobj ()));
  }

  auto
  RecentInfo::create_app_info (const Glib::ustring& app_name) -> Glib::RefPtr<Gio::AppInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gtk_recent_info_create_app_info (gobj (), app_name.c_str (), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentInfo::last_application () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_recent_info_last_application (
            const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::has_application (const Glib::ustring& app_name) const -> bool
  {
    return gtk_recent_info_has_application (
        const_cast<GtkRecentInfo*> (gobj ()),
        app_name.c_str ());
  }

  auto
  RecentInfo::has_group (const Glib::ustring& group_name) const -> bool
  {
    return gtk_recent_info_has_group (const_cast<GtkRecentInfo*> (gobj ()),
                                      group_name.c_str ());
  }

  auto
  RecentInfo::get_gicon () -> Glib::RefPtr<Gio::Icon>
  {
    auto retvalue = Glib::wrap (gtk_recent_info_get_gicon (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  RecentInfo::get_gicon () const -> Glib::RefPtr<const Gio::Icon>
  {
    return const_cast<RecentInfo*> (this)->get_gicon ();
  }

  auto
  RecentInfo::get_short_name () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_recent_info_get_short_name (const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::get_uri_display () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_recent_info_get_uri_display (const_cast<GtkRecentInfo*> (gobj ())));
  }

  auto
  RecentInfo::get_age () const -> int
  {
    return gtk_recent_info_get_age (const_cast<GtkRecentInfo*> (gobj ()));
  }

  auto
  RecentInfo::is_local () const -> bool
  {
    return gtk_recent_info_is_local (const_cast<GtkRecentInfo*> (gobj ()));
  }

  auto
  RecentInfo::exists () const -> bool
  {
    return gtk_recent_info_exists (const_cast<GtkRecentInfo*> (gobj ()));
  }

  auto
  RecentInfo::equal (const Glib::RefPtr<const RecentInfo>& info_b) const -> bool
  {
    return gtk_recent_info_match (
        const_cast<GtkRecentInfo*> (gobj ()),
        const_cast<GtkRecentInfo*> (Glib::unwrap<RecentInfo> (info_b)));
  }

} // namespace Gtk
