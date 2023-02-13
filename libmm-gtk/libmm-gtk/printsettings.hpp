
#ifndef _GTKMM_PRINTSETTINGS_H
#define _GTKMM_PRINTSETTINGS_H


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

#include <vector>

#include <mm/glib/object.hpp>
#include <mm/gtk/enums.hpp>
#include <mm/gtk/papersize.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintSettings = struct _GtkPrintSettings;
using GtkPrintSettingsClass = struct _GtkPrintSettingsClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API PrintSettings_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var PrintDuplex SIMPLEX
 * No duplex.
 *
 *  @var PrintDuplex HORIZONTAL
 * Horizontal duplex.
 *
 *  @var PrintDuplex VERTICAL
 * Vertical duplex.
 *
 *  @enum PrintDuplex
 *
 * See also Gtk::PrintSettings::set_duplex().
 *
 * @ingroup gtkmmEnums
 */
enum class PrintDuplex
{
  SIMPLEX,
  HORIZONTAL,
  VERTICAL
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PrintDuplex> : public Glib::Value_Enum<Gtk::PrintDuplex>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var PrintQuality LOW
 * Low quality.
 *
 *  @var PrintQuality NORMAL
 * Normal quality.
 *
 *  @var PrintQuality HIGH
 * High quality.
 *
 *  @var PrintQuality DRAFT
 * Draft quality.
 *
 *  @enum PrintQuality
 *
 * See also Gtk::PrintSettings::set_quality().
 *
 * @ingroup gtkmmEnums
 */
enum class PrintQuality
{
  LOW,
  NORMAL,
  HIGH,
  DRAFT
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PrintQuality> : public Glib::Value_Enum<Gtk::PrintQuality>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var PrintPages ALL
 * All pages.
 *
 *  @var PrintPages CURRENT
 * Current page.
 *
 *  @var PrintPages RANGES
 * Range of pages.
 *
 *  @var PrintPages SELECTION
 * Selected pages.
 *
 *  @enum PrintPages
 *
 * See also Gtk::PrintJob::set_pages()
 *
 * @ingroup gtkmmEnums
 */
enum class PrintPages
{
  ALL,
  CURRENT,
  RANGES,
  SELECTION
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PrintPages> : public Glib::Value_Enum<Gtk::PrintPages>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var PageSet ALL
 * All pages.
 *
 *  @var PageSet EVEN
 * Even pages.
 *
 *  @var PageSet ODD
 * Odd pages.
 *
 *  @enum PageSet
 *
 * See also Gtk::PrintJob::set_page_set().
 *
 * @ingroup gtkmmEnums
 */
enum class PageSet
{
  ALL,
  EVEN,
  ODD
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PageSet> : public Glib::Value_Enum<Gtk::PageSet>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var NumberUpLayout LEFT_TO_RIGHT_TOP_TO_BOTTOM
 * ![](layout-lrtb.png).
 *
 *  @var NumberUpLayout LEFT_TO_RIGHT_BOTTOM_TO_TOP
 * ![](layout-lrbt.png).
 *
 *  @var NumberUpLayout RIGHT_TO_LEFT_TOP_TO_BOTTOM
 * ![](layout-rltb.png).
 *
 *  @var NumberUpLayout RIGHT_TO_LEFT_BOTTOM_TO_TOP
 * ![](layout-rlbt.png).
 *
 *  @var NumberUpLayout TOP_TO_BOTTOM_LEFT_TO_RIGHT
 * ![](layout-tblr.png).
 *
 *  @var NumberUpLayout TOP_TO_BOTTOM_RIGHT_TO_LEFT
 * ![](layout-tbrl.png).
 *
 *  @var NumberUpLayout BOTTOM_TO_TOP_LEFT_TO_RIGHT
 * ![](layout-btlr.png).
 *
 *  @var NumberUpLayout BOTTOM_TO_TOP_RIGHT_TO_LEFT
 * ![](layout-btrl.png).
 *
 *  @enum NumberUpLayout
 *
 * Used to determine the layout of pages on a sheet when printing
 * multiple pages per sheet.
 *
 * @ingroup gtkmmEnums
 */
enum class NumberUpLayout
{
  LEFT_TO_RIGHT_TOP_TO_BOTTOM,
  LEFT_TO_RIGHT_BOTTOM_TO_TOP,
  RIGHT_TO_LEFT_TOP_TO_BOTTOM,
  RIGHT_TO_LEFT_BOTTOM_TO_TOP,
  TOP_TO_BOTTOM_LEFT_TO_RIGHT,
  TOP_TO_BOTTOM_RIGHT_TO_LEFT,
  BOTTOM_TO_TOP_LEFT_TO_RIGHT,
  BOTTOM_TO_TOP_RIGHT_TO_LEFT
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::NumberUpLayout> : public Glib::Value_Enum<Gtk::NumberUpLayout>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** A page range.
 */
class GTKMM_API PageRange
{
public:
  PageRange();
  PageRange(int start, int end);

