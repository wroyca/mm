
#ifndef _GTKMM_COMBOBOX_H
#define _GTKMM_COMBOBOX_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2003 The gtkmm Development Team
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
#include <libmm-gtk/celllayout.hxx>
#include <libmm-gtk/celleditable.hxx>
#include <libmm-gtk/entry.hxx>
#include <libmm-gtk/treemodel.hxx>
#include <libmm-gtk/treeview.hxx>
#include <libmm-gtk/enums.hxx> //For SensitivityType.


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkComboBox = struct _GtkComboBox;
using GtkComboBoxClass = struct _GtkComboBoxClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ComboBox_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GTKMM_API Device;
}

namespace Gtk
{

/** A widget used to choose from a list of items.
 *
 * A ComboBox is a widget that allows the user to choose from a list of valid choices. The ComboBox displays the
 * selected choice. When activated, the ComboBox displays a popup which allows the user to make a new choice. The
 * style in which the selected value is displayed, and the style of the popup is determined by the current theme.
 * It may be similar to a Windows-style combo box.
 *
 * The ComboBox uses the model-view pattern; the list of valid choices is specified in the form of a tree model,
 * and the display of the choices can be adapted to the data in the model by using cell renderers, as you would in
 * a tree view. This is possible since ComboBox implements the CellLayout interface. The tree model holding the
 * valid choices is not restricted to a flat list, it can be a real tree, and the popup will reflect the tree
 * structure.
 *
 * To allow the user to enter values not in the model, the 'has-entry'
 * property allows the ComboBox to contain a Gtk::Entry. This entry
 * can be accessed by calling get_entry(), or you can just call get_entry_text()
 * to get the text from the Entry.
 *
 * For a simple list of textual choices, the model-view API of ComboBox
 * can be a bit overwhelming. In this case, ComboBoxText offers a
 * simple alternative. Both ComboBox and ComboBoxText can contain
 * an entry.
 *
 * The ComboBox widget looks like this:
 * @image html combobox1.png
 *
 * @ingroup Widgets
 */

class GTKMM_API ComboBox
: public Widget,
  public CellLayout,
  public CellEditable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ComboBox CppObjectType;
  typedef ComboBox_Class CppClassType;
  typedef GtkComboBox BaseObjectType;
  typedef GtkComboBoxClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ComboBox(ComboBox&& src) noexcept;
  auto operator=(ComboBox&& src) noexcept -> ComboBox&;

  // noncopyable
  ComboBox(const ComboBox&) = delete;
  auto operator=(const ComboBox&) -> ComboBox& = delete;

