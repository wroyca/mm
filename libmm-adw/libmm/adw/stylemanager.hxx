// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_STYLEMANAGER_H
#define _LIBADWAITAMM_STYLEMANAGER_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT StyleManager_Class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT ColorScheme
  {
    DEFAULT,
    FORCE_LIGHT,
    PREFER_LIGHT,
    PREFER_DARK,
    FORCE_DARK
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::ColorScheme> : public glib::Value_Enum<adw::ColorScheme>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT StyleManager : public glib::Object
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
    explicit StyleManager (const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<StyleManager>;

    static auto
    get_default () -> glib::RefPtr<StyleManager>;

    static auto
    get_for_display (const glib::RefPtr<gdk::Display>& display)
        -> glib::RefPtr<StyleManager>;

    auto
    get_color_scheme () const -> ColorScheme;

    auto
    get_system_supports_color_schemes () const -> bool;

    auto
    get_dark () const -> bool;

    auto
    get_high_contrast () const -> bool;

    auto
    get_display () const -> glib::RefPtr<gdk::Display>;

    auto
    set_color_scheme (ColorScheme color_scheme) -> void;

    auto
    property_high_contrast () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_color_scheme () -> glib::PropertyProxy<ColorScheme>;

    auto
    property_color_scheme () const -> glib::PropertyProxy_ReadOnly<ColorScheme>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>;

    auto
    property_system_supports_color_schemes () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_dark () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwStyleManager* object, bool take_copy = false) -> glib::RefPtr<adw::StyleManager>;
}

#endif
