// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/printcontext.hxx>
#include <libmm/gtk/printcontext_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gdk/cairoutils.hxx>

namespace gtk
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GtkPrintContext* object, bool take_copy) -> glib::RefPtr<gtk::PrintContext>
  {
    return glib::make_refptr_for_instance<gtk::PrintContext> (
        dynamic_cast<gtk::PrintContext*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  PrintContext_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PrintContext_Class::class_init_function;

      register_derived_type (gtk_print_context_get_type ());
    }

    return *this;
  }

  auto
  PrintContext_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PrintContext_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new PrintContext ((GtkPrintContext*) object);
  }

  auto
  PrintContext::gobj_copy () -> GtkPrintContext*
  {
    reference ();
    return gobj ();
  }

  PrintContext::PrintContext (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  PrintContext::PrintContext (GtkPrintContext* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  PrintContext::PrintContext (PrintContext&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  PrintContext::operator= (PrintContext&& src) noexcept -> PrintContext&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  PrintContext::~PrintContext () noexcept {}

  PrintContext::CppClassType PrintContext::printcontext_class_;

  auto
  PrintContext::get_type () -> GType
  {
    return printcontext_class_.init ().get_type ();
  }

  auto
  PrintContext::get_base_type () -> GType
  {
    return gtk_print_context_get_type ();
  }

  auto
  PrintContext::get_cairo_context () -> cairo::RefPtr<cairo::Context>
  {
    auto retvalue =
        gdk::cairo::wrap (gtk_print_context_get_cairo_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintContext::get_cairo_context () const -> cairo::RefPtr<const cairo::Context>
  {
    return const_cast<PrintContext*> (this)->get_cairo_context ();
  }

  auto
  PrintContext::get_page_setup () -> glib::RefPtr<PageSetup>
  {
    auto retvalue = glib::wrap (gtk_print_context_get_page_setup (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintContext::get_page_setup () const -> glib::RefPtr<const PageSetup>
  {
    return const_cast<PrintContext*> (this)->get_page_setup ();
  }

  auto
  PrintContext::get_width () const -> double
  {
    return gtk_print_context_get_width (const_cast<GtkPrintContext*> (gobj ()));
  }

  auto
  PrintContext::get_height () const -> double
  {
    return gtk_print_context_get_height (
        const_cast<GtkPrintContext*> (gobj ()));
  }

  auto
  PrintContext::get_dpi_x () const -> double
  {
    return gtk_print_context_get_dpi_x (const_cast<GtkPrintContext*> (gobj ()));
  }

  auto
  PrintContext::get_dpi_y () const -> double
  {
    return gtk_print_context_get_dpi_y (const_cast<GtkPrintContext*> (gobj ()));
  }

  auto
  PrintContext::get_hard_margins (double& top,
                                  double& bottom,
                                  double& left,
                                  double& right) const -> bool
  {
    return gtk_print_context_get_hard_margins (
        const_cast<GtkPrintContext*> (gobj ()),
        &(top),
        &(bottom),
        &(left),
        &(right));
  }

  auto
  PrintContext::get_pango_fontmap () -> glib::RefPtr<pango::FontMap>
  {
    auto retvalue = glib::wrap (gtk_print_context_get_pango_fontmap (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintContext::get_pango_fontmap () const -> glib::RefPtr<const pango::FontMap>
  {
    return const_cast<PrintContext*> (this)->get_pango_fontmap ();
  }

  auto
  PrintContext::create_pango_context () -> glib::RefPtr<pango::Context>
  {
    auto retvalue =
        glib::wrap (gtk_print_context_create_pango_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintContext::create_pango_layout () -> glib::RefPtr<pango::Layout>
  {
    auto retvalue =
        glib::wrap (gtk_print_context_create_pango_layout (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintContext::set_cairo_context (const cairo::RefPtr<cairo::Context>& cr,
                                   double dpi_x,
                                   double dpi_y) -> void
  {
    gtk_print_context_set_cairo_context (gobj (),
                                         ((cr) ? (cr)->cobj () : nullptr),
                                         dpi_x,
                                         dpi_y);
  }

} // namespace gtk
