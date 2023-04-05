// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcut.hxx>
#include <libmm/gtk/shortcut_p.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkShortcut* object, bool take_copy) -> glib::RefPtr<gtk::Shortcut>
  {
    return glib::make_refptr_for_instance<gtk::Shortcut> (
        dynamic_cast<gtk::Shortcut*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Shortcut_Class::init () -> const glib::Class&
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
  Shortcut_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Shortcut ((GtkShortcut*) object);
  }

  auto
  Shortcut::gobj_copy () -> GtkShortcut*
  {
    reference ();
    return gobj ();
  }

  Shortcut::Shortcut (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Shortcut::Shortcut (GtkShortcut* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Shortcut::Shortcut (Shortcut&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Shortcut::operator= (Shortcut&& src) noexcept -> Shortcut&
  {
    glib::Object::operator= (std::move (src));
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

  Shortcut::Shortcut (const glib::RefPtr<const ShortcutTrigger>& trigger,
                      const glib::RefPtr<const ShortcutAction>& action)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (
          shortcut_class_.init (),
          "trigger",
          const_cast<GtkShortcutTrigger*> (glib::unwrap (trigger)),
          "action",
          const_cast<GtkShortcutAction*> (glib::unwrap (action)),
          nullptr))
  {
  }

  auto
  Shortcut::create (const glib::RefPtr<const ShortcutTrigger>& trigger,
                    const glib::RefPtr<const ShortcutAction>& action) -> glib::RefPtr<Shortcut>
  {
    return glib::make_refptr_for_instance<Shortcut> (
        new Shortcut (trigger, action));
  }

  auto
  Shortcut::get_trigger () const -> glib::RefPtr<ShortcutTrigger>
  {
    auto retvalue = glib::wrap (
        gtk_shortcut_get_trigger (const_cast<GtkShortcut*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Shortcut::set_trigger (const glib::RefPtr<const ShortcutTrigger>& trigger) -> void
  {
    gtk_shortcut_set_trigger (
        gobj (),
        glib::unwrap_copy (std::const_pointer_cast<ShortcutTrigger> (trigger)));
  }

  auto
  Shortcut::get_action () const -> glib::RefPtr<ShortcutAction>
  {
    auto retvalue = glib::wrap (
        gtk_shortcut_get_action (const_cast<GtkShortcut*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Shortcut::set_trigger (const glib::RefPtr<const ShortcutAction>& action) -> void
  {
    gtk_shortcut_set_action (
        gobj (),
        glib::unwrap_copy (std::const_pointer_cast<ShortcutAction> (action)));
  }

  auto
  Shortcut::get_arguments () const -> glib::VariantBase
  {
    return glib::wrap (
        gtk_shortcut_get_arguments (const_cast<GtkShortcut*> (gobj ())),
        true);
  }

  auto
  Shortcut::set_arguments (const glib::VariantBase& args) const -> void
  {
    gtk_shortcut_set_arguments (const_cast<GtkShortcut*> (gobj ()),
                                const_cast<GVariant*> ((args).gobj ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ShortcutTrigger>>::value,
      "Type glib::RefPtr<ShortcutTrigger> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Shortcut::property_trigger () -> glib::PropertyProxy<glib::RefPtr<ShortcutTrigger>>
  {
    return glib::PropertyProxy<glib::RefPtr<ShortcutTrigger>> (this, "trigger");
  }

  auto
  Shortcut::property_trigger () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ShortcutTrigger>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ShortcutTrigger>> (
        this,
        "trigger");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ShortcutAction>>::value,
      "Type glib::RefPtr<ShortcutAction> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Shortcut::property_action () -> glib::PropertyProxy<glib::RefPtr<ShortcutAction>>
  {
    return glib::PropertyProxy<glib::RefPtr<ShortcutAction>> (this, "action");
  }

  auto
  Shortcut::property_action () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ShortcutAction>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ShortcutAction>> (
        this,
        "action");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantBase>::value,
      "Type glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Shortcut::property_arguments () -> glib::PropertyProxy<glib::VariantBase>
  {
    return glib::PropertyProxy<glib::VariantBase> (this, "arguments");
  }

  auto
  Shortcut::property_arguments () const -> glib::PropertyProxy_ReadOnly<glib::VariantBase>
  {
    return glib::PropertyProxy_ReadOnly<glib::VariantBase> (this, "arguments");
  }

} // namespace gtk
