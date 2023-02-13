
#ifndef _GTKMM_PRINTER_H
#define _GTKMM_PRINTER_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gtk/pagesetup.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrinter = struct _GtkPrinter;
using GtkPrinterClass = struct _GtkPrinterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Printer_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API PaperSize;

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var PrintCapabilities PAGE_SET
 * Print dialog will offer printing even/odd pages.
 *
 *  @var PrintCapabilities COPIES
 * Print dialog will allow to print multiple copies.
 *
 *  @var PrintCapabilities COLLATE
 * Print dialog will allow to collate multiple copies.
 *
 *  @var PrintCapabilities REVERSE
 * Print dialog will allow to print pages in reverse order.
 *
 *  @var PrintCapabilities SCALE
 * Print dialog will allow to scale the output.
 *
 *  @var PrintCapabilities GENERATE_PDF
 * The program will send the document to
 * the printer in PDF format.
 *
 *  @var PrintCapabilities GENERATE_PS
 * The program will send the document to
 * the printer in Postscript format.
 *
 *  @var PrintCapabilities PREVIEW
 * Print dialog will offer a preview.
 *
 *  @var PrintCapabilities NUMBER_UP
 * Print dialog will offer printing multiple
 * pages per sheet.
 *
 *  @var PrintCapabilities NUMBER_UP_LAYOUT
 * Print dialog will allow to rearrange
 * pages when printing multiple pages per sheet.
 *
 *  @enum PrintCapabilities
 *
 * Specifies which features the print dialog should offer.
 *
 * If neither Gtk::PrintCapabilities::GENERATE_PDF nor
 * Gtk::PrintCapabilities::GENERATE_PS is specified, GTK assumes that all
 * formats are supported.
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>PrintCapabilities operator|(PrintCapabilities, PrintCapabilities)</tt><br>
 * <tt>PrintCapabilities operator&(PrintCapabilities, PrintCapabilities)</tt><br>
 * <tt>PrintCapabilities operator^(PrintCapabilities, PrintCapabilities)</tt><br>
 * <tt>PrintCapabilities operator~(PrintCapabilities)</tt><br>
 * <tt>PrintCapabilities& operator|=(PrintCapabilities&, PrintCapabilities)</tt><br>
 * <tt>PrintCapabilities& operator&=(PrintCapabilities&, PrintCapabilities)</tt><br>
 * <tt>PrintCapabilities& operator^=(PrintCapabilities&, PrintCapabilities)</tt><br>
 */
enum class PrintCapabilities
{
  PAGE_SET = 1 << 0,
  COPIES = 1 << 1,
  COLLATE = 1 << 2,
  REVERSE = 1 << 3,
  SCALE = 1 << 4,
  GENERATE_PDF = 1 << 5,
  GENERATE_PS = 1 << 6,
  PREVIEW = 1 << 7,
  NUMBER_UP = 1 << 8,
  NUMBER_UP_LAYOUT = 1 << 9
};

