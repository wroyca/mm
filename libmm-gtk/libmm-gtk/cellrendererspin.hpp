
#ifndef _GTKMM_CELLRENDERERSPIN_H
#define _GTKMM_CELLRENDERERSPIN_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2006 The gtkmm Development Team
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

#include <mm/gtk/cellrenderertext.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererSpin = struct _GtkCellRendererSpin;
using GtkCellRendererSpinClass = struct _GtkCellRendererSpinClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellRendererSpin_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Adjustment;

/**  Renders a spin button in a cell.
 *
 * Gtk::CellRendererSpin renders text in a cell like Gtk::CellRendererText,
 * from which it is derived. But while Gtk::CellRendererText offers a simple
 * entry to edit the text, Gtk::CellRendererSpin offers a Gtk::SpinButton widget.
 * Of course, that means that the text must be parseable as a floating point
 * number.
 *
 * The range of the spinbutton is taken from the adjustment property of the
 * cell renderer, which can be set explicitly or mapped to a column in
 * the tree model, like all properties of cell renders. Gtk::CellRendererSpin
 * also has properties for the climb rate and the number of digits to display.
 * Other Gtk::SpinButton properties can be set in a handler for the start-editing
 * signal.
 *
 * @ingroup TreeView
 * @newin{2,12}
 */

class GTKMM_API CellRendererSpin : public CellRendererText
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellRendererSpin CppObjectType;
  typedef CellRendererSpin_Class CppClassType;
  typedef GtkCellRendererSpin BaseObjectType;
  typedef GtkCellRendererSpinClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CellRendererSpin(CellRendererSpin&& src) noexcept;
  auto operator=(CellRendererSpin&& src) noexcept -> CellRendererSpin&;

  // noncopyable
  CellRendererSpin(const CellRendererSpin&) = delete;
  auto operator=(const CellRendererSpin&) -> CellRendererSpin& = delete;

  ~CellRendererSpin() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class CellRendererSpin_Class;
  static CppClassType cellrendererspin_class_;

protected:
  explicit CellRendererSpin(const Glib::ConstructParams& construct_params);
  explicit CellRendererSpin(GtkCellRendererSpin* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellRendererSpin*       { return reinterpret_cast<GtkCellRendererSpin*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellRendererSpin* { return reinterpret_cast<GtkCellRendererSpin*>(gobject_); }

private:

public:

  CellRendererSpin();

  /** The adjustment that holds the value of the spinbutton.
   * This must be non-<tt>nullptr</tt> for the cell renderer to be editable.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_adjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> > ;

/** The adjustment that holds the value of the spinbutton.
   * This must be non-<tt>nullptr</tt> for the cell renderer to be editable.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_adjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >;

  /** The acceleration rate when you hold down a button.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_climb_rate() -> Glib::PropertyProxy< double > ;

/** The acceleration rate when you hold down a button.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_climb_rate() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The number of decimal places to display.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_digits() -> Glib::PropertyProxy< guint > ;

/** The number of decimal places to display.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_digits() const -> Glib::PropertyProxy_ReadOnly< guint >;


  auto _property_renderable() -> Glib::PropertyProxy_Base override;


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
   * @relates Gtk::CellRendererSpin
   */
  GTKMM_API
  auto wrap(GtkCellRendererSpin* object, bool take_copy = false) -> Gtk::CellRendererSpin*;
} //namespace Glib


#endif /* _GTKMM_CELLRENDERERSPIN_H */

