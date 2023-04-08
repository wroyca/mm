// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/stylemanager.hxx>
#include <libmm/adw/stylemanager_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

auto
glib::Value<adw::ColorScheme>::value_type () -> GType
{
  return adw_color_scheme_get_type ();
}

namespace glib
{

  auto
  wrap (AdwStyleManager* object, bool take_copy) -> glib::RefPtr<adw::style_manager>
  {
    return glib::make_refptr_for_instance<adw::style_manager> (
        dynamic_cast<adw::style_manager*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  style_manager_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_style_manager_get_type ();
    }

    return *this;
  }

  auto
  style_manager_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new style_manager ((AdwStyleManager*) object);
  }

  auto
  style_manager::gobj_copy () -> AdwStyleManager*
  {
    reference ();
    return gobj ();
  }

  style_manager::style_manager (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  style_manager::style_manager (AdwStyleManager* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  style_manager::style_manager (style_manager&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  style_manager::operator= (style_manager&& src) noexcept -> style_manager&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  style_manager::~style_manager () noexcept {}

  style_manager::CppClassType style_manager::stylemanager_class_;

  auto
  style_manager::get_type () -> GType
  {
    return stylemanager_class_.init ().get_type ();
  }

  auto
  style_manager::get_base_type () -> GType
  {
    return adw_style_manager_get_type ();
  }

  style_manager::style_manager ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (stylemanager_class_.init ()))
  {
  }

  auto
  style_manager::create () -> glib::RefPtr<style_manager>
  {
    return glib::make_refptr_for_instance<style_manager> (new style_manager ());
  }

  auto
  style_manager::get_default () -> glib::RefPtr<style_manager>
  {
    auto retvalue = glib::wrap (adw_style_manager_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  style_manager::get_for_display (const glib::RefPtr<gdk::Display>& display) -> glib::RefPtr<style_manager>
  {
    auto retvalue =
        glib::wrap (adw_style_manager_get_for_display (glib::unwrap (display)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  style_manager::get_color_scheme () const -> ColorScheme
  {
    return static_cast<ColorScheme> (adw_style_manager_get_color_scheme (
        const_cast<AdwStyleManager*> (gobj ())));
  }

  auto
  style_manager::get_system_supports_color_schemes () const -> bool
  {
    return adw_style_manager_get_system_supports_color_schemes (
        const_cast<AdwStyleManager*> (gobj ()));
  }

  auto
  style_manager::get_dark () const -> bool
  {
    return adw_style_manager_get_dark (const_cast<AdwStyleManager*> (gobj ()));
  }

  auto
  style_manager::get_high_contrast () const -> bool
  {
    return adw_style_manager_get_high_contrast (
        const_cast<AdwStyleManager*> (gobj ()));
  }

  auto
  style_manager::get_display () const -> glib::RefPtr<gdk::Display>
  {
    auto retvalue = glib::wrap (
        adw_style_manager_get_display (const_cast<AdwStyleManager*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  style_manager::set_color_scheme (ColorScheme color_scheme) -> void
  {
    adw_style_manager_set_color_scheme (
        gobj (),
        static_cast<AdwColorScheme> (color_scheme));
  }

  auto
  style_manager::property_high_contrast () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "high-contrast"};
  }

  auto
  style_manager::property_color_scheme () -> glib::PropertyProxy<ColorScheme>
  {
    return {this, "color-scheme"};
  }

  auto
  style_manager::property_color_scheme () const -> glib::PropertyProxy_ReadOnly<ColorScheme>
  {
    return {this, "color-scheme"};
  }

  auto
  style_manager::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>
  {
    return {this, "display"};
  }

  auto
  style_manager::property_system_supports_color_schemes () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "system-supports-color-schemes"};
  }

  auto
  style_manager::property_dark () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "dark"};
  }

} // namespace adw
