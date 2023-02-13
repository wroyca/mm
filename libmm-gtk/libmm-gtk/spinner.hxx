
#ifndef _GTKMM_SPINNER_H
#define _GTKMM_SPINNER_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2009 The gtkmm Development Team
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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSpinner = struct _GtkSpinner;
using GtkSpinnerClass = struct _GtkSpinnerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Spinner_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** A widget that displays a spinner animation.
 *
 * @newin{2,20}
 * @ingroup Widgets
 */

class GTKMM_API Spinner : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Spinner CppObjectType;
  typedef Spinner_Class CppClassType;
  typedef GtkSpinner BaseObjectType;
  typedef GtkSpinnerClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Spinner(Spinner&& src) noexcept;
  auto operator=(Spinner&& src) noexcept -> Spinner&;

  // noncopyable
  Spinner(const Spinner&) = delete;
  auto operator=(const Spinner&) -> Spinner& = delete;

  ~Spinner() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Spinner_Class;
  static CppClassType spinner_class_;

protected:
  explicit Spinner(const Glib::ConstructParams& construct_params);
  explicit Spinner(GtkSpinner* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkSpinner*       { return reinterpret_cast<GtkSpinner*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSpinner* { return reinterpret_cast<GtkSpinner*>(gobject_); }

private:

public:

  Spinner();


  /** Starts the animation of the spinner.
   */
  void start();

  /** Stops the animation of the spinner.
   */
  void stop();

  /** Sets the activity of the spinner.
   *
   * @param spinning Whether the spinner should be spinning.
   */
  void set_spinning(bool spinning =  true);

  /** Returns whether the spinner is spinning.
   *
   * @return <tt>true</tt> if the spinner is active.
   */
  auto get_spinning() const -> bool;

  /** Whether the spinner is spinning
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spinning() -> Glib::PropertyProxy< bool > ;

/** Whether the spinner is spinning
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spinning() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gtk::Spinner
   */
  GTKMM_API
  auto wrap(GtkSpinner* object, bool take_copy = false) -> Gtk::Spinner*;
} //namespace Glib


#endif /* _GTKMM_SPINNER_H */

