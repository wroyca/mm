// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/shortcutcontroller.hxx>
#include <libmm-gtk/shortcutcontroller_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkShortcutController* object, bool take_copy) -> Glib::RefPtr<Gtk::ShortcutController>
  {
    return Glib::make_refptr_for_instance<Gtk::ShortcutController> (
        dynamic_cast<Gtk::ShortcutController*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ShortcutController_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutController_Class::class_init_function;

      register_derived_type (gtk_shortcut_controller_get_type ());

      Gio::ListModel::add_interface (get_type ());
      Buildable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ShortcutController_Class::class_init_function (void* g_class,
                                                 void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ShortcutController_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ShortcutController ((GtkShortcutController*) object);
  }

  auto
  ShortcutController::gobj_copy () -> GtkShortcutController*
  {
    reference ();
    return gobj ();
  }

  ShortcutController::ShortcutController (
      const Glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  ShortcutController::ShortcutController (GtkShortcutController* castitem)
    : EventController ((GtkEventController*) (castitem))
  {
  }

  ShortcutController::ShortcutController (ShortcutController&& src) noexcept
    : EventController (std::move (src)),
      Gio::ListModel (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  ShortcutController::operator= (ShortcutController&& src) noexcept -> ShortcutController&
  {
    EventController::operator= (std::move (src));
    Gio::ListModel::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  ShortcutController::~ShortcutController () noexcept {}

  ShortcutController::CppClassType
      ShortcutController::shortcutcontroller_class_;

  auto
  ShortcutController::get_type () -> GType
  {
    return shortcutcontroller_class_.init ().get_type ();
  }

  auto
  ShortcutController::get_base_type () -> GType
  {
    return gtk_shortcut_controller_get_type ();
  }

  ShortcutController::ShortcutController ()
    : Glib::ObjectBase (nullptr),
      EventController (
          Glib::ConstructParams (shortcutcontroller_class_.init ()))
  {
  }

  ShortcutController::ShortcutController (
      const Glib::RefPtr<Gio::ListModel>& model)
    : Glib::ObjectBase (nullptr),
      EventController (Glib::ConstructParams (shortcutcontroller_class_.init (),
                                              "model",
                                              Glib::unwrap (model),
                                              nullptr))
  {
  }

  auto
  ShortcutController::create () -> Glib::RefPtr<ShortcutController>
  {
    return Glib::make_refptr_for_instance<ShortcutController> (
        new ShortcutController ());
  }

  auto
  ShortcutController::create (const Glib::RefPtr<Gio::ListModel>& model) -> Glib::RefPtr<ShortcutController>
  {
    return Glib::make_refptr_for_instance<ShortcutController> (
        new ShortcutController (model));
  }

  auto
  ShortcutController::set_mnemonics_modifiers (Gdk::ModifierType modifiers) -> void
  {
    gtk_shortcut_controller_set_mnemonics_modifiers (
        gobj (),
        static_cast<GdkModifierType> (modifiers));
  }

  auto
  ShortcutController::get_mnemonics_modifiers () const -> Gdk::ModifierType
  {
    return static_cast<Gdk::ModifierType> (
        gtk_shortcut_controller_get_mnemonics_modifiers (
            const_cast<GtkShortcutController*> (gobj ())));
  }

  auto
  ShortcutController::set_scope (ShortcutScope scope) -> void
  {
    gtk_shortcut_controller_set_scope (gobj (),
                                       static_cast<GtkShortcutScope> (scope));
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  ShortcutController::set_scope () const -> ShortcutScope
  {
    return static_cast<ShortcutScope> (gtk_shortcut_controller_get_scope (
        const_cast<GtkShortcutController*> (gobj ())));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  ShortcutController::get_scope () const -> ShortcutScope
  {
    return static_cast<ShortcutScope> (gtk_shortcut_controller_get_scope (
        const_cast<GtkShortcutController*> (gobj ())));
  }

  auto
  ShortcutController::add_shortcut (const Glib::RefPtr<Shortcut>& shortcut) -> void
  {
    gtk_shortcut_controller_add_shortcut (gobj (),
                                          Glib::unwrap_copy (shortcut));
  }

  auto
  ShortcutController::remove_shortcut (
      const Glib::RefPtr<const Shortcut>& shortcut) -> void
  {
    gtk_shortcut_controller_remove_shortcut (
        gobj (),
        const_cast<GtkShortcut*> (Glib::unwrap (shortcut)));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ShortcutController::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return Glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::ModifierType>::value,
      "Type Gdk::ModifierType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ShortcutController::property_mnemonic_modifiers () -> Glib::PropertyProxy<Gdk::ModifierType>
  {
    return Glib::PropertyProxy<Gdk::ModifierType> (this, "mnemonic-modifiers");
  }

  auto
  ShortcutController::property_mnemonic_modifiers () const -> Glib::PropertyProxy_ReadOnly<Gdk::ModifierType>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::ModifierType> (
        this,
        "mnemonic-modifiers");
  }

  auto
  ShortcutController::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ShortcutScope>::value,
      "Type ShortcutScope cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ShortcutController::property_scope () -> Glib::PropertyProxy<ShortcutScope>
  {
    return Glib::PropertyProxy<ShortcutScope> (this, "scope");
  }

  auto
  ShortcutController::property_scope () const -> Glib::PropertyProxy_ReadOnly<ShortcutScope>
  {
    return Glib::PropertyProxy_ReadOnly<ShortcutScope> (this, "scope");
  }

} // namespace Gtk
