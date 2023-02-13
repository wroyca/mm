
#ifndef _GDKMM_GLCONTEXT_H
#define _GDKMM_GLCONTEXT_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2015 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-gdk/mm-gdkconfig.hpp>
#include <libmm-gdk/drawcontext.hpp>
#include <libmm-gdk/display.hpp>
#include <libmm-gdk/surface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkGLContext = struct _GdkGLContext;
using GdkGLContextClass = struct _GdkGLContextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API GLContext_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
//TODO: When we can break API/ABI, remove all API with GLAPI
// and rename get_allowed_apis2() and get_api2().
#ifdef GDKMM_BUILD
// Make sure GLAPI is not defined when gdkmm is built.
#undef GLAPI
#endif

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 *  @var GLApi GL
 * The OpenGL API.
 *
 *  @var GLApi GLES
 * The OpenGL ES API.
 *
 *  @enum GLApi
 *
 * The list of the different APIs that GdkGLContext can potentially support.
 *
 * @newin{4,8}
 *
 * @ingroup gdkmmEnums
 * @par Bitwise operators:
 * <tt>GLApi operator|(GLApi, GLApi)</tt><br>
 * <tt>GLApi operator&(GLApi, GLApi)</tt><br>
 * <tt>GLApi operator^(GLApi, GLApi)</tt><br>
 * <tt>GLApi operator~(GLApi)</tt><br>
 * <tt>GLApi& operator|=(GLApi&, GLApi)</tt><br>
 * <tt>GLApi& operator&=(GLApi&, GLApi)</tt><br>
 * <tt>GLApi& operator^=(GLApi&, GLApi)</tt><br>
 */
enum class GLApi
{
  GL = 1 << 0,
  GLES = 1 << 1
};