  int start;
  int end;
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct PageRangeTraits
{
  using CppType       = PageRange;
  using CType         = GtkPageRange;
  using CTypeNonConst = GtkPageRange;

  static auto   to_c_type      (CType c_obj) -> CType            { return c_obj; }
  static void    release_c_type (CType)                  {}
  static auto   to_c_type      (const CppType& cpp_obj) -> CType { CTypeNonConst c_obj = {cpp_obj.start, cpp_obj.end}; return c_obj; }
  static auto to_cpp_type    (CType c_obj) -> CppType            { return CppType (c_obj.start, c_obj.end); }
};
#endif // DOXYGEN_SHOULD_SKIP_THIS

/** A PrintSettings object represents the settings of a print dialog in a system-independent way.
 * The main use for this object is that once you've printed you can get a settings object that
 * represents the settings the user chose, and the next time you print you can pass that object
 * in so that the user doesn't have to re-set all his settings.
 *
 * It's also possible to enumerate the settings so that you can easily save the settings for the
 * next time your app runs, or even store them in a document. The predefined keys try to use shared
 * values as much as possible so that moving such a document between systems still works.
 *
 * @newin{2,10}
 *
 * @ingroup Printing
 */

class GTKMM_API PrintSettings : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PrintSettings;
  using CppClassType = PrintSettings_Class;
  using BaseObjectType = GtkPrintSettings;
  using BaseClassType = GtkPrintSettingsClass;