/** @ingroup gtkmmEnums */
inline auto operator|(PrintCapabilities lhs, PrintCapabilities rhs) -> PrintCapabilities
  { return static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(PrintCapabilities lhs, PrintCapabilities rhs) -> PrintCapabilities
  { return static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(PrintCapabilities lhs, PrintCapabilities rhs) -> PrintCapabilities
  { return static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(PrintCapabilities flags) -> PrintCapabilities
  { return static_cast<PrintCapabilities>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(PrintCapabilities& lhs, PrintCapabilities rhs) -> PrintCapabilities&
  { return (lhs = static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(PrintCapabilities& lhs, PrintCapabilities rhs) -> PrintCapabilities&
  { return (lhs = static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(PrintCapabilities& lhs, PrintCapabilities rhs) -> PrintCapabilities&
  { return (lhs = static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PrintCapabilities> : public Glib::Value_Flags<Gtk::PrintCapabilities>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** A Printer object represents a printer. You only need to deal directly with printers if you use the
 * non-portable PrintUnixDialog API.
 *
 * A Printer object allows to get status information about the printer, such as its description, its location,
 * the number of queued jobs, etc. Most importantly, a Printer object can be used to create a PrintJob object,
 * which lets you print to the printer.
 *
 * @newin{2,10}
 *
 * @ingroup Printing
 */

class GTKMM_API Printer : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Printer;
  using CppClassType = Printer_Class;
  using BaseObjectType = GtkPrinter;
  using BaseClassType = GtkPrinterClass;

  // noncopyable
  Printer(const Printer&) = delete;
  auto operator=(const Printer&) -> Printer& = delete;

private:  friend class Printer_Class;
  static CppClassType printer_class_;

protected:
  explicit Printer(const Glib::ConstructParams& construct_params);
  explicit Printer(GtkPrinter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Printer(Printer&& src) noexcept;
  auto operator=(Printer&& src) noexcept -> Printer&;

  ~Printer() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkPrinter*       { return reinterpret_cast<GtkPrinter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPrinter* { return reinterpret_cast<GtkPrinter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkPrinter*;

private:

  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


public:
  auto equal(const Glib::RefPtr<Printer>& other) const -> bool;

  //GtkPrintBackend is in a "semi-private" header.
  //_WRAP_METHOD(Glib::RefPtr<PrintBackend> get_backend(), gtk_printer_get_backend, refreturn)
  //_WRAP_METHOD(Glib::RefPtr<const PrintBackend> get_backend() const, gtk_printer_get_backend, refreturn, constversion)


  /** Returns the name of the printer.
   *
   * @return The name of @a printer.
   */
  auto get_name() const -> Glib::ustring;

  /** Returns the state message describing the current state
   * of the printer.
   *
   * @return The state message of @a printer.
   */
  auto get_state_message() const -> Glib::ustring;

  /** Gets the description of the printer.
   *
   * @return The description of @a printer.
   */
  auto get_description() const -> Glib::ustring;

  /** Returns a description of the location of the printer.
   *
   * @return The location of @a printer.
   */
  auto get_location() const -> Glib::ustring;

  /** Gets the name of the icon to use for the printer.
   *
   * @return The icon name for @a printer.
   */
  auto get_icon_name() const -> Glib::ustring;

  /** Gets the number of jobs currently queued on the printer.
   *
   * @return The number of jobs on @a printer.
   */
  auto get_job_count() const -> int;

  /** Returns whether the printer is currently active (i.e.\ accepts new jobs).
   *
   * @return <tt>true</tt> if @a printer is active.
   */
  auto is_active() const -> bool;

  /** Returns whether the printer is currently paused.
   *
   * A paused printer still accepts jobs, but it is not
   * printing them.
   *
   * @return <tt>true</tt> if @a printer is paused.
   */
  auto is_paused() const -> bool;

  /** Returns whether the printer is accepting jobs
   *
   * @return <tt>true</tt> if @a printer is accepting jobs.
   */
  auto is_accepting_jobs() const -> bool;

  /** Returns whether the printer is virtual (i.e.\ does not
   * represent actual printer hardware, but something like
   * a CUPS class).
   *
   * @return <tt>true</tt> if @a printer is virtual.
   */
  auto is_virtual() const -> bool;

  /** Returns whether the printer is the default printer.
   *
   * @return <tt>true</tt> if @a printer is the default.
   */
  auto is_default() const -> bool;

  /** Returns whether the printer accepts input in
   * PDF format.
   *
   * @return <tt>true</tt> if @a printer accepts PDF.
   */
  auto accepts_pdf() const -> bool;

  /** Returns whether the printer accepts input in
   * PostScript format.
   *
   * @return <tt>true</tt> if @a printer accepts PostScript.
   */
  auto accepts_ps() const -> bool;


  /** Lists all the paper sizes @a printer supports.
   *
   * This will return and empty list unless the printer’s details
   * are available, see has_details() and
   * request_details().
   *
   * @return A newly
   * allocated list of newly allocated `Gtk::PageSetup`s.
   */
  auto list_papers() -> std::vector< Glib::RefPtr<PageSetup> >;


  /** Returns default page size of @a printer.
   *
   * @return A newly allocated `Gtk::PageSetup` with default page size
   * of the printer.
   */
  auto get_default_page_size() const -> Glib::RefPtr<PageSetup>;


  /** Lists all the paper sizes @a printer supports.
   *
   * This will return and empty list unless the printer’s details
   * are available, see has_details() and
   * request_details().
   *
   * @return A newly
   * allocated list of newly allocated `Gtk::PageSetup`s.
   */
  auto list_papers() const -> std::vector< Glib::RefPtr<const PageSetup> >;


  /** Returns whether the printer details are available.
   *
   * @return <tt>true</tt> if @a printer details are available.
   */
  auto has_details() const -> bool;

  /** Requests the printer details. When the details are available,
   * the details_acquired signal will be emitted.
   *
   * @newin{2,12}
   */
  void request_details();

  /** Returns the printer’s capabilities.
   *
   * This is useful when you’re using `Gtk::PrintUnixDialog`’s
   * manual-capabilities setting and need to know which settings
   * the printer can handle and which you must handle yourself.
   *
   * This will return 0 unless the printer’s details are
   * available, see has_details() and
   * request_details().
   *
   * @return The printer’s capabilities.
   */
  auto get_capabilities() const -> PrintCapabilities;

  /** Retrieve the hard margins of @a printer.
   *
   * These are the margins that define the area at the borders
   * of the paper that the printer cannot print to.
   *
   * @note This will not succeed unless the printer’s details are
   * available, see has_details() and
   * request_details().
   *
   * @param top A location to store the top margin in.
   * @param bottom A location to store the bottom margin in.
   * @param left A location to store the left margin in.
   * @param right A location to store the right margin in.
   * @return <tt>true</tt> iff the hard margins were retrieved.
   */
  auto get_hard_margins(double& top, double& bottom, double& left, double& right) const -> bool;

  /** Retrieve the hard margins of @a printer for @a paper_size.
   *
   * These are the margins that define the area at the borders
   * of the paper that the printer cannot print to.
   *
   * @note This will not succeed unless the printer’s details are
   * available, see has_details() and
   * request_details().
   *
   * @param paper_size A `Gtk::PaperSize`.
   * @param top A location to store the top margin in.
   * @param bottom A location to store the bottom margin in.
   * @param left A location to store the left margin in.
   * @param right A location to store the right margin in.
   * @return <tt>true</tt> iff the hard margins were retrieved.
   */
  auto get_hard_margins(const PaperSize& paper_size, double& top, double& bottom, double& left, double& right) const -> bool;

  // no_default_handler because GtkPrinterClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%details_acquired(bool success)</tt>
   *
   * Flags: Run Last
   *
   * Emitted in response to a request for detailed information
   * about a printer from the print backend.
   *
   * The @a success parameter indicates if the information was
   * actually obtained.
   *
   * @param success <tt>true</tt> if the details were successfully acquired.
   */

  auto signal_details_acquired() -> Glib::SignalProxy<void(bool)>;


  /** The name of the printer.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** <tt>false</tt> if this represents a real hardware device.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_virtual() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** String giving the current status of the printer.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_state_message() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Information about the location of the printer.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_location() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Icon name to use for the printer.
   *
   * Default value: "printer"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Number of jobs queued in the printer.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_job_count() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** <tt>true</tt> if this printer can accept PDF.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accepts_pdf() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** <tt>true</tt> if this printer can accept PostScript.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accepts_ps() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** <tt>true</tt> if this printer is paused.
   *
   * A paused printer still accepts jobs, but it does
   * not print them.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paused() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** <tt>true</tt> if the printer is accepting jobs.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accepting_jobs() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** @relates Gtk::Printer */
inline auto operator==(const Glib::RefPtr<Printer>& lhs, const Glib::RefPtr<Printer>& rhs) -> bool
  { return lhs->equal(rhs); }

/** @relates Gtk::Printer */
inline auto operator!=(const Glib::RefPtr<Printer>& lhs, const Glib::RefPtr<Printer>& rhs) -> bool
  { return !lhs->equal(rhs); }

/** For example,
 * bool on_enumerate_printers(const Glib::RefPtr<Printer>& printer);
 * @param printer A printer.
 * @param result true to stop the enumeration, false to continue.
 *
 * @relates Gtk::Printer
 */
typedef sigc::slot<bool(const Glib::RefPtr<Printer>&)> SlotPrinterEnumerator;

/** Calls a function for all Printers. If the callback returns true, the enumeration is stopped.
 * @param slot A function to call for each printer
 * @param wait If true, wait in a recursive mainloop until all printers are enumerated; otherwise return early.
 *
 * @relates Gtk::Printer
 */
GTKMM_API
void enumerate_printers(const SlotPrinterEnumerator& slot, bool wait = true);

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Printer
   */
  GTKMM_API
  auto wrap(GtkPrinter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Printer>;
}


#endif /* _GTKMM_PRINTER_H */

