

#include <libmm-cairo/private.hxx>
#include <libmm-cairo/script_surface.hxx>

namespace Cairo
{

#ifdef CAIRO_HAS_SCRIPT_SURFACE

  ScriptSurface::ScriptSurface (cairo_surface_t* cobject,
                                const bool has_reference)
    : Surface (cobject, has_reference)
  {
  }

  ScriptSurface::~ScriptSurface () {}

  auto
  ScriptSurface::create (const RefPtr<Script>& script,
                         Content content,
                         const double width,
                         const double height) -> RefPtr<ScriptSurface>
  {
    const auto cobject = cairo_script_surface_create (
        script->cobj (),
        static_cast<cairo_content_t> (content),
        width,
        height);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<ScriptSurface> (
        new ScriptSurface (cobject, true));
  }

  auto
  ScriptSurface::create_for_target (const RefPtr<Script>& script,
                                    const RefPtr<Surface>& target) -> RefPtr<ScriptSurface>
  {
    const auto cobject = cairo_script_surface_create_for_target (
        script->cobj (),
        target->cobj ());
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<ScriptSurface> (
        new ScriptSurface (cobject, true));
  }

#endif

} // namespace Cairo
