// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/colorbutton.hxx>
  #include <libmm/gtk/colorbutton_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{
}

namespace
{

  static const Glib::SignalProxyInfo ColorButton_signal_color_set_info = {
      "color-set",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GtkColorButton* object, bool take_copy) -> Gtk::ColorButton*
  {
    return dynamic_cast<Gtk::ColorButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ColorButton_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ColorButton_Class::class_init_function;

      register_derived_type (gtk_color_button_get_type ());

      ColorChooser::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ColorButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ColorButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ColorButton ((GtkColorButton*) (o)));
  }

  ColorButton::ColorButton (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ColorButton::ColorButton (GtkColorButton* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ColorButton::ColorButton (ColorButton&& src) noexcept
    : Gtk::Widget (std::move (src)),
      ColorChooser (std::move (src))
  {
  }

  auto
  ColorButton::operator= (ColorButton&& src) noexcept -> ColorButton&
  {
    Gtk::Widget::operator= (std::move (src));
    ColorChooser::operator= (std::move (src));
    return *this;
  }

  ColorButton::~ColorButton () noexcept
  {
    destroy_ ();
  }

  ColorButton::CppClassType ColorButton::colorbutton_class_;

  auto
  ColorButton::get_type () -> GType
  {
    return colorbutton_class_.init ().get_type ();
  }

  auto
  ColorButton::get_base_type () -> GType
  {
    return gtk_color_button_get_type ();
  }

  ColorButton::ColorButton ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (colorbutton_class_.init ()))
  {
  }

  ColorButton::ColorButton (const Gdk::RGBA& rgba)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (colorbutton_class_.init (),
                                          "rgba",
                                          (rgba).gobj (),
                                          nullptr))
  {
  }

  auto
  ColorButton::set_title (const Glib::ustring& title) -> void
  {
    gtk_color_button_set_title (gobj (), title.c_str ());
  }

  auto
  ColorButton::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_color_button_get_title (const_cast<GtkColorButton*> (gobj ())));
  }

  auto
  ColorButton::set_modal (bool modal) -> void
  {
    gtk_color_button_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  ColorButton::get_modal () const -> bool
  {
    return gtk_color_button_get_modal (const_cast<GtkColorButton*> (gobj ()));
  }

  auto
  ColorButton::signal_color_set () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &ColorButton_signal_color_set_info);
  }

  auto
  ColorButton::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  ColorButton::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  ColorButton::property_show_editor () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-editor");
  }

  auto
  ColorButton::property_show_editor () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-editor");
  }

  auto
  ColorButton::property_modal () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  ColorButton::property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

} // namespace Gtk

#endif