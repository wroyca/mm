
#ifndef _GTKMM_STYLECONTEXT_H
#define _GTKMM_STYLECONTEXT_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The gtkmm Development Team
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


#include <libmm-gtk/styleprovider.hxx>
#include <libmm-gtk/border.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gdk/display.hxx>
#include <libmm-gdk/rgba.hxx>

#include <libmm-gtk/enums.hxx>
#include <libmm-pango/context.hxx>
#include <libmm-pango/fontdescription.hxx>
#include <libmm-pango/layout.hxx>
#include <libmm-gtk/mm-gtkconfig.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStyleContext = struct _GtkStyleContext;
using GtkStyleContextClass = struct _GtkStyleContextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API StyleContext_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GTKMM_API Texture;
}

namespace Gtk
{

//TODO: Add (and translate to C++) the code examples from the C documentation.
/** This object stores styling information affecting a widget defined by WidgetPath.
 *
 * In order to construct the final style information, StyleContext
 * queries information from all attached StyleProviders. Style providers
 * can be either attached explicitly to the context through
 * add_provider(), or to the display through
 * add_provider_for_display(). The resulting style is a
 * combination of all providers' information in priority order.
 *
 * For GTK+ widgets, any StyleContext returned by
 * Widget::get_style_context() will already have a WidgetPath, a
 * Gdk::Display and RTL/LTR information set, The style context will be also
 * updated automatically if any of these settings change on the widget.
 *
 * <h2>Transition animations</h2>
 *
 * StyleContext has built-in support for state change transitions.
 * Note that these animations respect the Settings::property_gtk_enable_animations()
 * setting.
 *
 * For simple widgets where state changes affect the whole widget area,
 * calling notify_state_change() with a no region
 * is sufficient to trigger the transition animation. And GTK+ already
 * does that when Widget::set_state() or Widget::set_state_flags()
 * are called.
 *
 * If a widget needs to declare several animatable regions (i.e. not
 * affecting the whole widget area), its Widget::signal_draw() signal handler
 * needs to wrap the render operations for the different regions with
 * calls to push_animatable_region() and
 * pop_animatable_region(). These methods take an
 * identifier for the region which must be unique within the style context.
 * For simple widgets with a fixed set of animatable regions, using an
 * enumeration works well.
 *
 * For complex widgets with an arbitrary number of animatable regions, it
 * is up to the implementation to come up with a way to uniquely identify
 * each animatable region. Using pointers to internal objects is one way
 * to achieve this.
 *
 * The widget also needs to notify the style context about a state change
 * for a given animatable region so the animation is triggered.
 * notify_state_change() can take no region IDs, meaning that the whole widget
 * area will be updated by the animation.
 *
 * @newin{3,0}
 */

class GTKMM_API StyleContext : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = StyleContext;
  using CppClassType = StyleContext_Class;
  using BaseObjectType = GtkStyleContext;
  using BaseClassType = GtkStyleContextClass;

