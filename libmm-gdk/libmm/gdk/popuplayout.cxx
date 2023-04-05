// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/popuplayout.hxx>
#include <libmm/gdk/popuplayout_p.hxx>

#include <gdk/gdk.h>

namespace gdk
{

  auto
  PopupLayout::set_shadow_width (int width) -> void
  {
    gdk_popup_layout_set_shadow_width (gobj (), width, width, width, width);
  }

} // namespace gdk

namespace
{
}

auto
glib::Value<gdk::AnchorHints>::value_type () -> GType
{
  return gdk_anchor_hints_get_type ();
}

namespace glib
{

  auto
  wrap (GdkPopupLayout* object, bool take_copy) -> glib::RefPtr<gdk::PopupLayout>
  {
    if (take_copy && object)
      gdk_popup_layout_ref (object);

    return glib::make_refptr_for_instance<gdk::PopupLayout> (
        reinterpret_cast<gdk::PopupLayout*> (object));
  }

} // namespace glib

namespace gdk
{

  auto
  PopupLayout::reference () const -> void
  {
    gdk_popup_layout_ref (
        reinterpret_cast<GdkPopupLayout*> (const_cast<PopupLayout*> (this)));
  }

  auto
  PopupLayout::unreference () const -> void
  {
    gdk_popup_layout_unref (
        reinterpret_cast<GdkPopupLayout*> (const_cast<PopupLayout*> (this)));
  }

  auto
  PopupLayout::gobj () -> GdkPopupLayout*
  {
    return reinterpret_cast<GdkPopupLayout*> (this);
  }

  auto
  PopupLayout::gobj () const -> const GdkPopupLayout*
  {
    return reinterpret_cast<const GdkPopupLayout*> (this);
  }

  auto
  PopupLayout::gobj_copy () const -> GdkPopupLayout*
  {
    const auto gobject =
        reinterpret_cast<GdkPopupLayout*> (const_cast<PopupLayout*> (this));
    gdk_popup_layout_ref (gobject);
    return gobject;
  }

  auto
  PopupLayout::create (const Rectangle& anchor_rect,
                       Gravity rect_anchor,
                       Gravity surface_anchor) -> glib::RefPtr<PopupLayout>
  {
    return glib::wrap (
        gdk_popup_layout_new ((anchor_rect).gobj (),
                              static_cast<GdkGravity> (rect_anchor),
                              static_cast<GdkGravity> (surface_anchor)));
  }

  auto
  PopupLayout::copy () const -> glib::RefPtr<PopupLayout>
  {
    return glib::wrap (
        gdk_popup_layout_copy (const_cast<GdkPopupLayout*> (gobj ())));
  }

  auto
  PopupLayout::equal (const glib::RefPtr<const PopupLayout>& other) const -> bool
  {
    return gdk_popup_layout_equal (
        const_cast<GdkPopupLayout*> (gobj ()),
        const_cast<GdkPopupLayout*> (glib::unwrap (other)));
  }

  auto
  PopupLayout::set_anchor_rect (const Rectangle& anchor_rect) -> void
  {
    gdk_popup_layout_set_anchor_rect (gobj (), (anchor_rect).gobj ());
  }

  auto
  PopupLayout::get_anchor_rect () const -> Rectangle
  {
    return Rectangle (gdk_popup_layout_get_anchor_rect (
        const_cast<GdkPopupLayout*> (gobj ())));
  }

  auto
  PopupLayout::set_rect_anchor (Gravity anchor) -> void
  {
    gdk_popup_layout_set_rect_anchor (gobj (),
                                      static_cast<GdkGravity> (anchor));
  }

  auto
  PopupLayout::get_rect_anchor () const -> Gravity
  {
    return static_cast<Gravity> (gdk_popup_layout_get_rect_anchor (
        const_cast<GdkPopupLayout*> (gobj ())));
  }

  auto
  PopupLayout::set_surface_anchor (Gravity anchor) -> void
  {
    gdk_popup_layout_set_surface_anchor (gobj (),
                                         static_cast<GdkGravity> (anchor));
  }

  auto
  PopupLayout::get_surface_anchor () const -> Gravity
  {
    return static_cast<Gravity> (gdk_popup_layout_get_surface_anchor (
        const_cast<GdkPopupLayout*> (gobj ())));
  }

  auto
  PopupLayout::set_anchor_hints (AnchorHints anchor_hints) -> void
  {
    gdk_popup_layout_set_anchor_hints (
        gobj (),
        static_cast<GdkAnchorHints> (anchor_hints));
  }

  auto
  PopupLayout::get_anchor_hints () const -> AnchorHints
  {
    return static_cast<AnchorHints> (gdk_popup_layout_get_anchor_hints (
        const_cast<GdkPopupLayout*> (gobj ())));
  }

  auto
  PopupLayout::set_offset (int dx, int dy) -> void
  {
    gdk_popup_layout_set_offset (gobj (), dx, dy);
  }

  auto
  PopupLayout::get_offset (int& dx, int& dy) -> void
  {
    gdk_popup_layout_get_offset (gobj (), &(dx), &(dy));
  }

  auto
  PopupLayout::set_shadow_width (int left, int right, int top, int bottom) -> void
  {
    gdk_popup_layout_set_shadow_width (gobj (), left, right, top, bottom);
  }

  auto
  PopupLayout::get_shadow_width (int& left,
                                 int& right,
                                 int& top,
                                 int& bottom) const -> void
  {
    gdk_popup_layout_get_shadow_width (const_cast<GdkPopupLayout*> (gobj ()),
                                       &(left),
                                       &(right),
                                       &(top),
                                       &(bottom));
  }

} // namespace gdk
