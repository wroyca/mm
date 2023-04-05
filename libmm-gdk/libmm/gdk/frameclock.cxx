// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/frameclock.hxx>
#include <libmm/gdk/frameclock_p.hxx>

#include <gdk/gdk.h>

namespace
{

  static const glib::SignalProxyInfo FrameClock_signal_update_info = {
      "update",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo FrameClock_signal_layout_info = {
      "layout",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo FrameClock_signal_paint_info = {
      "paint",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
glib::Value<gdk::FrameClock::Phase>::value_type () -> GType
{
  return gdk_frame_clock_phase_get_type ();
}

namespace glib
{

  auto
  wrap (GdkFrameClock* object, bool take_copy) -> glib::RefPtr<gdk::FrameClock>
  {
    return glib::make_refptr_for_instance<gdk::FrameClock> (
        dynamic_cast<gdk::FrameClock*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  FrameClock_Class::init () -> const glib::Class&
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
  FrameClock_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FrameClock ((GdkFrameClock*) object);
  }

  auto
  FrameClock::gobj_copy () -> GdkFrameClock*
  {
    reference ();
    return gobj ();
  }

  FrameClock::FrameClock (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  FrameClock::FrameClock (GdkFrameClock* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  FrameClock::FrameClock (FrameClock&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  FrameClock::operator= (FrameClock&& src) noexcept -> FrameClock&
  {
    glib::Object::operator= (std::move (src));
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
  FrameClock::get_timings (gint64 frame_counter) -> glib::RefPtr<FrameTimings>
  {
    auto retvalue =
        glib::wrap (gdk_frame_clock_get_timings (gobj (), frame_counter));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FrameClock::get_timings (gint64 frame_counter) const -> glib::RefPtr<const FrameTimings>
  {
    return const_cast<FrameClock*> (this)->get_timings (frame_counter);
  }

  auto
  FrameClock::get_current_timings () -> glib::RefPtr<FrameTimings>
  {
    auto retvalue = glib::wrap (gdk_frame_clock_get_current_timings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FrameClock::get_current_timings () const -> glib::RefPtr<const FrameTimings>
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
  FrameClock::signal_update () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &FrameClock_signal_update_info);
  }

  auto
  FrameClock::signal_layout () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &FrameClock_signal_layout_info);
  }

  auto
  FrameClock::signal_paint () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &FrameClock_signal_paint_info);
  }

} // namespace gdk
