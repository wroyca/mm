// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/printjob.hxx>
#include <libmm/gtk/printjob_p.hxx>

#include <gtk/gtkunixprint.h>
#include <libmm/gdk/cairoutils.hxx>

static auto
SignalProxy_Custom_gtk_callback (GtkPrintJob* print_job,
                                 gpointer data,
                                 const GError* gerror) -> void
{
  const auto the_slot =
      static_cast<gtk::PrintJob::SlotPrintJobComplete*> (data);

  try
  {
    if (gerror)
      glib::Error::throw_exception (g_error_copy (gerror));

    auto job = glib::wrap (print_job);
    (*the_slot) (job);
  }
  catch (...)
  {
    glib::exception_handlers_invoke ();
  }
}

namespace gtk
{

  auto
  PrintJob::send (const SlotPrintJobComplete& slot) -> void
  {
    auto slot_copy = new SlotPrintJobComplete (slot);

    gtk_print_job_send (gobj (),
                        &SignalProxy_Custom_gtk_callback,
                        slot_copy,
                        &glib::destroy_notify_delete<SlotPrintJobComplete>);
  }

  auto
  PrintJob::get_page_ranges () const -> std::vector<PageRange>
  {
    int num_ranges (0);
    const GtkPageRange* page_ranges = gtk_print_job_get_page_ranges (
        const_cast<GtkPrintJob*> (gobj ()),
        &num_ranges);

    return glib::ArrayHandler<PageRange, PageRangeTraits>::array_to_vector (
        page_ranges,
        num_ranges,
        glib::OWNERSHIP_NONE);
  }