  // noncopyable
  PrintSettings(const PrintSettings&) = delete;
  auto operator=(const PrintSettings&) -> PrintSettings& = delete;

private:  friend class PrintSettings_Class;
  static CppClassType printsettings_class_;

protected:
  explicit PrintSettings(const Glib::ConstructParams& construct_params);
  explicit PrintSettings(GtkPrintSettings* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PrintSettings(PrintSettings&& src) noexcept;
  auto operator=(PrintSettings&& src) noexcept -> PrintSettings&;

  ~PrintSettings() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkPrintSettings*       { return reinterpret_cast<GtkPrintSettings*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPrintSettings* { return reinterpret_cast<GtkPrintSettings*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkPrintSettings*;

private:

protected:
  PrintSettings();

public:

  static auto create() -> Glib::RefPtr<PrintSettings>;


 /** Reads the print settings from the @a key_file.
  * Returns a new PrintSettings object with the restored settings,
  * or an empty RefPtr if an error occurred.
  * See save_to_key_file().
  *
  * @param key_file The KeyFile to retrieve the settings from.
  * @result the restored PrintSettings
  *
  * @throws KeyFileError, FileError
  *
  * @newin{2,14}
  */
  static auto create_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file) -> Glib::RefPtr<PrintSettings>;

 /** Reads the print settings from the group @a group_name in @a key_file.
  * Returns a new PrintSettings object with the restored settings,
  * or an empty RefPtr if an error occurred.
  * See save_to_key_file().
  *
  * @param key_file The KeyFile to retrieve the settings from.
  * @param group_name The name of the group to use.
  * @result the restored PrintSettings
  *
  * @throws KeyFileError, FileError
  *
  * @newin{2,14}
  */
  static auto create_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file, const Glib::ustring& group_name) -> Glib::RefPtr<PrintSettings>;


 /** Reads the print settings from @a file_name. Returns a new PrintSettings
  * object with the restored settings, or an empty RefPtr if an error occurred.
  * See save_to_file().
  *
  * @param file_name The filename to read the settings from.
  * @result the restored PrintSettings
  *
  * @throws KeyFileError, FileError
  *
  * @newin{2,14}
  */
  static auto create_from_file(const std::string& file_name) -> Glib::RefPtr<PrintSettings>;


  /** Print settings keys.
   */
  class Keys
  {
  public:
    static const Glib::ustring PRINTER;
    static const Glib::ustring ORIENTATION;
    static const Glib::ustring PAPER_FORMAT;
    static const Glib::ustring PAPER_WIDTH;
    static const Glib::ustring PAPER_HEIGHT;
    static const Glib::ustring NUM_COPIES;
    static const Glib::ustring DEFAULT_SOURCE;
    static const Glib::ustring QUALITY;
    static const Glib::ustring RESOLUTION;
    static const Glib::ustring USE_COLOR;
    static const Glib::ustring DUPLEX;
    static const Glib::ustring COLLATE;
    static const Glib::ustring REVERSE;
    static const Glib::ustring MEDIA_TYPE;
    static const Glib::ustring DITHER;
    static const Glib::ustring SCALE;
    static const Glib::ustring PRINT_PAGES;
    static const Glib::ustring PAGE_RANGES;
    static const Glib::ustring PAGE_SET;
    static const Glib::ustring FINISHINGS;
    static const Glib::ustring NUMBER_UP;
    static const Glib::ustring NUMBER_UP_LAYOUT;
    static const Glib::ustring OUTPUT_BIN;

    static const Glib::ustring OUTPUT_FILE_FORMAT;
    static const Glib::ustring OUTPUT_URI;

    static const Glib::ustring WIN32_DRIVER_VERSION;
    static const Glib::ustring WIN32_DRIVER_EXTRA;
  };


  /** Copies a `Gtk::PrintSettings` object.
   *
   * @return A newly allocated copy of @a other.
   */
  auto copy() const -> Glib::RefPtr<PrintSettings>;

  //The from_ infix was added to these functions to make them clearer. GTK+ didn't want to change them.

  /** Reads the print settings from @a file_name.
   *
   * If the file could not be loaded then error is set to either
   * a `Glib::FileError` or `Glib::KeyFileError`.
   *
   * See to_file().
   *
   * @param file_name The filename to read the settings from.
   * @return <tt>true</tt> on success.
   *
   * @throws Glib::Error
   */
  auto load_from_file(const std::string& file_name) -> bool;


  /** Reads the print settings from the group @a group_name in @a key_file.
   *
   * If the file could not be loaded then error is set to either a
   * `Glib::FileError` or `Glib::KeyFileError`.
   *
   * @param key_file The `Glib::KeyFile` to retrieve the settings from.
   * @param group_name The name of the group to use, or <tt>nullptr</tt>
   * to use the default “Print Settings”.
   * @return <tt>true</tt> on success.
   *
   * @throws Glib::Error
   */
  auto load_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file, const Glib::ustring& group_name) -> bool;

 /** Reads the print settings from the @a key_file.
  * See save_to_key_file().
  *
  * @param key_file The KeyFile to retrieve the settings from.
  * @result true on success.
  *
  * @throws KeyFileError, FileError
  *
  * @newin{2,14}
  */
  auto load_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file) -> bool;


