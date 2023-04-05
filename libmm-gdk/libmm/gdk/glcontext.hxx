// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_GLCONTEXT_H
#define _GDKMM_GLCONTEXT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/display.hxx>
#include <libmm/gdk/drawcontext.hxx>
#include <libmm/gdk/mm-gdkconfig.hxx>
#include <libmm/gdk/surface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkGLContext = struct _GdkGLContext;
using GdkGLContextClass = struct _GdkGLContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT GLContext_Class;
}
#endif

namespace gdk
{

#ifdef GDKMM_BUILD

  #undef GLAPI
#endif

  enum class GLApi
  {
    GL = 1 << 0,
    GLES = 1 << 1
  };

  inline auto
  operator| (GLApi lhs, GLApi rhs) -> GLApi
  {
    return static_cast<GLApi> (static_cast<unsigned> (lhs) |
                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (GLApi lhs, GLApi rhs) -> GLApi
  {
    return static_cast<GLApi> (static_cast<unsigned> (lhs) &
                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (GLApi lhs, GLApi rhs) -> GLApi
  {
    return static_cast<GLApi> (static_cast<unsigned> (lhs) ^
                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(GLApi flags) -> GLApi
  {
    return static_cast<GLApi> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (GLApi& lhs, GLApi rhs) -> GLApi&
  {
    return (lhs = static_cast<GLApi> (static_cast<unsigned> (lhs) |
                                      static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (GLApi& lhs, GLApi rhs) -> GLApi&
  {
    return (lhs = static_cast<GLApi> (static_cast<unsigned> (lhs) &
                                      static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (GLApi& lhs, GLApi rhs) -> GLApi&
  {
    return (lhs = static_cast<GLApi> (static_cast<unsigned> (lhs) ^
                                      static_cast<unsigned> (rhs)));
  }

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::GLApi> : public glib::Value_Flags<gdk::GLApi>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

#ifndef GLAPI
  #ifndef GDKMM_DISABLE_DEPRECATED

  enum class GLAPI
  {
    GL = 1 << 0,
    GLES = 1 << 1
  };

  inline auto
  operator| (GLAPI lhs, GLAPI rhs) -> GLAPI
  {
    return static_cast<GLAPI> (static_cast<unsigned> (lhs) |
                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (GLAPI lhs, GLAPI rhs) -> GLAPI
  {
    return static_cast<GLAPI> (static_cast<unsigned> (lhs) &
                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (GLAPI lhs, GLAPI rhs) -> GLAPI
  {
    return static_cast<GLAPI> (static_cast<unsigned> (lhs) ^
                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(GLAPI flags) -> GLAPI
  {
    return static_cast<GLAPI> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (GLAPI& lhs, GLAPI rhs) -> GLAPI&
  {
    return (lhs = static_cast<GLAPI> (static_cast<unsigned> (lhs) |
                                      static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (GLAPI& lhs, GLAPI rhs) -> GLAPI&
  {
    return (lhs = static_cast<GLAPI> (static_cast<unsigned> (lhs) &
                                      static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (GLAPI& lhs, GLAPI rhs) -> GLAPI&
  {
    return (lhs = static_cast<GLAPI> (static_cast<unsigned> (lhs) ^
                                      static_cast<unsigned> (rhs)));
  }

  #endif
}

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

    #ifndef GDKMM_DISABLE_DEPRECATED
  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::GLAPI> : public glib::Value_Flags<gdk::GLAPI>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };
    #endif

} // namespace glib
  #endif

namespace gdk
{

#endif

  class GLError : public glib::Error
  {
  public:
    enum Code
    {
      NOT_AVAILABLE,
      UNSUPPORTED_FORMAT,
      UNSUPPORTED_PROFILE,
      COMPILATION_FAILED,
      LINK_FAILED
    };

    LIBMM_GDK_SYMEXPORT
    GLError (Code error_code, const glib::ustring& error_message);
    LIBMM_GDK_SYMEXPORT explicit GLError (GError* gobject);
    LIBMM_GDK_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GDK_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GDK_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::GLError::Code>
    : public glib::Value_Enum<gdk::GLError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT GLContext : public DrawContext
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GLContext;
    using CppClassType = GLContext_Class;
    using BaseObjectType = GdkGLContext;
    using BaseClassType = GdkGLContextClass;

    GLContext (const GLContext&) = delete;
    auto
    operator= (const GLContext&) -> GLContext& = delete;

  private:
    friend class GLContext_Class;
    static CppClassType glcontext_class_;

  protected:
    explicit GLContext (const glib::ConstructParams& construct_params);
    explicit GLContext (GdkGLContext* castitem);

#endif

  public:
    GLContext (GLContext&& src) noexcept;
    auto
    operator= (GLContext&& src) noexcept -> GLContext&;

    ~GLContext () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkGLContext*
    {
      return reinterpret_cast<GdkGLContext*> (gobject_);
    }

    auto
    gobj () const -> const GdkGLContext*
    {
      return reinterpret_cast<GdkGLContext*> (gobject_);
    }

    auto
    gobj_copy () -> GdkGLContext*;

  private:
  protected:
    GLContext ();

  public:
    auto
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    get_surface () -> glib::RefPtr<Surface>;

    auto
    get_surface () const -> glib::RefPtr<const Surface>;

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    get_shared_context () -> glib::RefPtr<GLContext>;
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    get_shared_context () const -> glib::RefPtr<const GLContext>;
#endif

    auto
    get_version (int& major, int& minor) const -> void;

    auto
    is_legacy () const -> bool;

    auto
    is_shared (const glib::RefPtr<const GLContext>& other) const -> bool;

    auto
    get_required_version (int& major, int& minor) const -> void;

    auto
    set_required_version (int major, int minor) -> void;

    auto
    get_debug_enabled () const -> bool;

    auto
    set_debug_enabled (bool enabled = true) -> void;

    auto
    get_forward_compatible () const -> bool;

    auto
    set_forward_compatible (bool compatible = true) -> void;
#ifndef GLAPI

  #ifndef GDKMM_DISABLE_DEPRECATED

    auto
    set_allowed_apis (GLAPI apis) -> void;
  #endif

  #ifndef GDKMM_DISABLE_DEPRECATED

    auto
    get_allowed_apis () const -> GLAPI;
  #endif

  #ifndef GDKMM_DISABLE_DEPRECATED

    auto
    get_api () const -> GLAPI;
  #endif

#endif

    auto
    set_allowed_apis (GLApi apis) -> void;

    auto
    get_allowed_apis2 () const -> GLApi;

    auto
    get_api2 () const -> GLApi;

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    set_use_es (bool use_es = true) -> void;
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    unset_use_es () -> void;
#endif

    auto
    get_use_es () const -> bool;

    auto
    realize () -> bool;

    auto
    make_current () -> void;

    static auto
    get_current () -> glib::RefPtr<GLContext>;

    static auto
    clear_current () -> void;

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    property_shared_context () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<GLContext>>;

#endif

#ifndef GLAPI

  #ifndef GDKMM_DISABLE_DEPRECATED

    auto
    property_allowed_apis () -> glib::PropertyProxy<GLAPI>;

    auto
    property_allowed_apis () const -> glib::PropertyProxy_ReadOnly<GLAPI>;

  #endif

  #ifndef GDKMM_DISABLE_DEPRECATED

    auto
    property_api () const -> glib::PropertyProxy_ReadOnly<GLAPI>;

  #endif

#endif

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkGLContext* object, bool take_copy = false) -> glib::RefPtr<gdk::GLContext>;
} // namespace glib

#endif
