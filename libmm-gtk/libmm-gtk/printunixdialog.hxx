
#ifndef _GTKMM_PRINTUNIXDIALOG_H
#define _GTKMM_PRINTUNIXDIALOG_H


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

#include <libmm-gtk/dialog.hxx>
#include <libmm-gtk/pagesetup.hxx>
#include <libmm-gtk/printer.hxx>
#include <libmm-gtk/printjob.hxx>
#include <libmm-gtk/printsettings.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintUnixDialog = struct _GtkPrintUnixDialog;
using GtkPrintUnixDialogClass = struct _GtkPrintUnixDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API PrintUnixDialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** PrintUnixDialog implements a print dialog for platforms
 * which don't provide a native print dialog, like Unix. It can
 * be used very much like any other GTK+ dialog, at the cost of
 * the portability offered by the high-level printing API exposed
 * through PrintOperation.
 *
 * In order to print something with PrintUnixDialog, you need
 * to use get_selected_printer() to obtain a Printer object and
 * use it to construct a PrintJob using PrintJob::create().
 *
 * PrintUnixDialog uses the following response values:
 * - RESPONSE_OK for the "Print" button
 * - RESPONSE_APPLY for the "Preview" button
 * - RESPONSE_CANCEL for the "Cancel" button
 *
 * @newin{2,10}
 *
 * @ingroup Printing
 */

class GTKMM_API PrintUnixDialog : public Dialog
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef PrintUnixDialog CppObjectType;
  typedef PrintUnixDialog_Class CppClassType;
  typedef GtkPrintUnixDialog BaseObjectType;
  typedef GtkPrintUnixDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  PrintUnixDialog(PrintUnixDialog&& src) noexcept;
  auto operator=(PrintUnixDialog&& src) noexcept -> PrintUnixDialog&;

  // noncopyable
  PrintUnixDialog(const PrintUnixDialog&) = delete;
  auto operator=(const PrintUnixDialog&) -> PrintUnixDialog& = delete;

  ~PrintUnixDialog() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class PrintUnixDialog_Class;
  static CppClassType printunixdialog_class_;

