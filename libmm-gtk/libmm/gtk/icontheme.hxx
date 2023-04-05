// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ICONTHEME_H
#define _GTKMM_ICONTHEME_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gdk/display.hxx>
#include <libmm/gdk/paintable.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/iconpaintable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkIconTheme = struct _GtkIconTheme;
using GtkIconThemeClass = struct _GtkIconThemeClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT IconTheme_Class;
}
#endif

namespace gtk
{

  enum class IconLookupFlags
  {
    FORCE_REGULAR = 1 << 0,
    FORCE_SYMBOLIC = 1 << 1,
    PRELOAD = 1 << 2
  };

  inline auto
  operator| (IconLookupFlags lhs, IconLookupFlags rhs) -> IconLookupFlags
  {
    return static_cast<IconLookupFlags> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (IconLookupFlags lhs, IconLookupFlags rhs) -> IconLookupFlags
  {
    return static_cast<IconLookupFlags> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (IconLookupFlags lhs, IconLookupFlags rhs) -> IconLookupFlags
  {
    return static_cast<IconLookupFlags> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(IconLookupFlags flags) -> IconLookupFlags
  {
    return static_cast<IconLookupFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (IconLookupFlags& lhs, IconLookupFlags rhs) -> IconLookupFlags&
  {
    return (lhs = static_cast<IconLookupFlags> (static_cast<unsigned> (lhs) |
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (IconLookupFlags& lhs, IconLookupFlags rhs) -> IconLookupFlags&
  {
    return (lhs = static_cast<IconLookupFlags> (static_cast<unsigned> (lhs) &
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (IconLookupFlags& lhs, IconLookupFlags rhs) -> IconLookupFlags&
  {
    return (lhs = static_cast<IconLookupFlags> (static_cast<unsigned> (lhs) ^
                                                static_cast<unsigned> (rhs)));
  }

  class IconThemeError : public glib::Error
  {
  public:
    enum Code
    {
      ICON_THEME_NOT_FOUND,
      ICON_THEME_FAILED
    };

    LIBMM_GTK_SYMEXPORT
    IconThemeError (Code error_code, const glib::ustring& error_message);
    LIBMM_GTK_SYMEXPORT explicit IconThemeError (GError* gobject);
    LIBMM_GTK_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GTK_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GTK_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::IconThemeError::Code>
    : public glib::Value_Enum<gtk::IconThemeError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT IconTheme : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = IconTheme;
    using CppClassType = IconTheme_Class;
    using BaseObjectType = GtkIconTheme;
    using BaseClassType = GtkIconThemeClass;

    IconTheme (const IconTheme&) = delete;
    auto
    operator= (const IconTheme&) -> IconTheme& = delete;

  private:
    friend class IconTheme_Class;
    static CppClassType icontheme_class_;

  protected:
    explicit IconTheme (const glib::ConstructParams& construct_params);
    explicit IconTheme (GtkIconTheme* castitem);

#endif

  public:
    IconTheme (IconTheme&& src) noexcept;
    auto
    operator= (IconTheme&& src) noexcept -> IconTheme&;

    ~IconTheme () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkIconTheme*
    {
      return reinterpret_cast<GtkIconTheme*> (gobject_);
    }

    auto
    gobj () const -> const GtkIconTheme*
    {
      return reinterpret_cast<GtkIconTheme*> (gobject_);
    }

    auto
    gobj_copy () -> GtkIconTheme*;

  private:
  protected:
    IconTheme ();

  public:
    static auto
    create () -> glib::RefPtr<IconTheme>;

    static auto
    get_for_display (const glib::RefPtr<gdk::Display>& display)
        -> glib::RefPtr<IconTheme>;

    auto
    get_display () -> glib::RefPtr<gdk::Display>;

    auto
    get_display () const -> glib::RefPtr<const gdk::Display>;

    auto
    set_search_path (const std::vector<std::string>& path) -> void;

    auto
    get_search_path () const -> std::vector<std::string>;

    auto
    add_search_path (const std::string& path) -> void;

    auto
    set_resource_path (const std::vector<std::string>& path) -> void;

    auto
    get_resource_path () const -> std::vector<std::string>;

    auto
    add_resource_path (const std::string& path) -> void;

    auto
    set_theme_name (const glib::ustring& theme_name) -> void;

    auto
    get_theme_name () const -> glib::ustring;

    auto
    has_icon (const glib::ustring& icon_name) const -> bool;

    auto
    has_gicon (const glib::RefPtr<const gio::Icon>& gicon) const -> bool;

    auto
    get_icon_sizes (const glib::ustring& icon_name) const -> std::vector<int>;

    auto
    lookup_icon (const glib::ustring& icon_name,
                 const std::vector<glib::ustring>& fallbacks,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0)
        -> glib::RefPtr<IconPaintable>;

    auto
    lookup_icon (const glib::ustring& icon_name,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0)
        -> glib::RefPtr<IconPaintable>;

    auto
    lookup_icon (const glib::ustring& icon_name,
                 const std::vector<glib::ustring>& fallbacks,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0) const
        -> glib::RefPtr<const IconPaintable>;

    auto
    lookup_icon (const glib::ustring& icon_name,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0) const
        -> glib::RefPtr<const IconPaintable>;

    auto
    lookup_icon (const glib::RefPtr<const gio::Icon>& icon,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0)
        -> glib::RefPtr<IconPaintable>;

    auto
    lookup_icon (const glib::RefPtr<const gio::Icon>& icon,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0) const
        -> glib::RefPtr<const IconPaintable>;

    auto
    get_icon_names () const -> std::vector<glib::ustring>;

    auto
    signal_changed () -> glib::SignalProxy<void ()>;

    auto
    property_display () -> glib::PropertyProxy<glib::RefPtr<gdk::Display>>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>;

    auto
    property_icon_names () const
        -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;

    auto
    property_search_path () -> glib::PropertyProxy<std::vector<std::string>>;

    auto
    property_search_path () const
        -> glib::PropertyProxy_ReadOnly<std::vector<std::string>>;

    auto
    property_resource_path () -> glib::PropertyProxy<std::vector<std::string>>;

    auto
    property_resource_path () const
        -> glib::PropertyProxy_ReadOnly<std::vector<std::string>>;

    auto
    property_theme_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_theme_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkIconTheme* object, bool take_copy = false) -> glib::RefPtr<gtk::IconTheme>;
} // namespace glib

#endif
