// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/stylemanager.hxx>
#include <libmm-adw/stylemanager_p.hxx>

#include <adwaita.h>
#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

auto
Glib::Value<Adw::ColorScheme>::value_type () -> GType
{
  return adw_color_scheme_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwStyleManager* object, bool take_copy) -> Glib::RefPtr<Adw::StyleManager>
  {
    return Glib::make_refptr_for_instance<Adw::StyleManager> (
        dynamic_cast<Adw::StyleManager*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  StyleManager_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_style_manager_get_type ();
    }

    return *this;
  }

  auto
  StyleManager_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new StyleManager ((AdwStyleManager*) object);
  }

  auto
  StyleManager::gobj_copy () -> AdwStyleManager*
  {
    reference ();
    return gobj ();
  }

  StyleManager::StyleManager (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  StyleManager::StyleManager (AdwStyleManager* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  StyleManager::StyleManager (StyleManager&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  StyleManager::operator= (StyleManager&& src) noexcept -> StyleManager&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (stylemanager_class_.init ()))
  {
  }

  auto
  StyleManager::create () -> Glib::RefPtr<StyleManager>
  {
    return Glib::make_refptr_for_instance<StyleManager> (new StyleManager ());
  }

  auto
  StyleManager::get_default () -> Glib::RefPtr<StyleManager>
  {
    auto retvalue = Glib::wrap (adw_style_manager_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StyleManager::get_for_display (const Glib::RefPtr<Gdk::Display>& display) -> Glib::RefPtr<StyleManager>
  {
    auto retvalue =
        Glib::wrap (adw_style_manager_get_for_display (Glib::unwrap (display)));
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
  StyleManager::get_display () const -> Glib::RefPtr<Gdk::Display>
  {
    auto retvalue = Glib::wrap (
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
  StyleManager::property_high_contrast () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "high-contrast");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ColorScheme>::value,
      "Type ColorScheme cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  StyleManager::property_color_scheme () -> Glib::PropertyProxy<ColorScheme>
  {
    return Glib::PropertyProxy<ColorScheme> (this, "color-scheme");
  }

  auto
  StyleManager::property_color_scheme () const -> Glib::PropertyProxy_ReadOnly<ColorScheme>
  {
    return Glib::PropertyProxy_ReadOnly<ColorScheme> (this, "color-scheme");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Display>>::value,
      "Type Glib::RefPtr<Gdk::Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  StyleManager::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>> (this,
                                                                     "display");
  }

  auto
  StyleManager::property_system_supports_color_schemes () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "system-supports-color-schemes");
  }

  auto
  StyleManager::property_dark () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "dark");
  }

} // namespace Adw
