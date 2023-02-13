
#ifndef _GTKMM_CSSSECTION_H
#define _GTKMM_CSSSECTION_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2014 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/glib/refptr.hpp>
#include <mm/gio/file.hpp>
#include <mm/gtk/csslocation.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkCssSection GtkCssSection;
#endif

namespace Gtk
{

/** Defines a part of a CSS document.
 * Because sections are nested into one another, you can use get_parent()
 * to get the containing region.
 *
 * A %CssSection is input data to a Gtk::CssProvider::signal_parsing_error() handler.
 *
 * @newin{3,16}
 */
class GTKMM_API CssSection final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = CssSection;
  using BaseObjectType = GtkCssSection;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkCssSection*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkCssSection*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GtkCssSection*;

  CssSection() = delete;

  // noncopyable
  CssSection(const CssSection&) = delete;
  auto operator=(const CssSection&) -> CssSection& = delete;

protected:
  // Do not derive this.  Gtk::CssSection can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:

  /** Creates a new `Gtk::CssSection` referring to the section
   * in the given `file` from the `start` location to the
   * `end` location.
   *
   * @param file The file this section refers to.
   * @param start The start location.
   * @param end The end location.
   * @return A new `Gtk::CssSection`.
   */
  static auto create(const Glib::RefPtr<Gio::File>& file, const CssLocation& start, const CssLocation& end) -> Glib::RefPtr<CssSection>;


  /** Prints the section into a human-readable text form.
   *
   * This is a form like `gtk.css:32:1-23` to denote line 32,
   * characters 1 to 23 in the file gtk.css.
   *
   * @return A new string.
   */
  auto to_string() const -> Glib::ustring;


  /** Gets the parent section for the given `section`.
   *
   * The parent section is the section that contains this `section`. A special
   * case are sections of  type `Gtk::CssSection::Type::DOCUMEN`T. Their parent will
   * either be <tt>nullptr</tt> if they are the original CSS document that was loaded by
   * Gtk::CssProvider::load_from_file() or a section of type
   * `Gtk::CssSection::Type::IMPORT` if it was loaded with an ` @a import` rule from
   * a different file.
   *
   * @return The parent section.
   */
  auto get_parent() -> Glib::RefPtr<CssSection>;

  /** Gets the parent section for the given `section`.
   *
   * The parent section is the section that contains this `section`. A special
   * case are sections of  type `Gtk::CssSection::Type::DOCUMEN`T. Their parent will
   * either be <tt>nullptr</tt> if they are the original CSS document that was loaded by
   * Gtk::CssProvider::load_from_file() or a section of type
   * `Gtk::CssSection::Type::IMPORT` if it was loaded with an ` @a import` rule from
   * a different file.
   *
   * @return The parent section.
   */
  auto get_parent() const -> Glib::RefPtr<const CssSection>;

  /** Gets the file that @a section was parsed from.
   *
   * If no such file exists, for example because the CSS was loaded via
   * Gtk::CssProvider::load_from_data(), then <tt>nullptr</tt> is returned.
   *
   * @return The `Gio::File` from which the `section`
   * was parsed.
   */
  auto get_file() -> Glib::RefPtr<Gio::File>;

  /** Gets the file that @a section was parsed from.
   *
   * If no such file exists, for example because the CSS was loaded via
   * Gtk::CssProvider::load_from_data(), then <tt>nullptr</tt> is returned.
   *
   * @return The `Gio::File` from which the `section`
   * was parsed.
   */
  auto get_file() const -> Glib::RefPtr<const Gio::File>;

  /** Returns the location in the CSS document where this section starts.
   *
   * @return The start location of
   * this section.
   */
  auto get_start_location() const -> CssLocation;

  /** Returns the location in the CSS document where this section ends.
   *
   * @return The end location of
   * this section.
   */
  auto get_end_location() const -> CssLocation;


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
 * @relates Gtk::CssSection
 */
GTKMM_API
auto wrap(GtkCssSection* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CssSection>;

} // namespace Glib


#endif /* _GTKMM_CSSSECTION_H */

