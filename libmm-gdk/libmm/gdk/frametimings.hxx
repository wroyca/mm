// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_FRAMETIMINGS_H
#define _GDKMM_FRAMETIMINGS_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/refptr.hxx>

extern "C" typedef struct _GdkFrameTimings GdkFrameTimings;

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT FrameTimings final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FrameTimings;
    using BaseObjectType = GdkFrameTimings;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GdkFrameTimings*;

    auto
    gobj () const -> const GdkFrameTimings*;

    auto
    gobj_copy () const -> GdkFrameTimings*;

    FrameTimings () = delete;

    FrameTimings (const FrameTimings&) = delete;
    auto
    operator= (const FrameTimings&) -> FrameTimings& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    auto
    get_frame_counter () const -> gint64;

    auto
    get_complete () const -> bool;

    auto
    get_frame_time () const -> gint64;

    auto
    get_presentation_time () const -> gint64;

    auto
    get_refresh_interval () const -> gint64;

    auto
    get_predicted_presentation_time () const -> gint64;
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkFrameTimings* object, bool take_copy = false) -> glib::RefPtr<gdk::FrameTimings>;

} // namespace glib

#endif
