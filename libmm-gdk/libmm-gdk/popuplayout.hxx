
#ifndef _GDKMM_POPUPLAYOUT_H
#define _GDKMM_POPUPLAYOUT_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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


#include <libmm-glib/refptr.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/rectangle.hxx>
#include <gdk/gdk.h> // For GdkPopupLayout.


namespace Gdk
{
/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 *  @var AnchorHints FLIP_X
 * Allow flipping anchors horizontally.
 *
 *  @var AnchorHints FLIP_Y
 * Allow flipping anchors vertically.
 *
 *  @var AnchorHints SLIDE_X
 * Allow sliding surface horizontally.
 *
 *  @var AnchorHints SLIDE_Y
 * Allow sliding surface vertically.
 *
 *  @var AnchorHints RESIZE_X
 * Allow resizing surface horizontally.
 *
 *  @var AnchorHints RESIZE_Y
 * Allow resizing surface vertically.
 *
 *  @var AnchorHints FLIP
 * Allow flipping anchors on both axes.
 *
 *  @var AnchorHints SLIDE
 * Allow sliding surface on both axes.
 *
 *  @var AnchorHints RESIZE
 * Allow resizing surface on both axes.
 *
 *  @enum AnchorHints
 *
 * Positioning hints for aligning a surface relative to a rectangle.
 *
 * These hints determine how the surface should be positioned in the case that
 * the surface would fall off-screen if placed in its ideal position.
 *
 * For example, Gdk::AnchorHints::FLIP_X will replace Gdk::Gravity::NORTH_WEST with
 * Gdk::Gravity::NORTH_EAST and vice versa if the surface extends beyond the left
 * or right edges of the monitor.
 *
 * If Gdk::AnchorHints::SLIDE_X is set, the surface can be shifted horizontally to fit
 * on-screen. If Gdk::AnchorHints::RESIZE_X is set, the surface can be shrunken
 * horizontally to fit.
 *
 * In general, when multiple flags are set, flipping should take precedence over
 * sliding, which should take precedence over resizing.
 *
 * @ingroup gdkmmEnums
 * @par Bitwise operators:
 * <tt>AnchorHints operator|(AnchorHints, AnchorHints)</tt><br>
 * <tt>AnchorHints operator&(AnchorHints, AnchorHints)</tt><br>
 * <tt>AnchorHints operator^(AnchorHints, AnchorHints)</tt><br>
 * <tt>AnchorHints operator~(AnchorHints)</tt><br>
 * <tt>AnchorHints& operator|=(AnchorHints&, AnchorHints)</tt><br>
 * <tt>AnchorHints& operator&=(AnchorHints&, AnchorHints)</tt><br>
 * <tt>AnchorHints& operator^=(AnchorHints&, AnchorHints)</tt><br>
 */
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

/** @ingroup gdkmmEnums */
inline auto operator|(AnchorHints lhs, AnchorHints rhs) -> AnchorHints
  { return static_cast<AnchorHints>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(AnchorHints lhs, AnchorHints rhs) -> AnchorHints
  { return static_cast<AnchorHints>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(AnchorHints lhs, AnchorHints rhs) -> AnchorHints
  { return static_cast<AnchorHints>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(AnchorHints flags) -> AnchorHints
  { return static_cast<AnchorHints>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(AnchorHints& lhs, AnchorHints rhs) -> AnchorHints&
  { return (lhs = static_cast<AnchorHints>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(AnchorHints& lhs, AnchorHints rhs) -> AnchorHints&
  { return (lhs = static_cast<AnchorHints>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(AnchorHints& lhs, AnchorHints rhs) -> AnchorHints&
  { return (lhs = static_cast<AnchorHints>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::AnchorHints> : public Glib::Value_Flags<Gdk::AnchorHints>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


/** Information for presenting popups.
 *
 * Popups are positioned relative to their parent surface.
 * The %Gdk::PopupLayout class contains information that is
 * necessary to do so.
 *
 * @newin{3,98}
 */
class GDKMM_API PopupLayout final
{
  // GdkPopupLayout is actually registered as a boxed type, but it has custom
  // reference-counting instead of copy/free functions, so we use it via RefPtr.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = PopupLayout;
  using BaseObjectType = GdkPopupLayout;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GdkPopupLayout*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GdkPopupLayout*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GdkPopupLayout*;

  PopupLayout() = delete;

  // noncopyable
  PopupLayout(const PopupLayout&) = delete;
  auto operator=(const PopupLayout&) -> PopupLayout& = delete;

protected:
  // Do not derive this.  Gdk::PopupLayout can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:


  /** Create a popup layout description.
   *
   * Used together with present() to describe how a popup
   * surface should be placed and behave on-screen.
   *
   *  @a anchor_rect is relative to the top-left corner of the surface's parent.
   *  @a rect_anchor and @a surface_anchor determine anchor points on @a anchor_rect
   * and surface to pin together.
   *
   * The position of @a anchor_rect's anchor point can optionally be offset using
   * set_offset(), which is equivalent to offsetting the
   * position of surface.
   *
   * @param anchor_rect The anchor `Gdk::Rectangle` to align @a surface with.
   * @param rect_anchor The point on @a anchor_rect to align with @a surface's anchor point.
   * @param surface_anchor The point on @a surface to align with @a rect's anchor point.
   * @return Newly created instance of `Gdk::PopupLayout`.
   */
  static auto create(const Rectangle& anchor_rect, Gravity rect_anchor, Gravity surface_anchor) -> Glib::RefPtr<PopupLayout>;

  /** Makes a copy of @a layout.
   *
   * @return A copy of @a layout.
   */
  auto copy() const -> Glib::RefPtr<PopupLayout>;

  /** Check whether @a layout and @a other has identical layout properties.
   *
   * @param other Another `Gdk::PopupLayout`.
   * @return <tt>true</tt> if @a layout and @a other have identical layout properties,
   * otherwise <tt>false</tt>.
   */
  auto equal(const Glib::RefPtr<const PopupLayout>& other) const -> bool;


  /** Set the anchor rectangle.
   *
   * @param anchor_rect The new anchor rectangle.
   */
  void set_anchor_rect(const Rectangle& anchor_rect);

  /** Get the anchor rectangle.
   *
   * @return The anchor rectangle.
   */
  auto get_anchor_rect() const -> Rectangle;

  /** Set the anchor on the anchor rectangle.
   *
   * @param anchor The new rect anchor.
   */
  void set_rect_anchor(Gravity anchor);

  /** Returns the anchor position on the anchor rectangle.
   *
   * @return The anchor on the anchor rectangle.
   */
  auto get_rect_anchor() const -> Gravity;

  /** Set the anchor on the popup surface.
   *
   * @param anchor The new popup surface anchor.
   */
  void set_surface_anchor(Gravity anchor);

  /** Returns the anchor position on the popup surface.
   *
   * @return The anchor on the popup surface.
   */
  auto get_surface_anchor() const -> Gravity;

  /** Set new anchor hints.
   *
   * The set @a anchor_hints determines how @a surface will be moved
   * if the anchor points cause it to move off-screen. For example,
   * Gdk::AnchorHints::FLIP_X will replace Gdk::Gravity::NORTH_WEST with
   * Gdk::Gravity::NORTH_EAST and vice versa if @a surface extends
   * beyond the left or right edges of the monitor.
   *
   * @param anchor_hints The new `Gdk::AnchorHints`.
   */
  void set_anchor_hints(AnchorHints anchor_hints);

  /** Get the `Gdk::AnchorHints`.
   *
   * @return The `Gdk::AnchorHints`.
   */
  auto get_anchor_hints() const -> AnchorHints;

  /** Offset the position of the anchor rectangle with the given delta.
   *
   * @param dx X delta to offset the anchor rectangle with.
   * @param dy Y delta to offset the anchor rectangle with.
   */
  void set_offset(int dx, int dy);

  /** Retrieves the offset for the anchor rectangle.
   *
   * @param dx Return location for the delta X coordinate.
   * @param dy Return location for the delta Y coordinate.
   */
  void get_offset(int& dx, int& dy);

  /** Sets the shadow width of the popup.
   *
   * The shadow width corresponds to the part of the computed
   * surface size that would consist of the shadow margin
   * surrounding the window, would there be any.
   *
   * @newin{4,2}
   *
   * @param left Width of the left part of the shadow.
   * @param right Width of the right part of the shadow.
   * @param top Height of the top part of the shadow.
   * @param bottom Height of the bottom part of the shadow.
   */
  void set_shadow_width(int left, int right, int top, int bottom);

  /** Sets the shadow width of the popup.
   *
   * The shadow width corresponds to the part of the computed
   * surface size that would consist of the shadow margin
   * surrounding the window, would there be any.
   *
   * @newin{4,2}
   * @param width Width of all parts of the shadow.
   */
  void set_shadow_width(int width);


  /** Obtains the shadow widths of this layout.
   *
   * @newin{4,2}
   *
   * @param left Return location for the left shadow width.
   * @param right Return location for the right shadow width.
   * @param top Return location for the top shadow width.
   * @param bottom Return location for the bottom shadow width.
   */
  void get_shadow_width(int& left, int& right, int& top, int& bottom) const;


};

} // namespace Gdk


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gdk::PopupLayout
 */
GDKMM_API
auto wrap(GdkPopupLayout* object, bool take_copy = false) -> Glib::RefPtr<Gdk::PopupLayout>;

} // namespace Glib


#endif /* _GDKMM_POPUPLAYOUT_H */

