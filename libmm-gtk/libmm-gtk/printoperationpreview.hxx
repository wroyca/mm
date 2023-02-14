// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTOPERATIONPREVIEW_H
#define _GTKMM_PRINTOPERATIONPREVIEW_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#include <libmm-gtk/pagesetup.hxx>
#include <libmm-gtk/printcontext.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkPrintOperationPreviewIface GtkPrintOperationPreviewIface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintOperationPreview = struct _GtkPrintOperationPreview;
using GtkPrintOperationPreviewClass = struct _GtkPrintOperationPreviewClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API PrintOperationPreview_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API PrintOperationPreview : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PrintOperationPreview;
    using CppClassType = PrintOperationPreview_Class;
    using BaseObjectType = GtkPrintOperationPreview;
    using BaseClassType = GtkPrintOperationPreviewIface;

    PrintOperationPreview (const PrintOperationPreview&) = delete;
    auto
    operator= (const PrintOperationPreview&) -> PrintOperationPreview& = delete;

  private:
    friend class PrintOperationPreview_Class;
    static CppClassType printoperationpreview_class_;

#endif
  protected:
    PrintOperationPreview ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit PrintOperationPreview (
        const Glib::Interface_Class& interface_class);

  public:
    explicit PrintOperationPreview (GtkPrintOperationPreview* castitem);

  protected:
#endif

  public:
    PrintOperationPreview (PrintOperationPreview&& src) noexcept;
    auto
    operator= (PrintOperationPreview&& src) noexcept -> PrintOperationPreview&;

    ~PrintOperationPreview () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPrintOperationPreview*
    {
      return reinterpret_cast<GtkPrintOperationPreview*> (gobject_);
    }

    auto
    gobj () const -> const GtkPrintOperationPreview*
    {
      return reinterpret_cast<GtkPrintOperationPreview*> (gobject_);
    }

  private:
  public:
    void
    render_page (int page_nr);

    void
    end_preview ();

    auto
    is_selected (int page_nr) const -> bool;

    auto
    signal_ready ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&)>;

    auto
    signal_got_page_size ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&,
                                   const Glib::RefPtr<PageSetup>&)>;

  protected:
    virtual void
    render_page_vfunc (int page_nr);

    virtual void
    end_preview_vfunc ();

    virtual auto
    is_selected_vfunc (int page_nr) const -> bool;

  public:
  public:
  protected:
    virtual void
    on_ready (const Glib::RefPtr<PrintContext>& context);

    virtual void
    on_got_page_size (const Glib::RefPtr<PrintContext>& context,
                      const Glib::RefPtr<PageSetup>& page_setup);
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPrintOperationPreview* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PrintOperationPreview>;

} // namespace Glib

#endif
