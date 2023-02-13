
#ifndef _GTKMM_SNAPSHOT_H
#define _GTKMM_SNAPSHOT_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The gtkmm Development Team
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

#include <mm/gdk/snapshot.hpp>
#include <mm/gdk/rectangle.hpp>
#include <mm/gtk/stylecontext.hpp>


typedef struct _graphene_rect_t graphene_rect_t;


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Snapshot_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GTKMM_API RGBA;
class GTKMM_API Texture;
}

namespace Gtk
{

/** Auxiliary object for snapshots.
 *
 * %Snapshot is an auxiliary object that assists in creating GskRenderNodes
 * in Gtk::Widget::snapshot_vfunc(). It functions in a similar way to
 * a cairo context, and maintains a stack of render nodes and their associated
 * transformations.
 *
 * The node at the top of the stack is the the one that append_node()
 * operates on. Use the push() and pop() functions to change the current node.
 *
 * The typical way to obtain a %Snapshot object is as an argument to
 * Gtk::Widget::snapshot_vfunc(). If you need to create your own %Snapshot, use create().
 *
 * @newin{3,90}
 */

class GTKMM_API Snapshot : public Gdk::Snapshot
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Snapshot;
  using CppClassType = Snapshot_Class;
  using BaseObjectType = GtkSnapshot;
  using BaseClassType = GtkSnapshotClass;

