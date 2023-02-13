


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/cellrendererprogress.hxx>
#include <libmm-gtk/cellrendererprogress_p.hxx>


/*
 * Copyright 2004 The gtkmm Development Team
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

namespace Gtk
{

auto CellRendererProgress::_property_renderable() -> Glib::PropertyProxy_Base
{
  return property_value();
}


} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellRendererProgress* object, const bool take_copy) -> Gtk::CellRendererProgress*
{
  return dynamic_cast<Gtk::CellRendererProgress *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellRendererProgress_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererProgress_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_progress_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto CellRendererProgress_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellRendererProgress_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellRendererProgress((GtkCellRendererProgress*)o));

}


/* The implementation: */

CellRendererProgress::CellRendererProgress(const Glib::ConstructParams& construct_params)
: CellRenderer(construct_params)
{
  }

CellRendererProgress::CellRendererProgress(GtkCellRendererProgress* castitem)
: CellRenderer((GtkCellRenderer*)castitem)
{
  }


CellRendererProgress::CellRendererProgress(CellRendererProgress&& src) noexcept
: CellRenderer(std::move(src))
  , Orientable(std::move(src))
{}

auto CellRendererProgress::operator=(CellRendererProgress&& src) noexcept -> CellRendererProgress&
{
  CellRenderer::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

CellRendererProgress::~CellRendererProgress() noexcept
{
  destroy_();
}

CellRendererProgress::CppClassType CellRendererProgress::cellrendererprogress_class_; // initialize static member

auto CellRendererProgress::get_type() -> GType
{
  return cellrendererprogress_class_.init().get_type();
}


auto CellRendererProgress::get_base_type() -> GType
{
  return gtk_cell_renderer_progress_get_type();
}


CellRendererProgress::CellRendererProgress()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
CellRenderer(Glib::ConstructParams(cellrendererprogress_class_.init()))
{


}


auto CellRendererProgress::property_value() -> Glib::PropertyProxy< int >
{
  return {this, "value"};
}

auto CellRendererProgress::property_value() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "value"};
}

auto CellRendererProgress::property_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "text"};
}

auto CellRendererProgress::property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "text"};
}

auto CellRendererProgress::property_pulse() -> Glib::PropertyProxy< int >
{
  return {this, "pulse"};
}

auto CellRendererProgress::property_pulse() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "pulse"};
}

auto CellRendererProgress::property_text_xalign() -> Glib::PropertyProxy< float >
{
  return {this, "text-xalign"};
}

auto CellRendererProgress::property_text_xalign() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return {this, "text-xalign"};
}

auto CellRendererProgress::property_text_yalign() -> Glib::PropertyProxy< float >
{
  return {this, "text-yalign"};
}

auto CellRendererProgress::property_text_yalign() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return {this, "text-yalign"};
}

auto CellRendererProgress::property_inverted() -> Glib::PropertyProxy< bool >
{
  return {this, "inverted"};
}

auto CellRendererProgress::property_inverted() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "inverted"};
}


} // namespace Gtk

