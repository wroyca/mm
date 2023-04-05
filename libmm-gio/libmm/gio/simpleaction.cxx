// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/simpleaction.hxx>
#include <libmm/gio/simpleaction_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/variant.hxx>

namespace gio
{

  SimpleAction::SimpleAction (const glib::ustring& name)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (simpleaction_class_.init (),
                                     "name",
                                     name.c_str (),
                                     nullptr))
  {
  }

  SimpleAction::SimpleAction (const glib::ustring& name,
                              const glib::VariantBase& state)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (simpleaction_class_.init (),
                                     "name",
                                     name.c_str (),
                                     "state",
                                     state.gobj (),
                                     nullptr))
  {
  }

  auto
  SimpleAction::create_bool (const glib::ustring& name, const bool state) -> glib::RefPtr<SimpleAction>
  {
    return create (name, glib::Variant<bool>::create (state));
  }

  auto
  SimpleAction::create_radio_string (const glib::ustring& name,
                                     const glib::ustring& initial_state) -> glib::RefPtr<SimpleAction>
  {
    return create (name,
                   glib::VARIANT_TYPE_STRING,
                   glib::Variant<glib::ustring>::create (initial_state));
  }

  auto
  SimpleAction::create_radio_integer (const glib::ustring& name,
                                      const gint32 initial_state) -> glib::RefPtr<SimpleAction>
  {
    return create (name,
                   glib::VARIANT_TYPE_INT32,
                   glib::Variant<gint32>::create (initial_state));
  }

} // namespace gio

namespace
{

  auto
  SimpleAction_signal_activate_callback (GSimpleAction* self,
                                         GVariant* p0,
                                         void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::VariantBase&)>;

    const auto obj = dynamic_cast<SimpleAction*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo SimpleAction_signal_activate_info = {
      "activate",
      (GCallback) &SimpleAction_signal_activate_callback,
      (GCallback) &SimpleAction_signal_activate_callback};

  auto
  SimpleAction_signal_change_state_callback (GSimpleAction* self,
                                             GVariant* p0,
                                             void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::VariantBase&)>;

    const auto obj = dynamic_cast<SimpleAction*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo SimpleAction_signal_change_state_info = {
      "change-state",
      (GCallback) &SimpleAction_signal_change_state_callback,
      (GCallback) &SimpleAction_signal_change_state_callback};

} // namespace

namespace glib
{

  auto
  wrap (GSimpleAction* object, const bool take_copy) -> RefPtr<gio::SimpleAction>
  {
    return glib::make_refptr_for_instance<gio::SimpleAction> (
        dynamic_cast<gio::SimpleAction*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  SimpleAction_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SimpleAction_Class::class_init_function;

      register_derived_type (g_simple_action_get_type ());

      Action::add_interface (get_type ());
    }

    return *this;
  }

  auto
  SimpleAction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SimpleAction_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SimpleAction ((GSimpleAction*) object);
  }

  auto
  SimpleAction::gobj_copy () -> GSimpleAction*
  {
    reference ();
    return gobj ();
  }

  SimpleAction::SimpleAction (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  SimpleAction::SimpleAction (GSimpleAction* castitem)
    : Object ((GObject*) castitem)
  {
  }

  SimpleAction::SimpleAction (SimpleAction&& src) noexcept
    : Object (std::move (src)),
      Action (std::move (src))
  {
  }

  auto
  SimpleAction::operator= (SimpleAction&& src) noexcept -> SimpleAction&
  {
    Object::operator= (std::move (src));
    Action::operator= (std::move (src));
    return *this;
  }

  SimpleAction::~SimpleAction () noexcept = default;

  SimpleAction::CppClassType SimpleAction::simpleaction_class_;

  auto
  SimpleAction::get_type () -> GType
  {
    return simpleaction_class_.init ().get_type ();
  }

  auto
  SimpleAction::get_base_type () -> GType
  {
    return g_simple_action_get_type ();
  }

  SimpleAction::SimpleAction (const glib::ustring& name,
                              const glib::VariantType& parameter_type)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (simpleaction_class_.init (),
                                     "name",
                                     name.c_str (),
                                     "parameter_type",
                                     parameter_type.gobj (),
                                     nullptr))
  {
  }

  SimpleAction::SimpleAction (const glib::ustring& name,
                              const glib::VariantType& parameter_type,
                              const glib::VariantBase& state)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (simpleaction_class_.init (),
                                     "name",
                                     name.c_str (),
                                     "parameter_type",
                                     parameter_type.gobj (),
                                     "state",
                                     state.gobj (),
                                     nullptr))
  {
  }

  auto
  SimpleAction::create (const glib::ustring& name) -> glib::RefPtr<SimpleAction>
  {
    return glib::make_refptr_for_instance<SimpleAction> (
        new SimpleAction (name));
  }

  auto
  SimpleAction::create (const glib::ustring& name,
                        const glib::VariantType& parameter_type) -> glib::RefPtr<SimpleAction>
  {
    return glib::make_refptr_for_instance<SimpleAction> (
        new SimpleAction (name, parameter_type));
  }

  auto
  SimpleAction::create (const glib::ustring& name,
                        const glib::VariantType& parameter_type,
                        const glib::VariantBase& state) -> glib::RefPtr<SimpleAction>
  {
    return glib::make_refptr_for_instance<SimpleAction> (
        new SimpleAction (name, parameter_type, state));
  }

  auto
  SimpleAction::create (const glib::ustring& name,
                        const glib::VariantBase& state) -> glib::RefPtr<SimpleAction>
  {
    return glib::make_refptr_for_instance<SimpleAction> (
        new SimpleAction (name, state));
  }

  auto
  SimpleAction::set_enabled (const bool enabled) -> void
  {
    g_simple_action_set_enabled (gobj (), enabled);
  }

  auto
  SimpleAction::set_state (const glib::VariantBase& value) -> void
  {
    g_simple_action_set_state (gobj (), const_cast<GVariant*> (value.gobj ()));
  }

  auto
  SimpleAction::set_state_hint (const glib::VariantBase& state_hint) -> void
  {
    g_simple_action_set_state_hint (gobj (),
                                    const_cast<GVariant*> (state_hint.gobj ()));
  }

  auto
  SimpleAction::signal_activate () -> glib::SignalProxy<void (const glib::VariantBase&)>
  {
    return {this, &SimpleAction_signal_activate_info};
  }

  auto
  SimpleAction::signal_change_state () -> glib::SignalProxy<void (const glib::VariantBase&)>
  {
    return {this, &SimpleAction_signal_change_state_info};
  }

  auto
  SimpleAction::property_enabled () -> glib::PropertyProxy<bool>
  {
    return {this, "enabled"};
  }

  auto
  SimpleAction::property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enabled"};
  }

  auto
  SimpleAction::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantType>::value,
      "Type glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SimpleAction::property_parameter_type () const -> glib::PropertyProxy_ReadOnly<glib::VariantType>
  {
    return {this, "parameter-type"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantBase>::value,
      "Type glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SimpleAction::property_state () -> glib::PropertyProxy<glib::VariantBase>
  {
    return {this, "state"};
  }

  auto
  SimpleAction::property_state () const -> glib::PropertyProxy_ReadOnly<glib::VariantBase>
  {
    return {this, "state"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantType>::value,
      "Type glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SimpleAction::property_state_type () const -> glib::PropertyProxy_ReadOnly<glib::VariantType>
  {
    return {this, "state-type"};
  }

} // namespace gio
