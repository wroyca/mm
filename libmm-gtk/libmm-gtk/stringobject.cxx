


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/stringobject.hxx>
#include <libmm-gtk/stringobject_p.hxx>


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

auto wrap(GtkStringObject* object, const bool take_copy) -> RefPtr<Gtk::StringObject>
{
  return Glib::make_refptr_for_instance<Gtk::StringObject>( dynamic_cast<Gtk::StringObject*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto StringObject_Class::init() -> const Class&
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


auto StringObject_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto StringObject_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new StringObject((GtkStringObject*)object);
}


/* The implementation: */

auto StringObject::gobj_copy() -> GtkStringObject*
{
  reference();
  return gobj();
}

StringObject::StringObject(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

StringObject::StringObject(GtkStringObject* castitem)
: Object((GObject*)castitem)
{}


StringObject::StringObject(StringObject&& src) noexcept
: Object(std::move(src))
{}

auto StringObject::operator=(StringObject&& src) noexcept -> StringObject&
{
  Object::operator=(std::move(src));
  return *this;
}


StringObject::~StringObject() noexcept = default;

StringObject::CppClassType StringObject::stringobject_class_; // initialize static member

auto StringObject::get_type() -> GType
{
  return stringobject_class_.init().get_type();
}


auto StringObject::get_base_type() -> GType
{
  return gtk_string_object_get_type();
}


auto StringObject::create(const Glib::ustring& string) -> Glib::RefPtr<StringObject>
{
  return Glib::wrap(gtk_string_object_new(string.c_str()));
}

auto StringObject::get_string() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_string_object_get_string(const_cast<GtkStringObject*>(gobj())));
}


auto StringObject::property_string() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "string"};
}


} // namespace Gtk


