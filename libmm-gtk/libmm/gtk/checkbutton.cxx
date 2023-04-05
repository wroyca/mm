// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/checkbutton.hxx>
#include <libmm/gtk/checkbutton_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  CheckButton::CheckButton (const glib::ustring& label, bool mnemonic)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (checkbutton_class_.init (),
                                          "label",
                                          label.c_str (),
                                          "use_underline",
                                          gboolean (mnemonic),
                                          nullptr))
  {
  }

  auto
  CheckButton::unset_child () -> void
  {
    gtk_check_button_set_child (gobj (), nullptr);
  }

  auto
  CheckButton::unset_group () -> void
  {
    gtk_check_button_set_group (gobj (), nullptr);
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo CheckButton_signal_toggled_info = {
      "toggled",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GtkCheckButton* object, bool take_copy) -> gtk::CheckButton*
  {
    return dynamic_cast<gtk::CheckButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CheckButton_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CheckButton_Class::class_init_function;

      register_derived_type (gtk_check_button_get_type ());

      Actionable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  CheckButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->toggled = &toggled_callback;
  }

  auto
  CheckButton_Class::toggled_callback (GtkCheckButton* self) -> void
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
          obj->on_toggled ();
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

    if (base && base->toggled)
      (*base->toggled) (self);
  }

  auto
  CheckButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CheckButton ((GtkCheckButton*) (o)));
  }

  CheckButton::CheckButton (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  CheckButton::CheckButton (GtkCheckButton* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  CheckButton::CheckButton (CheckButton&& src) noexcept
    : gtk::Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  CheckButton::operator= (CheckButton&& src) noexcept -> CheckButton&
  {
    gtk::Widget::operator= (std::move (src));
    Actionable::operator= (std::move (src));
    return *this;
  }

  CheckButton::~CheckButton () noexcept
  {
    destroy_ ();
  }

  CheckButton::CppClassType CheckButton::checkbutton_class_;

  auto
  CheckButton::get_type () -> GType
  {
    return checkbutton_class_.init ().get_type ();
  }

  auto
  CheckButton::get_base_type () -> GType
  {
    return gtk_check_button_get_type ();
  }

  CheckButton::CheckButton ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (checkbutton_class_.init ()))
  {
  }

  auto
  CheckButton::set_inconsistent (bool inconsistent) -> void
  {
    gtk_check_button_set_inconsistent (gobj (),
                                       static_cast<int> (inconsistent));
  }

  auto
  CheckButton::get_inconsistent () const -> bool
  {
    return gtk_check_button_get_inconsistent (
        const_cast<GtkCheckButton*> (gobj ()));
  }

  auto
  CheckButton::set_active (bool setting) -> void
  {
    gtk_check_button_set_active (gobj (), static_cast<int> (setting));
  }

  auto
  CheckButton::get_active () const -> bool
  {
    return gtk_check_button_get_active (const_cast<GtkCheckButton*> (gobj ()));
  }

  auto
  CheckButton::set_label (const glib::ustring& label) -> void
  {
    gtk_check_button_set_label (gobj (), label.c_str ());
  }

  auto
  CheckButton::get_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_check_button_get_label (const_cast<GtkCheckButton*> (gobj ())));
  }

  auto
  CheckButton::set_use_underline (bool setting) -> void
  {
    gtk_check_button_set_use_underline (gobj (), static_cast<int> (setting));
  }

  auto
  CheckButton::get_use_underline () const -> bool
  {
    return gtk_check_button_get_use_underline (
        const_cast<GtkCheckButton*> (gobj ()));
  }

  auto
  CheckButton::set_child (Widget& child) -> void
  {
    gtk_check_button_set_child (gobj (), (child).gobj ());
  }

  auto
  CheckButton::get_child () -> Widget*
  {
    return glib::wrap (gtk_check_button_get_child (gobj ()));
  }

  auto
  CheckButton::get_child () const -> const Widget*
  {
    return const_cast<CheckButton*> (this)->get_child ();
  }

  auto
  CheckButton::set_group (CheckButton& group) -> void
  {
    gtk_check_button_set_group (gobj (), (group).gobj ());
  }

  auto
  CheckButton::signal_toggled () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &CheckButton_signal_toggled_info);
  }

  auto
  CheckButton::property_active () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "active");
  }

  auto
  CheckButton::property_active () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "active");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<CheckButton*>::value,
      "Type CheckButton* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CheckButton::property_group () -> glib::PropertyProxy_WriteOnly<CheckButton*>
  {
    return glib::PropertyProxy_WriteOnly<CheckButton*> (this, "group");
  }

  auto
  CheckButton::property_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "label");
  }

  auto
  CheckButton::property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "label");
  }

  auto
  CheckButton::property_inconsistent () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "inconsistent");
  }

  auto
  CheckButton::property_inconsistent () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "inconsistent");
  }

  auto
  CheckButton::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  CheckButton::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

  auto
  CheckButton::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  CheckButton::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  gtk::CheckButton::on_toggled () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->toggled)
      (*base->toggled) (gobj ());
  }

} // namespace gtk
