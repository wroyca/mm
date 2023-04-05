// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTDIALOGBUTTON_H
#define _GTKMM_FONTDIALOGBUTTON_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/fontdialog.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FontDialogButton_Class;
}
#endif

namespace gtk
{

  enum class FontLevel
  {
    FAMILY,
    FACE,
    FONT,
    FEATURES
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::FontLevel>
    : public glib::Value_Enum<gtk::FontLevel>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
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
    explicit FontDialogButton (const glib::ConstructParams& construct_params);
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
    explicit FontDialogButton (const glib::RefPtr<FontDialog>& dialog = {});

    auto
    get_dialog () -> glib::RefPtr<FontDialog>;

    auto
    get_dialog () const -> glib::RefPtr<const FontDialog>;

    auto
    set_dialog (const glib::RefPtr<FontDialog>& dialog) -> void;

    auto
    get_level () const -> FontLevel;

    auto
    set_level (FontLevel level) -> void;

    auto
    get_font_desc () const -> pango::FontDescription;

    auto
    set_font_desc (const pango::FontDescription& font_desc) -> void;

    auto
    get_font_features () const -> glib::ustring;

    auto
    set_font_features (const glib::ustring& font_features) -> void;

    auto
    get_language () const -> pango::Language;

    auto
    set_language (const pango::Language& language) -> void;

    auto
    get_use_font () const -> bool;

    auto
    set_use_font (bool use_font = true) -> void;

    auto
    get_use_size () const -> bool;

    auto
    set_use_size (bool use_size = true) -> void;

    auto
    property_dialog () -> glib::PropertyProxy<glib::RefPtr<FontDialog>>;

    auto
    property_dialog () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FontDialog>>;

    auto
    property_level () -> glib::PropertyProxy<FontLevel>;

    auto
    property_level () const -> glib::PropertyProxy_ReadOnly<FontLevel>;

    auto
    property_font_desc () -> glib::PropertyProxy<pango::FontDescription>;

    auto
    property_font_desc () const
        -> glib::PropertyProxy_ReadOnly<pango::FontDescription>;

    auto
    property_font_features () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_font_features () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_language () -> glib::PropertyProxy<pango::Language>;

    auto
    property_language () const -> glib::PropertyProxy_ReadOnly<pango::Language>;

    auto
    property_use_font () -> glib::PropertyProxy<bool>;

    auto
    property_use_font () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_size () -> glib::PropertyProxy<bool>;

    auto
    property_use_size () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFontDialogButton* object, bool take_copy = false) -> gtk::FontDialogButton*;
} // namespace glib

#endif
