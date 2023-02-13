
#ifndef _GTKMM_LABEL_H
#define _GTKMM_LABEL_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <libmm-gtk/widget.hpp>
#include <libmm-pango/attrlist.hpp>
#include <libmm-pango/tabarray.hpp>
#include <libmm-gio/menumodel.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLabel = struct _GtkLabel;
using GtkLabelClass = struct _GtkLabelClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Label_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class GTKMM_API Menu;

/** A widget that displays a small to medium amount of text.
 *
 * A simple setable widget for holding a Glib::ustring.
 *
 * Key values are the codes which are sent whenever a key is pressed or released.
 * The complete list of key values can be found in the
 * <a href="https://gitlab.gnome.org/GNOME/gtk/tree/main/gdk/gdkkeysyms.h">gdk/gdkkeysyms.h</a>
 * header file. They are prefixed with <tt>GDK_KEY_</tt>.
 *
 * The Label widget looks like this:
 * @image html label1.png
 *
 * @ingroup Widgets
 */

class GTKMM_API Label : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Label CppObjectType;
  typedef Label_Class CppClassType;
  typedef GtkLabel BaseObjectType;
  typedef GtkLabelClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Label(Label&& src) noexcept;
  auto operator=(Label&& src) noexcept -> Label&;

  // noncopyable
  Label(const Label&) = delete;
  auto operator=(const Label&) -> Label& = delete;

  ~Label() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Label_Class;
  static CppClassType label_class_;

