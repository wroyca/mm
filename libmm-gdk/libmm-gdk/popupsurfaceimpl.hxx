#ifndef _GDKMM_POPUPSURFACEIMPL_H
#define _GDKMM_POPUPSURFACEIMPL_H

#include <libmm-gdk/mm-gdkconfig.hxx>
#include <libmm-gdk/popup.hxx>
#include <libmm-gdk/surface.hxx>

namespace Gdk
{

  class GDKMM_API PopupSurfaceImpl : public Popup,
                                     public Surface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  protected:
    explicit PopupSurfaceImpl (GdkSurface* castitem);
    friend class Surface_Class;

    PopupSurfaceImpl (const PopupSurfaceImpl&) = delete;
    auto
    operator= (const PopupSurfaceImpl&) -> PopupSurfaceImpl& = delete;
#endif

  public:
    PopupSurfaceImpl (PopupSurfaceImpl&& src) noexcept;
    auto
    operator= (PopupSurfaceImpl&& src) noexcept -> PopupSurfaceImpl&;

    ~PopupSurfaceImpl () noexcept override;
  };

} // namespace Gdk

#endif
