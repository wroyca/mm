// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcutcontroller.hxx>
#include <libmm/gtk/shortcutcontroller_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkShortcutController* object, bool take_copy) -> glib::RefPtr<gtk::ShortcutController>
  {
    return glib::make_refptr_for_instance<gtk::ShortcutController> (
        dynamic_cast<gtk::ShortcutController*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ShortcutController_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutController_Class::class_init_function;

      register_derived_type (gtk_shortcut_controller_get_type ());

      gio::ListModel::add_interface (get_type ());
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
  ShortcutController_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  ShortcutController::ShortcutController (GtkShortcutController* castitem)
    : EventController ((GtkEventController*) (castitem))
  {
  }

  ShortcutController::ShortcutController (ShortcutController&& src) noexcept
    : EventController (std::move (src)),
      gio::ListModel (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  ShortcutController::operator= (ShortcutController&& src) noexcept -> ShortcutController&
  {
    EventController::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      EventController (
          glib::ConstructParams (shortcutcontroller_class_.init ()))
  {
  }

  ShortcutController::ShortcutController (
      const glib::RefPtr<gio::ListModel>& model)
    : glib::ObjectBase (nullptr),
      EventController (glib::ConstructParams (shortcutcontroller_class_.init (),
                                              "model",
                                              glib::unwrap (model),
                                              nullptr))
  {
  }

  auto
  ShortcutController::create () -> glib::RefPtr<ShortcutController>
  {
    return glib::make_refptr_for_instance<ShortcutController> (
        new ShortcutController ());
  }

  auto
  ShortcutController::create (const glib::RefPtr<gio::ListModel>& model) -> glib::RefPtr<ShortcutController>
  {
    return glib::make_refptr_for_instance<ShortcutController> (
        new ShortcutController (model));
  }

  auto
  ShortcutController::set_mnemonics_modifiers (gdk::ModifierType modifiers) -> void
  {
    gtk_shortcut_controller_set_mnemonics_modifiers (
        gobj (),
        static_cast<GdkModifierType> (modifiers));
  }

  auto
  ShortcutController::get_mnemonics_modifiers () const -> gdk::ModifierType
  {
    return static_cast<gdk::ModifierType> (
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
  ShortcutController::add_shortcut (const glib::RefPtr<Shortcut>& shortcut) -> void
  {
    gtk_shortcut_controller_add_shortcut (gobj (),
                                          glib::unwrap_copy (shortcut));
  }

  auto
  ShortcutController::remove_shortcut (
      const glib::RefPtr<const Shortcut>& shortcut) -> void
  {
    gtk_shortcut_controller_remove_shortcut (
        gobj (),
        const_cast<GtkShortcut*> (glib::unwrap (shortcut)));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ShortcutController::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::ModifierType>::value,
      "Type gdk::ModifierType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ShortcutController::property_mnemonic_modifiers () -> glib::PropertyProxy<gdk::ModifierType>
  {
    return glib::PropertyProxy<gdk::ModifierType> (this, "mnemonic-modifiers");
  }

  auto
  ShortcutController::property_mnemonic_modifiers () const -> glib::PropertyProxy_ReadOnly<gdk::ModifierType>
  {
    return glib::PropertyProxy_ReadOnly<gdk::ModifierType> (
        this,
        "mnemonic-modifiers");
  }

  auto
  ShortcutController::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<ShortcutScope>::value,
      "Type ShortcutScope cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ShortcutController::property_scope () -> glib::PropertyProxy<ShortcutScope>
  {
    return glib::PropertyProxy<ShortcutScope> (this, "scope");
  }

  auto
  ShortcutController::property_scope () const -> glib::PropertyProxy_ReadOnly<ShortcutScope>
  {
    return glib::PropertyProxy_ReadOnly<ShortcutScope> (this, "scope");
  }

} // namespace gtk
