
#ifndef _GTKMM_PAGESETUP_H
#define _GTKMM_PAGESETUP_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-glib/object.hpp>
#include <libmm-gtk/enums.hpp>
#include <libmm-gtk/papersize.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPageSetup = struct _GtkPageSetup;
using GtkPageSetupClass = struct _GtkPageSetupClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API PageSetup_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A PageSetup object stores the page size, orientation and margins. You can get one of these from the page setup dialog
 * and then pass it to the PrintOperation when printing. The benefit of splitting this out of the PrintSettings is that
 * these affect the actual layout of the page, and thus need to be set long before the user prints.
 *
 * The margins specified in this object are the "print margins", i.e. the parts of the page that the printer cannot print
 * on. These are different from the layout margins that a word processor uses; they are typically used to determine the
 * minimal size for the layout margins.
 *
 * To obtain a PageSetup use PageSetup::create() to get the defaults, or use run_page_setup_dialog() to show the page
 * setup dialog and receive the resulting page setup.
 *
 * @newin{2,10}
 *
 * @ingroup Printing
 */

class GTKMM_API PageSetup : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PageSetup;
  using CppClassType = PageSetup_Class;
  using BaseObjectType = GtkPageSetup;
  using BaseClassType = GtkPageSetupClass;

  // noncopyable
  PageSetup(const PageSetup&) = delete;
  auto operator=(const PageSetup&) -> PageSetup& = delete;

private:  friend class PageSetup_Class;
  static CppClassType pagesetup_class_;

