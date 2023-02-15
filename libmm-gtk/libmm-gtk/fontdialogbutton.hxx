// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTDIALOGBUTTON_H
#define _GTKMM_FONTDIALOGBUTTON_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/fontdialog.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT FontDialogButton_Class;
}
#endif

namespace Gtk
{

  enum class FontLevel
  {
    FAMILY,
    FACE,
    FONT,
    FEATURES
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::FontLevel>
    : public Glib::Value_Enum<Gtk::FontLevel>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT FontDialogButton : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef FontDialogButton CppObjectType;
    typedef FontDialogButton_Class CppClassType;
    typedef GtkFontDialogButton BaseObjectType;
    typedef GtkFontDialogButtonClass BaseClassType;
#endif

    FontDialogButton (FontDialogButton&& src) noexcept;
    auto
    operator= (FontDialogButton&& src) noexcept -> FontDialogButton&;

    FontDialogButton (const FontDialogButton&) = delete;
    auto
    operator= (const FontDialogButton&) -> FontDialogButton& = delete;

    ~FontDialogButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class FontDialogButton_Class;
    static CppClassType fontdialogbutton_class_;

  protected:
    explicit FontDialogButton (const Glib::ConstructParams& construct_params);
    explicit FontDialogButton (GtkFontDialogButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFontDialogButton*
    {
      return reinterpret_cast<GtkFontDialogButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkFontDialogButton*
    {
      return reinterpret_cast<GtkFontDialogButton*> (gobject_);
    }

  private:
  public:
    explicit FontDialogButton (const Glib::RefPtr<FontDialog>& dialog = {});

    auto
    get_dialog () -> Glib::RefPtr<FontDialog>;

    auto
    get_dialog () const -> Glib::RefPtr<const FontDialog>;

    auto
    set_dialog (const Glib::RefPtr<FontDialog>& dialog) -> void;

    auto
    get_level () const -> FontLevel;

    auto
    set_level (FontLevel level) -> void;

    auto
    get_font_desc () const -> Pango::FontDescription;

    auto
    set_font_desc (const Pango::FontDescription& font_desc) -> void;

    auto
    get_font_features () const -> Glib::ustring;

    auto
    set_font_features (const Glib::ustring& font_features) -> void;

    auto
    get_language () const -> Pango::Language;

    auto
    set_language (const Pango::Language& language) -> void;

    auto
    get_use_font () const -> bool;

    auto
    set_use_font (bool use_font = true) -> void;

    auto
    get_use_size () const -> bool;

    auto
    set_use_size (bool use_size = true) -> void;

    auto
    property_dialog () -> Glib::PropertyProxy<Glib::RefPtr<FontDialog>>;

    auto
    property_dialog () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FontDialog>>;

    auto
    property_level () -> Glib::PropertyProxy<FontLevel>;

    auto
    property_level () const -> Glib::PropertyProxy_ReadOnly<FontLevel>;

    auto
    property_font_desc () -> Glib::PropertyProxy<Pango::FontDescription>;

    auto
    property_font_desc () const
        -> Glib::PropertyProxy_ReadOnly<Pango::FontDescription>;

    auto
    property_font_features () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_font_features () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_language () -> Glib::PropertyProxy<Pango::Language>;

    auto
    property_language () const -> Glib::PropertyProxy_ReadOnly<Pango::Language>;

    auto
    property_use_font () -> Glib::PropertyProxy<bool>;

    auto
    property_use_font () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_size () -> Glib::PropertyProxy<bool>;

    auto
    property_use_size () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFontDialogButton* object, bool take_copy = false) -> Gtk::FontDialogButton*;
} // namespace Glib

#endif
