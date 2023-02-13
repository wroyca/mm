


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/constraint.hpp>
#include <libmm-gtk/constraint_p.hpp>


/* Copyright (C) 2019 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

using Attribute = Gtk::Constraint::Attribute;
using Relation = Gtk::Constraint::Relation;

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::Constraint::Attribute>::value_type() -> GType
{
  return gtk_constraint_attribute_get_type();
}

// static
auto Glib::Value<Gtk::Constraint::Relation>::value_type() -> GType
{
  return gtk_constraint_relation_get_type();
}

// static
auto Glib::Value<Gtk::Constraint::Strength>::value_type() -> GType
{
  return gtk_constraint_strength_get_type();
}


namespace Glib
{

auto wrap(GtkConstraint* object, const bool take_copy) -> RefPtr<Gtk::Constraint>
{
  return Glib::make_refptr_for_instance<Gtk::Constraint>( dynamic_cast<Gtk::Constraint*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto Constraint_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Constraint_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_constraint_get_type();

  }

  return *this;
}


auto Constraint_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Constraint_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Constraint((GtkConstraint*)object);
}


/* The implementation: */

auto Constraint::gobj_copy() -> GtkConstraint*
{
  reference();
  return gobj();
}

Constraint::Constraint(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Constraint::Constraint(GtkConstraint* castitem)
: Object((GObject*)castitem)
{}


Constraint::Constraint(Constraint&& src) noexcept
: Object(std::move(src))
{}

auto Constraint::operator=(Constraint&& src) noexcept -> Constraint&
{
  Object::operator=(std::move(src));
  return *this;
}


Constraint::~Constraint() noexcept = default;

Constraint::CppClassType Constraint::constraint_class_; // initialize static member

auto Constraint::get_type() -> GType
{
  return constraint_class_.init().get_type();
}


auto Constraint::get_base_type() -> GType
{
  return gtk_constraint_get_type();
}


Constraint::Constraint(const Glib::RefPtr<ConstraintTarget>& target, const Attribute target_attribute, const Relation relation, const Glib::RefPtr<ConstraintTarget>& source, const Attribute source_attribute, const double multiplier, const double constant, const int strength)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(constraint_class_.init(), "target", Glib::unwrap(target), "target_attribute", target_attribute, "relation", relation, "source", Glib::unwrap(source), "source_attribute", source_attribute, "multiplier", multiplier, "constant", constant, "strength", strength, nullptr))
{


}

Constraint::Constraint(const Glib::RefPtr<ConstraintTarget>& target, const Attribute target_attribute, const Relation relation, const double constant, const int strength)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(constraint_class_.init(), "target", Glib::unwrap(target), "target_attribute", target_attribute, "relation", relation, "constant", constant, "strength", strength, nullptr))
{


}

auto Constraint::create(const Glib::RefPtr<ConstraintTarget>& target, const Attribute target_attribute, const Relation relation, const Glib::RefPtr<ConstraintTarget>& source, const Attribute source_attribute, const double multiplier, const double constant, const int strength) -> Glib::RefPtr<Constraint>
{
  return Glib::make_refptr_for_instance<Constraint>( new Constraint(target, target_attribute, relation, source, source_attribute, multiplier, constant, strength) );
}

auto Constraint::create(const Glib::RefPtr<ConstraintTarget>& target, const Attribute target_attribute, const Relation relation, const double constant, const int strength) -> Glib::RefPtr<Constraint>
{
  return Glib::make_refptr_for_instance<Constraint>( new Constraint(target, target_attribute, relation, constant, strength) );
}

auto Constraint::get_target() -> Glib::RefPtr<ConstraintTarget>
{
  auto retvalue = Glib::wrap(gtk_constraint_get_target(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Constraint::get_target() const -> Glib::RefPtr<const ConstraintTarget>
{
  return const_cast<Constraint*>(this)->get_target();
}

auto Constraint::get_target_attribute() const -> Attribute
{
  return static_cast<Attribute>(gtk_constraint_get_target_attribute(const_cast<GtkConstraint*>(gobj())));
}

auto Constraint::get_source() -> Glib::RefPtr<ConstraintTarget>
{
  auto retvalue = Glib::wrap(gtk_constraint_get_source(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Constraint::get_source() const -> Glib::RefPtr<const ConstraintTarget>
{
  return const_cast<Constraint*>(this)->get_source();
}

auto Constraint::get_source_attribute() const -> Attribute
{
  return static_cast<Attribute>(gtk_constraint_get_source_attribute(const_cast<GtkConstraint*>(gobj())));
}

auto Constraint::get_relation() const -> Relation
{
  return static_cast<Relation>(gtk_constraint_get_relation(const_cast<GtkConstraint*>(gobj())));
}

auto Constraint::get_multiplier() const -> double
{
  return gtk_constraint_get_multiplier(const_cast<GtkConstraint*>(gobj()));
}

auto Constraint::get_constant() const -> double
{
  return gtk_constraint_get_constant(const_cast<GtkConstraint*>(gobj()));
}

auto Constraint::get_strength() const -> int
{
  return gtk_constraint_get_strength(const_cast<GtkConstraint*>(gobj()));
}

auto Constraint::is_required() const -> bool
{
  return gtk_constraint_is_required(const_cast<GtkConstraint*>(gobj()));
}

auto Constraint::is_attached() const -> bool
{
  return gtk_constraint_is_attached(const_cast<GtkConstraint*>(gobj()));
}

auto Constraint::is_constant() const -> bool
{
  return gtk_constraint_is_constant(const_cast<GtkConstraint*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ConstraintTarget>>::value,
  "Type Glib::RefPtr<ConstraintTarget> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Constraint::property_target() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ConstraintTarget> >
{
  return {this, "target"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Attribute>::value,
  "Type Attribute cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Constraint::property_target_attribute() const -> Glib::PropertyProxy_ReadOnly< Attribute >
{
  return {this, "target-attribute"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Relation>::value,
  "Type Relation cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Constraint::property_relation() const -> Glib::PropertyProxy_ReadOnly< Relation >
{
  return {this, "relation"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ConstraintTarget>>::value,
  "Type Glib::RefPtr<ConstraintTarget> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Constraint::property_source() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ConstraintTarget> >
{
  return {this, "source"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Attribute>::value,
  "Type Attribute cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Constraint::property_source_attribute() const -> Glib::PropertyProxy_ReadOnly< Attribute >
{
  return {this, "source-attribute"};
}

auto Constraint::property_multiplier() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "multiplier"};
}

auto Constraint::property_constant() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "constant"};
}

auto Constraint::property_strength() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "strength"};
}


} // namespace Gtk


