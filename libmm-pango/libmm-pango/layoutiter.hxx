
#ifndef _PANGOMM_LAYOUTITER_H
#define _PANGOMM_LAYOUTITER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-pango/glyphitem.hxx>
#include <libmm-pango/layoutline.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoLayoutIter PangoLayoutIter;
}
#endif

namespace Pango
{

  class PANGOMM_API LayoutIter
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = LayoutIter;
    using BaseObjectType = PangoLayoutIter;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    LayoutIter ();

    explicit LayoutIter (PangoLayoutIter* gobject, bool make_a_copy = true);

    LayoutIter (const LayoutIter& other);
    auto
    operator= (const LayoutIter& other) -> LayoutIter&;

    LayoutIter (LayoutIter&& other) noexcept;
    auto
    operator= (LayoutIter&& other) noexcept -> LayoutIter&;

    ~LayoutIter () noexcept;

    void
    swap (LayoutIter& other) noexcept;

    auto
    gobj () -> PangoLayoutIter*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoLayoutIter*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> PangoLayoutIter*;

  protected:
    PangoLayoutIter* gobject_;

  private:
  public:
    auto
    get_index () const -> int;

    auto
    get_run () const -> GlyphItem;

    auto
    get_line () -> Glib::RefPtr<LayoutLine>;

    auto
    get_line () const -> Glib::RefPtr<const LayoutLine>;

    auto
    get_const_line () const -> Glib::RefPtr<const LayoutLine>;

    auto
    at_last_line () const -> bool;

    auto
    get_layout () -> Glib::RefPtr<Layout>;

    auto
    get_layout () const -> Glib::RefPtr<const Layout>;

    auto
    next_char () -> bool;

    auto
    next_cluster () -> bool;

    auto
    next_run () -> bool;

    auto
    next_line () -> bool;

    auto
    get_char_extents () const -> Rectangle;

    void
    get_cluster_extents (Rectangle& ink_rect, Rectangle& logical_rect) const;

    auto
    get_cluster_ink_extents () const -> Rectangle;

    auto
    get_cluster_logical_extents () const -> Rectangle;

    void
    get_run_extents (Rectangle& ink_rect, Rectangle& logical_rect) const;

    auto
    get_run_ink_extents () const -> Rectangle;

    auto
    get_run_logical_extents () const -> Rectangle;

    void
    get_line_extents (Rectangle& ink_rect, Rectangle& logical_rect) const;

    auto
    get_line_ink_extents () const -> Rectangle;

    auto
    get_line_logical_extents () const -> Rectangle;

    void
    get_line_yrange (int& y0, int& y1) const;

    void
    get_layout_extents (Rectangle& ink_rect, Rectangle& logical_rect) const;

    auto
    get_layout_ink_extents () const -> Rectangle;

    auto
    get_layout_logical_extents () const -> Rectangle;

    auto
    get_baseline () const -> int;
  };

} // namespace Pango

namespace Pango
{

  inline void
  swap (LayoutIter& lhs, LayoutIter& rhs) noexcept
  {
    lhs.swap (rhs);
  }

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoLayoutIter* object, bool take_copy = false) -> Pango::LayoutIter;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class PANGOMM_API Value<Pango::LayoutIter>
    : public Glib::Value_Boxed<Pango::LayoutIter>
  {
  };
#endif

} // namespace Glib

#endif
