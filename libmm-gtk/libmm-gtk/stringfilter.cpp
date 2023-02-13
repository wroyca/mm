


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/stringfilter.hpp>
#include <mm/gtk/private/stringfilter_p.hpp>


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

using MatchMode = Gtk::StringFilter::MatchMode;

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::StringFilter::MatchMode>::value_type() -> GType
{
  return gtk_string_filter_match_mode_get_type();
}


namespace Glib
{

auto wrap(GtkStringFilter* object, const bool take_copy) -> RefPtr<Gtk::StringFilter>
{
  return Glib::make_refptr_for_instance<Gtk::StringFilter>( dynamic_cast<Gtk::StringFilter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto StringFilter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &StringFilter_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_string_filter_get_type();

  }

  return *this;
}


auto StringFilter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto StringFilter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new StringFilter((GtkStringFilter*)object);
}


/* The implementation: */

auto StringFilter::gobj_copy() -> GtkStringFilter*
{
  reference();
  return gobj();
}

StringFilter::StringFilter(const Glib::ConstructParams& construct_params)
: Filter(construct_params)
{

}

StringFilter::StringFilter(GtkStringFilter* castitem)
: Filter((GtkFilter*)castitem)
{}


StringFilter::StringFilter(StringFilter&& src) noexcept
: Filter(std::move(src))
{}

auto StringFilter::operator=(StringFilter&& src) noexcept -> StringFilter&
{
  Filter::operator=(std::move(src));
  return *this;
}


StringFilter::~StringFilter() noexcept = default;

StringFilter::CppClassType StringFilter::stringfilter_class_; // initialize static member

auto StringFilter::get_type() -> GType
{
  return stringfilter_class_.init().get_type();
}


auto StringFilter::get_base_type() -> GType
{
  return gtk_string_filter_get_type();
}


StringFilter::StringFilter(const Glib::RefPtr<Expression<Glib::ustring>>& expression)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Filter(Glib::ConstructParams(stringfilter_class_.init(), "expression", expression ? expression->gobj() : nullptr, nullptr))
{


}

auto StringFilter::create(const Glib::RefPtr<Expression<Glib::ustring>>& expression) -> Glib::RefPtr<StringFilter>
{
  return Glib::make_refptr_for_instance<StringFilter>( new StringFilter(expression) );
}

auto StringFilter::get_search() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_string_filter_get_search(const_cast<GtkStringFilter*>(gobj())));
}

auto StringFilter::set_search (const Glib::ustring &search) -> void
{
  gtk_string_filter_set_search(gobj(), search.c_str());
}

auto StringFilter::get_expression() -> Glib::RefPtr<Expression<Glib::ustring>>
{
  auto retvalue = Glib::wrap<Glib::ustring>(gtk_string_filter_get_expression(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto StringFilter::get_expression() const -> Glib::RefPtr<const Expression<Glib::ustring>>
{
  auto retvalue = Glib::wrap<Glib::ustring>(gtk_string_filter_get_expression(const_cast<GtkStringFilter*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto StringFilter::set_expression (
  const Glib::RefPtr <Expression <Glib::ustring>> &expression) -> void
{
  gtk_string_filter_set_expression(gobj(), expression ? expression->gobj() : nullptr);
}

auto StringFilter::get_ignore_case() const -> bool
{
  return gtk_string_filter_get_ignore_case(const_cast<GtkStringFilter*>(gobj()));
}

auto StringFilter::set_ignore_case (
  const bool ignore_case) -> void
{
  gtk_string_filter_set_ignore_case(gobj(), ignore_case);
}

auto StringFilter::get_match_mode() const -> MatchMode
{
  return static_cast<MatchMode>(gtk_string_filter_get_match_mode(const_cast<GtkStringFilter*>(gobj())));
}

auto StringFilter::set_match_mode (MatchMode mode) -> void
{
  gtk_string_filter_set_match_mode(gobj(), static_cast<GtkStringFilterMatchMode>(mode));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Expression<Glib::ustring>>>::value,
  "Type Glib::RefPtr<Expression<Glib::ustring>> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto StringFilter::property_expression() -> Glib::PropertyProxy< Glib::RefPtr<Expression<Glib::ustring>> >
{
  return {this, "expression"};
}

auto StringFilter::property_expression() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Expression<Glib::ustring>> >
{
  return {this, "expression"};
}

auto StringFilter::property_ignore_case() -> Glib::PropertyProxy< bool >
{
  return {this, "ignore-case"};
}

auto StringFilter::property_ignore_case() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "ignore-case"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<MatchMode>::value,
  "Type MatchMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto StringFilter::property_match_mode() -> Glib::PropertyProxy< MatchMode >
{
  return {this, "match-mode"};
}

auto StringFilter::property_match_mode() const -> Glib::PropertyProxy_ReadOnly< MatchMode >
{
  return {this, "match-mode"};
}

auto StringFilter::property_search() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "search"};
}

auto StringFilter::property_search() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "search"};
}


} // namespace Gtk