  ~ComboBox() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ComboBox_Class;
  static CppClassType combobox_class_;

protected:
  explicit ComboBox(const Glib::ConstructParams& construct_params);
  explicit ComboBox(GtkComboBox* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkComboBox*       { return reinterpret_cast<GtkComboBox*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkComboBox* { return reinterpret_cast<GtkComboBox*>(gobject_); }

private:


public:

  /** Creates a new empty ComboBox, optionally with an entry.
   * @param has_entry If this is true then this will have an Entry widget.
   */
  explicit ComboBox(bool has_entry = false);


  /** Creates a new ComboBox with the model initialized to @a model, optionally with an entry.
   * @param model The model containing data to display in the ComboBox.
   * @param has_entry If this is true then this will have an Entry widget.
   */
  explicit ComboBox(const Glib::RefPtr<TreeModel>& model, bool has_entry = false);


/* get/set active item */

  /** Returns the index of the currently active item.
   *
   * If the model is a non-flat treemodel, and the active item is not
   * an immediate child of the root of the tree, this function returns
   * `gtk_tree_path_get_indices (path)[0]`, where `path` is the
   * Gtk::TreePath of the active item.
   *
   * @return An integer which is the index of the currently active item,
   * or -1 if there’s no active item.
   */
  auto get_active_row_number() const -> int;

  /** Gets an iterator that points to the current active item, if it exists.
   * @result The iterator.
   */
  auto get_active() -> TreeModel::iterator;

  /** Gets an iterator that points to the current active item, if it exists.
   * @result The iterator.
   */
  auto get_active() const -> TreeModel::const_iterator;


  /** Sets the active item of @a combo_box to be the item at @a index.
   *
   * @param index An index in the model passed during construction,
   * or -1 to have no active item.
   */
  void set_active(int index);

  /** Sets the current active item to be the one referenced by @a iter.
   *
   * If @a iter is <tt>nullptr</tt>, the active item is unset.
   *
   * @param iter The `Gtk::TreeIter`.
   */
  void set_active(const TreeModel::const_iterator& iter);

  // See https://bugzilla.gnome.org/show_bug.cgi?id=612396#c30
  /** Get the text in the entry, if there is an entry.
   *
   * @newin{2,24}
   */
  auto get_entry_text() const -> Glib::ustring;

  /** Causes no item to be active. See also set_active().
   */
  void unset_active();


  /** Returns the `Gtk::TreeModel` of @a combo_box.
   *
   * @return A `Gtk::TreeModel` which was passed
   * during construction.
   */
  auto get_model() -> Glib::RefPtr<TreeModel>;

  /** Returns the `Gtk::TreeModel` of @a combo_box.
   *
   * @return A `Gtk::TreeModel` which was passed
   * during construction.
   */
  auto get_model() const -> Glib::RefPtr<const TreeModel>;

  /** Sets the model used by @a combo_box to be @a model. Will unset a previously set
   * model (if applicable). Use unset_model() to unset the old model.
   *
   * Note that this function does not clear the cell renderers, you have to
   * call Gtk::CellLayout::clear() yourself if you need to set up different
   * cell renderers for the new model.
   *
   * @newin{2,4}
   *
   * @param model A `Gtk::TreeModel`.
   */
  void set_model(const Glib::RefPtr<TreeModel>& model);

  /** Remove the model from the ComboBox.
   *
   * @see set_model().
   *
   * @newin{2,16}
   */
  void unset_model();

  typedef TreeView::SlotRowSeparator SlotRowSeparator;

  /** Sets the row separator function, which is used to determine whether a row should be drawn as a separator.
   * See also unset_row_separator_func().
   *
   * @param slot The callback.
   */
  void set_row_separator_func(const SlotRowSeparator& slot);

  /** Causes no separators to be drawn.
   */
  void unset_row_separator_func();


  /** Sets whether the dropdown button of the combo box should update
   * its sensitivity depending on the model contents.
   *
   * @param sensitivity Specify the sensitivity of the dropdown button.
   */
  void set_button_sensitivity(SensitivityType sensitivity);

  /** Returns whether the combo box sets the dropdown button
   * sensitive or not when there are no items in the model.
   *
   * @return Gtk::SensitivityType::ON if the dropdown button
   * is sensitive when the model is empty, Gtk::SensitivityType::OFF
   * if the button is always insensitive or Gtk::SensitivityType::AUTO
   * if it is only sensitive as long as the model has one item to
   * be selected.
   */
  auto get_button_sensitivity() const -> SensitivityType;


  /** Returns whether the combo box has an entry.
   *
   * @return Whether there is an entry in @a combo_box.
   */
  auto get_has_entry() const -> bool;


  /** Sets the model column which @a combo_box should use to get strings
   * from to be @a text_column.
   *
   * For this column no separate
   * Gtk::CellRenderer is needed.
   *
   * The column @a text_column in the model of @a combo_box must be of
   * type G_TYPE_STRING.
   *
   * This is only relevant if @a combo_box has been created with
   * property_has_entry() as <tt>true</tt>.
   *
   * @param text_column A column in @a model to get the strings from for
   * the internal entry.
   */
  void set_entry_text_column(const TreeModelColumnBase& text_column) const;

  /** Sets the model column which @a combo_box should use to get strings
   * from to be @a text_column.
   *
   * For this column no separate
   * Gtk::CellRenderer is needed.
   *
   * The column @a text_column in the model of @a combo_box must be of
   * type G_TYPE_STRING.
   *
   * This is only relevant if @a combo_box has been created with
   * property_has_entry() as <tt>true</tt>.
   *
   * @param text_column A column in @a model to get the strings from for
   * the internal entry.
   */
  void set_entry_text_column(int text_column);


  /** Returns the column which @a combo_box is using to get the strings
   * from to display in the internal entry.
   *
   * @return A column in the data source model of @a combo_box.
   */
  auto get_entry_text_column() const -> int;


  /** Specifies whether the popup’s width should be a fixed width.
   *
   * If @a fixed is <tt>true</tt>, the popup's width is set to match the
   * allocated width of the combo box.
   *
   * @param fixed Whether to use a fixed popup width.
   */
  void set_popup_fixed_width(bool fixed =  true);

  /** Gets whether the popup uses a fixed width.
   *
   * @return <tt>true</tt> if the popup uses a fixed width.
   */
  auto get_popup_fixed_width() const -> bool;


  /** Pops up the menu or dropdown list of @a combo_box.
   *
   * This function is mostly intended for use by accessibility technologies;
   * applications should have little use for it.
   *
   * Before calling this, @a combo_box must be mapped, or nothing will happen.
   */
  void popup();

  /** Pops up the menu of @a combo_box.
   *
   * Note that currently this does not do anything with the device, as it was
   * previously only used for list-mode combo boxes, and those were removed
   * in GTK 4. However, it is retained in case similar functionality is added
   * back later.
   *
   * @param device A `Gdk::Device`.
   */
  void popup(const Glib::RefPtr<Gdk::Device>& device);

  /** Hides the menu or dropdown list of @a combo_box.
   *
   * This function is mostly intended for use by accessibility technologies;
   * applications should have little use for it.
   */
  void popdown();


  /** Returns the column which @a combo_box is using to get string IDs
   * for values from.
   *
   * @return A column in the data source model of @a combo_box.
   */
  auto get_id_column() const -> int;

  /** Sets the model column which @a combo_box should use to get string IDs
   * for values from.
   *
   * The column @a id_column in the model of @a combo_box must be of type
   * G_TYPE_STRING.
   *
   * @param id_column A column in @a model to get string IDs for values from.
   */
  void set_id_column(int id_column);

  /** Returns the ID of the active row of @a combo_box.
   *
   * This value is taken from the active row and the column specified
   * by the property_id_column() property of @a combo_box
   * (see set_id_column()).
   *
   * The returned value is an interned string which means that you can
   * compare the pointer by value to other interned strings and that you
   * must not free it.
   *
   * If the property_id_column() property of @a combo_box is
   * not set, or if no row is active, or if the active row has a <tt>nullptr</tt>
   * ID value, then <tt>nullptr</tt> is returned.
   *
   * @return The ID of the active row.
   */
  auto get_active_id() const -> Glib::ustring;


  /** Changes the active row of the combo box to the one that has an ID equal to
   * @a active_id.
   *
   * If property_id_column() is unset or if no row has the given ID then the function
   * does nothing and returns false.
   *
   * @param active_id The ID of the row that should be set to active.
   * @returns true if a row with a matching ID was found.
   *
   * @newin{3,6}
   */
  auto set_active_id(const Glib::ustring& active_id) -> bool;


  /** Sets the child widget of @a combo_box.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a combo_box.
   *
   * @return The child widget of @a combo_box.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a combo_box.
   *
   * @return The child widget of @a combo_box.
   */
  auto get_child() const -> const Widget*;

  /** @see get_child().
   * @newin{2,24}
   */
  auto get_entry() -> Entry*;

  /** @see get_child().
   * @newin{2,24}
   */
  auto get_entry() const -> const Entry*;

  /** The model from which the combo box takes its values.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<TreeModel> > ;

/** The model from which the combo box takes its values.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >;

  /** The item which is currently active.
   *
   * If the model is a non-flat treemodel, and the active item is not an
   * immediate child of the root of the tree, this property has the value
   * `gtk_tree_path_get_indices (path)[0]`, where `path` is the
   * Gtk::TreePath of the active item.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() -> Glib::PropertyProxy< int > ;

/** The item which is currently active.
   *
   * If the model is a non-flat treemodel, and the active item is not an
   * immediate child of the root of the tree, this property has the value
   * `gtk_tree_path_get_indices (path)[0]`, where `path` is the
   * Gtk::TreePath of the active item.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The `has-frame` property controls whether a frame is drawn around the entry.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_frame() -> Glib::PropertyProxy< bool > ;

/** The `has-frame` property controls whether a frame is drawn around the entry.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_frame() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the combo boxes dropdown is popped up.
   *
   * Note that this property is mainly useful, because
   * it allows you to connect to notify::popup-shown.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_popup_shown() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether the dropdown button is sensitive when
   * the model is empty.
   *
   * Default value: Gtk::SensitivityType::AUTO
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_button_sensitivity() -> Glib::PropertyProxy< SensitivityType > ;

/** Whether the dropdown button is sensitive when
   * the model is empty.
   *
   * Default value: Gtk::SensitivityType::AUTO
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_button_sensitivity() const -> Glib::PropertyProxy_ReadOnly< SensitivityType >;

  /** Whether the popup's width should be a fixed width matching the
   * allocated width of the combo box.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_popup_fixed_width() -> Glib::PropertyProxy< bool > ;

/** Whether the popup's width should be a fixed width matching the
   * allocated width of the combo box.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_popup_fixed_width() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the combo box has an entry.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_entry() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The model column to associate with strings from the entry.
   *
   * This is property only relevant if the combo was created with
   * property_has_entry() is <tt>true</tt>.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_entry_text_column() -> Glib::PropertyProxy< int > ;

/** The model column to associate with strings from the entry.
   *
   * This is property only relevant if the combo was created with
   * property_has_entry() is <tt>true</tt>.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_entry_text_column() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The model column that provides string IDs for the values
   * in the model, if != -1.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_id_column() -> Glib::PropertyProxy< int > ;

/** The model column that provides string IDs for the values
   * in the model, if != -1.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_id_column() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The value of the ID column of the active row.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active_id() -> Glib::PropertyProxy< Glib::ustring > ;

/** The value of the ID column of the active row.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the active item is changed.
   *
   * The can be due to the user selecting a different item from the list,
   * or due to a call to Gtk::ComboBox::set_active_iter(). It will
   * also be emitted while typing into the entry of a combo box with an entry.
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>Glib::ustring on_my_%format_entry_text(const TreeModel::Path& path)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to allow changing how the text in a combo box's entry is displayed.
   *
   * See property_has_entry().
   *
   * Connect a signal handler which returns an allocated string representing
   *  @a path. That string will then be used to set the text in the combo box's
   * entry. The default signal handler uses the text from the
   * property_entry_text_column() model column.
   *
   * Here's an example signal handler which fetches data from the model and
   * displays it in the entry.
   *
   * [C example ellipted]
   *
   * @param path The Gtk::TreePath string from the combo box's current model
   * to format text for.
   * @return A newly allocated string representing @a path
   * for the current `Gtk::ComboBox` model.
   */

  auto signal_format_entry_text() -> Glib::SignalProxy<Glib::ustring(const TreeModel::Path&)>;


  //Action signal:

  //Key-binding signals:


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed();
  /// This is a default handler for the signal signal_format_entry_text().
  virtual auto on_format_entry_text(const TreeModel::Path& path) -> Glib::ustring;


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
   * @relates Gtk::ComboBox
   */
  GTKMM_API
  auto wrap(GtkComboBox* object, bool take_copy = false) -> Gtk::ComboBox*;
} //namespace Glib


#endif /* _GTKMM_COMBOBOX_H */

