// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/constraint.h>
#include <gtkmm/private/constraint_p.h>


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
GType Glib::Value<Gtk::Constraint::Attribute>::value_type()
{
  return gtk_constraint_attribute_get_type();
}

// static
GType Glib::Value<Gtk::Constraint::Relation>::value_type()
{
  return gtk_constraint_relation_get_type();
}

// static
GType Glib::Value<Gtk::Constraint::Strength>::value_type()
{
  return gtk_constraint_strength_get_type();
}


namespace Glib
{

Glib::RefPtr<Gtk::Constraint> wrap(GtkConstraint* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gtk::Constraint>( dynamic_cast<Gtk::Constraint*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Constraint_Class::init()
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


void Constraint_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Constraint_Class::wrap_new(GObject* object)
{
  return new Constraint((GtkConstraint*)object);
}


/* The implementation: */

GtkConstraint* Constraint::gobj_copy()
{
  reference();
  return gobj();
}

Constraint::Constraint(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Constraint::Constraint(GtkConstraint* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Constraint::Constraint(Constraint&& src) noexcept
: Glib::Object(std::move(src))
{}

Constraint& Constraint::operator=(Constraint&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


Constraint::~Constraint() noexcept
{}


Constraint::CppClassType Constraint::constraint_class_; // initialize static member

GType Constraint::get_type()
{
  return constraint_class_.init().get_type();
}


GType Constraint::get_base_type()
{
  return gtk_constraint_get_type();
}


Constraint::Constraint(const Glib::RefPtr<ConstraintTarget>& target, Attribute target_attribute, Relation relation, const Glib::RefPtr<ConstraintTarget>& source, Attribute source_attribute, double multiplier, double constant, int strength)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(constraint_class_.init(), "target", Glib::unwrap(target), "target_attribute", static_cast<GtkConstraintAttribute>(target_attribute), "relation", static_cast<GtkConstraintRelation>(relation), "source", Glib::unwrap(source), "source_attribute", static_cast<GtkConstraintAttribute>(source_attribute), "multiplier", multiplier, "constant", constant, "strength", strength, nullptr))
{
  

}

Constraint::Constraint(const Glib::RefPtr<ConstraintTarget>& target, Attribute target_attribute, Relation relation, double constant, int strength)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(constraint_class_.init(), "target", Glib::unwrap(target), "target_attribute", static_cast<GtkConstraintAttribute>(target_attribute), "relation", static_cast<GtkConstraintRelation>(relation), "constant", constant, "strength", strength, nullptr))
{
  

}

Glib::RefPtr<Constraint> Constraint::create(const Glib::RefPtr<ConstraintTarget>& target, Attribute target_attribute, Relation relation, const Glib::RefPtr<ConstraintTarget>& source, Attribute source_attribute, double multiplier, double constant, int strength)
{
  return Glib::make_refptr_for_instance<Constraint>( new Constraint(target, target_attribute, relation, source, source_attribute, multiplier, constant, strength) );
}

Glib::RefPtr<Constraint> Constraint::create(const Glib::RefPtr<ConstraintTarget>& target, Attribute target_attribute, Relation relation, double constant, int strength)
{
  return Glib::make_refptr_for_instance<Constraint>( new Constraint(target, target_attribute, relation, constant, strength) );
}

Glib::RefPtr<ConstraintTarget> Constraint::get_target()
{
  auto retvalue = Glib::wrap(gtk_constraint_get_target(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const ConstraintTarget> Constraint::get_target() const
{
  return const_cast<Constraint*>(this)->get_target();
}

Attribute Constraint::get_target_attribute() const
{
  return static_cast<Attribute>(gtk_constraint_get_target_attribute(const_cast<GtkConstraint*>(gobj())));
}

Glib::RefPtr<ConstraintTarget> Constraint::get_source()
{
  auto retvalue = Glib::wrap(gtk_constraint_get_source(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const ConstraintTarget> Constraint::get_source() const
{
  return const_cast<Constraint*>(this)->get_source();
}

Attribute Constraint::get_source_attribute() const
{
  return static_cast<Attribute>(gtk_constraint_get_source_attribute(const_cast<GtkConstraint*>(gobj())));
}

Relation Constraint::get_relation() const
{
  return static_cast<Relation>(gtk_constraint_get_relation(const_cast<GtkConstraint*>(gobj())));
}

double Constraint::get_multiplier() const
{
  return gtk_constraint_get_multiplier(const_cast<GtkConstraint*>(gobj()));
}

double Constraint::get_constant() const
{
  return gtk_constraint_get_constant(const_cast<GtkConstraint*>(gobj()));
}

int Constraint::get_strength() const
{
  return gtk_constraint_get_strength(const_cast<GtkConstraint*>(gobj()));
}

bool Constraint::is_required() const
{
  return gtk_constraint_is_required(const_cast<GtkConstraint*>(gobj()));
}

bool Constraint::is_attached() const
{
  return gtk_constraint_is_attached(const_cast<GtkConstraint*>(gobj()));
}

bool Constraint::is_constant() const
{
  return gtk_constraint_is_constant(const_cast<GtkConstraint*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ConstraintTarget>>::value,
  "Type Glib::RefPtr<ConstraintTarget> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ConstraintTarget> > Constraint::property_target() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ConstraintTarget> >(this, "target");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Attribute>::value,
  "Type Attribute cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_ReadOnly< Attribute > Constraint::property_target_attribute() const
{
  return Glib::PropertyProxy_ReadOnly< Attribute >(this, "target-attribute");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Relation>::value,
  "Type Relation cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_ReadOnly< Relation > Constraint::property_relation() const
{
  return Glib::PropertyProxy_ReadOnly< Relation >(this, "relation");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ConstraintTarget>>::value,
  "Type Glib::RefPtr<ConstraintTarget> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ConstraintTarget> > Constraint::property_source() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ConstraintTarget> >(this, "source");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Attribute>::value,
  "Type Attribute cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_ReadOnly< Attribute > Constraint::property_source_attribute() const
{
  return Glib::PropertyProxy_ReadOnly< Attribute >(this, "source-attribute");
}

Glib::PropertyProxy_ReadOnly< double > Constraint::property_multiplier() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "multiplier");
}

Glib::PropertyProxy_ReadOnly< double > Constraint::property_constant() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "constant");
}

Glib::PropertyProxy_ReadOnly< int > Constraint::property_strength() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "strength");
}


} // namespace Gtk


