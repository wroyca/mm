


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/appchooserdialog.hpp>
#include <mm/gtk/private/appchooserdialog_p.hpp>


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

AppChooserDialog::AppChooserDialog(const Glib::ustring& content_type)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Dialog(Glib::ConstructParams(appchooserdialog_class_.init(), "content_type",content_type.c_str(), nullptr))
{
}

AppChooserDialog::AppChooserDialog(const Glib::ustring& content_type, Window & parent)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Dialog(Glib::ConstructParams(appchooserdialog_class_.init(), "content_type",content_type.c_str(), nullptr))
{
  set_transient_for(parent);
}

AppChooserDialog::AppChooserDialog(const Glib::RefPtr<Gio::File>& file)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Dialog(Glib::ConstructParams(appchooserdialog_class_.init(), "gfile",Glib::unwrap(file), nullptr))
{
}

AppChooserDialog::AppChooserDialog(const Glib::RefPtr<Gio::File>& file, Window & parent)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Dialog(Glib::ConstructParams(appchooserdialog_class_.init(), "gfile",Glib::unwrap(file), nullptr))
{
  set_transient_for(parent);
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkAppChooserDialog* object, const bool take_copy) -> Gtk::AppChooserDialog*
{
  return dynamic_cast<Gtk::AppChooserDialog *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto AppChooserDialog_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AppChooserDialog_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_app_chooser_dialog_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  AppChooser::add_interface(get_type());

  }

  return *this;
}


auto AppChooserDialog_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AppChooserDialog_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new AppChooserDialog((GtkAppChooserDialog*)o); //top-level windows can not be manage()ed.

}


/* The implementation: */

AppChooserDialog::AppChooserDialog(const Glib::ConstructParams& construct_params)
:
  Dialog(construct_params)
{
  }

AppChooserDialog::AppChooserDialog(GtkAppChooserDialog* castitem)
:
  Dialog((GtkDialog*)castitem)
{
  }


AppChooserDialog::AppChooserDialog(AppChooserDialog&& src) noexcept
: Dialog(std::move(src))
  , AppChooser(std::move(src))
{}

auto AppChooserDialog::operator=(AppChooserDialog&& src) noexcept -> AppChooserDialog&
{
  Dialog::operator=(std::move(src));
  AppChooser::operator=(std::move(src));
  return *this;
}

AppChooserDialog::~AppChooserDialog() noexcept
{
  destroy_();
}

AppChooserDialog::CppClassType AppChooserDialog::appchooserdialog_class_; // initialize static member

auto AppChooserDialog::get_type() -> GType
{
  return appchooserdialog_class_.init().get_type();
}


auto AppChooserDialog::get_base_type() -> GType
{
  return gtk_app_chooser_dialog_get_type();
}


auto AppChooserDialog::get_widget() -> Widget*
{
  return Glib::wrap(gtk_app_chooser_dialog_get_widget(gobj()));
}

auto AppChooserDialog::get_widget() const -> const Widget*
{
  return const_cast<AppChooserDialog*>(this)->get_widget();
}

auto AppChooserDialog::set_heading (const Glib::ustring &heading) -> void
{
  gtk_app_chooser_dialog_set_heading(gobj(), heading.c_str());
}

auto AppChooserDialog::get_heading() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_app_chooser_dialog_get_heading(const_cast<GtkAppChooserDialog*>(gobj())));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::File>>::value,
  "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto AppChooserDialog::property_gfile() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::File> >
{
  return {this, "gfile"};
}

auto AppChooserDialog::property_heading() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "heading"};
}

auto AppChooserDialog::property_heading() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "heading"};
}


} // namespace Gtk


