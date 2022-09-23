// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/stringobject.h>
#include <gtkmm/private/stringobject_p.h>


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

Glib::RefPtr<Gtk::StringObject> wrap(GtkStringObject* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gtk::StringObject>( dynamic_cast<Gtk::StringObject*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& StringObject_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &StringObject_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_string_object_get_type();

  }

  return *this;
}


void StringObject_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* StringObject_Class::wrap_new(GObject* object)
{
  return new StringObject((GtkStringObject*)object);
}


/* The implementation: */

GtkStringObject* StringObject::gobj_copy()
{
  reference();
  return gobj();
}

StringObject::StringObject(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

StringObject::StringObject(GtkStringObject* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


StringObject::StringObject(StringObject&& src) noexcept
: Glib::Object(std::move(src))
{}

StringObject& StringObject::operator=(StringObject&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


StringObject::~StringObject() noexcept
{}


StringObject::CppClassType StringObject::stringobject_class_; // initialize static member

GType StringObject::get_type()
{
  return stringobject_class_.init().get_type();
}


GType StringObject::get_base_type()
{
  return gtk_string_object_get_type();
}


Glib::RefPtr<StringObject> StringObject::create(const Glib::ustring& string)
{
  return Glib::wrap(gtk_string_object_new(string.c_str()));
}

Glib::ustring StringObject::get_string() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_string_object_get_string(const_cast<GtkStringObject*>(gobj())));
}


Glib::PropertyProxy_ReadOnly< Glib::ustring > StringObject::property_string() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "string");
}


} // namespace Gtk


