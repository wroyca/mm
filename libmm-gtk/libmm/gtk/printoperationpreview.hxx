// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTOPERATIONPREVIEW_H
#define _GTKMM_PRINTOPERATIONPREVIEW_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

#include <libmm/gtk/pagesetup.hxx>
#include <libmm/gtk/printcontext.hxx>

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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT PrintOperationPreview_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PrintOperationPreview : public glib::Interface
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
        const glib::Interface_Class& interface_class);

  public:
    explicit PrintOperationPreview (GtkPrintOperationPreview* castitem);

  protected:
#endif

  public:
    PrintOperationPreview (PrintOperationPreview&& src) noexcept;
    auto
    operator= (PrintOperationPreview&& src) noexcept -> PrintOperationPreview&;

    ~PrintOperationPreview () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

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
    auto
    render_page (int page_nr) -> void;

    auto
    end_preview () -> void;

    auto
    is_selected (int page_nr) const -> bool;

    auto
    signal_ready ()
        -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&)>;

    auto
    signal_got_page_size ()
        -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&,
                                   const glib::RefPtr<PageSetup>&)>;

  protected:
    virtual auto
    render_page_vfunc (int page_nr) -> void;

    virtual auto
    end_preview_vfunc () -> void;

    virtual auto
    is_selected_vfunc (int page_nr) const -> bool;

  public:
  public:
  protected:
    virtual auto
    on_ready (const glib::RefPtr<PrintContext>& context) -> void;

    virtual auto
    on_got_page_size (const glib::RefPtr<PrintContext>& context,
                      const glib::RefPtr<PageSetup>& page_setup) -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPrintOperationPreview* object, bool take_copy = false) -> glib::RefPtr<gtk::PrintOperationPreview>;

} // namespace glib

#endif
