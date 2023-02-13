


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/stringlist.hpp>
#include <mm/gtk/private/stringlist_p.hpp>


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

namespace Gtk
{

StringList::StringList(const std::vector<Glib::ustring>& strings)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(stringlist_class_.init()))
{
  gtk_string_list_splice(gobj(), 0, 0,
      Glib::ArrayHandler<Glib::ustring>::vector_to_array(strings).data());
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkStringList* object, const bool take_copy) -> RefPtr<Gtk::StringList>
{
  return Glib::make_refptr_for_instance<Gtk::StringList>( dynamic_cast<Gtk::StringList*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto StringList_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &StringList_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_string_list_get_type();

  }

  return *this;
}


auto StringList_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto StringList_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new StringList((GtkStringList*)object);
}


/* The implementation: */

auto StringList::gobj_copy() -> GtkStringList*
{
  reference();
  return gobj();
}

StringList::StringList(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

StringList::StringList(GtkStringList* castitem)
: Object((GObject*)castitem)
{}


StringList::StringList(StringList&& src) noexcept
: Object(std::move(src))
  ,
  ListModel(std::move(src))
  , Buildable(std::move(src))
{}

auto StringList::operator=(StringList&& src) noexcept -> StringList&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}


StringList::~StringList() noexcept = default;

StringList::CppClassType StringList::stringlist_class_; // initialize static member

auto StringList::get_type() -> GType
{
  return stringlist_class_.init().get_type();
}


auto StringList::get_base_type() -> GType
{
  return gtk_string_list_get_type();
}


auto StringList::create(const std::vector<Glib::ustring>& strings) -> Glib::RefPtr<StringList>
{
  return Glib::make_refptr_for_instance<StringList>( new StringList(strings) );
}

auto StringList::append (const Glib::ustring &string) -> void
{
  gtk_string_list_append(gobj(), string.c_str());
}

auto StringList::remove (
  const guint position) -> void
{
  gtk_string_list_remove(gobj(), position);
}

auto StringList::splice (
  const guint position, const guint n_removals, const std::vector <Glib::ustring> &additions) -> void
{
  gtk_string_list_splice(gobj(), position, n_removals, Glib::ArrayHandler<Glib::ustring>::vector_to_array(additions).data());
}

auto StringList::get_string(
  const guint position) const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_string_list_get_string(const_cast<GtkStringList*>(gobj()), position));
}


} // namespace Gtk