  //The save_ prefix was added to these functions to make them clearer. GTK+ didn't want to change them.

  /** This function saves the print settings from @a settings to @a file_name.
   *  @throws FileError
   *
   * @newin{2,12}
   *
   * @param file_name The file to save to.
   * @return <tt>true</tt> on success.
   */
  auto save_to_file(const std::string& file_name) const -> bool;


  /** This function adds the print settings from @a settings to @a key_file.
   *
   * @param key_file The Glib::KeyFile to save the print settings to.
   * @param group_name The group to add the settings to in @a key_file.
   */
  void save_to_key_file(const Glib::RefPtr<Glib::KeyFile>& key_file, const Glib::ustring& group_name) const;

  /** This function adds the print settings from @a settings to @a key_file,
   * in the "Print Settings" group.
   *
   * @newin{2,12}
   *
   * @param key_file The Glib::KeyFile to save the print settings to.
   */
  void save_to_key_file(const Glib::RefPtr<Glib::KeyFile>& key_file) const;


  /** Returns <tt>true</tt>, if a value is associated with @a key.
   *
   * @param key A key.
   * @return <tt>true</tt>, if @a key has a value.
   */
  auto has_key(const Glib::ustring& key) const -> bool;


  /** Looks up the string value associated with @a key.
   *
   * @param key A key.
   * @return The string value for @a key.
   */
  auto get(const Glib::ustring& key) const -> Glib::ustring;


  /** Associates @a value with @a key.
   *
   * @param key A key.
   * @param value A string value.
   */
  void set(const Glib::ustring& key, const Glib::ustring& value);

  /** Removes any value associated with @a key.
   *
   * This has the same effect as setting the value to <tt>nullptr</tt>.
   *
   * @param key A key.
   */
  void unset(const Glib::ustring& key);

  /** For example,
   * void on_foreach_setting(const Glib::ustring& key, const Glib::ustring& value);
   */
  typedef sigc::slot<void(const Glib::ustring&, const Glib::ustring&)> SlotForeach;

  /** Calls a function for each print setting.
  * @param slot The callback to call for each print setting.
  */
  void setting_foreach(const SlotForeach& slot);


  /** Returns the boolean represented by the value
   * that is associated with @a key.
   *
   * The string “true” represents <tt>true</tt>, any other
   * string <tt>false</tt>.
   *
   * @param key A key.
   * @return <tt>true</tt>, if @a key maps to a true value.
   */
  auto get_bool(const Glib::ustring& key) const -> bool;

  /** Sets @a key to a boolean value.
   *
   * @param key A key.
   * @param value A boolean.
   */
  void set_bool(const Glib::ustring& key, bool value =  true);


  /** Returns the double value associated with @a key, or 0.
   *
   * @param key A key.
   * @return The double value of @a key.
   */
  auto get_double(const Glib::ustring& key) const -> double;

  /** Returns the floating point number represented by
   * the value that is associated with @a key, or @a default_val
   * if the value does not represent a floating point number.
   *
   * Floating point numbers are parsed with Glib::ascii_strtod().
   *
   * @param key A key.
   * @param def The default value.
   * @return The floating point number associated with @a key.
   */
  auto get_double_with_default(const Glib::ustring& key, double def) const -> double;

  /** Sets @a key to a double value.
   *
   * @param key A key.
   * @param value A double value.
   */
  void set_double(const Glib::ustring& key, double value);


  /** Returns the value associated with @a key, interpreted
   * as a length.
   *
   * The returned value is converted to @a units.
   *
   * @param key A key.
   * @param unit The unit of the return value.
   * @return The length value of @a key, converted to @a unit.
   */
  auto get_length(const Glib::ustring& key, Unit unit) const -> double;