protected:
  explicit PrintUnixDialog(const Glib::ConstructParams& construct_params);
  explicit PrintUnixDialog(GtkPrintUnixDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkPrintUnixDialog*       { return reinterpret_cast<GtkPrintUnixDialog*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPrintUnixDialog* { return reinterpret_cast<GtkPrintUnixDialog*>(gobject_); }

private:


  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


public:
  explicit PrintUnixDialog(Gtk::Window& parent, const Glib::ustring& title);
  explicit PrintUnixDialog(const Glib::ustring& title);


  /** Sets the page setup of the `Gtk::PrintUnixDialog`.
   *
   * @param page_setup A `Gtk::PageSetup`.
   */
  void set_page_setup(const Glib::RefPtr<PageSetup>& page_setup);

  /** Gets the page setup that is used by the `Gtk::PrintUnixDialog`.
   *
   * @return The page setup of @a dialog.
   */
  auto get_page_setup() -> Glib::RefPtr<PageSetup>;

  /** Gets the page setup that is used by the `Gtk::PrintUnixDialog`.
   *
   * @return The page setup of @a dialog.
   */
  auto get_page_setup() const -> Glib::RefPtr<const PageSetup>;


  /** Sets the current page number.
   *
   * If @a current_page is not -1, this enables the current page choice
   * for the range of pages to print.
   *
   * @param current_page The current page number.
   */
  void set_current_page(int current_page);

  /** Gets the current page of the `Gtk::PrintUnixDialog`.
   *
   * @return The current page of @a dialog.
   */
  auto get_current_page() const -> int;


  /** Sets the `Gtk::PrintSettings` for the `Gtk::PrintUnixDialog`.
   *
   * Typically, this is used to restore saved print settings
   * from a previous print operation before the print dialog
   * is shown.
   *
   * @param settings A `Gtk::PrintSettings`.
   */
  void set_settings(const Glib::RefPtr<PrintSettings>& settings);

  /** Gets a new `Gtk::PrintSettings` object that represents the
   * current values in the print dialog.
   *
   * Note that this creates a new object, and you need to unref
   * it if don’t want to keep it.
   *
   * @return A new `Gtk::PrintSettings` object with the values from @a dialog.
   */
  auto get_settings() -> Glib::RefPtr<PrintSettings>;

  /** Gets a new `Gtk::PrintSettings` object that represents the
   * current values in the print dialog.
   *
   * Note that this creates a new object, and you need to unref
   * it if don’t want to keep it.
   *
   * @return A new `Gtk::PrintSettings` object with the values from @a dialog.
   */
  auto get_settings() const -> Glib::RefPtr<const PrintSettings>;


  /** Gets the currently selected printer.
   *
   * @return The currently selected printer.
   */
  auto get_selected_printer() -> Glib::RefPtr<Printer>;

  /** Gets the currently selected printer.
   *
   * @return The currently selected printer.
   */
  auto get_selected_printer() const -> Glib::RefPtr<const Printer>;

  void add_custom_tab(const Widget& child, const Glib::ustring& tab_label);

  /** Adds a custom tab to the print dialog.
   *
   * @param child The widget to put in the custom tab.
   * @param tab_label The widget to use as tab label.
   */
  void add_custom_tab(const Widget& child, const Widget& tab_label);

  /** This lets you specify the printing capabilities your application
   * supports.
   *
   * For instance, if you can handle scaling the output then you pass
   * Gtk::PrintCapabilities::SCALE. If you don’t pass that, then the dialog
   * will only let you select the scale if the printing system automatically
   * handles scaling.
   *
   * @param capabilities The printing capabilities of your application.
   */
  void set_manual_capabilities(PrintCapabilities capabilities);

  /** Gets the capabilities that have been set on this `Gtk::PrintUnixDialog`.
   *
   * @return The printing capabilities.
   */
  auto get_manual_capabilities() const -> PrintCapabilities;


  /** Sets whether the print dialog allows user to print a selection.
   *
   * @param support_selection <tt>true</tt> to allow print selection.
   */
  void get_support_selection(bool support_selection =  true);

  /** Gets whether the print dialog allows user to print a selection.
   *
   * @return Whether the application supports print of selection.
   */
  auto get_support_selection() const -> bool;

  /** Sets whether a selection exists.
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
   * @param embed Embed page setup selection.
   */
  void set_embed_page_setup(bool embed =  true);

  /** Gets whether to embed the page setup.
   *
   * @return Whether to embed the page setup.
   */
  auto get_embed_page_setup() const -> bool;

  /** Gets whether a page setup was set by the user.
   *
   * @return Whether a page setup was set by user.
   */
  auto get_page_setup_set() const -> bool;

  /** The `Gtk::PageSetup` object to use.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page_setup() -> Glib::PropertyProxy< Glib::RefPtr<PageSetup> > ;

/** The `Gtk::PageSetup` object to use.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page_setup() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<PageSetup> >;

  /** The current page in the document.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_current_page() -> Glib::PropertyProxy< int > ;

/** The current page in the document.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_current_page() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The `Gtk::PrintSettings` object used for this dialog.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_print_settings() -> Glib::PropertyProxy< Glib::RefPtr<PrintSettings> > ;

/** The `Gtk::PrintSettings` object used for this dialog.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_print_settings() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<PrintSettings> >;

  /** The `Gtk::Printer` which is selected.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selected_printer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Printer> >;


  /** Capabilities the application can handle.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_manual_capabilities() -> Glib::PropertyProxy< bool > ;

/** Capabilities the application can handle.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_manual_capabilities() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the dialog supports selection.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_support_selection() -> Glib::PropertyProxy< bool > ;

/** Whether the dialog supports selection.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_support_selection() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the application has a selection.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_selection() -> Glib::PropertyProxy< bool > ;

/** Whether the application has a selection.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_selection() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** <tt>true</tt> if the page setup controls are embedded.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_embed_page_setup() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if the page setup controls are embedded.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_embed_page_setup() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::PrintUnixDialog
   */
  GTKMM_API
  auto wrap(GtkPrintUnixDialog* object, bool take_copy = false) -> Gtk::PrintUnixDialog*;
} //namespace Glib


#endif /* _GTKMM_PRINTUNIXDIALOG_H */