  // noncopyable
  Snapshot(const Snapshot&) = delete;
  auto operator=(const Snapshot&) -> Snapshot& = delete;

private:  friend class Snapshot_Class;
  static CppClassType snapshot_class_;

protected:
  explicit Snapshot(const Glib::ConstructParams& construct_params);
  explicit Snapshot(GtkSnapshot* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Snapshot(Snapshot&& src) noexcept;
  auto operator=(Snapshot&& src) noexcept -> Snapshot&;

  ~Snapshot() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSnapshot*       { return reinterpret_cast<GtkSnapshot*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSnapshot* { return reinterpret_cast<GtkSnapshot*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSnapshot*;

private:

  // GtkSnapshot is typedefed as GdkSnapshot in gtktypes.h.
  // GtkSnapshot's wrap function can't be called wrap(). It would be ambiguous
  // when there is a wrap(GdkSnapshot*, bool)


public:
  //TODO: Add more methods. What shall be done with methods that take Gsk or graphene classes?


  // gtk_snapshot_new() does more than call g_object_new().

  /** Creates a new `Gtk::Snapshot`.
   *
   * @return A newly-allocated `Gtk::Snapshot`.
   */
  static auto create() -> Glib::RefPtr<Snapshot>;

  /** Creates a new debug node.
   *
   * @newin{3,94}
   *
   * @param name The name for the new node, or an empty string for no name.
   */
  void push_debug(const Glib::ustring& name);


  /** Modifies the opacity of an image.
   *
   * The image is recorded until the next call to pop().
   *
   * @param opacity The opacity to use.
   */
  void push_opacity(double opacity);

  /** Blurs an image.
   *
   * The image is recorded until the next call to pop().
   *
   * @param radius The blur radius to use. Must be positive.
   */
  void push_blur(double radius);


  /** Creates a node that repeats the child node.
   *
   * The child is recorded until the next call to pop().
   *
   * @param bounds The bounds within which to repeat.
   * @param child_bounds The bounds of the child or <tt>nullptr</tt>
   * to use the full size of the collected child node.
   */
  void push_repeat(const graphene_rect_t* bounds, const graphene_rect_t* child_bounds);

  /** Creates a node that repeats the child node.
   *
   * The child is recorded until the next call to pop().
   *
   * @param bounds The bounds within which to repeat.
   * @param child_bounds The bounds of the child or <tt>nullptr</tt>
   * to use the full size of the collected child node.
   */
  void push_repeat(const Gdk::Rectangle& bounds, const Gdk::Rectangle& child_bounds);

  /// A push_repeat() convenience overload.
  void push_repeat(const Gdk::Rectangle& bounds);


  /** Clips an image to a rectangle.
   *
   * The image is recorded until the next call to pop().
   *
   * @param bounds The rectangle to clip to.
   */
  void push_clip(const graphene_rect_t* bounds);

  /** Clips an image to a rectangle.
   *
   * The image is recorded until the next call to pop().
   *
   * @param bounds The rectangle to clip to.
   */
  void push_clip(const Gdk::Rectangle& bounds);


  /** Snapshots a cross-fade operation between two images with the
   * given @a progress.
   *
   * Until the first call to pop(), the start image
   * will be snapshot. After that call, the end image will be recorded
   * until the second call to pop().
   *
   * Calling this function requires two subsequent calls
   * to pop().
   *
   * @param progress Progress between 0.0 and 1.0.
   */
  void push_cross_fade(double progress);


  /** Removes the top element from the stack of render nodes and
   * adds it to the nearest Gsk::GLShaderNode below it.
   *
   * This must be called the same number of times as the number
   * of textures is needed for the shader in
   * push_gl_shader().
   */
  void gl_shader_pop_texture();

  /** Removes the top element from the stack of render nodes,
   * and appends it to the node underneath it.
   */
  void pop();


  /** Makes a copy of the current state of @a snapshot and saves it
   * on an internal stack.
   *
   * When restore() is called, @a snapshot will
   * be restored to the saved state. Multiple calls to
   * save() and [class@Snapshot.restore] can be nested;
   * each call to `restore()` restores the state from
   * the matching paired `save()`.
   *
   * It is necessary to clear all saved states with corresponding
   * calls to `restore()`.
   */
  void save();

  /** Restores @a snapshot to the state saved by a preceding call to
   * save() and removes that state from the stack of
   * saved states.
   */
  void restore();


  /** Rotates @ @a snapshot's coordinate system by @a angle degrees in 2D space -
   * or in 3D speak, rotates around the Z axis.
   *
   * To rotate around other axes, use Gsk::Transform::rotate_3d().
   *
   * @param angle The rotation angle, in degrees (clockwise).
   */
  void rotate(float angle);

  /** Scales @a snapshot's coordinate system in 2-dimensional space by
   * the given factors.
   *
   * Use scale_3d() to scale in all 3 dimensions.
   *
   * @param factor_x Scaling factor on the X axis.
   * @param factor_y Scaling factor on the Y axis.
   */
  void scale(float factor_x, float factor_y);

  /** Scales @a snapshot's coordinate system by the given factors.
   *
   * @param factor_x Scaling factor on the X axis.
   * @param factor_y Scaling factor on the Y axis.
   * @param factor_z Scaling factor on the Z axis.
   */
  void scale(float factor_x, float factor_y, float factor_z);

  /** Applies a perspective projection transform.
   *
   * See Gsk::Transform::perspective() for a discussion on the details.
   *
   * @param depth Distance of the z=0 plane.
   */
  void perspective(float depth);


  /** Creates a new Gsk::CairoNode and appends it to the current
   * render node of @a snapshot, without changing the current node.
   *
   * @param bounds The bounds for the new node.
   * @return A `cairo_t` suitable for drawing the contents of
   * the newly created render node.
   */
  auto append_cairo(const graphene_rect_t* bounds) -> Cairo::RefPtr<Cairo::Context>;

  /** Creates a new Gsk::CairoNode and appends it to the current
   * render node of @a snapshot, without changing the current node.
   *
   * @param bounds The bounds for the new node.
   * @return A `cairo_t` suitable for drawing the contents of
   * the newly created render node.
   */
  auto append_cairo(const Gdk::Rectangle& bounds) -> Cairo::RefPtr<Cairo::Context>;


  /** Creates a new render node drawing the @a texture
   * into the given @a bounds and appends it to the
   * current render node of @a snapshot.
   *
   * @param texture The texture to render.
   * @param bounds The bounds for the new node.
   */
  void append_texture(const Glib::RefPtr<Gdk::Texture>& texture, const graphene_rect_t* bounds);

  /** Creates a new render node drawing the @a texture
   * into the given @a bounds and appends it to the
   * current render node of @a snapshot.
   *
   * @param texture The texture to render.
   * @param bounds The bounds for the new node.
   */
  void append_texture(const Glib::RefPtr<Gdk::Texture>& texture, const Gdk::Rectangle& bounds);


  /** Creates a new render node drawing the @a color into the
   * given @a bounds and appends it to the current render node
   * of @a snapshot.
   *
   * You should try to avoid calling this function if
   *  @a color is transparent.
   *
   * @param color The color to draw.
   * @param bounds The bounds for the new node.
   */
  void append_color(const Gdk::RGBA& color, const graphene_rect_t* bounds);

  /** Creates a new render node drawing the @a color into the
   * given @a bounds and appends it to the current render node
   * of @a snapshot.
   *
   * You should try to avoid calling this function if
   *  @a color is transparent.
   *
   * @param color The color to draw.
   * @param bounds The bounds for the new node.
   */
  void append_color(const Gdk::RGBA& color, const Gdk::Rectangle& bounds);

  /** Creates render nodes for rendering @a layout in the given foregound @a color
   * and appends them to the current node of @a snapshot without changing the
   * current node.
   *
   * @param layout The `Pango::Layout` to render.
   * @param color The foreground color to render the layout in.
   */
  void append_layout(const Glib::RefPtr<Pango::Layout>& layout, const Gdk::RGBA& color);


  /** Creates a render node for the CSS background according to @a context,
   * and appends it to the current node of @a snapshot, without changing
   * the current node.
   *
   * @param context The style context that defines the background.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_backgrount(const Glib::RefPtr<StyleContext>& context, double x, double y, double width, double height);

  /** Creates a render node for the CSS border according to @a context,
   * and appends it to the current node of @a snapshot, without changing
   * the current node.
   *
   * @param context The style context that defines the frame.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_frame(const Glib::RefPtr<StyleContext>& context, double x, double y, double width, double height);

  /** Creates a render node for the focus outline according to @a context,
   * and appends it to the current node of @a snapshot, without changing
   * the current node.
   *
   * @param context The style context that defines the focus ring.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_focus(const Glib::RefPtr<StyleContext>& context, double x, double y, double width, double height);

  /** Creates a render node for rendering @a layout according to the style
   * information in @a context, and appends it to the current node of @a snapshot,
   * without changing the current node.
   *
   * @param context The style context that defines the text.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param layout The `Pango::Layout` to render.
   */
  void render_layout(const Glib::RefPtr<StyleContext>& context, double x, double y, const Glib::RefPtr<Pango::Layout>& layout);

  /** Draws a text caret using @a snapshot at the specified index of @a layout.
   *
   * @param context A `Gtk::StyleContext`.
   * @param x X origin.
   * @param y Y origin.
   * @param layout The `Pango::Layout` of the text.
   * @param index The index in the `Pango::Layout`.
   * @param direction The `Pango::Direction` of the text.
   */
  void render_insertion_cursor(const Glib::RefPtr<StyleContext>& context, double x, double y, const Glib::RefPtr<Pango::Layout>& layout, int index, Pango::Direction direction);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk

namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * It's not called %wrap() because GtkSnapshot is a typedef of GdkSnapshot.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Snapshot
   */
  GTKMM_API
  auto wrap_gtk_snapshot(GtkSnapshot* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Snapshot>;
}


#endif /* _GTKMM_SNAPSHOT_H */

