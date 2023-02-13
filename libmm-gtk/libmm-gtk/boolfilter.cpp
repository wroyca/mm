


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/boolfilter.hpp>
#include <mm/gtk/private/boolfilter_p.hpp>


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

auto wrap(GtkBoolFilter* object, const bool take_copy) -> RefPtr<Gtk::BoolFilter>
{
  return Glib::make_refptr_for_instance<Gtk::BoolFilter>( dynamic_cast<Gtk::BoolFilter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto BoolFilter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &BoolFilter_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_bool_filter_get_type();

  }

  return *this;
}


auto BoolFilter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto BoolFilter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new BoolFilter((GtkBoolFilter*)object);
}


/* The implementation: */

auto BoolFilter::gobj_copy() -> GtkBoolFilter*
{
  reference();
  return gobj();
}

BoolFilter::BoolFilter(const Glib::ConstructParams& construct_params)
: Filter(construct_params)
{

}

BoolFilter::BoolFilter(GtkBoolFilter* castitem)
: Filter((GtkFilter*)castitem)
{}


BoolFilter::BoolFilter(BoolFilter&& src) noexcept
: Filter(std::move(src))
{}

auto BoolFilter::operator=(BoolFilter&& src) noexcept -> BoolFilter&
{
  Filter::operator=(std::move(src));
  return *this;
}


BoolFilter::~BoolFilter() noexcept = default;

BoolFilter::CppClassType BoolFilter::boolfilter_class_; // initialize static member

auto BoolFilter::get_type() -> GType
{
  return boolfilter_class_.init().get_type();
}


auto BoolFilter::get_base_type() -> GType
{
  return gtk_bool_filter_get_type();
}


BoolFilter::BoolFilter(const Glib::RefPtr<Expression<bool>>& expression)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Filter(Glib::ConstructParams(boolfilter_class_.init(), "expression", expression ? expression->gobj() : nullptr, nullptr))
{


}

auto BoolFilter::create(const Glib::RefPtr<Expression<bool>>& expression) -> Glib::RefPtr<BoolFilter>
{
  return Glib::make_refptr_for_instance<BoolFilter>( new BoolFilter(expression) );
}

auto BoolFilter::get_expression() -> Glib::RefPtr<Expression<bool>>
{
  auto retvalue = Glib::wrap<bool>(gtk_bool_filter_get_expression(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto BoolFilter::get_expression() const -> Glib::RefPtr<const Expression<bool>>
{
  auto retvalue = Glib::wrap<bool>(gtk_bool_filter_get_expression(const_cast<GtkBoolFilter*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto BoolFilter::set_expression (const Glib::RefPtr <Expression <bool>> &expression) -> void
{
  gtk_bool_filter_set_expression(gobj(), expression ? expression->gobj() : nullptr);
}

auto BoolFilter::get_invert() const -> bool
{
  return gtk_bool_filter_get_invert(const_cast<GtkBoolFilter*>(gobj()));
}

auto BoolFilter::set_invert (
  const bool invert) -> void
{
  gtk_bool_filter_set_invert(gobj(), invert);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Expression<bool>>>::value,
  "Type Glib::RefPtr<Expression<bool>> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto BoolFilter::property_expression() -> Glib::PropertyProxy< Glib::RefPtr<Expression<bool>> >
{
  return {this, "expression"};
}

auto BoolFilter::property_expression() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Expression<bool>> >
{
  return {this, "expression"};
}

auto BoolFilter::property_invert() -> Glib::PropertyProxy< bool >
{
  return {this, "invert"};
}

auto BoolFilter::property_invert() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "invert"};
}


} // namespace Gtk


