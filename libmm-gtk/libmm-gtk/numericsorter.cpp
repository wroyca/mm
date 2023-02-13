


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/numericsorter.hpp>
#include <mm/gtk/private/numericsorter_p.hpp>


/* Copyright (C) 2020 The gtkmm Development Team
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

auto wrap(GtkNumericSorter* object, const bool take_copy) -> RefPtr<Gtk::NumericSorterBase>
{
  return Glib::make_refptr_for_instance<Gtk::NumericSorterBase>( dynamic_cast<Gtk::NumericSorterBase*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto NumericSorterBase_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &NumericSorterBase_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_numeric_sorter_get_type();

  }

  return *this;
}


auto NumericSorterBase_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto NumericSorterBase_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new NumericSorterBase((GtkNumericSorter*)object);
}


/* The implementation: */

auto NumericSorterBase::gobj_copy() -> GtkNumericSorter*
{
  reference();
  return gobj();
}

NumericSorterBase::NumericSorterBase(const Glib::ConstructParams& construct_params)
: Sorter(construct_params)
{

}

NumericSorterBase::NumericSorterBase(GtkNumericSorter* castitem)
: Sorter((GtkSorter*)castitem)
{}


NumericSorterBase::NumericSorterBase(NumericSorterBase&& src) noexcept
: Sorter(std::move(src))
{}

auto NumericSorterBase::operator=(NumericSorterBase&& src) noexcept -> NumericSorterBase&
{
  Sorter::operator=(std::move(src));
  return *this;
}


NumericSorterBase::~NumericSorterBase() noexcept = default;

NumericSorterBase::CppClassType NumericSorterBase::numericsorterbase_class_; // initialize static member

auto NumericSorterBase::get_type() -> GType
{
  return numericsorterbase_class_.init().get_type();
}


auto NumericSorterBase::get_base_type() -> GType
{
  return gtk_numeric_sorter_get_type();
}


NumericSorterBase::NumericSorterBase(const Glib::RefPtr<ExpressionBase>& expression)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Sorter(Glib::ConstructParams(numericsorterbase_class_.init(), "expression", expression ? expression->gobj() : nullptr, nullptr))
{


}

auto NumericSorterBase::get_sort_order() const -> SortType
{
  return static_cast<SortType>(gtk_numeric_sorter_get_sort_order(const_cast<GtkNumericSorter*>(gobj())));
}

auto NumericSorterBase::set_sort_order (SortType sort_order) -> void
{
  gtk_numeric_sorter_set_sort_order(gobj(), static_cast<GtkSortType>(sort_order));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SortType>::value,
  "Type SortType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto NumericSorterBase::property_sort_order() -> Glib::PropertyProxy< SortType >
{
  return {this, "sort-order"};
}

auto NumericSorterBase::property_sort_order() const -> Glib::PropertyProxy_ReadOnly< SortType >
{
  return {this, "sort-order"};
}


} // namespace Gtk


