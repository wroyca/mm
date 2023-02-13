
#ifndef _GTKMM_PRINTJOB_H
#define _GTKMM_PRINTJOB_H


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

#include <mm/glib/object.hpp>
#include <mm/gtk/pagesetup.hpp>
#include <mm/gtk/printer.hpp>
#include <mm/gtk/printoperation.hpp>
#include <mm/gtk/printsettings.hpp>
#include <mm/cairo/surface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintJob = struct _GtkPrintJob;
using GtkPrintJobClass = struct _GtkPrintJobClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API PrintJob_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A PrintJob object represents a job that is sent to a printer. You only need to deal
 * directly with print jobs if you  use the non-portable PrintUnixDialog API.
 *
 * Use get_surface() to obtain the cairo surface onto which the pages must be drawn.
 * Use send() to send the finished job to the printer.If you don't use cairo then
 * PrintJob also supports printing of manually generated postscript, via set_source_file().
 *
 * @newin{2,10}
 *
 * @ingroup Printing
 */

class GTKMM_API PrintJob : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PrintJob;
  using CppClassType = PrintJob_Class;
  using BaseObjectType = GtkPrintJob;
  using BaseClassType = GtkPrintJobClass;

  // noncopyable
  PrintJob(const PrintJob&) = delete;
  auto operator=(const PrintJob&) -> PrintJob& = delete;

private:  friend class PrintJob_Class;
  static CppClassType printjob_class_;

