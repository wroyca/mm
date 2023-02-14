
#ifndef _GDKMM_GLCONTEXT_H
#define _GDKMM_GLCONTEXT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/display.hxx>
#include <libmm-gdk/drawcontext.hxx>
#include <libmm-gdk/mm-gdkconfig.hxx>
#include <libmm-gdk/surface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkGLContext = struct _GdkGLContext;
using GdkGLContextClass = struct _GdkGLContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API GLContext_Class;
}
#endif

namespace Gdk
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

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::GLApi> : public Glib::Value_Flags<Gdk::GLApi>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
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
namespace Glib
{

    #ifndef GDKMM_DISABLE_DEPRECATED
  template <>
  class GDKMM_API Value<Gdk::GLAPI> : public Glib::Value_Flags<Gdk::GLAPI>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };
    #endif

} // namespace Glib
  #endif

namespace Gdk
{

#endif

  class GLError : public Glib::Error
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

    GDKMM_API
    GLError (Code error_code, const Glib::ustring& error_message);
    GDKMM_API explicit GLError (GError* gobject);
    GDKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GDKMM_API static void
    throw_func (GError* gobject);

    friend GDKMM_API void
    wrap_init ();

#endif
  };
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::GLError::Code>
    : public Glib::Value_Enum<Gdk::GLError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
{

  class GDKMM_API GLContext : public DrawContext
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
    explicit GLContext (const Glib::ConstructParams& construct_params);
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
    get_display () -> Glib::RefPtr<Display>;

    auto
    get_display () const -> Glib::RefPtr<const Display>;

    auto
    get_surface () -> Glib::RefPtr<Surface>;

    auto
    get_surface () const -> Glib::RefPtr<const Surface>;

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    get_shared_context () -> Glib::RefPtr<GLContext>;
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    get_shared_context () const -> Glib::RefPtr<const GLContext>;
#endif

    void
    get_version (int& major, int& minor) const;

    auto
    is_legacy () const -> bool;

    auto
    is_shared (const Glib::RefPtr<const GLContext>& other) const -> bool;

    void
    get_required_version (int& major, int& minor) const;

    void
    set_required_version (int major, int minor);

    auto
    get_debug_enabled () const -> bool;

    void
    set_debug_enabled (bool enabled = true);

    auto
    get_forward_compatible () const -> bool;

    void
    set_forward_compatible (bool compatible = true);
#ifndef GLAPI

  #ifndef GDKMM_DISABLE_DEPRECATED

    void
    set_allowed_apis (GLAPI apis);
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

    void
    set_allowed_apis (GLApi apis);

    auto
    get_allowed_apis2 () const -> GLApi;

    auto
    get_api2 () const -> GLApi;

#ifndef GDKMM_DISABLE_DEPRECATED

    void
    set_use_es (bool use_es = true);
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

    void
    unset_use_es ();
#endif

    auto
    get_use_es () const -> bool;

    auto
    realize () -> bool;

    void
    make_current ();

    static auto
    get_current () -> Glib::RefPtr<GLContext>;

    static void
    clear_current ();

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    property_shared_context () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<GLContext>>;

#endif

#ifndef GLAPI

  #ifndef GDKMM_DISABLE_DEPRECATED

    auto
    property_allowed_apis () -> Glib::PropertyProxy<GLAPI>;

    auto
    property_allowed_apis () const -> Glib::PropertyProxy_ReadOnly<GLAPI>;

  #endif

  #ifndef GDKMM_DISABLE_DEPRECATED

    auto
    property_api () const -> Glib::PropertyProxy_ReadOnly<GLAPI>;

  #endif

#endif

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkGLContext* object, bool take_copy = false) -> Glib::RefPtr<Gdk::GLContext>;
} // namespace Glib

#endif
