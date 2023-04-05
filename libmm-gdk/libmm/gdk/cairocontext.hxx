// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CAIROCONTEXT_H
#define _GDKMM_CAIROCONTEXT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/cairo/context.hxx>
#include <libmm/gdk/drawcontext.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkCairoContext = struct _GdkCairoContext;
using GdkCairoContextClass = struct _GdkCairoContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT CairoContext_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT CairoContext : public gdk::DrawContext
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CairoContext;
    using CppClassType = CairoContext_Class;
    using BaseObjectType = GdkCairoContext;
    using BaseClassType = GdkCairoContextClass;

    CairoContext (const CairoContext&) = delete;
    auto
    operator= (const CairoContext&) -> CairoContext& = delete;

  private:
    friend class CairoContext_Class;
    static CppClassType cairocontext_class_;

  protected:
    explicit CairoContext (const glib::ConstructParams& construct_params);
    explicit CairoContext (GdkCairoContext* castitem);

#endif

  public:
    CairoContext (CairoContext&& src) noexcept;
    auto
    operator= (CairoContext&& src) noexcept -> CairoContext&;

    ~CairoContext () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkCairoContext*
    {
      return reinterpret_cast<GdkCairoContext*> (gobject_);
    }

    auto
    gobj () const -> const GdkCairoContext*
    {
      return reinterpret_cast<GdkCairoContext*> (gobject_);
    }

    auto
    gobj_copy () -> GdkCairoContext*;

  private:
  protected:
    CairoContext ();

  public:
    auto
    cairo_create () -> ::cairo::RefPtr<::cairo::Context>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkCairoContext* object, bool take_copy = false) -> glib::RefPtr<gdk::CairoContext>;
} // namespace glib

#endif
