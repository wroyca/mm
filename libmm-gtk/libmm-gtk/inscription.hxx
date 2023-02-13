
#ifndef _GTKMM_INSCRIPTION_H
#define _GTKMM_INSCRIPTION_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2022 The gtkmm Development Team
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


#include <libmm-gtk/widget.hpp>
#include <libmm-pango/attrlist.hpp>
#include <libmm-pango/layout.hpp> // for Pango::WrapMode

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Inscription_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** %Gtk::Inscription is a widget to show text in a predefined area.
 *
 * You likely want to use Gtk::Label instead as this widget is intended only
 * for a small subset of use cases. The main scenario envisaged is inside lists
 * such as Gtk::ColumnView.
 *
 * While a Gtk::Label sizes itself depending on the text that is displayed,
 * %Gtk::Inscription is given a size and inscribes the given text into that
 * space as well as it can.
 *
 * Users of this widget should take care to plan behaviour for the common case
 * where the text doesn't fit exactly in the allocated space.
 *
 * @ingroup Widgets
 * @newin{4,8}
 */

class GTKMM_API Inscription : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Inscription CppObjectType;
  typedef Inscription_Class CppClassType;
  typedef GtkInscription BaseObjectType;
  typedef GtkInscriptionClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Inscription(Inscription&& src) noexcept;
  auto operator=(Inscription&& src) noexcept -> Inscription&;

  // noncopyable
  Inscription(const Inscription&) = delete;
  auto operator=(const Inscription&) -> Inscription& = delete;

  ~Inscription() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Inscription_Class;
  static CppClassType inscription_class_;

