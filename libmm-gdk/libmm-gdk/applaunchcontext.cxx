// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/applaunchcontext.hxx>
#include <libmm-gdk/applaunchcontext_p.hxx>

#include <gdk/gdk.h>
#include <libmm-gdk/display.hxx>

namespace Gdk
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkAppLaunchContext* object, bool take_copy) -> Glib::RefPtr<Gdk::AppLaunchContext>
  {
    return Glib::make_refptr_for_instance<Gdk::AppLaunchContext> (
        dynamic_cast<Gdk::AppLaunchContext*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  AppLaunchContext_Class::init () -> const Glib::Class&
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
  AppLaunchContext_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
    : Gio::AppLaunchContext (construct_params)
  {
  }

  AppLaunchContext::AppLaunchContext (GdkAppLaunchContext* castitem)
    : Gio::AppLaunchContext ((GAppLaunchContext*) (castitem))
  {
  }

  AppLaunchContext::AppLaunchContext (AppLaunchContext&& src) noexcept
    : Gio::AppLaunchContext (std::move (src))
  {
  }

  auto
  AppLaunchContext::operator= (AppLaunchContext&& src) noexcept -> AppLaunchContext&
  {
    Gio::AppLaunchContext::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gio::AppLaunchContext (
          Glib::ConstructParams (applaunchcontext_class_.init ()))
  {
  }

  auto
  AppLaunchContext::create () -> Glib::RefPtr<AppLaunchContext>
  {
    return Glib::make_refptr_for_instance<AppLaunchContext> (
        new AppLaunchContext ());
  }

  auto
  AppLaunchContext::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_app_launch_context_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  AppLaunchContext::get_display () const -> Glib::RefPtr<const Display>
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
  AppLaunchContext::set_icon (const Glib::RefPtr<Gio::Icon>& icon) -> void
  {
    gdk_app_launch_context_set_icon (
        gobj (),
        const_cast<GIcon*> (Glib::unwrap<Gio::Icon> (icon)));
  }

  auto
  AppLaunchContext::set_icon_name (const Glib::ustring& icon_name) -> void
  {
    gdk_app_launch_context_set_icon_name (gobj (), icon_name.c_str ());
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AppLaunchContext::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>> (this,
                                                                "display");
  }

} // namespace Gdk
