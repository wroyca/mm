


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/printcontext.hpp>
#include <mm/gtk/private/printcontext_p.hpp>


/* Copyright (C) 2006 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>
#include <mm/gdk/cairoutils.hpp>

namespace Gtk
{


} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkPrintContext* object, const bool take_copy) -> RefPtr<Gtk::PrintContext>
{
  return Glib::make_refptr_for_instance<Gtk::PrintContext>( dynamic_cast<Gtk::PrintContext*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto PrintContext_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PrintContext_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_print_context_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto PrintContext_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto PrintContext_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new PrintContext((GtkPrintContext*)object);
}


/* The implementation: */

auto PrintContext::gobj_copy() -> GtkPrintContext*
{
  reference();
  return gobj();
}

PrintContext::PrintContext(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

PrintContext::PrintContext(GtkPrintContext* castitem)
: Object((GObject*)castitem)
{}


PrintContext::PrintContext(PrintContext&& src) noexcept
: Object(std::move(src))
{}

auto PrintContext::operator=(PrintContext&& src) noexcept -> PrintContext&
{
  Object::operator=(std::move(src));
  return *this;
}


PrintContext::~PrintContext() noexcept = default;

PrintContext::CppClassType PrintContext::printcontext_class_; // initialize static member

auto PrintContext::get_type() -> GType
{
  return printcontext_class_.init().get_type();
}


auto PrintContext::get_base_type() -> GType
{
  return gtk_print_context_get_type();
}


auto PrintContext::get_cairo_context() -> Cairo::RefPtr<Cairo::Context>
{
  auto retvalue = Gdk::Cairo::wrap(gtk_print_context_get_cairo_context(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PrintContext::get_cairo_context() const -> Cairo::RefPtr<const Cairo::Context>
{
  return const_cast<PrintContext*>(this)->get_cairo_context();
}

auto PrintContext::get_page_setup() -> Glib::RefPtr<PageSetup>
{
  auto retvalue = Glib::wrap(gtk_print_context_get_page_setup(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PrintContext::get_page_setup() const -> Glib::RefPtr<const PageSetup>
{
  return const_cast<PrintContext*>(this)->get_page_setup();
}

auto PrintContext::get_width() const -> double
{
  return gtk_print_context_get_width(const_cast<GtkPrintContext*>(gobj()));
}

auto PrintContext::get_height() const -> double
{
  return gtk_print_context_get_height(const_cast<GtkPrintContext*>(gobj()));
}

auto PrintContext::get_dpi_x() const -> double
{
  return gtk_print_context_get_dpi_x(const_cast<GtkPrintContext*>(gobj()));
}

auto PrintContext::get_dpi_y() const -> double
{
  return gtk_print_context_get_dpi_y(const_cast<GtkPrintContext*>(gobj()));
}

auto PrintContext::get_hard_margins(double& top, double& bottom, double& left, double& right) const -> bool
{
  return gtk_print_context_get_hard_margins(const_cast<GtkPrintContext*>(gobj()), &top, &bottom, &left, &right);
}

auto PrintContext::get_pango_fontmap() -> Glib::RefPtr<Pango::FontMap>
{
  auto retvalue = Glib::wrap(gtk_print_context_get_pango_fontmap(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PrintContext::get_pango_fontmap() const -> Glib::RefPtr<const Pango::FontMap>
{
  return const_cast<PrintContext*>(this)->get_pango_fontmap();
}

auto PrintContext::create_pango_context() -> Glib::RefPtr<Pango::Context>
{
  auto retvalue = Glib::wrap(gtk_print_context_create_pango_context(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PrintContext::create_pango_layout() -> Glib::RefPtr<Pango::Layout>
{
  auto retvalue = Glib::wrap(gtk_print_context_create_pango_layout(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PrintContext::set_cairo_context (
  const Cairo::RefPtr <Cairo::Context> &cr, const double dpi_x, const double dpi_y) -> void
{
  gtk_print_context_set_cairo_context(gobj(), cr ? cr->cobj() : nullptr, dpi_x, dpi_y);
}


} // namespace Gtk


