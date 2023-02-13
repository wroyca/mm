
#ifndef _GTKMM_ENTRYBUFFER_H
#define _GTKMM_ENTRYBUFFER_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright(C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or(at your option) any later version.
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

// This is for including the config header before any code (such as
// the #ifndef GTKMM_DISABLE_DEPRECATED in deprecated classes) is generated:


#include <libmm-glib/object.hpp>
#include <libmm-gtk/mm-gtkconfig.hpp>
#include <utility>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEntryBuffer = struct _GtkEntryBuffer;
using GtkEntryBufferClass = struct _GtkEntryBufferClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API EntryBuffer_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A Text buffer for the Entry widget.
 *
 * The EntryBuffer class contains the actual text displayed in an Entry widget.
 *
 * A single EntryBuffer object can be shared by multiple Entry
 * widgets which will then share the same text content, but not the cursor
 * position, visibility attributes, icon etc.
 *
 * EntryBuffer may be derived from. Such a derived class might allow
 * text to be stored in an alternate location, such as non-pageable memory,
 * useful in the case of important passwords. Or a derived class could
 * integrate with an application's concept of undo/redo.
 *
 * @newin{2,20}
 */

class GTKMM_API EntryBuffer : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = EntryBuffer;
  using CppClassType = EntryBuffer_Class;
  using BaseObjectType = GtkEntryBuffer;
  using BaseClassType = GtkEntryBufferClass;

  // noncopyable
  EntryBuffer(const EntryBuffer&) = delete;
  auto operator=(const EntryBuffer&) -> EntryBuffer& = delete;

private:  friend class EntryBuffer_Class;
  static CppClassType entrybuffer_class_;

protected:
  explicit EntryBuffer(const Glib::ConstructParams& construct_params);
  explicit EntryBuffer(GtkEntryBuffer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  EntryBuffer(EntryBuffer&& src) noexcept;
  auto operator=(EntryBuffer&& src) noexcept -> EntryBuffer&;

  ~EntryBuffer() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkEntryBuffer*       { return reinterpret_cast<GtkEntryBuffer*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEntryBuffer* { return reinterpret_cast<GtkEntryBuffer*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkEntryBuffer*;

private:

protected:

  /** Create a new EntryBuffer object with no text.
   */
  EntryBuffer();

  /** Create a new EntryBuffer object.
   *
   * @param text Initial buffer text.
   */
  explicit EntryBuffer(const Glib::ustring& text);

public:
  /** Create a new EntryBuffer object with no text.
   */

  static auto create() -> Glib::RefPtr<EntryBuffer>;


  /** Create a new EntryBuffer object.
   *
   * @param text Initial buffer text.
   */

  static auto create(const Glib::ustring& text) -> Glib::RefPtr<EntryBuffer>;


  /** Retrieves the length in bytes of the buffer.
   *
   * See get_length().
   *
   * @return The byte length of the buffer.
   */
  auto get_bytes() const -> gsize;

  /** Retrieves the length in characters of the buffer.
   *
   * @return The number of characters in the buffer.
   */
  auto get_length() const -> guint;

  /** Retrieves the contents of the buffer.
   *
   * The memory pointer returned by this call will not change
   * unless this object emits a signal, or is finalized.
   *
   * @return A pointer to the contents of the widget as a
   * string. This string points to internally allocated storage
   * in the buffer and must not be freed, modified or stored.
   */
  auto get_text() const -> Glib::ustring;

  /** Sets the text in the buffer.
   * This is roughly equivalent to calling delete_text() and insert_text().
   *
   * @param text The text to set in the buffer.
   */
  void set_text(const Glib::ustring& text);


  /** Sets the maximum allowed length of the contents of the buffer.
   *
   * If the current contents are longer than the given length, then
   * they will be truncated to fit.
   *
   * @param max_length The maximum length of the entry buffer, or 0 for no maximum.
   * (other than the maximum length of entries.) The value passed in will
   * be clamped to the range 0-65536.
   */
  void set_max_length(int max_length);

  /** Retrieves the maximum allowed length of the text in @a buffer.
   *
   * @return The maximum allowed number of characters
   * in `Gtk::EntryBuffer`, or 0 if there is no maximum.
   */
  auto get_max_length() const -> int;

  /** Inserts @a text into the contents of the buffer, at position @a position.
   *
   * @param position The position at which to insert text.
   * @param text The text to insert into the buffer.
   * @result The number of characters actually inserted.
   */
  auto insert_text(guint position, const Glib::ustring& text) -> guint;


  /** Deletes a sequence of characters from the buffer.
   *
   *  @a n_chars characters are deleted starting at @a position.
   * If @a n_chars is negative, then all characters until the
   * end of the text are deleted.
   *
   * If @a position or @a n_chars are out of bounds, then they
   * are coerced to sane values.
   *
   * Note that the positions are specified in characters,
   * not bytes.
   *
   * @param position Position at which to delete text.
   * @param n_chars Number of characters to delete.
   * @return The number of characters deleted.
   */
  auto delete_text(guint position, int n_chars) -> guint;

  /** Used when deriving from EntryBuffer.
   * @param position Position at which text was inserted.
   * @param text Text that was inserted.
   */
  void emit_inserted_text(guint position, const Glib::ustring& text);


  /** Used when subclassing `Gtk::EntryBuffer`.
   *
   * @param position Position at which text was deleted.
   * @param n_chars Number of characters deleted.
   */
  void emit_deleted_text(guint position, guint n_chars);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%inserted_text(guint position, const char* chars, guint n_chars)</tt>
   *
   * Flags: Run First
   *
   * This signal is emitted after text is inserted into the buffer.
   *
   * @param position The position the text was inserted at.
   * @param chars The text that was inserted.
   * @param n_chars The number of characters that were inserted.
   */

  auto signal_inserted_text() -> Glib::SignalProxy<void(guint, const char*, guint)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%deleted_text(guint position, guint n_chars)</tt>
   *
   * Flags: Run Last
   *
   * The text is altered in the default handler for this signal.
   *
   * If you want access to the text after the text has been modified,
   * use connect(..., true).
   *
   * @param position The position the text was deleted at.
   * @param n_chars The number of characters that were deleted.
   */

  auto signal_deleted_text() -> Glib::SignalProxy<void(guint, guint)>;


  /** The contents of the buffer.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The contents of the buffer.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The length (in characters) of the text in buffer.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_length() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** The maximum length (in characters) of the text in the buffer.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_length() -> Glib::PropertyProxy< int > ;

/** The maximum length (in characters) of the text in the buffer.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_length() const -> Glib::PropertyProxy_ReadOnly< int >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_inserted_text().
  virtual void on_inserted_text(guint position, const char* chars, guint n_chars);
  /// This is a default handler for the signal signal_deleted_text().
  virtual void on_deleted_text(guint position, guint n_chars);


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
   * @relates Gtk::EntryBuffer
   */
  GTKMM_API
  auto wrap(GtkEntryBuffer* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EntryBuffer>;
}


#endif /* _GTKMM_ENTRYBUFFER_H */

