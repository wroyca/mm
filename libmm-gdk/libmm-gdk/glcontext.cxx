

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/glcontext.hxx>
#include <libmm-gdk/glcontext_p.hxx>

#include <gdk/gdk.h>
#include <libmm-gdk/cairoutils.hxx>

namespace Gdk
{

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  GLContext::unset_use_es () -> void
  {
    gdk_gl_context_set_use_es (gobj (), -1);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

} // namespace Gdk

namespace
{
}

auto
Glib::Value<Gdk::GLApi>::value_type () -> GType
{
  return gdk_gl_api_get_type ();
}

#ifndef GDKMM_DISABLE_DEPRECATED

auto
Glib::Value<Gdk::GLAPI>::value_type () -> GType
{
  return gdk_gl_api_get_type ();
}
#endif

Gdk::GLError::GLError (const Code error_code,
                       const Glib::ustring& error_message)
  : Error (GDK_GL_ERROR, error_code, error_message)
{
}

Gdk::GLError::GLError (GError* gobject)
  : Error (gobject)
{
}

auto
Gdk::GLError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Gdk::GLError::throw_func (GError* gobject) -> void
{
  throw GLError (gobject);
}

auto
Glib::Value<Gdk::GLError::Code>::value_type () -> GType
{
  return gdk_gl_error_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkGLContext* object, const bool take_copy) -> RefPtr<Gdk::GLContext>
  {
    return Glib::make_refptr_for_instance<Gdk::GLContext> (
        dynamic_cast<Gdk::GLContext*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  GLContext_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GLContext_Class::class_init_function;

      register_derived_type (gdk_gl_context_get_type ());
    }

    return *this;
  }

