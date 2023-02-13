


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/stringsorter.hpp>
#include <mm/gtk/private/stringsorter_p.hpp>


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

auto wrap(GtkStringSorter* object, const bool take_copy) -> RefPtr<Gtk::StringSorter>
{
  return Glib::make_refptr_for_instance<Gtk::StringSorter>( dynamic_cast<Gtk::StringSorter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto StringSorter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &StringSorter_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_string_sorter_get_type();

  }

  return *this;
}


auto StringSorter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto StringSorter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new StringSorter((GtkStringSorter*)object);
}


/* The implementation: */

auto StringSorter::gobj_copy() -> GtkStringSorter*
{
  reference();
  return gobj();
}

StringSorter::StringSorter(const Glib::ConstructParams& construct_params)
: Sorter(construct_params)
{

}

StringSorter::StringSorter(GtkStringSorter* castitem)
: Sorter((GtkSorter*)castitem)
{}


StringSorter::StringSorter(StringSorter&& src) noexcept
: Sorter(std::move(src))
{}

auto StringSorter::operator=(StringSorter&& src) noexcept -> StringSorter&
{
  Sorter::operator=(std::move(src));
  return *this;
}


StringSorter::~StringSorter() noexcept = default;

StringSorter::CppClassType StringSorter::stringsorter_class_; // initialize static member

auto StringSorter::get_type() -> GType
{
  return stringsorter_class_.init().get_type();
}


auto StringSorter::get_base_type() -> GType
{
  return gtk_string_sorter_get_type();
}


StringSorter::StringSorter(const Glib::RefPtr<Expression<Glib::ustring>>& expression)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Sorter(Glib::ConstructParams(stringsorter_class_.init(), "expression", expression ? expression->gobj() : nullptr, nullptr))
{


}

auto StringSorter::create(const Glib::RefPtr<Expression<Glib::ustring>>& expression) -> Glib::RefPtr<StringSorter>
{
  return Glib::make_refptr_for_instance<StringSorter>( new StringSorter(expression) );
}

auto StringSorter::get_expression() -> Glib::RefPtr<Expression<Glib::ustring>>
{
  auto retvalue = Glib::wrap<Glib::ustring>(gtk_string_sorter_get_expression(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto StringSorter::get_expression() const -> Glib::RefPtr<const Expression<Glib::ustring>>
{
  auto retvalue = Glib::wrap<Glib::ustring>(gtk_string_sorter_get_expression(const_cast<GtkStringSorter*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto StringSorter::set_expression (
  const Glib::RefPtr <Expression <Glib::ustring>> &expression) -> void
{
  gtk_string_sorter_set_expression(gobj(), expression ? expression->gobj() : nullptr);
}

auto StringSorter::get_ignore_case() const -> bool
{
  return gtk_string_sorter_get_ignore_case(const_cast<GtkStringSorter*>(gobj()));
}

auto StringSorter::set_ignore_case (
  const bool ignore_case) -> void
{
  gtk_string_sorter_set_ignore_case(gobj(), ignore_case);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Expression<Glib::ustring>>>::value,
  "Type Glib::RefPtr<Expression<Glib::ustring>> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto StringSorter::property_expression() -> Glib::PropertyProxy< Glib::RefPtr<Expression<Glib::ustring>> >
{
  return {this, "expression"};
}

auto StringSorter::property_expression() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Expression<Glib::ustring>> >
{
  return {this, "expression"};
}

auto StringSorter::property_ignore_case() -> Glib::PropertyProxy< bool >
{
  return {this, "ignore-case"};
}

auto StringSorter::property_ignore_case() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "ignore-case"};
}


} // namespace Gtk


