// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/printer.hxx>
#include <libmm/gtk/printer_p.hxx>

#include <libmm/glib/vectorutils.hxx>
#include <libmm/gtk/papersize.hxx>

#include <gtk/gtkunixprint.h>

static auto
SignalProxy_Custom_gtk_callback (GtkPrinter* gtk_printer, gpointer data)
    -> gboolean
{
  const auto the_slot = static_cast<gtk::SlotPrinterEnumerator*> (data);

  try
  {
    auto printer = glib::wrap (gtk_printer, true);

    return (*the_slot) (printer);
  }
  catch (...)
  {
    glib::exception_handlers_invoke ();
    return false;
  }
}

static auto
SignalProxy_Custom_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<gtk::SlotPrinterEnumerator*> (data);
}

namespace gtk
{

  auto
  Printer::equal (const glib::RefPtr<Printer>& other) const -> bool
  {
    return (static_cast<bool> (
        gtk_printer_compare (const_cast<GtkPrinter*> (this->gobj ()),
                             const_cast<GtkPrinter*> (other->gobj ()))));
  }

  auto
  enumerate_printers (const SlotPrinterEnumerator& slot, bool wait) -> void
  {
    auto slot_copy = new SlotPrinterEnumerator (slot);

    gtk_enumerate_printers (&SignalProxy_Custom_gtk_callback,
                            slot_copy,
                            &SignalProxy_Custom_gtk_callback_destroy,
                            static_cast<int> (wait));
  }

} // namespace gtk

namespace
{

  static auto
  Printer_signal_details_acquired_callback (GtkPrinter* self,
                                            gboolean p0,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (bool)>;

    auto obj = dynamic_cast<Printer*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Printer_signal_details_acquired_info = {
      "details_acquired",
      (GCallback) &Printer_signal_details_acquired_callback,
      (GCallback) &Printer_signal_details_acquired_callback};

} // namespace

auto
glib::Value<gtk::PrintCapabilities>::value_type () -> GType
{
  return gtk_print_capabilities_get_type ();
}

namespace glib
{

  auto
  wrap (GtkPrinter* object, bool take_copy) -> glib::RefPtr<gtk::Printer>
  {
    return glib::make_refptr_for_instance<gtk::Printer> (
        dynamic_cast<gtk::Printer*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Printer_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Printer_Class::class_init_function;

      register_derived_type (gtk_printer_get_type ());
    }

    return *this;
  }

  auto
  Printer_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Printer_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Printer ((GtkPrinter*) object);
  }

  auto
  Printer::gobj_copy () -> GtkPrinter*
  {
    reference ();
    return gobj ();
  }

