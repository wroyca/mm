
#ifndef _GTKMM_TEXTTAGTABLE_H
#define _GTKMM_TEXTTAGTABLE_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-glib/object.hpp>
#include <libmm-gtk/buildable.hpp>
#include <libmm-gtk/texttag.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextTagTable = struct _GtkTextTagTable;
using GtkTextTagTableClass = struct _GtkTextTagTableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TextTagTable_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class GTKMM_API TextTag;

/** Typedefed as Gtk::TextBuffer::TagTable. A Collection of @link Gtk::TextTag Gtk::TextBuffer::Tags@endlink that can be used together.
 *
 * A tag table defines a set of @link Gtk::TextTag Gtk::TextBuffer::Tags@endlink that can be used together. Each buffer has one tag
 * table associated with it; only tags from that tag table can be used with the buffer. A single tag table can be shared between
 * multiple buffers, however.
 *
 * @ingroup TextView
 */

class GTKMM_API TextTagTable : public Glib::Object, public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TextTagTable;
  using CppClassType = TextTagTable_Class;
  using BaseObjectType = GtkTextTagTable;
  using BaseClassType = GtkTextTagTableClass;

  // noncopyable
  TextTagTable(const TextTagTable&) = delete;
  auto operator=(const TextTagTable&) -> TextTagTable& = delete;

private:  friend class TextTagTable_Class;
  static CppClassType texttagtable_class_;

protected:
  explicit TextTagTable(const Glib::ConstructParams& construct_params);
  explicit TextTagTable(GtkTextTagTable* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TextTagTable(TextTagTable&& src) noexcept;
  auto operator=(TextTagTable&& src) noexcept -> TextTagTable&;

  ~TextTagTable() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTextTagTable*       { return reinterpret_cast<GtkTextTagTable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTextTagTable* { return reinterpret_cast<GtkTextTagTable*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTextTagTable*;

private:


protected:

  TextTagTable();

public:

  static auto create() -> Glib::RefPtr<TextTagTable>;


  /** Add a tag to the table.
   *
   * The tag is assigned the highest priority in the table.
   *
   *  @a tag must not be in a tag table already, and may not have
   * the same name as an already-added tag.
   *
   * @param tag A `Gtk::TextTag`.
   * @return <tt>true</tt> on success.
   */
  auto add(const Glib::RefPtr<TextTag>& tag) -> bool;

  /** Remove a tag from the table.
   *
   * If a `Gtk::TextBuffer` has @a table as its tag table, the tag is
   * removed from the buffer. The table’s reference to the tag is
   * removed, so the tag will end up destroyed if you don’t have
   * a reference to it.
   *
   * @param tag A `Gtk::TextTag`.
   */
  void remove(const Glib::RefPtr<TextTag>& tag);

  /** Look up a named tag.
   *
   * @param name Name of a tag.
   * @return The tag.
   */
  auto lookup(const Glib::ustring& name) -> Glib::RefPtr<TextTag>;

  /** Look up a named tag.
   *
   * @param name Name of a tag.
   * @return The tag.
   */
  auto lookup(const Glib::ustring& name) const -> Glib::RefPtr<const TextTag>;

  typedef sigc::slot<void(const Glib::RefPtr<TextTag>&)> SlotForEach;
  void foreach(const SlotForEach& slot);


  /** Returns the size of the table (number of tags)
   *
   * @return Number of tags in @a table.
   */
  auto get_size() const -> int;

  // no_default_handler because GtkTextTagTableClass is private.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%tag_changed(const Glib::RefPtr<TextTag>& tag, bool size_changed)</tt>
   *
   * Flags: Run Last
   *
   * Emitted every time a tag in the `Gtk::TextTagTable` changes.
   *
   * @param tag The changed tag.
   * @param size_changed Whether the change affects the `Gtk::TextView` layout.
   */

  auto signal_tag_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<TextTag>&, bool)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%tag_added(const Glib::RefPtr<TextTag>& tag)</tt>
   *
   * Flags: Run Last
   *
   * Emitted every time a new tag is added in the `Gtk::TextTagTable`.
   *
   * @param tag The added tag.
   */

  auto signal_tag_added() -> Glib::SignalProxy<void(const Glib::RefPtr<TextTag>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%tag_removed(const Glib::RefPtr<TextTag>& tag)</tt>
   *
   * Flags: Run Last
   *
   * Emitted every time a tag is removed from the `Gtk::TextTagTable`.
   *
   * The @a tag is still valid by the time the signal is emitted, but
   * it is not associated with a tag table any more.
   *
   * @param tag The removed tag.
   */

  auto signal_tag_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<TextTag>&)>;


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
   * @relates Gtk::TextTagTable
   */
  GTKMM_API
  auto wrap(GtkTextTagTable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TextTagTable>;
}


#endif /* _GTKMM_TEXTTAGTABLE_H */

