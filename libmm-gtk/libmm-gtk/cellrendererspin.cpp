


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/cellrendererspin.hpp>
#include <mm/gtk/private/cellrendererspin_p.hpp>


/* Copyright (C) 2006 The gtkmm Development Team
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

#include <mm/gtk/adjustment.hpp>
#include <gtk/gtk.h>

namespace Gtk
{

auto CellRendererSpin::_property_renderable() -> Glib::PropertyProxy_Base
{
  return CellRendererText::_property_renderable();
}

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellRendererSpin* object, const bool take_copy) -> Gtk::CellRendererSpin*
{
  return dynamic_cast<Gtk::CellRendererSpin *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellRendererSpin_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererSpin_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_spin_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto CellRendererSpin_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellRendererSpin_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellRendererSpin((GtkCellRendererSpin*)o));

}


/* The implementation: */

CellRendererSpin::CellRendererSpin(const Glib::ConstructParams& construct_params)
: CellRendererText(construct_params)
{
  }

CellRendererSpin::CellRendererSpin(GtkCellRendererSpin* castitem)
: CellRendererText((GtkCellRendererText*)castitem)
{
  }


CellRendererSpin::CellRendererSpin(CellRendererSpin&& src) noexcept
: CellRendererText(std::move(src))
{}

auto CellRendererSpin::operator=(CellRendererSpin&& src) noexcept -> CellRendererSpin&
{
  CellRendererText::operator=(std::move(src));
  return *this;
}

CellRendererSpin::~CellRendererSpin() noexcept
{
  destroy_();
}

CellRendererSpin::CppClassType CellRendererSpin::cellrendererspin_class_; // initialize static member

auto CellRendererSpin::get_type() -> GType
{
  return cellrendererspin_class_.init().get_type();
}


auto CellRendererSpin::get_base_type() -> GType
{
  return gtk_cell_renderer_spin_get_type();
}


CellRendererSpin::CellRendererSpin()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
CellRendererText(Glib::ConstructParams(cellrendererspin_class_.init()))
{


}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Adjustment>>::value,
  "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererSpin::property_adjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> >
{
  return {this, "adjustment"};
}

auto CellRendererSpin::property_adjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >
{
  return {this, "adjustment"};
}

auto CellRendererSpin::property_climb_rate() -> Glib::PropertyProxy< double >
{
  return {this, "climb-rate"};
}

auto CellRendererSpin::property_climb_rate() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "climb-rate"};
}

auto CellRendererSpin::property_digits() -> Glib::PropertyProxy< guint >
{
  return {this, "digits"};
}

auto CellRendererSpin::property_digits() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "digits"};
}


} // namespace Gtk