  /** Associates a length in units of @a unit with @a key.
   *
   * @param key A key.
   * @param value A length.
   * @param unit The unit of @a length.
   */
  void set_length(const Glib::ustring& key, double value, Unit unit);


  /** Returns the integer value of @a key, or 0.
   *
   * @param key A key.
   * @return The integer value of @a key.
   */
  auto get_int(const Glib::ustring& key) const -> int;

  /** Returns the value of @a key, interpreted as
   * an integer, or the default value.
   *
   * @param key A key.
   * @param def The default value.
   * @return The integer value of @a key.
   */
  auto get_int_with_default(const Glib::ustring& key, int def) const -> int;

  /** Sets @a key to an integer value.
   *
   * @param key A key.
   * @param value An integer.
   */
  void set_int(const Glib::ustring& key, int value);

  // helpers:


  /** Convenience function to obtain the value of
   * GTK_PRINT_SETTINGS_PRINTER.
   *
   * @return The printer name.
   */
  auto get_printer() const -> Glib::ustring;

  /** Convenience function to set GTK_PRINT_SETTINGS_PRINTER
   * to @a printer.
   *
   * @param printer The printer name.
   */
  void set_printer(const Glib::ustring& printer);


  /** Get the value of GTK_PRINT_SETTINGS_ORIENTATION,
   * converted to a `Gtk::PageOrientation`.
   *
   * @return The orientation.
   */
  auto get_orientation() const -> PageOrientation;

  /** Sets the value of GTK_PRINT_SETTINGS_ORIENTATION.
   *
   * @param orientation A page orientation.
   */
  void set_orientation(PageOrientation orientation);


  /** Gets the value of GTK_PRINT_SETTINGS_PAPER_FORMAT,
   * converted to a `Gtk::PaperSize`.
   *
   * @return The paper size.
   */
  auto get_paper_size() -> PaperSize;

  /** Gets the value of GTK_PRINT_SETTINGS_PAPER_FORMAT,
   * converted to a `Gtk::PaperSize`.
   *
   * @return The paper size.
   */
  auto get_paper_size() const -> const PaperSize;

  /** Sets the value of GTK_PRINT_SETTINGS_PAPER_FORMAT,
   * GTK_PRINT_SETTINGS_PAPER_WIDTH and
   * GTK_PRINT_SETTINGS_PAPER_HEIGHT.
   *
   * @param paper_size A paper size.
   */
  void set_paper_size(const PaperSize& paper_size);


  /** Gets the value of GTK_PRINT_SETTINGS_PAPER_WIDTH,
   * converted to @a unit.
   *
   * @param unit The unit for the return value.
   * @return The paper width, in units of @a unit.
   */
  auto get_paper_width(Unit unit) const -> double;

  /** Sets the value of GTK_PRINT_SETTINGS_PAPER_WIDTH.
   *
   * @param width The paper width.
   * @param unit The units of @a width.
   */
  void set_paper_width(double width, Unit unit);

  /** Gets the value of GTK_PRINT_SETTINGS_PAPER_HEIGHT,
   * converted to @a unit.
   *
   * @param unit The unit for the return value.
   * @return The paper height, in units of @a unit.
   */
  auto get_paper_height(Unit unit) const -> double;

  /** Sets the value of GTK_PRINT_SETTINGS_PAPER_HEIGHT.
   *
   * @param height The paper height.
   * @param unit The units of @a height.
   */
  void set_paper_height(double height, Unit unit);


  /** Gets the value of GTK_PRINT_SETTINGS_USE_COLOR.
   *
   * @return Whether to use color.
   */
  auto get_use_color() const -> bool;

  /** Sets the value of GTK_PRINT_SETTINGS_USE_COLOR.
   *
   * @param use_color Whether to use color.
   */
  void set_use_color(bool use_color =  true);


  /** Gets the value of GTK_PRINT_SETTINGS_COLLATE.
   *
   * @return Whether to collate the printed pages.
   */
  auto get_collate() const -> bool;

