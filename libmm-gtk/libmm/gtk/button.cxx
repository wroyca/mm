// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/button.hxx>
#include <libmm/gtk/button_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/image.hxx>

namespace gtk
{

  Button::Button (const glib::ustring& label, bool mnemonic)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (button_class_.init (),
                                          "label",
                                          label.c_str (),
                                          "use_underline",
                                          gboolean (mnemonic),
                                          nullptr))
  {
  }

  auto
  Button::set_image_from_icon_name (const glib::ustring& icon_name,
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

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo Button_signal_clicked_info = {
      "clicked",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GtkButton* object, bool take_copy) -> gtk::Button*
  {
    return dynamic_cast<gtk::Button*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Button_Class::init () -> const glib::Class&
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->clicked)
      (*base->clicked) (self);
  }

  auto
  Button_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Button ((GtkButton*) (o)));
  }

  Button::Button (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Button::Button (GtkButton* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Button::Button (Button&& src) noexcept
    : gtk::Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  Button::operator= (Button&& src) noexcept -> Button&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (button_class_.init ()))
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
  Button::set_label (const glib::ustring& label) -> void
  {
    gtk_button_set_label (gobj (), label.c_str ());
  }

  auto
  Button::get_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
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
  Button::set_icon_name (const glib::ustring& icon_name) -> void
  {
    gtk_button_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  Button::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
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
    return glib::wrap (gtk_button_get_child (gobj ()));
  }

  auto
  Button::get_child () const -> const Widget*
  {
    return const_cast<Button*> (this)->get_child ();
  }

  auto
  Button::signal_clicked () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Button_signal_clicked_info);
  }

  auto
  Button::property_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "label");
  }

  auto
  Button::property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "label");
  }

  auto
  Button::property_has_frame () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-frame");
  }

  auto
  Button::property_has_frame () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-frame");
  }

  auto
  Button::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  Button::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

  auto
  Button::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "icon-name");
  }

  auto
  Button::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  auto
  Button::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  Button::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  gtk::Button::on_clicked () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->clicked)
      (*base->clicked) (gobj ());
  }

} // namespace gtk
