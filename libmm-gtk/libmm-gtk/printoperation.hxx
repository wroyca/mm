
#ifndef _GTKMM_PRINTOPERATION_H
#define _GTKMM_PRINTOPERATION_H


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

#include <libmm-glib/object.hxx>

#include <libmm-gtk/pagesetup.hxx>
#include <libmm-gtk/printcontext.hxx>
#include <libmm-gtk/printoperationpreview.hxx>
#include <libmm-gtk/printsettings.hxx>
#include <libmm-gtk/window.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintOperation = struct _GtkPrintOperation;
using GtkPrintOperationClass = struct _GtkPrintOperationClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API PrintOperation_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var PrintStatus INITIAL
 * The printing has not started yet; this
 * status is set initially, and while the print dialog is shown.
 *
 *  @var PrintStatus PREPARING
 * This status is set while the begin-print
 * signal is emitted and during pagination.
 *
 *  @var PrintStatus GENERATING_DATA
 * This status is set while the
 * pages are being rendered.
 *
 *  @var PrintStatus SENDING_DATA
 * The print job is being sent off to the
 * printer.
 *
 *  @var PrintStatus PENDING
 * The print job has been sent to the printer,
 * but is not printed for some reason, e.g. the printer may be stopped.
 *
 *  @var PrintStatus PENDING_ISSUE
 * Some problem has occurred during
 * printing, e.g. a paper jam.
 *
 *  @var PrintStatus PRINTING
 * The printer is processing the print job.
 *
 *  @var PrintStatus FINISHED
 * The printing has been completed successfully.
 *
 *  @var PrintStatus FINISHED_ABORTED
 * The printing has been aborted.
 *
 *  @enum PrintStatus
 *
 * The status gives a rough indication of the completion of a running
 * print operation.
 *
 * @ingroup gtkmmEnums
 */
enum class PrintStatus
{
  INITIAL,
  PREPARING,
  GENERATING_DATA,
  SENDING_DATA,
  PENDING,
  PENDING_ISSUE,
  PRINTING,
  FINISHED,
  FINISHED_ABORTED
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PrintStatus> : public Glib::Value_Enum<Gtk::PrintStatus>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

class PrintError : public Glib::Error
{
public:
  /**  @var Code GENERAL
   * An unspecified error occurred.
   *
   *  @var Code INTERNAL_ERROR
   * An internal error occurred.
   *
   *  @var Code NOMEM
   * A memory allocation failed.
   *
   *  @var Code INVALID_FILE
   * An error occurred while loading a page setup
   * or paper size from a key file.
   *
   *  @enum Code
   *
   * %Error codes that identify various errors that can occur while
   * using the GTK printing support.
   */
  enum Code
  {
    GENERAL,
    INTERNAL_ERROR,
    NOMEM,
    INVALID_FILE
  };

  GTKMM_API PrintError(Code error_code, const Glib::ustring& error_message);
  GTKMM_API explicit PrintError(GError* gobject);
  GTKMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GTKMM_API static void throw_func(GError* gobject);

  friend GTKMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PrintError::Code> : public Glib::Value_Enum<Gtk::PrintError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** @defgroup Printing Printing
 */

/** PrintOperation is the high-level, portable printing API. It looks a bit different than other
 * GTK+ dialogs such as the FileChooser, since some platforms don't expose enough infrastructure
 * to implement a good print dialog. On such platforms, PrintOperation uses the native print
 * dialog. On platforms which do not provide a native print dialog, GTK+ uses its own, see PrintUnixDialog.
 *
 * The typical way to use the high-level printing API is to create a PrintOperation object
 * when the user chooses to print. Then you set some properties on it,such as the page size, any PrintSettings
 * from previous print operations, the number of  pages, the current page, etc.
 *
 * Then you start the print operation by calling run(). It will then show a dialog to
 * let the user select a printer and options. When the user finishes the dialog various signals will be
 * emitted by the PrintOperation for you to handle, the main one being draw_page. You should then
 * render the page on the provided PrintContext using Cairo.
 *
 * @newin{2,10}
 *
 * @ingroup Printing
 */

class GTKMM_API PrintOperation :
  public Glib::Object,
  public PrintOperationPreview
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PrintOperation;
  using CppClassType = PrintOperation_Class;
  using BaseObjectType = GtkPrintOperation;
  using BaseClassType = GtkPrintOperationClass;