  /** Sets the value of GTK_PRINT_SETTINGS_COLLATE.
   *
   * @param collate Whether to collate the output.
   */
  void set_collate(bool collate =  true);


  /** Gets the value of GTK_PRINT_SETTINGS_REVERSE.
   *
   * @return Whether to reverse the order of the printed pages.
   */
  auto get_reverse() const -> bool;

  /** Sets the value of GTK_PRINT_SETTINGS_REVERSE.
   *
   * @param reverse Whether to reverse the output.
   */
  void set_reverse(bool reverse =  true);


  /** Gets the value of GTK_PRINT_SETTINGS_DUPLEX.
   *
   * @return Whether to print the output in duplex.
   */
  auto get_duplex() const -> PrintDuplex;

  /** Sets the value of GTK_PRINT_SETTINGS_DUPLEX.
   *
   * @param duplex A `Gtk::PrintDuplex` value.
   */
  void set_duplex(PrintDuplex duplex);


  /** Gets the value of GTK_PRINT_SETTINGS_QUALITY.
   *
   * @return The print quality.
   */
  auto get_quality() const -> PrintQuality;

  /** Sets the value of GTK_PRINT_SETTINGS_QUALITY.
   *
   * @param quality A `Gtk::PrintQuality` value.
   */
  void set_quality(PrintQuality quality);


  /** Gets the value of GTK_PRINT_SETTINGS_N_COPIES.
   *
   * @return The number of copies to print.
   */
  auto get_n_copies() const -> int;

  /** Sets the value of GTK_PRINT_SETTINGS_N_COPIES.
   *
   * @param num_copies The number of copies.
   */
  void set_n_copies(int num_copies);


  /** Gets the value of GTK_PRINT_SETTINGS_NUMBER_UP.
   *
   * @return The number of pages per sheet.
   */
  auto get_number_up() const -> int;

  /** Sets the value of GTK_PRINT_SETTINGS_NUMBER_UP.
   *
   * @param number_up The number of pages per sheet.
   */
  void set_number_up(int number_up);


  /** Gets the value of GTK_PRINT_SETTINGS_NUMBER_UP_LAYOUT.
   *
   * @return Layout of page in number-up mode.
   */
  auto get_number_up_layout() const -> NumberUpLayout;

  /** Sets the value of GTK_PRINT_SETTINGS_NUMBER_UP_LAYOUT.
   *
   * @param number_up_layout A `Gtk::NumberUpLayout` value.
   */
  void set_number_up(NumberUpLayout number_up_layout);


  /** Gets the value of GTK_PRINT_SETTINGS_RESOLUTION.
   *
   * @return The resolution in dpi.
   */
  auto get_resolution() const -> int;

  /** Sets the values of GTK_PRINT_SETTINGS_RESOLUTION,
   * GTK_PRINT_SETTINGS_RESOLUTION_X and
   * GTK_PRINT_SETTINGS_RESOLUTION_Y.
   *
   * @param resolution The resolution in dpi.
   */
  void set_resolution(int resolution);


  /** Gets the value of GTK_PRINT_SETTINGS_RESOLUTION_X.
   *
   * @return The horizontal resolution in dpi.
   */
  auto get_resolution_x() const -> int;

  /** Gets the value of GTK_PRINT_SETTINGS_RESOLUTION_Y.
   *
   * @return The vertical resolution in dpi.
   */
  auto get_resolution_y() const -> int;

  /** Sets the values of GTK_PRINT_SETTINGS_RESOLUTION,
   * GTK_PRINT_SETTINGS_RESOLUTION_X and
   * GTK_PRINT_SETTINGS_RESOLUTION_Y.
   *
   * @param resolution_x The horizontal resolution in dpi.
   * @param resolution_y The vertical resolution in dpi.
   */
  void set_resolution_xy(int resolution_x, int resolution_y);

