


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/fontchooserdialog.hxx>
#include <libmm-gtk/fontchooserdialog_p.hxx>


/* Copyright 2011 The gtkmm Development Team
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

FontChooserDialog::FontChooserDialog(const Glib::ustring& title)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Dialog(Glib::ConstructParams(fontchooserdialog_class_.init(), "title",title.c_str(), nullptr))
{
}


} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkFontChooserDialog* object, const bool take_copy) -> Gtk::FontChooserDialog*
{
  return dynamic_cast<Gtk::FontChooserDialog *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto FontChooserDialog_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FontChooserDialog_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_font_chooser_dialog_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  FontChooser::add_interface(get_type());

  }

  return *this;
}


auto FontChooserDialog_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FontChooserDialog_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new FontChooserDialog((GtkFontChooserDialog*)o); //top-level windows can not be manage()ed.

}


/* The implementation: */

FontChooserDialog::FontChooserDialog(const Glib::ConstructParams& construct_params)
: Dialog(construct_params)
{
  }

FontChooserDialog::FontChooserDialog(GtkFontChooserDialog* castitem)
: Dialog((GtkDialog*)castitem)
{
  }


FontChooserDialog::FontChooserDialog(FontChooserDialog&& src) noexcept
: Dialog(std::move(src))
  , FontChooser(std::move(src))
{}

auto FontChooserDialog::operator=(FontChooserDialog&& src) noexcept -> FontChooserDialog&
{
  Dialog::operator=(std::move(src));
  FontChooser::operator=(std::move(src));
  return *this;
}

FontChooserDialog::~FontChooserDialog() noexcept
{
  destroy_();
}

FontChooserDialog::CppClassType FontChooserDialog::fontchooserdialog_class_; // initialize static member

auto FontChooserDialog::get_type() -> GType
{
  return fontchooserdialog_class_.init().get_type();
}


auto FontChooserDialog::get_base_type() -> GType
{
  return gtk_font_chooser_dialog_get_type();
}


FontChooserDialog::FontChooserDialog()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Dialog(Glib::ConstructParams(fontchooserdialog_class_.init()))
{


}

FontChooserDialog::FontChooserDialog(const Glib::ustring& title, Window& transient_for)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Dialog(Glib::ConstructParams(fontchooserdialog_class_.init(), "title", title.c_str(), "transient_for", transient_for.gobj(), nullptr))
{


}


} // namespace Gtk

