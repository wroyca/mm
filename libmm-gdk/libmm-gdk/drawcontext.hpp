
#ifndef _GDKMM_DRAWCONTEXT_H
#define _GDKMM_DRAWCONTEXT_H

#include <mm/gdk/mm-gdkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2016 The gtkmm Development Team
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


#include <mm/glib/object.hpp>
#include <mm/cairo/region.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDrawContext = struct _GdkDrawContext;
using GdkDrawContextClass = struct _GdkDrawContextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API DrawContext_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GDKMM_API Display;
class GDKMM_API Surface;

/** Drawing context base class.
 *
 * %Gdk::DrawContext is the base object used by contexts implementing different
 * rendering methods, such as GLContext or VulkanContext. It provides
 * shared functionality between those contexts.
 *
 * You will always interact with one of those subclasses.
 *
 * @newin{3,90}
 */

class GDKMM_API DrawContext : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DrawContext;
  using CppClassType = DrawContext_Class;
  using BaseObjectType = GdkDrawContext;
  using BaseClassType = GdkDrawContextClass;

  // noncopyable
  DrawContext(const DrawContext&) = delete;
  auto operator=(const DrawContext&) -> DrawContext& = delete;

private:  friend class DrawContext_Class;
  static CppClassType drawcontext_class_;

protected:
  explicit DrawContext(const Glib::ConstructParams& construct_params);
  explicit DrawContext(GdkDrawContext* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DrawContext(DrawContext&& src) noexcept;
  auto operator=(DrawContext&& src) noexcept -> DrawContext&;

  ~DrawContext() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkDrawContext*       { return reinterpret_cast<GdkDrawContext*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkDrawContext* { return reinterpret_cast<GdkDrawContext*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkDrawContext*;

private:


protected:
  /// This constructor is protected because only derived classes shall be instantiated.
  DrawContext();

public:

  /** Retrieves the `Gdk::Display` the @a context is created for
   *
   * @return The `Gdk::Display`.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Retrieves the `Gdk::Display` the @a context is created for
   *
   * @return The `Gdk::Display`.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;

  /** Retrieves the surface that @a context is bound to.
   *
   * @return A `Gdk::Surface`.
   */
  auto get_surface() -> Glib::RefPtr<Surface>;

  /** Retrieves the surface that @a context is bound to.
   *
   * @return A `Gdk::Surface`.
   */
  auto get_surface() const -> Glib::RefPtr<const Surface>;

  /** Indicates that you are beginning the process of redrawing @a region
   * on the @a context's surface.
   *
   * Calling this function begins a drawing operation using @a context on the
   * surface that @a context was created from. The actual requirements and
   * guarantees for the drawing operation vary for different implementations
   * of drawing, so a Gdk::CairoContext and a Gdk::GLContext
   * need to be treated differently.
   *
   * A call to this function is a requirement for drawing and must be
   * followed by a call to end_frame(), which will
   * complete the drawing operation and ensure the contents become visible
   * on screen.
   *
   * Note that the @a region passed to this function is the minimum region that
   * needs to be drawn and depending on implementation, windowing system and
   * hardware in use, it might be necessary to draw a larger region. Drawing
   * implementation must use get_frame_region() to
   * query the region that must be drawn.
   *
   * When using GTK, the widget system automatically places calls to
   * begin_frame() and end_frame() via the
   * use of Gsk::Renderers, so application code does not need to call
   * these functions explicitly.
   *
   * @param region Minimum region that should be drawn.
   */
  void begin_frame(const ::Cairo::RefPtr<const ::Cairo::Region>& region);

  /** Ends a drawing operation started with begin_frame().
   *
   * This makes the drawing available on screen.
   * See begin_frame() for more details about drawing.
   *
   * When using a Gdk::GLContext, this function may call `glFlush()`
   * implicitly before returning; it is not recommended to call `glFlush()`
   * explicitly before calling this function.
   */
  void end_frame();

  /** Returns <tt>true</tt> if @a context is in the process of drawing to its surface.
   *
   * This is the case between calls to begin_frame()
   * and end_frame(). In this situation, drawing commands
   * may be effecting the contents of the @a context's surface.
   *
   * @return <tt>true</tt> if the context is between begin_frame()
   * and end_frame() calls.
   */
  auto is_in_frame() const -> bool;

  /** Retrieves the region that is currently being repainted.
   *
   * After a call to begin_frame() this function will
   * return a union of the region passed to that function and the area of the
   * surface that the @a context determined needs to be repainted.
   *
   * If @a context is not in between calls to begin_frame()
   * and end_frame(), <tt>nullptr</tt> will be returned.
   *
   * @return A Cairo region.
   */
  auto get_frame_region() const -> ::Cairo::RefPtr<const ::Cairo::Region>;

  /** The `Gdk::Display` used to create the `Gdk::DrawContext`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >;


  /** The `Gdk::Surface` the context is bound to.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_surface() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Surface> >;


  // There are no signals or vfuncs.


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
   * @relates Gdk::DrawContext
   */
  GDKMM_API
  auto wrap(GdkDrawContext* object, bool take_copy = false) -> Glib::RefPtr<Gdk::DrawContext>;
}


#endif /* _GDKMM_DRAWCONTEXT_H */

