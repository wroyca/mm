


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/constraintguide.hxx>
#include <libmm-gtk/constraintguide_p.hxx>


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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkConstraintGuide* object, const bool take_copy) -> RefPtr<Gtk::ConstraintGuide>
{
  return Glib::make_refptr_for_instance<Gtk::ConstraintGuide>( dynamic_cast<Gtk::ConstraintGuide*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto ConstraintGuide_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ConstraintGuide_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_constraint_guide_get_type();

  }

  return *this;
}


auto ConstraintGuide_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ConstraintGuide_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ConstraintGuide((GtkConstraintGuide*)object);
}


/* The implementation: */

auto ConstraintGuide::gobj_copy() -> GtkConstraintGuide*
{
  reference();
  return gobj();
}

ConstraintGuide::ConstraintGuide(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ConstraintGuide::ConstraintGuide(GtkConstraintGuide* castitem)
: Object((GObject*)castitem)
{}


ConstraintGuide::ConstraintGuide(ConstraintGuide&& src) noexcept
: Object(std::move(src))
  , ConstraintTarget(std::move(src))
{}

auto ConstraintGuide::operator=(ConstraintGuide&& src) noexcept -> ConstraintGuide&
{
  Object::operator=(std::move(src));
  ConstraintTarget::operator=(std::move(src));
  return *this;
}


ConstraintGuide::~ConstraintGuide() noexcept = default;

ConstraintGuide::CppClassType ConstraintGuide::constraintguide_class_; // initialize static member

auto ConstraintGuide::get_type() -> GType
{
  return constraintguide_class_.init().get_type();
}


auto ConstraintGuide::get_base_type() -> GType
{
  return gtk_constraint_guide_get_type();
}


ConstraintGuide::ConstraintGuide()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(constraintguide_class_.init()))
{


}

auto ConstraintGuide::create() -> Glib::RefPtr<ConstraintGuide>
{
  return Glib::make_refptr_for_instance<ConstraintGuide>( new ConstraintGuide() );
}

auto ConstraintGuide::set_min_size (
  const int width, const int height) -> void
{
  gtk_constraint_guide_set_min_size(gobj(), width, height);
}

auto ConstraintGuide::get_min_size (int &width, int &height) const -> void
{
  gtk_constraint_guide_get_min_size(const_cast<GtkConstraintGuide*>(gobj()), &width, &height);
}

auto ConstraintGuide::set_nat_size (
  const int width, const int height) -> void
{
  gtk_constraint_guide_set_nat_size(gobj(), width, height);
}

auto ConstraintGuide::get_nat_size (int &width, int &height) const -> void
{
  gtk_constraint_guide_get_nat_size(const_cast<GtkConstraintGuide*>(gobj()), &width, &height);
}

auto ConstraintGuide::set_max_size (
  const int width, const int height) -> void
{
  gtk_constraint_guide_set_max_size(gobj(), width, height);
}

auto ConstraintGuide::get_max_size (int &width, int &height) const -> void
{
  gtk_constraint_guide_get_max_size(const_cast<GtkConstraintGuide*>(gobj()), &width, &height);
}

auto ConstraintGuide::set_strength (Constraint::Strength strength) -> void
{
  gtk_constraint_guide_set_strength(gobj(), static_cast<GtkConstraintStrength>(strength));
}

auto ConstraintGuide::get_strength() const -> Constraint::Strength
{
  return static_cast<Constraint::Strength>(gtk_constraint_guide_get_strength(const_cast<GtkConstraintGuide*>(gobj())));
}

auto ConstraintGuide::set_name (const Glib::ustring &name) -> void
{
  gtk_constraint_guide_set_name(gobj(), name.c_str());
}

auto ConstraintGuide::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_constraint_guide_get_name(const_cast<GtkConstraintGuide*>(gobj())));
}


auto ConstraintGuide::property_min_width() -> Glib::PropertyProxy< int >
{
  return {this, "min-width"};
}

auto ConstraintGuide::property_min_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "min-width"};
}

auto ConstraintGuide::property_min_height() -> Glib::PropertyProxy< int >
{
  return {this, "min-height"};
}

auto ConstraintGuide::property_min_height() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "min-height"};
}

auto ConstraintGuide::property_nat_width() -> Glib::PropertyProxy< int >
{
  return {this, "nat-width"};
}

auto ConstraintGuide::property_nat_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "nat-width"};
}

auto ConstraintGuide::property_nat_height() -> Glib::PropertyProxy< int >
{
  return {this, "nat-height"};
}

auto ConstraintGuide::property_nat_height() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "nat-height"};
}

auto ConstraintGuide::property_max_width() -> Glib::PropertyProxy< int >
{
  return {this, "max-width"};
}

auto ConstraintGuide::property_max_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "max-width"};
}

auto ConstraintGuide::property_max_height() -> Glib::PropertyProxy< int >
{
  return {this, "max-height"};
}

auto ConstraintGuide::property_max_height() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "max-height"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Constraint::Strength>::value,
  "Type Constraint::Strength cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ConstraintGuide::property_strength() -> Glib::PropertyProxy< Constraint::Strength >
{
  return {this, "strength"};
}

auto ConstraintGuide::property_strength() const -> Glib::PropertyProxy_ReadOnly< Constraint::Strength >
{
  return {this, "strength"};
}

auto ConstraintGuide::property_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "name"};
}

auto ConstraintGuide::property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "name"};
}


} // namespace Gtk

