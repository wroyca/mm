// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DRAWCONTEXT_H
#define _GDKMM_DRAWCONTEXT_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-cairo/region.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDrawContext = struct _GdkDrawContext;
using GdkDrawContextClass = struct _GdkDrawContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API DrawContext_Class;
}
#endif

namespace Gdk
{
  class GDKMM_API Display;
  class GDKMM_API Surface;

  class GDKMM_API DrawContext : public Glib::Object
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
    explicit DrawContext (const Glib::ConstructParams& construct_params);
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
    get_display () -> Glib::RefPtr<Display>;

    auto
    get_display () const -> Glib::RefPtr<const Display>;

    auto
    get_surface () -> Glib::RefPtr<Surface>;

    auto
    get_surface () const -> Glib::RefPtr<const Surface>;

    void
    begin_frame (const ::Cairo::RefPtr<const ::Cairo::Region>& region);

    void
    end_frame ();

    auto
    is_in_frame () const -> bool;

    auto
    get_frame_region () const -> ::Cairo::RefPtr<const ::Cairo::Region>;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>;

    auto
    property_surface () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkDrawContext* object, bool take_copy = false) -> Glib::RefPtr<Gdk::DrawContext>;
} // namespace Glib

#endif
