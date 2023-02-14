// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_REGION_H
#define __CAIROMM_REGION_H

#include <cairo.h>
#include <libmm-cairo/enums.hxx>
#include <libmm-cairo/refptr.hxx>
#include <libmm-cairo/types.hxx>
#include <vector>

namespace Cairo
{

  class CAIROMM_API Region
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

    void
    translate (int dx, int dy);

    void
    subtract (const RefPtr<Region>& other);

    void
    subtract (const RectangleInt& rectangle);

    void
    intersect (const RefPtr<Region>& other);

    void
    intersect (const RectangleInt& rectangle);

    void
    do_union (const RefPtr<Region>& other);

    void
    do_union (const RectangleInt& rectangle);

    void
    do_xor (const RefPtr<Region>& other);

    void
    do_xor (const RectangleInt& rectangle);

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

    void
    reference () const;
    void
    unreference () const;

  protected:
    cobject* m_cobject;
  };

} // namespace Cairo

#endif
