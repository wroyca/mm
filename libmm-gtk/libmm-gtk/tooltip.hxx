
#ifndef _GTKMM_TOOLTIP_H
#define _GTKMM_TOOLTIP_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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

#include <libmm-glib/object.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gdk/paintable.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/widget.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTooltip = struct _GtkTooltip;
using GtkTooltipClass = struct _GtkTooltipClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Tooltip_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Add tips to your widgets
 *
 * Basic tooltips can be realized simply by using set_tooltip_text()
 * or set_tooltip_markup() without any explicit tooltip object.
 *
 * When you need a tooltip with a little more fancy contents, like
 * adding an image, or you want the tooltip to have different contents
 * per Gtk::TreeView row or cell, you will have to do a little more work:
 *
 * - Call Gtk::Widget:set_has_tooltip(); this will
 * make GTK+ monitor the widget for motion and related events
 * which are needed to determine when and where to show a tooltip.
 *
 * - Connect to Gtk::Widget::signal_query_tooltip(). This signal
 * will be emitted when a tooltip is supposed to be shown. One
 * of the arguments passed to the signal handler is a Gtk::Tooltip
 * object. This is the object that we are about to display as a
 * tooltip, and can be manipulated in your callback using functions
 * like Gtk::Tooltip::set_icon(). There are functions for setting
 * the tooltip's markup, setting an image from a named icon, or
 * even putting in a custom widget.
 *
 * - Return true from your query-tooltip handler. This causes
 * the tooltip to be show. If you return false, it will not be shown.
 *
 * @newin{2,12}
 */

class GTKMM_API Tooltip : public Glib::Object
{
protected:

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Tooltip;
  using CppClassType = Tooltip_Class;
  using BaseObjectType = GtkTooltip;
  using BaseClassType = GtkTooltipClass;

  // noncopyable
  Tooltip(const Tooltip&) = delete;
  auto operator=(const Tooltip&) -> Tooltip& = delete;

private:  friend class Tooltip_Class;
  static CppClassType tooltip_class_;

protected:
  explicit Tooltip(const Glib::ConstructParams& construct_params);
  explicit Tooltip(GtkTooltip* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Tooltip(Tooltip&& src) noexcept;
  auto operator=(Tooltip&& src) noexcept -> Tooltip&;

  ~Tooltip() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTooltip*       { return reinterpret_cast<GtkTooltip*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTooltip* { return reinterpret_cast<GtkTooltip*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTooltip*;

private:


public:

  /** Sets the text of the tooltip to be @a markup.
   *
   * The string must be marked up with Pango markup.
   * If @a markup is <tt>nullptr</tt>, the label will be hidden.
   *
   * @param markup A string with Pango markup or N::LL.
   */
  void set_markup(const Glib::ustring& markup);

  /** Hide the label.
   * @newin{3,2}
   */
  void unset_markup();


  /** Sets the text of the tooltip to be @a text.
   *
   * If @a text is <tt>nullptr</tt>, the label will be hidden.
   * See also set_markup().
   *
   * @param text A text string.
   */
  void set_text(const Glib::ustring& text);

  /** Hide the label.
   * @newin{3,2}
   */
  void unset_text();


  /** Sets the icon of the tooltip (which is in front of the text) to be
   *  @a paintable.  If @a paintable is <tt>nullptr</tt>, the image will be hidden.
   *
   * @param paintable A `Gdk::Paintable`.
   */
  void set_icon(const Glib::RefPtr<Gdk::Paintable>& paintable);

  /** Sets the icon of the tooltip (which is in front of the text)
   * to be the icon indicated by @a gicon with the size indicated
   * by @a size. If @a gicon is <tt>nullptr</tt>, the image will be hidden.
   *
   * @param gicon A `Gio::Icon` representing the icon.
   */
  void set_icon(const Glib::RefPtr<Gio::Icon>& gicon);

  /** Sets the icon of the tooltip (which is in front of the text) to be
   * the icon indicated by @a icon_name with the size indicated
   * by @a size.  If @a icon_name is <tt>nullptr</tt>, the image will be hidden.
   *
   * @param icon_name An icon name.
   */
  void set_icon(const Glib::ustring& icon_name);

  /** Hide the image.
   * @newin{3,2}
   */
  void unset_icon();


  /** Replaces the widget packed into the tooltip with
   *  @a custom_widget. @a custom_widget does not get destroyed when the tooltip goes
   * away.
   * By default a box with a `Gtk::Image` and `Gtk::Label` is embedded in
   * the tooltip, which can be configured using set_markup()
   * and set_icon().
   *
   * @param custom_widget A `Gtk::Widget`, or <tt>nullptr</tt> to unset the old custom widget.
   */
  void set_custom(Widget& custom_widget);

  /** Remove the custom widget.
   * @newin{3,2}
   */
  void unset_custom();


  /** Sets the area of the widget, where the contents of this tooltip apply,
   * to be @a rect (in widget coordinates).  This is especially useful for
   * properly setting tooltips on `Gtk::TreeView` rows and cells, `Gtk::IconViews`,
   * etc.
   *
   * For setting tooltips on `Gtk::TreeView`, please refer to the convenience
   * functions for this: Gtk::TreeView::set_tooltip_row() and
   * Gtk::TreeView::set_tooltip_cell().
   *
   * @param rect A `Gdk::Rectangle`.
   */
  void set_tip_area(const Gdk::Rectangle& rect);


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
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Tooltip
   */
  GTKMM_API
  auto wrap(GtkTooltip* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Tooltip>;
}


#endif /* _GTKMM_TOOLTIP_H */