  Printer::Printer (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Printer::Printer (GtkPrinter* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Printer::Printer (Printer&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Printer::operator= (Printer&& src) noexcept -> Printer&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Printer::~Printer () noexcept {}

  Printer::CppClassType Printer::printer_class_;

  auto
  Printer::get_type () -> GType
  {
    return printer_class_.init ().get_type ();
  }

  auto
  Printer::get_base_type () -> GType
  {
    return gtk_printer_get_type ();
  }

  auto
  Printer::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_printer_get_name (const_cast<GtkPrinter*> (gobj ())));
  }

  auto
  Printer::get_state_message () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_printer_get_state_message (const_cast<GtkPrinter*> (gobj ())));
  }

  auto
  Printer::get_description () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_printer_get_description (const_cast<GtkPrinter*> (gobj ())));
  }

  auto
  Printer::get_location () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_printer_get_location (const_cast<GtkPrinter*> (gobj ())));
  }

  auto
  Printer::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_printer_get_icon_name (const_cast<GtkPrinter*> (gobj ())));
  }

  auto
  Printer::get_job_count () const -> int
  {
    return gtk_printer_get_job_count (const_cast<GtkPrinter*> (gobj ()));
  }

  auto
  Printer::is_active () const -> bool
  {
    return gtk_printer_is_active (const_cast<GtkPrinter*> (gobj ()));
  }

  auto
  Printer::is_paused () const -> bool
  {
    return gtk_printer_is_paused (const_cast<GtkPrinter*> (gobj ()));
  }

  auto
  Printer::is_accepting_jobs () const -> bool
  {
    return gtk_printer_is_accepting_jobs (const_cast<GtkPrinter*> (gobj ()));
  }

  auto
  Printer::is_virtual () const -> bool
  {
    return gtk_printer_is_virtual (const_cast<GtkPrinter*> (gobj ()));
  }

  auto
  Printer::is_default () const -> bool
  {
    return gtk_printer_is_default (const_cast<GtkPrinter*> (gobj ()));
  }

  auto
  Printer::accepts_pdf () const -> bool
  {
    return gtk_printer_accepts_pdf (const_cast<GtkPrinter*> (gobj ()));
  }

  auto
  Printer::accepts_ps () const -> bool
  {
    return gtk_printer_accepts_ps (const_cast<GtkPrinter*> (gobj ()));
  }

  auto
  Printer::list_papers () -> std::vector<glib::RefPtr<PageSetup>>
  {
    return glib::ListHandler<glib::RefPtr<PageSetup>>::list_to_vector (
        gtk_printer_list_papers (gobj ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Printer::get_default_page_size () const -> glib::RefPtr<PageSetup>
  {
    auto retvalue = glib::wrap (
        gtk_printer_get_default_page_size (const_cast<GtkPrinter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Printer::list_papers () const -> std::vector<glib::RefPtr<const PageSetup>>
  {
    return glib::ListHandler<glib::RefPtr<const PageSetup>>::list_to_vector (
        gtk_printer_list_papers (const_cast<GtkPrinter*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Printer::has_details () const -> bool
  {
    return gtk_printer_has_details (const_cast<GtkPrinter*> (gobj ()));
  }

  auto
  Printer::request_details () -> void
  {
    gtk_printer_request_details (gobj ());
  }

  auto
  Printer::get_capabilities () const -> PrintCapabilities
  {
    return static_cast<PrintCapabilities> (
        gtk_printer_get_capabilities (const_cast<GtkPrinter*> (gobj ())));
  }

  auto
  Printer::get_hard_margins (double& top,
                             double& bottom,
                             double& left,
                             double& right) const -> bool
  {
    return gtk_printer_get_hard_margins (const_cast<GtkPrinter*> (gobj ()),
                                         &(top),
                                         &(bottom),
                                         &(left),
                                         &(right));
  }

  auto
  Printer::get_hard_margins (const PaperSize& paper_size,
                             double& top,
                             double& bottom,
                             double& left,
                             double& right) const -> bool
  {
    return gtk_printer_get_hard_margins_for_paper_size (
        const_cast<GtkPrinter*> (gobj ()),
        const_cast<GtkPaperSize*> ((paper_size).gobj ()),
        &(top),
        &(bottom),
        &(left),
        &(right));
  }

  auto
  Printer::signal_details_acquired () -> glib::SignalProxy<void (bool)>
  {
    return glib::SignalProxy<void (bool)> (
        this,
        &Printer_signal_details_acquired_info);
  }

  auto
  Printer::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

  auto
  Printer::property_is_virtual () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "is-virtual");
  }

  auto
  Printer::property_state_message () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "state-message");
  }

  auto
  Printer::property_location () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "location");
  }

  auto
  Printer::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  auto
  Printer::property_job_count () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "job-count");
  }

  auto
  Printer::property_accepts_pdf () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "accepts-pdf");
  }

  auto
  Printer::property_accepts_ps () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "accepts-ps");
  }

  auto
  Printer::property_paused () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "paused");
  }

  auto
  Printer::property_accepting_jobs () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "accepting-jobs");
  }

} // namespace gtk
