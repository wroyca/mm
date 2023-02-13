


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/cellareabox.hpp>
#include <mm/gtk/private/cellareabox_p.hpp>


/* Copyright 2010 The gtkmm Development Team
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

#include <gtk/gtk.h>


namespace Gtk
{

} //namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellAreaBox* object, const bool take_copy) -> RefPtr<Gtk::CellAreaBox>
{
  return Glib::make_refptr_for_instance<Gtk::CellAreaBox>( dynamic_cast<Gtk::CellAreaBox*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto CellAreaBox_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellAreaBox_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_area_box_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto CellAreaBox_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellAreaBox_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new CellAreaBox((GtkCellAreaBox*)object);
}


/* The implementation: */

auto CellAreaBox::gobj_copy() -> GtkCellAreaBox*
{
  reference();
  return gobj();
}

CellAreaBox::CellAreaBox(const Glib::ConstructParams& construct_params)
:
  CellArea(construct_params)
{

}

CellAreaBox::CellAreaBox(GtkCellAreaBox* castitem)
:
  CellArea((GtkCellArea*)castitem)
{}


CellAreaBox::CellAreaBox(CellAreaBox&& src) noexcept
: CellArea(std::move(src))
  , Orientable(std::move(src))
{}

auto CellAreaBox::operator=(CellAreaBox&& src) noexcept -> CellAreaBox&
{
  CellArea::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}


CellAreaBox::~CellAreaBox() noexcept = default;

CellAreaBox::CppClassType CellAreaBox::cellareabox_class_; // initialize static member

auto CellAreaBox::get_type() -> GType
{
  return cellareabox_class_.init().get_type();
}


auto CellAreaBox::get_base_type() -> GType
{
  return gtk_cell_area_box_get_type();
}


CellAreaBox::CellAreaBox()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  CellArea(Glib::ConstructParams(cellareabox_class_.init()))
{


}

auto CellAreaBox::create() -> Glib::RefPtr<CellAreaBox>
{
  return Glib::make_refptr_for_instance<CellAreaBox>( new CellAreaBox() );
}

auto CellAreaBox::pack_start (CellRenderer &renderer, const bool expand, const bool align, const bool fixed) -> void
{
  gtk_cell_area_box_pack_start(gobj(), renderer.gobj(), expand, align, fixed);
}

auto CellAreaBox::pack_end (CellRenderer &renderer, const bool expand, const bool align, const bool fixed) -> void
{
  gtk_cell_area_box_pack_end(gobj(), renderer.gobj(), expand, align, fixed);
}

auto CellAreaBox::get_spacing() const -> int
{
  return gtk_cell_area_box_get_spacing(const_cast<GtkCellAreaBox*>(gobj()));
}

auto CellAreaBox::set_spacing (
  const int spacing) -> void
{
  gtk_cell_area_box_set_spacing(gobj(), spacing);
}


auto CellAreaBox::property_spacing() -> Glib::PropertyProxy< int >
{
  return {this, "spacing"};
}

auto CellAreaBox::property_spacing() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "spacing"};
}


} // namespace Gtk