protected:
  explicit Label(const Glib::ConstructParams& construct_params);
  explicit Label(GtkLabel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkLabel*       { return reinterpret_cast<GtkLabel*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkLabel* { return reinterpret_cast<GtkLabel*>(gobject_); }

private:

public:
  Label();
  explicit Label(const Glib::ustring& label, bool mnemonic = false);

  /** This constructor is a shortcut to create a Label with Widget
   * alignment properties different from the default Align::FILL.
   * @code
   * Gtk::Label label(text, h, v, mnemonic);
   * @endcode
   * is equivalent to:
   * @code
   * Gtk::Label label(text, mnemonic);
   * label.set_halign(h);
   * label.set_valign(v);
   * @endcode
   */
  Label(const Glib::ustring& label, Align halign, Align valign = Align::CENTER, bool mnemonic = false);


  /** Sets the text within the `Gtk::Label` widget.
   *
   * It overwrites any text that was there before.
   *
   * This function will clear any previously set mnemonic accelerators,
   * and set the [property@Gtk.Label:use-underline property] to <tt>false</tt> as
   * a side effect.
   *
   * This function will set the property_use_markup() property
   * to <tt>false</tt> as a side effect.
   *
   * See also: set_markup()
   *
   * @param str The text you want to set.
   */
  void set_text(const Glib::ustring & str);

  /** Fetches the text from a label.
   *
   * The returned text is as it appears on screen. This does not include
   * any embedded underlines indicating mnemonics or Pango markup. (See
   * get_label())
   *
   * @return The text in the label widget.
   */
  auto get_text() const -> Glib::ustring;


  /** Apply attributes to the label text.
   *
   * The attributes set with this function will be applied and merged with
   * any other attributes previously effected by way of the
   * property_use_underline() or property_use_markup()
   * properties. While it is not recommended to mix markup strings with
   * manually set attributes, if you must; know that the attributes will
   * be applied to the label after the markup string is parsed.
   *
   * @param attrs A Pango::AttrList.
   */
  void set_attributes(Pango::AttrList& attrs);

  /** Gets the labels attribute list.
   *
   * This is the Pango::AttrList that was set on the label using
   * set_attributes(), if any. This function does not
   * reflect attributes that come from the labels markup (see
   * set_markup()). If you want to get the effective
   * attributes for the label, use
   * `pango_layout_get_attribute (gtk_label_get_layout (self))`.
   *
   * @return The attribute list.
   */
  auto get_attributes() const -> Pango::AttrList;


  /** Sets the text of the label.
   *
   * The label is interpreted as including embedded underlines and/or Pango
   * markup depending on the values of the property_use_underline()
   * and property_use_markup() properties.
   *
   * @param str The new text to set for the label.
   */
  void set_label(const Glib::ustring& str);

  /** Fetches the text from a label.
   *
   * The returned text includes any embedded underlines indicating
   * mnemonics and Pango markup. (See get_text()).
   *
   * @return The text of the label widget.
   */
  auto get_label() const -> Glib::ustring;

  /** Sets the labels text and attributes from markup.
   *
   * The string must be marked up with Pango markup
   * (see pango_parse_markup()).
   *
   * If the @a str is external data, you may need to escape it
   * with Glib::markup_escape_text() or Glib::markup_printf_escaped():
   *
   *
   * [C example ellipted]
   *
   * This function will set the property_use_markup() property
   * to <tt>true</tt> as a side effect.
   *
   * If you set the label contents using the property_label()
   * property you should also ensure that you set the
   * property_use_markup() property accordingly.
   *
   * See also: set_text()
   *
   * @param str A markup string.
   */
  void set_markup(const Glib::ustring& str);

  /** Sets whether the text of the label contains markup.
   *
   * See set_markup().
   *
   * @param setting <tt>true</tt> if the label’s text should be parsed for markup.
   */
  void set_use_markup(bool setting =  true);

  /** Returns whether the label’s text is interpreted as Pango markup.
   *
   * See set_use_markup().
   *
   * @return <tt>true</tt> if the label’s text will be parsed for markup.
   */
  auto get_use_markup() const -> bool;

  /** Sets whether underlines in the text indicate mnemonics.
   *
   * @param setting <tt>true</tt> if underlines in the text indicate mnemonics.
   */
  void set_use_underline(bool setting =  true);

  /** Returns whether an embedded underlines in the label indicate mnemonics.
   *
   * See set_use_underline().
   *
   * @return <tt>true</tt> whether an embedded underline in the label indicates
   * the mnemonic accelerator keys.
   */
  auto get_use_underline() const -> bool;


  /** Sets the labels text, attributes and mnemonic from markup.
   *
   * Parses @a str which is marked up with Pango markup (see pango_parse_markup()),
   * setting the label’s text and attribute list based on the parse results.
   * If characters in @a str are preceded by an underscore, they are underlined
   * indicating that they represent a keyboard accelerator called a mnemonic.
   *
   * The mnemonic key can be used to activate another widget, chosen
   * automatically, or explicitly using set_mnemonic_widget().
   *
   * @param str A markup string.
   */
  void set_markup_with_mnemonic(const Glib::ustring& str);

  /** Return the mnemonic accelerator.
   *
   * If the label has been set so that it has a mnemonic key this function
   * returns the keyval used for the mnemonic accelerator. If there is no
   * mnemonic set up it returns `GDK_KEY_VoidSymbol`.
   *
   * @return GDK keyval usable for accelerators, or `GDK_KEY_VoidSymbol`.
   */
  auto get_mnemonic_keyval() const -> guint;

  /** Associate the label with its mnemonic target.
   *
   * If the label has been set so that it has a mnemonic key (using
   * i.e. set_markup_with_mnemonic(),
   * set_text_with_mnemonic(),
   * new_with_mnemonic()
   * or the [property@Gtk.Label:use_underline] property) the label can be
   * associated with a widget that is the target of the mnemonic. When the
   * label is inside a widget (like a Gtk::Button or a
   * Gtk::Notebook tab) it is automatically associated with the correct
   * widget, but sometimes (i.e. when the target is a Gtk::Entry next to
   * the label) you need to set it explicitly using this function.
   *
   * The target widget will be accelerated by emitting the
   * Gtk::GtkWidget::signal_mnemonic_activate() signal on it. The default handler for
   * this signal will activate the widget if there are no mnemonic collisions
   * and toggle focus between the colliding widgets otherwise.
   *
   * @param widget The target `Gtk::Widget`, or <tt>nullptr</tt> to unset.
   */
  void set_mnemonic_widget(Widget& widget);

  /** Retrieves the target of the mnemonic (keyboard shortcut) of this
   * label.
   *
   * See set_mnemonic_widget().
   *
   * @return The target of the label’s mnemonic,
   * or <tt>nullptr</tt> if none has been set and the default algorithm will be used.
   */
  auto get_mnemonic_widget() -> Widget*;

  /** Retrieves the target of the mnemonic (keyboard shortcut) of this
   * label.
   *
   * See set_mnemonic_widget().
   *
   * @return The target of the label’s mnemonic,
   * or <tt>nullptr</tt> if none has been set and the default algorithm will be used.
   */
  auto get_mnemonic_widget() const -> const Widget*;

  /** Sets the label’s text from the string @a str.
   *
   * If characters in @a str are preceded by an underscore, they are underlined
   * indicating that they represent a keyboard accelerator called a mnemonic.
   * The mnemonic key can be used to activate another widget, chosen
   * automatically, or explicitly using set_mnemonic_widget().
   *
   * @param str A string.
   */
  void set_text_with_mnemonic(const Glib::ustring& str);

  /** Sets the alignment of the lines in the text of the label relative to
   * each other.
   *
   * Gtk::Justification::LEFT is the default value when the widget is first created
   * with new(). If you instead want to set the alignment of
   * the label as a whole, use Gtk::Widget::set_halign() instead.
   * set_justify() has no effect on labels containing
   * only a single line.
   *
   * @param jtype A `Gtk::Justification`.
   */
  void set_justify(Justification jtype);

  /** Returns the justification of the label.
   *
   * See set_justify().
   *
   * @return `Gtk::Justification`.
   */
  auto get_justify() const -> Justification;


  /** Sets the mode used to ellipsizei the text.
   *
   * The text will be ellipsized if there is not enough space
   * to render the entire string.
   *
   * @param mode A `Pango::EllipsizeMode`.
   */
  void set_ellipsize(Pango::EllipsizeMode mode);

  /** Returns the ellipsizing position of the label.
   *
   * See set_ellipsize().
   *
   * @return `Pango::EllipsizeMode`.
   */
  auto get_ellipsize() const -> Pango::EllipsizeMode;


  /** Sets the desired width in characters of @a label to @a n_chars.
   *
   * @param n_chars The new desired width, in characters.
   */
  void set_width_chars(int n_chars);

  /** Retrieves the desired width of @a label, in characters.
   *
   * See set_width_chars().
   *
   * @return The width of the label in characters.
   */
  auto get_width_chars() const -> int;


  /** Sets the desired maximum width in characters of @a label to @a n_chars.
   *
   * @param n_chars The new desired maximum width, in characters.
   */
  void set_max_width_chars(int n_chars);

  /** Retrieves the desired maximum width of @a label, in characters.
   *
   * See set_width_chars().
   *
   * @return The maximum width of the label in characters.
   */
  auto get_max_width_chars() const -> int;


  /** Sets the number of lines to which an ellipsized, wrapping label
   * should be limited.
   *
   * This has no effect if the label is not wrapping or ellipsized.
   * Set this to -1 if you don’t want to limit the number of lines.
   *
   * @param lines The desired number of lines, or -1.
   */
  void set_lines(int lines);

  /** Gets the number of lines to which an ellipsized, wrapping
   * label should be limited.
   *
   * See set_lines().
   *
   * @return The number of lines.
   */
  auto get_lines() const -> int;


  /** Toggles line wrapping within the `Gtk::Label` widget.
   *
   * <tt>true</tt> makes it break lines if text exceeds the widget’s size.
   * <tt>false</tt> lets the text get cut off by the edge of the widget if
   * it exceeds the widget size.
   *
   * Note that setting line wrapping to <tt>true</tt> does not make the label
   * wrap at its parent container’s width, because GTK widgets
   * conceptually can’t make their requisition depend on the parent
   * container’s size. For a label that wraps at a specific position,
   * set the label’s width using Gtk::Widget::set_size_request().
   *
   * @param wrap The setting.
   */
  void set_wrap(bool wrap =  true);

  /** Returns whether lines in the label are automatically wrapped.
   *
   * See set_wrap().
   *
   * @return <tt>true</tt> if the lines of the label are automatically wrapped.
   */
  auto get_wrap() const -> bool;

  /** Controls how line wrapping is done.
   *
   * This only affects the label if line wrapping is on. (See
   * set_wrap()) The default is Pango::WrapMode::WORD
   * which means wrap on word boundaries.
   *
   * For sizing behavior, also consider the property_natural_wrap_mode()
   * property.
   *
   * @param wrap_mode The line wrapping mode.
   */
  void set_wrap_mode(Pango::WrapMode wrap_mode);

  /** Returns line wrap mode used by the label.
   *
   * See set_wrap_mode().
   *
   * @return The line wrap mode.
   */
  auto get_wrap_mode() const -> Pango::WrapMode;

  /** Select the line wrapping for the natural size request.
   *
   * This only affects the natural size requested, for the actual wrapping used,
   * see the property_wrap_mode() property.
   *
   * @newin{4,6}
   *
   * @param wrap_mode The line wrapping mode.
   */
  void set_natural_wrap_mode(NaturalWrapMode wrap_mode);

  /** Returns line wrap mode used by the label.
   *
   * See set_natural_wrap_mode().
   *
   * @newin{4,6}
   *
   * @return The natural line wrap mode.
   */
  auto get_natural_wrap_mode() const -> NaturalWrapMode;

  /** Makes text in the label selectable.
   *
   * Selectable labels allow the user to select text from the label,
   * for copy-and-paste.
   *
   * @param setting <tt>true</tt> to allow selecting text in the label.
   */
  void set_selectable(bool setting =  true);

  /** Returns whether the label is selectable.
   *
   * @return <tt>true</tt> if the user can copy text from the label.
   */
  auto get_selectable() const -> bool;

  /** Selects a range of characters in the label, if the label is selectable.
   *
   * See set_selectable(). If the label is not selectable,
   * this function has no effect. If @a start_offset or
   *  @a end_offset are -1, then the end of the label will be substituted.
   *
   * @param start_offset Start offset (in characters not bytes).
   * @param end_offset End offset (in characters not bytes).
   */
  void select_region(int start_offset, int end_offset);

  /** Selects a range of characters in the label, from @a start_offset to the end,
   * if the label is selectable.
   * See gtk_label_set_selectable(). If the label is not selectable,
   * this function has no effect.
   *
   * @param start_offset Start offset (in characters not bytes)
   */
  void select_region(int start_offset);


  /** Gets the selected range of characters in the label.
   *
   * @param start Return location for start of selection, as a character offset.
   * @param end Return location for end of selection, as a character offset.
   * @return <tt>true</tt> if selection is non-empty.
   */
  auto get_selection_bounds(int& start, int& end) const -> bool;


  /** Gets the Pango::Layout used to display the label.
   * The layout is useful to e.g. convert text positions to
   * pixel positions, in combination with get_layout_offsets().
   *
   * @return The Pango::Layout for this label.
   */
  auto get_layout() -> Glib::RefPtr<Pango::Layout>;

  /** Gets the Pango::Layout used to display the label.
   * The layout is useful to e.g. convert text positions to
   * pixel positions, in combination with get_layout_offsets().
   *
   * @return The Pango::Layout for this label.
   */
  auto get_layout() const -> Glib::RefPtr<const Pango::Layout>;

  /** Obtains the coordinates where the label will draw its `Pango::Layout`.
   *
   * The coordinates are useful to convert mouse events into coordinates
   * inside the Pango::Layout, e.g. to take some action if some part
   * of the label is clicked. Remember when using the Pango::Layout
   * functions you need to convert to and from pixels using PANGO_PIXELS()
   * or [const@Pango.SCALE].
   *
   * @param x Location to store X offset of layout.
   * @param y Location to store Y offset of layout.
   */
  void get_layout_offsets(int& x, int& y) const;


  /** Sets whether the label is in single line mode.
   *
   * @param single_line_mode <tt>true</tt> if the label should be in single line mode.
   */
  void set_single_line_mode(bool single_line_mode =  true);

  /** Returns whether the label is in single line mode.
   *
   * @return <tt>true</tt> when the label is in single line mode.
   */
  auto get_single_line_mode() const -> bool;


  /** Returns the URI for the currently active link in the label.
   *
   * The active link is the one under the mouse pointer or, in a
   * selectable label, the link in which the text cursor is currently
   * positioned.
   *
   * This function is intended for use in a signal_activate_link()
   * handler or for use in a Gtk::Widget::signal_query_tooltip() handler.
   *
   * @return The currently active URI.
   */
  auto get_current_uri() const -> Glib::ustring;


  /** Sets the `xalign` of the label.
   *
   * See the property_xalign() property.
   *
   * @param xalign The new xalign value, between 0 and 1.
   */
  void set_xalign(float xalign);

  /** Gets the `xalign` of the label.
   *
   * See the property_xalign() property.
   *
   * @return The xalign property.
   */
  auto get_xalign() const -> float;

  /** Sets the `yalign` of the label.
   *
   * See the property_yalign() property.
   *
   * @param yalign The new yalign value, between 0 and 1.
   */
  void set_yalign(float yalign);

  /** Gets the `yalign` of the label.
   *
   * See the property_yalign() property.
   *
   * @return The yalign property.
   */
  auto get_yalign() const -> float;


  /** Sets a menu model to add when constructing
   * the context menu for @a label.
   *
   * @param model A `Gio::MenuModel`.
   */
  void set_extra_menu(const Glib::RefPtr<Gio::MenuModel>& model);

  /** Gets the extra menu model of @a label.
   *
   * See set_extra_menu().
   *
   * @return The menu model.
   */
  auto get_extra_menu() -> Glib::RefPtr<Gio::MenuModel>;

  /** Gets the extra menu model of @a label.
   *
   * See set_extra_menu().
   *
   * @return The menu model.
   */
  auto get_extra_menu() const -> Glib::RefPtr<const Gio::MenuModel>;


  /** Sets the default tab stops for paragraphs in @a self.
   *
   * @newin{4,8}
   *
   * @param tabs Tabs as a `Pango::TabArray`.
   */
  void set_tabs(const Pango::TabArray& tabs);

  /** Gets the tabs for @a self.
   *
   * The returned array will be <tt>nullptr</tt> if “standard” (8-space) tabs are used.
   * Free the return value with Pango::TabArray::free().
   *
   * @newin{4,8}
   *
   * @return Copy of default tab array,
   * or <tt>nullptr</tt> if standard tabs are used; must be freed with
   * Pango::TabArray::free().
   */
  auto get_tabs() const -> Pango::TabArray;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%activate_link(const Glib::ustring& uri)</tt>
   *
   * Flags: Run Last
   *
   * Gets emitted to activate a URI.
   *
   * Applications may connect to it to override the default behaviour,
   * which is to call gtk_show_uri().
   *
   * @param uri The URI that is activated.
   * @return <tt>true</tt> if the link has been activated.
   */

  auto signal_activate_link() -> Glib::SignalProxy<bool(const Glib::ustring&)>;


  //Keybinding signals:


  /** The contents of the label.
   *
   * If the string contains Pango markup (see pango_parse_markup()),
   * you will have to set the property_use_markup() property to
   * <tt>true</tt> in order for the label to display the markup attributes. See also
   * Gtk::Label::set_markup() for a convenience function that sets both
   * this property and the property_use_markup() property at the
   * same time.
   *
   * If the string contains underlines acting as mnemonics, you will have to
   * set the property_use_underline() property to <tt>true</tt> in order
   * for the label to display them.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** The contents of the label.
   *
   * If the string contains Pango markup (see pango_parse_markup()),
   * you will have to set the property_use_markup() property to
   * <tt>true</tt> in order for the label to display the markup attributes. See also
   * Gtk::Label::set_markup() for a convenience function that sets both
   * this property and the property_use_markup() property at the
   * same time.
   *
   * If the string contains underlines acting as mnemonics, you will have to
   * set the property_use_underline() property to <tt>true</tt> in order
   * for the label to display them.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** A list of style attributes to apply to the text of the label.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() -> Glib::PropertyProxy< Pango::AttrList > ;

/** A list of style attributes to apply to the text of the label.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() const -> Glib::PropertyProxy_ReadOnly< Pango::AttrList >;

  /** <tt>true</tt> if the text of the label includes Pango markup.
   *
   * See pango_parse_markup().
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_markup() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if the text of the label includes Pango markup.
   *
   * See pango_parse_markup().
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_markup() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** <tt>true</tt> if the text of the label indicates a mnemonic with _.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_underline() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if the text of the label indicates a mnemonic with _.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_underline() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The alignment of the lines in the text of the label, relative to each other.
   *
   * This does *not* affect the alignment of the label within its allocation.
   * See property_xalign() for that.
   *
   * Default value: Gtk::Justification::LEFT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_justify() -> Glib::PropertyProxy< Justification > ;

/** The alignment of the lines in the text of the label, relative to each other.
   *
   * This does *not* affect the alignment of the label within its allocation.
   * See property_xalign() for that.
   *
   * Default value: Gtk::Justification::LEFT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_justify() const -> Glib::PropertyProxy_ReadOnly< Justification >;

  /** <tt>true</tt> if the label text will wrap if it gets too wide.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if the label text will wrap if it gets too wide.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Controls how the line wrapping is done.
   *
   * This only affects the formatting if line wrapping is on (see the
   * property_wrap() property). The default is Pango::WrapMode::WORD,
   * which means wrap on word boundaries.
   *
   * For sizing behavior, also consider the property_natural_wrap_mode()
   * property.
   *
   * Default value: Pango::WrapMode::WORD
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() -> Glib::PropertyProxy< Pango::WrapMode > ;

/** Controls how the line wrapping is done.
   *
   * This only affects the formatting if line wrapping is on (see the
   * property_wrap() property). The default is Pango::WrapMode::WORD,
   * which means wrap on word boundaries.
   *
   * For sizing behavior, also consider the property_natural_wrap_mode()
   * property.
   *
   * Default value: Pango::WrapMode::WORD
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() const -> Glib::PropertyProxy_ReadOnly< Pango::WrapMode >;

  /** Select the line wrapping for the natural size request.
   *
   * This only affects the natural size requested. For the actual wrapping used,
   * see the property_wrap_mode() property.
   *
   * The default is Gtk::NaturalWrapMode::INHERIT, which inherits the behavior of the
   * property_wrap_mode() property.
   *
   * @newin{4,6}
   *
   * Default value: Gtk::NaturalWrapMode::INHERIT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_natural_wrap_mode() -> Glib::PropertyProxy< NaturalWrapMode > ;

/** Select the line wrapping for the natural size request.
   *
   * This only affects the natural size requested. For the actual wrapping used,
   * see the property_wrap_mode() property.
   *
   * The default is Gtk::NaturalWrapMode::INHERIT, which inherits the behavior of the
   * property_wrap_mode() property.
   *
   * @newin{4,6}
   *
   * Default value: Gtk::NaturalWrapMode::INHERIT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_natural_wrap_mode() const -> Glib::PropertyProxy_ReadOnly< NaturalWrapMode >;

  /** Whether the label text can be selected with the mouse.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selectable() -> Glib::PropertyProxy< bool > ;

/** Whether the label text can be selected with the mouse.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selectable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The mnemonic accelerator key for the label.
   *
   * Default value: 16777215
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mnemonic_keyval() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** The widget to be activated when the labels mnemonic key is pressed.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mnemonic_widget() -> Glib::PropertyProxy< Widget* > ;

/** The widget to be activated when the labels mnemonic key is pressed.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mnemonic_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** The preferred place to ellipsize the string, if the label does
   * not have enough room to display the entire string.
   *
   * Note that setting this property to a value other than
   * Pango::EllipsizeMode::NONE has the side-effect that the label requests
   * only enough space to display the ellipsis "...". In particular, this
   * means that ellipsizing labels do not work well in notebook tabs, unless
   * the Gtk::NotebookPage::property_tab_expand() child property is set to <tt>true</tt>.
   * Other ways to set a label's width are Gtk::Widget::set_size_request()
   * and Gtk::Label::set_width_chars().
   *
   * Default value: Pango::EllipsizeMode::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ellipsize() -> Glib::PropertyProxy< Pango::EllipsizeMode > ;

/** The preferred place to ellipsize the string, if the label does
   * not have enough room to display the entire string.
   *
   * Note that setting this property to a value other than
   * Pango::EllipsizeMode::NONE has the side-effect that the label requests
   * only enough space to display the ellipsis "...". In particular, this
   * means that ellipsizing labels do not work well in notebook tabs, unless
   * the Gtk::NotebookPage::property_tab_expand() child property is set to <tt>true</tt>.
   * Other ways to set a label's width are Gtk::Widget::set_size_request()
   * and Gtk::Label::set_width_chars().
   *
   * Default value: Pango::EllipsizeMode::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ellipsize() const -> Glib::PropertyProxy_ReadOnly< Pango::EllipsizeMode >;

  /** The desired width of the label, in characters.
   *
   * If this property is set to -1, the width will be calculated automatically.
   *
   * See the section on [text layout](class.Label.html#text-layout) for details of how
   * property_width_chars() and property_max_width_chars()
   * determine the width of ellipsized and wrapped labels.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width_chars() -> Glib::PropertyProxy< int > ;

/** The desired width of the label, in characters.
   *
   * If this property is set to -1, the width will be calculated automatically.
   *
   * See the section on [text layout](class.Label.html#text-layout) for details of how
   * property_width_chars() and property_max_width_chars()
   * determine the width of ellipsized and wrapped labels.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the label is in single line mode.
   *
   * In single line mode, the height of the label does not depend on the
   * actual text, it is always set to ascent + descent of the font. This
   * can be an advantage in situations where resizing the label because
   * of text changes would be distracting, e.g. in a statusbar.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_single_line_mode() -> Glib::PropertyProxy< bool > ;

/** Whether the label is in single line mode.
   *
   * In single line mode, the height of the label does not depend on the
   * actual text, it is always set to ascent + descent of the font. This
   * can be an advantage in situations where resizing the label because
   * of text changes would be distracting, e.g. in a statusbar.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_single_line_mode() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The desired maximum width of the label, in characters.
   *
   * If this property is set to -1, the width will be calculated automatically.
   *
   * See the section on [text layout](class.Label.html#text-layout) for details of how
   * property_width_chars() and property_max_width_chars()
   * determine the width of ellipsized and wrapped labels.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width_chars() -> Glib::PropertyProxy< int > ;

/** The desired maximum width of the label, in characters.
   *
   * If this property is set to -1, the width will be calculated automatically.
   *
   * See the section on [text layout](class.Label.html#text-layout) for details of how
   * property_width_chars() and property_max_width_chars()
   * determine the width of ellipsized and wrapped labels.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The number of lines to which an ellipsized, wrapping label
   * should be limited.
   *
   * This property has no effect if the label is not wrapping or ellipsized.
   * Set this property to -1 if you don't want to limit the number of lines.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_lines() -> Glib::PropertyProxy< int > ;

/** The number of lines to which an ellipsized, wrapping label
   * should be limited.
   *
   * This property has no effect if the label is not wrapping or ellipsized.
   * Set this property to -1 if you don't want to limit the number of lines.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_lines() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The horizontal alignment of the label text inside its size allocation.
   *
   * Compare this to Gtk::Widget::property_halign(), which determines how the
   * labels size allocation is positioned in the space available for the label.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() -> Glib::PropertyProxy< float > ;

/** The horizontal alignment of the label text inside its size allocation.
   *
   * Compare this to Gtk::Widget::property_halign(), which determines how the
   * labels size allocation is positioned in the space available for the label.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() const -> Glib::PropertyProxy_ReadOnly< float >;

  /** The vertical alignment of the label text inside its size allocation.
   *
   * Compare this to Gtk::Widget::property_valign(), which determines how the
   * labels size allocation is positioned in the space available for the label.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_yalign() -> Glib::PropertyProxy< float > ;

/** The vertical alignment of the label text inside its size allocation.
   *
   * Compare this to Gtk::Widget::property_valign(), which determines how the
   * labels size allocation is positioned in the space available for the label.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_yalign() const -> Glib::PropertyProxy_ReadOnly< float >;

  /** A menu model whose contents will be appended to the context menu.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_extra_menu() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > ;

/** A menu model whose contents will be appended to the context menu.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_extra_menu() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >;

  /** Custom tabs for this label.
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs() -> Glib::PropertyProxy< Pango::TabArray > ;

/** Custom tabs for this label.
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs() const -> Glib::PropertyProxy_ReadOnly< Pango::TabArray >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

}  // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Label
   */
  GTKMM_API
  auto wrap(GtkLabel* object, bool take_copy = false) -> Gtk::Label*;
} //namespace Glib


#endif /* _GTKMM_LABEL_H */

