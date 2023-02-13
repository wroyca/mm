


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/menuattributeiter.hpp>
#include <libmm-gio/menuattributeiter_p.hpp>


/* Copyright (C) 2012 The giomm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>

namespace Gio
{

auto
MenuAttributeIter::get_next(Glib::ustring& out_name, Glib::VariantBase& value) -> bool
{
  const char* g_out_name = nullptr;
  GVariant* g_value = nullptr;

  bool const result = g_menu_attribute_iter_get_next(gobj(), &g_out_name, &g_value);

  out_name = g_out_name;
  value.init(g_value);

  return result;
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GMenuAttributeIter* object, const bool take_copy) -> RefPtr<Gio::MenuAttributeIter>
{
  return Glib::make_refptr_for_instance<Gio::MenuAttributeIter>( dynamic_cast<Gio::MenuAttributeIter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto MenuAttributeIter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MenuAttributeIter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_menu_attribute_iter_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto MenuAttributeIter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MenuAttributeIter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MenuAttributeIter((GMenuAttributeIter*)object);
}


/* The implementation: */

auto MenuAttributeIter::gobj_copy() -> GMenuAttributeIter*
{
  reference();
  return gobj();
}

MenuAttributeIter::MenuAttributeIter(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

MenuAttributeIter::MenuAttributeIter(GMenuAttributeIter* castitem)
: Object((GObject*)castitem)
{}


MenuAttributeIter::MenuAttributeIter(MenuAttributeIter&& src) noexcept
: Object(std::move(src))
{}

auto MenuAttributeIter::operator=(MenuAttributeIter&& src) noexcept -> MenuAttributeIter&
{
  Object::operator=(std::move(src));
  return *this;
}


MenuAttributeIter::~MenuAttributeIter() noexcept = default;

MenuAttributeIter::CppClassType MenuAttributeIter::menuattributeiter_class_; // initialize static member

auto MenuAttributeIter::get_type() -> GType
{
  return menuattributeiter_class_.init().get_type();
}


auto MenuAttributeIter::get_base_type() -> GType
{
  return g_menu_attribute_iter_get_type();
}


MenuAttributeIter::MenuAttributeIter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(menuattributeiter_class_.init()))
{


}

auto MenuAttributeIter::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_menu_attribute_iter_get_name(const_cast<GMenuAttributeIter*>(gobj())));
}

auto MenuAttributeIter::get_value() const -> Glib::VariantBase
{
  return Glib::wrap(g_menu_attribute_iter_get_value(const_cast<GMenuAttributeIter*>(gobj())), false);
}

auto MenuAttributeIter::next() -> bool
{
  return g_menu_attribute_iter_next(gobj());
}


} // namespace Gio