  /** Gets the value of GTK_PRINT_SETTINGS_PRINTER_LPI.
   *
   * @return The resolution in lpi (lines per inch).
   */
  auto get_printer_lpi() const -> double;

  /** Sets the value of GTK_PRINT_SETTINGS_PRINTER_LPI.
   *
   * @param lpi The resolution in lpi (lines per inch).
   */
  void set_printer_lpi(double lpi);


  /** Gets the value of GTK_PRINT_SETTINGS_SCALE.
   *
   * @return The scale in percent.
   */
  auto get_scale() const -> double;

  /** Sets the value of GTK_PRINT_SETTINGS_SCALE.
   *
   * @param scale The scale in percent.
   */
  void set_scale(double scale);


  /** Gets the value of GTK_PRINT_SETTINGS_PRINT_PAGES.
   *
   * @return Which pages to print.
   */
  auto get_print_pages() const -> PrintPages;

  /** Sets the value of GTK_PRINT_SETTINGS_PRINT_PAGES.
   *
   * @param pages A `Gtk::PrintPages` value.
   */
  void set_print_pages(PrintPages pages);

  auto get_page_ranges() const -> std::vector<PageRange>;
  void set_page_ranges(const std::vector<PageRange>& page_ranges);


  /** Gets the value of GTK_PRINT_SETTINGS_PAGE_SET.
   *
   * @return The set of pages to print.
   */
  auto get_page_set() const -> PageSet;

  /** Sets the value of GTK_PRINT_SETTINGS_PAGE_SET.
   *
   * @param page_set A `Gtk::PageSet` value.
   */
  void set_page_set(PageSet page_set);


  /** Gets the value of GTK_PRINT_SETTINGS_DEFAULT_SOURCE.
   *
   * @return The default source.
   */
  auto get_default_source() const -> Glib::ustring;

  /** Sets the value of GTK_PRINT_SETTINGS_DEFAULT_SOURCE.
   *
   * @param default_source The default source.
   */
  void set_default_source(const Glib::ustring& default_source);


  /** Gets the value of GTK_PRINT_SETTINGS_MEDIA_TYPE.
   *
   * The set of media types is defined in PWG 5101.1-2002 PWG.
   *
   * @return The media type.
   */
  auto get_media_type() const -> Glib::ustring;

  /** Sets the value of GTK_PRINT_SETTINGS_MEDIA_TYPE.
   *
   * The set of media types is defined in PWG 5101.1-2002 PWG.
   *
   * @param media_type The media type.
   */
  void set_media_type(const Glib::ustring& media_type);


  /** Gets the value of GTK_PRINT_SETTINGS_DITHER.
   *
   * @return The dithering that is used.
   */
  auto get_dither() const -> Glib::ustring;

  /** Sets the value of GTK_PRINT_SETTINGS_DITHER.
   *
   * @param dither The dithering that is used.
   */
  void set_dither(const Glib::ustring& dither);


  /** Gets the value of GTK_PRINT_SETTINGS_FINISHINGS.
   *
   * @return The finishings.
   */
  auto get_finishings() const -> Glib::ustring;

  /** Sets the value of GTK_PRINT_SETTINGS_FINISHINGS.
   *
   * @param finishings The finishings.
   */
  void set_finishings(const Glib::ustring& finishings);


  /** Gets the value of GTK_PRINT_SETTINGS_OUTPUT_BIN.
   *
   * @return The output bin.
   */
  auto get_output_bin() const -> Glib::ustring;

  /** Sets the value of GTK_PRINT_SETTINGS_OUTPUT_BIN.
   *
   * @param output_bin The output bin.
   */
  void set_output_bin(const Glib::ustring& output_bin);

  //There are no properties.


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
   * @relates Gtk::PrintSettings
   */
  GTKMM_API
  auto wrap(GtkPrintSettings* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PrintSettings>;
}


#endif /* _GTKMM_PRINTSETTINGS_H */

