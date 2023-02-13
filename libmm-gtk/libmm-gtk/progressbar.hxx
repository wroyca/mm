
#ifndef _GTKMM_PROGRESSBAR_H
#define _GTKMM_PROGRESSBAR_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/orientable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkProgressBar = struct _GtkProgressBar;
using GtkProgressBarClass = struct _GtkProgressBarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class  ProgressBar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** A widget which indicates progress visually.
 *
 * The Gtk::ProgressBar is typically used to display the progress of a long
 * running operation. It provides a visual clue that processing is underway.
 * The Gtk::ProgressBar can be used in two different modes: percentage mode
 * and activity mode.
 *
 * When an application can determine how much work needs to take place (e.g.
 * read a fixed number of bytes from a file) and can monitor its progress,
 * it can use the Gtk::ProgressBar in percentage mode and the user sees a
 * growing bar indicating the percentage of the work that has been
 * completed. In this mode, the application is required to call
 * set_fraction() periodically to update the progress bar.
 *
 * When an application has no accurate way of knowing the amount of work to
 * do, it can use the Gtk::ProgressBar in activity mode, which shows
 * activity by a block moving back and forth within the progress area. In
 * this mode, the application is required to call pulse() perodically to
 * update the progress bar.
 *
 * There is quite a bit of flexibility provided to control the appearance of
 * the Gtk::ProgressBar. Functions are provided to control the orientation of
 * the bar, optional text can be displayed along with the bar, and the step
 * size used in activity mode can be set.
 *
 * The ProgressBar widget looks like this:
 * @image html progressbar1.png
 *
 * @ingroup Widgets
 */

class GTKMM_API ProgressBar
 : public Widget,
   public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ProgressBar CppObjectType;
  typedef ProgressBar_Class CppClassType;
  typedef GtkProgressBar BaseObjectType;
  typedef GtkProgressBarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ProgressBar(ProgressBar&& src) noexcept;
  auto operator=(ProgressBar&& src) noexcept -> ProgressBar&;

  // noncopyable
  ProgressBar(const ProgressBar&) = delete;
  auto operator=(const ProgressBar&) -> ProgressBar& = delete;

  ~ProgressBar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend  class ProgressBar_Class;
  static CppClassType progressbar_class_;

