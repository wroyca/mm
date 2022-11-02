/* Copyright (C) 2006 The gtkmm Development Team
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

#ifndef _WIN32

#include <mm/glib/mm-glib.h>

#include <mm/gtk/pagesetupunixdialog.h>
#include <mm/gtk/private/pagesetupunixdialog_p.h>

#include <gtk/gtkunixprint.h>

namespace Gtk
{

PageSetupUnixDialog::PageSetupUnixDialog(Gtk::Window& parent, const Glib::ustring& title)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Dialog(Glib::ConstructParams(pagesetupunixdialog_class_.init(), "title",title.c_str(), nullptr))
{
  set_transient_for(parent);
}

PageSetupUnixDialog::PageSetupUnixDialog(const Glib::ustring& title)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Dialog(Glib::ConstructParams(pagesetupunixdialog_class_.init(), "title",title.c_str(), nullptr))
{
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkPageSetupUnixDialog* object, bool take_copy) -> Gtk::PageSetupUnixDialog*
{
  return dynamic_cast<Gtk::PageSetupUnixDialog *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto PageSetupUnixDialog_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PageSetupUnixDialog_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_page_setup_unix_dialog_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void PageSetupUnixDialog_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto PageSetupUnixDialog_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new PageSetupUnixDialog((GtkPageSetupUnixDialog*)(o)); //top-level windows can not be manage()ed.

}


/* The implementation: */

PageSetupUnixDialog::PageSetupUnixDialog(const Glib::ConstructParams& construct_params)
:
  Gtk::Dialog(construct_params)
{
  }

PageSetupUnixDialog::PageSetupUnixDialog(GtkPageSetupUnixDialog* castitem)
:
  Gtk::Dialog((GtkDialog*)(castitem))
{
  }


PageSetupUnixDialog::PageSetupUnixDialog(PageSetupUnixDialog&& src) noexcept
: Gtk::Dialog(std::move(src))
{}

auto PageSetupUnixDialog::operator=(PageSetupUnixDialog&& src) noexcept -> PageSetupUnixDialog&
{
  Gtk::Dialog::operator=(std::move(src));
  return *this;
}

PageSetupUnixDialog::~PageSetupUnixDialog() noexcept
{
  destroy_();
}

PageSetupUnixDialog::CppClassType PageSetupUnixDialog::pagesetupunixdialog_class_; // initialize static member

auto PageSetupUnixDialog::get_type() -> GType
{
  return pagesetupunixdialog_class_.init().get_type();
}


auto PageSetupUnixDialog::get_base_type() -> GType
{
  return gtk_page_setup_unix_dialog_get_type();
}


void PageSetupUnixDialog::set_page_setup(const Glib::RefPtr<PageSetup>& page_setup)
{
  gtk_page_setup_unix_dialog_set_page_setup(gobj(), Glib::unwrap(page_setup));
}

auto PageSetupUnixDialog::get_page_setup() -> Glib::RefPtr<PageSetup>
{
  auto retvalue = Glib::wrap(gtk_page_setup_unix_dialog_get_page_setup(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PageSetupUnixDialog::get_page_setup() const -> Glib::RefPtr<const PageSetup>
{
  return const_cast<PageSetupUnixDialog*>(this)->get_page_setup();
}

void PageSetupUnixDialog::set_print_settings(const Glib::RefPtr<PrintSettings>& print_settings)
{
  gtk_page_setup_unix_dialog_set_print_settings(gobj(), Glib::unwrap(print_settings));
}

auto PageSetupUnixDialog::get_print_settings() -> Glib::RefPtr<PrintSettings>
{
  auto retvalue = Glib::wrap(gtk_page_setup_unix_dialog_get_print_settings(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PageSetupUnixDialog::get_print_settings() const -> Glib::RefPtr<const PrintSettings>
{
  return const_cast<PageSetupUnixDialog*>(this)->get_print_settings();
}

} // namespace Gtk

#endif // _WIN32