  auto
  PrintJob::set_page_ranges (const std::vector<PageRange>& page_ranges) -> void
  {
    GtkPageRange* c_ranges = g_new0 (GtkPageRange, page_ranges.size ());
    for (std::size_t i = 0; i < page_ranges.size (); ++i)
    {
      c_ranges[i].start = page_ranges[i].start;
      c_ranges[i].end = page_ranges[i].end;
    }
    gtk_print_job_set_page_ranges (gobj (), c_ranges, page_ranges.size ());
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo PrintJob_signal_status_changed_info = {
      "status_changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GtkPrintJob* object, bool take_copy) -> glib::RefPtr<gtk::PrintJob>
  {
    return glib::make_refptr_for_instance<gtk::PrintJob> (
        dynamic_cast<gtk::PrintJob*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  PrintJob_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PrintJob_Class::class_init_function;

      register_derived_type (gtk_print_job_get_type ());
    }

    return *this;
  }

  auto
  PrintJob_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PrintJob_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new PrintJob ((GtkPrintJob*) object);
  }

  auto
  PrintJob::gobj_copy () -> GtkPrintJob*
  {
    reference ();
    return gobj ();
  }

  PrintJob::PrintJob (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  PrintJob::PrintJob (GtkPrintJob* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  PrintJob::PrintJob (PrintJob&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  PrintJob::operator= (PrintJob&& src) noexcept -> PrintJob&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  PrintJob::~PrintJob () noexcept {}

  PrintJob::CppClassType PrintJob::printjob_class_;

  auto
  PrintJob::get_type () -> GType
  {
    return printjob_class_.init ().get_type ();
  }

  auto
  PrintJob::get_base_type () -> GType
  {
    return gtk_print_job_get_type ();
  }

  PrintJob::PrintJob (const glib::ustring& title,
                      const glib::RefPtr<Printer>& printer,
                      const glib::RefPtr<PrintSettings>& settings,
                      const glib::RefPtr<PageSetup>& page_setup)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (printjob_class_.init (),
                                           "title",
                                           title.c_str (),
                                           "printer",
                                           glib::unwrap (printer),
                                           "settings",
                                           glib::unwrap (settings),
                                           "page_setup",
                                           glib::unwrap (page_setup),
                                           nullptr))
  {
  }

  auto
  PrintJob::create (const glib::ustring& title,
                    const glib::RefPtr<Printer>& printer,
                    const glib::RefPtr<PrintSettings>& settings,
                    const glib::RefPtr<PageSetup>& page_setup) -> glib::RefPtr<PrintJob>
  {
    return glib::make_refptr_for_instance<PrintJob> (
        new PrintJob (title, printer, settings, page_setup));
  }

  auto
  PrintJob::get_settings () -> glib::RefPtr<PrintSettings>
  {
    auto retvalue = glib::wrap (gtk_print_job_get_settings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintJob::get_settings () const -> glib::RefPtr<const PrintSettings>
  {
    return const_cast<PrintJob*> (this)->get_settings ();
  }

  auto
  PrintJob::get_printer () -> glib::RefPtr<Printer>
  {
    auto retvalue = glib::wrap (gtk_print_job_get_printer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintJob::get_printer () const -> glib::RefPtr<const Printer>
  {
    return const_cast<PrintJob*> (this)->get_printer ();
  }

  auto
  PrintJob::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_print_job_get_title (const_cast<GtkPrintJob*> (gobj ())));
  }

  auto
  PrintJob::get_status () const -> PrintStatus
  {
    return static_cast<PrintStatus> (
        gtk_print_job_get_status (const_cast<GtkPrintJob*> (gobj ())));
  }

  auto
  PrintJob::set_source_file (const std::string& filename) -> void
  {
    GError* gerror = nullptr;
    gtk_print_job_set_source_file (gobj (), filename.c_str (), &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
  }

  auto
  PrintJob::get_surface () -> cairo::RefPtr<cairo::Surface>
  {
    GError* gerror = nullptr;
    auto retvalue =
        gdk::cairo::wrap (gtk_print_job_get_surface (gobj (), &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintJob::get_surface () const -> cairo::RefPtr<const cairo::Surface>
  {
    return const_cast<PrintJob*> (this)->get_surface ();
  }

  auto
  PrintJob::set_track_print_status (bool track_status) -> void
  {
    gtk_print_job_set_track_print_status (gobj (),
                                          static_cast<int> (track_status));
  }

  auto
  PrintJob::get_track_print_status () const -> bool
  {
    return gtk_print_job_get_track_print_status (
        const_cast<GtkPrintJob*> (gobj ()));
  }

  auto
  PrintJob::get_pages () const -> PrintPages
  {
    return static_cast<PrintPages> (
        gtk_print_job_get_pages (const_cast<GtkPrintJob*> (gobj ())));
  }

  auto
  PrintJob::set_pages (PrintPages pages) -> void
  {
    gtk_print_job_set_pages (gobj (), static_cast<GtkPrintPages> (pages));
  }

  auto
  PrintJob::get_page_set () const -> PageSet
  {
    return static_cast<PageSet> (
        gtk_print_job_get_page_set (const_cast<GtkPrintJob*> (gobj ())));
  }

  auto
  PrintJob::set_page_set (PageSet page_set) -> void
  {
    gtk_print_job_set_page_set (gobj (), static_cast<GtkPageSet> (page_set));
  }

  auto
  PrintJob::get_num_copies () const -> int
  {
    return gtk_print_job_get_num_copies (const_cast<GtkPrintJob*> (gobj ()));
  }

  auto
  PrintJob::set_num_copies (int num_copies) -> void
  {
    gtk_print_job_set_num_copies (gobj (), num_copies);
  }

  auto
  PrintJob::get_scale () const -> double
  {
    return gtk_print_job_get_scale (const_cast<GtkPrintJob*> (gobj ()));
  }

  auto
  PrintJob::set_scale (double scale) -> void
  {
    gtk_print_job_set_scale (gobj (), scale);
  }

  auto
  PrintJob::get_n_up () const -> guint
  {
    return gtk_print_job_get_n_up (const_cast<GtkPrintJob*> (gobj ()));
  }

  auto
  PrintJob::set_n_up (guint n_up) -> void
  {
    gtk_print_job_set_n_up (gobj (), n_up);
  }

  auto
  PrintJob::get_n_up_layout () const -> NumberUpLayout
  {
    return static_cast<NumberUpLayout> (
        gtk_print_job_get_n_up_layout (const_cast<GtkPrintJob*> (gobj ())));
  }

  auto
  PrintJob::set_n_up_layout (NumberUpLayout layout) -> void
  {
    gtk_print_job_set_n_up_layout (gobj (),
                                   static_cast<GtkNumberUpLayout> (layout));
  }

  auto
  PrintJob::get_rotate () const -> bool
  {
    return gtk_print_job_get_rotate (const_cast<GtkPrintJob*> (gobj ()));
  }

  auto
  PrintJob::set_rotate (bool rotate) -> void
  {
    gtk_print_job_set_rotate (gobj (), static_cast<int> (rotate));
  }

  auto
  PrintJob::get_collate () const -> bool
  {
    return gtk_print_job_get_collate (const_cast<GtkPrintJob*> (gobj ()));
  }

  auto
  PrintJob::set_collate (bool collate) -> void
  {
    gtk_print_job_set_collate (gobj (), static_cast<int> (collate));
  }

  auto
  PrintJob::get_reverse () const -> bool
  {
    return gtk_print_job_get_reverse (const_cast<GtkPrintJob*> (gobj ()));
  }

  auto
  PrintJob::set_reverse (bool reverse) -> void
  {
    gtk_print_job_set_reverse (gobj (), static_cast<int> (reverse));
  }

  auto
  PrintJob::signal_status_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &PrintJob_signal_status_changed_info);
  }

  auto
  PrintJob::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Printer>>::value,
      "Type glib::RefPtr<Printer> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintJob::property_printer () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Printer>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Printer>> (this,
                                                                "printer");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<PrintSettings>>::value,
      "Type glib::RefPtr<PrintSettings> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintJob::property_settings () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PrintSettings>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<PrintSettings>> (
        this,
        "settings");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<PageSetup>>::value,
      "Type glib::RefPtr<PageSetup> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintJob::property_page_setup () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PageSetup>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<PageSetup>> (this,
                                                                  "page-setup");
  }

  auto
  PrintJob::property_track_print_status () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "track-print-status");
  }

  auto
  PrintJob::property_track_print_status () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "track-print-status");
  }

} // namespace gtk
