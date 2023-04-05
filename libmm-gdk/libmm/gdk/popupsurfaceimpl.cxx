// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gdk/popupsurfaceimpl.hxx>
#include <utility>

namespace gdk
{
  PopupSurfaceImpl::PopupSurfaceImpl (GdkSurface* castitem)
    : glib::ObjectBase (nullptr),
      Surface (castitem)
  {
  }

  PopupSurfaceImpl::PopupSurfaceImpl (PopupSurfaceImpl&& src) noexcept
    : Popup (std::move (src)),
      Surface (std::move (src))
  {
  }

  auto
  PopupSurfaceImpl::operator= (PopupSurfaceImpl&& src) noexcept -> PopupSurfaceImpl&
  {
    Popup::operator= (std::move (src));
    Surface::operator= (std::move (src));
    return *this;
  }

  PopupSurfaceImpl::~PopupSurfaceImpl () noexcept {}

} // namespace gdk
