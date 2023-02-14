// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ICONTHEME_H
#define _GTKMM_ICONTHEME_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-gdk/display.hxx>
#include <libmm-gdk/paintable.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/iconpaintable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkIconTheme = struct _GtkIconTheme;
using GtkIconThemeClass = struct _GtkIconThemeClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API IconTheme_Class;
}
#endif

namespace Gtk
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

  class IconThemeError : public Glib::Error
  {
  public:
    enum Code
    {
      ICON_THEME_NOT_FOUND,
      ICON_THEME_FAILED
    };

    GTKMM_API
    IconThemeError (Code error_code, const Glib::ustring& error_message);
    GTKMM_API explicit IconThemeError (GError* gobject);
    GTKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GTKMM_API static void
    throw_func (GError* gobject);

    friend GTKMM_API void
    wrap_init ();

#endif
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::IconThemeError::Code>
    : public Glib::Value_Enum<Gtk::IconThemeError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API IconTheme : public Glib::Object
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
    explicit IconTheme (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<IconTheme>;

    static auto
    get_for_display (const Glib::RefPtr<Gdk::Display>& display)
        -> Glib::RefPtr<IconTheme>;

    auto
    get_display () -> Glib::RefPtr<Gdk::Display>;

    auto
    get_display () const -> Glib::RefPtr<const Gdk::Display>;

    void
    set_search_path (const std::vector<std::string>& path);

    auto
    get_search_path () const -> std::vector<std::string>;

    void
    add_search_path (const std::string& path);

    void
    set_resource_path (const std::vector<std::string>& path);

    auto
    get_resource_path () const -> std::vector<std::string>;

    void
    add_resource_path (const std::string& path);

    void
    set_theme_name (const Glib::ustring& theme_name);

    auto
    get_theme_name () const -> Glib::ustring;

    auto
    has_icon (const Glib::ustring& icon_name) const -> bool;

    auto
    has_gicon (const Glib::RefPtr<const Gio::Icon>& gicon) const -> bool;

    auto
    get_icon_sizes (const Glib::ustring& icon_name) const -> std::vector<int>;

    auto
    lookup_icon (const Glib::ustring& icon_name,
                 const std::vector<Glib::ustring>& fallbacks,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0)
        -> Glib::RefPtr<IconPaintable>;

    auto
    lookup_icon (const Glib::ustring& icon_name,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0)
        -> Glib::RefPtr<IconPaintable>;

    auto
    lookup_icon (const Glib::ustring& icon_name,
                 const std::vector<Glib::ustring>& fallbacks,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0) const
        -> Glib::RefPtr<const IconPaintable>;

    auto
    lookup_icon (const Glib::ustring& icon_name,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0) const
        -> Glib::RefPtr<const IconPaintable>;

    auto
    lookup_icon (const Glib::RefPtr<const Gio::Icon>& icon,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0)
        -> Glib::RefPtr<IconPaintable>;

    auto
    lookup_icon (const Glib::RefPtr<const Gio::Icon>& icon,
                 int size,
                 int scale = 1,
                 TextDirection direction = TextDirection::NONE,
                 IconLookupFlags flags = (IconLookupFlags) 0) const
        -> Glib::RefPtr<const IconPaintable>;

    auto
    get_icon_names () const -> std::vector<Glib::ustring>;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    property_display () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Display>>;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>>;

    auto
    property_icon_names () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_search_path () -> Glib::PropertyProxy<std::vector<std::string>>;

    auto
    property_search_path () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<std::string>>;

    auto
    property_resource_path () -> Glib::PropertyProxy<std::vector<std::string>>;

    auto
    property_resource_path () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<std::string>>;

    auto
    property_theme_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_theme_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkIconTheme* object, bool take_copy = false) -> Glib::RefPtr<Gtk::IconTheme>;
} // namespace Glib

#endif
