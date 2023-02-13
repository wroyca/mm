
#ifndef _GTKMM_SCALEBUTTON_H
#define _GTKMM_SCALEBUTTON_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2007 The gtkmm Development Team
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


#include <vector>

#include <libmm-gtk/button.hpp>
#include <libmm-gtk/adjustment.hpp>
#include <libmm-gtk/orientable.hpp>
#include <libmm-gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScaleButton = struct _GtkScaleButton;
using GtkScaleButtonClass = struct _GtkScaleButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ScaleButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A button which pops up a scale widget.
 *
 * This kind of widget is commonly used for volume controls in multimedia
 * applications, and there is a Gtk::VolumeButton subclass that is tailored
 * for this use case.
 *
 * @ingroup Widgets
 * @newin{2,12}
 */

class GTKMM_API ScaleButton
 : public Widget,
   public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ScaleButton CppObjectType;
  typedef ScaleButton_Class CppClassType;
  typedef GtkScaleButton BaseObjectType;
  typedef GtkScaleButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ScaleButton(ScaleButton&& src) noexcept;
  auto operator=(ScaleButton&& src) noexcept -> ScaleButton&;

  // noncopyable
  ScaleButton(const ScaleButton&) = delete;
  auto operator=(const ScaleButton&) -> ScaleButton& = delete;

  ~ScaleButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ScaleButton_Class;
  static CppClassType scalebutton_class_;

protected:
  explicit ScaleButton(const Glib::ConstructParams& construct_params);
  explicit ScaleButton(GtkScaleButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkScaleButton*       { return reinterpret_cast<GtkScaleButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkScaleButton* { return reinterpret_cast<GtkScaleButton*>(gobject_); }

private:


public:
  //We custom-implement the constructor because gtk_scale_button_new() does more than just call g_object_new().
  /** Creates a %ScaleButton, with a range between min and max, with a stepping of step.
   *
   * @param min The minimum value of the scale (usually 0).
   * @param max The maximum value of the scale (usually 100).
   * @param step The stepping of value when a scroll-wheel event, or up/down arrow event occurs (usually 2).
   * @param icons A vector of icon names.
   */
  explicit ScaleButton(double min, double max, double step, const std::vector<Glib::ustring>& icons);


  //We add the constructor without icons because the C functions allows that to be NULL.
  /** Creates a %ScaleButton, with a range between min and max, with a stepping of step.
   *
   * @param min The minimum value of the scale (usually 0).
   * @param max The maximum value of the scale (usually 100).
   * @param step The stepping of value when a scroll-wheel event, or up/down arrow event occurs (usually 2).
   *
   * @newin{3,16}
   */
  explicit ScaleButton(double min, double max, double step);


  /** Sets the icons to be used by the scale button.
   *
   * @param icons A <tt>nullptr</tt>-terminated array of icon names.
   */
  void set_icons(const std::vector<Glib::ustring>& icons);

  /** Gets the current value of the scale button.
   *
   * @return Current value of the scale button.
   */
  auto get_value() const -> double;

  /** Sets the current value of the scale.
   *
   * If the value is outside the minimum or maximum range values,
   * it will be clamped to fit inside them.
   *
   * The scale button emits the signal_value_changed()
   * signal if the value changes.
   *
   * @param value New value of the scale button.
   */
  void set_value(double value);


  /** Gets the `Gtk::Adjustment` associated with the `Gtk::ScaleButton`’s scale.
   *
   * See Gtk::Range::get_adjustment() for details.
   *
   * @return The adjustment associated with the scale.
   */
  auto get_adjustment() -> Glib::RefPtr<Adjustment>;

  /** Gets the `Gtk::Adjustment` associated with the `Gtk::ScaleButton`’s scale.
   *
   * See Gtk::Range::get_adjustment() for details.
   *
   * @return The adjustment associated with the scale.
   */
  auto get_adjustment() const -> Glib::RefPtr<const Adjustment>;


  /** Sets the `Gtk::Adjustment` to be used as a model
   * for the `Gtk::ScaleButton`’s scale.
   *
   * See Gtk::Range::set_adjustment() for details.
   *
   * @param adjustment A `Gtk::Adjustment`.
   */
  void set_adjustment(const Glib::RefPtr<Adjustment>& adjustment);


  /** Retrieves the plus button of the `GtkScaleButton.`
   *
   * @return The plus button
   * of the `Gtk::ScaleButton`.
   */
  auto get_plus_button() -> Button*;

  /** Retrieves the plus button of the `GtkScaleButton.`
   *
   * @return The plus button
   * of the `Gtk::ScaleButton`.
   */
  auto get_plus_button() const -> const Button*;


  /** Retrieves the minus button of the `Gtk::ScaleButton`.
   *
   * @return The minus button
   * of the `Gtk::ScaleButton`.
   */
  auto get_minus_button() -> Button*;

  /** Retrieves the minus button of the `Gtk::ScaleButton`.
   *
   * @return The minus button
   * of the `Gtk::ScaleButton`.
   */
  auto get_minus_button() const -> const Button*;

  //TODO: Use a more specific return type?
  // It's a Popover now, but that fact is not documented. Can change in the future? (Kjell 2017-03-08)

  /** Retrieves the popup of the `Gtk::ScaleButton`.
   *
   * @return The popup of the `Gtk::ScaleButton`.
   */
  auto get_popup() -> Gtk::Widget*;

  /** Retrieves the popup of the `Gtk::ScaleButton`.
   *
   * @return The popup of the `Gtk::ScaleButton`.
   */
  auto get_popup() const -> const Gtk::Widget*;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%value_changed(double value)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the value field has changed.
   *
   * @param value The new value.
   */

  auto signal_value_changed() -> Glib::SignalProxy<void(double)>;


  //Ignore key-binding signals:


  /** The value of the scale.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value() -> Glib::PropertyProxy< double > ;

/** The value of the scale.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The `Gtk::Adjustment` that is used as the model.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_adjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> > ;

/** The `Gtk::Adjustment` that is used as the model.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_adjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >;

  /** The names of the icons to be used by the scale button.
   *
   * The first item in the array will be used in the button
   * when the current value is the lowest value, the second
   * item for the highest value. All the subsequent icons will
   * be used for all the other values, spread evenly over the
   * range of values.
   *
   * If there's only one icon name in the @a icons array, it will
   * be used for all the values. If only two icon names are in
   * the @a icons array, the first one will be used for the bottom
   * 50% of the scale, and the second one for the top 50%.
   *
   * It is recommended to use at least 3 icons so that the
   * `Gtk::ScaleButton` reflects the current value of the scale
   * better for the users.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icons() -> Glib::PropertyProxy< std::vector<Glib::ustring> > ;

/** The names of the icons to be used by the scale button.
   *
   * The first item in the array will be used in the button
   * when the current value is the lowest value, the second
   * item for the highest value. All the subsequent icons will
   * be used for all the other values, spread evenly over the
   * range of values.
   *
   * If there's only one icon name in the @a icons array, it will
   * be used for all the values. If only two icon names are in
   * the @a icons array, the first one will be used for the bottom
   * 50% of the scale, and the second one for the top 50%.
   *
   * It is recommended to use at least 3 icons so that the
   * `Gtk::ScaleButton` reflects the current value of the scale
   * better for the users.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icons() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_value_changed().
  virtual void on_value_changed(double value);


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
   * @relates Gtk::ScaleButton
   */
  GTKMM_API
  auto wrap(GtkScaleButton* object, bool take_copy = false) -> Gtk::ScaleButton*;
} //namespace Glib


#endif /* _GTKMM_SCALEBUTTON_H */

