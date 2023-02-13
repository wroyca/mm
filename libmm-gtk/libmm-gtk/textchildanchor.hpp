
#ifndef _GTKMM_TEXTCHILDANCHOR_H
#define _GTKMM_TEXTCHILDANCHOR_H


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

#include <vector>

#include <libmm-gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextChildAnchor = struct _GtkTextChildAnchor;
using GtkTextChildAnchorClass = struct _GtkTextChildAnchorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TextChildAnchor_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A %TextChildAnchor is a spot in the buffer where child widgets can be "anchored"
 * (inserted inline, as if they were characters). The anchor can have multiple widgets anchored,
 * to allow for multiple views.
 *
 * Typedefed as Gtk::TextBuffer::ChildAnchor.
 * @ingroup TextView
 */

class GTKMM_API TextChildAnchor : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TextChildAnchor;
  using CppClassType = TextChildAnchor_Class;
  using BaseObjectType = GtkTextChildAnchor;
  using BaseClassType = GtkTextChildAnchorClass;

  // noncopyable
  TextChildAnchor(const TextChildAnchor&) = delete;
  auto operator=(const TextChildAnchor&) -> TextChildAnchor& = delete;

private:  friend class TextChildAnchor_Class;
  static CppClassType textchildanchor_class_;

protected:
  explicit TextChildAnchor(const Glib::ConstructParams& construct_params);
  explicit TextChildAnchor(GtkTextChildAnchor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TextChildAnchor(TextChildAnchor&& src) noexcept;
  auto operator=(TextChildAnchor&& src) noexcept -> TextChildAnchor&;

  ~TextChildAnchor() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTextChildAnchor*       { return reinterpret_cast<GtkTextChildAnchor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTextChildAnchor* { return reinterpret_cast<GtkTextChildAnchor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTextChildAnchor*;

private:

protected:
  TextChildAnchor();

public:

  static auto create() -> Glib::RefPtr<TextChildAnchor>;


  // gtk_text_child_anchor_new_with_replacement() does more than call g_object_new().

  /** Creates a new `Gtk::TextChildAnchor` with the given replacement character.
   *
   * Usually you would then insert it into a `Gtk::TextBuffer` with
   * Gtk::TextBuffer::insert_child_anchor().
   *
   * @param replacement_character Must be exactly one UTF-8 character.
   *                              Can be more than one byte.
   *
   * @newin{4,6}
   *
   * @return A new `Gtk::TextChildAnchor`.
   */
  static auto create(const Glib::ustring& replacement_character) -> Glib::RefPtr<TextChildAnchor>;

  /** Gets a list of all widgets anchored at this child anchor.
   *
   * @return A vector of widgets anchored at this %TextChildAnchor.
   */
  auto get_widgets() -> std::vector<Widget*>;

  /** Gets a list of all widgets anchored at this child anchor.
   *
   * @return A vector of widgets anchored at this %TextChildAnchor.
   */
  auto get_widgets() const -> std::vector<const Widget*>;


  /** Determines whether a child anchor has been deleted from
   * the buffer.
   *
   * Keep in mind that the child anchor will be unreferenced
   * when removed from the buffer, so you need to hold your own
   * reference (with Glib::object_ref()) if you plan to use this
   * function — otherwise all deleted child anchors will also
   * be finalized.
   *
   * @return <tt>true</tt> if the child anchor has been deleted from its buffer.
   */
  auto get_deleted() const -> bool;


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
   * @relates Gtk::TextChildAnchor
   */
  GTKMM_API
  auto wrap(GtkTextChildAnchor* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TextChildAnchor>;
}


#endif /* _GTKMM_TEXTCHILDANCHOR_H */

