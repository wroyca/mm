// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/gesturestylus.h>
#include <gtkmm/private/gesturestylus_p.h>


/* Copyright (C) 2018 The gtkmm Development Team
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

#include <gdkmm/devicetool.h>
#include <gtk/gtk.h>
#include <memory>

namespace Gtk
{

std::optional<double> GestureStylus::get_axis(Gdk::AxisUse axis) const
{
  double g_value = double();
  auto retvalue = gtk_gesture_stylus_get_axis(
    const_cast<GtkGestureStylus*>(gobj()), static_cast<GdkAxisUse>(axis), &g_value);

  if (retvalue)
    return g_value;
  else
    return {};
}

std::vector<double> GestureStylus::get_axes(const std::vector<Gdk::AxisUse>& axes) const
{
  // Glib::ArrayHandler is not used for axes.
  // Glib::ArrayHandler::vector_to_array() creates a 0-terminated array,
  // but it might be risky to rely on GDK_AXIS_IGNORE being 0.
  auto g_axes = std::make_unique<GdkAxisUse[]>(axes.size() + 1);
  for (std::size_t i = 0; i < axes.size(); ++i)
    g_axes[i] = static_cast<GdkAxisUse>(axes[i]);
  g_axes[axes.size()] = GDK_AXIS_IGNORE;

  double* g_values = nullptr;
  const bool result = gtk_gesture_stylus_get_axes(
    const_cast<GtkGestureStylus*>(gobj()), g_axes.get(), &g_values);

  if (result)
    return Glib::ArrayHandler<double>::array_to_vector(
      g_values, axes.size(), Glib::OWNERSHIP_DEEP);
  else
    return {};
}

std::vector<Gdk::TimeCoord> GestureStylus::get_backlog() const
{
  GdkTimeCoord* g_backlog = nullptr;
  guint n_elems = 0;
  const bool result = gtk_gesture_stylus_get_backlog(
    const_cast<GtkGestureStylus*>(gobj()), &g_backlog, &n_elems);

  if (result)
    return Glib::ArrayHandler<Gdk::TimeCoord, Gdk::TimeCoordTraits>::array_to_vector(
      g_backlog, n_elems, Glib::OWNERSHIP_DEEP);
  else
    return {};
}

} // namespace Gtk

namespace
{


static void GestureStylus_signal_proximity_callback(GtkGestureStylus* self, gdouble p0,gdouble p1,void* data)
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  auto obj = dynamic_cast<GestureStylus*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

static const Glib::SignalProxyInfo GestureStylus_signal_proximity_info =
{
  "proximity",
  (GCallback) &GestureStylus_signal_proximity_callback,
  (GCallback) &GestureStylus_signal_proximity_callback
};


static void GestureStylus_signal_down_callback(GtkGestureStylus* self, gdouble p0,gdouble p1,void* data)
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  auto obj = dynamic_cast<GestureStylus*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

static const Glib::SignalProxyInfo GestureStylus_signal_down_info =
{
  "down",
  (GCallback) &GestureStylus_signal_down_callback,
  (GCallback) &GestureStylus_signal_down_callback
};


static void GestureStylus_signal_motion_callback(GtkGestureStylus* self, gdouble p0,gdouble p1,void* data)
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  auto obj = dynamic_cast<GestureStylus*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

static const Glib::SignalProxyInfo GestureStylus_signal_motion_info =
{
  "motion",
  (GCallback) &GestureStylus_signal_motion_callback,
  (GCallback) &GestureStylus_signal_motion_callback
};


static void GestureStylus_signal_up_callback(GtkGestureStylus* self, gdouble p0,gdouble p1,void* data)
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  auto obj = dynamic_cast<GestureStylus*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

static const Glib::SignalProxyInfo GestureStylus_signal_up_info =
{
  "up",
  (GCallback) &GestureStylus_signal_up_callback,
  (GCallback) &GestureStylus_signal_up_callback
};


} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::GestureStylus> wrap(GtkGestureStylus* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gtk::GestureStylus>( dynamic_cast<Gtk::GestureStylus*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& GestureStylus_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GestureStylus_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gesture_stylus_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void GestureStylus_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* GestureStylus_Class::wrap_new(GObject* object)
{
  return new GestureStylus((GtkGestureStylus*)object);
}


/* The implementation: */

GtkGestureStylus* GestureStylus::gobj_copy()
{
  reference();
  return gobj();
}

GestureStylus::GestureStylus(const Glib::ConstructParams& construct_params)
:
  GestureSingle(construct_params)
{

}

GestureStylus::GestureStylus(GtkGestureStylus* castitem)
:
  GestureSingle((GtkGestureSingle*)(castitem))
{}


GestureStylus::GestureStylus(GestureStylus&& src) noexcept
: GestureSingle(std::move(src))
{}

GestureStylus& GestureStylus::operator=(GestureStylus&& src) noexcept
{
  GestureSingle::operator=(std::move(src));
  return *this;
}


GestureStylus::~GestureStylus() noexcept
{}


GestureStylus::CppClassType GestureStylus::gesturestylus_class_; // initialize static member

GType GestureStylus::get_type()
{
  return gesturestylus_class_.init().get_type();
}


GType GestureStylus::get_base_type()
{
  return gtk_gesture_stylus_get_type();
}


GestureStylus::GestureStylus()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  GestureSingle(Glib::ConstructParams(gesturestylus_class_.init()))
{
  

}

Glib::RefPtr<GestureStylus> GestureStylus::create()
{
  return Glib::make_refptr_for_instance<GestureStylus>( new GestureStylus() );
}

Glib::RefPtr<Gdk::DeviceTool> GestureStylus::get_device_tool()
{
  auto retvalue = Glib::wrap(gtk_gesture_stylus_get_device_tool(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gdk::DeviceTool> GestureStylus::get_device_tool() const
{
  return const_cast<GestureStylus*>(this)->get_device_tool();
}


Glib::SignalProxy<void(double, double)> GestureStylus::signal_proximity()
{
  return Glib::SignalProxy<void(double, double) >(this, &GestureStylus_signal_proximity_info);
}


Glib::SignalProxy<void(double, double)> GestureStylus::signal_down()
{
  return Glib::SignalProxy<void(double, double) >(this, &GestureStylus_signal_down_info);
}


Glib::SignalProxy<void(double, double)> GestureStylus::signal_motion()
{
  return Glib::SignalProxy<void(double, double) >(this, &GestureStylus_signal_motion_info);
}


Glib::SignalProxy<void(double, double)> GestureStylus::signal_up()
{
  return Glib::SignalProxy<void(double, double) >(this, &GestureStylus_signal_up_info);
}


} // namespace Gtk


