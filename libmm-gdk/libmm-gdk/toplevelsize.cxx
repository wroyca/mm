

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/toplevelsize.hxx>
#include <libmm-gdk/toplevelsize_p.hxx>

#include <gdk/gdk.h>
#include <utility>

namespace Gdk
{

  ToplevelSize::operator bool () const
  {
    return gobj ();
  }

  ToplevelSize::ToplevelSize (GdkToplevelSize* gobject)
    : gobject_ (gobject)
  {
  }

  ToplevelSize::ToplevelSize (ToplevelSize&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
    other.gobject_ = nullptr;
  }

  auto
  ToplevelSize::operator= (ToplevelSize&& other) noexcept -> ToplevelSize&
  {
    ToplevelSize temp (std::move (other));
    std::swap (gobject_, temp.gobject_);
    return *this;
  }

  ToplevelSize::~ToplevelSize () noexcept {}

} // namespace Gdk

namespace
{
}

namespace Gdk
{

  auto
  ToplevelSize::get_bounds (int& bounds_width, int& bounds_height) const -> void
  {
    gdk_toplevel_size_get_bounds (const_cast<GdkToplevelSize*> (gobj ()),
                                  &bounds_width,
                                  &bounds_height);
  }

  auto
  ToplevelSize::set_size (const int width, const int height) -> void
  {
    gdk_toplevel_size_set_size (gobj (), width, height);
  }

  auto
  ToplevelSize::set_min_size (const int min_width, const int min_height) -> void
  {
    gdk_toplevel_size_set_min_size (gobj (), min_width, min_height);
  }

  auto
  ToplevelSize::set_shadow_width (const int left,
                                  const int right,
                                  const int top,
                                  const int bottom) -> void
  {
    gdk_toplevel_size_set_shadow_width (gobj (), left, right, top, bottom);
  }

} // namespace Gdk
