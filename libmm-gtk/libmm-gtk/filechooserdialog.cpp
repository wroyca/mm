


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/filechooserdialog.hpp>
#include <mm/gtk/private/filechooserdialog_p.hpp>


/*
 * Copyright 2003 The gtkmm Development Team
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


namespace Gtk
{

FileChooserDialog::FileChooserDialog(Window & parent, const Glib::ustring& title, const Action action, const bool use_header_bar)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Dialog(Glib::ConstructParams(filechooserdialog_class_.init(), "title",title.c_str(),"action",action,"use-header-bar",use_header_bar, nullptr))
{
  set_transient_for(parent);
}

FileChooserDialog::FileChooserDialog(const Glib::ustring& title, const Action action, const bool use_header_bar)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Dialog(Glib::ConstructParams(filechooserdialog_class_.init(), "title",title.c_str(),"action",action,"use-header-bar",use_header_bar, nullptr))
{
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkFileChooserDialog* object, const bool take_copy) -> Gtk::FileChooserDialog*
{
  return dynamic_cast<Gtk::FileChooserDialog *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto FileChooserDialog_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileChooserDialog_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_file_chooser_dialog_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  FileChooser::add_interface(get_type());

  }

  return *this;
}


auto FileChooserDialog_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FileChooserDialog_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new FileChooserDialog((GtkFileChooserDialog*)o); //top-level windows can not be manage()ed.

}


/* The implementation: */

FileChooserDialog::FileChooserDialog(const Glib::ConstructParams& construct_params)
: Dialog(construct_params)
{
  }

FileChooserDialog::FileChooserDialog(GtkFileChooserDialog* castitem)
: Dialog((GtkDialog*)castitem)
{
  }


FileChooserDialog::FileChooserDialog(FileChooserDialog&& src) noexcept
: Dialog(std::move(src))
  , FileChooser(std::move(src))
{}

auto FileChooserDialog::operator=(FileChooserDialog&& src) noexcept -> FileChooserDialog&
{
  Dialog::operator=(std::move(src));
  FileChooser::operator=(std::move(src));
  return *this;
}

FileChooserDialog::~FileChooserDialog() noexcept
{
  destroy_();
}

FileChooserDialog::CppClassType FileChooserDialog::filechooserdialog_class_; // initialize static member

auto FileChooserDialog::get_type() -> GType
{
  return filechooserdialog_class_.init().get_type();
}


auto FileChooserDialog::get_base_type() -> GType
{
  return gtk_file_chooser_dialog_get_type();
}


} // namespace Gtk


