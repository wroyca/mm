// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/colorbutton.hxx>
  #include <libmm/gtk/colorbutton_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{
}

namespace
{

  static const glib::SignalProxyInfo ColorButton_signal_color_set_info = {
      "color-set",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GtkColorButton* object, bool take_copy) -> gtk::ColorButton*
  {
    return dynamic_cast<gtk::ColorButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ColorButton_Class::init () -> const glib::Class&
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
  ColorButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ColorButton ((GtkColorButton*) (o)));
  }

  ColorButton::ColorButton (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ColorButton::ColorButton (GtkColorButton* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ColorButton::ColorButton (ColorButton&& src) noexcept
    : gtk::Widget (std::move (src)),
      ColorChooser (std::move (src))
  {
  }

  auto
  ColorButton::operator= (ColorButton&& src) noexcept -> ColorButton&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (colorbutton_class_.init ()))
  {
  }

  ColorButton::ColorButton (const gdk::RGBA& rgba)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (colorbutton_class_.init (),
                                          "rgba",
                                          (rgba).gobj (),
                                          nullptr))
  {
  }

  auto
  ColorButton::set_title (const glib::ustring& title) -> void
  {
    gtk_color_button_set_title (gobj (), title.c_str ());
  }

  auto
  ColorButton::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
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
  ColorButton::signal_color_set () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &ColorButton_signal_color_set_info);
  }

  auto
  ColorButton::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  ColorButton::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  ColorButton::property_show_editor () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-editor");
  }

  auto
  ColorButton::property_show_editor () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-editor");
  }

  auto
  ColorButton::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  ColorButton::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

} // namespace gtk

#endif
