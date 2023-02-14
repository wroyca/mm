
#ifndef _GTKMM_PRINTUNIXDIALOG_H
#define _GTKMM_PRINTUNIXDIALOG_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/dialog.hxx>
#include <libmm-gtk/pagesetup.hxx>
#include <libmm-gtk/printer.hxx>
#include <libmm-gtk/printjob.hxx>
#include <libmm-gtk/printsettings.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintUnixDialog = struct _GtkPrintUnixDialog;
using GtkPrintUnixDialogClass = struct _GtkPrintUnixDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API PrintUnixDialog_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API PrintUnixDialog : public Dialog
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PrintUnixDialog CppObjectType;
    typedef PrintUnixDialog_Class CppClassType;
    typedef GtkPrintUnixDialog BaseObjectType;
    typedef GtkPrintUnixDialogClass BaseClassType;
#endif

    PrintUnixDialog (PrintUnixDialog&& src) noexcept;
    auto
    operator= (PrintUnixDialog&& src) noexcept -> PrintUnixDialog&;

    PrintUnixDialog (const PrintUnixDialog&) = delete;
    auto
    operator= (const PrintUnixDialog&) -> PrintUnixDialog& = delete;

    ~PrintUnixDialog () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class PrintUnixDialog_Class;
    static CppClassType printunixdialog_class_;

  protected:
    explicit PrintUnixDialog (const Glib::ConstructParams& construct_params);
    explicit PrintUnixDialog (GtkPrintUnixDialog* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPrintUnixDialog*
    {
      return reinterpret_cast<GtkPrintUnixDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkPrintUnixDialog*
    {
      return reinterpret_cast<GtkPrintUnixDialog*> (gobject_);
    }

  private:
  public:
    explicit PrintUnixDialog (Gtk::Window& parent, const Glib::ustring& title);
    explicit PrintUnixDialog (const Glib::ustring& title);

    void
    set_page_setup (const Glib::RefPtr<PageSetup>& page_setup);

    auto
    get_page_setup () -> Glib::RefPtr<PageSetup>;

    auto
    get_page_setup () const -> Glib::RefPtr<const PageSetup>;

    void
    set_current_page (int current_page);

    auto
    get_current_page () const -> int;

    void
    set_settings (const Glib::RefPtr<PrintSettings>& settings);

    auto
    get_settings () -> Glib::RefPtr<PrintSettings>;

    auto
    get_settings () const -> Glib::RefPtr<const PrintSettings>;

    auto
    get_selected_printer () -> Glib::RefPtr<Printer>;

    auto
    get_selected_printer () const -> Glib::RefPtr<const Printer>;

    void
    add_custom_tab (const Widget& child, const Glib::ustring& tab_label);

    void
    add_custom_tab (const Widget& child, const Widget& tab_label);

    void
    set_manual_capabilities (PrintCapabilities capabilities);

    auto
    get_manual_capabilities () const -> PrintCapabilities;

    void
    get_support_selection (bool support_selection = true);

    auto
    get_support_selection () const -> bool;

    void
    set_has_selection (bool has_selection = true);

    auto
    get_has_selection () const -> bool;

    void
    set_embed_page_setup (bool embed = true);

    auto
    get_embed_page_setup () const -> bool;

    auto
    get_page_setup_set () const -> bool;

    auto
    property_page_setup () -> Glib::PropertyProxy<Glib::RefPtr<PageSetup>>;

    auto
    property_page_setup () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PageSetup>>;

    auto
    property_current_page () -> Glib::PropertyProxy<int>;

    auto
    property_current_page () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_print_settings ()
        -> Glib::PropertyProxy<Glib::RefPtr<PrintSettings>>;

    auto
    property_print_settings () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PrintSettings>>;

    auto
    property_selected_printer () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Printer>>;

    auto
    property_manual_capabilities () -> Glib::PropertyProxy<bool>;

    auto
    property_manual_capabilities () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_support_selection () -> Glib::PropertyProxy<bool>;

    auto
    property_support_selection () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_selection () -> Glib::PropertyProxy<bool>;

    auto
    property_has_selection () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_embed_page_setup () -> Glib::PropertyProxy<bool>;

    auto
    property_embed_page_setup () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPrintUnixDialog* object, bool take_copy = false) -> Gtk::PrintUnixDialog*;
} // namespace Glib

#endif
