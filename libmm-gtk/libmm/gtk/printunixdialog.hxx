// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTUNIXDIALOG_H
#define _GTKMM_PRINTUNIXDIALOG_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/dialog.hxx>
#include <libmm/gtk/pagesetup.hxx>
#include <libmm/gtk/printer.hxx>
#include <libmm/gtk/printjob.hxx>
#include <libmm/gtk/printsettings.hxx>
#include <libmm/gtk/export.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintUnixDialog = struct _GtkPrintUnixDialog;
using GtkPrintUnixDialogClass = struct _GtkPrintUnixDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT PrintUnixDialog_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT PrintUnixDialog : public Dialog
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
    friend LIBMM_GTK_SYMEXPORT class PrintUnixDialog_Class;
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

    auto
    set_page_setup (const Glib::RefPtr<PageSetup>& page_setup) -> void;

    auto
    get_page_setup () -> Glib::RefPtr<PageSetup>;

    auto
    get_page_setup () const -> Glib::RefPtr<const PageSetup>;

    auto
    set_current_page (int current_page) -> void;

    auto
    get_current_page () const -> int;

    auto
    set_settings (const Glib::RefPtr<PrintSettings>& settings) -> void;

    auto
    get_settings () -> Glib::RefPtr<PrintSettings>;

    auto
    get_settings () const -> Glib::RefPtr<const PrintSettings>;

    auto
    get_selected_printer () -> Glib::RefPtr<Printer>;

    auto
    get_selected_printer () const -> Glib::RefPtr<const Printer>;

    auto
    add_custom_tab (const Widget& child, const Glib::ustring& tab_label)
        -> void;

    auto
    add_custom_tab (const Widget& child, const Widget& tab_label) -> void;

    auto
    set_manual_capabilities (PrintCapabilities capabilities) -> void;

    auto
    get_manual_capabilities () const -> PrintCapabilities;

    auto
    get_support_selection (bool support_selection = true) -> void;

    auto
    get_support_selection () const -> bool;

    auto
    set_has_selection (bool has_selection = true) -> void;

    auto
    get_has_selection () const -> bool;

    auto
    set_embed_page_setup (bool embed = true) -> void;

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
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPrintUnixDialog* object, bool take_copy = false) -> Gtk::PrintUnixDialog*;
} // namespace Glib

#endif
