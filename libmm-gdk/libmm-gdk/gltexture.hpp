
#ifndef _GDKMM_GLTEXTURE_H
#define _GDKMM_GLTEXTURE_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2018 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-gdk/texture.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkGLTexture = struct _GdkGLTexture;
using GdkGLTextureClass = struct _GdkGLTextureClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API GLTexture_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GDKMM_API GLContext;

/** A Gdk::Texture representing a GL texture object.
 *
 * @newin{3,94}
 */

class GDKMM_API GLTexture : public Gdk::Texture
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = GLTexture;
  using CppClassType = GLTexture_Class;
  using BaseObjectType = GdkGLTexture;
  using BaseClassType = GdkGLTextureClass;

  // noncopyable
  GLTexture(const GLTexture&) = delete;
  auto operator=(const GLTexture&) -> GLTexture& = delete;

private:  friend class GLTexture_Class;
  static CppClassType gltexture_class_;

protected:
  explicit GLTexture(const Glib::ConstructParams& construct_params);
  explicit GLTexture(GdkGLTexture* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  GLTexture(GLTexture&& src) noexcept;
  auto operator=(GLTexture&& src) noexcept -> GLTexture&;

  ~GLTexture() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkGLTexture*       { return reinterpret_cast<GdkGLTexture*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkGLTexture* { return reinterpret_cast<GdkGLTexture*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkGLTexture*;

private:


protected:
  GLTexture();

public:
  /** For instance,
   * void on_gl_resources_released();
   */
  using SlotGLReleased = sigc::slot<void()>;

  // gdk_gl_texture_new() does more than call g_object_new().

  /** Creates a new texture for an existing GL texture.
   *
   * Note that the GL texture must not be modified until @a slot is called,
   * which will happen when the GdkTexture object is finalized, or due to
   * an explicit call of release().
   *
   * @param context A `Gdk::GLContext`.
   * @param id The ID of a texture that was created with @a context.
   * @param width The nominal width of the texture.
   * @param height The nominal height of the texture.
   * @param slot A destroy notify that will be called when the GL resources
   * are released.
   * @return A newly-created
   * `Gdk::Texture`.
   */
  static auto create(const Glib::RefPtr<GLContext>& context, guint id, int width, int height, const SlotGLReleased& slot =  {}) -> Glib::RefPtr<Texture>;


  /** Releases the GL resources held by a `Gdk::GLTexture`.
   *
   * The texture contents are still available via the
   * Gdk::Texture::download() function, after this
   * function has been called.
   */
  void release();

  // There are no public signals, properties or vfuncs.


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
   * @relates Gdk::GLTexture
   */
  GDKMM_API
  auto wrap(GdkGLTexture* object, bool take_copy = false) -> Glib::RefPtr<Gdk::GLTexture>;
}


#endif /* _GDKMM_GLTEXTURE_H */

