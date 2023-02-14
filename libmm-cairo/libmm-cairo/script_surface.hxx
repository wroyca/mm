

#ifndef __CAIROMM_SCRIPT_SURFACE_H
#define __CAIROMM_SCRIPT_SURFACE_H

#include <libmm-cairo/script.hxx>
#include <libmm-cairo/surface.hxx>

namespace Cairo
{

#ifdef CAIRO_HAS_SCRIPT_SURFACE

  class CAIROMM_API ScriptSurface : public Surface
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

} // namespace Cairo

#endif
