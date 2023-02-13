


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/cellareacontext.hpp>
#include <libmm-gtk/cellareacontext_p.hpp>


/* Copyright (C) 2010 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-gtk/cellarea.hpp>
#include <gtk/gtk.h>

namespace Gtk
{

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellAreaContext* object, const bool take_copy) -> RefPtr<Gtk::CellAreaContext>
{
  return Glib::make_refptr_for_instance<Gtk::CellAreaContext>( dynamic_cast<Gtk::CellAreaContext*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto CellAreaContext_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellAreaContext_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_area_context_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto CellAreaContext_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellAreaContext_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new CellAreaContext((GtkCellAreaContext*)object);
}


/* The implementation: */

auto CellAreaContext::gobj_copy() -> GtkCellAreaContext*
{
  reference();
  return gobj();
}

CellAreaContext::CellAreaContext(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

CellAreaContext::CellAreaContext(GtkCellAreaContext* castitem)
: Object((GObject*)castitem)
{}


CellAreaContext::CellAreaContext(CellAreaContext&& src) noexcept
: Object(std::move(src))
{}

auto CellAreaContext::operator=(CellAreaContext&& src) noexcept -> CellAreaContext&
{
  Object::operator=(std::move(src));
  return *this;
}


CellAreaContext::~CellAreaContext() noexcept = default;

CellAreaContext::CppClassType CellAreaContext::cellareacontext_class_; // initialize static member

auto CellAreaContext::get_type() -> GType
{
  return cellareacontext_class_.init().get_type();
}


auto CellAreaContext::get_base_type() -> GType
{
  return gtk_cell_area_context_get_type();
}


auto CellAreaContext::get_area() -> Glib::RefPtr<CellArea>
{
  auto retvalue = Glib::wrap(gtk_cell_area_context_get_area(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto CellAreaContext::get_area() const -> Glib::RefPtr<const CellArea>
{
  return const_cast<CellAreaContext*>(this)->get_area();
}

auto CellAreaContext::allocate (
  const int width, const int height) -> void
{
  gtk_cell_area_context_allocate(gobj(), width, height);
}

auto CellAreaContext::reset () -> void
{
  gtk_cell_area_context_reset(gobj());
}

auto CellAreaContext::get_preferred_width (int &minimum_width, int &natural_width) const -> void
{
  gtk_cell_area_context_get_preferred_width(const_cast<GtkCellAreaContext*>(gobj()), &minimum_width, &natural_width);
}

auto CellAreaContext::get_preferred_height (int &minimum_height, int &natural_height) const -> void
{
  gtk_cell_area_context_get_preferred_height(const_cast<GtkCellAreaContext*>(gobj()), &minimum_height, &natural_height);
}

auto CellAreaContext::get_preferred_height_for_width (
  const int width, int &minimum_height, int &natural_height) const -> void
{
  gtk_cell_area_context_get_preferred_height_for_width(const_cast<GtkCellAreaContext*>(gobj()), width, &minimum_height, &natural_height);
}

auto CellAreaContext::get_preferred_width_for_height (
  const int height, int &minimum_width, int &natural_width) const -> void
{
  gtk_cell_area_context_get_preferred_width_for_height(const_cast<GtkCellAreaContext*>(gobj()), height, &minimum_width, &natural_width);
}

auto CellAreaContext::get_allocation (int &width, int &height) const -> void
{
  gtk_cell_area_context_get_allocation(const_cast<GtkCellAreaContext*>(gobj()), &width, &height);
}

auto CellAreaContext::push_preferred_width (
  const int minimum_width, const int natural_width) -> void
{
  gtk_cell_area_context_push_preferred_width(gobj(), minimum_width, natural_width);
}

auto CellAreaContext::push_preferred_height (
  const int minimum_height, const int natural_height) -> void
{
  gtk_cell_area_context_push_preferred_height(gobj(), minimum_height, natural_height);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<CellArea*>::value,
  "Type CellArea* cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellAreaContext::property_area() const -> Glib::PropertyProxy_ReadOnly< CellArea* >
{
  return {this, "area"};
}

auto CellAreaContext::property_minimum_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "minimum-width"};
}

auto CellAreaContext::property_natural_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "natural-width"};
}

auto CellAreaContext::property_minimum_height() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "minimum-height"};
}

auto CellAreaContext::property_natural_height() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "natural-height"};
}


} // namespace Gtk


