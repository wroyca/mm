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

#include <mm/gtk/printer.h>
#include <mm/gtk/private/printer_p.h>
#include <mm/glib/vectorutils.h>
#include <mm/gtk/papersize.h>

#include <gtk/gtkunixprint.h>

// This Signal Proxy allows the C++ coder to specify a sigc::slot instead of a static function.

static auto SignalProxy_Custom_gtk_callback(GtkPrinter* gtk_printer, gpointer data) -> gboolean
{
  const auto the_slot = static_cast<Gtk::SlotPrinterEnumerator*>(data);

  try
  {
    // Create a suitable C++ instance to pass to the C++ method;
    auto printer = Glib::wrap(gtk_printer, true);

    return (*the_slot)(printer);
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
    return false; // arbitrary default;
  }
}

static void SignalProxy_Custom_gtk_callback_destroy(void* data)
{
  delete static_cast<Gtk::SlotPrinterEnumerator*>(data);
}

namespace Gtk
{

auto Printer::equal(const Glib::RefPtr<Printer>& other) const -> bool
{
  return (static_cast<bool>(gtk_printer_compare(const_cast<GtkPrinter*>(this->gobj()),
                                                const_cast<GtkPrinter*>(other->gobj()))));
}

void enumerate_printers(const SlotPrinterEnumerator& slot, bool wait)
{
  // Create a copy of the slot. A pointer to this will be passed through the callback's data parameter.
  // It will be deleted when SignalProxy_Custom_gtk_callback_destroy() is called.
  auto slot_copy = new SlotPrinterEnumerator(slot);

  gtk_enumerate_printers(&SignalProxy_Custom_gtk_callback,
                         slot_copy,
                         &SignalProxy_Custom_gtk_callback_destroy,
                         static_cast<int>(wait));
}

} // namespace Gtk

namespace
{


void Printer_signal_details_acquired_callback(GtkPrinter* self, gboolean p0,void* data)
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(bool)>;

  auto obj = dynamic_cast<Printer*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Printer_signal_details_acquired_info =
{
  "details_acquired",
  (GCallback) &Printer_signal_details_acquired_callback,
  (GCallback) &Printer_signal_details_acquired_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::PrintCapabilities>::value_type() -> GType
{
  return gtk_print_capabilities_get_type();
}


namespace Glib
{

auto wrap(GtkPrinter* object, bool take_copy) -> Glib::RefPtr<Gtk::Printer>
{
  return Glib::make_refptr_for_instance<Gtk::Printer>( dynamic_cast<Gtk::Printer*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto Printer_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Printer_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_printer_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Printer_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Printer_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Printer((GtkPrinter*)object);
}


/* The implementation: */

auto Printer::gobj_copy() -> GtkPrinter*
{
  reference();
  return gobj();
}

Printer::Printer(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Printer::Printer(GtkPrinter* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Printer::Printer(Printer&& src) noexcept
: Glib::Object(std::move(src))
{}

auto Printer::operator=(Printer&& src) noexcept -> Printer&
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


Printer::~Printer() noexcept
{}


Printer::CppClassType Printer::printer_class_; // initialize static member

auto Printer::get_type() -> GType
{
  return printer_class_.init().get_type();
}


auto Printer::get_base_type() -> GType
{
  return gtk_printer_get_type();
}


auto Printer::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_printer_get_name(const_cast<GtkPrinter*>(gobj())));
}

auto Printer::get_state_message() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_printer_get_state_message(const_cast<GtkPrinter*>(gobj())));
}

auto Printer::get_description() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_printer_get_description(const_cast<GtkPrinter*>(gobj())));
}

auto Printer::get_location() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_printer_get_location(const_cast<GtkPrinter*>(gobj())));
}

auto Printer::get_icon_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_printer_get_icon_name(const_cast<GtkPrinter*>(gobj())));
}

auto Printer::get_job_count() const -> int
{
  return gtk_printer_get_job_count(const_cast<GtkPrinter*>(gobj()));
}

auto Printer::is_active() const -> bool
{
  return gtk_printer_is_active(const_cast<GtkPrinter*>(gobj()));
}

auto Printer::is_paused() const -> bool
{
  return gtk_printer_is_paused(const_cast<GtkPrinter*>(gobj()));
}

auto Printer::is_accepting_jobs() const -> bool
{
  return gtk_printer_is_accepting_jobs(const_cast<GtkPrinter*>(gobj()));
}

auto Printer::is_virtual() const -> bool
{
  return gtk_printer_is_virtual(const_cast<GtkPrinter*>(gobj()));
}

auto Printer::is_default() const -> bool
{
  return gtk_printer_is_default(const_cast<GtkPrinter*>(gobj()));
}

auto Printer::accepts_pdf() const -> bool
{
  return gtk_printer_accepts_pdf(const_cast<GtkPrinter*>(gobj()));
}

auto Printer::accepts_ps() const -> bool
{
  return gtk_printer_accepts_ps(const_cast<GtkPrinter*>(gobj()));
}

auto Printer::list_papers() -> std::vector< Glib::RefPtr<PageSetup> >
{
  return Glib::ListHandler< Glib::RefPtr<PageSetup> >::list_to_vector(gtk_printer_list_papers(gobj()), Glib::OWNERSHIP_DEEP);
}

auto Printer::get_default_page_size() const -> Glib::RefPtr<PageSetup>
{
  auto retvalue = Glib::wrap(gtk_printer_get_default_page_size(const_cast<GtkPrinter*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Printer::list_papers() const -> std::vector< Glib::RefPtr<const PageSetup> >
{
  return Glib::ListHandler< Glib::RefPtr<const PageSetup> >::list_to_vector(gtk_printer_list_papers(const_cast<GtkPrinter*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto Printer::has_details() const -> bool
{
  return gtk_printer_has_details(const_cast<GtkPrinter*>(gobj()));
}

void Printer::request_details()
{
  gtk_printer_request_details(gobj());
}

auto Printer::get_capabilities() const -> PrintCapabilities
{
  return static_cast<PrintCapabilities>(gtk_printer_get_capabilities(const_cast<GtkPrinter*>(gobj())));
}

auto Printer::get_hard_margins(double& top, double& bottom, double& left, double& right) const -> bool
{
  return gtk_printer_get_hard_margins(const_cast<GtkPrinter*>(gobj()), &(top), &(bottom), &(left), &(right));
}

auto Printer::get_hard_margins(const PaperSize& paper_size, double& top, double& bottom, double& left, double& right) const -> bool
{
  return gtk_printer_get_hard_margins_for_paper_size(const_cast<GtkPrinter*>(gobj()), const_cast<GtkPaperSize*>((paper_size).gobj()), &(top), &(bottom), &(left), &(right));
}


auto Printer::signal_details_acquired() -> Glib::SignalProxy<void(bool)>
{
  return Glib::SignalProxy<void(bool) >(this, &Printer_signal_details_acquired_info);
}


auto Printer::property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "name");
}

auto Printer::property_is_virtual() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "is-virtual");
}

auto Printer::property_state_message() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "state-message");
}

auto Printer::property_location() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "location");
}

auto Printer::property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "icon-name");
}

auto Printer::property_job_count() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "job-count");
}

auto Printer::property_accepts_pdf() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "accepts-pdf");
}

auto Printer::property_accepts_ps() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "accepts-ps");
}

auto Printer::property_paused() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "paused");
}

auto Printer::property_accepting_jobs() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "accepting-jobs");
}


} // namespace Gtk

#endif // _WIN32