  // noncopyable
  StyleContext(const StyleContext&) = delete;
  auto operator=(const StyleContext&) -> StyleContext& = delete;

private:  friend class StyleContext_Class;
  static CppClassType stylecontext_class_;

protected:
  explicit StyleContext(const Glib::ConstructParams& construct_params);
  explicit StyleContext(GtkStyleContext* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  StyleContext(StyleContext&& src) noexcept;
  auto operator=(StyleContext&& src) noexcept -> StyleContext&;

  ~StyleContext() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkStyleContext*       { return reinterpret_cast<GtkStyleContext*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkStyleContext* { return reinterpret_cast<GtkStyleContext*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkStyleContext*;

private:

protected:
  StyleContext();

public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var PrintFlags NONE
   * Default value.
   *
   *  @var PrintFlags RECURSE
   * Print the entire tree of
   * CSS nodes starting at the style context's node.
   *
   *  @var PrintFlags SHOW_STYLE
   * Show the values of the
   * CSS properties for each node.
   *
   *  @var PrintFlags SHOW_CHANGE
   * Show information about
   * what changes affect the styles.
   *
   *  @enum PrintFlags
   *
   * Flags that modify the behavior of Gtk::StyleContext::to_string().
   *
   * New values may be added to this enumeration.
   *
   * @ingroup gtkmmEnums
   * @par Bitwise operators:
   * <tt>StyleContext::PrintFlags operator|(StyleContext::PrintFlags, StyleContext::PrintFlags)</tt><br>
   * <tt>StyleContext::PrintFlags operator&(StyleContext::PrintFlags, StyleContext::PrintFlags)</tt><br>
   * <tt>StyleContext::PrintFlags operator^(StyleContext::PrintFlags, StyleContext::PrintFlags)</tt><br>
   * <tt>StyleContext::PrintFlags operator~(StyleContext::PrintFlags)</tt><br>
   * <tt>StyleContext::PrintFlags& operator|=(StyleContext::PrintFlags&, StyleContext::PrintFlags)</tt><br>
   * <tt>StyleContext::PrintFlags& operator&=(StyleContext::PrintFlags&, StyleContext::PrintFlags)</tt><br>
   * <tt>StyleContext::PrintFlags& operator^=(StyleContext::PrintFlags&, StyleContext::PrintFlags)</tt><br>
   */
  enum class PrintFlags
  {
    NONE = 0x0,
    RECURSE = 1 << 0,
    SHOW_STYLE = 1 << 1,
    SHOW_CHANGE = 1 << 2
  };


  /** Adds a global style provider to @a display, which will be used
   * in style construction for all `Gtk::StyleContexts` under @a display.
   *
   * GTK uses this to make styling information from `Gtk::Settings`
   * available.
   *
   * @note If both priorities are the same, A `Gtk::StyleProvider`
   * added through add_provider() takes
   * precedence over another added through this function.
   *
   * @param display A `Gdk::Display`.
   * @param provider A `Gtk::StyleProvider`.
   * @param priority The priority of the style provider. The lower
   * it is, the earlier it will be used in the style construction.
   * Typically this will be in the range between
   * GTK_STYLE_PROVIDER_PRIORITY_FALLBACK and
   * GTK_STYLE_PROVIDER_PRIORITY_USER.
   */
  static void add_provider_for_display(const Glib::RefPtr<Gdk::Display>& display, const Glib::RefPtr<StyleProvider>& provider, guint priority);

  /** Removes @a provider from the global style providers list in @a display.
   *
   * @param display A `Gdk::Display`.
   * @param provider A `Gtk::StyleProvider`.
   */
  static void remove_provider_for_display(const Glib::RefPtr<Gdk::Display>& display, const Glib::RefPtr<StyleProvider>& provider);


  /** Adds a style provider to @a context, to be used in style construction.
   *
   * Note that a style provider added by this function only affects
   * the style of the widget to which @a context belongs. If you want
   * to affect the style of all widgets, use
   * add_provider_for_display().
   *
   * @note If both priorities are the same, a `Gtk::StyleProvider`
   * added through this function takes precedence over another added
   * through add_provider_for_display().
   *
   * @param provider A `Gtk::StyleProvider`.
   * @param priority The priority of the style provider. The lower
   * it is, the earlier it will be used in the style construction.
   * Typically this will be in the range between
   * GTK_STYLE_PROVIDER_PRIORITY_FALLBACK and
   * GTK_STYLE_PROVIDER_PRIORITY_USER.
   */
  void add_provider(const Glib::RefPtr<StyleProvider>& provider, guint priority);


  /** Removes @a provider from the style providers list in @a context.
   *
   * @param provider A `Gtk::StyleProvider`.
   */
  void remove_provider(const Glib::RefPtr<StyleProvider>& provider);


  /** Saves the @a context state.
   *
   * This allows temporary modifications done through
   * add_class(),
   * remove_class(),
   * set_state() to be quickly
   * reverted in one go through restore().
   *
   * The matching call to restore()
   * must be done before GTK returns to the main loop.
   */
  void context_save();

  /** Restores @a context state to a previous stage.
   *
   * See save().
   */
  void context_restore();


  /** Sets the state to be used for style matching.
   *
   * @param flags State to represent.
   */
  void set_state(StateFlags flags);

  /** Returns the state used for style matching.
   *
   * This method should only be used to retrieve the `Gtk::StateFlags`
   * to pass to `Gtk::StyleContext` methods, like
   * get_padding().
   * If you need to retrieve the current state of a `Gtk::Widget`, use
   * Gtk::Widget::get_state_flags().
   *
   * @return The state flags.
   */
  auto get_state() const -> StateFlags;


  /** Sets the scale to use when getting image assets for the style.
   *
   * @param scale Scale.
   */
  void set_scale(int scale);

  /** Returns the scale used for assets.
   *
   * @return The scale.
   */
  auto get_scale() const -> int;


  /** Adds a style class to @a context, so later uses of the
   * style context will make use of this new class for styling.
   *
   * In the CSS file format, a `Gtk::Entry` defining a “search”
   * class, would be matched by:
   *
   *
   * [C example ellipted]
   *
   * While any widget defining a “search” class would be
   * matched by:
   *
   * [C example ellipted]
   *
   * @param class_name Class name to use in styling.
   */
  void add_class(const Glib::ustring& class_name);

  /** Removes @a class_name from @a context.
   *
   * @param class_name Class name to remove.
   */
  void remove_class(const Glib::ustring& class_name);

  /** Returns <tt>true</tt> if @a context currently has defined the
   * given class name.
   *
   * @param class_name A class name.
   * @return <tt>true</tt> if @a context has @a class_name defined.
   */
  auto has_class(const Glib::ustring& class_name) -> bool;


  /** Attaches @a context to the given display.
   *
   * The display is used to add style information from “global”
   * style providers, such as the display's `Gtk::Settings` instance.
   *
   * If you are using a `Gtk::StyleContext` returned from
   * Gtk::Widget::get_style_context(), you do not need to
   * call this yourself.
   *
   * @param display A `Gdk::Display`.
   */
  void set_display(const Glib::RefPtr<Gdk::Display>& display);


  /** Returns the `Gdk::Display` to which @a context is attached.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() -> Glib::RefPtr<Gdk::Display>;

  /** Returns the `Gdk::Display` to which @a context is attached.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() const -> Glib::RefPtr<const Gdk::Display>;


  /** Looks up and resolves a color name in the @a context color map.
   *
   * @param color_name Color name to lookup.
   * @param color Return location for the looked up color.
   * @return <tt>true</tt> if @a color_name was found and resolved, <tt>false</tt> otherwise.
   */
  auto lookup_color(const Glib::ustring& color_name, Gdk::RGBA& color) -> bool;

  /** Gets the foreground color for a given state.
   *
   * @newin{3,0}
   *
   * @return The foreground color for the given state.
   */
  auto get_color() const -> Gdk::RGBA;


  auto get_border() const -> Border;


  auto get_padding() const -> Border;


  auto get_margin() const -> Border;


  /** Renders a checkmark (as in a `Gtk::CheckButton`).
   *
   * The Gtk::StateFlags::CHECKED state determines whether the check is
   * on or off, and Gtk::StateFlags::INCONSISTENT determines whether it
   * should be marked as undefined.
   *
   * Typical checkmark rendering:
   *
   * ![](checks.png)
   *
   * @param cr A `cairo_t`.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_check(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y, double width, double height);

  /** Renders an option mark (as in a radio button), the Gtk::StateFlags::CHECKED
   * state will determine whether the option is on or off, and
   * Gtk::StateFlags::INCONSISTENT whether it should be marked as undefined.
   *
   * Typical option mark rendering:
   *
   * ![](options.png)
   *
   * @param cr A `cairo_t`.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_option(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y, double width, double height);

  /** Renders an arrow pointing to @a angle.
   *
   * Typical arrow rendering at 0, 1⁄2 π;, π; and 3⁄2 π:
   *
   * ![](arrows.png)
   *
   * @param cr A `cairo_t`.
   * @param angle Arrow angle from 0 to 2 * G_PI, being 0 the arrow pointing to the north.
   * @param x X origin of the render area.
   * @param y Y origin of the render area.
   * @param size Square side for render area.
   */
  void render_arrow(const Cairo::RefPtr<Cairo::Context>& cr, double angle, double x, double y, double size);

  /** Renders the background of an element.
   *
   * Typical background rendering, showing the effect of
   * `background-image`, `border-width` and `border-radius`:
   *
   * ![](background.png)
   *
   * @param cr A `cairo_t`.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_background(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y, double width, double height);

  /** Renders a frame around the rectangle defined by @a x, @a y, @a width, @a height.
   *
   * Examples of frame rendering, showing the effect of `border-image`,
   * `border-color`, `border-width`, `border-radius` and junctions:
   *
   * ![](frames.png)
   *
   * @param cr A `cairo_t`.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_frame(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y, double width, double height);

  /** Renders an expander (as used in `Gtk::TreeView` and `Gtk::Expander`) in the area
   * defined by @a x, @a y, @a width, @a height. The state Gtk::StateFlags::CHECKED
   * determines whether the expander is collapsed or expanded.
   *
   * Typical expander rendering:
   *
   * ![](expanders.png)
   *
   * @param cr A `cairo_t`.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_expander(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y, double width, double height);

  /** Renders a focus indicator on the rectangle determined by @a x, @a y, @a width, @a height.
   *
   * Typical focus rendering:
   *
   * ![](focus.png)
   *
   * @param cr A `cairo_t`.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_focus(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y, double width, double height);

  /** Renders @a layout on the coordinates @a x, @a y
   *
   * @param cr A `cairo_t`.
   * @param x X origin.
   * @param y Y origin.
   * @param layout The `Pango::Layout` to render.
   */
  void render_layout(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y, const Glib::RefPtr<Pango::Layout>& layout);

  /** Renders a line from (x0, y0) to (x1, y1).
   *
   * @param cr A `cairo_t`.
   * @param x0 X coordinate for the origin of the line.
   * @param y0 Y coordinate for the origin of the line.
   * @param x1 X coordinate for the end of the line.
   * @param y1 Y coordinate for the end of the line.
   */
  void render_line(const Cairo::RefPtr<Cairo::Context>& cr, double x0, double y0, double x1, double y1);

  /** Renders a handle (as in `Gtk::Paned` and `Gtk::Window`’s resize grip),
   * in the rectangle determined by @a x, @a y, @a width, @a height.
   *
   * Handles rendered for the paned and grip classes:
   *
   * ![](handles.png)
   *
   * @param cr A `cairo_t`.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_handle(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y, double width, double height);

  /** Renders an activity indicator (such as in `Gtk::Spinner`).
   * The state Gtk::StateFlags::CHECKED determines whether there is
   * activity going on.
   *
   * @param cr A `cairo_t`.
   * @param x X origin of the rectangle.
   * @param y Y origin of the rectangle.
   * @param width Rectangle width.
   * @param height Rectangle height.
   */
  void render_activity(const Cairo::RefPtr<Cairo::Context>& cr, double x, double y, double width, double height);

  /** Renders the icon in @a texture at the specified @a x and @a y coordinates.
   *
   * This function will render the icon in @a texture at exactly its size,
   * regardless of scaling factors, which may not be appropriate when
   * drawing on displays with high pixel densities.
   *
   * @param cr A `cairo_t`.
   * @param texture A `Gdk::Texture` containing the icon to draw.
   * @param x X position for the @a texture.
   * @param y Y position for the @a texture.
   */
  void render_icon(const Cairo::RefPtr<Cairo::Context>& cr, const Glib::RefPtr<Gdk::Texture>& texture, double x, double y);


  /** Converts the style context into a string representation.
   *
   * The string representation always includes information about
   * the name, state, id, visibility and style classes of the CSS
   * node that is backing @a context. Depending on the flags, more
   * information may be included.
   *
   * This function is intended for testing and debugging of the
   * CSS implementation in GTK. There are no guarantees about
   * the format of the returned string, it may change.
   *
   * @param flags Flags that determine what to print.
   * @return A newly allocated string representing @a context.
   */
  auto to_string(PrintFlags flags) const -> Glib::ustring;

  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Display> > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Display> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk

namespace Gtk
{

/** @ingroup gtkmmEnums */
inline auto operator|(StyleContext::PrintFlags lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags
  { return static_cast<StyleContext::PrintFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(StyleContext::PrintFlags lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags
  { return static_cast<StyleContext::PrintFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(StyleContext::PrintFlags lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags
  { return static_cast<StyleContext::PrintFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(StyleContext::PrintFlags flags) -> StyleContext::PrintFlags
  { return static_cast<StyleContext::PrintFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(StyleContext::PrintFlags& lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags&
  { return (lhs = static_cast<StyleContext::PrintFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(StyleContext::PrintFlags& lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags&
  { return (lhs = static_cast<StyleContext::PrintFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(StyleContext::PrintFlags& lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags&
  { return (lhs = static_cast<StyleContext::PrintFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::StyleContext::PrintFlags> : public Glib::Value_Flags<Gtk::StyleContext::PrintFlags>
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
   * @relates Gtk::StyleContext
   */
  GTKMM_API
  auto wrap(GtkStyleContext* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StyleContext>;
}


#endif /* _GTKMM_STYLECONTEXT_H */

