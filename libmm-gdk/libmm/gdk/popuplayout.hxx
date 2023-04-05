// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_POPUPLAYOUT_H
#define _GDKMM_POPUPLAYOUT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/rectangle.hxx>
#include <libmm/glib/refptr.hxx>

namespace gdk
{

  enum class AnchorHints
  {
    FLIP_X = 1 << 0,
    FLIP_Y = 1 << 1,
    SLIDE_X = 1 << 2,
    SLIDE_Y = 1 << 3,
    RESIZE_X = 1 << 4,
    RESIZE_Y = 1 << 5,
    FLIP = 0x3,
    SLIDE = 0xC,
    RESIZE = 0x30
  };

  inline auto
  operator| (AnchorHints lhs, AnchorHints rhs) -> AnchorHints
  {
    return static_cast<AnchorHints> (static_cast<unsigned> (lhs) |
                                     static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (AnchorHints lhs, AnchorHints rhs) -> AnchorHints
  {
    return static_cast<AnchorHints> (static_cast<unsigned> (lhs) &
                                     static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (AnchorHints lhs, AnchorHints rhs) -> AnchorHints
  {
    return static_cast<AnchorHints> (static_cast<unsigned> (lhs) ^
                                     static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(AnchorHints flags) -> AnchorHints
  {
    return static_cast<AnchorHints> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (AnchorHints& lhs, AnchorHints rhs) -> AnchorHints&
  {
    return (lhs = static_cast<AnchorHints> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (AnchorHints& lhs, AnchorHints rhs) -> AnchorHints&
  {
    return (lhs = static_cast<AnchorHints> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (AnchorHints& lhs, AnchorHints rhs) -> AnchorHints&
  {
    return (lhs = static_cast<AnchorHints> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs)));
  }

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::AnchorHints>
    : public glib::Value_Flags<gdk::AnchorHints>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT PopupLayout final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PopupLayout;
    using BaseObjectType = GdkPopupLayout;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GdkPopupLayout*;

    auto
    gobj () const -> const GdkPopupLayout*;

    auto
    gobj_copy () const -> GdkPopupLayout*;

    PopupLayout () = delete;

    PopupLayout (const PopupLayout&) = delete;
    auto
    operator= (const PopupLayout&) -> PopupLayout& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create (const Rectangle& anchor_rect,
            Gravity rect_anchor,
            Gravity surface_anchor) -> glib::RefPtr<PopupLayout>;

    auto
    copy () const -> glib::RefPtr<PopupLayout>;

    auto
    equal (const glib::RefPtr<const PopupLayout>& other) const -> bool;

    auto
    set_anchor_rect (const Rectangle& anchor_rect) -> void;

    auto
    get_anchor_rect () const -> Rectangle;

    auto
    set_rect_anchor (Gravity anchor) -> void;

    auto
    get_rect_anchor () const -> Gravity;

    auto
    set_surface_anchor (Gravity anchor) -> void;

    auto
    get_surface_anchor () const -> Gravity;

    auto
    set_anchor_hints (AnchorHints anchor_hints) -> void;

    auto
    get_anchor_hints () const -> AnchorHints;

    auto
    set_offset (int dx, int dy) -> void;

    auto
    get_offset (int& dx, int& dy) -> void;

    auto
    set_shadow_width (int left, int right, int top, int bottom) -> void;

    auto
    set_shadow_width (int width) -> void;

    auto
    get_shadow_width (int& left, int& right, int& top, int& bottom) const
        -> void;
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkPopupLayout* object, bool take_copy = false) -> glib::RefPtr<gdk::PopupLayout>;

} // namespace glib

#endif
