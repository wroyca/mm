// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_SCRIPT_SURFACE_H
#define __CAIROMM_SCRIPT_SURFACE_H

#include <libmm/cairo/script.hxx>
#include <libmm/cairo/surface.hxx>

namespace cairo
{

#ifdef CAIRO_HAS_SCRIPT_SURFACE

  class LIBMM_CAIRO_SYMEXPORT ScriptSurface : public Surface
  {
  public:
    explicit ScriptSurface (cairo_surface_t* cobject,
                            bool has_reference = false);
    ~ScriptSurface () override;

    static auto
    create (const RefPtr<Script>& script,
            Content content,
            double width,
            double height) -> RefPtr<ScriptSurface>;

    static auto
    create_for_target (const RefPtr<Script>& script,
                       const RefPtr<Surface>& target) -> RefPtr<ScriptSurface>;
  };

#endif

} // namespace cairo

#endif
