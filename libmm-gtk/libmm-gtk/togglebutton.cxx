// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/togglebutton.hxx>
#include <libmm-gtk/togglebutton_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  ToggleButton::ToggleButton (const Glib::ustring& label, bool mnemonic)
    : Glib::ObjectBase (nullptr),
      Gtk::Button (Glib::ConstructParams (togglebutton_class_.init (),
                                          "label",
                                          label.c_str (),
                                          "use_underline",
                                          gboolean (mnemonic),
                                          nullptr))
  {
  }

  auto
  ToggleButton::unset_group () -> void
  {
    gtk_toggle_button_set_group (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo ToggleButton_signal_toggled_info = {
      "toggled",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GtkToggleButton* object, bool take_copy) -> Gtk::ToggleButton*
  {
    return dynamic_cast<Gtk::ToggleButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ToggleButton_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ToggleButton_Class::class_init_function;

      register_derived_type (gtk_toggle_button_get_type ());
    }

    return *this;
  }

  auto
  ToggleButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->toggled = &toggled_callback;
  }

  auto
  ToggleButton_Class::toggled_callback (GtkToggleButton* self) -> void
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
  ToggleButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ToggleButton ((GtkToggleButton*) (o)));
  }

  ToggleButton::ToggleButton (const Glib::ConstructParams& construct_params)
    : Gtk::Button (construct_params)
  {
  }

  ToggleButton::ToggleButton (GtkToggleButton* castitem)
    : Gtk::Button ((GtkButton*) (castitem))
  {
  }

  ToggleButton::ToggleButton (ToggleButton&& src) noexcept
    : Gtk::Button (std::move (src))
  {
  }

  auto
  ToggleButton::operator= (ToggleButton&& src) noexcept -> ToggleButton&
  {
    Gtk::Button::operator= (std::move (src));
    return *this;
  }

  ToggleButton::~ToggleButton () noexcept
  {
    destroy_ ();
  }

  ToggleButton::CppClassType ToggleButton::togglebutton_class_;

  auto
  ToggleButton::get_type () -> GType
  {
    return togglebutton_class_.init ().get_type ();
  }

  auto
  ToggleButton::get_base_type () -> GType
  {
    return gtk_toggle_button_get_type ();
  }

  ToggleButton::ToggleButton ()
    : Glib::ObjectBase (nullptr),
      Gtk::Button (Glib::ConstructParams (togglebutton_class_.init ()))
  {
  }

  auto
  ToggleButton::set_active (bool is_active) -> void
  {
    gtk_toggle_button_set_active (gobj (), static_cast<int> (is_active));
  }

  auto
  ToggleButton::get_active () const -> bool
  {
    return gtk_toggle_button_get_active (
        const_cast<GtkToggleButton*> (gobj ()));
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  ToggleButton::toggled () -> void
  {
    gtk_toggle_button_toggled (gobj ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  ToggleButton::set_group (ToggleButton& group) -> void
  {
    gtk_toggle_button_set_group (gobj (), (group).gobj ());
  }

  auto
  ToggleButton::signal_toggled () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &ToggleButton_signal_toggled_info);
  }

  auto
  ToggleButton::property_active () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "active");
  }

  auto
  ToggleButton::property_active () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "active");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ToggleButton*>::value,
      "Type ToggleButton* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ToggleButton::property_group () -> Glib::PropertyProxy_WriteOnly<ToggleButton*>
  {
    return Glib::PropertyProxy_WriteOnly<ToggleButton*> (this, "group");
  }

  auto
  Gtk::ToggleButton::on_toggled () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->toggled)
      (*base->toggled) (gobj ());
  }

} // namespace Gtk
