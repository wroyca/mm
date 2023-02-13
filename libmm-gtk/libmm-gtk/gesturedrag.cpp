


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/gesturedrag.hpp>
#include <libmm-gtk/gesturedrag_p.hpp>


/* Copyright (C) 2014 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace
{


auto GestureDrag_signal_drag_begin_callback (
  GtkGestureDrag *self, const gdouble p0, const gdouble p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<GestureDrag*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo GestureDrag_signal_drag_begin_info =
{
  "drag-begin",
  (GCallback) &GestureDrag_signal_drag_begin_callback,
  (GCallback) &GestureDrag_signal_drag_begin_callback
};


auto GestureDrag_signal_drag_update_callback (
  GtkGestureDrag *self, const gdouble p0, const gdouble p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<GestureDrag*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo GestureDrag_signal_drag_update_info =
{
  "drag-update",
  (GCallback) &GestureDrag_signal_drag_update_callback,
  (GCallback) &GestureDrag_signal_drag_update_callback
};


auto GestureDrag_signal_drag_end_callback (
  GtkGestureDrag *self, const gdouble p0, const gdouble p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<GestureDrag*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo GestureDrag_signal_drag_end_info =
{
  "drag-end",
  (GCallback) &GestureDrag_signal_drag_end_callback,
  (GCallback) &GestureDrag_signal_drag_end_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkGestureDrag* object, const bool take_copy) -> RefPtr<Gtk::GestureDrag>
{
  return Glib::make_refptr_for_instance<Gtk::GestureDrag>( dynamic_cast<Gtk::GestureDrag*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto GestureDrag_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GestureDrag_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gesture_drag_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto GestureDrag_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto GestureDrag_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new GestureDrag((GtkGestureDrag*)object);
}


/* The implementation: */

auto GestureDrag::gobj_copy() -> GtkGestureDrag*
{
  reference();
  return gobj();
}

GestureDrag::GestureDrag(const Glib::ConstructParams& construct_params)
:
  GestureSingle(construct_params)
{

}

GestureDrag::GestureDrag(GtkGestureDrag* castitem)
:
  GestureSingle((GtkGestureSingle*)castitem)
{}


GestureDrag::GestureDrag(GestureDrag&& src) noexcept
: GestureSingle(std::move(src))
{}

auto GestureDrag::operator=(GestureDrag&& src) noexcept -> GestureDrag&
{
  GestureSingle::operator=(std::move(src));
  return *this;
}


GestureDrag::~GestureDrag() noexcept = default;

GestureDrag::CppClassType GestureDrag::gesturedrag_class_; // initialize static member

auto GestureDrag::get_type() -> GType
{
  return gesturedrag_class_.init().get_type();
}


auto GestureDrag::get_base_type() -> GType
{
  return gtk_gesture_drag_get_type();
}


GestureDrag::GestureDrag()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  GestureSingle(Glib::ConstructParams(gesturedrag_class_.init()))
{


}

auto GestureDrag::create() -> Glib::RefPtr<GestureDrag>
{
  return Glib::make_refptr_for_instance<GestureDrag>( new GestureDrag() );
}

auto GestureDrag::get_start_point(double& x, double& y) const -> bool
{
  return gtk_gesture_drag_get_start_point(const_cast<GtkGestureDrag*>(gobj()), &x, &y);
}

auto GestureDrag::get_offset(double& x, double& y) const -> bool
{
  return gtk_gesture_drag_get_offset(const_cast<GtkGestureDrag*>(gobj()), &x, &y);
}


auto GestureDrag::signal_drag_begin() -> Glib::SignalProxy<void(double, double)>
{
  return {this, &GestureDrag_signal_drag_begin_info};
}


auto GestureDrag::signal_drag_update() -> Glib::SignalProxy<void(double, double)>
{
  return {this, &GestureDrag_signal_drag_update_info};
}


auto GestureDrag::signal_drag_end() -> Glib::SignalProxy<void(double, double)>
{
  return {this, &GestureDrag_signal_drag_end_info};
}


} // namespace Gtk


