#ifndef _GDKMM_TOPLEVELSURFACEIMPL_H
#define _GDKMM_TOPLEVELSURFACEIMPL_H

#include <libmm-gdk/mm-gdkconfig.hxx>
#include <libmm-gdk/surface.hxx>
#include <libmm-gdk/toplevel.hxx>

namespace Gdk
{

  class GDKMM_API ToplevelSurfaceImpl : public Toplevel,
                                        public Surface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  protected:
    explicit ToplevelSurfaceImpl (GdkSurface* castitem);
    friend class Surface_Class;

    ToplevelSurfaceImpl (const ToplevelSurfaceImpl&) = delete;
    auto
    operator= (const ToplevelSurfaceImpl&) -> ToplevelSurfaceImpl& = delete;
#endif

  public:
    ToplevelSurfaceImpl (ToplevelSurfaceImpl&& src) noexcept;
    auto
    operator= (ToplevelSurfaceImpl&& src) noexcept -> ToplevelSurfaceImpl&;

    ~ToplevelSurfaceImpl () noexcept override;
  };

} // namespace Gdk

#endif
