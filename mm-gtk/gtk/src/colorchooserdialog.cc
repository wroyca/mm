// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/colorchooserdialog.h>
#include <gtkmm/private/colorchooserdialog_p.h>


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
  Glib::ObjectBase(nullptr),
  Gtk::Dialog(Glib::ConstructParams(colorchooserdialog_class_.init(), "title",title.c_str(), nullptr))
{
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::ColorChooserDialog* wrap(GtkColorChooserDialog* object, bool take_copy)
{
  return dynamic_cast<Gtk::ColorChooserDialog *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& ColorChooserDialog_Class::init()
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


void ColorChooserDialog_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* ColorChooserDialog_Class::wrap_new(GObject* o)
{
  return new ColorChooserDialog((GtkColorChooserDialog*)(o)); //top-level windows can not be manage()ed.

}


/* The implementation: */

ColorChooserDialog::ColorChooserDialog(const Glib::ConstructParams& construct_params)
:
  Gtk::Dialog(construct_params)
{
  }

ColorChooserDialog::ColorChooserDialog(GtkColorChooserDialog* castitem)
:
  Gtk::Dialog((GtkDialog*)(castitem))
{
  }


ColorChooserDialog::ColorChooserDialog(ColorChooserDialog&& src) noexcept
: Gtk::Dialog(std::move(src))
{}

ColorChooserDialog& ColorChooserDialog::operator=(ColorChooserDialog&& src) noexcept
{
  Gtk::Dialog::operator=(std::move(src));
  return *this;
}

ColorChooserDialog::~ColorChooserDialog() noexcept
{
  destroy_();
}

ColorChooserDialog::CppClassType ColorChooserDialog::colorchooserdialog_class_; // initialize static member

GType ColorChooserDialog::get_type()
{
  return colorchooserdialog_class_.init().get_type();
}


GType ColorChooserDialog::get_base_type()
{
  return gtk_color_chooser_dialog_get_type();
}


ColorChooserDialog::ColorChooserDialog()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Dialog(Glib::ConstructParams(colorchooserdialog_class_.init()))
{
  

}

ColorChooserDialog::ColorChooserDialog(const Glib::ustring& title, Window& transient_for)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Dialog(Glib::ConstructParams(colorchooserdialog_class_.init(), "title", title.c_str(), "transient_for", (transient_for).gobj(), nullptr))
{
  

}


Glib::PropertyProxy< bool > ColorChooserDialog::property_show_editor() 
{
  return Glib::PropertyProxy< bool >(this, "show-editor");
}

Glib::PropertyProxy_ReadOnly< bool > ColorChooserDialog::property_show_editor() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "show-editor");
}


} // namespace Gtk


