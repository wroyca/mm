
#ifndef _GTKMM_PAPERSIZE_H
#define _GTKMM_PAPERSIZE_H

#include <mm/gtk/mm-gtkconfig.hpp>


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


#include <mm/glib/keyfile.hpp>
#include <mm/glib/value.hpp>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GtkPaperSize GtkPaperSize; }
#endif

namespace Gtk
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct PaperSizeTraits;
#endif

/** Common paper names, from PWG 5101.1-2002 PWG: Standard for Media Standardized Names
 */
extern GTKMM_API const Glib::ustring PAPER_NAME_A3;
extern GTKMM_API const Glib::ustring PAPER_NAME_A4;
extern GTKMM_API const Glib::ustring PAPER_NAME_A5;
extern GTKMM_API const Glib::ustring PAPER_NAME_B5;
extern GTKMM_API const Glib::ustring PAPER_NAME_LETTER;
extern GTKMM_API const Glib::ustring PAPER_NAME_EXECUTIVE;
extern GTKMM_API const Glib::ustring PAPER_NAME_LEGAL;

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var Unit NONE
 * No units.
 *
 *  @var Unit POINTS
 * Dimensions in points.
 *
 *  @var Unit INCH
 * Dimensions in inches.
 *
 *  @var Unit MM
 * Dimensions in millimeters.
 *
 *  @enum Unit
 *
 * See also Gtk::PrintSettings::set_paper_width().
 *
 * @ingroup gtkmmEnums
 */
enum class Unit
{
  NONE,
  POINTS,
  INCH,
  MM
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Unit> : public Glib::Value_Enum<Gtk::Unit>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** PaperSize handles paper sizes. It uses the standard called "PWG 5101.1-2002 PWG: Standard for Media Standardized Names"
 * to name the paper sizes (and to get the data for the page sizes). In addition to standard paper sizes, PaperSize allows
 * to construct custom paper sizes with arbitrary dimensions.
 *
 * The PaperSize object stores not only the dimensions (width and height) of a paper size and its name, it also provides
 * default print margins.
 *
 * @newin{2,10}
 *
 * @ingroup Printing
 */
class GTKMM_API PaperSize
{
  // Cannot pass the _new function here, it must accept the 'name' argument.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = PaperSize;
  using BaseObjectType = GtkPaperSize;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  PaperSize();

  explicit PaperSize(GtkPaperSize* gobject, bool make_a_copy = true);

  PaperSize(const PaperSize& other);
  auto operator=(const PaperSize& other) -> PaperSize&;

  PaperSize(PaperSize&& other) noexcept;
  auto operator=(PaperSize&& other) noexcept -> PaperSize&;

  ~PaperSize() noexcept;

