// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTER_H
#define _GTKMM_PRINTER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gtk/pagesetup.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrinter = struct _GtkPrinter;
using GtkPrinterClass = struct _GtkPrinterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Printer_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT PaperSize;

  enum class PrintCapabilities
  {
    PAGE_SET = 1 << 0,
    COPIES = 1 << 1,
    COLLATE = 1 << 2,
    REVERSE = 1 << 3,
    SCALE = 1 << 4,
    GENERATE_PDF = 1 << 5,
    GENERATE_PS = 1 << 6,
    PREVIEW = 1 << 7,
    NUMBER_UP = 1 << 8,
    NUMBER_UP_LAYOUT = 1 << 9
  };

  inline auto
  operator| (PrintCapabilities lhs, PrintCapabilities rhs) -> PrintCapabilities
  {
    return static_cast<PrintCapabilities> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (PrintCapabilities lhs, PrintCapabilities rhs) -> PrintCapabilities
  {
    return static_cast<PrintCapabilities> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (PrintCapabilities lhs, PrintCapabilities rhs) -> PrintCapabilities
  {
    return static_cast<PrintCapabilities> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(PrintCapabilities flags) -> PrintCapabilities
  {
    return static_cast<PrintCapabilities> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (PrintCapabilities& lhs, PrintCapabilities rhs) -> PrintCapabilities&
  {
    return (lhs = static_cast<PrintCapabilities> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (PrintCapabilities& lhs, PrintCapabilities rhs) -> PrintCapabilities&
  {
    return (lhs = static_cast<PrintCapabilities> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (PrintCapabilities& lhs, PrintCapabilities rhs) -> PrintCapabilities&
  {
    return (lhs = static_cast<PrintCapabilities> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs)));
  }

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PrintCapabilities>
    : public glib::Value_Flags<gtk::PrintCapabilities>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Printer : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Printer;
    using CppClassType = Printer_Class;
    using BaseObjectType = GtkPrinter;
    using BaseClassType = GtkPrinterClass;

    Printer (const Printer&) = delete;
    auto
    operator= (const Printer&) -> Printer& = delete;

  private:
    friend class Printer_Class;
    static CppClassType printer_class_;

  protected:
    explicit Printer (const glib::ConstructParams& construct_params);
    explicit Printer (GtkPrinter* castitem);

#endif

  public:
    Printer (Printer&& src) noexcept;
    auto
    operator= (Printer&& src) noexcept -> Printer&;

    ~Printer () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPrinter*
    {
      return reinterpret_cast<GtkPrinter*> (gobject_);
    }

    auto
    gobj () const -> const GtkPrinter*
    {
      return reinterpret_cast<GtkPrinter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkPrinter*;

  private:
  public:
    auto
    equal (const glib::RefPtr<Printer>& other) const -> bool;

    auto
    get_name () const -> glib::ustring;

    auto
    get_state_message () const -> glib::ustring;

    auto
    get_description () const -> glib::ustring;

    auto
    get_location () const -> glib::ustring;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_job_count () const -> int;

    auto
    is_active () const -> bool;

    auto
    is_paused () const -> bool;

    auto
    is_accepting_jobs () const -> bool;

    auto
    is_virtual () const -> bool;

    auto
    is_default () const -> bool;

    auto
    accepts_pdf () const -> bool;

    auto
    accepts_ps () const -> bool;

    auto
    list_papers () -> std::vector<glib::RefPtr<PageSetup>>;

    auto
    get_default_page_size () const -> glib::RefPtr<PageSetup>;

    auto
    list_papers () const -> std::vector<glib::RefPtr<const PageSetup>>;

    auto
    has_details () const -> bool;

    auto
    request_details () -> void;

    auto
    get_capabilities () const -> PrintCapabilities;

    auto
    get_hard_margins (double& top,
                      double& bottom,
                      double& left,
                      double& right) const -> bool;

    auto
    get_hard_margins (const PaperSize& paper_size,
                      double& top,
                      double& bottom,
                      double& left,
                      double& right) const -> bool;

    auto
    signal_details_acquired () -> glib::SignalProxy<void (bool)>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_is_virtual () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_state_message () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_location () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_job_count () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_accepts_pdf () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accepts_ps () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_paused () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accepting_jobs () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

  inline auto
  operator== (const glib::RefPtr<Printer>& lhs,
              const glib::RefPtr<Printer>& rhs) -> bool
  {
    return lhs->equal (rhs);
  }

  inline auto
  operator!= (const glib::RefPtr<Printer>& lhs,
              const glib::RefPtr<Printer>& rhs) -> bool
  {
    return !lhs->equal (rhs);
  }

  typedef sigc::slot<bool (const glib::RefPtr<Printer>&)> SlotPrinterEnumerator;

  LIBMM_GTK_SYMEXPORT auto
  enumerate_printers (const SlotPrinterEnumerator& slot, bool wait = true) -> void;

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPrinter* object, bool take_copy = false) -> glib::RefPtr<gtk::Printer>;
} // namespace glib

#endif
