


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/simpleaction.hpp>
#include <mm/gio/private/simpleaction_p.hpp>


/* Copyright (C) 2011 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <mm/glib/exceptionhandler.hpp>
#include <mm/glib/variant.hpp>

namespace Gio
{

SimpleAction::SimpleAction(const Glib::ustring& name) : // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  ObjectBase(nullptr),
  Object(Glib::ConstructParams(simpleaction_class_.init(), "name",name.c_str(), nullptr))
{
}

SimpleAction::SimpleAction(const Glib::ustring& name, const Glib::VariantBase& state)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(simpleaction_class_.init(), "name",name.c_str(),"state",state.gobj(), nullptr))
{
}

auto
SimpleAction::create_bool(const Glib::ustring& name, const bool state) -> Glib::RefPtr<SimpleAction>
{
  // We must provide some initial state, as a way to specify the type of the state.
  return create(name, Glib::Variant<bool>::create(state));
}

auto
SimpleAction::create_radio_string(const Glib::ustring& name, const Glib::ustring& initial_state) -> Glib::RefPtr<SimpleAction>
{
  // See
  // https://developer.gnome.org/glib/stable/gvariant-format-strings.html#gvariant-format-strings-strings
  return create(
    name, Glib::VARIANT_TYPE_STRING, Glib::Variant<Glib::ustring>::create(initial_state));
}

auto
SimpleAction::create_radio_integer(const Glib::ustring& name, const gint32 initial_state) -> Glib::RefPtr<SimpleAction>
{
  // See
  // https://developer.gnome.org/glib/stable/gvariant-format-strings.html#gvariant-format-strings-numeric-types
  return create(name, Glib::VARIANT_TYPE_INT32, Glib::Variant<gint32>::create(initial_state));
}

} // namespace Gio

namespace
{


auto SimpleAction_signal_activate_callback (GSimpleAction *self, GVariant *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::VariantBase&)>;

  const auto obj = dynamic_cast<SimpleAction*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo SimpleAction_signal_activate_info =
{
  "activate",
  (GCallback) &SimpleAction_signal_activate_callback,
  (GCallback) &SimpleAction_signal_activate_callback
};


auto SimpleAction_signal_change_state_callback (
  GSimpleAction *self, GVariant *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::VariantBase&)>;

  const auto obj = dynamic_cast<SimpleAction*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo SimpleAction_signal_change_state_info =
{
  "change-state",
  (GCallback) &SimpleAction_signal_change_state_callback,
  (GCallback) &SimpleAction_signal_change_state_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GSimpleAction* object, const bool take_copy) -> RefPtr<Gio::SimpleAction>
{
  return Glib::make_refptr_for_instance<Gio::SimpleAction>( dynamic_cast<Gio::SimpleAction*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto SimpleAction_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SimpleAction_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_simple_action_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Action::add_interface(get_type());

  }

  return *this;
}


auto SimpleAction_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SimpleAction_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SimpleAction((GSimpleAction*)object);
}


/* The implementation: */

auto SimpleAction::gobj_copy() -> GSimpleAction*
{
  reference();
  return gobj();
}

SimpleAction::SimpleAction(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SimpleAction::SimpleAction(GSimpleAction* castitem)
: Object((GObject*)castitem)
{}


SimpleAction::SimpleAction(SimpleAction&& src) noexcept
: Object(std::move(src))
  , Action(std::move(src))
{}

auto SimpleAction::operator=(SimpleAction&& src) noexcept -> SimpleAction&
{
  Object::operator=(std::move(src));
  Action::operator=(std::move(src));
  return *this;
}


SimpleAction::~SimpleAction() noexcept = default;

SimpleAction::CppClassType SimpleAction::simpleaction_class_; // initialize static member

auto SimpleAction::get_type() -> GType
{
  return simpleaction_class_.init().get_type();
}


auto SimpleAction::get_base_type() -> GType
{
  return g_simple_action_get_type();
}


SimpleAction::SimpleAction(const Glib::ustring& name, const Glib::VariantType& parameter_type)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(simpleaction_class_.init(), "name", name.c_str(), "parameter_type", parameter_type.gobj(), nullptr))
{


}

SimpleAction::SimpleAction(const Glib::ustring& name, const Glib::VariantType& parameter_type, const Glib::VariantBase& state)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(simpleaction_class_.init(), "name", name.c_str(), "parameter_type", parameter_type.gobj(), "state", state.gobj(), nullptr))
{


}

auto SimpleAction::create(const Glib::ustring& name) -> Glib::RefPtr<SimpleAction>
{
  return Glib::make_refptr_for_instance<SimpleAction>( new SimpleAction(name) );
}

auto SimpleAction::create(const Glib::ustring& name, const Glib::VariantType& parameter_type) -> Glib::RefPtr<SimpleAction>
{
  return Glib::make_refptr_for_instance<SimpleAction>( new SimpleAction(name, parameter_type) );
}

auto SimpleAction::create(const Glib::ustring& name, const Glib::VariantType& parameter_type, const Glib::VariantBase& state) -> Glib::RefPtr<SimpleAction>
{
  return Glib::make_refptr_for_instance<SimpleAction>( new SimpleAction(name, parameter_type, state) );
}

auto SimpleAction::create(const Glib::ustring& name, const Glib::VariantBase& state) -> Glib::RefPtr<SimpleAction>
{
  return Glib::make_refptr_for_instance<SimpleAction>( new SimpleAction(name, state) );
}

auto SimpleAction::set_enabled (
  const bool enabled) -> void
{
  g_simple_action_set_enabled(gobj(), enabled);
}

auto SimpleAction::set_state (const Glib::VariantBase &value) -> void
{
  g_simple_action_set_state(gobj(), const_cast<GVariant*>(value.gobj()));
}

auto SimpleAction::set_state_hint (const Glib::VariantBase &state_hint) -> void
{
  g_simple_action_set_state_hint(gobj(), const_cast<GVariant*>(state_hint.gobj()));
}


auto SimpleAction::signal_activate() -> Glib::SignalProxy<void(const Glib::VariantBase&)>
{
  return {this, &SimpleAction_signal_activate_info};
}


auto SimpleAction::signal_change_state() -> Glib::SignalProxy<void(const Glib::VariantBase&)>
{
  return {this, &SimpleAction_signal_change_state_info};
}


auto SimpleAction::property_enabled() -> Glib::PropertyProxy< bool >
{
  return {this, "enabled"};
}

auto SimpleAction::property_enabled() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "enabled"};
}

auto SimpleAction::property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "name"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantType>::value,
  "Type Glib::VariantType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SimpleAction::property_parameter_type() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantType >
{
  return {this, "parameter-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantBase>::value,
  "Type Glib::VariantBase cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SimpleAction::property_state() -> Glib::PropertyProxy< Glib::VariantBase >
{
  return {this, "state"};
}

auto SimpleAction::property_state() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantBase >
{
  return {this, "state"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantType>::value,
  "Type Glib::VariantType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SimpleAction::property_state_type() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantType >
{
  return {this, "state-type"};
}


} // namespace Gio