  auto
  GLContext_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GLContext_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GLContext ((GdkGLContext*) object);
  }

  auto
  GLContext::gobj_copy () -> GdkGLContext*
  {
    reference ();
    return gobj ();
  }

  GLContext::GLContext (const Glib::ConstructParams& construct_params)
    : DrawContext (construct_params)
  {
  }

  GLContext::GLContext (GdkGLContext* castitem)
    : DrawContext ((GdkDrawContext*) castitem)
  {
  }

  GLContext::GLContext (GLContext&& src) noexcept
    : DrawContext (std::move (src))
  {
  }

  auto
  GLContext::operator= (GLContext&& src) noexcept -> GLContext&
  {
    DrawContext::operator= (std::move (src));
    return *this;
  }

  GLContext::~GLContext () noexcept = default;

  GLContext::CppClassType GLContext::glcontext_class_;

  auto
  GLContext::get_type () -> GType
  {
    return glcontext_class_.init ().get_type ();
  }

  auto
  GLContext::get_base_type () -> GType
  {
    return gdk_gl_context_get_type ();
  }

  GLContext::GLContext ()
    : ObjectBase (nullptr),
      DrawContext (Glib::ConstructParams (glcontext_class_.init ()))
  {
  }

  auto
  GLContext::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_gl_context_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  GLContext::get_display () const -> Glib::RefPtr<const Display>
  {
    return const_cast<GLContext*> (this)->get_display ();
  }

  auto
  GLContext::get_surface () -> Glib::RefPtr<Surface>
  {
    auto retvalue = Glib::wrap (gdk_gl_context_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  GLContext::get_surface () const -> Glib::RefPtr<const Surface>
  {
    return const_cast<GLContext*> (this)->get_surface ();
  }

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  GLContext::get_shared_context () -> Glib::RefPtr<GLContext>
  {
    auto retvalue = Glib::wrap (gdk_gl_context_get_shared_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  GLContext::get_shared_context () const -> Glib::RefPtr<const GLContext>
  {
    return const_cast<GLContext*> (this)->get_shared_context ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  GLContext::get_version (int& major, int& minor) const -> void
  {
    gdk_gl_context_get_version (const_cast<GdkGLContext*> (gobj ()),
                                &major,
                                &minor);
  }

  auto
  GLContext::is_legacy () const -> bool
  {
    return gdk_gl_context_is_legacy (const_cast<GdkGLContext*> (gobj ()));
  }

  auto
  GLContext::is_shared (const Glib::RefPtr<const GLContext>& other) const -> bool
  {
    return gdk_gl_context_is_shared (
        const_cast<GdkGLContext*> (gobj ()),
        const_cast<GdkGLContext*> (Glib::unwrap<GLContext> (other)));
  }

  auto
  GLContext::get_required_version (int& major, int& minor) const -> void
  {
    gdk_gl_context_get_required_version (const_cast<GdkGLContext*> (gobj ()),
                                         &major,
                                         &minor);
  }

  auto
  GLContext::set_required_version (const int major, const int minor) -> void
  {
    gdk_gl_context_set_required_version (gobj (), major, minor);
  }

  auto
  GLContext::get_debug_enabled () const -> bool
  {
    return gdk_gl_context_get_debug_enabled (
        const_cast<GdkGLContext*> (gobj ()));
  }

  auto
  GLContext::set_debug_enabled (const bool enabled) -> void
  {
    gdk_gl_context_set_debug_enabled (gobj (), enabled);
  }

  auto
  GLContext::get_forward_compatible () const -> bool
  {
    return gdk_gl_context_get_forward_compatible (
        const_cast<GdkGLContext*> (gobj ()));
  }

  auto
  GLContext::set_forward_compatible (const bool compatible) -> void
  {
    gdk_gl_context_set_forward_compatible (gobj (), compatible);
  }

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  GLContext::set_allowed_apis (GLAPI apis) -> void
  {
    gdk_gl_context_set_allowed_apis (gobj (), static_cast<GdkGLAPI> (apis));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  GLContext::get_allowed_apis () const -> GLAPI
  {
    return static_cast<GLAPI> (
        gdk_gl_context_get_allowed_apis (const_cast<GdkGLContext*> (gobj ())));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  GLContext::get_api () const -> GLAPI
  {
    return static_cast<GLAPI> (
        gdk_gl_context_get_api (const_cast<GdkGLContext*> (gobj ())));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  GLContext::set_allowed_apis (GLApi apis) -> void
  {
    gdk_gl_context_set_allowed_apis (gobj (), static_cast<GdkGLAPI> (apis));
  }

  auto
  GLContext::get_allowed_apis2 () const -> GLApi
  {
    return static_cast<GLApi> (
        gdk_gl_context_get_allowed_apis (const_cast<GdkGLContext*> (gobj ())));
  }

  auto
  GLContext::get_api2 () const -> GLApi
  {
    return static_cast<GLApi> (
        gdk_gl_context_get_api (const_cast<GdkGLContext*> (gobj ())));
  }

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  GLContext::set_use_es (const bool use_es) -> void
  {
    gdk_gl_context_set_use_es (gobj (), use_es);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  GLContext::get_use_es () const -> bool
  {
    return gdk_gl_context_get_use_es (const_cast<GdkGLContext*> (gobj ()));
  }

  auto
  GLContext::realize () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = gdk_gl_context_realize (gobj (), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  GLContext::make_current () -> void
  {
    gdk_gl_context_make_current (gobj ());
  }

  auto
  GLContext::get_current () -> Glib::RefPtr<GLContext>
  {
    auto retvalue = Glib::wrap (gdk_gl_context_get_current ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  GLContext::clear_current () -> void
  {
    gdk_gl_context_clear_current ();
  }

#ifndef GDKMM_DISABLE_DEPRECATED

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<GLContext>>::value,
      "Type Glib::RefPtr<GLContext> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  GLContext::property_shared_context () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<GLContext>>
  {
    return {this, "shared-context"};
  }
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GLAPI>::value,
      "Type GLAPI cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  GLContext::property_allowed_apis () -> Glib::PropertyProxy<GLAPI>
  {
    return {this, "allowed-apis"};
  }
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

  auto
  GLContext::property_allowed_apis () const -> Glib::PropertyProxy_ReadOnly<GLAPI>
  {
    return {this, "allowed-apis"};
  }
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GLAPI>::value,
      "Type GLAPI cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  GLContext::property_api () const -> Glib::PropertyProxy_ReadOnly<GLAPI>
  {
    return {this, "api"};
  }
#endif

} // namespace Gdk
