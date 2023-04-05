// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DRAGSURFACE_H
#define _GDKMM_DRAGSURFACE_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GdkDragSurfaceInterface GdkDragSurfaceInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDragSurface = struct _GdkDragSurface;
using GdkDragSurfaceClass = struct _GdkDragSurfaceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT DragSurface_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DragSurface : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DragSurface;
    using CppClassType = DragSurface_Class;
    using BaseObjectType = GdkDragSurface;
    using BaseClassType = GdkDragSurfaceInterface;

    DragSurface (const DragSurface&) = delete;
    auto
    operator= (const DragSurface&) -> DragSurface& = delete;

  private:
    friend class DragSurface_Class;
    static CppClassType dragsurface_class_;

#endif
  protected:
    DragSurface ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit DragSurface (const glib::Interface_Class& interface_class);

  public:
    explicit DragSurface (GdkDragSurface* castitem);

  protected:
#endif

  public:
    DragSurface (DragSurface&& src) noexcept;
    auto
    operator= (DragSurface&& src) noexcept -> DragSurface&;

    ~DragSurface () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkDragSurface*
    {
      return reinterpret_cast<GdkDragSurface*> (gobject_);
    }

    auto
    gobj () const -> const GdkDragSurface*
    {
      return reinterpret_cast<GdkDragSurface*> (gobject_);
    }

  private:
  public:
    auto
    present (int width, int height) -> bool;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDragSurface* object, bool take_copy = false) -> glib::RefPtr<gdk::DragSurface>;

} // namespace glib

#endif
