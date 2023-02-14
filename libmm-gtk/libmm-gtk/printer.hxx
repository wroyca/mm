
#ifndef _GTKMM_PRINTER_H
#define _GTKMM_PRINTER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-gtk/pagesetup.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrinter = struct _GtkPrinter;
using GtkPrinterClass = struct _GtkPrinterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Printer_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API PaperSize;

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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PrintCapabilities>
    : public Glib::Value_Flags<Gtk::PrintCapabilities>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API Printer : public Glib::Object
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
    explicit Printer (const Glib::ConstructParams& construct_params);
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
    equal (const Glib::RefPtr<Printer>& other) const -> bool;

    auto
    get_name () const -> Glib::ustring;

    auto
    get_state_message () const -> Glib::ustring;

    auto
    get_description () const -> Glib::ustring;

    auto
    get_location () const -> Glib::ustring;

    auto
    get_icon_name () const -> Glib::ustring;

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
    list_papers () -> std::vector<Glib::RefPtr<PageSetup>>;

    auto
    get_default_page_size () const -> Glib::RefPtr<PageSetup>;

    auto
    list_papers () const -> std::vector<Glib::RefPtr<const PageSetup>>;

    auto
    has_details () const -> bool;

    void
    request_details ();

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
    signal_details_acquired () -> Glib::SignalProxy<void (bool)>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_is_virtual () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_state_message () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_location () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_job_count () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_accepts_pdf () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accepts_ps () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_paused () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accepting_jobs () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

  inline auto
  operator== (const Glib::RefPtr<Printer>& lhs,
              const Glib::RefPtr<Printer>& rhs) -> bool
  {
    return lhs->equal (rhs);
  }

  inline auto
  operator!= (const Glib::RefPtr<Printer>& lhs,
              const Glib::RefPtr<Printer>& rhs) -> bool
  {
    return !lhs->equal (rhs);
  }

  typedef sigc::slot<bool (const Glib::RefPtr<Printer>&)> SlotPrinterEnumerator;

  GTKMM_API
  void
  enumerate_printers (const SlotPrinterEnumerator& slot, bool wait = true);

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPrinter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Printer>;
} // namespace Glib

#endif
