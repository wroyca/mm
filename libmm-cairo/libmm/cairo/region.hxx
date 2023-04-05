// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_REGION_H
#define __CAIROMM_REGION_H

#include <cairo.h>
#include <libmm/cairo/enums.hxx>
#include <libmm/cairo/refptr.hxx>
#include <libmm/cairo/types.hxx>
#include <vector>

namespace cairo
{

  class LIBMM_CAIRO_SYMEXPORT Region
  {
  private:
    Region ();

    explicit Region (const RectangleInt& rectangle);

    explicit Region (const std::vector<RectangleInt>& rects);
    Region (const RectangleInt* rects, int count);

  public:
    enum class Overlap
    {
      IN = CAIRO_REGION_OVERLAP_IN,

      OUT = CAIRO_REGION_OVERLAP_OUT,

      REGION_OVERLAP_PART = CAIRO_REGION_OVERLAP_PART
    };

    explicit Region (cairo_region_t* cobject, bool has_reference = false);

    static auto
    create () -> RefPtr<Region>;

    static auto
    create (const RectangleInt& rectangle) -> RefPtr<Region>;

    static auto
    create (const std::vector<RectangleInt>& rects) -> RefPtr<Region>;

    static auto
    create (const RectangleInt* rects, int count) -> RefPtr<Region>;

    auto
    copy () const -> RefPtr<Region>;

    virtual ~Region ();

    auto
    get_extents () const -> RectangleInt;

    auto
    get_num_rectangles () const -> int;

    auto
    get_rectangle (int nth_rectangle) const -> RectangleInt;

    auto
    empty () const -> bool;

    auto
    contains_rectangle (const RectangleInt& rectangle) const -> Overlap;

    auto
    contains_point (int x, int y) const -> bool;

    auto
    translate (int dx, int dy) -> void;

    auto
    subtract (const RefPtr<Region>& other) -> void;

    auto
    subtract (const RectangleInt& rectangle) -> void;

    auto
    intersect (const RefPtr<Region>& other) -> void;

    auto
    intersect (const RectangleInt& rectangle) -> void;

    auto
    do_union (const RefPtr<Region>& other) -> void;

    auto
    do_union (const RectangleInt& rectangle) -> void;

    auto
    do_xor (const RefPtr<Region>& other) -> void;

    auto
    do_xor (const RectangleInt& rectangle) -> void;

    typedef cairo_region_t cobject;

    inline auto
    cobj () -> cobject*
    {
      return m_cobject;
    }

    inline auto
    cobj () const -> const cobject*
    {
      return m_cobject;
    }

#ifndef DOXYGEN_IGNORE_THIS

    inline auto
    get_status () const -> ErrorStatus
    {
      return cairo_region_status (const_cast<cairo_region_t*> (cobj ()));
    }
#endif

    auto
    reference () const -> void;
    auto
    unreference () const -> void;

  protected:
    cobject* m_cobject;
  };

} // namespace cairo

#endif
