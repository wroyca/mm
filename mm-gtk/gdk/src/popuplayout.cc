// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gdkmm/popuplayout.h>
#include <gdkmm/private/popuplayout_p.h>

#include <gdk/gdk.h>

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

namespace Gdk
{

void PopupLayout::set_shadow_width(int width)
{
  gdk_popup_layout_set_shadow_width(gobj(), width, width, width, width);
}

} // namespace Gdk

namespace
{
} // anonymous namespace

// static
GType Glib::Value<Gdk::AnchorHints>::value_type()
{
  return gdk_anchor_hints_get_type();
}


/* Why reinterpret_cast<PopupLayout*>(gobject) is needed:
 *
 * A PopupLayout instance is in fact always a GdkPopupLayout instance.
 * Unfortunately, GdkPopupLayout cannot be a member of PopupLayout,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because PopupLayout does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

Glib::RefPtr<Gdk::PopupLayout> wrap(GdkPopupLayout* object, bool take_copy)
{
  if(take_copy && object)
    gdk_popup_layout_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gdk::PopupLayout>(reinterpret_cast<Gdk::PopupLayout*>(object));
}

} // namespace Glib


namespace Gdk
{

void PopupLayout::reference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_popup_layout_ref(reinterpret_cast<GdkPopupLayout*>(const_cast<PopupLayout*>(this)));
}

void PopupLayout::unreference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_popup_layout_unref(reinterpret_cast<GdkPopupLayout*>(const_cast<PopupLayout*>(this)));
}

GdkPopupLayout* PopupLayout::gobj()
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GdkPopupLayout*>(this);
}

const GdkPopupLayout* PopupLayout::gobj() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GdkPopupLayout*>(this);
}

GdkPopupLayout* PopupLayout::gobj_copy() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GdkPopupLayout*>(const_cast<PopupLayout*>(this));
  gdk_popup_layout_ref(gobject);
  return gobject;
}


Glib::RefPtr<PopupLayout> PopupLayout::create(const Rectangle& anchor_rect, Gravity rect_anchor, Gravity surface_anchor)
{
  return Glib::wrap(gdk_popup_layout_new((anchor_rect).gobj(), static_cast<GdkGravity>(rect_anchor), static_cast<GdkGravity>(surface_anchor)));
}

Glib::RefPtr<PopupLayout> PopupLayout::copy() const
{
  return Glib::wrap(gdk_popup_layout_copy(const_cast<GdkPopupLayout*>(gobj())));
}

bool PopupLayout::equal(const Glib::RefPtr<const PopupLayout>& other) const
{
  return gdk_popup_layout_equal(const_cast<GdkPopupLayout*>(gobj()), const_cast<GdkPopupLayout*>(Glib::unwrap(other)));
}

void PopupLayout::set_anchor_rect(const Rectangle& anchor_rect)
{
  gdk_popup_layout_set_anchor_rect(gobj(), (anchor_rect).gobj());
}

Rectangle PopupLayout::get_anchor_rect() const
{
  return Rectangle(gdk_popup_layout_get_anchor_rect(const_cast<GdkPopupLayout*>(gobj())));
}

void PopupLayout::set_rect_anchor(Gravity anchor)
{
  gdk_popup_layout_set_rect_anchor(gobj(), static_cast<GdkGravity>(anchor));
}

Gravity PopupLayout::get_rect_anchor() const
{
  return static_cast<Gravity>(gdk_popup_layout_get_rect_anchor(const_cast<GdkPopupLayout*>(gobj())));
}

void PopupLayout::set_surface_anchor(Gravity anchor)
{
  gdk_popup_layout_set_surface_anchor(gobj(), static_cast<GdkGravity>(anchor));
}

Gravity PopupLayout::get_surface_anchor() const
{
  return static_cast<Gravity>(gdk_popup_layout_get_surface_anchor(const_cast<GdkPopupLayout*>(gobj())));
}

void PopupLayout::set_anchor_hints(AnchorHints anchor_hints)
{
  gdk_popup_layout_set_anchor_hints(gobj(), static_cast<GdkAnchorHints>(anchor_hints));
}

AnchorHints PopupLayout::get_anchor_hints() const
{
  return static_cast<AnchorHints>(gdk_popup_layout_get_anchor_hints(const_cast<GdkPopupLayout*>(gobj())));
}

void PopupLayout::set_offset(int dx, int dy)
{
  gdk_popup_layout_set_offset(gobj(), dx, dy);
}

void PopupLayout::get_offset(int& dx, int& dy)
{
  gdk_popup_layout_get_offset(gobj(), &(dx), &(dy));
}

void PopupLayout::set_shadow_width(int left, int right, int top, int bottom)
{
  gdk_popup_layout_set_shadow_width(gobj(), left, right, top, bottom);
}

void PopupLayout::get_shadow_width(int& left, int& right, int& top, int& bottom) const
{
  gdk_popup_layout_get_shadow_width(const_cast<GdkPopupLayout*>(gobj()), &(left), &(right), &(top), &(bottom));
}


} // namespace Gdk


