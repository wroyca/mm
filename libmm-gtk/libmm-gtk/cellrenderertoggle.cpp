


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/cellrenderertoggle.hpp>
#include <libmm-gtk/cellrenderertoggle_p.hpp>


/*
 * Copyright 1998-2002 The gtkmm Development Team
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

auto CellRendererToggle::_property_renderable() -> Glib::PropertyProxy_Base
{
  return property_active();
}

} //namespace Gtk

namespace
{


auto CellRendererToggle_signal_toggled_callback (
  GtkCellRendererToggle *self, const gchar *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  const auto obj = dynamic_cast<CellRendererToggle*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo CellRendererToggle_signal_toggled_info =
{
  "toggled",
  (GCallback) &CellRendererToggle_signal_toggled_callback,
  (GCallback) &CellRendererToggle_signal_toggled_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellRendererToggle* object, const bool take_copy) -> Gtk::CellRendererToggle*
{
  return dynamic_cast<Gtk::CellRendererToggle *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellRendererToggle_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererToggle_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_toggle_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto CellRendererToggle_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellRendererToggle_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellRendererToggle((GtkCellRendererToggle*)o));

}


/* The implementation: */

CellRendererToggle::CellRendererToggle(const Glib::ConstructParams& construct_params)
: CellRenderer(construct_params)
{
  }

CellRendererToggle::CellRendererToggle(GtkCellRendererToggle* castitem)
: CellRenderer((GtkCellRenderer*)castitem)
{
  }


CellRendererToggle::CellRendererToggle(CellRendererToggle&& src) noexcept
: CellRenderer(std::move(src))
{}

auto CellRendererToggle::operator=(CellRendererToggle&& src) noexcept -> CellRendererToggle&
{
  CellRenderer::operator=(std::move(src));
  return *this;
}

CellRendererToggle::~CellRendererToggle() noexcept
{
  destroy_();
}

CellRendererToggle::CppClassType CellRendererToggle::cellrenderertoggle_class_; // initialize static member

auto CellRendererToggle::get_type() -> GType
{
  return cellrenderertoggle_class_.init().get_type();
}


auto CellRendererToggle::get_base_type() -> GType
{
  return gtk_cell_renderer_toggle_get_type();
}


CellRendererToggle::CellRendererToggle()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
CellRenderer(Glib::ConstructParams(cellrenderertoggle_class_.init()))
{


}

auto CellRendererToggle::get_radio() const -> bool
{
  return gtk_cell_renderer_toggle_get_radio(const_cast<GtkCellRendererToggle*>(gobj()));
}

auto CellRendererToggle::set_radio (
  const bool radio) -> void
{
  gtk_cell_renderer_toggle_set_radio(gobj(), radio);
}

auto CellRendererToggle::get_active() const -> bool
{
  return gtk_cell_renderer_toggle_get_active(const_cast<GtkCellRendererToggle*>(gobj()));
}

auto CellRendererToggle::set_active (
  const bool setting) -> void
{
  gtk_cell_renderer_toggle_set_active(gobj(), setting);
}

auto CellRendererToggle::get_activatable() const -> bool
{
  return gtk_cell_renderer_toggle_get_activatable(const_cast<GtkCellRendererToggle*>(gobj()));
}

auto CellRendererToggle::set_activatable (
  const bool setting) -> void
{
  gtk_cell_renderer_toggle_set_activatable(gobj(), setting);
}


auto CellRendererToggle::signal_toggled() -> Glib::SignalProxy<void(const Glib::ustring&)>
{
  return {this, &CellRendererToggle_signal_toggled_info};
}


auto CellRendererToggle::property_activatable() -> Glib::PropertyProxy< bool >
{
  return {this, "activatable"};
}

auto CellRendererToggle::property_activatable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "activatable"};
}

auto CellRendererToggle::property_active() -> Glib::PropertyProxy< bool >
{
  return {this, "active"};
}

auto CellRendererToggle::property_active() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "active"};
}

auto CellRendererToggle::property_inconsistent() -> Glib::PropertyProxy< bool >
{
  return {this, "inconsistent"};
}

auto CellRendererToggle::property_inconsistent() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "inconsistent"};
}

auto CellRendererToggle::property_radio() -> Glib::PropertyProxy< bool >
{
  return {this, "radio"};
}

auto CellRendererToggle::property_radio() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "radio"};
}


} // namespace Gtk


