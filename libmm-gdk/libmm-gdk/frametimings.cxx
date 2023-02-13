


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/frametimings.hxx>
#include <libmm-gdk/frametimings_p.hxx>

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
} // anonymous namespace


/* Why reinterpret_cast<FrameTimings*>(gobject) is needed:
 *
 * A FrameTimings instance is in fact always a GdkFrameTimings instance.
 * Unfortunately, GdkFrameTimings cannot be a member of FrameTimings,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because FrameTimings does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GdkFrameTimings* object, const bool take_copy) -> RefPtr<Gdk::FrameTimings>
{
  if(take_copy && object)
    gdk_frame_timings_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gdk::FrameTimings>(reinterpret_cast<Gdk::FrameTimings*>(object));
}

} // namespace Glib


namespace Gdk
{

auto FrameTimings::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_frame_timings_ref(reinterpret_cast<GdkFrameTimings*>(const_cast<FrameTimings*>(this)));
}

auto FrameTimings::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_frame_timings_unref(reinterpret_cast<GdkFrameTimings*>(const_cast<FrameTimings*>(this)));
}

auto FrameTimings::gobj() -> GdkFrameTimings*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GdkFrameTimings*>(this);
}

auto FrameTimings::gobj() const -> const GdkFrameTimings*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GdkFrameTimings*>(this);
}

auto FrameTimings::gobj_copy() const -> GdkFrameTimings*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GdkFrameTimings*>(const_cast<FrameTimings*>(this));
  gdk_frame_timings_ref(gobject);
  return gobject;
}


auto FrameTimings::get_frame_counter() const -> gint64
{
  return gdk_frame_timings_get_frame_counter(const_cast<GdkFrameTimings*>(gobj()));
}

auto FrameTimings::get_complete() const -> bool
{
  return gdk_frame_timings_get_complete(const_cast<GdkFrameTimings*>(gobj()));
}

auto FrameTimings::get_frame_time() const -> gint64
{
  return gdk_frame_timings_get_frame_time(const_cast<GdkFrameTimings*>(gobj()));
}

auto FrameTimings::get_presentation_time() const -> gint64
{
  return gdk_frame_timings_get_presentation_time(const_cast<GdkFrameTimings*>(gobj()));
}

auto FrameTimings::get_refresh_interval() const -> gint64
{
  return gdk_frame_timings_get_refresh_interval(const_cast<GdkFrameTimings*>(gobj()));
}

auto FrameTimings::get_predicted_presentation_time() const -> gint64
{
  return gdk_frame_timings_get_predicted_presentation_time(const_cast<GdkFrameTimings*>(gobj()));
}


} // namespace Gdk

