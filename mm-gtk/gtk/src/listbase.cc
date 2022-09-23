// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/listbase.h>
#include <gtkmm/private/listbase_p.h>


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

Gtk::ListBase* wrap(GtkListBase* object, bool take_copy)
{
  return dynamic_cast<Gtk::ListBase *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& ListBase_Class::init()
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


void ListBase_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* ListBase_Class::wrap_new(GObject* o)
{
  return manage(new ListBase((GtkListBase*)(o)));

}


/* The implementation: */

ListBase::ListBase(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

ListBase::ListBase(GtkListBase* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


ListBase::ListBase(ListBase&& src) noexcept
: Gtk::Widget(std::move(src))
  , Orientable(std::move(src))
  , Scrollable(std::move(src))
{}

ListBase& ListBase::operator=(ListBase&& src) noexcept
{
  Gtk::Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  Scrollable::operator=(std::move(src));
  return *this;
}

ListBase::~ListBase() noexcept
{
  destroy_();
}

ListBase::CppClassType ListBase::listbase_class_; // initialize static member

GType ListBase::get_type()
{
  return listbase_class_.init().get_type();
}


GType ListBase::get_base_type()
{
  return gtk_list_base_get_type();
}


} // namespace Gtk


