
#ifndef _GTKMM_PAGESETUPUNIXDIALOG_H
#define _GTKMM_PAGESETUPUNIXDIALOG_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/dialog.hxx>
#include <libmm-gtk/pagesetup.hxx>
#include <libmm-gtk/printsettings.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPageSetupUnixDialog = struct _GtkPageSetupUnixDialog;
using GtkPageSetupUnixDialogClass = struct _GtkPageSetupUnixDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API PageSetupUnixDialog_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API PageSetupUnixDialog : public Dialog
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PageSetupUnixDialog CppObjectType;
    typedef PageSetupUnixDialog_Class CppClassType;
    typedef GtkPageSetupUnixDialog BaseObjectType;
    typedef GtkPageSetupUnixDialogClass BaseClassType;
#endif

    PageSetupUnixDialog (PageSetupUnixDialog&& src) noexcept;
    auto
    operator= (PageSetupUnixDialog&& src) noexcept -> PageSetupUnixDialog&;

    PageSetupUnixDialog (const PageSetupUnixDialog&) = delete;
    auto
    operator= (const PageSetupUnixDialog&) -> PageSetupUnixDialog& = delete;

    ~PageSetupUnixDialog () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class PageSetupUnixDialog_Class;
    static CppClassType pagesetupunixdialog_class_;

  protected:
    explicit PageSetupUnixDialog (
        const Glib::ConstructParams& construct_params);
    explicit PageSetupUnixDialog (GtkPageSetupUnixDialog* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPageSetupUnixDialog*
    {
      return reinterpret_cast<GtkPageSetupUnixDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkPageSetupUnixDialog*
    {
      return reinterpret_cast<GtkPageSetupUnixDialog*> (gobject_);
    }

  private:
  public:
    explicit PageSetupUnixDialog (Gtk::Window& parent,
                                  const Glib::ustring& title);
    explicit PageSetupUnixDialog (const Glib::ustring& title);

    void
    set_page_setup (const Glib::RefPtr<PageSetup>& page_setup);

    auto
    get_page_setup () -> Glib::RefPtr<PageSetup>;

    auto
    get_page_setup () const -> Glib::RefPtr<const PageSetup>;

    void
    set_print_settings (const Glib::RefPtr<PrintSettings>& print_settings);

    auto
    get_print_settings () -> Glib::RefPtr<PrintSettings>;

    auto
    get_print_settings () const -> Glib::RefPtr<const PrintSettings>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPageSetupUnixDialog* object, bool take_copy = false) -> Gtk::PageSetupUnixDialog*;
} // namespace Glib

#endif
