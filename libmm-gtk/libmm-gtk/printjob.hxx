// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTJOB_H
#define _GTKMM_PRINTJOB_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-cairo/surface.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gtk/pagesetup.hxx>
#include <libmm-gtk/printer.hxx>
#include <libmm-gtk/printoperation.hxx>
#include <libmm-gtk/printsettings.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintJob = struct _GtkPrintJob;
using GtkPrintJobClass = struct _GtkPrintJobClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API PrintJob_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API PrintJob : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PrintJob;
    using CppClassType = PrintJob_Class;
    using BaseObjectType = GtkPrintJob;
    using BaseClassType = GtkPrintJobClass;

    PrintJob (const PrintJob&) = delete;
    auto
    operator= (const PrintJob&) -> PrintJob& = delete;

  private:
    friend class PrintJob_Class;
    static CppClassType printjob_class_;

  protected:
    explicit PrintJob (const Glib::ConstructParams& construct_params);
    explicit PrintJob (GtkPrintJob* castitem);

#endif

  public:
    PrintJob (PrintJob&& src) noexcept;
    auto
    operator= (PrintJob&& src) noexcept -> PrintJob&;

    ~PrintJob () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPrintJob*
    {
      return reinterpret_cast<GtkPrintJob*> (gobject_);
    }

    auto
    gobj () const -> const GtkPrintJob*
    {
      return reinterpret_cast<GtkPrintJob*> (gobject_);
    }

    auto
    gobj_copy () -> GtkPrintJob*;

  private:
  protected:
    explicit PrintJob (const Glib::ustring& title,
                       const Glib::RefPtr<Printer>& printer,
                       const Glib::RefPtr<PrintSettings>& settings,
                       const Glib::RefPtr<PageSetup>& page_setup);

  public:
    static auto
    create (const Glib::ustring& title,
            const Glib::RefPtr<Printer>& printer,
            const Glib::RefPtr<PrintSettings>& settings,
            const Glib::RefPtr<PageSetup>& page_setup)
        -> Glib::RefPtr<PrintJob>;

    auto
    get_settings () -> Glib::RefPtr<PrintSettings>;

    auto
    get_settings () const -> Glib::RefPtr<const PrintSettings>;

    auto
    get_printer () -> Glib::RefPtr<Printer>;

    auto
    get_printer () const -> Glib::RefPtr<const Printer>;

    auto
    get_title () const -> Glib::ustring;

    auto
    get_status () const -> PrintStatus;

    void
    set_source_file (const std::string& filename);

    auto
    get_surface () -> Cairo::RefPtr<Cairo::Surface>;

    auto
    get_surface () const -> Cairo::RefPtr<const Cairo::Surface>;

    void
    set_track_print_status (bool track_status = true);

    auto
    get_track_print_status () const -> bool;

    typedef sigc::slot<void (const Glib::RefPtr<PrintJob>&)>
        SlotPrintJobComplete;

    void
    send (const SlotPrintJobComplete& slot);

    auto
    get_pages () const -> PrintPages;

    void
    set_pages (PrintPages pages);

    auto
    get_page_ranges () const -> std::vector<PageRange>;

    void
    set_page_ranges (const std::vector<PageRange>& ranges);

    auto
    get_page_set () const -> PageSet;

    void
    set_page_set (PageSet page_set);

    auto
    get_num_copies () const -> int;

    void
    set_num_copies (int num_copies);

    auto
    get_scale () const -> double;

    void
    set_scale (double scale);

    auto
    get_n_up () const -> guint;

    void
    set_n_up (guint n_up);

    auto
    get_n_up_layout () const -> NumberUpLayout;

    void
    set_n_up_layout (NumberUpLayout layout);

    auto
    get_rotate () const -> bool;

    void
    set_rotate (bool rotate = true);

    auto
    get_collate () const -> bool;

    void
    set_collate (bool collate = true);

    auto
    get_reverse () const -> bool;

    void
    set_reverse (bool reverse = true);

    auto
    signal_status_changed () -> Glib::SignalProxy<void ()>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_printer () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Printer>>;

    auto
    property_settings () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PrintSettings>>;

    auto
    property_page_setup () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PageSetup>>;

    auto
    property_track_print_status () -> Glib::PropertyProxy<bool>;

    auto
    property_track_print_status () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPrintJob* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PrintJob>;
} // namespace Glib

#endif
