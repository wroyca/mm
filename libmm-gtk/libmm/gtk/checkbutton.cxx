// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/checkbutton.hxx>
#include <libmm/gtk/checkbutton_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  CheckButton::CheckButton (const Glib::ustring& label, bool mnemonic)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (checkbutton_class_.init (),
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

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo CheckButton_signal_toggled_info = {
      "toggled",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GtkCheckButton* object, bool take_copy) -> Gtk::CheckButton*
  {
    return dynamic_cast<Gtk::CheckButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CheckButton_Class::init () -> const Glib::Class&
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->toggled)
      (*base->toggled) (self);
  }

  auto
  CheckButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CheckButton ((GtkCheckButton*) (o)));
  }

  CheckButton::CheckButton (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  CheckButton::CheckButton (GtkCheckButton* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  CheckButton::CheckButton (CheckButton&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  CheckButton::operator= (CheckButton&& src) noexcept -> CheckButton&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (checkbutton_class_.init ()))
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
  CheckButton::set_label (const Glib::ustring& label) -> void
  {
    gtk_check_button_set_label (gobj (), label.c_str ());
  }

  auto
  CheckButton::get_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
    return Glib::wrap (gtk_check_button_get_child (gobj ()));
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
  CheckButton::signal_toggled () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &CheckButton_signal_toggled_info);
  }

  auto
  CheckButton::property_active () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "active");
  }

  auto
  CheckButton::property_active () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "active");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<CheckButton*>::value,
      "Type CheckButton* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CheckButton::property_group () -> Glib::PropertyProxy_WriteOnly<CheckButton*>
  {
    return Glib::PropertyProxy_WriteOnly<CheckButton*> (this, "group");
  }

  auto
  CheckButton::property_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "label");
  }

  auto
  CheckButton::property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "label");
  }

  auto
  CheckButton::property_inconsistent () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "inconsistent");
  }

  auto
  CheckButton::property_inconsistent () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "inconsistent");
  }

  auto
  CheckButton::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  CheckButton::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

  auto
  CheckButton::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  CheckButton::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  Gtk::CheckButton::on_toggled () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->toggled)
      (*base->toggled) (gobj ());
  }

} // namespace Gtk
