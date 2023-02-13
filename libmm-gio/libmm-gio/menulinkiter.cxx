


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/menulinkiter.hxx>
#include <libmm-gio/menulinkiter_p.hxx>


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
#include <libmm-gio/menumodel.hxx>

namespace Gio
{

auto
MenuLinkIter::get_next(Glib::ustring& out_link, Glib::RefPtr<MenuModel>& value) -> bool
{
  const char* g_out_link = nullptr;
  GMenuModel* g_value = nullptr;

  bool const result = g_menu_link_iter_get_next(gobj(), &g_out_link, &g_value);
  out_link = g_out_link;
  value = Glib::wrap(g_value);

  return result;
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GMenuLinkIter* object, const bool take_copy) -> RefPtr<Gio::MenuLinkIter>
{
  return Glib::make_refptr_for_instance<Gio::MenuLinkIter>( dynamic_cast<Gio::MenuLinkIter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto MenuLinkIter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MenuLinkIter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_menu_link_iter_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto MenuLinkIter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MenuLinkIter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MenuLinkIter((GMenuLinkIter*)object);
}


/* The implementation: */

auto MenuLinkIter::gobj_copy() -> GMenuLinkIter*
{
  reference();
  return gobj();
}

MenuLinkIter::MenuLinkIter(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

MenuLinkIter::MenuLinkIter(GMenuLinkIter* castitem)
: Object((GObject*)castitem)
{}


MenuLinkIter::MenuLinkIter(MenuLinkIter&& src) noexcept
: Object(std::move(src))
{}

auto MenuLinkIter::operator=(MenuLinkIter&& src) noexcept -> MenuLinkIter&
{
  Object::operator=(std::move(src));
  return *this;
}


MenuLinkIter::~MenuLinkIter() noexcept = default;

MenuLinkIter::CppClassType MenuLinkIter::menulinkiter_class_; // initialize static member

auto MenuLinkIter::get_type() -> GType
{
  return menulinkiter_class_.init().get_type();
}


auto MenuLinkIter::get_base_type() -> GType
{
  return g_menu_link_iter_get_type();
}


MenuLinkIter::MenuLinkIter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(menulinkiter_class_.init()))
{


}

auto MenuLinkIter::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_menu_link_iter_get_name(const_cast<GMenuLinkIter*>(gobj())));
}

auto MenuLinkIter::get_value() -> Glib::RefPtr<MenuModel>
{
  return Glib::wrap(g_menu_link_iter_get_value(gobj()));
}

auto MenuLinkIter::get_value() const -> Glib::RefPtr<const MenuModel>
{
  return const_cast<MenuLinkIter*>(this)->get_value();
}

auto MenuLinkIter::next() -> bool
{
  return g_menu_link_iter_next(gobj());
}


} // namespace Gio

