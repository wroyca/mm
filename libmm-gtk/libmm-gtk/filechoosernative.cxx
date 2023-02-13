


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/filechoosernative.hxx>
#include <libmm-gtk/filechoosernative_p.hxx>


/* Copyright (C) 2017 The gtkmm Development Team
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
#include <libmm-gtk/window.hxx>

namespace Gtk
{

FileChooserNative::FileChooserNative(const Glib::ustring& title, Window& parent, const Action action,
  const Glib::ustring& accept_label, const Glib::ustring& cancel_label)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  NativeDialog(Glib::ConstructParams(filechoosernative_class_.init(), "title",title.c_str(),"transient-for",parent.gobj(),"action",action,"accept_label", c_str_or_nullptr(accept_label),"cancel_label", c_str_or_nullptr(cancel_label), nullptr))
{
}

FileChooserNative::FileChooserNative(const Glib::ustring& title, const Action action,
  const Glib::ustring& accept_label, const Glib::ustring& cancel_label)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  NativeDialog(Glib::ConstructParams(filechoosernative_class_.init(), "title",title.c_str(),"action",action,"accept_label", c_str_or_nullptr(accept_label),"cancel_label", c_str_or_nullptr(cancel_label), nullptr))
{
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkFileChooserNative* object, const bool take_copy) -> RefPtr<Gtk::FileChooserNative>
{
  return Glib::make_refptr_for_instance<Gtk::FileChooserNative>( dynamic_cast<Gtk::FileChooserNative*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto FileChooserNative_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileChooserNative_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_file_chooser_native_get_type();

  }

  return *this;
}


auto FileChooserNative_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FileChooserNative_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FileChooserNative((GtkFileChooserNative*)object);
}


/* The implementation: */

auto FileChooserNative::gobj_copy() -> GtkFileChooserNative*
{
  reference();
  return gobj();
}

FileChooserNative::FileChooserNative(const Glib::ConstructParams& construct_params)
:
  NativeDialog(construct_params)
{

}

FileChooserNative::FileChooserNative(GtkFileChooserNative* castitem)
:
  NativeDialog((GtkNativeDialog*)castitem)
{}


FileChooserNative::FileChooserNative(FileChooserNative&& src) noexcept
: NativeDialog(std::move(src))
  , FileChooser(std::move(src))
{}

auto FileChooserNative::operator=(FileChooserNative&& src) noexcept -> FileChooserNative&
{
  NativeDialog::operator=(std::move(src));
  FileChooser::operator=(std::move(src));
  return *this;
}


FileChooserNative::~FileChooserNative() noexcept = default;

FileChooserNative::CppClassType FileChooserNative::filechoosernative_class_; // initialize static member

auto FileChooserNative::get_type() -> GType
{
  return filechoosernative_class_.init().get_type();
}


auto FileChooserNative::get_base_type() -> GType
{
  return gtk_file_chooser_native_get_type();
}


FileChooserNative::FileChooserNative()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  NativeDialog(Glib::ConstructParams(filechoosernative_class_.init()))
{


}

auto FileChooserNative::create(const Glib::ustring& title, Window& parent, const Action action, const Glib::ustring& accept_label, const Glib::ustring& cancel_label) -> Glib::RefPtr<FileChooserNative>
{
  return Glib::make_refptr_for_instance<FileChooserNative>( new FileChooserNative(title, parent, action, accept_label, cancel_label) );
}

auto FileChooserNative::create(const Glib::ustring& title, const Action action, const Glib::ustring& accept_label, const Glib::ustring& cancel_label) -> Glib::RefPtr<FileChooserNative>
{
  return Glib::make_refptr_for_instance<FileChooserNative>( new FileChooserNative(title, action, accept_label, cancel_label) );
}

auto FileChooserNative::get_accept_label() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_file_chooser_native_get_accept_label(const_cast<GtkFileChooserNative*>(gobj())));
}

auto FileChooserNative::set_accept_label (const Glib::ustring &accept_label) -> void
{
  gtk_file_chooser_native_set_accept_label(gobj(), accept_label.empty() ? nullptr : accept_label.c_str());
}

auto FileChooserNative::get_cancel_label() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_file_chooser_native_get_cancel_label(const_cast<GtkFileChooserNative*>(gobj())));
}

auto FileChooserNative::set_cancel_label (const Glib::ustring &cancel_label) -> void
{
  gtk_file_chooser_native_set_cancel_label(gobj(), cancel_label.empty() ? nullptr : cancel_label.c_str());
}


auto FileChooserNative::property_accept_label() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "accept-label"};
}

auto FileChooserNative::property_accept_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "accept-label"};
}

auto FileChooserNative::property_cancel_label() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "cancel-label"};
}

auto FileChooserNative::property_cancel_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "cancel-label"};
}


} // namespace Gtk


