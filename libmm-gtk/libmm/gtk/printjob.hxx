// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTJOB_H
#define _GTKMM_PRINTJOB_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/gtk/pagesetup.hxx>
#include <libmm/gtk/printer.hxx>
#include <libmm/gtk/printoperation.hxx>
#include <libmm/gtk/printsettings.hxx>
#include <libmm/cairo/surface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintJob = struct _GtkPrintJob;
using GtkPrintJobClass = struct _GtkPrintJobClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT PrintJob_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PrintJob : public glib::Object
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
    explicit PrintJob (const glib::ConstructParams& construct_params);
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
    explicit PrintJob (const glib::ustring& title,
                       const glib::RefPtr<Printer>& printer,
                       const glib::RefPtr<PrintSettings>& settings,
                       const glib::RefPtr<PageSetup>& page_setup);

  public:
    static auto
    create (const glib::ustring& title,
            const glib::RefPtr<Printer>& printer,
            const glib::RefPtr<PrintSettings>& settings,
            const glib::RefPtr<PageSetup>& page_setup)
        -> glib::RefPtr<PrintJob>;

    auto
    get_settings () -> glib::RefPtr<PrintSettings>;

    auto
    get_settings () const -> glib::RefPtr<const PrintSettings>;

    auto
    get_printer () -> glib::RefPtr<Printer>;

    auto
    get_printer () const -> glib::RefPtr<const Printer>;

    auto
    get_title () const -> glib::ustring;

    auto
    get_status () const -> PrintStatus;

    auto
    set_source_file (const std::string& filename) -> void;

    auto
    get_surface () -> cairo::RefPtr<cairo::Surface>;

    auto
    get_surface () const -> cairo::RefPtr<const cairo::Surface>;

    auto
    set_track_print_status (bool track_status = true) -> void;

    auto
    get_track_print_status () const -> bool;

    typedef sigc::slot<void (const glib::RefPtr<PrintJob>&)>
        SlotPrintJobComplete;

    auto
    send (const SlotPrintJobComplete& slot) -> void;

    auto
    get_pages () const -> PrintPages;

    auto
    set_pages (PrintPages pages) -> void;

    auto
    get_page_ranges () const -> std::vector<PageRange>;

    auto
    set_page_ranges (const std::vector<PageRange>& ranges) -> void;

    auto
    get_page_set () const -> PageSet;

    auto
    set_page_set (PageSet page_set) -> void;

    auto
    get_num_copies () const -> int;

    auto
    set_num_copies (int num_copies) -> void;

    auto
    get_scale () const -> double;

    auto
    set_scale (double scale) -> void;

    auto
    get_n_up () const -> guint;

    auto
    set_n_up (guint n_up) -> void;

    auto
    get_n_up_layout () const -> NumberUpLayout;

    auto
    set_n_up_layout (NumberUpLayout layout) -> void;

    auto
    get_rotate () const -> bool;

    auto
    set_rotate (bool rotate = true) -> void;

    auto
    get_collate () const -> bool;

    auto
    set_collate (bool collate = true) -> void;

    auto
    get_reverse () const -> bool;

    auto
    set_reverse (bool reverse = true) -> void;

    auto
    signal_status_changed () -> glib::SignalProxy<void ()>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_printer () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Printer>>;

    auto
    property_settings () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PrintSettings>>;

    auto
    property_page_setup () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PageSetup>>;

    auto
    property_track_print_status () -> glib::PropertyProxy<bool>;

    auto
    property_track_print_status () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPrintJob* object, bool take_copy = false) -> glib::RefPtr<gtk::PrintJob>;
} // namespace glib

#endif
