// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_LAYOUTLINE_H
#define _PANGOMM_LAYOUTLINE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-cairo/context.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-pango/rectangle.hxx>
#include <pango/pango.h>

namespace Pango
{

  class LIBMM_PANGO_SYMEXPORT Layout;

  class LIBMM_PANGO_SYMEXPORT LayoutLine final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = LayoutLine;
    using BaseObjectType = PangoLayoutLine;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> PangoLayoutLine*;

    auto
    gobj () const -> const PangoLayoutLine*;

    auto
    gobj_copy () const -> PangoLayoutLine*;

    LayoutLine () = delete;

    LayoutLine (const LayoutLine&) = delete;
    auto
    operator= (const LayoutLine&) -> LayoutLine& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    auto
    x_to_index (int x_pos, int& index, int& trailing) const -> bool;

    auto
    index_to_x (int index, bool trailing) const -> int;

    auto
    get_x_ranges (int start_index, int end_index) const
        -> std::vector<std::pair<int, int>>;

    auto
    get_extents (Rectangle& ink_rect, Rectangle& logical_rect) const -> void;

    auto
    get_ink_extents () const -> Rectangle;

    auto
    get_logical_extents () const -> Rectangle;

    auto
    get_pixel_extents (Rectangle& ink_rect, Rectangle& logical_rect) const
        -> void;

    auto
    get_pixel_ink_extents () const -> Rectangle;

    auto
    get_pixel_logical_extents () const -> Rectangle;

    auto
    show_in_cairo_context (const Cairo::RefPtr<Cairo::Context>& context)
        -> void;

    auto
    add_to_cairo_context (const Cairo::RefPtr<Cairo::Context>& context) -> void;

    auto
    get_layout () -> Glib::RefPtr<Pango::Layout>;
    auto
    get_layout () const -> Glib::RefPtr<const Pango::Layout>;

    auto
    get_length () const -> int;
    auto
    get_start_index () const -> int;
  };

} // namespace Pango

namespace Glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoLayoutLine* object, bool take_copy = false) -> Glib::RefPtr<Pango::LayoutLine>;

} // namespace Glib

#endif
