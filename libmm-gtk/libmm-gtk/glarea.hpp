
#ifndef _GTKMM_GLAREA_H
#define _GTKMM_GLAREA_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2015 The gtkmm Development Team
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

#include <mm/gtk/widget.hpp>


#include <mm/gdk/glcontext.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGLArea = struct _GtkGLArea;
using GtkGLAreaClass = struct _GtkGLAreaClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GLArea_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget used for drawing with OpenGL.
 * @newin{3,18}
 * @ingroup Widgets
 */

class GTKMM_API GLArea : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef GLArea CppObjectType;
  typedef GLArea_Class CppClassType;
  typedef GtkGLArea BaseObjectType;
  typedef GtkGLAreaClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  GLArea(GLArea&& src) noexcept;
  auto operator=(GLArea&& src) noexcept -> GLArea&;

  // noncopyable
  GLArea(const GLArea&) = delete;
  auto operator=(const GLArea&) -> GLArea& = delete;

  ~GLArea() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class GLArea_Class;
  static CppClassType glarea_class_;

protected:
  explicit GLArea(const Glib::ConstructParams& construct_params);
  explicit GLArea(GtkGLArea* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkGLArea*       { return reinterpret_cast<GtkGLArea*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGLArea* { return reinterpret_cast<GtkGLArea*>(gobject_); }

private:

public:

  GLArea();


  /** Retrieves the `Gdk::GLContext` used by @a area.
   *
   * @newin{3,18}
   *
   * @return The `Gdk::GLContext`.
   */
  auto get_context() -> Glib::RefPtr<Gdk::GLContext>;

  /** Retrieves the `Gdk::GLContext` used by @a area.
   *
   * @newin{3,18}
   *
   * @return The `Gdk::GLContext`.
   */
  auto get_context() const -> Glib::RefPtr<const Gdk::GLContext>;

  /** Ensures that the `Gdk::GLContext` used by @a area is associated with
   * the `Gtk::GLArea`.
   *
   * This function is automatically called before emitting the
   * signal_render() signal, and doesn't normally need
   * to be called by application code.
   *
   * @newin{3,18}
   */
  void make_current();

  /** Marks the currently rendered data (if any) as invalid, and queues
   * a redraw of the widget.
   *
   * This ensures that the signal_render() signal
   * is emitted during the draw.
   *
   * This is only needed when set_auto_render() has
   * been called with a <tt>false</tt> value. The default behaviour is to
   * emit signal_render() on each draw.
   *
   * @newin{3,18}
   */
  void queue_render();

  /** Binds buffers to the framebuffer.
   *
   * Ensures that the @a area framebuffer object is made the current draw
   * and read target, and that all the required buffers for the @a area
   * are created and bound to the framebuffer.
   *
   * This function is automatically called before emitting the
   * signal_render() signal, and doesn't normally need to be
   * called by application code.
   *
   * @newin{3,18}
   */
  void attach_buffers();
  /** Check if any error is currently set on this <i>area</i>.
   *
   * The error may be obtained by using throw_if_error() and
   * set using set_error().
   *
   * @newin{3,18}
   *
   * @return true if an error is currently set.
   */
  auto has_error() const -> bool;


  /** Will throw the correct Glib::Error subclass if
   * any is currently set on this <i>area</i>.
   *
   * @newin{3,18}
   *
   * @throw Throws any currently set error (e.g. Gdk::GLError).
   */
  void throw_if_error() const;


  /** Sets an error on the <i>area</i> which will be shown
   * instead of GL rendering.
   *
   * This is useful in the signal_create_context() handler
   * if GL context creation fails.
   *
   * @newin{3,18}
   *
   * @param error The error to set on the <i>area</i>.
   */
  void set_error(const Glib::Error& error);
  /** Clears any previous set error on this <i>area</i> made with set_error().
   *
   * @newin{3,18}
   */
  void unset_error();

  /** Returns whether the area has a depth buffer.
   *
   * @newin{3,18}
   *
   * @return <tt>true</tt> if the @a area has a depth buffer, <tt>false</tt> otherwise.
   */
  auto get_has_depth_buffer() const -> bool;

  /** Sets whether the `Gtk::GLArea` should use a depth buffer.
   *
   * If @a has_depth_buffer is <tt>true</tt> the widget will allocate and
   * enable a depth buffer for the target framebuffer. Otherwise
   * there will be none.
   *
   * @newin{3,18}
   *
   * @param has_depth_buffer <tt>true</tt> to add a depth buffer.
   */
  void set_has_depth_buffer(bool has_depth_buffer =  true);

  /** Returns whether the area has a stencil buffer.
   *
   * @newin{3,18}
   *
   * @return <tt>true</tt> if the @a area has a stencil buffer, <tt>false</tt> otherwise.
   */
  auto get_has_stencil_buffer() const -> bool;

  /** Sets whether the `Gtk::GLArea` should use a stencil buffer.
   *
   * If @a has_stencil_buffer is <tt>true</tt> the widget will allocate and
   * enable a stencil buffer for the target framebuffer. Otherwise
   * there will be none.
   *
   * @newin{3,18}
   *
   * @param has_stencil_buffer <tt>true</tt> to add a stencil buffer.
   */
  void set_has_stencil_buffer(bool has_stencil_buffer =  true);

  /** Returns whether the area is in auto render mode or not.
   *
   * @newin{3,18}
   *
   * @return <tt>true</tt> if the @a area is auto rendering, <tt>false</tt> otherwise.
   */
  auto get_auto_render() const -> bool;

  /** Sets whether the `Gtk::GLArea` is in auto render mode.
   *
   * If @a auto_render is <tt>true</tt> the signal_render() signal will
   * be emitted every time the widget draws. This is the default and is
   * useful if drawing the widget is faster.
   *
   * If @a auto_render is <tt>false</tt> the data from previous rendering is kept
   * around and will be used for drawing the widget the next time,
   * unless the window is resized. In order to force a rendering
   * queue_render() must be called. This mode is
   * useful when the scene changes seldom, but takes a long time to redraw.
   *
   * @newin{3,18}
   *
   * @param auto_render A boolean.
   */
  void set_auto_render(bool auto_render =  true);

  /** Retrieves the required version of OpenGL.
   *
   * See set_required_version().
   *
   * @newin{3,18}
   *
   * @param major Return location for the required major version.
   * @param minor Return location for the required minor version.
   */
  void get_required_version(int& major, int& minor) const;

  /** Sets the required version of OpenGL to be used when creating
   * the context for the widget.
   *
   * This function must be called before the area has been realized.
   *
   * @newin{3,18}
   *
   * @param major The major version.
   * @param minor The minor version.
   */
  void set_required_version(int major, int minor);

  /** Returns whether the `Gtk::GLArea` should use OpenGL ES.
   *
   * See set_use_es().
   *
   * @return <tt>true</tt> if the `Gtk::GLArea` should create an OpenGL ES context
   * and <tt>false</tt> otherwise.
   */
  auto get_use_es() const -> bool;

  /** Sets whether the @a area should create an OpenGL or an OpenGL ES context.
   *
   * You should check the capabilities of the `Gdk::GLContext` before drawing
   * with either API.
   *
   * @param use_es Whether to use OpenGL or OpenGL ES.
   */
  void set_use_es(bool use_es =  true);

  /** If set to <tt>true</tt> the signal_render() signal will be emitted every time
   * the widget draws.
   *
   * This is the default and is useful if drawing the widget is faster.
   *
   * If set to <tt>false</tt> the data from previous rendering is kept around and will
   * be used for drawing the widget the next time, unless the window is resized.
   * In order to force a rendering Gtk::GLArea::queue_render() must be called.
   * This mode is useful when the scene changes seldom, but takes a long time
   * to redraw.
   *
   * @newin{3,18}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_auto_render() -> Glib::PropertyProxy< bool > ;

/** If set to <tt>true</tt> the signal_render() signal will be emitted every time
   * the widget draws.
   *
   * This is the default and is useful if drawing the widget is faster.
   *
   * If set to <tt>false</tt> the data from previous rendering is kept around and will
   * be used for drawing the widget the next time, unless the window is resized.
   * In order to force a rendering Gtk::GLArea::queue_render() must be called.
   * This mode is useful when the scene changes seldom, but takes a long time
   * to redraw.
   *
   * @newin{3,18}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_auto_render() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The `Gdk::GLContext` used by the `Gtk::GLArea` widget.
   *
   * The `Gtk::GLArea` widget is responsible for creating the `Gdk::GLContext`
   * instance. If you need to render with other kinds of buffers (stencil,
   * depth, etc), use render buffers.
   *
   * @newin{3,18}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_context() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::GLContext> >;


  /** If set to <tt>true</tt> the widget will allocate and enable a depth buffer for the
   * target framebuffer.
   *
   * Setting this property will enable GL's depth testing as a side effect. If
   * you don't need depth testing, you should call `glDisable(GL_DEPTH_TEST)`
   * in your `GtkGLArea::render` handler.
   *
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_depth_buffer() -> Glib::PropertyProxy< bool > ;

/** If set to <tt>true</tt> the widget will allocate and enable a depth buffer for the
   * target framebuffer.
   *
   * Setting this property will enable GL's depth testing as a side effect. If
   * you don't need depth testing, you should call `glDisable(GL_DEPTH_TEST)`
   * in your `GtkGLArea::render` handler.
   *
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_depth_buffer() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If set to <tt>true</tt> the widget will allocate and enable a stencil buffer for the
   * target framebuffer.
   *
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_stencil_buffer() -> Glib::PropertyProxy< bool > ;

/** If set to <tt>true</tt> the widget will allocate and enable a stencil buffer for the
   * target framebuffer.
   *
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_stencil_buffer() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If set to <tt>true</tt> the widget will try to create a `Gdk::GLContext` using
   * OpenGL ES instead of OpenGL.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_es() -> Glib::PropertyProxy< bool > ;

/** If set to <tt>true</tt> the widget will try to create a `Gdk::GLContext` using
   * OpenGL ES instead of OpenGL.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_es() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /**
   * @par Slot Prototype:
   * <tt>Glib::RefPtr<Gdk::GLContext> on_my_%create_context()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the widget is being realized.
   *
   * This allows you to override how the GL context is created.
   * This is useful when you want to reuse an existing GL context,
   * or if you want to try creating different kinds of GL options.
   *
   * If context creation fails then the signal handler can use
   * Gtk::GLArea::set_error() to register a more detailed error
   * of how the construction failed.
   *
   * @newin{3,18}
   *
   * @return A newly created `Gdk::GLContext`;
   * the `Gtk::GLArea` widget will take ownership of the returned value.
   */

  auto signal_create_context() -> Glib::SignalProxy<Glib::RefPtr<Gdk::GLContext>()>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%render(const Glib::RefPtr<Gdk::GLContext>& context)</tt>
   *
   * Flags: Run Last
   *
   * Emitted every time the contents of the `Gtk::GLArea` should be redrawn.
   *
   * The @a context is bound to the @a area prior to emitting this function,
   * and the buffers are painted to the window once the emission terminates.
   *
   * @newin{3,18}
   *
   * @param context The `Gdk::GLContext` used by @a area.
   * @return <tt>true</tt> to stop other handlers from being invoked for the event.
   * <tt>false</tt> to propagate the event further.
   */

  auto signal_render() -> Glib::SignalProxy<bool(const Glib::RefPtr<Gdk::GLContext>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%resize(int width, int height)</tt>
   *
   * Flags: Run Last
   *
   * Emitted once when the widget is realized, and then each time the widget
   * is changed while realized.
   *
   * This is useful in order to keep GL state up to date with the widget size,
   * like for instance camera properties which may depend on the width/height
   * ratio.
   *
   * The GL context for the area is guaranteed to be current when this signal
   * is emitted.
   *
   * The default handler sets up the GL viewport.
   *
   * @newin{3,18}
   *
   * @param width The width of the viewport.
   * @param height The height of the viewport.
   */

  auto signal_resize() -> Glib::SignalProxy<void(int, int)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_create_context().
  virtual auto on_create_context() -> Glib::RefPtr<Gdk::GLContext>;
  /// This is a default handler for the signal signal_render().
  virtual auto on_render(const Glib::RefPtr<Gdk::GLContext>& context) -> bool;
  /// This is a default handler for the signal signal_resize().
  virtual void on_resize(int width, int height);


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::GLArea
   */
  GTKMM_API
  auto wrap(GtkGLArea* object, bool take_copy = false) -> Gtk::GLArea*;
} //namespace Glib


#endif /* _GTKMM_GLAREA_H */