protected:
  explicit PrintJob(const Glib::ConstructParams& construct_params);
  explicit PrintJob(GtkPrintJob* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PrintJob(PrintJob&& src) noexcept;
  auto operator=(PrintJob&& src) noexcept -> PrintJob&;

  ~PrintJob() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkPrintJob*       { return reinterpret_cast<GtkPrintJob*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPrintJob* { return reinterpret_cast<GtkPrintJob*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkPrintJob*;

private:

  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


protected:
    explicit PrintJob(const Glib::ustring& title, const Glib::RefPtr<Printer>& printer, const Glib::RefPtr<PrintSettings>& settings, const Glib::RefPtr<PageSetup>& page_setup);


public:

  static auto create(const Glib::ustring& title, const Glib::RefPtr<Printer>& printer, const Glib::RefPtr<PrintSettings>& settings, const Glib::RefPtr<PageSetup>& page_setup) -> Glib::RefPtr<PrintJob>;


  /** Gets the `Gtk::PrintSettings` of the print job.
   *
   * @return The settings of @a job.
   */
  auto get_settings() -> Glib::RefPtr<PrintSettings>;

  /** Gets the `Gtk::PrintSettings` of the print job.
   *
   * @return The settings of @a job.
   */
  auto get_settings() const -> Glib::RefPtr<const PrintSettings>;


  /** Gets the `Gtk::Printer` of the print job.
   *
   * @return The printer of @a job.
   */
  auto get_printer() -> Glib::RefPtr<Printer>;

  /** Gets the `Gtk::Printer` of the print job.
   *
   * @return The printer of @a job.
   */
  auto get_printer() const -> Glib::RefPtr<const Printer>;


  /** Gets the job title.
   *
   * @return The title of @a job.
   */
  auto get_title() const -> Glib::ustring;

  /** Gets the status of the print job.
   *
   * @return The status of @a job.
   */
  auto get_status() const -> PrintStatus;

  /** Make the `Gtk::PrintJob` send an existing document to the
   * printing system.
   *
   * The file can be in any format understood by the platforms
   * printing system (typically PostScript, but on many platforms
   * PDF may work too). See Gtk::Printer::accepts_pdf() and
   * Gtk::Printer::accepts_ps().
   *
   * @param filename The file to be printed.
   *
   * @throws Glib::Error
   */
  void set_source_file(const std::string& filename);


  /** Gets a cairo surface onto which the pages of
   * the print job should be rendered.
   *
   * @return The cairo surface of @a job.
   *
   * @throws Glib::Error
   */
  auto get_surface() -> Cairo::RefPtr<Cairo::Surface>;

  /** Gets a cairo surface onto which the pages of
   * the print job should be rendered.
   *
   * @return The cairo surface of @a job.
   *
   * @throws Glib::Error
   */
  auto get_surface() const -> Cairo::RefPtr<const Cairo::Surface>;


  /** If track_status is <tt>true</tt>, the print job will try to continue report
   * on the status of the print job in the printer queues and printer.
   *
   * This can allow your application to show things like “out of paper”
   * issues, and when the print job actually reaches the printer.
   *
   * This function is often implemented using some form of polling,
   * so it should not be enabled unless needed.
   *
   * @param track_status <tt>true</tt> to track status after printing.
   */
  void set_track_print_status(bool track_status =  true);

  /** Returns whether jobs will be tracked after printing.
   *
   * For details, see set_track_print_status().
   *
   * @return <tt>true</tt> if print job status will be reported after printing.
   */
  auto get_track_print_status() const -> bool;

  /** For example,
   * void on_print_job_complete(const Glib::RefPtr<PrintJob>& job);
   *
   * @throws exception
   */
  typedef sigc::slot<void(const Glib::RefPtr<PrintJob>&)> SlotPrintJobComplete;

  /** Sends the print job off to the printer.
   * @param slot A function to call when the job completes or an error occurs.
   */
  void send(const SlotPrintJobComplete& slot);


  /** Gets the `Gtk::PrintPages` setting for this job.
   *
   * @return The `Gtk::PrintPages` setting.
   */
  auto get_pages() const -> PrintPages;

  /** Sets the `Gtk::PrintPages` setting for this job.
   *
   * @param pages The `Gtk::PrintPages` setting.
   */
  void set_pages(PrintPages pages);

  auto get_page_ranges() const -> std::vector<PageRange>;


  void set_page_ranges(const std::vector<PageRange>& ranges);


  /** Gets the `Gtk::PageSet` setting for this job.
   *
   * @return The `Gtk::PageSet` setting.
   */
  auto get_page_set() const -> PageSet;

  /** Sets the `Gtk::PageSet` setting for this job.
   *
   * @param page_set A `Gtk::PageSet` setting.
   */
  void set_page_set(PageSet page_set);

  /** Gets the number of copies of this job.
   *
   * @return The number of copies.
   */
  auto get_num_copies() const -> int;

  /** Sets the number of copies for this job.
   *
   * @param num_copies The number of copies.
   */
  void set_num_copies(int num_copies);

  /** Gets the scale for this job.
   *
   * @return The scale.
   */
  auto get_scale() const -> double;

  /** Sets the scale for this job.
   *
   * 1.0 means unscaled.
   *
   * @param scale The scale.
   */
  void set_scale(double scale);

  /** Gets the n-up setting for this job.
   *
   * @return The n-up setting.
   */
  auto get_n_up() const -> guint;

  /** Sets the n-up setting for this job.
   *
   * @param n_up The n-up value.
   */
  void set_n_up(guint n_up);

  /** Gets the n-up layout setting for this job.
   *
   * @return The n-up layout.
   */
  auto get_n_up_layout() const -> NumberUpLayout;

  /** Sets the n-up layout setting for this job.
   *
   * @param layout The n-up layout setting.
   */
  void set_n_up_layout(NumberUpLayout layout);

  /** Gets whether the job is printed rotated.
   *
   * @return Whether the job is printed rotated.
   */
  auto get_rotate() const -> bool;

  /** Sets whether this job is printed rotated.
   *
   * @param rotate Whether to print rotated.
   */
  void set_rotate(bool rotate =  true);

  /** Gets whether this job is printed collated.
   *
   * @return Whether the job is printed collated.
   */
  auto get_collate() const -> bool;

  /** Sets whether this job is printed collated.
   *
   * @param collate Whether the job is printed collated.
   */
  void set_collate(bool collate =  true);

  /** Gets whether this job is printed reversed.
   *
   * @return Whether the job is printed reversed.
   */
  auto get_reverse() const -> bool;

  /** Sets whether this job is printed reversed.
   *
   * @param reverse Whether the job is printed reversed.
   */
  void set_reverse(bool reverse =  true);

  // no_default_handler because GtkPrintJobClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%status_changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the status of a job changes.
   *
   * The signal handler can use Gtk::PrintJob::get_status()
   * to obtain the new status.
   */

  auto signal_status_changed() -> Glib::SignalProxy<void()>;


  /** The title of the print job.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The printer to send the job to.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_printer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Printer> >;


  /** Printer settings.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_settings() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<PrintSettings> >;


  /** Page setup.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page_setup() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<PageSetup> >;


  /** <tt>true</tt> if the print job will continue to emit status-changed
   * signals after the print data has been setn to the printer.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_track_print_status() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if the print job will continue to emit status-changed
   * signals after the print data has been setn to the printer.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_track_print_status() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::PrintJob
   */
  GTKMM_API
  auto wrap(GtkPrintJob* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PrintJob>;
}


#endif /* _GTKMM_PRINTJOB_H */

