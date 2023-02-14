// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-gdk/toplevelsurfaceimpl.hxx>
#include <utility>

namespace Gdk
{
  ToplevelSurfaceImpl::ToplevelSurfaceImpl (GdkSurface* castitem)
    : ObjectBase (nullptr),
      Surface (castitem)
  {
  }

  ToplevelSurfaceImpl::ToplevelSurfaceImpl (ToplevelSurfaceImpl&& src) noexcept
    : Toplevel (std::move (src)),
      Surface (std::move (src))
  {
  }

  auto
  ToplevelSurfaceImpl::operator= (ToplevelSurfaceImpl&& src) noexcept -> ToplevelSurfaceImpl&
  {
    Toplevel::operator= (std::move (src));
    Surface::operator= (std::move (src));
    return *this;
  }

  ToplevelSurfaceImpl::~ToplevelSurfaceImpl () noexcept = default;
} // namespace Gdk
