// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTCHOOSER_H
#define _GTKMM_FONTCHOOSER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/glib/interface.hxx>
  #include <libmm/pango/fontdescription.hxx>
  #include <libmm/pango/fontface.hxx>
  #include <libmm/pango/fontfamily.hxx>
  #include <libmm/pango/fontmap.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkFontChooserIface GtkFontChooserIface;
}
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFontChooser = struct _GtkFontChooser;
using GtkFontChooserClass = struct _GtkFontChooserClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT FontChooser_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT FontChooser : public Glib::Interface
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FontChooser;
    using CppClassType = FontChooser_Class;
    using BaseObjectType = GtkFontChooser;
    using BaseClassType = GtkFontChooserIface;

    FontChooser (const FontChooser&) = delete;
    auto
    operator= (const FontChooser&) -> FontChooser& = delete;

  private:
    friend class FontChooser_Class;
    static CppClassType fontchooser_class_;

  #endif
  protected:
    FontChooser ();

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit FontChooser (const Glib::Interface_Class& interface_class);

  public:
    explicit FontChooser (GtkFontChooser* castitem);

  protected:
  #endif

  public:
    FontChooser (FontChooser&& src) noexcept;
    auto
    operator= (FontChooser&& src) noexcept -> FontChooser&;

    ~FontChooser () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkFontChooser*
    {
      return reinterpret_cast<GtkFontChooser*> (gobject_);
    }

    auto
    gobj () const -> const GtkFontChooser*
    {
      return reinterpret_cast<GtkFontChooser*> (gobject_);
    }

  private:
  public:
    enum class Level
    {
      FAMILY = 0x0,
      STYLE = 1 << 0,
      SIZE = 1 << 1,
      VARIATIONS = 1 << 2,
      FEATURES = 1 << 3
    };

    auto
    get_font_family () -> Glib::RefPtr<Pango::FontFamily>;

    auto
    get_font_family () const -> Glib::RefPtr<const Pango::FontFamily>;

    auto
    get_font_face () -> Glib::RefPtr<Pango::FontFace>;

    auto
    get_font_face () const -> Glib::RefPtr<const Pango::FontFace>;

    auto
    get_font_size () const -> int;

    auto
    get_font_desc () const -> Pango::FontDescription;

    auto
    set_font_desc (const Pango::FontDescription& font_desc) -> void;

    auto
    get_font () const -> Glib::ustring;

    auto
    set_font (const Glib::ustring& fontname) -> void;

    auto
    get_preview_text () const -> Glib::ustring;

    auto
    set_preview_text (const Glib::ustring& text) -> void;

    auto
    get_show_preview_entry () const -> bool;

    auto
    set_show_preview_entry (bool show_preview_entry = true) -> void;

    typedef sigc::slot<bool (const Glib::RefPtr<const Pango::FontFamily>&,
                             const Glib::RefPtr<const Pango::FontFace>&)>
        SlotFontFilter;

    auto
    set_filter_func (const SlotFontFilter& slot) -> void;

    auto
    set_font_map (const Glib::RefPtr<Pango::FontMap>& fontmap) -> void;

    auto
    get_font_map () -> Glib::RefPtr<Pango::FontMap>;

    auto
    get_font_map () const -> Glib::RefPtr<const Pango::FontMap>;

    auto
    set_level (Level level) -> void;

    auto
    get_level () const -> Level;

    auto
    get_font_features () const -> Glib::ustring;

    auto
    get_language () const -> Glib::ustring;

    auto
    set_language (const Glib::ustring& language) -> void;

    auto
    signal_font_activated () -> Glib::SignalProxy<void (const Glib::ustring&)>;

    auto
    property_font () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_font () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_font_desc () -> Glib::PropertyProxy<Pango::FontDescription>;

    auto
    property_font_desc () const
        -> Glib::PropertyProxy_ReadOnly<Pango::FontDescription>;

    auto
    property_preview_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_preview_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_show_preview_entry () -> Glib::PropertyProxy<bool>;

    auto
    property_show_preview_entry () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_level () -> Glib::PropertyProxy<Level>;

    auto
    property_level () const -> Glib::PropertyProxy_ReadOnly<Level>;

    auto
    property_font_features () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_language () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_language () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
    virtual auto
    on_font_activated (const Glib::ustring& fontname) -> void;
  };

} // namespace Gtk

namespace Gtk
{

  inline auto
  operator| (FontChooser::Level lhs, FontChooser::Level rhs) -> FontChooser::Level
  {
    return static_cast<FontChooser::Level> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (FontChooser::Level lhs, FontChooser::Level rhs) -> FontChooser::Level
  {
    return static_cast<FontChooser::Level> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (FontChooser::Level lhs, FontChooser::Level rhs) -> FontChooser::Level
  {
    return static_cast<FontChooser::Level> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(FontChooser::Level flags) -> FontChooser::Level
  {
    return static_cast<FontChooser::Level> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (FontChooser::Level& lhs, FontChooser::Level rhs) -> FontChooser::Level&
  {
    return (lhs = static_cast<FontChooser::Level> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (FontChooser::Level& lhs, FontChooser::Level rhs) -> FontChooser::Level&
  {
    return (lhs = static_cast<FontChooser::Level> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (FontChooser::Level& lhs, FontChooser::Level rhs) -> FontChooser::Level&
  {
    return (lhs = static_cast<FontChooser::Level> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::FontChooser::Level>
    : public Glib::Value_Flags<Gtk::FontChooser::Level>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
  #endif

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFontChooser* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FontChooser>;

} // namespace Glib

#endif

#endif