/** @ingroup gdkmmEnums */
inline auto operator|(GLApi lhs, GLApi rhs) -> GLApi
  { return static_cast<GLApi>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(GLApi lhs, GLApi rhs) -> GLApi
  { return static_cast<GLApi>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(GLApi lhs, GLApi rhs) -> GLApi
  { return static_cast<GLApi>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(GLApi flags) -> GLApi
  { return static_cast<GLApi>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(GLApi& lhs, GLApi rhs) -> GLApi&
  { return (lhs = static_cast<GLApi>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(GLApi& lhs, GLApi rhs) -> GLApi&
  { return (lhs = static_cast<GLApi>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(GLApi& lhs, GLApi rhs) -> GLApi&
  { return (lhs = static_cast<GLApi>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::GLApi> : public Glib::Value_Flags<Gdk::GLApi>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

#ifndef GLAPI
#ifndef GDKMM_DISABLE_DEPRECATED
/**  @enum GLAPI
 * @note Name clash! GLAPI is defined as a preprocessor macro in epoxy/gl.h.
 * If you include epoxy/gl.h and want to use API with %Gdk::GLAPI, you must undef GLAPI.
 * @code
 * #include <libmm-gdk/glcontext.hpp> // or <gtkmm.h>
 * #include <epoxy/gl.h>
 * #undef GLAPI
 * @endcode
 * or
 * @code
 * #include <epoxy/gl.h>
 * #undef GLAPI
 * #include <libmm-gdk/glcontext.hpp> // or <gtkmm.h>
 * @endcode
 *
 *  @var GLAPI GL
 * The OpenGL API.
 *
 *  @var GLAPI GLES
 * The OpenGL ES API.
 *
 *  @enum GLAPI
 *
 * The list of the different APIs that GdkGLContext can potentially support.
 *
 * @newin{4,6}
 * @deprecated Use Gdk::GLApi instead.
 *
 *
 * @ingroup gdkmmEnums
 * @par Bitwise operators:
 * <tt>GLAPI operator|(GLAPI, GLAPI)</tt><br>
 * <tt>GLAPI operator&(GLAPI, GLAPI)</tt><br>
 * <tt>GLAPI operator^(GLAPI, GLAPI)</tt><br>
 * <tt>GLAPI operator~(GLAPI)</tt><br>
 * <tt>GLAPI& operator|=(GLAPI&, GLAPI)</tt><br>
 * <tt>GLAPI& operator&=(GLAPI&, GLAPI)</tt><br>
 * <tt>GLAPI& operator^=(GLAPI&, GLAPI)</tt><br>
 */
enum class GLAPI
{
  GL = 1 << 0,
  GLES = 1 << 1
};

/** @ingroup gdkmmEnums */
inline auto operator|(GLAPI lhs, GLAPI rhs) -> GLAPI
  { return static_cast<GLAPI>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(GLAPI lhs, GLAPI rhs) -> GLAPI
  { return static_cast<GLAPI>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(GLAPI lhs, GLAPI rhs) -> GLAPI
  { return static_cast<GLAPI>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(GLAPI flags) -> GLAPI
  { return static_cast<GLAPI>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(GLAPI& lhs, GLAPI rhs) -> GLAPI&
  { return (lhs = static_cast<GLAPI>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(GLAPI& lhs, GLAPI rhs) -> GLAPI&
  { return (lhs = static_cast<GLAPI>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(GLAPI& lhs, GLAPI rhs) -> GLAPI&
  { return (lhs = static_cast<GLAPI>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

#endif // GDKMM_DISABLE_DEPRECATED

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

#ifndef GDKMM_DISABLE_DEPRECATED
template <>
class GDKMM_API Value<Gdk::GLAPI> : public Glib::Value_Flags<Gdk::GLAPI>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};
#endif // GDKMM_DISABLE_DEPRECATED

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

#endif // GLAPI
/**  @newin{3,18}
 */
class GLError : public Glib::Error
{
public:
  /**  @var Code NOT_AVAILABLE
   * OpenGL support is not available.
   *
   *  @var Code UNSUPPORTED_FORMAT
   * The requested visual format is not supported.
   *
   *  @var Code UNSUPPORTED_PROFILE
   * The requested profile is not supported.
   *
   *  @var Code COMPILATION_FAILED
   * The shader compilation failed.
   *
   *  @var Code LINK_FAILED
   * The shader linking failed.
   *
   *  @enum Code
   *
   * Error enumeration for `Gdk::GLContext`.
   *
   * @newin{3,18}
   */
  enum Code
  {
    NOT_AVAILABLE,
    UNSUPPORTED_FORMAT,
    UNSUPPORTED_PROFILE,
    COMPILATION_FAILED,
    LINK_FAILED
  };

  GDKMM_API GLError(Code error_code, const Glib::ustring& error_message);
  GDKMM_API explicit GLError(GError* gobject);
  GDKMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GDKMM_API static void throw_func(GError* gobject);

  friend GDKMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::GLError::Code> : public Glib::Value_Enum<Gdk::GLError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


/** A %Gdk::GLContext is an OpenGL context abstraction.
 *
 * It's a low-level object, used to implement high-level objects such
 * as Gtk::GLArea on the GTK level.
 *
 * @note Name clash! GLAPI is defined as a preprocessor macro in epoxy/gl.h.
 * Use GLApi instead of GLAPI.
 * If you include epoxy/gl.h and want to use API with Gdk::GLAPI, you must undef GLAPI.
 * @code
 * #include <libmm-gdk/glcontext.hpp> // or <gtkmm.h>
 * #include <epoxy/gl.h>
 * #undef GLAPI
 * @endcode
 * or
 * @code
 * #include <epoxy/gl.h>
 * #undef GLAPI
 * #include <libmm-gdk/glcontext.hpp> // or <gtkmm.h>
 * @endcode
 *
 * @newin{3,18}
 */

class GDKMM_API GLContext : public DrawContext
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = GLContext;
  using CppClassType = GLContext_Class;
  using BaseObjectType = GdkGLContext;
  using BaseClassType = GdkGLContextClass;

  // noncopyable
  GLContext(const GLContext&) = delete;
  auto operator=(const GLContext&) -> GLContext& = delete;

private:  friend class GLContext_Class;
  static CppClassType glcontext_class_;

protected:
  explicit GLContext(const Glib::ConstructParams& construct_params);
  explicit GLContext(GdkGLContext* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  GLContext(GLContext&& src) noexcept;
  auto operator=(GLContext&& src) noexcept -> GLContext&;

  ~GLContext() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkGLContext*       { return reinterpret_cast<GdkGLContext*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkGLContext* { return reinterpret_cast<GdkGLContext*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkGLContext*;

private:


protected:
  GLContext();

public:

  /** Retrieves the display the @a context is created for
   *
   * @newin{3,18}
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Retrieves the display the @a context is created for
   *
   * @newin{3,18}
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;

  /** Retrieves the surface used by the @a context.
   *
   * @newin{3,18}
   *
   * @return A `Gdk::Surface`.
   */
  auto get_surface() -> Glib::RefPtr<Surface>;

  /** Retrieves the surface used by the @a context.
   *
   * @newin{3,18}
   *
   * @return A `Gdk::Surface`.
   */
  auto get_surface() const -> Glib::RefPtr<const Surface>;

#ifndef GDKMM_DISABLE_DEPRECATED

  /** Used to retrieves the `Gdk::GLContext` that this @a context share data with.
   *
   * As many contexts can share data now and no single shared context exists
   * anymore, this function has been deprecated and now always returns <tt>nullptr</tt>.
   *
   * Deprecated: 4.4: Use is_shared() to check if contexts
   * can be shared.
   *
   * @newin{3,18}
   *
   * @deprecated Always returns an empty RefPtr. Use is_shared() to check if contexts can be shared.
   *
   * @return <tt>nullptr</tt>.
   */
  auto get_shared_context() -> Glib::RefPtr<GLContext>;
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Used to retrieves the `Gdk::GLContext` that this @a context share data with.
   *
   * As many contexts can share data now and no single shared context exists
   * anymore, this function has been deprecated and now always returns <tt>nullptr</tt>.
   *
   * Deprecated: 4.4: Use is_shared() to check if contexts
   * can be shared.
   *
   * @newin{3,18}
   *
   * @deprecated Always returns an empty RefPtr. Use is_shared() to check if contexts can be shared.
   *
   * @return <tt>nullptr</tt>.
   */
  auto get_shared_context() const -> Glib::RefPtr<const GLContext>;
#endif // GDKMM_DISABLE_DEPRECATED


  /** Retrieves the OpenGL version of the @a context.
   *
   * The @a context must be realized prior to calling this function.
   *
   * If the @a context has never been made current, the version cannot
   * be known and it will return 0 for both @a major and @a minor.
   *
   * @newin{3,18}
   *
   * @param major Return location for the major version.
   * @param minor Return location for the minor version.
   */
  void get_version(int& major, int& minor) const;

  /** Whether the `Gdk::GLContext` is in legacy mode or not.
   *
   * The `Gdk::GLContext` must be realized before calling this function.
   *
   * When realizing a GL context, GDK will try to use the OpenGL 3.2 core
   * profile; this profile removes all the OpenGL API that was deprecated
   * prior to the 3.2 version of the specification. If the realization is
   * successful, this function will return <tt>false</tt>.
   *
   * If the underlying OpenGL implementation does not support core profiles,
   * GDK will fall back to a pre-3.2 compatibility profile, and this function
   * will return <tt>true</tt>.
   *
   * You can use the value returned by this function to decide which kind
   * of OpenGL API to use, or whether to do extension discovery, or what
   * kind of shader programs to load.
   *
   * @return <tt>true</tt> if the GL context is in legacy mode.
   */
  auto is_legacy() const -> bool;

  /** Checks if the two GL contexts can share resources.
   *
   * When they can, the texture IDs from @a other can be used in @a self. This
   * is particularly useful when passing `Gdk::GLTexture` objects between
   * different contexts.
   *
   * Contexts created for the same display with the same properties will
   * always be compatible, even if they are created for different surfaces.
   * For other contexts it depends on the GL backend.
   *
   * Both contexts must be realized for this check to succeed. If either one
   * is not, this function will return <tt>false</tt>.
   *
   * @newin{4,4}
   *
   * @param other The `Gdk::GLContext` that should be compatible with @a self.
   * @return <tt>true</tt> if the two GL contexts are compatible.
   */
  auto is_shared(const Glib::RefPtr<const GLContext>& other) const -> bool;

  /** Retrieves required OpenGL version set as a requirement for the @a context
   * realization. It will not change even if a greater OpenGL version is supported
   * and used after the @a context is realized. See
   * get_version() for the real version in use.
   *
   * See set_required_version().
   *
   * @newin{3,18}
   *
   * @param major Return location for the major version to request.
   * @param minor Return location for the minor version to request.
   */
  void get_required_version(int& major, int& minor) const;

  /** Sets the major and minor version of OpenGL to request.
   *
   * Setting @a major and @a minor to zero will use the default values.
   *
   * Setting @a major and @a minor lower than the minimum versions required
   * by GTK will result in the context choosing the minimum version.
   *
   * The @a context must not be realized or made current prior to calling
   * this function.
   *
   * @newin{3,18}
   *
   * @param major The major version to request.
   * @param minor The minor version to request.
   */
  void set_required_version(int major, int minor);

  /** Retrieves whether the context is doing extra validations and runtime checking.
   *
   * See set_debug_enabled().
   *
   * @newin{3,18}
   *
   * @return <tt>true</tt> if debugging is enabled.
   */
  auto get_debug_enabled() const -> bool;

  /** Sets whether the `Gdk::GLContext` should perform extra validations and
   * runtime checking.
   *
   * This is useful during development, but has additional overhead.
   *
   * The `Gdk::GLContext` must not be realized or made current prior to
   * calling this function.
   *
   * @newin{3,18}
   *
   * @param enabled Whether to enable debugging in the context.
   */
  void set_debug_enabled(bool enabled =  true);

  /** Retrieves whether the context is forward-compatible.
   *
   * See set_forward_compatible().
   *
   * @newin{3,18}
   *
   * @return <tt>true</tt> if the context should be forward-compatible.
   */
  auto get_forward_compatible() const -> bool;

  /** Sets whether the `Gdk::GLContext` should be forward-compatible.
   *
   * Forward-compatible contexts must not support OpenGL functionality that
   * has been marked as deprecated in the requested version; non-forward
   * compatible contexts, on the other hand, must support both deprecated and
   * non deprecated functionality.
   *
   * The `Gdk::GLContext` must not be realized or made current prior to calling
   * this function.
   *
   * @newin{3,18}
   *
   * @param compatible Whether the context should be forward-compatible.
   */
  void set_forward_compatible(bool compatible =  true);
#ifndef GLAPI

#ifndef GDKMM_DISABLE_DEPRECATED

  /** Sets the allowed APIs. When realize() is called, only the
   * allowed APIs will be tried. If you set this to 0, realizing will always fail.
   *
   * If you set it on a realized context, the property will not have any effect.
   * It is only relevant during realize().
   *
   * By default, all APIs are allowed.
   *
   * @newin{4,6}
   *
   * @deprecated Use set_allowed_apis(GLApi apis) instead.
   *
   * @param apis The allowed APIs.
   */
  void set_allowed_apis(GLAPI apis);
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Gets the allowed APIs set via set_allowed_apis().
   *
   * @newin{4,6}
   *
   * @deprecated Use get_allowed_apis2() instead.
   *
   * @return The allowed APIs.
   */
  auto get_allowed_apis() const -> GLAPI;
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Gets the API currently in use.
   *
   * If the renderer has not been realized yet, 0 is returned.
   *
   * @newin{4,6}
   *
   * @deprecated Use get_api2() instead.
   *
   * @return The currently used API.
   */
  auto get_api() const -> GLAPI;
#endif // GDKMM_DISABLE_DEPRECATED


#endif // GLAPI

  /** Sets the allowed APIs. When realize() is called, only the
   * allowed APIs will be tried. If you set this to 0, realizing will always fail.
   *
   * If you set it on a realized context, the property will not have any effect.
   * It is only relevant during realize().
   *
   * By default, all APIs are allowed.
   *
   * @newin{4,8}
   *
   * @param apis The allowed APIs.
   */
  void set_allowed_apis(GLApi apis);


  /** Gets the allowed APIs set via set_allowed_apis().
   *
   * @newin{4,8}
   *
   * @return The allowed APIs.
   */
  auto get_allowed_apis2() const -> GLApi;

  /** Gets the API currently in use.
   *
   * If the renderer has not been realized yet, 0 is returned.
   *
   * @newin{4,8}
   *
   * @return The currently used API.
   */
  auto get_api2() const -> GLApi;

#ifndef GDKMM_DISABLE_DEPRECATED

  /** Requests that GDK create an OpenGL ES context instead of an OpenGL one.
   *
   * Not all platforms support OpenGL ES.
   *
   * The @a context must not have been realized.
   *
   * By default, GDK will attempt to automatically detect whether the
   * underlying GL implementation is OpenGL or OpenGL ES once the @a context
   * is realized.
   *
   * You should check the return value of get_use_es()
   * after calling realize() to decide whether to use
   * the OpenGL or OpenGL ES API, extensions, or shaders.
   *
   * @deprecated Use set_allowed_apis(GLApi apis) instead.
   *
   * @param use_es Whether the context should use OpenGL ES instead of OpenGL,
   * or -1 to allow auto-detection.
   */
  void set_use_es(bool use_es =  true);
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED
  /** Undo a previous call to set_use_es().
   *
   * GDK will attempt to automatically detect whether the underlying
   * GL implementation is OpenGL or OpenGL ES once the %GLContext is realized.
   *
   * @newin{3,24}
   *
   * @deprecated Use set_allowed_apis(GLApi apis) instead.
   */
  void unset_use_es();
#endif // GDKMM_DISABLE_DEPRECATED


  /** Checks whether the @a context is using an OpenGL or OpenGL ES profile.
   *
   * @return <tt>true</tt> if the `Gdk::GLContext` is using an OpenGL ES profile;
   * <tt>false</tt> if other profile is in use of if the @a context has not yet
   * been realized.
   */
  auto get_use_es() const -> bool;

  /** Realizes the given `Gdk::GLContext`.
   *
   * It is safe to call this function on a realized `Gdk::GLContext`.
   *
   * @newin{3,18}
   *
   * @return <tt>true</tt> if the context is realized.
   *
   * @throws Glib::Error
   */
  auto realize() -> bool;


  /** Makes the @a context the current one.
   *
   * @newin{3,18}
   */
  void make_current();

  /** Retrieves the current `Gdk::GLContext`.
   *
   * @newin{3,18}
   *
   * @return The current `Gdk::GLContext`.
   */
  static auto get_current() -> Glib::RefPtr<GLContext>;

  /** Clears the current `Gdk::GLContext`.
   *
   * Any OpenGL call after this function returns will be ignored
   * until make_current() is called.
   *
   * @newin{3,18}
   */
  static void clear_current();


#ifndef GDKMM_DISABLE_DEPRECATED

/** Always <tt>nullptr</tt>
   *
   * As many contexts can share data now and no single shared context exists
   * anymore, this function has been deprecated and now always returns <tt>nullptr</tt>.
   *
   * Deprecated: 4.4: Use Gdk::GLContext::is_shared() to check if contexts
   * can be shared.
   *
   * @newin{3,18}
   *
   * @deprecated Always returns an empty RefPtr. Use is_shared() to check if contexts can be shared.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_shared_context() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<GLContext> >;


#endif // GDKMM_DISABLE_DEPRECATED

#ifndef GLAPI
  //TODO: When we can break API/ABI, change GLAPI to GLApi.
  // Can't have both _WRAP_PROPERTY("xxx", GLAPI) and _WRAP_PROPERTY("xxx", GLApi).

#ifndef GDKMM_DISABLE_DEPRECATED

/** The allowed APIs.
   *
   * @newin{4,6}
   *
   * @deprecated Use set/get-methods instead.
   *
   * Default value: Gdk::GLAPI::GL | Gdk::GLAPI::GLES
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_allowed_apis() -> Glib::PropertyProxy< GLAPI > ;

/** The allowed APIs.
   *
   * @newin{4,6}
   *
   * @deprecated Use set/get-methods instead.
   *
   * Default value: Gdk::GLAPI::GL | Gdk::GLAPI::GLES
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_allowed_apis() const -> Glib::PropertyProxy_ReadOnly< GLAPI >;

#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

/** The API currently in use.
   *
   * @newin{4,6}
   *
   * @deprecated Use get_api2() instead.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_api() const -> Glib::PropertyProxy_ReadOnly< GLAPI >;


#endif // GDKMM_DISABLE_DEPRECATED

#endif // GLAPI


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::GLContext
   */
  GDKMM_API
  auto wrap(GdkGLContext* object, bool take_copy = false) -> Glib::RefPtr<Gdk::GLContext>;
}


#endif /* _GDKMM_GLCONTEXT_H */

