
#ifndef _GTKMM_CELLRENDERERCOMBO_H
#define _GTKMM_CELLRENDERERCOMBO_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2004 The gtkmm Development Team
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

#include <libmm-gtk/cellrenderertext.hxx>
#include <libmm-gtk/treemodel.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererCombo = struct _GtkCellRendererCombo;
using GtkCellRendererComboClass = struct _GtkCellRendererComboClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellRendererCombo_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/**  Renders a combobox in a cell.
 * CellRendererCombo renders text in a cell like CellRendererText, from which it is derived. But while
 * CellRendererText offers a simple entry to edit the text, CellRendererCombo offers a ComboBox or
 * ComboBoxEntry widget to edit the text. The values to display in the combo box are taken from the
 * tree model specified in the model property.
 *
 * The combo cell renderer takes care of adding a text cell renderer to the combo box and sets it to
 * display the column specified by its text_column property. Further cell renderers can be added in a
 * handler for the editing_started signal.
 *
 * @ingroup TreeView
 */

class GTKMM_API CellRendererCombo : public CellRendererText
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellRendererCombo CppObjectType;
  typedef CellRendererCombo_Class CppClassType;
  typedef GtkCellRendererCombo BaseObjectType;
  typedef GtkCellRendererComboClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CellRendererCombo(CellRendererCombo&& src) noexcept;
  auto operator=(CellRendererCombo&& src) noexcept -> CellRendererCombo&;

  // noncopyable
  CellRendererCombo(const CellRendererCombo&) = delete;
  auto operator=(const CellRendererCombo&) -> CellRendererCombo& = delete;

  ~CellRendererCombo() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class CellRendererCombo_Class;
  static CppClassType cellrenderercombo_class_;

protected:
  explicit CellRendererCombo(const Glib::ConstructParams& construct_params);
  explicit CellRendererCombo(GtkCellRendererCombo* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellRendererCombo*       { return reinterpret_cast<GtkCellRendererCombo*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellRendererCombo* { return reinterpret_cast<GtkCellRendererCombo*>(gobject_); }

private:

public:

  CellRendererCombo();


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed(const Glib::ustring& path, const TreeModel::iterator& iter)</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted each time after the user selected an item in
   * the combo box, either by using the mouse or the arrow keys.  Contrary
   * to GtkComboBox, GtkCellRendererCombo::changed is not emitted for
   * changes made to a selected item in the entry.  The argument @a iter
   * corresponds to the newly selected item in the combo box and it is relative
   * to the GtkTreeModel set via the model property on GtkCellRendererCombo.
   *
   * Note that as soon as you change the model displayed in the tree view,
   * the tree view will immediately cease the editing operating.  This
   * means that you most probably want to refrain from changing the model
   * until the combo cell renderer emits the edited or editing_canceled signal.
   *
   * @param path A string of the path identifying the edited cell
   * (relative to the tree view model).
   * @param iter The new iter selected in the combo box
   * (relative to the combo box model).
   */

  auto signal_changed() -> Glib::SignalProxy<void(const Glib::ustring&, const TreeModel::iterator&)>;


  /** Holds a tree model containing the possible values for the combo box.
   * Use the text_column property to specify the column holding the values.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<Gtk::TreeModel> > ;

/** Holds a tree model containing the possible values for the combo box.
   * Use the text_column property to specify the column holding the values.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gtk::TreeModel> >;

  /** Specifies the model column which holds the possible values for the
   * combo box.
   *
   * Note that this refers to the model specified in the model property,
   * not the model backing the tree view to which
   * this cell renderer is attached.
   *
   * `Gtk::CellRendererCombo` automatically adds a text cell renderer for
   * this column to its combo box.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_column() -> Glib::PropertyProxy< int > ;

/** Specifies the model column which holds the possible values for the
   * combo box.
   *
   * Note that this refers to the model specified in the model property,
   * not the model backing the tree view to which
   * this cell renderer is attached.
   *
   * `Gtk::CellRendererCombo` automatically adds a text cell renderer for
   * this column to its combo box.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_column() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** If <tt>true</tt>, the cell renderer will include an entry and allow to enter
   * values other than the ones in the popup list.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_entry() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, the cell renderer will include an entry and allow to enter
   * values other than the ones in the popup list.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_entry() const -> Glib::PropertyProxy_ReadOnly< bool >;


  auto _property_renderable() -> Glib::PropertyProxy_Base override;


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
   * @relates Gtk::CellRendererCombo
   */
  GTKMM_API
  auto wrap(GtkCellRendererCombo* object, bool take_copy = false) -> Gtk::CellRendererCombo*;
} //namespace Glib


#endif /* _GTKMM_CELLRENDERERCOMBO_H */
