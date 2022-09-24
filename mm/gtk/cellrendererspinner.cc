// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/cellrendererspinner.h>
#include <mm/gtk/private/cellrendererspinner_p.h>

#include <gtk/gtk.h>

/*
 * Copyright 2009 The gtkmm Development Team
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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellRendererSpinner* object, bool take_copy) -> Gtk::CellRendererSpinner*
{
  return dynamic_cast<Gtk::CellRendererSpinner *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellRendererSpinner_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererSpinner_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_spinner_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void CellRendererSpinner_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellRendererSpinner_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellRendererSpinner((GtkCellRendererSpinner*)(o)));

}


/* The implementation: */

CellRendererSpinner::CellRendererSpinner(const Glib::ConstructParams& construct_params)
:
  Gtk::CellRenderer(construct_params)
{
  }

CellRendererSpinner::CellRendererSpinner(GtkCellRendererSpinner* castitem)
:
  Gtk::CellRenderer((GtkCellRenderer*)(castitem))
{
  }


CellRendererSpinner::CellRendererSpinner(CellRendererSpinner&& src) noexcept
: Gtk::CellRenderer(std::move(src))
{}

auto CellRendererSpinner::operator=(CellRendererSpinner&& src) noexcept -> CellRendererSpinner&
{
  Gtk::CellRenderer::operator=(std::move(src));
  return *this;
}

CellRendererSpinner::~CellRendererSpinner() noexcept
{
  destroy_();
}

CellRendererSpinner::CppClassType CellRendererSpinner::cellrendererspinner_class_; // initialize static member

auto CellRendererSpinner::get_type() -> GType
{
  return cellrendererspinner_class_.init().get_type();
}


auto CellRendererSpinner::get_base_type() -> GType
{
  return gtk_cell_renderer_spinner_get_type();
}


CellRendererSpinner::CellRendererSpinner()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::CellRenderer(Glib::ConstructParams(cellrendererspinner_class_.init()))
{


}


auto CellRendererSpinner::property_active() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "active");
}

auto CellRendererSpinner::property_active() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "active");
}

auto CellRendererSpinner::property_pulse() -> Glib::PropertyProxy< guint >
{
  return Glib::PropertyProxy< guint >(this, "pulse");
}

auto CellRendererSpinner::property_pulse() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return Glib::PropertyProxy_ReadOnly< guint >(this, "pulse");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gtk::IconSize>::value,
  "Type Gtk::IconSize cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererSpinner::property_size() -> Glib::PropertyProxy< Gtk::IconSize >
{
  return Glib::PropertyProxy< Gtk::IconSize >(this, "size");
}

auto CellRendererSpinner::property_size() const -> Glib::PropertyProxy_ReadOnly< Gtk::IconSize >
{
  return Glib::PropertyProxy_ReadOnly< Gtk::IconSize >(this, "size");
}


} // namespace Gtk


