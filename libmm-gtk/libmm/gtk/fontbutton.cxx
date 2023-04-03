// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/fontbutton.hxx>
  #include <libmm/gtk/fontbutton_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{

  static const Glib::SignalProxyInfo FontButton_signal_font_set_info = {
      "font-set",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GtkFontButton* object, bool take_copy) -> Gtk::FontButton*
  {
    return dynamic_cast<Gtk::FontButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FontButton_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FontButton_Class::class_init_function;

      register_derived_type (gtk_font_button_get_type ());

      FontChooser::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FontButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FontButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new FontButton ((GtkFontButton*) (o)));
  }

  FontButton::FontButton (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  FontButton::FontButton (GtkFontButton* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  FontButton::FontButton (FontButton&& src) noexcept
    : Gtk::Widget (std::move (src)),
      FontChooser (std::move (src))
  {
  }

  auto
  FontButton::operator= (FontButton&& src) noexcept -> FontButton&
  {
    Gtk::Widget::operator= (std::move (src));
    FontChooser::operator= (std::move (src));
    return *this;
  }

  FontButton::~FontButton () noexcept
  {
    destroy_ ();
  }

  FontButton::CppClassType FontButton::fontbutton_class_;

  auto
  FontButton::get_type () -> GType
  {
    return fontbutton_class_.init ().get_type ();
  }

  auto
  FontButton::get_base_type () -> GType
  {
    return gtk_font_button_get_type ();
  }

  FontButton::FontButton ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (fontbutton_class_.init ()))
  {
  }

  FontButton::FontButton (const Glib::ustring& font)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (fontbutton_class_.init (),
                                          "font",
                                          font.c_str (),
                                          nullptr))
  {
  }

  auto
  FontButton::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_font_button_get_title (const_cast<GtkFontButton*> (gobj ())));
  }

  auto
  FontButton::set_title (const Glib::ustring& title) -> void
  {
    gtk_font_button_set_title (gobj (), title.c_str ());
  }

  auto
  FontButton::get_modal () const -> bool
  {
    return gtk_font_button_get_modal (const_cast<GtkFontButton*> (gobj ()));
  }

  auto
  FontButton::set_modal (bool modal) -> void
  {
    gtk_font_button_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  FontButton::get_use_font () const -> bool
  {
    return gtk_font_button_get_use_font (const_cast<GtkFontButton*> (gobj ()));
  }

  auto
  FontButton::set_use_font (bool use_font) -> void
  {
    gtk_font_button_set_use_font (gobj (), static_cast<int> (use_font));
  }

  auto
  FontButton::get_use_size () const -> bool
  {
    return gtk_font_button_get_use_size (const_cast<GtkFontButton*> (gobj ()));
  }

  auto
  FontButton::set_use_size (bool use_size) -> void
  {
    gtk_font_button_set_use_size (gobj (), static_cast<int> (use_size));
  }

  auto
  FontButton::signal_font_set () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &FontButton_signal_font_set_info);
  }

  auto
  FontButton::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  FontButton::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  FontButton::property_modal () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  FontButton::property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  FontButton::property_use_font () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-font");
  }

  auto
  FontButton::property_use_font () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-font");
  }

  auto
  FontButton::property_use_size () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-size");
  }

  auto
  FontButton::property_use_size () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-size");
  }

} // namespace Gtk

#endif
