
#ifndef _PANGOMM_RENDERER_H
#define _PANGOMM_RENDERER_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* renderer.h
 *
 * Copyright(C) 2004 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or(at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <libmm-glib/object.hxx>
#include <libmm-pango/context.hxx>
#include <libmm-pango/glyphitem.hxx>
#include <libmm-pango/glyphstring.hxx>
#include <libmm-pango/layout.hxx>
#include <libmm-pango/layoutline.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoRenderer = struct _PangoRenderer;
using PangoRendererClass = struct _PangoRendererClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{ class PANGOMM_API Renderer_Class; } // namespace Pango
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Pango
{

/** Pango::Renderer is a base class that contains the necessary logic for rendering a Pango::Layout or Pango::LayoutLine.
 * By subclassing Pango::Renderer and overriding operations such as draw_glyphs and draw_rectangle,
 * renderers for particular font backends and destinations can be created.
 */

class PANGOMM_API Renderer : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Renderer;
  using CppClassType = Renderer_Class;
  using BaseObjectType = PangoRenderer;
  using BaseClassType = PangoRendererClass;

  // noncopyable
  Renderer(const Renderer&) = delete;
  auto operator=(const Renderer&) -> Renderer& = delete;

private:  friend class Renderer_Class;
  static CppClassType renderer_class_;

protected:
  explicit Renderer(const Glib::ConstructParams& construct_params);
  explicit Renderer(PangoRenderer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Renderer(Renderer&& src) noexcept;
  auto operator=(Renderer&& src) noexcept -> Renderer&;

  ~Renderer() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> PangoRenderer*       { return reinterpret_cast<PangoRenderer*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const PangoRenderer* { return reinterpret_cast<PangoRenderer*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> PangoRenderer*;

private:


public:
  /** @addtogroup pangommEnums pangomm Enums and Flags */

  /**
   *  @var Part FOREGROUND
   * The text itself.
   *
   *  @var Part BACKGROUND
   * The area behind the text.
   *
   *  @var Part UNDERLINE
   * Underlines.
   *
   *  @var Part STRIKETHROUGH
   * Strikethrough lines.
   *
   *  @var Part OVERLINE
   * Overlines.
   *
   *  @enum Part
   *
   * `Pango::RenderPart` defines different items to render for such
   * purposes as setting colors.
   *
   * @newin{1,8}
   *
   * @ingroup pangommEnums
   */
  enum class Part
  {
    FOREGROUND,
    BACKGROUND,
    UNDERLINE,
    STRIKETHROUGH,
    OVERLINE
  };


  /** Draws @a layout with the specified `Pango::Renderer`.
   *
   * This is equivalent to drawing the lines of the layout, at their
   * respective positions relative to @a x, @a y.
   *
   * @newin{1,8}
   *
   * @param layout A `Pango::Layout`.
   * @param x X position of left edge of baseline, in user space coordinates
   * in Pango units.
   * @param y Y position of left edge of baseline, in user space coordinates
   * in Pango units.
   */
  void draw_layout(const Glib::RefPtr<Layout>& layout, int x, int y);

  /** Draws @a line with the specified `Pango::Renderer`.
   *
   * This draws the glyph items that make up the line, as well as
   * shapes, backgrounds and lines that are specified by the attributes
   * of those items.
   *
   * @newin{1,8}
   *
   * @param line A `Pango::LayoutLine`.
   * @param x X position of left edge of baseline, in user space coordinates
   * in Pango units.
   * @param y Y position of left edge of baseline, in user space coordinates
   * in Pango units.
   */
  void draw_layout_line(const Glib::RefPtr<LayoutLine>& line, int x, int y);

  /** Draws the glyphs in @a glyphs with the specified `Pango::Renderer`.
   *
   * @newin{1,8}
   *
   * @param font A `Pango::Font`.
   * @param glyphs A `Pango::GlyphString`.
   * @param x X position of left edge of baseline, in user space coordinates
   * in Pango units.
   * @param y Y position of left edge of baseline, in user space coordinates
   * in Pango units.
   */
  void draw_glyphs(const Glib::RefPtr<Font>& font, const GlyphString& glyphs, int x, int y);

  /** Draws the glyphs in @a glyph_item with the specified `Pango::Renderer`,
   * embedding the text associated with the glyphs in the output if the
   * output format supports it.
   *
   * This is useful for rendering text in PDF.
   *
   * Note that this method does not handle attributes in @a glyph_item.
   * If you want colors, shapes and lines handled automatically according
   * to those attributes, you need to use draw_layout_line()
   * or draw_layout().
   *
   * Note that @a text is the start of the text for layout, which is then
   * indexed by `glyph_item->item->offset`.
   *
   * If @a text is <tt>nullptr</tt>, this simply calls draw_glyphs().
   *
   * The default implementation of this method simply falls back to
   * draw_glyphs().
   *
   * @newin{1,22}
   *
   * @param text The UTF-8 text that @a glyph_item refers to.
   * @param glyph_item A `Pango::GlyphItem`.
   * @param x X position of left edge of baseline, in user space coordinates
   * in Pango units.
   * @param y Y position of left edge of baseline, in user space coordinates
   * in Pango units.
   */
  void draw_glyph_item(const Glib::ustring& text, const GlyphItem& glyph_item, int x, int y);

  /** Draws an axis-aligned rectangle in user space coordinates with the
   * specified `Pango::Renderer`.
   *
   * This should be called while @a renderer is already active.
   * Use activate() to activate a renderer.
   *
   * @newin{1,8}
   *
   * @param part Type of object this rectangle is part of.
   * @param x X position at which to draw rectangle, in user space coordinates
   * in Pango units.
   * @param y Y position at which to draw rectangle, in user space coordinates
   * in Pango units.
   * @param width Width of rectangle in Pango units.
   * @param height Height of rectangle in Pango units.
   */
  void draw_rectangle(Part part, int x, int y, int width, int height);

  /** Draw a squiggly line that approximately covers the given rectangle
   * in the style of an underline used to indicate a spelling error.
   *
   * The width of the underline is rounded to an integer number
   * of up/down segments and the resulting rectangle is centered
   * in the original rectangle.
   *
   * This should be called while @a renderer is already active.
   * Use activate() to activate a renderer.
   *
   * @newin{1,8}
   *
   * @param x X coordinate of underline, in Pango units in user coordinate system.
   * @param y Y coordinate of underline, in Pango units in user coordinate system.
   * @param width Width of underline, in Pango units in user coordinate system.
   * @param height Height of underline, in Pango units in user coordinate system.
   */
  void draw_error_underline(int x, int y, int width, int height);

  /** Draws a trapezoid with the parallel sides aligned with the X axis
   * using the given `Pango::Renderer`; coordinates are in device space.
   *
   * @newin{1,8}
   *
   * @param part Type of object this trapezoid is part of.
   * @param y1 Y coordinate of top of trapezoid.
   * @param x11 X coordinate of left end of top of trapezoid.
   * @param x21 X coordinate of right end of top of trapezoid.
   * @param y2 Y coordinate of bottom of trapezoid.
   * @param x12 X coordinate of left end of bottom of trapezoid.
   * @param x22 X coordinate of right end of bottom of trapezoid.
   */
  void draw_trapezoid(Part part, double y1, double x11, double x21, double y2, double x12, double x22);

  /** Draws a single glyph with coordinates in device space.
   *
   * @newin{1,8}
   *
   * @param font A `Pango::Font`.
   * @param glyph The glyph index of a single glyph.
   * @param x X coordinate of left edge of baseline of glyph.
   * @param y Y coordinate of left edge of baseline of glyph.
   */
  void draw_glyph(const Glib::RefPtr<Font>& font, Glyph glyph, double x, double y);


  /** Does initial setup before rendering operations on @a renderer.
   *
   * deactivate() should be called when done drawing.
   * Calls such as draw_layout() automatically
   * activate the layout before drawing on it.
   *
   * Calls to activate() and
   * deactivate() can be nested and the
   * renderer will only be initialized and deinitialized once.
   *
   * @newin{1,8}
   */
  void activate();

  /** Cleans up after rendering operations on @a renderer.
   *
   * See docs for activate().
   *
   * @newin{1,8}
   */
  void deactivate();


  /** Informs Pango that the way that the rendering is done
   * for @a part has changed.
   *
   * This should be called if the rendering changes in a way that would
   * prevent multiple pieces being joined together into one drawing call.
   * For instance, if a subclass of `Pango::Renderer` was to add a stipple
   * option for drawing underlines, it needs to call
   *
   * ```
   * pango_renderer_part_changed (render, PANGO_RENDER_PART_UNDERLINE);
   * ```
   *
   * When the stipple changes or underlines with different stipples
   * might be joined together. Pango automatically calls this for
   * changes to colors. (See set_color())
   *
   * @newin{1,8}
   *
   * @param part The part for which rendering has changed.
   */
  void part_changed(Part part);


  /** Sets the color for part of the rendering.
   *
   * Also see set_alpha().
   *
   * @newin{1,8}
   *
   * @param part The part to change the color of.
   * @param color The new color or <tt>nullptr</tt> to unset the current color.
   */
  void set_color(Part part, const Color& color);


  /** Gets the current rendering color for the specified part.
   *
   * @newin{1,8}
   *
   * @param part The part to get the color for.
   * @return The color for the
   * specified part, or <tt>nullptr</tt> if it hasn't been set and should be
   * inherited from the environment.
   */
  auto get_color(Part part) const -> Color;


  /** Sets the alpha for part of the rendering.
   *
   * Note that the alpha may only be used if a color is
   * specified for @a part as well.
   *
   * @newin{1,38}
   *
   * @param part The part to set the alpha for.
   * @param alpha An alpha value between 1 and 65536, or 0 to unset the alpha.
   */
  void set_alpha(Part part, guint16 alpha);

  /** Gets the current alpha for the specified part.
   *
   * @newin{1,38}
   *
   * @param part The part to get the alpha for.
   * @return The alpha for the specified part,
   * or 0 if it hasn't been set and should be
   * inherited from the environment.
   */
  auto get_alpha(Part part) const -> guint16;


  /** Sets the transformation matrix that will be applied when rendering.
   *
   * @newin{1,8}
   *
   * @param matrix A `Pango::Matrix`, or <tt>nullptr</tt> to unset any existing matrix
   * (No matrix set is the same as setting the identity matrix.).
   */
  void set_matrix(const Matrix& matrix);

  /** Gets the transformation matrix that will be applied when rendering.
   * See set_matrix().
   *
   * @return The matrix. If no matrix has been set, an identity matrix is returned.
   */
  auto get_matrix() const -> Matrix;


  /** Gets the layout currently being rendered using @a renderer.
   *
   * Calling this function only makes sense from inside a subclass's
   * methods, like in its draw_shape vfunc, for example.
   *
   * The returned layout should not be modified while still being
   * rendered.
   *
   * @newin{1,20}
   *
   * @return The layout, or <tt>nullptr</tt> if
   * no layout is being rendered using @a renderer at this time.
   */
  auto get_layout() -> Glib::RefPtr<Layout>;

  /** Gets the layout currently being rendered using @a renderer.
   *
   * Calling this function only makes sense from inside a subclass's
   * methods, like in its draw_shape vfunc, for example.
   *
   * The returned layout should not be modified while still being
   * rendered.
   *
   * @newin{1,20}
   *
   * @return The layout, or <tt>nullptr</tt> if
   * no layout is being rendered using @a renderer at this time.
   */
  auto get_layout() const -> Glib::RefPtr<const Layout>;


  /** Gets the layout line currently being rendered using @a renderer.
   *
   * Calling this function only makes sense from inside a subclass's
   * methods, like in its draw_shape vfunc, for example.
   *
   * The returned layout line should not be modified while still being
   * rendered.
   *
   * @newin{1,20}
   *
   * @return The layout line, or <tt>nullptr</tt>
   * if no layout line is being rendered using @a renderer at this time.
   */
  auto get_layout_line() -> Glib::RefPtr<LayoutLine>;

  /** Gets the layout line currently being rendered using @a renderer.
   *
   * Calling this function only makes sense from inside a subclass's
   * methods, like in its draw_shape vfunc, for example.
   *
   * The returned layout line should not be modified while still being
   * rendered.
   *
   * @newin{1,20}
   *
   * @return The layout line, or <tt>nullptr</tt>
   * if no layout line is being rendered using @a renderer at this time.
   */
  auto get_layout_line() const -> Glib::RefPtr<const LayoutLine>;

protected:


    virtual void draw_glyphs_vfunc(const Glib::RefPtr<Font>& font, const GlyphString& glyphs, int x, int y);

    virtual void draw_rectangle_vfunc(Part part, int x, int y, int width, int height);

    virtual void draw_error_underline_vfunc(int x, int y, int width, int height);

    virtual void draw_shape_vfunc(const AttrShape& attr, int x, int y);

    virtual void draw_trapezoid_vfunc(Part part, double y1, double x11, double x21, double y2, double x12, double x22);

    virtual void draw_glyph_vfunc(const Glib::RefPtr<Font>& font, Glyph glyph, double x, double y);

    virtual void part_changed_vfunc(Part part);

    virtual void begin_vfunc();

    virtual void end_vfunc();

    virtual void prepare_run_vfunc(const GlyphItem& run);

    virtual void draw_glyph_item_vfunc(const Glib::ustring& text, const GlyphItem& glyph_item, int x, int y);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Pango */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::Renderer::Part> : public Glib::Value_Enum<Pango::Renderer::Part>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Pango::Renderer
   */
  PANGOMM_API
  auto wrap(PangoRenderer* object, bool take_copy = false) -> Glib::RefPtr<Pango::Renderer>;
}


#endif /* _PANGOMM_RENDERER_H */

