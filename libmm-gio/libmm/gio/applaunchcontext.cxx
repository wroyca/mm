// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/applaunchcontext.hxx>
#include <libmm/gio/applaunchcontext_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/appinfo.hxx>
#include <libmm/gio/file.hxx>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GAppLaunchContext* object, const bool take_copy) -> RefPtr<gio::AppLaunchContext>
  {
    return glib::make_refptr_for_instance<gio::AppLaunchContext> (
        dynamic_cast<gio::AppLaunchContext*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  AppLaunchContext_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AppLaunchContext_Class::class_init_function;

      register_derived_type (g_app_launch_context_get_type ());
    }

    return *this;
  }

  auto
  AppLaunchContext_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AppLaunchContext_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new AppLaunchContext ((GAppLaunchContext*) object);
  }

  auto
  AppLaunchContext::gobj_copy () -> GAppLaunchContext*
  {
    reference ();
    return gobj ();
  }

  AppLaunchContext::AppLaunchContext (
      const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  AppLaunchContext::AppLaunchContext (GAppLaunchContext* castitem)
    : Object ((GObject*) castitem)
  {
  }

  AppLaunchContext::AppLaunchContext (AppLaunchContext&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  AppLaunchContext::operator= (AppLaunchContext&& src) noexcept -> AppLaunchContext&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  AppLaunchContext::~AppLaunchContext () noexcept = default;

  AppLaunchContext::CppClassType AppLaunchContext::applaunchcontext_class_;

  auto
  AppLaunchContext::get_type () -> GType
  {
    return applaunchcontext_class_.init ().get_type ();
  }

  auto
  AppLaunchContext::get_base_type () -> GType
  {
    return g_app_launch_context_get_type ();
  }

  AppLaunchContext::AppLaunchContext ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (applaunchcontext_class_.init ()))
  {
  }

  auto
  AppLaunchContext::create () -> glib::RefPtr<AppLaunchContext>
  {
    return glib::make_refptr_for_instance<AppLaunchContext> (
        new AppLaunchContext ());
  }

  auto
  AppLaunchContext::setenv (const glib::ustring& variable,
                            const glib::ustring& value) -> void
  {
    g_app_launch_context_setenv (gobj (), variable.c_str (), value.c_str ());
  }

  auto
  AppLaunchContext::unsetenv (const glib::ustring& variable) -> void
  {
    g_app_launch_context_unsetenv (gobj (), variable.c_str ());
  }

  auto
  AppLaunchContext::get_environment () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_app_launch_context_get_environment (
            const_cast<GAppLaunchContext*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  AppLaunchContext::get_display (const glib::RefPtr<AppInfo>& info,
                                 const std::vector<glib::RefPtr<File>>& files) -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_app_launch_context_get_display (
            gobj (),
            glib::unwrap (info),
            glib::ListHandler<glib::RefPtr<File>>::vector_to_list (files)
                .data ()));
  }

  auto
  AppLaunchContext::get_startup_notify_id (
      const glib::RefPtr<AppInfo>& info,
      const std::vector<glib::RefPtr<File>>& files) -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_app_launch_context_get_startup_notify_id (
            gobj (),
            glib::unwrap (info),
            glib::ListHandler<glib::RefPtr<File>>::vector_to_list (files)
                .data ()));
  }

  auto
  AppLaunchContext::launch_failed (const std::string& startup_notify_id) -> void
  {
    g_app_launch_context_launch_failed (gobj (), startup_notify_id.c_str ());
  }

} // namespace gio
