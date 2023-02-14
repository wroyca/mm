// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/frametimings.hxx>
#include <libmm-gdk/frametimings_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkFrameTimings* object, const bool take_copy) -> RefPtr<Gdk::FrameTimings>
  {
    if (take_copy && object)
      gdk_frame_timings_ref (object);

    return Glib::make_refptr_for_instance<Gdk::FrameTimings> (
        reinterpret_cast<Gdk::FrameTimings*> (object));
  }

} // namespace Glib

namespace Gdk
{

  auto
  FrameTimings::reference () const -> void
  {
    gdk_frame_timings_ref (
        reinterpret_cast<GdkFrameTimings*> (const_cast<FrameTimings*> (this)));
  }

  auto
  FrameTimings::unreference () const -> void
  {
    gdk_frame_timings_unref (
        reinterpret_cast<GdkFrameTimings*> (const_cast<FrameTimings*> (this)));
  }

  auto
  FrameTimings::gobj () -> GdkFrameTimings*
  {
    return reinterpret_cast<GdkFrameTimings*> (this);
  }

  auto
  FrameTimings::gobj () const -> const GdkFrameTimings*
  {
    return reinterpret_cast<const GdkFrameTimings*> (this);
  }

  auto
  FrameTimings::gobj_copy () const -> GdkFrameTimings*
  {
    const auto gobject =
        reinterpret_cast<GdkFrameTimings*> (const_cast<FrameTimings*> (this));
    gdk_frame_timings_ref (gobject);
    return gobject;
  }

  auto
  FrameTimings::get_frame_counter () const -> gint64
  {
    return gdk_frame_timings_get_frame_counter (
        const_cast<GdkFrameTimings*> (gobj ()));
  }

  auto
  FrameTimings::get_complete () const -> bool
  {
    return gdk_frame_timings_get_complete (
        const_cast<GdkFrameTimings*> (gobj ()));
  }

  auto
  FrameTimings::get_frame_time () const -> gint64
  {
    return gdk_frame_timings_get_frame_time (
        const_cast<GdkFrameTimings*> (gobj ()));
  }

  auto
  FrameTimings::get_presentation_time () const -> gint64
  {
    return gdk_frame_timings_get_presentation_time (
        const_cast<GdkFrameTimings*> (gobj ()));
  }

  auto
  FrameTimings::get_refresh_interval () const -> gint64
  {
    return gdk_frame_timings_get_refresh_interval (
        const_cast<GdkFrameTimings*> (gobj ()));
  }

  auto
  FrameTimings::get_predicted_presentation_time () const -> gint64
  {
    return gdk_frame_timings_get_predicted_presentation_time (
        const_cast<GdkFrameTimings*> (gobj ()));
  }

} // namespace Gdk