protected:
  explicit PageSetup(const Glib::ConstructParams& construct_params);
  explicit PageSetup(GtkPageSetup* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PageSetup(PageSetup&& src) noexcept;
  auto operator=(PageSetup&& src) noexcept -> PageSetup&;

  ~PageSetup() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkPageSetup*       { return reinterpret_cast<GtkPageSetup*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPageSetup* { return reinterpret_cast<GtkPageSetup*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkPageSetup*;

private:

protected:
  PageSetup();

public:

  static auto create() -> Glib::RefPtr<PageSetup>;


 /** Reads the page setup from the "Page Setup" group in the key file @a key_file.
  * Returns a new PageSetup object with the restored
  * page setup, or an empty RefPtr if an error occurred.
  *
  * @param key_file The KeyFile to retrieve the page setup from.
  * @result The restored PageSetup
  *
  * @throws KeyFileError
  *
  * @newin{2,14}
  */
  static auto create_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file) -> Glib::RefPtr<PageSetup>;

 /** Reads the page setup from the group @a group_name in the key file @a key_file.
  * Returns a new PageSetup object with the restored
  * page setup, or an empty RefPtr if an error occurred.
  *
  * @param key_file The KeyFile to retrieve the page setup from.
  * @param group_name The name of the group in the key_file to read.
  * @result The restored PageSetup
  *
  * @throws KeyFileError
  *
  * @newin{2,14}
  */
  static auto create_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file, const Glib::ustring& group_name) -> Glib::RefPtr<PageSetup>;


 /** Reads the page setup from the file @a file_name. Returns a
  * new PageSetup object with the restored page setup,
  * or an empty RefPtr if an error occurred. See save_to_file().
  *
  * @param file_name The filename to read the page setup from.
  * @result The restored PageSetup
  *
  * @newin{2,14}
  */
  static auto create_from_file(const std::string& file_name) -> Glib::RefPtr<PageSetup>;


  /** Copies a `Gtk::PageSetup`.
   *
   * @return A copy of @a other.
   */
  auto copy() const -> Glib::RefPtr<PageSetup>;

  //The from_ infix was added to these functions to make them clearer. GTK+ didn't want to change them.

  /** Reads the page setup from the file @a file_name.
   *
   * See to_file().
   *
   * @param file_name The filename to read the page setup from.
   * @return <tt>true</tt> on success.
   *
   * @throws Glib::Error
   */
  auto load_from_file(const std::string& file_name) -> bool;


  /** Reads the page setup from the group @a group_name in the key file
   *  @a key_file.
   *
   * @param key_file The `Glib::KeyFile` to retrieve the page_setup from.
   * @param group_name The name of the group in the key_file to read
   * to use the default name “Page Setup”.
   * @return <tt>true</tt> on success.
   *
   * @throws Glib::Error
   */
  auto load_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file, const Glib::ustring& group_name) -> bool;

 /** Reads the page setup from the "Page Setup" group in the key file @a key_file.
  *
  * @param key_file The KeyFile to retrieve the page setup from.
  * @result true on success
  *
  * @throws KeyFileError
  *
  * @newin{2,14}
  */
  auto load_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file) -> bool;


  /** Gets the page orientation of the `Gtk::PageSetup`.
   *
   * @return The page orientation.
   */
  auto get_orientation() const -> PageOrientation;

  /** Sets the page orientation of the `Gtk::PageSetup`.
   *
   * @param orientation A `Gtk::PageOrientation` value.
   */
  void set_orientation(PageOrientation orientation);


  /** Gets the paper size of the `Gtk::PageSetup`.
   *
   * @return The paper size.
   */
  auto get_paper_size() -> PaperSize;

  /** Gets the paper size of the `Gtk::PageSetup`.
   *
   * @return The paper size.
   */
  auto get_paper_size() const -> const PaperSize;

  /** Sets the paper size of the `Gtk::PageSetup` without
   * changing the margins.
   *
   * See set_paper_size_and_default_margins().
   *
   * @param size A `Gtk::PaperSize`.
   */
  void set_paper_size(const PaperSize& size);


  /** Gets the top margin in units of @a unit.
   *
   * @param unit The unit for the return value.
   * @return The top margin.
   */
  auto get_top_margin(Unit unit) const -> double;

  /** Sets the top margin of the `Gtk::PageSetup`.
   *
   * @param margin The new top margin in units of @a unit.
   * @param unit The units for @a margin.
   */
  void set_top_margin(double margin, Unit unit);


  /** Gets the bottom margin in units of @a unit.
   *
   * @param unit The unit for the return value.
   * @return The bottom margin.
   */
  auto get_bottom_margin(Unit unit) const -> double;

  /** Sets the bottom margin of the `Gtk::PageSetup`.
   *
   * @param margin The new bottom margin in units of @a unit.
   * @param unit The units for @a margin.
   */
  void set_bottom_margin(double margin, Unit unit);


  /** Gets the left margin in units of @a unit.
   *
   * @param unit The unit for the return value.
   * @return The left margin.
   */
  auto get_left_margin(Unit unit) const -> double;

  /** Sets the left margin of the `Gtk::PageSetup`.
   *
   * @param margin The new left margin in units of @a unit.
   * @param unit The units for @a margin.
   */
  void set_left_margin(double margin, Unit unit);


  /** Gets the right margin in units of @a unit.
   *
   * @param unit The unit for the return value.
   * @return The right margin.
   */
  auto get_right_margin(Unit unit) const -> double;

  /** Sets the right margin of the `Gtk::PageSetup`.
   *
   * @param margin The new right margin in units of @a unit.
   * @param unit The units for @a margin.
   */
  void set_right_margin(double margin, Unit unit);


  /** Sets the paper size of the `Gtk::PageSetup` and modifies
   * the margins according to the new paper size.
   *
   * @param size A `Gtk::PaperSize`.
   */
  void set_paper_size_and_default_margins(const PaperSize& size);


  /** Returns the paper width in units of @a unit.
   *
   * Note that this function takes orientation,
   * but not margins into consideration.
   * See get_page_width().
   *
   * @param unit The unit for the return value.
   * @return The paper width.
   */
  auto get_paper_width(Unit unit) const -> double;

  /** Returns the paper height in units of @a unit.
   *
   * Note that this function takes orientation,
   * but not margins into consideration.
   * See get_page_height().
   *
   * @param unit The unit for the return value.
   * @return The paper height.
   */
  auto get_paper_height(Unit unit) const -> double;


  /** Returns the page width in units of @a unit.
   *
   * Note that this function takes orientation
   * and margins into consideration.
   * See get_paper_width().
   *
   * @param unit The unit for the return value.
   * @return The page width.
   */
  auto get_page_width(Unit unit) const -> double;

  /** Returns the page height in units of @a unit.
   *
   * Note that this function takes orientation
   * and margins into consideration.
   * See get_paper_height().
   *
   * @param unit The unit for the return value.
   * @return The page height.
   */
  auto get_page_height(Unit unit) const -> double;

  //The save_ prefix was added to these functions to make them clearer. GTK+ didn't want to change them.

  /** This function saves the information from @a setup to @a file_name.
   *  @throws Glib::FileError
   *
   * @newin{2,12}
   *
   * @param file_name The file to save to.
   * @return <tt>true</tt> on success.
   */
  auto save_to_file(const std::string& file_name) const -> bool;


  /** This function adds the page setup from @a setup to @a key_file.
   *
   * @param key_file The Glib::KeyFile to save the page setup to.
   * @param group_name The group to add the settings to in @a key_file.
   */
  void save_to_key_file(const Glib::RefPtr<Glib::KeyFile>& key_file, const Glib::ustring& group_name) const;

  /** This function adds the page setup from @a setup to @a key_file,
   * in the group "Page Setup"
   *
   * @newin{2,12}
   *
   * @param key_file The G::KeyFile to save the page setup to.
   */
  void save_to_key_file(const Glib::RefPtr<Glib::KeyFile>& key_file) const;


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
   * @relates Gtk::PageSetup
   */
  GTKMM_API
  auto wrap(GtkPageSetup* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PageSetup>;
}


#endif /* _GTKMM_PAGESETUP_H */