protected:
  explicit Inscription(const Glib::ConstructParams& construct_params);
  explicit Inscription(GtkInscription* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkInscription*       { return reinterpret_cast<GtkInscription*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkInscription* { return reinterpret_cast<GtkInscription*>(gobject_); }

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Overflow CLIP
   * Clip the remaining text.
   *
   *  @var Overflow ELLIPSIZE_START
   * Omit characters at the start of the text.
   *
   *  @var Overflow ELLIPSIZE_MIDDLE
   * Omit characters at the middle of the text.
   *
   *  @var Overflow ELLIPSIZE_END
   * Omit characters at the end of the text.
   *
   *  @enum Overflow
   *
   * The different methods to handle text in Gtk::Inscription when it doesn't
   * fit the available space.
   *
   * @newin{4,8}
   *
   * @ingroup gtkmmEnums
   */
  enum class Overflow
  {
    CLIP,
    ELLIPSIZE_START,
    ELLIPSIZE_MIDDLE,
    ELLIPSIZE_END
  };


  Inscription();

  /** Creates a new %Gtk::Inscription with the given text.
   * @param text The text.
   */
    explicit Inscription(const Glib::ustring& text);


  /** Gets the text that is displayed.
   *
   * @newin{4,8}
   *
   * @return The displayed text.
   */
  auto get_text() const -> Glib::ustring;

  /** Sets the text to be displayed.
   *
   * @newin{4,8}
   *
   * @param text The text to display.
   */
  void set_text(const Glib::ustring& text);

  /** Gets the inscription's attribute list.
   *
   * @newin{4,8}
   *
   * @return The attribute list.
   */
  auto get_attributes() const -> Pango::AttrList;

  /** Apply attributes to the inscription text.
   *
   * These attributes will not be evaluated for sizing the inscription.
   *
   * @newin{4,8}
   *
   * @param attrs A Pango::AttrList.
   */
  void set_attributes(Pango::AttrList& attrs);

  /** Utility function to set the text and attributes to be displayed.
   *
   * See the property_markup() property.
   *
   * @newin{4,8}
   *
   * @param markup The markup to display.
   */
  void set_markup(const Glib::ustring& markup);

  /** Gets the inscription's overflow method.
   *
   * @newin{4,8}
   *
   * @return The overflow method.
   */
  auto get_text_overflow() const -> Inscription::Overflow;

  /** Sets what to do when the text doesn't fit.
   *
   * @newin{4,8}
   *
   * @param overflow The overflow method to use.
   */
  void set_text_overflow(Overflow overflow);

  /** Returns line wrap mode used by the inscription.
   *
   * See set_wrap_mode().
   *
   * @newin{4,8}
   *
   * @return The line wrap mode.
   */
  auto get_wrap_mode() const -> Pango::WrapMode;

  /** Controls how line wrapping is done.
   *
   * @newin{4,8}
   *
   * @param wrap_mode The line wrapping mode.
   */
  void set_wrap_mode(Pango::WrapMode wrap_mode);

  /** Gets the `min-chars` of the inscription.
   *
   * See the property_min_chars() property.
   *
   * @newin{4,8}
   *
   * @return The min-chars property.
   */
  auto get_min_chars() const -> unsigned int;

  /** Sets the `min-chars` of the inscription.
   *
   * See the property_min_chars() property.
   *
   * @newin{4,8}
   *
   * @param min_chars The minimum number of characters that should fit, approximately.
   */
  void set_min_chars(unsigned int min_chars);

  /** Gets the `nat-chars` of the inscription.
   *
   * See the property_nat_chars() property.
   *
   * @newin{4,8}
   *
   * @return The nat-chars property.
   */
  auto get_nat_chars() const -> unsigned int;

  /** Sets the `nat-chars` of the inscription.
   *
   * See the property_nat_chars() property.
   *
   * @newin{4,8}
   *
   * @param nat_chars The number of characters that should ideally fit, approximately.
   */
  void set_nat_chars(unsigned int nat_chars);

  /** Gets the `min-lines` of the inscription.
   *
   * See the property_min_lines() property.
   *
   * @newin{4,8}
   *
   * @return The min-lines property.
   */
  auto get_min_lines() const -> unsigned int;

  /** Sets the `min-lines` of the inscription.
   *
   * See the property_min_lines() property.
   *
   * @newin{4,8}
   *
   * @param min_lines The minimum number of lines that should fit, approximately.
   */
  void set_min_lines(unsigned int min_lines);

  /** Gets the `nat-lines` of the inscription.
   *
   * See the property_nat_lines() property.
   *
   * @newin{4,8}
   *
   * @return The nat-lines property.
   */
  auto get_nat_lines() const -> unsigned int;

  /** Sets the `nat-lines` of the inscription.
   *
   * See the property_nat_lines() property.
   *
   * @newin{4,8}
   *
   * @param nat_lines The number of lines that should ideally fit.
   */
  void set_nat_lines(unsigned int nat_lines);

  /** Gets the `xalign` of the inscription.
   *
   * See the property_xalign() property.
   *
   * @newin{4,8}
   *
   * @return The xalign property.
   */
  auto get_xalign() const -> float;

  /** Sets the `xalign` of the inscription.
   *
   * See the property_xalign() property.
   *
   * @newin{4,8}
   *
   * @param xalign The new xalign value, between 0 and 1.
   */
  void set_xalign(float xalign);

  /** Gets the `yalign` of the inscription.
   *
   * See the property_yalign() property.
   *
   * @newin{4,8}
   *
   * @return The yalign property.
   */
  auto get_yalign() const -> float;

  /** Sets the `yalign` of the inscription.
   *
   * See the property_yalign() property.
   *
   * @newin{4,8}
   *
   * @param yalign The new yalign value, between 0 and 1.
   */
  void set_yalign(float yalign);

  /** A list of style attributes to apply to the text of the inscription.
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() -> Glib::PropertyProxy< Pango::AttrList > ;

/** A list of style attributes to apply to the text of the inscription.
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() const -> Glib::PropertyProxy_ReadOnly< Pango::AttrList >;

  /** Utility property that sets both the property_text() and
   * property_attributes() properties, mainly intended for use in
   * GtkBuilder ui files to ease translation support and bindings.
   *
   * This function uses pango_parse_markup() to parse the markup into text and
   * attributes. The markup must be valid. If you cannot ensure that, consider using
   * pango_parse_markup() and setting the two properties yourself.
   *
   * @newin{4,8}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_markup() -> Glib::PropertyProxy_WriteOnly< Glib::ustring > ;


  /** The number of characters that should fit into the inscription at minimum.
   *
   * This influences the requested width, not the width actually given to the widget,
   * which might turn out to be larger.
   *
   * Note that this is an approximate character width, so some characters might be
   * wider and some might be thinner, so do not expect the number of characters to
   * exactly match.
   *
   * If you set this property to 0, the inscription will not request any width at all
   * and its width will be determined entirely by its surroundings.
   *
   * @newin{4,8}
   *
   * Default value: 3
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_chars() -> Glib::PropertyProxy< unsigned int > ;

/** The number of characters that should fit into the inscription at minimum.
   *
   * This influences the requested width, not the width actually given to the widget,
   * which might turn out to be larger.
   *
   * Note that this is an approximate character width, so some characters might be
   * wider and some might be thinner, so do not expect the number of characters to
   * exactly match.
   *
   * If you set this property to 0, the inscription will not request any width at all
   * and its width will be determined entirely by its surroundings.
   *
   * @newin{4,8}
   *
   * Default value: 3
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_chars() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;

  /** The number of lines that should fit into the inscription at minimum.
   *
   * This influences the requested height, not the height actually given to the widget,
   * which might turn out to be larger.
   *
   * Note that this is an approximate line height, so if the text uses things like fancy
   * Unicode or attribute that influence the height, the text might not fit.
   *
   * If you set this property to 0, the inscription will not request any height at all
   * and its height will be determined entirely by its surroundings.
   *
   * @newin{4,8}
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_lines() -> Glib::PropertyProxy< unsigned int > ;

/** The number of lines that should fit into the inscription at minimum.
   *
   * This influences the requested height, not the height actually given to the widget,
   * which might turn out to be larger.
   *
   * Note that this is an approximate line height, so if the text uses things like fancy
   * Unicode or attribute that influence the height, the text might not fit.
   *
   * If you set this property to 0, the inscription will not request any height at all
   * and its height will be determined entirely by its surroundings.
   *
   * @newin{4,8}
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_lines() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;

  /** The number of characters that should ideally fit into the inscription.
   *
   * This influences the requested width, not the width actually given to the widget.
   * The widget might turn out larger as well as smaller.
   *
   * If this property is set to a value smaller than property_min_chars(),
   * that value will be used. In particular, for the default value of 0, this will always
   * be the case.
   *
   * @newin{4,8}
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_nat_chars() -> Glib::PropertyProxy< unsigned int > ;

/** The number of characters that should ideally fit into the inscription.
   *
   * This influences the requested width, not the width actually given to the widget.
   * The widget might turn out larger as well as smaller.
   *
   * If this property is set to a value smaller than property_min_chars(),
   * that value will be used. In particular, for the default value of 0, this will always
   * be the case.
   *
   * @newin{4,8}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_nat_chars() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;

  /** The number of lines that should ideally fit into the inscription.
   *
   * This influences the requested height, not the height actually given to the widget.
   * The widget might turn out larger as well as smaller.
   *
   * If this property is set to a value smaller than property_min_lines(),
   * that value will be used. In particular, for the default value of 0, this will always
   * be the case.
   *
   * @newin{4,8}
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_nat_lines() -> Glib::PropertyProxy< unsigned int > ;

/** The number of lines that should ideally fit into the inscription.
   *
   * This influences the requested height, not the height actually given to the widget.
   * The widget might turn out larger as well as smaller.
   *
   * If this property is set to a value smaller than property_min_lines(),
   * that value will be used. In particular, for the default value of 0, this will always
   * be the case.
   *
   * @newin{4,8}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_nat_lines() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;

  /** The displayed text.
   *
   * @newin{4,8}
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The displayed text.
   *
   * @newin{4,8}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The overflow method to use for the text.
   *
   * @newin{4,8}
   *
   * Default value: Gtk::Inscription::Overflow::CLIP
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_overflow() -> Glib::PropertyProxy< Inscription::Overflow > ;

/** The overflow method to use for the text.
   *
   * @newin{4,8}
   *
   * Default value: Gtk::Inscription::Overflow::CLIP
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_overflow() const -> Glib::PropertyProxy_ReadOnly< Inscription::Overflow >;

  /** Controls how the line wrapping is done.
   *
   * Note that unlike `Gtk::Label`, the default here is Pango::WrapMode::WORD_CHAR.
   *
   * @newin{4,8}
   *
   * Default value: Pango::WrapMode::WORD_CHAR
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() -> Glib::PropertyProxy< Pango::WrapMode > ;

/** Controls how the line wrapping is done.
   *
   * Note that unlike `Gtk::Label`, the default here is Pango::WrapMode::WORD_CHAR.
   *
   * @newin{4,8}
   *
   * Default value: Pango::WrapMode::WORD_CHAR
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() const -> Glib::PropertyProxy_ReadOnly< Pango::WrapMode >;

  /** The horizontal alignment of the text inside the allocated size.
   *
   * Compare this to Gtk::Widget::property_halign(), which determines how the
   * inscription's size allocation is positioned in the available space.
   *
   * @newin{4,8}
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() -> Glib::PropertyProxy< float > ;

/** The horizontal alignment of the text inside the allocated size.
   *
   * Compare this to Gtk::Widget::property_halign(), which determines how the
   * inscription's size allocation is positioned in the available space.
   *
   * @newin{4,8}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() const -> Glib::PropertyProxy_ReadOnly< float >;

  /** The vertical alignment of the text inside the allocated size.
   *
   * Compare this to Gtk::Widget::property_valign(), which determines how the
   * inscription's size allocation is positioned in the available space.
   *
   * @newin{4,8}
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_yalign() -> Glib::PropertyProxy< float > ;

/** The vertical alignment of the text inside the allocated size.
   *
   * Compare this to Gtk::Widget::property_valign(), which determines how the
   * inscription's size allocation is positioned in the available space.
   *
   * @newin{4,8}
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_yalign() const -> Glib::PropertyProxy_ReadOnly< float >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Inscription::Overflow> : public Glib::Value_Enum<Gtk::Inscription::Overflow>
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
   * @relates Gtk::Inscription
   */
  GTKMM_API
  auto wrap(GtkInscription* object, bool take_copy = false) -> Gtk::Inscription*;
} //namespace Glib


#endif /* _GTKMM_INSCRIPTION_H */

