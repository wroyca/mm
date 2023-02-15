// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/fontdialogbutton.hxx>
#include <libmm-gtk/fontdialogbutton_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

auto
Glib::Value<Gtk::FontLevel>::value_type () -> GType
{
  return gtk_font_level_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkFontDialogButton* object, bool take_copy) -> Gtk::FontDialogButton*
  {
    return dynamic_cast<Gtk::FontDialogButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FontDialogButton_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_font_dialog_button_get_type ();
    }

    return *this;
  }

  auto
  FontDialogButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new FontDialogButton ((GtkFontDialogButton*) (o)));
  }

  FontDialogButton::FontDialogButton (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  FontDialogButton::FontDialogButton (GtkFontDialogButton* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  FontDialogButton::FontDialogButton (FontDialogButton&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  FontDialogButton::operator= (FontDialogButton&& src) noexcept -> FontDialogButton&
  {
    Gtk::Widget::operator= (std::move (src));
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

  FontDialogButton::FontDialogButton (const Glib::RefPtr<FontDialog>& dialog)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (fontdialogbutton_class_.init (),
                                          "dialog",
                                          Glib::unwrap (dialog),
                                          nullptr))
  {
  }

  auto
  FontDialogButton::get_dialog () -> Glib::RefPtr<FontDialog>
  {
    auto retvalue = Glib::wrap (gtk_font_dialog_button_get_dialog (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontDialogButton::get_dialog () const -> Glib::RefPtr<const FontDialog>
  {
    return const_cast<FontDialogButton*> (this)->get_dialog ();
  }

  auto
  FontDialogButton::set_dialog (const Glib::RefPtr<FontDialog>& dialog) -> void
  {
    gtk_font_dialog_button_set_dialog (gobj (), Glib::unwrap (dialog));
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
  FontDialogButton::get_font_desc () const -> Pango::FontDescription
  {
    return Glib::wrap (gtk_font_dialog_button_get_font_desc (
                           const_cast<GtkFontDialogButton*> (gobj ())),
                       true);
  }

  auto
  FontDialogButton::set_font_desc (const Pango::FontDescription& font_desc) -> void
  {
    gtk_font_dialog_button_set_font_desc (gobj (), (font_desc).gobj ());
  }

  auto
  FontDialogButton::get_font_features () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_font_dialog_button_get_font_features (
            const_cast<GtkFontDialogButton*> (gobj ())));
  }

  auto
  FontDialogButton::set_font_features (const Glib::ustring& font_features) -> void
  {
    gtk_font_dialog_button_set_font_features (gobj (), font_features.c_str ());
  }

  auto
  FontDialogButton::get_language () const -> Pango::Language
  {
    return Pango::Language (gtk_font_dialog_button_get_language (
        const_cast<GtkFontDialogButton*> (gobj ())));
  }

  auto
  FontDialogButton::set_language (const Pango::Language& language) -> void
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
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<FontDialog>>::value,
      "Type Glib::RefPtr<FontDialog> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FontDialogButton::property_dialog () -> Glib::PropertyProxy<Glib::RefPtr<FontDialog>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<FontDialog>> (this, "dialog");
  }

  auto
  FontDialogButton::property_dialog () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FontDialog>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FontDialog>> (this,
                                                                   "dialog");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<FontLevel>::value,
      "Type FontLevel cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FontDialogButton::property_level () -> Glib::PropertyProxy<FontLevel>
  {
    return Glib::PropertyProxy<FontLevel> (this, "level");
  }

  auto
  FontDialogButton::property_level () const -> Glib::PropertyProxy_ReadOnly<FontLevel>
  {
    return Glib::PropertyProxy_ReadOnly<FontLevel> (this, "level");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Pango::FontDescription>::value,
      "Type Pango::FontDescription cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FontDialogButton::property_font_desc () -> Glib::PropertyProxy<Pango::FontDescription>
  {
    return Glib::PropertyProxy<Pango::FontDescription> (this, "font-desc");
  }

  auto
  FontDialogButton::property_font_desc () const -> Glib::PropertyProxy_ReadOnly<Pango::FontDescription>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::FontDescription> (this,
                                                                 "font-desc");
  }

  auto
  FontDialogButton::property_font_features () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "font-features");
  }

  auto
  FontDialogButton::property_font_features () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "font-features");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Language>::value,
      "Type Pango::Language cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FontDialogButton::property_language () -> Glib::PropertyProxy<Pango::Language>
  {
    return Glib::PropertyProxy<Pango::Language> (this, "language");
  }

  auto
  FontDialogButton::property_language () const -> Glib::PropertyProxy_ReadOnly<Pango::Language>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::Language> (this, "language");
  }

  auto
  FontDialogButton::property_use_font () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-font");
  }

  auto
  FontDialogButton::property_use_font () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-font");
  }

  auto
  FontDialogButton::property_use_size () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-size");
  }

  auto
  FontDialogButton::property_use_size () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-size");
  }

} // namespace Gtk
