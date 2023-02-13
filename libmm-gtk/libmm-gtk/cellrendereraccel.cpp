


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/cellrendereraccel.hpp>
#include <mm/gtk/private/cellrendereraccel_p.hpp>


/*
 * Copyright 2005 The gtkmm Development Team
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

using Mode = Gtk::CellRendererAccel::Mode;

namespace Gtk
{

auto CellRendererAccel::_property_renderable() -> Glib::PropertyProxy_Base
{
  //Renderering just this one property would probably not be meaningful.
  return property_accel_key();
}

} //namespace Gtk

namespace
{


auto CellRendererAccel_signal_accel_edited_callback (
  GtkCellRendererAccel *self, const gchar *p0, const guint p1, GdkModifierType p2, const guint p3,
  void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&, guint, Gdk::ModifierType, guint)>;

  const auto obj = dynamic_cast<CellRendererAccel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
, p1, static_cast<Gdk::ModifierType>(p2)
, p3);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo CellRendererAccel_signal_accel_edited_info =
{
  "accel_edited",
  (GCallback) &CellRendererAccel_signal_accel_edited_callback,
  (GCallback) &CellRendererAccel_signal_accel_edited_callback
};


auto CellRendererAccel_signal_accel_cleared_callback (
  GtkCellRendererAccel *self, const gchar *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  const auto obj = dynamic_cast<CellRendererAccel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo CellRendererAccel_signal_accel_cleared_info =
{
  "accel_cleared",
  (GCallback) &CellRendererAccel_signal_accel_cleared_callback,
  (GCallback) &CellRendererAccel_signal_accel_cleared_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::CellRendererAccel::Mode>::value_type() -> GType
{
  return gtk_cell_renderer_accel_mode_get_type();
}


namespace Glib
{

auto wrap(GtkCellRendererAccel* object, const bool take_copy) -> Gtk::CellRendererAccel*
{
  return dynamic_cast<Gtk::CellRendererAccel *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellRendererAccel_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererAccel_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_accel_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto CellRendererAccel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellRendererAccel_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellRendererAccel((GtkCellRendererAccel*)o));

}


/* The implementation: */

CellRendererAccel::CellRendererAccel(const Glib::ConstructParams& construct_params)
: CellRendererText(construct_params)
{
  }

CellRendererAccel::CellRendererAccel(GtkCellRendererAccel* castitem)
: CellRendererText((GtkCellRendererText*)castitem)
{
  }


CellRendererAccel::CellRendererAccel(CellRendererAccel&& src) noexcept
: CellRendererText(std::move(src))
{}

auto CellRendererAccel::operator=(CellRendererAccel&& src) noexcept -> CellRendererAccel&
{
  CellRendererText::operator=(std::move(src));
  return *this;
}

CellRendererAccel::~CellRendererAccel() noexcept
{
  destroy_();
}

CellRendererAccel::CppClassType CellRendererAccel::cellrendereraccel_class_; // initialize static member

auto CellRendererAccel::get_type() -> GType
{
  return cellrendereraccel_class_.init().get_type();
}


auto CellRendererAccel::get_base_type() -> GType
{
  return gtk_cell_renderer_accel_get_type();
}


CellRendererAccel::CellRendererAccel()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
CellRendererText(Glib::ConstructParams(cellrendereraccel_class_.init()))
{


}


auto CellRendererAccel::signal_accel_edited() -> Glib::SignalProxy<void(const Glib::ustring&, guint, Gdk::ModifierType, guint)>
{
  return {this, &CellRendererAccel_signal_accel_edited_info};
}


auto CellRendererAccel::signal_accel_cleared() -> Glib::SignalProxy<void(const Glib::ustring&)>
{
  return {this, &CellRendererAccel_signal_accel_cleared_info};
}


auto CellRendererAccel::property_accel_key() -> Glib::PropertyProxy< guint >
{
  return {this, "accel-key"};
}

auto CellRendererAccel::property_accel_key() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "accel-key"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::ModifierType>::value,
  "Type Gdk::ModifierType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererAccel::property_accel_mods() -> Glib::PropertyProxy< Gdk::ModifierType >
{
  return {this, "accel-mods"};
}

auto CellRendererAccel::property_accel_mods() const -> Glib::PropertyProxy_ReadOnly< Gdk::ModifierType >
{
  return {this, "accel-mods"};
}

auto CellRendererAccel::property_keycode() -> Glib::PropertyProxy< guint >
{
  return {this, "keycode"};
}

auto CellRendererAccel::property_keycode() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "keycode"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Mode>::value,
  "Type Mode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererAccel::property_accel_mode() -> Glib::PropertyProxy< Mode >
{
  return {this, "accel-mode"};
}

auto CellRendererAccel::property_accel_mode() const -> Glib::PropertyProxy_ReadOnly< Mode >
{
  return {this, "accel-mode"};
}


} // namespace Gtk


