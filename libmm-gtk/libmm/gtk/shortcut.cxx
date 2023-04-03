// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcut.hxx>
#include <libmm/gtk/shortcut_p.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkShortcut* object, bool take_copy) -> Glib::RefPtr<Gtk::Shortcut>
  {
    return Glib::make_refptr_for_instance<Gtk::Shortcut> (
        dynamic_cast<Gtk::Shortcut*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Shortcut_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Shortcut_Class::class_init_function;

      gtype_ = gtk_shortcut_get_type ();
    }

    return *this;
  }

  auto
  Shortcut_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Shortcut_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Shortcut ((GtkShortcut*) object);
  }

  auto
  Shortcut::gobj_copy () -> GtkShortcut*
  {
    reference ();
    return gobj ();
  }

  Shortcut::Shortcut (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Shortcut::Shortcut (GtkShortcut* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Shortcut::Shortcut (Shortcut&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Shortcut::operator= (Shortcut&& src) noexcept -> Shortcut&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  Shortcut::~Shortcut () noexcept {}

  Shortcut::CppClassType Shortcut::shortcut_class_;

  auto
  Shortcut::get_type () -> GType
  {
    return shortcut_class_.init ().get_type ();
  }

  auto
  Shortcut::get_base_type () -> GType
  {
    return gtk_shortcut_get_type ();
  }

  Shortcut::Shortcut (const Glib::RefPtr<const ShortcutTrigger>& trigger,
                      const Glib::RefPtr<const ShortcutAction>& action)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (
          shortcut_class_.init (),
          "trigger",
          const_cast<GtkShortcutTrigger*> (Glib::unwrap (trigger)),
          "action",
          const_cast<GtkShortcutAction*> (Glib::unwrap (action)),
          nullptr))
  {
  }

  auto
  Shortcut::create (const Glib::RefPtr<const ShortcutTrigger>& trigger,
                    const Glib::RefPtr<const ShortcutAction>& action) -> Glib::RefPtr<Shortcut>
  {
    return Glib::make_refptr_for_instance<Shortcut> (
        new Shortcut (trigger, action));
  }

  auto
  Shortcut::get_trigger () const -> Glib::RefPtr<ShortcutTrigger>
  {
    auto retvalue = Glib::wrap (
        gtk_shortcut_get_trigger (const_cast<GtkShortcut*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Shortcut::set_trigger (const Glib::RefPtr<const ShortcutTrigger>& trigger) -> void
  {
    gtk_shortcut_set_trigger (
        gobj (),
        Glib::unwrap_copy (std::const_pointer_cast<ShortcutTrigger> (trigger)));
  }

  auto
  Shortcut::get_action () const -> Glib::RefPtr<ShortcutAction>
  {
    auto retvalue = Glib::wrap (
        gtk_shortcut_get_action (const_cast<GtkShortcut*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Shortcut::set_trigger (const Glib::RefPtr<const ShortcutAction>& action) -> void
  {
    gtk_shortcut_set_action (
        gobj (),
        Glib::unwrap_copy (std::const_pointer_cast<ShortcutAction> (action)));
  }

  auto
  Shortcut::get_arguments () const -> Glib::VariantBase
  {
    return Glib::wrap (
        gtk_shortcut_get_arguments (const_cast<GtkShortcut*> (gobj ())),
        true);
  }

  auto
  Shortcut::set_arguments (const Glib::VariantBase& args) const -> void
  {
    gtk_shortcut_set_arguments (const_cast<GtkShortcut*> (gobj ()),
                                const_cast<GVariant*> ((args).gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ShortcutTrigger>>::value,
      "Type Glib::RefPtr<ShortcutTrigger> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Shortcut::property_trigger () -> Glib::PropertyProxy<Glib::RefPtr<ShortcutTrigger>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<ShortcutTrigger>> (this, "trigger");
  }

  auto
  Shortcut::property_trigger () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ShortcutTrigger>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ShortcutTrigger>> (
        this,
        "trigger");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ShortcutAction>>::value,
      "Type Glib::RefPtr<ShortcutAction> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Shortcut::property_action () -> Glib::PropertyProxy<Glib::RefPtr<ShortcutAction>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<ShortcutAction>> (this, "action");
  }

  auto
  Shortcut::property_action () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ShortcutAction>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ShortcutAction>> (
        this,
        "action");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantBase>::value,
      "Type Glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Shortcut::property_arguments () -> Glib::PropertyProxy<Glib::VariantBase>
  {
    return Glib::PropertyProxy<Glib::VariantBase> (this, "arguments");
  }

  auto
  Shortcut::property_arguments () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::VariantBase> (this, "arguments");
  }

} // namespace Gtk