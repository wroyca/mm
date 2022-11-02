// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/filefilter.h>
#include <mm/gtk/private/filefilter_p.h>


/* Copyright 2003 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkFileFilter* object, bool take_copy) -> Glib::RefPtr<Gtk::FileFilter>
{
  return Glib::make_refptr_for_instance<Gtk::FileFilter>( dynamic_cast<Gtk::FileFilter*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto FileFilter_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileFilter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_file_filter_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Buildable::add_interface(get_type());

  }

  return *this;
}


void FileFilter_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FileFilter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FileFilter((GtkFileFilter*)object);
}


/* The implementation: */

auto FileFilter::gobj_copy() -> GtkFileFilter*
{
  reference();
  return gobj();
}

FileFilter::FileFilter(const Glib::ConstructParams& construct_params)
:
  Gtk::Filter(construct_params)
{

}

FileFilter::FileFilter(GtkFileFilter* castitem)
:
  Gtk::Filter((GtkFilter*)(castitem))
{}


FileFilter::FileFilter(FileFilter&& src) noexcept
: Gtk::Filter(std::move(src))
  , Buildable(std::move(src))
{}

auto FileFilter::operator=(FileFilter&& src) noexcept -> FileFilter&
{
  Gtk::Filter::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}


FileFilter::~FileFilter() noexcept
{}


FileFilter::CppClassType FileFilter::filefilter_class_; // initialize static member

auto FileFilter::get_type() -> GType
{
  return filefilter_class_.init().get_type();
}


auto FileFilter::get_base_type() -> GType
{
  return gtk_file_filter_get_type();
}


FileFilter::FileFilter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Filter(Glib::ConstructParams(filefilter_class_.init()))
{


}

auto FileFilter::create() -> Glib::RefPtr<FileFilter>
{
  return Glib::make_refptr_for_instance<FileFilter>( new FileFilter() );
}

void FileFilter::set_name(const Glib::ustring& name)
{
  gtk_file_filter_set_name(gobj(), name.c_str());
}

auto FileFilter::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_file_filter_get_name(const_cast<GtkFileFilter*>(gobj())));
}

void FileFilter::add_mime_type(const Glib::ustring& mime_type)
{
  gtk_file_filter_add_mime_type(gobj(), mime_type.c_str());
}

void FileFilter::add_pattern(const Glib::ustring& pattern)
{
  gtk_file_filter_add_pattern(gobj(), pattern.c_str());
}

void FileFilter::add_suffix(const std::string& suffix)
{
  gtk_file_filter_add_suffix(gobj(), suffix.c_str());
}

void FileFilter::add_pixbuf_formats()
{
  gtk_file_filter_add_pixbuf_formats(gobj());
}


auto FileFilter::property_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "name");
}

auto FileFilter::property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "name");
}


} // namespace Gtk

