// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/glcontext.hxx>
#include <libmm/gdk/glcontext_p.hxx>

#include <gdk/gdk.h>
#include <libmm/gdk/cairoutils.hxx>

namespace gdk
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

} // namespace gdk

namespace
{
}

auto
glib::Value<gdk::GLApi>::value_type () -> GType
{
  return gdk_gl_api_get_type ();
}

#ifndef GDKMM_DISABLE_DEPRECATED

auto
glib::Value<gdk::GLAPI>::value_type () -> GType
{
  return gdk_gl_api_get_type ();
}
#endif

gdk::GLError::GLError (gdk::GLError::Code error_code,
                       const glib::ustring& error_message)
  : glib::Error (GDK_GL_ERROR, error_code, error_message)
{
}

gdk::GLError::GLError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gdk::GLError::code () const -> gdk::GLError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gdk::GLError::throw_func (GError* gobject) -> void
{
  throw gdk::GLError (gobject);
}

auto
glib::Value<gdk::GLError::Code>::value_type () -> GType
{
  return gdk_gl_error_get_type ();
}

namespace glib
{

  auto
  wrap (GdkGLContext* object, bool take_copy) -> glib::RefPtr<gdk::GLContext>
  {
    return glib::make_refptr_for_instance<gdk::GLContext> (
        dynamic_cast<gdk::GLContext*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  GLContext_Class::init () -> const glib::Class&
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
  GLContext_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new GLContext ((GdkGLContext*) object);
  }

  auto
  GLContext::gobj_copy () -> GdkGLContext*
  {
    reference ();
    return gobj ();
  }

  GLContext::GLContext (const glib::ConstructParams& construct_params)
    : gdk::DrawContext (construct_params)
  {
  }

  GLContext::GLContext (GdkGLContext* castitem)
    : gdk::DrawContext ((GdkDrawContext*) (castitem))
  {
  }

  GLContext::GLContext (GLContext&& src) noexcept
    : gdk::DrawContext (std::move (src))
  {
  }

  auto
  GLContext::operator= (GLContext&& src) noexcept -> GLContext&
  {
    gdk::DrawContext::operator= (std::move (src));
    return *this;
  }

  GLContext::~GLContext () noexcept {}

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
    : glib::ObjectBase (nullptr),
      gdk::DrawContext (glib::ConstructParams (glcontext_class_.init ()))
  {
  }

  auto
  GLContext::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_gl_context_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  GLContext::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<GLContext*> (this)->get_display ();
  }

  auto
  GLContext::get_surface () -> glib::RefPtr<Surface>
  {
    auto retvalue = glib::wrap (gdk_gl_context_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  GLContext::get_surface () const -> glib::RefPtr<const Surface>
  {
    return const_cast<GLContext*> (this)->get_surface ();
  }

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  GLContext::get_shared_context () -> glib::RefPtr<GLContext>
  {
    auto retvalue = glib::wrap (gdk_gl_context_get_shared_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  GLContext::get_shared_context () const -> glib::RefPtr<const GLContext>
  {
    return const_cast<GLContext*> (this)->get_shared_context ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  GLContext::get_version (int& major, int& minor) const -> void
  {
    gdk_gl_context_get_version (const_cast<GdkGLContext*> (gobj ()),
                                &(major),
                                &(minor));
  }

  auto
  GLContext::is_legacy () const -> bool
  {
    return gdk_gl_context_is_legacy (const_cast<GdkGLContext*> (gobj ()));
  }

  auto
  GLContext::is_shared (const glib::RefPtr<const GLContext>& other) const -> bool
  {
    return gdk_gl_context_is_shared (
        const_cast<GdkGLContext*> (gobj ()),
        const_cast<GdkGLContext*> (glib::unwrap<gdk::GLContext> (other)));
  }

  auto
  GLContext::get_required_version (int& major, int& minor) const -> void
  {
    gdk_gl_context_get_required_version (const_cast<GdkGLContext*> (gobj ()),
                                         &(major),
                                         &(minor));
  }

  auto
  GLContext::set_required_version (int major, int minor) -> void
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
  GLContext::set_debug_enabled (bool enabled) -> void
  {
    gdk_gl_context_set_debug_enabled (gobj (), static_cast<int> (enabled));
  }

  auto
  GLContext::get_forward_compatible () const -> bool
  {
    return gdk_gl_context_get_forward_compatible (
        const_cast<GdkGLContext*> (gobj ()));
  }

  auto
  GLContext::set_forward_compatible (bool compatible) -> void
  {
    gdk_gl_context_set_forward_compatible (gobj (),
                                           static_cast<int> (compatible));
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
  GLContext::set_use_es (bool use_es) -> void
  {
    gdk_gl_context_set_use_es (gobj (), static_cast<int> (use_es));
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
    auto retvalue = gdk_gl_context_realize (gobj (), &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  GLContext::make_current () -> void
  {
    gdk_gl_context_make_current (gobj ());
  }

  auto
  GLContext::get_current () -> glib::RefPtr<GLContext>
  {
    auto retvalue = glib::wrap (gdk_gl_context_get_current ());
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<GLContext>>::value,
      "Type glib::RefPtr<GLContext> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  GLContext::property_shared_context () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<GLContext>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<GLContext>> (
        this,
        "shared-context");
  }
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GLAPI>::value,
      "Type GLAPI cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  GLContext::property_allowed_apis () -> glib::PropertyProxy<GLAPI>
  {
    return glib::PropertyProxy<GLAPI> (this, "allowed-apis");
  }
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

  auto
  GLContext::property_allowed_apis () const -> glib::PropertyProxy_ReadOnly<GLAPI>
  {
    return glib::PropertyProxy_ReadOnly<GLAPI> (this, "allowed-apis");
  }
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GLAPI>::value,
      "Type GLAPI cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  GLContext::property_api () const -> glib::PropertyProxy_ReadOnly<GLAPI>
  {
    return glib::PropertyProxy_ReadOnly<GLAPI> (this, "api");
  }
#endif

} // namespace gdk
