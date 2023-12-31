// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DRAGSURFACEIMPL_H
#define _GDKMM_DRAGSURFACEIMPL_H

#include <libmm/gdk/dragsurface.hxx>
#include <libmm/gdk/mm-gdkconfig.hxx>
#include <libmm/gdk/surface.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DragSurfaceImpl : public DragSurface,
                                    public Surface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  protected:
    explicit DragSurfaceImpl (GdkSurface* castitem);
    friend class Surface_Class;

    DragSurfaceImpl (const DragSurfaceImpl&) = delete;
    auto
    operator= (const DragSurfaceImpl&) -> DragSurfaceImpl& = delete;
#endif

  public:
    DragSurfaceImpl (DragSurfaceImpl&& src) noexcept;
    auto
    operator= (DragSurfaceImpl&& src) noexcept -> DragSurfaceImpl&;

    ~DragSurfaceImpl () noexcept override;
  };

} // namespace gdk

#endif
