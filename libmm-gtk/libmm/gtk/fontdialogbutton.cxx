// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/fontdialogbutton.hxx>
#include <libmm/gtk/fontdialogbutton_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

auto
glib::Value<gtk::FontLevel>::value_type () -> GType
{
  return gtk_font_level_get_type ();
}

namespace glib
{

  auto
  wrap (GtkFontDialogButton* object, bool take_copy) -> gtk::FontDialogButton*
  {
    return dynamic_cast<gtk::FontDialogButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  FontDialogButton_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_font_dialog_button_get_type ();
    }

    return *this;
  }

  auto
  FontDialogButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new FontDialogButton ((GtkFontDialogButton*) (o)));
  }

  FontDialogButton::FontDialogButton (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  FontDialogButton::FontDialogButton (GtkFontDialogButton* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  FontDialogButton::FontDialogButton (FontDialogButton&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  FontDialogButton::operator= (FontDialogButton&& src) noexcept -> FontDialogButton&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  FontDialogButton::~FontDialogButton () noexcept
  {
    destroy_ ();
  }

  FontDialogButton::CppClassType FontDialogButton::fontdialogbutton_class_;

  auto
  FontDialogButton::get_type () -> GType
  {
    return fontdialogbutton_class_.init ().get_type ();
  }

  auto
  FontDialogButton::get_base_type () -> GType
  {
    return gtk_font_dialog_button_get_type ();
  }

  FontDialogButton::FontDialogButton (const glib::RefPtr<FontDialog>& dialog)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (fontdialogbutton_class_.init (),
                                          "dialog",
                                          glib::unwrap (dialog),
                                          nullptr))
  {
  }

  auto
  FontDialogButton::get_dialog () -> glib::RefPtr<FontDialog>
  {
    auto retvalue = glib::wrap (gtk_font_dialog_button_get_dialog (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontDialogButton::get_dialog () const -> glib::RefPtr<const FontDialog>
  {
    return const_cast<FontDialogButton*> (this)->get_dialog ();
  }

  auto
  FontDialogButton::set_dialog (const glib::RefPtr<FontDialog>& dialog) -> void
  {
    gtk_font_dialog_button_set_dialog (gobj (), glib::unwrap (dialog));
  }

  auto
  FontDialogButton::get_level () const -> FontLevel
  {
    return static_cast<FontLevel> (gtk_font_dialog_button_get_level (
        const_cast<GtkFontDialogButton*> (gobj ())));
  }

  auto
  FontDialogButton::set_level (FontLevel level) -> void
  {
    gtk_font_dialog_button_set_level (gobj (),
                                      static_cast<GtkFontLevel> (level));
  }

  auto
  FontDialogButton::get_font_desc () const -> pango::FontDescription
  {
    return glib::wrap (gtk_font_dialog_button_get_font_desc (
                           const_cast<GtkFontDialogButton*> (gobj ())),
                       true);
  }

  auto
  FontDialogButton::set_font_desc (const pango::FontDescription& font_desc) -> void
  {
    gtk_font_dialog_button_set_font_desc (gobj (), (font_desc).gobj ());
  }

  auto
  FontDialogButton::get_font_features () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_font_dialog_button_get_font_features (
            const_cast<GtkFontDialogButton*> (gobj ())));
  }

  auto
  FontDialogButton::set_font_features (const glib::ustring& font_features) -> void
  {
    gtk_font_dialog_button_set_font_features (gobj (), font_features.c_str ());
  }

  auto
  FontDialogButton::get_language () const -> pango::Language
  {
    return pango::Language (gtk_font_dialog_button_get_language (
        const_cast<GtkFontDialogButton*> (gobj ())));
  }

  auto
  FontDialogButton::set_language (const pango::Language& language) -> void
  {
    gtk_font_dialog_button_set_language (
        gobj (),
        const_cast<PangoLanguage*> ((language).gobj ()));
  }

  auto
  FontDialogButton::get_use_font () const -> bool
  {
    return gtk_font_dialog_button_get_use_font (
        const_cast<GtkFontDialogButton*> (gobj ()));
  }

  auto
  FontDialogButton::set_use_font (bool use_font) -> void
  {
    gtk_font_dialog_button_set_use_font (gobj (), static_cast<int> (use_font));
  }

  auto
  FontDialogButton::get_use_size () const -> bool
  {
    return gtk_font_dialog_button_get_use_size (
        const_cast<GtkFontDialogButton*> (gobj ()));
  }

  auto
  FontDialogButton::set_use_size (bool use_size) -> void
  {
    gtk_font_dialog_button_set_use_size (gobj (), static_cast<int> (use_size));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<FontDialog>>::value,
      "Type glib::RefPtr<FontDialog> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FontDialogButton::property_dialog () -> glib::PropertyProxy<glib::RefPtr<FontDialog>>
  {
    return glib::PropertyProxy<glib::RefPtr<FontDialog>> (this, "dialog");
  }

  auto
  FontDialogButton::property_dialog () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FontDialog>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<FontDialog>> (this,
                                                                   "dialog");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<FontLevel>::value,
      "Type FontLevel cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FontDialogButton::property_level () -> glib::PropertyProxy<FontLevel>
  {
    return glib::PropertyProxy<FontLevel> (this, "level");
  }

  auto
  FontDialogButton::property_level () const -> glib::PropertyProxy_ReadOnly<FontLevel>
  {
    return glib::PropertyProxy_ReadOnly<FontLevel> (this, "level");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          pango::FontDescription>::value,
      "Type pango::FontDescription cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FontDialogButton::property_font_desc () -> glib::PropertyProxy<pango::FontDescription>
  {
    return glib::PropertyProxy<pango::FontDescription> (this, "font-desc");
  }

  auto
  FontDialogButton::property_font_desc () const -> glib::PropertyProxy_ReadOnly<pango::FontDescription>
  {
    return glib::PropertyProxy_ReadOnly<pango::FontDescription> (this,
                                                                 "font-desc");
  }

  auto
  FontDialogButton::property_font_features () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "font-features");
  }

  auto
  FontDialogButton::property_font_features () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "font-features");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Language>::value,
      "Type pango::Language cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FontDialogButton::property_language () -> glib::PropertyProxy<pango::Language>
  {
    return glib::PropertyProxy<pango::Language> (this, "language");
  }

  auto
  FontDialogButton::property_language () const -> glib::PropertyProxy_ReadOnly<pango::Language>
  {
    return glib::PropertyProxy_ReadOnly<pango::Language> (this, "language");
  }

  auto
  FontDialogButton::property_use_font () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-font");
  }

  auto
  FontDialogButton::property_use_font () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-font");
  }

  auto
  FontDialogButton::property_use_size () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-size");
  }

  auto
  FontDialogButton::property_use_size () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-size");
  }

} // namespace gtk
