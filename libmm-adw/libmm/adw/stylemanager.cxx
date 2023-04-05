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
  wrap (AdwStyleManager* object, bool take_copy) -> glib::RefPtr<adw::StyleManager>
  {
    return glib::make_refptr_for_instance<adw::StyleManager> (
        dynamic_cast<adw::StyleManager*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  StyleManager_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_style_manager_get_type ();
    }

    return *this;
  }

  auto
  StyleManager_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new StyleManager ((AdwStyleManager*) object);
  }

  auto
  StyleManager::gobj_copy () -> AdwStyleManager*
  {
    reference ();
    return gobj ();
  }

  StyleManager::StyleManager (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  StyleManager::StyleManager (AdwStyleManager* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  StyleManager::StyleManager (StyleManager&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  StyleManager::operator= (StyleManager&& src) noexcept -> StyleManager&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  StyleManager::~StyleManager () noexcept {}

  StyleManager::CppClassType StyleManager::stylemanager_class_;

  auto
  StyleManager::get_type () -> GType
  {
    return stylemanager_class_.init ().get_type ();
  }

  auto
  StyleManager::get_base_type () -> GType
  {
    return adw_style_manager_get_type ();
  }

  StyleManager::StyleManager ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (stylemanager_class_.init ()))
  {
  }

  auto
  StyleManager::create () -> glib::RefPtr<StyleManager>
  {
    return glib::make_refptr_for_instance<StyleManager> (new StyleManager ());
  }

  auto
  StyleManager::get_default () -> glib::RefPtr<StyleManager>
  {
    auto retvalue = glib::wrap (adw_style_manager_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StyleManager::get_for_display (const glib::RefPtr<gdk::Display>& display) -> glib::RefPtr<StyleManager>
  {
    auto retvalue =
        glib::wrap (adw_style_manager_get_for_display (glib::unwrap (display)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StyleManager::get_color_scheme () const -> ColorScheme
  {
    return static_cast<ColorScheme> (adw_style_manager_get_color_scheme (
        const_cast<AdwStyleManager*> (gobj ())));
  }

  auto
  StyleManager::get_system_supports_color_schemes () const -> bool
  {
    return adw_style_manager_get_system_supports_color_schemes (
        const_cast<AdwStyleManager*> (gobj ()));
  }

  auto
  StyleManager::get_dark () const -> bool
  {
    return adw_style_manager_get_dark (const_cast<AdwStyleManager*> (gobj ()));
  }

  auto
  StyleManager::get_high_contrast () const -> bool
  {
    return adw_style_manager_get_high_contrast (
        const_cast<AdwStyleManager*> (gobj ()));
  }

  auto
  StyleManager::get_display () const -> glib::RefPtr<gdk::Display>
  {
    auto retvalue = glib::wrap (
        adw_style_manager_get_display (const_cast<AdwStyleManager*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StyleManager::set_color_scheme (ColorScheme color_scheme) -> void
  {
    adw_style_manager_set_color_scheme (
        gobj (),
        static_cast<AdwColorScheme> (color_scheme));
  }

  auto
  StyleManager::property_high_contrast () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "high-contrast");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<ColorScheme>::value,
      "Type ColorScheme cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StyleManager::property_color_scheme () -> glib::PropertyProxy<ColorScheme>
  {
    return glib::PropertyProxy<ColorScheme> (this, "color-scheme");
  }

  auto
  StyleManager::property_color_scheme () const -> glib::PropertyProxy_ReadOnly<ColorScheme>
  {
    return glib::PropertyProxy_ReadOnly<ColorScheme> (this, "color-scheme");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Display>>::value,
      "Type glib::RefPtr<gdk::Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StyleManager::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>> (this,
                                                                     "display");
  }

  auto
  StyleManager::property_system_supports_color_schemes () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "system-supports-color-schemes");
  }

  auto
  StyleManager::property_dark () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "dark");
  }

} // namespace adw
