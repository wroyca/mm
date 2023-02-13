
#ifndef _GTKMM_COMBOBOXTEXT_H
#define _GTKMM_COMBOBOXTEXT_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2010 The gtkmm Development Team
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

#include <libmm-gtk/combobox.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkComboBoxText = struct _GtkComboBoxText;
using GtkComboBoxTextClass = struct _GtkComboBoxTextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ComboBoxText_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** This is a simple variant of ComboBox that hides the model-view complexity for simple text-only use cases.
 * You can add items to a ComboBoxText with append(), insert() or prepend() and remove items with remove_text().
 *
 * If the ComboBoxText contains an entry (via the 'has_entry' property), its contents can be retrieved using
 * get_active_text(). The entry itself can be accessed by calling ComboBox::get_entry() or ComboBox::get_entry_text().
 *
 * You should not call set_model() or attempt to pack more cells into this combo box via its CellLayout base class.
 *
 * @ingroup Widgets
 */

class GTKMM_API ComboBoxText
: public ComboBox
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ComboBoxText CppObjectType;
  typedef ComboBoxText_Class CppClassType;
  typedef GtkComboBoxText BaseObjectType;
  typedef GtkComboBoxTextClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ComboBoxText(ComboBoxText&& src) noexcept;
  auto operator=(ComboBoxText&& src) noexcept -> ComboBoxText&;

  // noncopyable
  ComboBoxText(const ComboBoxText&) = delete;
  auto operator=(const ComboBoxText&) -> ComboBoxText& = delete;

  ~ComboBoxText() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ComboBoxText_Class;
  static CppClassType comboboxtext_class_;

protected:
  explicit ComboBoxText(const Glib::ConstructParams& construct_params);
  explicit ComboBoxText(GtkComboBoxText* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkComboBoxText*       { return reinterpret_cast<GtkComboBoxText*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkComboBoxText* { return reinterpret_cast<GtkComboBoxText*>(gobject_); }

private:

public:

  /** Creates a new empty ComboBoxText, optionally with an entry.
   * @param has_entry If this is true then this will have an Entry widget.
   */
  explicit ComboBoxText(bool has_entry = false);


  /** Appends @a text to the list of strings stored in @a combo_box.
   *
   * This is the same as calling insert_text()
   * with a position of -1.
   *
   * @param text A string.
   */
  void append(const Glib::ustring& text);

  /** Appends @a text to the list of strings stored in @a combo_box.
   *
   * If @a id is non-<tt>nullptr</tt> then it is used as the ID of the row.
   *
   * This is the same as calling insert()
   * with a position of -1.
   *
   * @param id A string ID for this value.
   * @param text A string.
   */
  void append(const Glib::ustring& id, const Glib::ustring& text);

  /** Inserts @a text at @a position in the list of strings stored in @a combo_box.
   *
   * If @a position is negative then @a text is appended.
   *
   * This is the same as calling insert()
   * with a <tt>nullptr</tt> ID string.
   *
   * @param position An index to insert @a text.
   * @param text A string.
   */
  void insert(int position, const Glib::ustring& text);

  /** Inserts @a text at @a position in the list of strings stored in @a combo_box.
   *
   * If @a id is non-<tt>nullptr</tt> then it is used as the ID of the row.
   * See Gtk::ComboBox::property_id_column().
   *
   * If @a position is negative then @a text is appended.
   *
   * @param position An index to insert @a text.
   * @param id A string ID for this value.
   * @param text A string to display.
   */
  void insert(int position, const Glib::ustring& id, const Glib::ustring& text);

  /** Prepends @a text to the list of strings stored in @a combo_box.
   *
   * This is the same as calling insert_text()
   * with a position of 0.
   *
   * @param text A string.
   */
  void prepend(const Glib::ustring& text);

  /** Prepends @a text to the list of strings stored in @a combo_box.
   *
   * If @a id is non-<tt>nullptr</tt> then it is used as the ID of the row.
   *
   * This is the same as calling insert()
   * with a position of 0.
   *
   * @param id A string ID for this value.
   * @param text A string.
   */
  void prepend(const Glib::ustring& id, const Glib::ustring& text);


  /** Removes the string at @a position from @a combo_box.
   *
   * @param position Index of the item to remove.
   */
  void remove_text(int position);

  /** Returns the currently active string in @a combo_box.
   *
   * If no row is currently selected, <tt>nullptr</tt> is returned.
   * If @a combo_box contains an entry, this function will
   * return its contents (which will not necessarily
   * be an item from the list).
   *
   * @return A newly allocated
   * string containing the currently active text.
   */
  auto get_active_text() const -> Glib::ustring;


  /** Removes all the text entries from the combo box.
   */
  void remove_all();

  /** Sets the active item of the combo box.
   *
   * If @a text is one of the strings in the combo box, set that item as active,
   * else set no item as active.
   */
  void set_active_text(const Glib::ustring& text);


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
   * @relates Gtk::ComboBoxText
   */
  GTKMM_API
  auto wrap(GtkComboBoxText* object, bool take_copy = false) -> Gtk::ComboBoxText*;
} //namespace Glib


#endif /* _GTKMM_COMBOBOXTEXT_H */
