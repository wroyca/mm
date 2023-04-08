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
  class LIBMM_ADW_SYMEXPORT style_manager_class;
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

  class LIBMM_ADW_SYMEXPORT style_manager : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = style_manager;
    using CppClassType = style_manager_class;
    using BaseObjectType = AdwStyleManager;
    using BaseClassType = AdwStyleManagerClass;

    style_manager (const style_manager&) = delete;
    auto
    operator= (const style_manager&) -> style_manager& = delete;

  private:
    friend class style_manager_class;
    static CppClassType stylemanager_class_;

  protected:
    explicit style_manager (const glib::ConstructParams& construct_params);
    explicit style_manager (AdwStyleManager* castitem);

#endif

  public:
    style_manager (style_manager&& src) noexcept;
    auto
    operator= (style_manager&& src) noexcept -> style_manager&;

    ~style_manager () noexcept override;

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
    style_manager ();

  public:
    static auto
    create () -> glib::RefPtr<style_manager>;

    static auto
    get_default () -> glib::RefPtr<style_manager>;

    static auto
    get_for_display (const glib::RefPtr<gdk::Display>& display)
        -> glib::RefPtr<style_manager>;

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
  wrap (AdwStyleManager* object, bool take_copy = false) -> glib::RefPtr<adw::style_manager>;
}

#endif
