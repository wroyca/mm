
#ifndef _GTKMM_PRINTOPERATIONPREVIEW_H
#define _GTKMM_PRINTOPERATIONPREVIEW_H


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

#include <libmm-glib/interface.hxx>

#include <libmm-gtk/pagesetup.hxx>
#include <libmm-gtk/printcontext.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkPrintOperationPreviewIface GtkPrintOperationPreviewIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintOperationPreview = struct _GtkPrintOperationPreview;
using GtkPrintOperationPreviewClass = struct _GtkPrintOperationPreviewClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API PrintOperationPreview_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

//TODO: There is no GtkPrintOperationPreview documentation either.
// See http://bugzilla.gnome.org/show_bug.cgi?id=575538
/**
 * @newin{2,10}
 *
 * @ingroup Printing
 */

class GTKMM_API PrintOperationPreview : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PrintOperationPreview;
  using CppClassType = PrintOperationPreview_Class;
  using BaseObjectType = GtkPrintOperationPreview;
  using BaseClassType = GtkPrintOperationPreviewIface;

  // noncopyable
  PrintOperationPreview(const PrintOperationPreview&) = delete;
  auto operator=(const PrintOperationPreview&) -> PrintOperationPreview& = delete;

private:
  friend class PrintOperationPreview_Class;
  static CppClassType printoperationpreview_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  PrintOperationPreview();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit PrintOperationPreview(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit PrintOperationPreview(GtkPrintOperationPreview* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PrintOperationPreview(PrintOperationPreview&& src) noexcept;
  auto operator=(PrintOperationPreview&& src) noexcept -> PrintOperationPreview&;

  ~PrintOperationPreview() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkPrintOperationPreview*       { return reinterpret_cast<GtkPrintOperationPreview*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPrintOperationPreview* { return reinterpret_cast<GtkPrintOperationPreview*>(gobject_); }

private:

public:


  /** Renders a page to the preview.
   *
   * This is using the print context that was passed to the
   * Gtk::PrintOperation::signal_preview() handler together
   * with @a preview.
   *
   * A custom print preview should use this function to render
   * the currently selected page.
   *
   * Note that this function requires a suitable cairo context to
   * be associated with the print context.
   *
   * @param page_nr The page to render.
   */
  void render_page(int page_nr);

  /** Ends a preview.
   *
   * This function must be called to finish a custom print preview.
   */
  void end_preview();

  /** Returns whether the given page is included in the set of pages that
   * have been selected for printing.
   *
   * @param page_nr A page number.
   * @return <tt>true</tt> if the page has been selected for printing.
   */
  auto is_selected(int page_nr) const -> bool;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%ready(const Glib::RefPtr<PrintContext>& context)</tt>
   *
   * Flags: Run Last
   *
   * The signal_ready() signal gets emitted once per preview operation,
   * before the first page is rendered.
   *
   * A handler for this signal can be used for setup tasks.
   *
   * @param context The current `Gtk::PrintContext`.
   */

  auto signal_ready() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%got_page_size(const Glib::RefPtr<PrintContext>& context, const Glib::RefPtr<PageSetup>& page_setup)</tt>
   *
   * Flags: Run Last
   *
   * Emitted once for each page that gets rendered to the preview.
   *
   * A handler for this signal should update the @a context
   * according to @a page_setup and set up a suitable cairo
   * context, using Gtk::PrintContext::set_cairo_context().
   *
   * @param context The current `Gtk::PrintContext`.
   * @param page_setup The `Gtk::PageSetup` for the current page.
   */

  auto signal_got_page_size() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&, const Glib::RefPtr<PageSetup>&)>;


protected:
    virtual void render_page_vfunc(int page_nr);

    virtual void end_preview_vfunc();

    virtual auto is_selected_vfunc(int page_nr) const -> bool;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_ready().
  virtual void on_ready(const Glib::RefPtr<PrintContext>& context);
  /// This is a default handler for the signal signal_got_page_size().
  virtual void on_got_page_size(const Glib::RefPtr<PrintContext>& context, const Glib::RefPtr<PageSetup>& page_setup);


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
   * @relates Gtk::PrintOperationPreview
   */
  GTKMM_API
  auto wrap(GtkPrintOperationPreview* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PrintOperationPreview>;

} // namespace Glib


#endif /* _GTKMM_PRINTOPERATIONPREVIEW_H */
