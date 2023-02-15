// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-gdk/dragsurfaceimpl.hxx>
#include <utility>

namespace Gdk
{
  DragSurfaceImpl::DragSurfaceImpl (GdkSurface* castitem)
    : Glib::ObjectBase (nullptr),
      Surface (castitem)
  {
  }

  DragSurfaceImpl::DragSurfaceImpl (DragSurfaceImpl&& src) noexcept
    : DragSurface (std::move (src)),
      Surface (std::move (src))
  {
  }

  auto
  DragSurfaceImpl::operator= (DragSurfaceImpl&& src) noexcept -> DragSurfaceImpl&
  {
    DragSurface::operator= (std::move (src));
    Surface::operator= (std::move (src));
    return *this;
  }

  DragSurfaceImpl::~DragSurfaceImpl () noexcept {}

} // namespace Gdk
