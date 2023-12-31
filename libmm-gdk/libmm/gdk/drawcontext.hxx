// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DRAWCONTEXT_H
#define _GDKMM_DRAWCONTEXT_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/cairo/region.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDrawContext = struct _GdkDrawContext;
using GdkDrawContextClass = struct _GdkDrawContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT DrawContext_Class;
}
#endif

namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Display;
  class LIBMM_GDK_SYMEXPORT Surface;

  class LIBMM_GDK_SYMEXPORT DrawContext : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DrawContext;
    using CppClassType = DrawContext_Class;
    using BaseObjectType = GdkDrawContext;
    using BaseClassType = GdkDrawContextClass;

    DrawContext (const DrawContext&) = delete;
    auto
    operator= (const DrawContext&) -> DrawContext& = delete;

  private:
    friend class DrawContext_Class;
    static CppClassType drawcontext_class_;

  protected:
    explicit DrawContext (const glib::ConstructParams& construct_params);
    explicit DrawContext (GdkDrawContext* castitem);

#endif

  public:
    DrawContext (DrawContext&& src) noexcept;
    auto
    operator= (DrawContext&& src) noexcept -> DrawContext&;

    ~DrawContext () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkDrawContext*
    {
      return reinterpret_cast<GdkDrawContext*> (gobject_);
    }

    auto
    gobj () const -> const GdkDrawContext*
    {
      return reinterpret_cast<GdkDrawContext*> (gobject_);
    }

    auto
    gobj_copy () -> GdkDrawContext*;

  private:
  protected:
    DrawContext ();

  public:
    auto
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    get_surface () -> glib::RefPtr<Surface>;

    auto
    get_surface () const -> glib::RefPtr<const Surface>;

    auto
    begin_frame (const ::cairo::RefPtr<const ::cairo::Region>& region) -> void;

    auto
    end_frame () -> void;

    auto
    is_in_frame () const -> bool;

    auto
    get_frame_region () const -> ::cairo::RefPtr<const ::cairo::Region>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

    auto
    property_surface () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDrawContext* object, bool take_copy = false) -> glib::RefPtr<gdk::DrawContext>;
} // namespace glib

#endif
