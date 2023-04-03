// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/propertyaction.hxx>
#include <libmm/gio/propertyaction_p.hxx>

#include <gio/gio.h>

namespace Gio
{

  PropertyAction::PropertyAction (
      const Glib::ustring& name,
      const Glib::PropertyProxy_Base& property_proxy,
      const bool invert_boolean)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (propertyaction_class_.init (),
                                     "name",
                                     name.c_str (),
                                     "object",
                                     property_proxy.get_object ()->gobj (),
                                     "property-name",
                                     property_proxy.get_name (),
                                     "invert-boolean",
                                     invert_boolean,
                                     nullptr))
  {
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GPropertyAction* object, const bool take_copy) -> RefPtr<Gio::PropertyAction>
  {
    return Glib::make_refptr_for_instance<Gio::PropertyAction> (
        dynamic_cast<Gio::PropertyAction*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  PropertyAction_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PropertyAction_Class::class_init_function;

      register_derived_type (g_property_action_get_type ());

      Action::add_interface (get_type ());
    }

    return *this;
  }

  auto
  PropertyAction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PropertyAction_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new PropertyAction ((GPropertyAction*) object);
  }

  auto
  PropertyAction::gobj_copy () -> GPropertyAction*
  {
    reference ();
    return gobj ();
  }

  PropertyAction::PropertyAction (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  PropertyAction::PropertyAction (GPropertyAction* castitem)
    : Object ((GObject*) castitem)
  {
  }

  PropertyAction::PropertyAction (PropertyAction&& src) noexcept
    : Object (std::move (src)),
      Action (std::move (src))
  {
  }

  auto
  PropertyAction::operator= (PropertyAction&& src) noexcept -> PropertyAction&
  {
    Object::operator= (std::move (src));
    Action::operator= (std::move (src));
    return *this;
  }

  PropertyAction::~PropertyAction () noexcept = default;

  PropertyAction::CppClassType PropertyAction::propertyaction_class_;

  auto
  PropertyAction::get_type () -> GType
  {
    return propertyaction_class_.init ().get_type ();
  }

  auto
  PropertyAction::get_base_type () -> GType
  {
    return g_property_action_get_type ();
  }

  auto
  PropertyAction::create (const Glib::ustring& name,
                          const Glib::PropertyProxy_Base& property_proxy,
                          const bool invert_boolean) -> Glib::RefPtr<PropertyAction>
  {
    return Glib::make_refptr_for_instance<PropertyAction> (
        new PropertyAction (name, property_proxy, invert_boolean));
  }

  auto
  PropertyAction::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "name"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantType>::value,
      "Type Glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PropertyAction::property_parameter_type () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantType>
  {
    return {this, "parameter-type"};
  }

  auto
  PropertyAction::property_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enabled"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantType>::value,
      "Type Glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PropertyAction::property_state_type () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantType>
  {
    return {this, "state-type"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantBase>::value,
      "Type Glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PropertyAction::property_state () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>
  {
    return {this, "state"};
  }

  auto
  PropertyAction::property_invert_boolean () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "invert-boolean"};
  }

} // namespace Gio
