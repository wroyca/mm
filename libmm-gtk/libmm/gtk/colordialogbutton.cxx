// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/colordialogbutton.hxx>
#include <libmm/gtk/colordialogbutton_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkColorDialogButton* object, bool take_copy) -> gtk::ColorDialogButton*
  {
    return dynamic_cast<gtk::ColorDialogButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ColorDialogButton_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_color_dialog_button_get_type ();
    }

    return *this;
  }

  auto
  ColorDialogButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ColorDialogButton ((GtkColorDialogButton*) (o)));
  }

  ColorDialogButton::ColorDialogButton (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ColorDialogButton::ColorDialogButton (GtkColorDialogButton* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ColorDialogButton::ColorDialogButton (ColorDialogButton&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  ColorDialogButton::operator= (ColorDialogButton&& src) noexcept -> ColorDialogButton&
  {
    gtk::Widget::operator= (std::move (src));
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

  ColorDialogButton::ColorDialogButton (const glib::RefPtr<ColorDialog>& dialog)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (colordialogbutton_class_.init (),
                                          "dialog",
                                          glib::unwrap (dialog),
                                          nullptr))
  {
  }

  auto
  ColorDialogButton::get_dialog () -> glib::RefPtr<ColorDialog>
  {
    auto retvalue = glib::wrap (gtk_color_dialog_button_get_dialog (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColorDialogButton::get_dialog () const -> glib::RefPtr<const ColorDialog>
  {
    return const_cast<ColorDialogButton*> (this)->get_dialog ();
  }

  auto
  ColorDialogButton::set_dialog (const glib::RefPtr<ColorDialog>& dialog) -> void
  {
    gtk_color_dialog_button_set_dialog (gobj (), glib::unwrap (dialog));
  }

  auto
  ColorDialogButton::get_rgba () const -> gdk::RGBA
  {
    return glib::wrap (const_cast<GdkRGBA*> (gtk_color_dialog_button_get_rgba (
                           const_cast<GtkColorDialogButton*> (gobj ()))),
                       true);
  }

  auto
  ColorDialogButton::set_rgba (const gdk::RGBA& color) -> void
  {
    gtk_color_dialog_button_set_rgba (gobj (), (color).gobj ());
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ColorDialog>>::value,
      "Type glib::RefPtr<ColorDialog> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ColorDialogButton::property_dialog () -> glib::PropertyProxy<glib::RefPtr<ColorDialog>>
  {
    return glib::PropertyProxy<glib::RefPtr<ColorDialog>> (this, "dialog");
  }

  auto
  ColorDialogButton::property_dialog () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ColorDialog>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ColorDialog>> (this,
                                                                    "dialog");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::RGBA>::value,
      "Type gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ColorDialogButton::property_rgba () -> glib::PropertyProxy<gdk::RGBA>
  {
    return glib::PropertyProxy<gdk::RGBA> (this, "rgba");
  }

  auto
  ColorDialogButton::property_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>
  {
    return glib::PropertyProxy_ReadOnly<gdk::RGBA> (this, "rgba");
  }

} // namespace gtk
