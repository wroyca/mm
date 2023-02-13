


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/frameclock.hpp>
#include <mm/gdk/private/frameclock_p.hpp>

#include <gdk/gdk.h>

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


namespace
{


const Glib::SignalProxyInfo FrameClock_signal_update_info =
{
  "update",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo FrameClock_signal_layout_info =
{
  "layout",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo FrameClock_signal_paint_info =
{
  "paint",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gdk::FrameClock::Phase>::value_type() -> GType
{
  return gdk_frame_clock_phase_get_type();
}


namespace Glib
{

auto wrap(GdkFrameClock* object, const bool take_copy) -> RefPtr<Gdk::FrameClock>
{
  return Glib::make_refptr_for_instance<Gdk::FrameClock>( dynamic_cast<Gdk::FrameClock*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto FrameClock_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FrameClock_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_frame_clock_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto FrameClock_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FrameClock_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FrameClock((GdkFrameClock*)object);
}


/* The implementation: */

auto FrameClock::gobj_copy() -> GdkFrameClock*
{
  reference();
  return gobj();
}

FrameClock::FrameClock(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FrameClock::FrameClock(GdkFrameClock* castitem)
: Object((GObject*)castitem)
{}


FrameClock::FrameClock(FrameClock&& src) noexcept
: Object(std::move(src))
{}

auto FrameClock::operator=(FrameClock&& src) noexcept -> FrameClock&
{
  Object::operator=(std::move(src));
  return *this;
}


FrameClock::~FrameClock() noexcept = default;

FrameClock::CppClassType FrameClock::frameclock_class_; // initialize static member

auto FrameClock::get_type() -> GType
{
  return frameclock_class_.init().get_type();
}


auto FrameClock::get_base_type() -> GType
{
  return gdk_frame_clock_get_type();
}


auto FrameClock::get_frame_time() const -> gint64
{
  return gdk_frame_clock_get_frame_time(const_cast<GdkFrameClock*>(gobj()));
}

auto FrameClock::request_phase (Phase phase) -> void
{
  gdk_frame_clock_request_phase(gobj(), static_cast<GdkFrameClockPhase>(phase));
}

auto FrameClock::begin_updating () -> void
{
  gdk_frame_clock_begin_updating(gobj());
}

auto FrameClock::end_updating () -> void
{
  gdk_frame_clock_end_updating(gobj());
}

auto FrameClock::get_frame_counter() const -> gint64
{
  return gdk_frame_clock_get_frame_counter(const_cast<GdkFrameClock*>(gobj()));
}

auto FrameClock::get_history_start() const -> gint64
{
  return gdk_frame_clock_get_history_start(const_cast<GdkFrameClock*>(gobj()));
}

auto FrameClock::get_timings(
  const gint64 frame_counter) -> Glib::RefPtr<FrameTimings>
{
  auto retvalue = Glib::wrap(gdk_frame_clock_get_timings(gobj(), frame_counter));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FrameClock::get_timings(
  const gint64 frame_counter) const -> Glib::RefPtr<const FrameTimings>
{
  return const_cast<FrameClock*>(this)->get_timings(frame_counter);
}

auto FrameClock::get_current_timings() -> Glib::RefPtr<FrameTimings>
{
  auto retvalue = Glib::wrap(gdk_frame_clock_get_current_timings(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FrameClock::get_current_timings() const -> Glib::RefPtr<const FrameTimings>
{
  return const_cast<FrameClock*>(this)->get_current_timings();
}

auto FrameClock::get_refresh_info (
  const gint64 base_time, gint64 &refresh_interval_return, gint64 &presentation_time_return) const -> void
{
  gdk_frame_clock_get_refresh_info(const_cast<GdkFrameClock*>(gobj()), base_time, &refresh_interval_return, &presentation_time_return);
}

auto FrameClock::get_fps() const -> double
{
  return gdk_frame_clock_get_fps(const_cast<GdkFrameClock*>(gobj()));
}


auto FrameClock::signal_update() -> Glib::SignalProxy<void()>
{
  return {this, &FrameClock_signal_update_info};
}


auto FrameClock::signal_layout() -> Glib::SignalProxy<void()>
{
  return {this, &FrameClock_signal_layout_info};
}


auto FrameClock::signal_paint() -> Glib::SignalProxy<void()>
{
  return {this, &FrameClock_signal_paint_info};
}


} // namespace Gdk


