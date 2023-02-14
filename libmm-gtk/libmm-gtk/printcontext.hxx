// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTCONTEXT_H
#define _GTKMM_PRINTCONTEXT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#include <libmm-cairo/context.hxx>

#include <libmm-pango/context.hxx>
#include <libmm-pango/fontmap.hxx>
#include <libmm-pango/layout.hxx>

#include <libmm-gtk/pagesetup.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintContext = struct _GtkPrintContext;
using GtkPrintContextClass = struct _GtkPrintContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API PrintContext_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API PrintContext : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PrintContext;
    using CppClassType = PrintContext_Class;
    using BaseObjectType = GtkPrintContext;
    using BaseClassType = GtkPrintContextClass;

    PrintContext (const PrintContext&) = delete;
    auto
    operator= (const PrintContext&) -> PrintContext& = delete;

  private:
    friend class PrintContext_Class;
    static CppClassType printcontext_class_;

  protected:
    explicit PrintContext (const Glib::ConstructParams& construct_params);
    explicit PrintContext (GtkPrintContext* castitem);

#endif

  public:
    PrintContext (PrintContext&& src) noexcept;
    auto
    operator= (PrintContext&& src) noexcept -> PrintContext&;

    ~PrintContext () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPrintContext*
    {
      return reinterpret_cast<GtkPrintContext*> (gobject_);
    }

    auto
    gobj () const -> const GtkPrintContext*
    {
      return reinterpret_cast<GtkPrintContext*> (gobject_);
    }

    auto
    gobj_copy () -> GtkPrintContext*;

  private:
  public:
    auto
    get_cairo_context () -> Cairo::RefPtr<Cairo::Context>;

    auto
    get_cairo_context () const -> Cairo::RefPtr<const Cairo::Context>;

    auto
    get_page_setup () -> Glib::RefPtr<PageSetup>;

    auto
    get_page_setup () const -> Glib::RefPtr<const PageSetup>;

    auto
    get_width () const -> double;

    auto
    get_height () const -> double;

    auto
    get_dpi_x () const -> double;

    auto
    get_dpi_y () const -> double;

    auto
    get_hard_margins (double& top,
                      double& bottom,
                      double& left,
                      double& right) const -> bool;

    auto
    get_pango_fontmap () -> Glib::RefPtr<Pango::FontMap>;

    auto
    get_pango_fontmap () const -> Glib::RefPtr<const Pango::FontMap>;

    auto
    create_pango_context () -> Glib::RefPtr<Pango::Context>;

    auto
    create_pango_layout () -> Glib::RefPtr<Pango::Layout>;

    void
    set_cairo_context (const Cairo::RefPtr<Cairo::Context>& cr,
                       double dpi_x,
                       double dpi_y);

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPrintContext* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PrintContext>;
} // namespace Glib

#endif
