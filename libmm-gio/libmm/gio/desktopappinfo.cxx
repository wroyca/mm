// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/desktopappinfo.hxx>
#include <libmm/gio/desktopappinfo_p.hxx>

#ifndef _WIN32

  #include <gio/gdesktopappinfo.h>
  #include <gio/gio.h>
  #include <libmm/glib/keyfile.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GDesktopAppInfo* object, bool take_copy) -> Glib::RefPtr<Gio::DesktopAppInfo>
  {
    return Glib::make_refptr_for_instance<Gio::DesktopAppInfo> (
        dynamic_cast<Gio::DesktopAppInfo*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  DesktopAppInfo_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DesktopAppInfo_Class::class_init_function;

      register_derived_type (g_desktop_app_info_get_type ());

      AppInfo::add_interface (get_type ());
    }

    return *this;
  }

  void
  DesktopAppInfo_Class::class_init_function (void* g_class, void* class_data)
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DesktopAppInfo_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new DesktopAppInfo ((GDesktopAppInfo*) object);
  }

  auto
  DesktopAppInfo::gobj_copy () -> GDesktopAppInfo*
  {
    reference ();
    return gobj ();
  }

  DesktopAppInfo::DesktopAppInfo (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  DesktopAppInfo::DesktopAppInfo (GDesktopAppInfo* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  DesktopAppInfo::DesktopAppInfo (DesktopAppInfo&& src) noexcept
    : Glib::Object (std::move (src)),
      AppInfo (std::move (src))
  {
  }

  auto
  DesktopAppInfo::operator= (DesktopAppInfo&& src) noexcept -> DesktopAppInfo&
  {
    Glib::Object::operator= (std::move (src));
    AppInfo::operator= (std::move (src));
    return *this;
  }

  DesktopAppInfo::~DesktopAppInfo () noexcept {}

  DesktopAppInfo::CppClassType DesktopAppInfo::desktopappinfo_class_;

  auto
  DesktopAppInfo::get_type () -> GType
  {
    return desktopappinfo_class_.init ().get_type ();
  }

  auto
  DesktopAppInfo::get_base_type () -> GType
  {
    return g_desktop_app_info_get_type ();
  }

  auto
  DesktopAppInfo::create (const std::string& desktop_id) -> Glib::RefPtr<DesktopAppInfo>
  {
    return Glib::wrap (g_desktop_app_info_new (desktop_id.c_str ()));
  }

  auto
  DesktopAppInfo::create_from_keyfile (
      const Glib::RefPtr<Glib::KeyFile>& key_file) -> Glib::RefPtr<DesktopAppInfo>
  {
    return Glib::wrap (
        g_desktop_app_info_new_from_keyfile (Glib::unwrap (key_file)));
  }

  auto
  DesktopAppInfo::create_from_filename (const std::string& filename) -> Glib::RefPtr<DesktopAppInfo>
  {
    return Glib::wrap (
        g_desktop_app_info_new_from_filename (filename.c_str ()));
  }

  auto
  DesktopAppInfo::get_filename () const -> std::string
  {
    return Glib::convert_const_gchar_ptr_to_stdstring (
        g_desktop_app_info_get_filename (
            const_cast<GDesktopAppInfo*> (gobj ())));
  }

  auto
  DesktopAppInfo::is_hidden () const -> bool
  {
    return g_desktop_app_info_get_is_hidden (
        const_cast<GDesktopAppInfo*> (gobj ()));
  }

  auto
  DesktopAppInfo::get_keywords () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        g_desktop_app_info_get_keywords (
            const_cast<GDesktopAppInfo*> (gobj ())),
        Glib::OWNERSHIP_NONE);
  }

  auto
  DesktopAppInfo::get_startup_wm_class () const -> std::string
  {
    return Glib::convert_const_gchar_ptr_to_stdstring (
        g_desktop_app_info_get_startup_wm_class (
            const_cast<GDesktopAppInfo*> (gobj ())));
  }

  auto
  DesktopAppInfo::get_nodisplay () const -> bool
  {
    return g_desktop_app_info_get_nodisplay (
        const_cast<GDesktopAppInfo*> (gobj ()));
  }

  auto
  DesktopAppInfo::get_show_in (const std::string& desktop_env) const -> bool
  {
    return g_desktop_app_info_get_show_in (
        const_cast<GDesktopAppInfo*> (gobj ()),
        desktop_env.c_str ());
  }

  auto
  DesktopAppInfo::get_generic_name () const -> std::string
  {
    return Glib::convert_const_gchar_ptr_to_stdstring (
        g_desktop_app_info_get_generic_name (
            const_cast<GDesktopAppInfo*> (gobj ())));
  }

  auto
  DesktopAppInfo::get_categories () const -> std::string
  {
    return Glib::convert_const_gchar_ptr_to_stdstring (
        g_desktop_app_info_get_categories (
            const_cast<GDesktopAppInfo*> (gobj ())));
  }

  auto
  DesktopAppInfo::has_key (const Glib::ustring& key) const -> bool
  {
    return g_desktop_app_info_has_key (const_cast<GDesktopAppInfo*> (gobj ()),
                                       key.c_str ());
  }

  auto
  DesktopAppInfo::get_string (const Glib::ustring& key) -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_desktop_app_info_get_string (gobj (), key.c_str ()));
  }

  auto
  DesktopAppInfo::get_locale_string (const Glib::ustring& key) -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_desktop_app_info_get_locale_string (gobj (), key.c_str ()));
  }

  auto
  DesktopAppInfo::get_boolean (const Glib::ustring& key) const -> bool
  {
    return g_desktop_app_info_get_boolean (
        const_cast<GDesktopAppInfo*> (gobj ()),
        key.c_str ());
  }

  auto
  DesktopAppInfo::list_actions () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        g_desktop_app_info_list_actions (
            const_cast<GDesktopAppInfo*> (gobj ())),
        Glib::OWNERSHIP_NONE);
  }

  void
  DesktopAppInfo::launch_action (
      const Glib::ustring& action_name,
      const Glib::RefPtr<AppLaunchContext>& launch_context)
  {
    g_desktop_app_info_launch_action (gobj (),
                                      action_name.c_str (),
                                      Glib::unwrap (launch_context));
  }

  void
  DesktopAppInfo::launch_action (const Glib::ustring& action_name)
  {
    g_desktop_app_info_launch_action (gobj (), action_name.c_str (), nullptr);
  }

  auto
  DesktopAppInfo::get_action_name (const Glib::ustring& action_name) const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_desktop_app_info_get_action_name (
            const_cast<GDesktopAppInfo*> (gobj ()),
            action_name.c_str ()));
  }

} // namespace Gio

#endif