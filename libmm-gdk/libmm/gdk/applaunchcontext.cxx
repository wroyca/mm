// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/applaunchcontext.hxx>
#include <libmm/gdk/applaunchcontext_p.hxx>

#include <gdk/gdk.h>
#include <libmm/gdk/display.hxx>

namespace gdk
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GdkAppLaunchContext* object, bool take_copy) -> glib::RefPtr<gdk::AppLaunchContext>
  {
    return glib::make_refptr_for_instance<gdk::AppLaunchContext> (
        dynamic_cast<gdk::AppLaunchContext*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  AppLaunchContext_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AppLaunchContext_Class::class_init_function;

      register_derived_type (gdk_app_launch_context_get_type ());
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
    return new AppLaunchContext ((GdkAppLaunchContext*) object);
  }

  auto
  AppLaunchContext::gobj_copy () -> GdkAppLaunchContext*
  {
    reference ();
    return gobj ();
  }

  AppLaunchContext::AppLaunchContext (
      const glib::ConstructParams& construct_params)
    : gio::AppLaunchContext (construct_params)
  {
  }

  AppLaunchContext::AppLaunchContext (GdkAppLaunchContext* castitem)
    : gio::AppLaunchContext ((GAppLaunchContext*) (castitem))
  {
  }

  AppLaunchContext::AppLaunchContext (AppLaunchContext&& src) noexcept
    : gio::AppLaunchContext (std::move (src))
  {
  }

  auto
  AppLaunchContext::operator= (AppLaunchContext&& src) noexcept -> AppLaunchContext&
  {
    gio::AppLaunchContext::operator= (std::move (src));
    return *this;
  }

  AppLaunchContext::~AppLaunchContext () noexcept {}

  AppLaunchContext::CppClassType AppLaunchContext::applaunchcontext_class_;

  auto
  AppLaunchContext::get_type () -> GType
  {
    return applaunchcontext_class_.init ().get_type ();
  }

  auto
  AppLaunchContext::get_base_type () -> GType
  {
    return gdk_app_launch_context_get_type ();
  }

  AppLaunchContext::AppLaunchContext ()
    : glib::ObjectBase (nullptr),
      gio::AppLaunchContext (
          glib::ConstructParams (applaunchcontext_class_.init ()))
  {
  }

  auto
  AppLaunchContext::create () -> glib::RefPtr<AppLaunchContext>
  {
    return glib::make_refptr_for_instance<AppLaunchContext> (
        new AppLaunchContext ());
  }

  auto
  AppLaunchContext::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_app_launch_context_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  AppLaunchContext::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<AppLaunchContext*> (this)->get_display ();
  }

  auto
  AppLaunchContext::set_desktop (int desktop) -> void
  {
    gdk_app_launch_context_set_desktop (gobj (), desktop);
  }

  auto
  AppLaunchContext::set_timestamp (guint32 timestamp) -> void
  {
    gdk_app_launch_context_set_timestamp (gobj (), timestamp);
  }

  auto
  AppLaunchContext::set_icon (const glib::RefPtr<gio::Icon>& icon) -> void
  {
    gdk_app_launch_context_set_icon (
        gobj (),
        const_cast<GIcon*> (glib::unwrap<gio::Icon> (icon)));
  }

  auto
  AppLaunchContext::set_icon_name (const glib::ustring& icon_name) -> void
  {
    gdk_app_launch_context_set_icon_name (gobj (), icon_name.c_str ());
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AppLaunchContext::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (this,
                                                                "display");
  }

} // namespace gdk
