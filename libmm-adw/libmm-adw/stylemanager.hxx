// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_STYLEMANAGER_H
#define _LIBADWAITAMM_STYLEMANAGER_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT StyleManager_Class;
}
#endif

namespace Adw
{

  enum class LIBMM_ADW_SYMEXPORT ColorScheme
  {
    DEFAULT,
    FORCE_LIGHT,
    PREFER_LIGHT,
    PREFER_DARK,
    FORCE_DARK
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<Adw::ColorScheme> : public Glib::Value_Enum<Adw::ColorScheme>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT StyleManager : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = StyleManager;
    using CppClassType = StyleManager_Class;
    using BaseObjectType = AdwStyleManager;
    using BaseClassType = AdwStyleManagerClass;

    StyleManager (const StyleManager&) = delete;
    auto
    operator= (const StyleManager&) -> StyleManager& = delete;

  private:
    friend class StyleManager_Class;
    static CppClassType stylemanager_class_;

  protected:
    explicit StyleManager (const Glib::ConstructParams& construct_params);
    explicit StyleManager (AdwStyleManager* castitem);

#endif

  public:
    StyleManager (StyleManager&& src) noexcept;
    auto
    operator= (StyleManager&& src) noexcept -> StyleManager&;

    ~StyleManager () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwStyleManager*
    {
      return reinterpret_cast<AdwStyleManager*> (gobject_);
    }

    auto
    gobj () const -> const AdwStyleManager*
    {
      return reinterpret_cast<AdwStyleManager*> (gobject_);
    }

    auto
    gobj_copy () -> AdwStyleManager*;

  private:
  protected:
    StyleManager ();

  public:
    static auto
    create () -> Glib::RefPtr<StyleManager>;

    static auto
    get_default () -> Glib::RefPtr<StyleManager>;

    static auto
    get_for_display (const Glib::RefPtr<Gdk::Display>& display)
        -> Glib::RefPtr<StyleManager>;

    auto
    get_color_scheme () const -> ColorScheme;

    auto
    get_system_supports_color_schemes () const -> bool;

    auto
    get_dark () const -> bool;

    auto
    get_high_contrast () const -> bool;

    auto
    get_display () const -> Glib::RefPtr<Gdk::Display>;

    auto
    set_color_scheme (ColorScheme color_scheme) -> void;

    auto
    property_high_contrast () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_color_scheme () -> Glib::PropertyProxy<ColorScheme>;

    auto
    property_color_scheme () const -> Glib::PropertyProxy_ReadOnly<ColorScheme>;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>>;

    auto
    property_system_supports_color_schemes () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_dark () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwStyleManager* object, bool take_copy = false) -> Glib::RefPtr<Adw::StyleManager>;
}

#endif
