// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/colordialogbutton.hxx>
#include <libmm/gtk/colordialogbutton_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkColorDialogButton* object, bool take_copy) -> Gtk::ColorDialogButton*
  {
    return dynamic_cast<Gtk::ColorDialogButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ColorDialogButton_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_color_dialog_button_get_type ();
    }

    return *this;
  }

  auto
  ColorDialogButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ColorDialogButton ((GtkColorDialogButton*) (o)));
  }

  ColorDialogButton::ColorDialogButton (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ColorDialogButton::ColorDialogButton (GtkColorDialogButton* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ColorDialogButton::ColorDialogButton (ColorDialogButton&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  ColorDialogButton::operator= (ColorDialogButton&& src) noexcept -> ColorDialogButton&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ColorDialogButton::~ColorDialogButton () noexcept
  {
    destroy_ ();
  }

  ColorDialogButton::CppClassType ColorDialogButton::colordialogbutton_class_;

  auto
  ColorDialogButton::get_type () -> GType
  {
    return colordialogbutton_class_.init ().get_type ();
  }

  auto
  ColorDialogButton::get_base_type () -> GType
  {
    return gtk_color_dialog_button_get_type ();
  }

  ColorDialogButton::ColorDialogButton (const Glib::RefPtr<ColorDialog>& dialog)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (colordialogbutton_class_.init (),
                                          "dialog",
                                          Glib::unwrap (dialog),
                                          nullptr))
  {
  }

  auto
  ColorDialogButton::get_dialog () -> Glib::RefPtr<ColorDialog>
  {
    auto retvalue = Glib::wrap (gtk_color_dialog_button_get_dialog (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColorDialogButton::get_dialog () const -> Glib::RefPtr<const ColorDialog>
  {
    return const_cast<ColorDialogButton*> (this)->get_dialog ();
  }

  auto
  ColorDialogButton::set_dialog (const Glib::RefPtr<ColorDialog>& dialog) -> void
  {
    gtk_color_dialog_button_set_dialog (gobj (), Glib::unwrap (dialog));
  }

  auto
  ColorDialogButton::get_rgba () const -> Gdk::RGBA
  {
    return Glib::wrap (const_cast<GdkRGBA*> (gtk_color_dialog_button_get_rgba (
                           const_cast<GtkColorDialogButton*> (gobj ()))),
                       true);
  }

  auto
  ColorDialogButton::set_rgba (const Gdk::RGBA& color) -> void
  {
    gtk_color_dialog_button_set_rgba (gobj (), (color).gobj ());
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ColorDialog>>::value,
      "Type Glib::RefPtr<ColorDialog> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ColorDialogButton::property_dialog () -> Glib::PropertyProxy<Glib::RefPtr<ColorDialog>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<ColorDialog>> (this, "dialog");
  }

  auto
  ColorDialogButton::property_dialog () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ColorDialog>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ColorDialog>> (this,
                                                                    "dialog");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
      "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ColorDialogButton::property_rgba () -> Glib::PropertyProxy<Gdk::RGBA>
  {
    return Glib::PropertyProxy<Gdk::RGBA> (this, "rgba");
  }

  auto
  ColorDialogButton::property_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::RGBA> (this, "rgba");
  }

} // namespace Gtk
