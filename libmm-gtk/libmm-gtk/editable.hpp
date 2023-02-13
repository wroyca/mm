
#ifndef _GTKMM_EDITABLE_H
#define _GTKMM_EDITABLE_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
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


#include <mm/glib/interface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkEditableInterface GtkEditableInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEditable = struct _GtkEditable;
using GtkEditableClass = struct _GtkEditableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Editable_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Base class for text-editing widgets.
 *
 * The Gtk::Editable class is a base class for widgets for editing text,
 * such as Gtk::Entry. It cannot be instantiated by itself. The editable
 * class contains functions for generically manipulating an editable widget,
 * a large number of action signals used for key bindings, and several
 * signals that an application can connect to to modify the behavior of a
 * widget.
 */

class GTKMM_API Editable : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Editable;
  using CppClassType = Editable_Class;
  using BaseObjectType = GtkEditable;
  using BaseClassType = GtkEditableInterface;

  // noncopyable
  Editable(const Editable&) = delete;
  auto operator=(const Editable&) -> Editable& = delete;

private:
  friend class Editable_Class;
  static CppClassType editable_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Editable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Editable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Editable(GtkEditable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Editable(Editable&& src) noexcept;
  auto operator=(Editable&& src) noexcept -> Editable&;

  ~Editable() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkEditable*       { return reinterpret_cast<GtkEditable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEditable* { return reinterpret_cast<GtkEditable*>(gobject_); }

private:


public:

  /** Retrieves the contents of @a editable.
   *
   * The returned string is owned by GTK and must not be modified or freed.
   *
   * @return A pointer to the contents of the editable.
   */
  auto get_text() const -> Glib::ustring;

  /** Sets the text in the editable to the given value.
   *
   * This is replacing the current contents.
   *
   * @param text The text to set.
   */
  void set_text(const Glib::ustring& text);


  /** Deletes the currently selected text of the editable.
   *
   * This call doesn’t do anything if there is no selected text.
   */
  void delete_selection();

  /** Determines if the user can edit the text in the editable widget.
   *
   * @param is_editable <tt>true</tt> if the user is allowed to edit the text
   * in the widget.
   */
  void set_editable(bool is_editable =  true);

  /** Retrieves whether @a editable is editable.
   *
   * @return <tt>true</tt> if @a editable is editable.
   */
  auto get_editable() const -> bool;


  /** Inserts @a new_text_length bytes of @a new_text into the contents of the
   * widget, at position @a position.
   *
   * Note that the position is in characters, not in bytes.
   * The function updates @a position to point after the newly
   * inserted text.
   *
   * @param new_text The text to append.
   * @param new_text_length The length of the text in bytes, or -1.
   * @param position Location of the position text will be inserted at.
   */
  void insert_text(const Glib::ustring& new_text, int new_text_length, int& position);

  /** Deletes a sequence of characters.
   *
   * The characters that are deleted are those characters at positions
   * from @a start_pos up to, but not including @a end_pos. If @a end_pos is
   * negative, then the characters deleted are those from @a start_pos to
   * the end of the text.
   *
   * Note that the positions are specified in characters, not bytes.
   *
   * @param start_pos Start position.
   * @param end_pos End position.
   */
  void delete_text(int start_pos, int end_pos);


  /** Retrieves a sequence of characters.
   *
   * The characters that are retrieved are those characters at positions
   * from @a start_pos up to, but not including @a end_pos. If @a end_pos is negative,
   * then the characters retrieved are those characters from @a start_pos to
   * the end of the text.
   *
   * Note that positions are specified in characters, not bytes.
   *
   * @param start_pos Start of text.
   * @param end_pos End of text.
   * @return A pointer to the contents of the widget as a
   * string. This string is allocated by the `Gtk::Editable` implementation
   * and should be freed by the caller.
   */
  auto get_chars(int start_pos, int end_pos) const -> Glib::ustring;


  /** Selects a region of text.
   *
   * The characters that are selected are those characters at positions
   * from @a start_pos up to, but not including @a end_pos. If @a end_pos is
   * negative, then the characters selected are those characters from
   *  @a start_pos to  the end of the text.
   *
   * Note that positions are specified in characters, not bytes.
   *
   * @param start_pos Start of region.
   * @param end_pos End of region.
   */
  void select_region(int start_pos, int end_pos);

  /** Retrieves the selection bound of the editable.
   *
   *  @a start_pos will be filled with the start of the selection and
   *  @a end_pos with end. If no text was selected both will be identical
   * and <tt>false</tt> will be returned.
   *
   * Note that positions are specified in characters, not bytes.
   *
   * @param start_pos Location to store the starting position.
   * @param end_pos Location to store the end position.
   * @return <tt>true</tt> if there is a non-empty selection, <tt>false</tt> otherwise.
   */
  auto get_selection_bounds(int& start_pos, int& end_pos) const -> bool;


  /** Sets the cursor position in the editable to the given value.
   *
   * The cursor is displayed before the character with the given (base 0)
   * index in the contents of the editable. The value must be less than
   * or equal to the number of characters in the editable. A value of -1
   * indicates that the position should be set after the last character
   * of the editable. Note that @a position is in characters, not in bytes.
   *
   * @param position The position of the cursor.
   */
  void set_position(int position);

  /** Retrieves the current position of the cursor relative
   * to the start of the content of the editable.
   *
   * Note that this position is in characters, not in bytes.
   *
   * @return The cursor position.
   */
  auto get_position() const -> int;


  /** Gets the alignment of the editable.
   *
   * @return The alignment.
   */
  auto get_alignment() const -> float;

  /** Sets the alignment for the contents of the editable.
   *
   * This controls the horizontal positioning of the contents when
   * the displayed text is shorter than the width of the editable.
   *
   * @param xalign The horizontal alignment, from 0 (left) to 1 (right).
   * Reversed for RTL layouts.
   */
  void set_alignment(float xalign);


  /** Gets the number of characters of space reserved
   * for the contents of the editable.
   *
   * @return Number of chars to request space for, or negative if unset.
   */
  auto get_width_chars() const -> int;

  /** Changes the size request of the editable to be about the
   * right size for @a n_chars characters.
   *
   * Note that it changes the size request, the size can still
   * be affected by how you pack the widget into containers.
   * If @a n_chars is -1, the size reverts to the default size.
   *
   * @param n_chars Width in chars.
   */
  void set_width_chars(int n_chars);


  /** Retrieves the desired maximum width of @a editable, in characters.
   *
   * @return The maximum width of the entry, in characters.
   */
  auto get_max_width_chars() const -> int;

  /** Sets the desired maximum width in characters of @a editable.
   *
   * @param n_chars The new desired maximum width, in characters.
   */
  void set_max_width_chars(int n_chars);


  /** Gets if undo/redo actions are enabled for @a editable
   *
   * @return <tt>true</tt> if undo is enabled.
   */
  auto get_enable_undo() const -> bool;

  /** If enabled, changes to @a editable will be saved for undo/redo
   * actions.
   *
   * This results in an additional copy of text changes and are not
   * stored in secure memory. As such, undo is forcefully disabled
   * when Gtk::Text::property_visibility() is set to <tt>false</tt>.
   *
   * @param enable_undo If undo/redo should be enabled.
   */
  void set_enable_undo(bool enable_undo =  true);

  // Don't wrap API for implementations. Should it be wrapped?


  auto signal_insert_text() -> Glib::SignalProxy<void(const Glib::ustring&, int*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%delete_text(int start_pos, int end_pos)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when text is deleted from the widget by the user.
   *
   * The default handler for this signal will normally be responsible for
   * deleting the text, so by connecting to this signal and then stopping
   * the signal with Glib::signal_stop_emission(), it is possible to modify the
   * range of deleted text, or prevent it from being deleted entirely.
   *
   * The @a start_pos and @a end_pos parameters are interpreted as for
   * Gtk::Editable::delete_text().
   *
   * @param start_pos The starting position.
   * @param end_pos The end position.
   */

  auto signal_delete_text() -> Glib::SignalProxy<void(int, int)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted at the end of a single user-visible operation on the
   * contents.
   *
   * E.g., a paste operation that replaces the contents of the
   * selection will cause only one signal emission (even though it
   * is implemented by first deleting the selection, then inserting
   * the new content, and may cause multiple ::notify::text signals
   * to be emitted).
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /** The contents of the entry.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The contents of the entry.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The current position of the insertion cursor in chars.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cursor_position() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** If undo/redo should be enabled for the editable.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_undo() -> Glib::PropertyProxy< bool > ;

/** If undo/redo should be enabled for the editable.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_undo() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The position of the opposite end of the selection from the cursor in chars.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selection_bound() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Whether the entry contents can be edited.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable() -> Glib::PropertyProxy< bool > ;

/** Whether the entry contents can be edited.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Number of characters to leave space for in the entry.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width_chars() -> Glib::PropertyProxy< int > ;

/** Number of characters to leave space for in the entry.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The desired maximum width of the entry, in characters.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width_chars() -> Glib::PropertyProxy< int > ;

/** The desired maximum width of the entry, in characters.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The horizontal alignment, from 0 (left) to 1 (right).
   *
   * Reversed for RTL layouts.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() -> Glib::PropertyProxy< float > ;

/** The horizontal alignment, from 0 (left) to 1 (right).
   *
   * Reversed for RTL layouts.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() const -> Glib::PropertyProxy_ReadOnly< float >;


protected:


    virtual void delete_text_vfunc(int start_pos, int end_pos);


    virtual auto get_text_vfunc() const -> Glib::ustring;


    virtual void select_region_vfunc(int start_pos, int end_pos);

    virtual auto get_selection_bounds_vfunc(int& start_pos, int& end_pos) const -> bool;

  // Don't wrap API for implementations. Should it be wrapped?
  // _WRAP_VFUNC(Editable* get_delegate(), get_delegate)


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
virtual void insert_text_vfunc(const Glib::ustring& text, int& position);


  //Default Signal Handlers::
  /// This is a default handler for the signal signal_insert_text().
  virtual void on_insert_text(const Glib::ustring& text, int* position);
  /// This is a default handler for the signal signal_delete_text().
  virtual void on_delete_text(int start_pos, int end_pos);
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed();


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
   * @relates Gtk::Editable
   */
  GTKMM_API
  auto wrap(GtkEditable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Editable>;

} // namespace Glib


#endif /* _GTKMM_EDITABLE_H */

