// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/button.hxx>
#include <libmm-gtk/button_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/image.hxx>

namespace Gtk
{

  Button::Button (const Glib::ustring& label, bool mnemonic)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (button_class_.init (),
                                          "label",
                                          label.c_str (),
                                          "use_underline",
                                          gboolean (mnemonic),
                                          nullptr))
  {
  }

  auto
  Button::set_image_from_icon_name (const Glib::ustring& icon_name,
                                    IconSize size,
                                    bool use_fallback) -> void
  {
    set_icon_name (icon_name);
    if (size == IconSize::INHERIT && !use_fallback)
      return;

    auto image = dynamic_cast<Image*> (get_child ());
    if (image)
    {
      image->set_from_icon_name (icon_name);
      image->set_icon_size (size);
      image->property_use_fallback () = use_fallback;
    }
  }

  auto
  Button::unset_child () -> void
  {
    gtk_button_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo Button_signal_clicked_info = {
      "clicked",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GtkButton* object, bool take_copy) -> Gtk::Button*
  {
    return dynamic_cast<Gtk::Button*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Button_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Button_Class::class_init_function;

      register_derived_type (gtk_button_get_type ());

      Actionable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Button_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->clicked = &clicked_callback;
  }

  auto
  Button_Class::clicked_callback (GtkButton* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_clicked ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->clicked)
      (*base->clicked) (self);
  }

  auto
  Button_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Button ((GtkButton*) (o)));
  }

  Button::Button (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Button::Button (GtkButton* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Button::Button (Button&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  Button::operator= (Button&& src) noexcept -> Button&
  {
    Gtk::Widget::operator= (std::move (src));
    Actionable::operator= (std::move (src));
    return *this;
  }

  Button::~Button () noexcept
  {
    destroy_ ();
  }

  Button::CppClassType Button::button_class_;

  auto
  Button::get_type () -> GType
  {
    return button_class_.init ().get_type ();
  }

  auto
  Button::get_base_type () -> GType
  {
    return gtk_button_get_type ();
  }

  Button::Button ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (button_class_.init ()))
  {
  }

  auto
  Button::set_has_frame (bool has_frame) -> void
  {
    gtk_button_set_has_frame (gobj (), static_cast<int> (has_frame));
  }

  auto
  Button::get_has_frame () const -> bool
  {
    return gtk_button_get_has_frame (const_cast<GtkButton*> (gobj ()));
  }

  auto
  Button::set_label (const Glib::ustring& label) -> void
  {
    gtk_button_set_label (gobj (), label.c_str ());
  }

  auto
  Button::get_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_button_get_label (const_cast<GtkButton*> (gobj ())));
  }

  auto
  Button::set_use_underline (bool use_underline) -> void
  {
    gtk_button_set_use_underline (gobj (), static_cast<int> (use_underline));
  }

  auto
  Button::get_use_underline () const -> bool
  {
    return gtk_button_get_use_underline (const_cast<GtkButton*> (gobj ()));
  }

  auto
  Button::set_icon_name (const Glib::ustring& icon_name) -> void
  {
    gtk_button_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  Button::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_button_get_icon_name (const_cast<GtkButton*> (gobj ())));
  }

  auto
  Button::set_child (Widget& child) -> void
  {
    gtk_button_set_child (gobj (), (child).gobj ());
  }

  auto
  Button::get_child () -> Widget*
  {
    return Glib::wrap (gtk_button_get_child (gobj ()));
  }

  auto
  Button::get_child () const -> const Widget*
  {
    return const_cast<Button*> (this)->get_child ();
  }

  auto
  Button::signal_clicked () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Button_signal_clicked_info);
  }

  auto
  Button::property_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "label");
  }

  auto
  Button::property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "label");
  }

  auto
  Button::property_has_frame () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "has-frame");
  }

  auto
  Button::property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-frame");
  }

  auto
  Button::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  Button::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

  auto
  Button::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  Button::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  auto
  Button::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  Button::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  Gtk::Button::on_clicked () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->clicked)
      (*base->clicked) (gobj ());
  }

} // namespace Gtk