protected:
  explicit ProgressBar(const Glib::ConstructParams& construct_params);
  explicit ProgressBar(GtkProgressBar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkProgressBar*       { return reinterpret_cast<GtkProgressBar*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkProgressBar* { return reinterpret_cast<GtkProgressBar*>(gobject_); }

private:


public:
  ProgressBar();


  /** Indicates that some progress has been made, but you don’t know how much.
   *
   * Causes the progress bar to enter “activity mode,” where a block
   * bounces back and forth. Each call to pulse()
   * causes the block to move by a little bit (the amount of movement
   * per pulse is determined by set_pulse_step()).
   */
  void pulse();


  /** Retrieves the text displayed superimposed on the progress bar,
   * if any.
   *
   * @return Text.
   */
  auto get_text() const -> Glib::ustring;

  /** Causes the given @a text to appear next to the progress bar.
   *
   * If @a text is <tt>nullptr</tt> and property_show_text() is <tt>true</tt>,
   * the current value of property_fraction() will be displayed
   * as a percentage.
   *
   * If @a text is non-<tt>nullptr</tt> and property_show_text() is <tt>true</tt>,
   * the text will be displayed. In this case, it will not display the progress
   * percentage. If @a text is the empty string, the progress bar will still
   * be styled and sized suitably for containing text, as long as
   * property_show_text() is <tt>true</tt>.
   *
   * @param text A UTF-8 string.
   */
  void set_text(const Glib::ustring& text);


  /** Returns the current fraction of the task that’s been completed.
   *
   * @return A fraction from 0.0 to 1.0.
   */
  auto get_fraction() const -> double;

  /** Causes the progress bar to “fill in” the given fraction
   * of the bar.
   *
   * The fraction should be between 0.0 and 1.0, inclusive.
   *
   * @param fraction Fraction of the task that’s been completed.
   */
  void set_fraction(double fraction);


  /** Retrieves the pulse step.
   *
   * See set_pulse_step().
   *
   * @return A fraction from 0.0 to 1.0.
   */
  auto get_pulse_step() const -> double;

  /** Sets the fraction of total progress bar length to move the
   * bouncing block.
   *
   * The bouncing block is moved when pulse()
   * is called.
   *
   * @param fraction Fraction between 0.0 and 1.0.
   */
  void set_pulse_step(double fraction);


  /** Sets whether the progress bar is inverted.
   *
   * Progress bars normally grow from top to bottom or left to right.
   * Inverted progress bars grow in the opposite direction.
   *
   * @param inverted <tt>true</tt> to invert the progress bar.
   */
  void set_inverted(bool inverted =  true);

  /** Returns whether the progress bar is inverted.
   *
   * @return <tt>true</tt> if the progress bar is inverted.
   */
  auto get_inverted() const -> bool;


  /** Sets the mode used to ellipsize the text.
   *
   * The text is ellipsized if there is not enough space
   * to render the entire string.
   *
   * @param mode A `Pango::EllipsizeMode`.
   */
  void set_ellipsize(Pango::EllipsizeMode mode);

  /** Returns the ellipsizing position of the progress bar.
   *
   * See set_ellipsize().
   *
   * @return `Pango::EllipsizeMode`.
   */
  auto get_ellipsize() const -> Pango::EllipsizeMode;


  /** Sets whether the progress bar will show text next to the bar.
   *
   * The shown text is either the value of the property_text()
   * property or, if that is <tt>nullptr</tt>, the property_fraction() value,
   * as a percentage.
   *
   * To make a progress bar that is styled and sized suitably for containing
   * text (even if the actual text is blank), set property_show_text()
   * to <tt>true</tt> and property_text() to the empty string (not <tt>nullptr</tt>).
   *
   * @param show_text Whether to show text.
   */
  void set_show_text(bool show_text =  true);

  /** Returns whether the `Gtk::ProgressBar` shows text.
   *
   * See set_show_text().
   *
   * @return <tt>true</tt> if text is shown in the progress bar.
   */
  auto get_show_text() const -> bool;

  /** The fraction of total work that has been completed.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fraction() -> Glib::PropertyProxy< double > ;

/** The fraction of total work that has been completed.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fraction() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The fraction of total progress to move the bounding block when pulsed.
   *
   * Default value: 0.1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pulse_step() -> Glib::PropertyProxy< double > ;

/** The fraction of total progress to move the bounding block when pulsed.
   *
   * Default value: 0.1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pulse_step() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Text to be displayed in the progress bar.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** Text to be displayed in the progress bar.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The preferred place to ellipsize the string.
   *
   * The text will be ellipsized if the progress bar does not have enough room
   * to display the entire string, specified as a `Pango::EllipsizeMode`.
   *
   * Note that setting this property to a value other than
   * Pango::EllipsizeMode::NONE has the side-effect that the progress bar requests
   * only enough space to display the ellipsis ("..."). Another means to set a
   * progress bar's width is Gtk::Widget::set_size_request().
   *
   * Default value: Pango::EllipsizeMode::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ellipsize() -> Glib::PropertyProxy< bool > ;

/** The preferred place to ellipsize the string.
   *
   * The text will be ellipsized if the progress bar does not have enough room
   * to display the entire string, specified as a `Pango::EllipsizeMode`.
   *
   * Note that setting this property to a value other than
   * Pango::EllipsizeMode::NONE has the side-effect that the progress bar requests
   * only enough space to display the ellipsis ("..."). Another means to set a
   * progress bar's width is Gtk::Widget::set_size_request().
   *
   * Default value: Pango::EllipsizeMode::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ellipsize() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Sets whether the progress bar will show a text in addition
   * to the bar itself.
   *
   * The shown text is either the value of the property_text()
   * property or, if that is <tt>nullptr</tt>, the property_fraction()
   * value, as a percentage.
   *
   * To make a progress bar that is styled and sized suitably for showing text
   * (even if the actual text is blank), set property_show_text()
   * to <tt>true</tt> and property_text() to the empty string (not <tt>nullptr</tt>).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_text() -> Glib::PropertyProxy< bool > ;

/** Sets whether the progress bar will show a text in addition
   * to the bar itself.
   *
   * The shown text is either the value of the property_text()
   * property or, if that is <tt>nullptr</tt>, the property_fraction()
   * value, as a percentage.
   *
   * To make a progress bar that is styled and sized suitably for showing text
   * (even if the actual text is blank), set property_show_text()
   * to <tt>true</tt> and property_text() to the empty string (not <tt>nullptr</tt>).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_text() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Invert the direction in which the progress bar grows.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inverted() -> Glib::PropertyProxy< bool > ;

/** Invert the direction in which the progress bar grows.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inverted() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::ProgressBar
   */

  auto wrap(GtkProgressBar* object, bool take_copy = false) -> Gtk::ProgressBar*;
} //namespace Glib


#endif /* _GTKMM_PROGRESSBAR_H */

