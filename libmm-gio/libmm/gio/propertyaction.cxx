// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/propertyaction.hxx>
#include <libmm/gio/propertyaction_p.hxx>

#include <gio/gio.h>

namespace gio
{

  PropertyAction::PropertyAction (
      const glib::ustring& name,
      const glib::PropertyProxy_Base& property_proxy,
      const bool invert_boolean)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (propertyaction_class_.init (),
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

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GPropertyAction* object, const bool take_copy) -> RefPtr<gio::PropertyAction>
  {
    return glib::make_refptr_for_instance<gio::PropertyAction> (
        dynamic_cast<gio::PropertyAction*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
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
  PropertyAction_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new PropertyAction ((GPropertyAction*) object);
  }

  auto
  PropertyAction::gobj_copy () -> GPropertyAction*
  {
    reference ();
    return gobj ();
  }

  PropertyAction::PropertyAction (const glib::ConstructParams& construct_params)
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
  PropertyAction::create (const glib::ustring& name,
                          const glib::PropertyProxy_Base& property_proxy,
                          const bool invert_boolean) -> glib::RefPtr<PropertyAction>
  {
    return glib::make_refptr_for_instance<PropertyAction> (
        new PropertyAction (name, property_proxy, invert_boolean));
  }

  auto
  PropertyAction::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantType>::value,
      "Type glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PropertyAction::property_parameter_type () const -> glib::PropertyProxy_ReadOnly<glib::VariantType>
  {
    return {this, "parameter-type"};
  }

  auto
  PropertyAction::property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enabled"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantType>::value,
      "Type glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PropertyAction::property_state_type () const -> glib::PropertyProxy_ReadOnly<glib::VariantType>
  {
    return {this, "state-type"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantBase>::value,
      "Type glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PropertyAction::property_state () const -> glib::PropertyProxy_ReadOnly<glib::VariantBase>
  {
    return {this, "state"};
  }

  auto
  PropertyAction::property_invert_boolean () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "invert-boolean"};
  }

} // namespace gio
