


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/listbase.hpp>
#include <mm/gtk/private/listbase_p.hpp>


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

auto wrap(GtkListBase* object, const bool take_copy) -> Gtk::ListBase*
{
  return dynamic_cast<Gtk::ListBase *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ListBase_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ListBase_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_list_base_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());
  Scrollable::add_interface(get_type());

  }

  return *this;
}


auto ListBase_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ListBase_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ListBase((GtkListBase*)o));

}


/* The implementation: */

ListBase::ListBase(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

ListBase::ListBase(GtkListBase* castitem)
: Widget((GtkWidget*)castitem)
{
  }


ListBase::ListBase(ListBase&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
  , Scrollable(std::move(src))
{}

auto ListBase::operator=(ListBase&& src) noexcept -> ListBase&
{
  Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  Scrollable::operator=(std::move(src));
  return *this;
}

ListBase::~ListBase() noexcept
{
  destroy_();
}

ListBase::CppClassType ListBase::listbase_class_; // initialize static member

auto ListBase::get_type() -> GType
{
  return listbase_class_.init().get_type();
}


auto ListBase::get_base_type() -> GType
{
  return gtk_list_base_get_type();
}


} // namespace Gtk