  void swap(PaperSize& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkPaperSize*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkPaperSize* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GtkPaperSize*;

protected:
  GtkPaperSize* gobject_;

private:

public:

  // We don't use a "" default parameter value, though gtk_paper_size_new() can take NULL,
  // because there is already a (desired) default constructor (creating an invalid instance).
  // get_default() does what name="" would do.
  explicit PaperSize(const Glib::ustring& name);
  explicit PaperSize(const Glib::ustring& ppd_name, const Glib::ustring& ppd_display_name, double width, double height);
  explicit PaperSize(const Glib::ustring& name, const Glib::ustring& display_name, double width, double height, Unit unit);

  /** Reads a paper size from the group @a group_name in the key file @a key_file.
   *
   * @param key_file The Glib::KeyFile to retrieve the paper size from.
   * @param group_name The name of the group in the key file to read,
   *                   or an empty string to read the first group.
   *
   * @throws Gtk::PrintError, Glib::KeyFileError
   */
  explicit PaperSize(const Glib::RefPtr<const Glib::KeyFile>& key_file, const Glib::ustring& group_name = {});


  auto equal(const PaperSize& other) const -> bool;

   /** Returns true if the PaperSize is a valid object.
    * For instance,
    * @code
    * if(papersize)
    *   do_something()
    * @endcode
    *
    * @newin{3,22}
    */
   explicit operator bool() const;


  /** Creates a list of known paper sizes.
   *
   * @param include_custom Whether to include custom paper sizes
   * as defined in the page setup dialog.
   * @return A newly allocated list of newly
   * allocated `Gtk::PaperSize` objects.
   */
  static auto get_paper_sizes(bool include_custom =  true) -> std::vector<PaperSize>;


  /** Gets the name of the `Gtk::PaperSize`.
   *
   * @return The name of @a size.
   */
  auto get_name() const -> Glib::ustring;

  /** Gets the human-readable name of the `Gtk::PaperSize`.
   *
   * @return The human-readable name of @a size.
   */
  auto get_display_name() const -> Glib::ustring;

  /** Gets the PPD name of the `Gtk::PaperSize`, which
   * may be <tt>nullptr</tt>.
   *
   * @return The PPD name of @a size.
   */
  auto get_ppd_name() const -> Glib::ustring;


  /** Gets the paper width of the `Gtk::PaperSize`, in
   * units of @a unit.
   *
   * @param unit The unit for the return value, not Gtk::Unit::NONE.
   * @return The paper width.
   */
  auto get_width(Unit unit) const -> double;

  /** Gets the paper height of the `Gtk::PaperSize`, in
   * units of @a unit.
   *
   * @param unit The unit for the return value, not Gtk::Unit::NONE.
   * @return The paper height.
   */
  auto get_height(Unit unit) const -> double;

  /** Returns <tt>true</tt> if @a size is not a standard paper size.
   *
   * @return Whether @a size is a custom paper size.
   */
  auto is_custom() const -> bool;

  /** Returns <tt>true</tt> if @a size is an IPP standard paper size.
   *
   * @return Whether @a size is not an IPP custom paper size.
   */
  auto is_ipp() const -> bool;


  /** Changes the dimensions of a @a size to @a width x @a height.
   *
   * @param width The new width in units of @a unit.
   * @param height The new height in units of @a unit.
   * @param unit The unit for @a width and @a height.
   */
  void set_size(double width, double height, Unit unit);

  /** Gets the default top margin for the `Gtk::PaperSize`.
   *
   * @param unit The unit for the return value, not Gtk::Unit::NONE.
   * @return The default top margin.
   */
  auto get_default_top_margin(Unit unit) const -> double;

  /** Gets the default bottom margin for the `Gtk::PaperSize`.
   *
   * @param unit The unit for the return value, not Gtk::Unit::NONE.
   * @return The default bottom margin.
   */
  auto get_default_bottom_margin(Unit unit) const -> double;

  /** Gets the default left margin for the `Gtk::PaperSize`.
   *
   * @param unit The unit for the return value, not Gtk::Unit::NONE.
   * @return The default left margin.
   */
  auto get_default_left_margin(Unit unit) const -> double;

  /** Gets the default right margin for the `Gtk::PaperSize`.
   *
   * @param unit The unit for the return value, not Gtk::Unit::NONE.
   * @return The default right margin.
   */
  auto get_default_right_margin(Unit unit) const -> double;


  /** Returns the name of the default paper size, which
   * depends on the current locale.
   *
   * @return The name of the default paper size. The string
   * is owned by GTK and should not be modified.
   */
  static auto get_default() -> Glib::ustring;


  /** This function adds the paper size from @a size to @a key_file.
   *
   * @param key_file The `Glib::KeyFile` to save the paper size to.
   * @param group_name The group to add the settings to in @a key_file.
   */
  void save_to_key_file(const Glib::RefPtr<Glib::KeyFile>& key_file, const Glib::ustring& group_name);

  /** This function adds the paper size to @a key_file in the first group.
   *
   * @newin{2,12}
   *
   * @param key_file The Glib::KeyFile to save the paper size to.
   */
  void save_to_key_file(const Glib::RefPtr<Glib::KeyFile>& key_file);


};

/** @relates Gtk::PaperSize */
inline auto operator==(const PaperSize& lhs, const PaperSize& rhs) -> bool
  { return lhs.equal(rhs); }

/** @relates Gtk::PaperSize */
inline auto operator!=(const PaperSize& lhs, const PaperSize& rhs) -> bool
  { return !lhs.equal(rhs); }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct PaperSizeTraits
{
  typedef PaperSize  CppType;
  typedef const GtkPaperSize*      CType;
  typedef GtkPaperSize*            CTypeNonConst;

  static auto   to_c_type      (const CppType& obj) -> CType { return obj.gobj();     }
  static auto   to_c_type      (CType          ptr) -> CType { return ptr;                   }
  static auto to_cpp_type    (CType          ptr) -> CppType { return PaperSize(const_cast<GtkPaperSize*>(ptr), true /* make_copy */); /* Does not take ownership */ }
  static void    release_c_type (CType          ptr);
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gtk


namespace Gtk
{

/** @relates Gtk::PaperSize
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(PaperSize& lhs, PaperSize& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Gtk

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gtk::PaperSize
 */
GTKMM_API
auto wrap(GtkPaperSize* object, bool take_copy = false) -> Gtk::PaperSize;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GTKMM_API Value<Gtk::PaperSize> : public Glib::Value_Boxed<Gtk::PaperSize>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_PAPERSIZE_H */