  // noncopyable
  PrintOperation(const PrintOperation&) = delete;
  auto operator=(const PrintOperation&) -> PrintOperation& = delete;

private:  friend class PrintOperation_Class;
  static CppClassType printoperation_class_;

protected:
  explicit PrintOperation(const Glib::ConstructParams& construct_params);
  explicit PrintOperation(GtkPrintOperation* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PrintOperation(PrintOperation&& src) noexcept;
  auto operator=(PrintOperation&& src) noexcept -> PrintOperation&;

  ~PrintOperation() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkPrintOperation*       { return reinterpret_cast<GtkPrintOperation*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPrintOperation* { return reinterpret_cast<GtkPrintOperation*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkPrintOperation*;

private:


protected:

  PrintOperation();

public:
  /**
   *  @var Result ERROR
   * An error has occurred.
   *
   *  @var Result APPLY
   * The print settings should be stored.
   *
   *  @var Result CANCEL
   * The print operation has been canceled,
   * the print settings should not be stored.
   *
   *  @var Result IN_PROGRESS
   * The print operation is not complete
   * yet. This value will only be returned when running asynchronously.
   *
   *  @enum Result
   *
   * The result of a print operation.
   *
   * A value of this type is returned by Gtk::PrintOperation::run().
   *
   * @ingroup gtkmmEnums
   */
  enum class Result
  {
    ERROR,
    APPLY,
    CANCEL,
    IN_PROGRESS
  };


  /**
   *  @var Action PRINT_DIALOG
   * Show the print dialog.
   *
   *  @var Action PRINT
   * Start to print without showing
   * the print dialog, based on the current print settings.
   *
   *  @var Action PREVIEW
   * Show the print preview.
   *
   *  @var Action EXPORT
   * Export to a file. This requires
   * the export-filename property to be set.
   *
   *  @enum Action
   *
   * Determines what action the print operation should perform.
   *
   * A parameter of this typs is passed to Gtk::PrintOperation::run().
   *
   * @ingroup gtkmmEnums
   */
  enum class Action
  {
    PRINT_DIALOG,
    PRINT,
    PREVIEW,
    EXPORT
  };


  static auto create() -> Glib::RefPtr<PrintOperation>;


  /** Makes @a default_page_setup the default page setup for @a op.
   *
   * This page setup will be used by run(),
   * but it can be overridden on a per-page basis by connecting
   * to the signal_request_page_setup() signal.
   *
   * @param default_page_setup A `Gtk::PageSetup`.
   */
  void set_default_page_setup(const Glib::RefPtr<PageSetup>& default_page_setup);


  /** Returns the default page setup.
   *
   * @return The default page setup.
   */
  auto get_default_page_setup() -> Glib::RefPtr<PageSetup>;

  /** Returns the default page setup.
   *
   * @return The default page setup.
   */
  auto get_default_page_setup() const -> Glib::RefPtr<const PageSetup>;


  /** Sets the print settings for @a op.
   *
   * This is typically used to re-establish print settings
   * from a previous print operation, see run().
   *
   * @param print_settings `Gtk::PrintSettings`.
   */
  void set_print_settings(const Glib::RefPtr<PrintSettings>& print_settings);


  /** Returns the current print settings.
   *
   * Note that the return value is <tt>nullptr</tt> until either
   * set_print_settings() or
   * run() have been called.
   *
   * @return The current print settings of @a op.
   */
  auto get_print_settings() -> Glib::RefPtr<PrintSettings>;

  /** Returns the current print settings.
   *
   * Note that the return value is <tt>nullptr</tt> until either
   * set_print_settings() or
   * run() have been called.
   *
   * @return The current print settings of @a op.
   */
  auto get_print_settings() const -> Glib::RefPtr<const PrintSettings>;


  /** Sets the name of the print job.
   *
   * The name is used to identify the job (e.g. in monitoring
   * applications like eggcups).
   *
   * If you don’t set a job name, GTK picks a default one by
   * numbering successive print jobs.
   *
   * @param job_name A string that identifies the print job.
   */
  void set_job_name(const Glib::ustring& job_name);

  /** Sets the number of pages in the document.
   *
   * This must be set to a positive number before the rendering
   * starts. It may be set in a signal_begin_print()
   * signal handler.
   *
   * Note that the page numbers passed to the
   * signal_request_page_setup()
   * and signal_draw_page() signals are 0-based, i.e.
   * if the user chooses to print all pages, the last signal_draw_page() signal
   * will be for page @a n_pages - 1.
   *
   * @param n_pages The number of pages.
   */
  void set_n_pages(int n_pages);

  /** Sets the current page.
   *
   * If this is called before run(),
   * the user will be able to select to print only the current page.
   *
   * Note that this only makes sense for pre-paginated documents.
   *
   * @param current_page The current page, 0-based.
   */
  void set_current_page(int current_page);

  /** If @a use_full_page is <tt>true</tt>, the transformation for the cairo context
   * obtained from `Gtk::PrintContext` puts the origin at the top left
   * corner of the page.
   *
   * This may not be the top left corner of the sheet, depending on page
   * orientation and the number of pages per sheet). Otherwise, the origin
   * is at the top left corner of the imageable area (i.e. inside the margins).
   *
   * @param use_full_page <tt>true</tt> to set up the `Gtk::PrintContext` for the full page.
   */
  void set_use_full_page(bool use_full_page =  true);

  /** Sets up the transformation for the cairo context obtained from
   * `Gtk::PrintContext` in such a way that distances are measured in
   * units of @a unit.
   *
   * @param unit The unit to use.
   */
  void set_unit(Unit unit);

  /** Sets up the `Gtk::PrintOperation` to generate a file instead
   * of showing the print dialog.
   *
   * The intended use of this function is for implementing
   * “Export to PDF” actions. Currently, PDF is the only supported
   * format.
   *
   * “Print to PDF” support is independent of this and is done
   * by letting the user pick the “Print to PDF” item from the list
   * of printers in the print dialog.
   *
   * @param filename The filename for the exported file.
   */
  void set_export_filename(const std::string& filename);

  /** If track_status is <tt>true</tt>, the print operation will try to continue
   * report on the status of the print job in the printer queues and printer.
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

  /** If @a show_progress is <tt>true</tt>, the print operation will show
   * a progress dialog during the print operation.
   *
   * @param show_progress <tt>true</tt> to show a progress dialog.
   */
  void set_show_progress(bool show_progress =  true);

  /** Sets whether run() may return
   * before the print operation is completed.
   *
   * Note that some platforms may not allow asynchronous
   * operation.
   *
   * @param allow_async <tt>true</tt> to allow asynchronous operation.
   */
  void set_allow_async(bool allow_async =  true);

  /** Sets the label for the tab holding custom widgets.
   *
   * @param label The label to use, or <tt>nullptr</tt> to use the default label.
   */
  void set_custom_tab_label(const Glib::ustring& label);


  /** See the run() method that takes both action and parent parameters.
   */
  auto run(Action action = Action::PRINT_DIALOG) -> Result;


  /** Runs the print operation.
   *
   * Normally that this function does not return until the rendering
   * of all pages is complete. You can connect to the
   * signal_status_changed() signal on @a op to obtain
   * some information about the progress of the print operation.
   *
   * Furthermore, it may use a recursive mainloop to show the print dialog.
   *
   * If you set the [Gtk.PrintOperation:allow-async] property, the operation
   * will run asynchronously if this is supported on the platform. The
   * signal_done() signal will be emitted with the result
   * of the operation when the it is done (i.e. when the dialog is canceled,
   * or when the print succeeds or fails).
   *
   *
   * [C example ellipted]
   *
   * Note that run() can only be called once on a
   * given `Gtk::PrintOperation`.
   *
   * @param action The action to start.
   * @param parent Transient parent of the dialog.
   * @return The result of the print operation. A return value of
   * Gtk::PrintOperation::Result::APPLY indicates that the printing was
   * completed successfully. In this case, it is a good idea to obtain
   * the used print settings with
   * get_print_settings()
   * and store them for reuse with the next print operation. A value of
   * Gtk::PrintOperation::Result::IN_PROGRESS means the operation is running
   * asynchronously, and will emit the signal_done()
   * signal when done.
   *
   * @throws Glib::Error
   */
  auto run(Action action, Window& parent) -> Result;


  /** Returns the status of the print operation.
   *
   * Also see get_status_string().
   *
   * @return The status of the print operation.
   */
  auto get_status() const -> PrintStatus;

  /** Returns a string representation of the status of the
   * print operation.
   *
   * The string is translated and suitable for displaying
   * the print status e.g. in a `Gtk::Statusbar`.
   *
   * Use get_status() to obtain
   * a status value that is suitable for programmatic use.
   *
   * @return A string representation of the status
   * of the print operation.
   */
  auto get_status_string() const -> Glib::ustring;

  /** Cancels a running print operation.
   *
   * This function may be called from a signal_begin_print(),
   * signal_paginate() or signal_draw_page()
   * signal handler to stop the currently running print operation.
   */
  void cancel();

  /** A convenience function to find out if the print operation
   * is finished.
   *
   * a print operation is finished if its status is either
   * Gtk::PrintStatus::FINISHED or Gtk::PrintStatus::FINISHED_ABORTED.
   *
   * @note when you enable print status tracking the print operation
   * can be in a non-finished state even after done has been called, as
   * the operation status then tracks the print job status on the printer.
   *
   * @return <tt>true</tt>, if the print operation is finished.
   */
  auto is_finished() const -> bool;


  /** Signal that drawing of particular page is complete.
   *
   * It is called after completion of page drawing (e.g. drawing
   * in another thread). If set_defer_drawing()
   * was called before, then this function has to be called by application.
   * Otherwise it is called by GTK itself.
   */
  void draw_page_finish();

  /** Sets up the `Gtk::PrintOperation` to wait for calling of
   * [method @a Gtk.PrintOperation.draw_page_finish from application.
   *
   * This can be used for drawing page in another thread.
   *
   * This function must be called in the callback of the
   * signal_draw_page() signal.
   */
  void set_defer_drawing();


  /** Sets whether selection is supported by `Gtk::PrintOperation`.
   *
   * @param support_selection <tt>true</tt> to support selection.
   */
  void set_support_selection(bool support_selection =  true);

  /** Gets whether the application supports print of selection
   *
   * @return Whether the application supports print of selection.
   */
  auto get_support_selection() const -> bool;

  /** Sets whether there is a selection to print.
   *
   * Application has to set number of pages to which the selection
   * will draw by set_n_pages() in a handler
   * for the signal_begin_print() signal.
   *
   * @param has_selection <tt>true</tt> indicates that a selection exists.
   */
  void set_has_selection(bool has_selection =  true);

  /** Gets whether there is a selection.
   *
   * @return Whether there is a selection.
   */
  auto get_has_selection() const -> bool;


  /** Embed page size combo box and orientation combo box into page setup page.
   *
   * Selected page setup is stored as default page setup in `Gtk::PrintOperation`.
   *
   * @param embed <tt>true</tt> to embed page setup selection in the `Gtk::PrintUnixDialog`.
   */
  void set_embed_page_setup(bool embed =  true);

  /** Gets whether page setup selection combos are embedded
   *
   * @return Whether page setup selection combos are embedded.
   */
  auto get_embed_page_setup() const -> bool;

  /** Returns the number of pages that will be printed.
   *
   * Note that this value is set during print preparation phase
   * (Gtk::PrintStatus::PREPARING), so this function should never be
   * called before the data generation phase (Gtk::PrintStatus::GENERATING_DATA).
   * You can connect to the signal_status_changed()
   * signal and call get_n_pages_to_print() when
   * print status is Gtk::PrintStatus::GENERATING_DATA.
   *
   * This is typically used to track the progress of print operation.
   *
   * @return The number of pages that will be printed.
   */
  auto get_n_pages_to_print() const -> int;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%done(Result result)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the print operation run has finished doing
   * everything required for printing.
   *
   *  @a result gives you information about what happened during the run.
   * If @a result is Gtk::PrintOperation::Result::ERROR then you can call
   * Gtk::PrintOperation::get_error() for more information.
   *
   * If you enabled print status tracking then
   * Gtk::PrintOperation::is_finished() may still return <tt>false</tt>
   * after the signal_done() signal was emitted.
   *
   * @param result The result of the print operation.
   */

  auto signal_done() -> Glib::SignalProxy<void(Result)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%begin_print(const Glib::RefPtr<PrintContext>& context)</tt>
   *
   * Flags: Run Last
   *
   * Emitted after the user has finished changing print settings
   * in the dialog, before the actual rendering starts.
   *
   * A typical use for signal_begin_print() is to use the parameters from the
   * Gtk::PrintContext and paginate the document accordingly,
   * and then set the number of pages with
   * Gtk::PrintOperation::set_n_pages().
   *
   * @param context The `Gtk::PrintContext` for the current operation.
   */

  auto signal_begin_print() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%paginate(const Glib::RefPtr<PrintContext>& context)</tt>
   *
   * Flags: Run Last
   *
   * Emitted after the signal_begin_print() signal, but before the actual rendering
   * starts.
   *
   * It keeps getting emitted until a connected signal handler returns <tt>true</tt>.
   *
   * The signal_paginate() signal is intended to be used for paginating a document
   * in small chunks, to avoid blocking the user interface for a long
   * time. The signal handler should update the number of pages using
   * Gtk::PrintOperation::set_n_pages(), and return <tt>true</tt> if the document
   * has been completely paginated.
   *
   * If you don't need to do pagination in chunks, you can simply do
   * it all in the signal_begin_print() handler, and set the number of pages
   * from there.
   *
   * @param context The `Gtk::PrintContext` for the current operation.
   * @return <tt>true</tt> if pagination is complete.
   */

  auto signal_paginate() -> Glib::SignalProxy<bool(const Glib::RefPtr<PrintContext>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%request_page_setup(const Glib::RefPtr<PrintContext>& context, int page_no, const Glib::RefPtr<PageSetup>& setup)</tt>
   *
   * Flags: Run Last
   *
   * Emitted once for every page that is printed.
   *
   * This gives the application a chance to modify the page setup.
   * Any changes done to @a setup will be in force only for printing
   * this page.
   *
   * @param context The `Gtk::PrintContext` for the current operation.
   * @param page_no The number of the currently printed page (0-based).
   * @param setup The `Gtk::PageSetup`.
   */

  auto signal_request_page_setup() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&, int, const Glib::RefPtr<PageSetup>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%draw_page(const Glib::RefPtr<PrintContext>& context, int page_nr)</tt>
   *
   * Flags: Run Last
   *
   * Emitted for every page that is printed.
   *
   * The signal handler must render the @a page_nr's page onto the cairo
   * context obtained from @a context using
   * Gtk::PrintContext::get_cairo_context().
   *
   *
   * [C example ellipted]
   *
   * Use Gtk::PrintOperation::set_use_full_page() and
   * Gtk::PrintOperation::set_unit() before starting the print
   * operation to set up the transformation of the cairo context
   * according to your needs.
   *
   * @param context The `Gtk::PrintContext` for the current operation.
   * @param page_nr The number of the currently printed page (0-based).
   */

  auto signal_draw_page() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&, int)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%end_print(const Glib::RefPtr<PrintContext>& context)</tt>
   *
   * Flags: Run Last
   *
   * Emitted after all pages have been rendered.
   *
   * A handler for this signal can clean up any resources that have
   * been allocated in the signal_begin_print() handler.
   *
   * @param context The `Gtk::PrintContext` for the current operation.
   */

  auto signal_end_print() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%status_changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted at between the various phases of the print operation.
   *
   * See Gtk::PrintStatus for the phases that are being discriminated.
   * Use Gtk::PrintOperation::get_status() to find out the current
   * status.
   */

  auto signal_status_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>Widget* on_my_%create_custom_widget()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when displaying the print dialog.
   *
   * If you return a widget in a handler for this signal it will be
   * added to a custom tab in the print dialog. You typically return a
   * container widget with multiple widgets in it.
   *
   * The print dialog owns the returned widget, and its lifetime is not
   * controlled by the application. However, the widget is guaranteed
   * to stay around until the signal_custom_widget_apply()
   * signal is emitted on the operation. Then you can read out any
   * information you need from the widgets.
   *
   * @return A custom widget that gets embedded in
   * the print dialog.
   */

  auto signal_create_custom_widget() -> Glib::SignalProxy<Widget*()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%custom_widget_apply(Widget* widget)</tt>
   *
   * Flags: Run Last
   *
   * Emitted right before signal_begin_print() if you added
   * a custom widget in the signal_create_custom_widget() handler.
   *
   * When you get this signal you should read the information from the
   * custom widgets, as the widgets are not guaranteed to be around at a
   * later time.
   *
   * @param widget The custom widget added in signal_create_custom_widget().
   */

  auto signal_custom_widget_apply() -> Glib::SignalProxy<void(Widget*)>;


  //TODO: This is causing crashes. Is it still causing crashes? murrayc.

  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%preview(const Glib::RefPtr<PrintOperationPreview>& preview, const Glib::RefPtr<PrintContext>& context, Window* parent)</tt>
   *
   * Flags: Run Last
   *
   * Gets emitted when a preview is requested from the native dialog.
   *
   * The default handler for this signal uses an external viewer
   * application to preview.
   *
   * To implement a custom print preview, an application must return
   * <tt>true</tt> from its handler for this signal. In order to use the
   * provided @a context for the preview implementation, it must be
   * given a suitable cairo context with
   * Gtk::PrintContext::set_cairo_context().
   *
   * The custom preview implementation can use
   * Gtk::PrintOperationPreview::is_selected() and
   * Gtk::PrintOperationPreview::render_page() to find pages which
   * are selected for print and render them. The preview must be
   * finished by calling Gtk::PrintOperationPreview::end_preview()
   * (typically in response to the user clicking a close button).
   *
   * @param preview The `Gtk::PrintOperationPreview` for the current operation.
   * @param context The `Gtk::PrintContext` that will be used.
   * @param parent The `Gtk::Window` to use as window parent.
   * @return <tt>true</tt> if the listener wants to take over control of the preview.
   */

  auto signal_preview() -> Glib::SignalProxy<bool(const Glib::RefPtr<PrintOperationPreview>&, const Glib::RefPtr<PrintContext>&, Window*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%update_custom_widget(Widget* widget, const Glib::RefPtr<PageSetup>& setup, const Glib::RefPtr<PrintSettings>& settings)</tt>
   *
   * Flags: Run Last
   *
   * Emitted after change of selected printer.
   *
   * The actual page setup and print settings are passed to the custom
   * widget, which can actualize itself according to this change.
   *
   * @param widget The custom widget added in signal_create_custom_widget().
   * @param setup Actual page setup.
   * @param settings Actual print settings.
   */

  auto signal_update_custom_widget() -> Glib::SignalProxy<void(Widget*, const Glib::RefPtr<PageSetup>&, const Glib::RefPtr<PrintSettings>&)>;


  /** The `Gtk::PageSetup` used by default.
   *
   * This page setup will be used by Gtk::PrintOperation::run(),
   * but it can be overridden on a per-page basis by connecting
   * to the signal_request_page_setup() signal.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_page_setup() -> Glib::PropertyProxy< Glib::RefPtr<PageSetup> > ;

/** The `Gtk::PageSetup` used by default.
   *
   * This page setup will be used by Gtk::PrintOperation::run(),
   * but it can be overridden on a per-page basis by connecting
   * to the signal_request_page_setup() signal.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_page_setup() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<PageSetup> >;

  /** The `Gtk::PrintSettings` used for initializing the dialog.
   *
   * Setting this property is typically used to re-establish
   * print settings from a previous print operation, see
   * Gtk::PrintOperation::run().
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_print_settings() -> Glib::PropertyProxy< Glib::RefPtr<PrintSettings> > ;

/** The `Gtk::PrintSettings` used for initializing the dialog.
   *
   * Setting this property is typically used to re-establish
   * print settings from a previous print operation, see
   * Gtk::PrintOperation::run().
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_print_settings() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<PrintSettings> >;

  /** A string used to identify the job (e.g.\ in monitoring
   * applications like eggcups).
   *
   * If you don't set a job name, GTK picks a default one
   * by numbering successive print jobs.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_job_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** A string used to identify the job (e.g.\ in monitoring
   * applications like eggcups).
   *
   * If you don't set a job name, GTK picks a default one
   * by numbering successive print jobs.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_job_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The number of pages in the document.
   *
   * This must be set to a positive number before the rendering
   * starts. It may be set in a signal_begin_print()
   * signal handler.
   *
   * Note that the page numbers passed to the
   * signal_request_page_setup() and
   * signal_draw_page() signals are 0-based, i.e.
   * if the user chooses to print all pages, the last signal_draw_page() signal
   * will be for page @a n_pages - 1.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_n_pages() -> Glib::PropertyProxy< int > ;

/** The number of pages in the document.
   *
   * This must be set to a positive number before the rendering
   * starts. It may be set in a signal_begin_print()
   * signal handler.
   *
   * Note that the page numbers passed to the
   * signal_request_page_setup() and
   * signal_draw_page() signals are 0-based, i.e.
   * if the user chooses to print all pages, the last signal_draw_page() signal
   * will be for page @a n_pages - 1.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_n_pages() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The current page in the document.
   *
   * If this is set before Gtk::PrintOperation::run(),
   * the user will be able to select to print only the current page.
   *
   * Note that this only makes sense for pre-paginated documents.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_current_page() -> Glib::PropertyProxy< int > ;

/** The current page in the document.
   *
   * If this is set before Gtk::PrintOperation::run(),
   * the user will be able to select to print only the current page.
   *
   * Note that this only makes sense for pre-paginated documents.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_current_page() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** If <tt>true</tt>, the transformation for the cairo context obtained
   * from `Gtk::PrintContext` puts the origin at the top left corner
   * of the page.
   *
   * This may not be the top left corner of the sheet, depending on
   * page orientation and the number of pages per sheet. Otherwise,
   * the origin is at the top left corner of the imageable area (i.e.
   * inside the margins).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_full_page() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, the transformation for the cairo context obtained
   * from `Gtk::PrintContext` puts the origin at the top left corner
   * of the page.
   *
   * This may not be the top left corner of the sheet, depending on
   * page orientation and the number of pages per sheet. Otherwise,
   * the origin is at the top left corner of the imageable area (i.e.
   * inside the margins).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_full_page() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If <tt>true</tt>, the print operation will try to continue report on
   * the status of the print job in the printer queues and printer.
   *
   * This can allow your application to show things like “out of paper”
   * issues, and when the print job actually reaches the printer.
   * However, this is often implemented using polling, and should
   * not be enabled unless needed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_track_print_status() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, the print operation will try to continue report on
   * the status of the print job in the printer queues and printer.
   *
   * This can allow your application to show things like “out of paper”
   * issues, and when the print job actually reaches the printer.
   * However, this is often implemented using polling, and should
   * not be enabled unless needed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_track_print_status() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The transformation for the cairo context obtained from
   * `Gtk::PrintContext` is set up in such a way that distances
   * are measured in units of @a unit.
   *
   * Default value: Gtk::Unit::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_unit() -> Glib::PropertyProxy< Unit > ;

/** The transformation for the cairo context obtained from
   * `Gtk::PrintContext` is set up in such a way that distances
   * are measured in units of @a unit.
   *
   * Default value: Gtk::Unit::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_unit() const -> Glib::PropertyProxy_ReadOnly< Unit >;

  /** Determines whether to show a progress dialog during the
   * print operation.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_progress() -> Glib::PropertyProxy< bool > ;

/** Determines whether to show a progress dialog during the
   * print operation.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_progress() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether the print operation may run asynchronously or not.
   *
   * Some systems don't support asynchronous printing, but those that do
   * will return Gtk::PrintOperation::Result::IN_PROGRESS as the status, and
   * emit the signal_done() signal when the operation
   * is actually done.
   *
   * The Windows port does not support asynchronous operation at all (this
   * is unlikely to change). On other platforms, all actions except for
   * Gtk::PrintOperation::Action::EXPORT support asynchronous operation.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_allow_async() -> Glib::PropertyProxy< bool > ;

/** Determines whether the print operation may run asynchronously or not.
   *
   * Some systems don't support asynchronous printing, but those that do
   * will return Gtk::PrintOperation::Result::IN_PROGRESS as the status, and
   * emit the signal_done() signal when the operation
   * is actually done.
   *
   * The Windows port does not support asynchronous operation at all (this
   * is unlikely to change). On other platforms, all actions except for
   * Gtk::PrintOperation::Action::EXPORT support asynchronous operation.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_allow_async() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The name of a file to generate instead of showing the print dialog.
   *
   * Currently, PDF is the only supported format.
   *
   * The intended use of this property is for implementing
   * “Export to PDF” actions.
   *
   * “Print to PDF” support is independent of this and is done
   * by letting the user pick the “Print to PDF” item from the
   * list of printers in the print dialog.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_export_filename() -> Glib::PropertyProxy< std::string > ;

/** The name of a file to generate instead of showing the print dialog.
   *
   * Currently, PDF is the only supported format.
   *
   * The intended use of this property is for implementing
   * “Export to PDF” actions.
   *
   * “Print to PDF” support is independent of this and is done
   * by letting the user pick the “Print to PDF” item from the
   * list of printers in the print dialog.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_export_filename() const -> Glib::PropertyProxy_ReadOnly< std::string >;

  /** The status of the print operation.
   *
   * Default value: Gtk::PrintStatus::INITIAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_status() const -> Glib::PropertyProxy_ReadOnly< PrintStatus >;


  /** A string representation of the status of the print operation.
   *
   * The string is translated and suitable for displaying the print
   * status e.g. in a `Gtk::Statusbar`.
   *
   * See the property_status() property for a status
   * value that is suitable for programmatic use.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_status_string() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Used as the label of the tab containing custom widgets.
   *
   * Note that this property may be ignored on some platforms.
   *
   * If this is <tt>nullptr</tt>, GTK uses a default label.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_custom_tab_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** Used as the label of the tab containing custom widgets.
   *
   * Note that this property may be ignored on some platforms.
   *
   * If this is <tt>nullptr</tt>, GTK uses a default label.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_custom_tab_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** If <tt>true</tt>, the print operation will support print of selection.
   *
   * This allows the print dialog to show a "Selection" button.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_support_selection() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, the print operation will support print of selection.
   *
   * This allows the print dialog to show a "Selection" button.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_support_selection() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether there is a selection in your application.
   *
   * This can allow your application to print the selection.
   * This is typically used to make a "Selection" button sensitive.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_selection() -> Glib::PropertyProxy< bool > ;

/** Determines whether there is a selection in your application.
   *
   * This can allow your application to print the selection.
   * This is typically used to make a "Selection" button sensitive.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_selection() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If <tt>true</tt>, page size combo box and orientation combo box
   * are embedded into page setup page.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_embed_page_setup() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, page size combo box and orientation combo box
   * are embedded into page setup page.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_embed_page_setup() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The number of pages that will be printed.
   *
   * Note that this value is set during print preparation phase
   * (Gtk::PrintStatus::PREPARING), so this value should never be
   * get before the data generation phase (Gtk::PrintStatus::GENERATING_DATA).
   * You can connect to the signal_status_changed() signal
   * and call Gtk::PrintOperation::get_n_pages_to_print() when
   * print status is Gtk::PrintStatus::GENERATING_DATA.
   *
   * This is typically used to track the progress of print operation.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_n_pages_to_print() const -> Glib::PropertyProxy_ReadOnly< int >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_done().
  virtual void on_done(Result result);
  /// This is a default handler for the signal signal_begin_print().
  virtual void on_begin_print(const Glib::RefPtr<PrintContext>& context);
  /// This is a default handler for the signal signal_paginate().
  virtual auto on_paginate(const Glib::RefPtr<PrintContext>& context) -> bool;
  /// This is a default handler for the signal signal_request_page_setup().
  virtual void on_request_page_setup(const Glib::RefPtr<PrintContext>& context, int page_no, const Glib::RefPtr<PageSetup>& setup);
  /// This is a default handler for the signal signal_draw_page().
  virtual void on_draw_page(const Glib::RefPtr<PrintContext>& context, int page_nr);
  /// This is a default handler for the signal signal_end_print().
  virtual void on_end_print(const Glib::RefPtr<PrintContext>& context);
  /// This is a default handler for the signal signal_status_changed().
  virtual void on_status_changed();
  /// This is a default handler for the signal signal_create_custom_widget().
  virtual auto on_create_custom_widget() -> Widget*;
  /// This is a default handler for the signal signal_custom_widget_apply().
  virtual void on_custom_widget_apply(Widget* widget);
  /// This is a default handler for the signal signal_preview().
  virtual auto on_preview(const Glib::RefPtr<PrintOperationPreview>& preview, const Glib::RefPtr<PrintContext>& context, Window* parent) -> bool;
  /// This is a default handler for the signal signal_update_custom_widget().
  virtual void on_update_custom_widget(Widget* widget, const Glib::RefPtr<PageSetup>& setup, const Glib::RefPtr<PrintSettings>& settings);


};

  //TODO: Make these static members of a class instead of non-class functions?

  //Note: gtk_run_page_setup_dialog() can take a null page_setup object, but the application should always
  //store and reuse a page_setup object, so I see no need to provide an overload for that. murrayc.
  //TODO: The parent parameter may also be null, so maybe we should add an overload for that.

  /** Runs a page setup dialog, letting the user modify the values from page_setup.
   * If the user cancels the dialog, the returned PageSetup is identical to that passed in @a page_setup,
   * otherwise it contains the modifications done in the dialog.
   *
   * Note that this function may use a recursive mainloop to show the page setup dialog.
   * See run_page_setup_dialog_async() if this is a problem.
   *
   * @param parent Transient parent.
   * @param page_setup An existing GtkPageSetup.
   * @param print_settings Print settings.
   * @result A new PageSetup object.
   *
   * @since 2.10
   */
  GTKMM_API
  auto run_page_setup_dialog(Window& parent,
                                                const Glib::RefPtr<const PageSetup>& page_setup,
                                                const Glib::RefPtr<const PrintSettings>& print_settings) -> Glib::RefPtr<PageSetup>;

  /** Runs a page setup dialog, letting the user modify the values from page_setup.
   * If the user cancels the dialog, the returned PageSetup is identical to that passed in @a page_setup,
   * otherwise it contains the modifications done in the dialog.
   *
   * Note that this function may use a recursive mainloop to show the page setup dialog.
   * See run_page_setup_dialog_async() if this is a problem.
   *
   * @param parent Transient parent.
   * @param print_settings Print settings.
   * @result A new PageSetup object.
   *
   * @since 2.22
   */
  GTKMM_API
  auto run_page_setup_dialog(Window& parent,
                                                const Glib::RefPtr<const PrintSettings>& print_settings) -> Glib::RefPtr<PageSetup>;

  /** For example,
   * void on_setup_done(const Glib::RefPtr<PageSetup>& page_setup);
   */
  typedef sigc::slot<void(const Glib::RefPtr<PageSetup>&)> SlotPrintSetupDone;

  /** Runs a page setup dialog, letting the user modify the values from page_setup.
   *
   * In contrast to run_page_setup_dialog(), this function returns after showing the
   * page setup dialog on platforms that support this, and calls the @a slot from a
   * signal handler for the ::response signal of the dialog.
   *
   * @param parent Transient parent.
   * @param page_setup An existing GtkPageSetup.
   * @param print_settings Print settings.
   * @result A new PageSetup object.
   * @param slot
   *
   * @since 2.10
   */
  GTKMM_API
  void run_page_setup_dialog_async(Window& parent,
                                   const Glib::RefPtr<const PageSetup>& page_setup,
                                   const Glib::RefPtr<const PrintSettings>& print_settings,
                                   const SlotPrintSetupDone& slot);

  /** Runs a page setup dialog, letting the user modify the values from page_setup.
   *
   * In contrast to run_page_setup_dialog(), this function returns after showing the
   * page setup dialog on platforms that support this, and calls the @a slot from a
   * signal handler for the ::response signal of the dialog.
   *
   * @param parent Transient parent.
   * @param print_settings Print settings.
   * @result A new PageSetup object.
   * @param slot
   *
   * @since 2.22
   */
  GTKMM_API
  void run_page_setup_dialog_async(Window& parent,
                                   const Glib::RefPtr<const PrintSettings>& print_settings,
                                   const SlotPrintSetupDone& slot);

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PrintOperation::Result> : public Glib::Value_Enum<Gtk::PrintOperation::Result>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PrintOperation::Action> : public Glib::Value_Enum<Gtk::PrintOperation::Action>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::PrintOperation
   */
  GTKMM_API
  auto wrap(GtkPrintOperation* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PrintOperation>;
}


#endif /* _GTKMM_PRINTOPERATION_H */

