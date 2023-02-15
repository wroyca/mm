// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/frameclock.hxx>
#include <libmm-gdk/frameclock_p.hxx>

#include <gdk/gdk.h>

namespace
{

  static const Glib::SignalProxyInfo FrameClock_signal_update_info = {
      "update",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo FrameClock_signal_layout_info = {
      "layout",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo FrameClock_signal_paint_info = {
      "paint",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
Glib::Value<Gdk::FrameClock::Phase>::value_type () -> GType
{
  return gdk_frame_clock_phase_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkFrameClock* object, bool take_copy) -> Glib::RefPtr<Gdk::FrameClock>
  {
    return Glib::make_refptr_for_instance<Gdk::FrameClock> (
        dynamic_cast<Gdk::FrameClock*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  FrameClock_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FrameClock_Class::class_init_function;

      register_derived_type (gdk_frame_clock_get_type ());
    }

    return *this;
  }

  auto
  FrameClock_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FrameClock_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FrameClock ((GdkFrameClock*) object);
  }

  auto
  FrameClock::gobj_copy () -> GdkFrameClock*
  {
    reference ();
    return gobj ();
  }

  FrameClock::FrameClock (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  FrameClock::FrameClock (GdkFrameClock* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  FrameClock::FrameClock (FrameClock&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  FrameClock::operator= (FrameClock&& src) noexcept -> FrameClock&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  FrameClock::~FrameClock () noexcept {}

  FrameClock::CppClassType FrameClock::frameclock_class_;

  auto
  FrameClock::get_type () -> GType
  {
    return frameclock_class_.init ().get_type ();
  }

  auto
  FrameClock::get_base_type () -> GType
  {
    return gdk_frame_clock_get_type ();
  }

  auto
  FrameClock::get_frame_time () const -> gint64
  {
    return gdk_frame_clock_get_frame_time (
        const_cast<GdkFrameClock*> (gobj ()));
  }

  auto
  FrameClock::request_phase (Phase phase) -> void
  {
    gdk_frame_clock_request_phase (gobj (),
                                   static_cast<GdkFrameClockPhase> (phase));
  }

  auto
  FrameClock::begin_updating () -> void
  {
    gdk_frame_clock_begin_updating (gobj ());
  }

  auto
  FrameClock::end_updating () -> void
  {
    gdk_frame_clock_end_updating (gobj ());
  }

  auto
  FrameClock::get_frame_counter () const -> gint64
  {
    return gdk_frame_clock_get_frame_counter (
        const_cast<GdkFrameClock*> (gobj ()));
  }

  auto
  FrameClock::get_history_start () const -> gint64
  {
    return gdk_frame_clock_get_history_start (
        const_cast<GdkFrameClock*> (gobj ()));
  }

  auto
  FrameClock::get_timings (gint64 frame_counter) -> Glib::RefPtr<FrameTimings>
  {
    auto retvalue =
        Glib::wrap (gdk_frame_clock_get_timings (gobj (), frame_counter));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FrameClock::get_timings (gint64 frame_counter) const -> Glib::RefPtr<const FrameTimings>
  {
    return const_cast<FrameClock*> (this)->get_timings (frame_counter);
  }

  auto
  FrameClock::get_current_timings () -> Glib::RefPtr<FrameTimings>
  {
    auto retvalue = Glib::wrap (gdk_frame_clock_get_current_timings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FrameClock::get_current_timings () const -> Glib::RefPtr<const FrameTimings>
  {
    return const_cast<FrameClock*> (this)->get_current_timings ();
  }

  auto
  FrameClock::get_refresh_info (gint64 base_time,
                                gint64& refresh_interval_return,
                                gint64& presentation_time_return) const -> void
  {
    gdk_frame_clock_get_refresh_info (const_cast<GdkFrameClock*> (gobj ()),
                                      base_time,
                                      &(refresh_interval_return),
                                      &(presentation_time_return));
  }

  auto
  FrameClock::get_fps () const -> double
  {
    return gdk_frame_clock_get_fps (const_cast<GdkFrameClock*> (gobj ()));
  }

  auto
  FrameClock::signal_update () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &FrameClock_signal_update_info);
  }

  auto
  FrameClock::signal_layout () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &FrameClock_signal_layout_info);
  }

  auto
  FrameClock::signal_paint () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &FrameClock_signal_paint_info);
  }

} // namespace Gdk
