


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/colorchooserdialog.hpp>
#include <mm/gtk/private/colorchooserdialog_p.hpp>


/* Copyright 2012 The gtkmm Development Team
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

ColorChooserDialog::ColorChooserDialog(const Glib::ustring& title)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Dialog(Glib::ConstructParams(colorchooserdialog_class_.init(), "title",title.c_str(), nullptr))
{
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkColorChooserDialog* object, const bool take_copy) -> Gtk::ColorChooserDialog*
{
  return dynamic_cast<Gtk::ColorChooserDialog *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ColorChooserDialog_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ColorChooserDialog_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_color_chooser_dialog_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ColorChooserDialog_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ColorChooserDialog_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new ColorChooserDialog((GtkColorChooserDialog*)o); //top-level windows can not be manage()ed.

}


/* The implementation: */

ColorChooserDialog::ColorChooserDialog(const Glib::ConstructParams& construct_params)
: Dialog(construct_params)
{
  }

ColorChooserDialog::ColorChooserDialog(GtkColorChooserDialog* castitem)
: Dialog((GtkDialog*)castitem)
{
  }


ColorChooserDialog::ColorChooserDialog(ColorChooserDialog&& src) noexcept
: Dialog(std::move(src))
{}

auto ColorChooserDialog::operator=(ColorChooserDialog&& src) noexcept -> ColorChooserDialog&
{
  Dialog::operator=(std::move(src));
  return *this;
}

ColorChooserDialog::~ColorChooserDialog() noexcept
{
  destroy_();
}

ColorChooserDialog::CppClassType ColorChooserDialog::colorchooserdialog_class_; // initialize static member

auto ColorChooserDialog::get_type() -> GType
{
  return colorchooserdialog_class_.init().get_type();
}


auto ColorChooserDialog::get_base_type() -> GType
{
  return gtk_color_chooser_dialog_get_type();
}


ColorChooserDialog::ColorChooserDialog()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Dialog(Glib::ConstructParams(colorchooserdialog_class_.init()))
{


}

ColorChooserDialog::ColorChooserDialog(const Glib::ustring& title, Window& transient_for)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Dialog(Glib::ConstructParams(colorchooserdialog_class_.init(), "title", title.c_str(), "transient_for", transient_for.gobj(), nullptr))
{


}


auto ColorChooserDialog::property_show_editor() -> Glib::PropertyProxy< bool >
{
  return {this, "show-editor"};
}

auto ColorChooserDialog::property_show_editor() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-editor"};
}


} // namespace Gtk


