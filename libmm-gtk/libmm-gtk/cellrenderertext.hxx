
#ifndef _GTKMM_CELLRENDERERTEXT_H
#define _GTKMM_CELLRENDERERTEXT_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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


#include <libmm-gtk/cellrenderer.hpp>
#include <libmm-pango/attrlist.hpp>
#include <libmm-pango/fontdescription.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererText = struct _GtkCellRendererText;
using GtkCellRendererTextClass = struct _GtkCellRendererTextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellRendererText_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Renders text in a cell.
 *
 * @ingroup TreeView
 */

class GTKMM_API CellRendererText : public CellRenderer
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellRendererText CppObjectType;
  typedef CellRendererText_Class CppClassType;
  typedef GtkCellRendererText BaseObjectType;
  typedef GtkCellRendererTextClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CellRendererText(CellRendererText&& src) noexcept;
  auto operator=(CellRendererText&& src) noexcept -> CellRendererText&;

  // noncopyable
  CellRendererText(const CellRendererText&) = delete;
  auto operator=(const CellRendererText&) -> CellRendererText& = delete;

  ~CellRendererText() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class CellRendererText_Class;
  static CppClassType cellrenderertext_class_;

protected:
  explicit CellRendererText(const Glib::ConstructParams& construct_params);
  explicit CellRendererText(GtkCellRendererText* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellRendererText*       { return reinterpret_cast<GtkCellRendererText*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellRendererText* { return reinterpret_cast<GtkCellRendererText*>(gobject_); }

private:

public:
  CellRendererText();


  /** Sets the height of a renderer to explicitly be determined by the “font” and
   * “y_pad” property set on it.  Further changes in these properties do not
   * affect the height, so they must be accompanied by a subsequent call to this
   * function.  Using this function is inflexible, and should really only be used
   * if calculating the size of a cell is too slow (ie, a massive number of cells
   * displayed).  If @a number_of_rows is -1, then the fixed height is unset, and
   * the height is determined by the properties again.
   *
   * @param number_of_rows Number of rows of text each cell renderer is allocated, or -1.
   */
  void set_fixed_height_from_font(int number_of_rows);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%edited(const Glib::ustring& path, const Glib::ustring& new_text)</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted after @a renderer has been edited.
   *
   * It is the responsibility of the application to update the model
   * and store @a new_text at the position indicated by @a path.
   *
   * @param path The path identifying the edited cell.
   * @param new_text The new text.
   */

  auto signal_edited() -> Glib::SignalProxy<void(const Glib::ustring&, const Glib::ustring&)>;


  /** Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_markup() -> Glib::PropertyProxy_WriteOnly< Glib::ustring > ;


  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() -> Glib::PropertyProxy< Pango::AttrList > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() const -> Glib::PropertyProxy_ReadOnly< Pango::AttrList >;

  /** Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background() -> Glib::PropertyProxy_WriteOnly< Glib::ustring > ;


  /** Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground() -> Glib::PropertyProxy_WriteOnly< Glib::ustring > ;


  /** Background color as a `GdkRGBA`
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** Background color as a `GdkRGBA`
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** Foreground color as a `GdkRGBA`
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** Foreground color as a `GdkRGBA`
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font() -> Glib::PropertyProxy< Glib::ustring > ;

/** Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_desc() -> Glib::PropertyProxy< Pango::FontDescription > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_desc() const -> Glib::PropertyProxy_ReadOnly< Pango::FontDescription >;

  /** Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family() -> Glib::PropertyProxy< Glib::ustring > ;

/** Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Default value: Pango::Style::NORMAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_style() -> Glib::PropertyProxy< Pango::Style > ;

/** Default value: Pango::Style::NORMAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_style() const -> Glib::PropertyProxy_ReadOnly< Pango::Style >;

  /** Default value: Pango::Variant::NORMAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_variant() -> Glib::PropertyProxy< Pango::Variant > ;

/** Default value: Pango::Variant::NORMAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_variant() const -> Glib::PropertyProxy_ReadOnly< Pango::Variant >;

  /** Default value: 400
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_weight() -> Glib::PropertyProxy< int > ;

/** Default value: 400
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_weight() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: Pango::Stretch::NORMAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stretch() -> Glib::PropertyProxy< Pango::Stretch > ;

/** Default value: Pango::Stretch::NORMAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stretch() const -> Glib::PropertyProxy_ReadOnly< Pango::Stretch >;

  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size() -> Glib::PropertyProxy< int > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size_points() -> Glib::PropertyProxy< double > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size_points() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale() -> Glib::PropertyProxy< double > ;

/** Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: Pango::Underline::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline() -> Glib::PropertyProxy< Pango::Underline > ;

/** Default value: Pango::Underline::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline() const -> Glib::PropertyProxy_ReadOnly< Pango::Underline >;

  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rise() -> Glib::PropertyProxy< int > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rise() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language() -> Glib::PropertyProxy< Glib::ustring > ;

/** Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Specifies the preferred place to ellipsize the string, if the cell renderer
   * does not have enough room to display the entire string. Setting it to
   * Pango::EllipsizeMode::NONE turns off ellipsizing. See the wrap-width property
   * for another way of making the text fit into a given width.
   *
   * Default value: Pango::EllipsizeMode::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ellipsize() -> Glib::PropertyProxy< Pango::EllipsizeMode > ;

/** Specifies the preferred place to ellipsize the string, if the cell renderer
   * does not have enough room to display the entire string. Setting it to
   * Pango::EllipsizeMode::NONE turns off ellipsizing. See the wrap-width property
   * for another way of making the text fit into a given width.
   *
   * Default value: Pango::EllipsizeMode::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ellipsize() const -> Glib::PropertyProxy_ReadOnly< Pango::EllipsizeMode >;

  /** The desired width of the cell, in characters. If this property is set to
   * -1, the width will be calculated automatically, otherwise the cell will
   * request either 3 characters or the property value, whichever is greater.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width_chars() -> Glib::PropertyProxy< int > ;

/** The desired width of the cell, in characters. If this property is set to
   * -1, the width will be calculated automatically, otherwise the cell will
   * request either 3 characters or the property value, whichever is greater.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The desired maximum width of the cell, in characters. If this property
   * is set to -1, the width will be calculated automatically.
   *
   * For cell renderers that ellipsize or wrap text; this property
   * controls the maximum reported width of the cell. The
   * cell should not receive any greater allocation unless it is
   * set to expand in its `Gtk::CellLayout` and all of the cell's siblings
   * have received their natural width.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width_chars() -> Glib::PropertyProxy< int > ;

/** The desired maximum width of the cell, in characters. If this property
   * is set to -1, the width will be calculated automatically.
   *
   * For cell renderers that ellipsize or wrap text; this property
   * controls the maximum reported width of the cell. The
   * cell should not receive any greater allocation unless it is
   * set to expand in its `Gtk::CellLayout` and all of the cell's siblings
   * have received their natural width.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Specifies how to break the string into multiple lines, if the cell
   * renderer does not have enough room to display the entire string.
   * This property has no effect unless the wrap-width property is set.
   *
   * Default value: Pango::WrapMode::CHAR
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() -> Glib::PropertyProxy< Pango::WrapMode > ;

/** Specifies how to break the string into multiple lines, if the cell
   * renderer does not have enough room to display the entire string.
   * This property has no effect unless the wrap-width property is set.
   *
   * Default value: Pango::WrapMode::CHAR
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() const -> Glib::PropertyProxy_ReadOnly< Pango::WrapMode >;

  /** Specifies the minimum width at which the text is wrapped. The wrap-mode property can
   * be used to influence at what character positions the line breaks can be placed.
   * Setting wrap-width to -1 turns wrapping off.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_width() -> Glib::PropertyProxy< int > ;

/** Specifies the minimum width at which the text is wrapped. The wrap-mode property can
   * be used to influence at what character positions the line breaks can be placed.
   * Setting wrap-width to -1 turns wrapping off.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Specifies how to align the lines of text with respect to each other.
   *
   * Note that this property describes how to align the lines of text in
   * case there are several of them. The "xalign" property of `Gtk::CellRenderer`,
   * on the other hand, sets the horizontal alignment of the whole text.
   *
   * Default value: Pango::Alignment::LEFT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_alignment() -> Glib::PropertyProxy< Pango::Alignment > ;

/** Specifies how to align the lines of text with respect to each other.
   *
   * Note that this property describes how to align the lines of text in
   * case there are several of them. The "xalign" property of `Gtk::CellRenderer`,
   * on the other hand, sets the horizontal alignment of the whole text.
   *
   * Default value: Pango::Alignment::LEFT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_alignment() const -> Glib::PropertyProxy_ReadOnly< Pango::Alignment >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_style_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_style_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_variant_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_variant_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_weight_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_weight_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stretch_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stretch_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rise_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rise_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ellipsize_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ellipsize_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_single_paragraph_mode() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_single_paragraph_mode() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_align_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_align_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The text that will be displayed in the `Gtk::CellRenderer` if
   * `GtkCellRendererText:editable` is <tt>true</tt> and the cell is empty.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text that will be displayed in the `Gtk::CellRenderer` if
   * `GtkCellRendererText:editable` is <tt>true</tt> and the cell is empty.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  auto _property_renderable() -> Glib::PropertyProxy_Base override;

protected:
  /** Emits the "edited" signal.
   * This is useful when implementing custom CellRenderers.
   */
  void edited(const Glib::ustring& path, const Glib::ustring& new_text);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_edited().
  virtual void on_edited(const Glib::ustring& path, const Glib::ustring& new_text);


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
   * @relates Gtk::CellRendererText
   */
  GTKMM_API
  auto wrap(GtkCellRendererText* object, bool take_copy = false) -> Gtk::CellRendererText*;
} //namespace Glib


#endif /* _GTKMM_CELLRENDERERTEXT_H */

