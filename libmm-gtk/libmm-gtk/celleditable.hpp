
#ifndef _GTKMM_CELLEDITABLE_H
#define _GTKMM_CELLEDITABLE_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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


#include <libmm-glib/interface.hpp>
#include <libmm-gdk/event.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkCellEditableIface GtkCellEditableIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellEditable = struct _GtkCellEditable;
using GtkCellEditableClass = struct _GtkCellEditableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellEditable_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Interface for widgets which are used for editing cells.
 * The CellEditable interface must be implemented for widgets to be usable when editing the contents of a TreeView cell.
 */

class GTKMM_API CellEditable : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CellEditable;
  using CppClassType = CellEditable_Class;
  using BaseObjectType = GtkCellEditable;
  using BaseClassType = GtkCellEditableIface;

  // noncopyable
  CellEditable(const CellEditable&) = delete;
  auto operator=(const CellEditable&) -> CellEditable& = delete;

private:
  friend class CellEditable_Class;
  static CppClassType celleditable_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  CellEditable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit CellEditable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit CellEditable(GtkCellEditable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CellEditable(CellEditable&& src) noexcept;
  auto operator=(CellEditable&& src) noexcept -> CellEditable&;

  ~CellEditable() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellEditable*       { return reinterpret_cast<GtkCellEditable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellEditable* { return reinterpret_cast<GtkCellEditable*>(gobject_); }

private:


public:

  /** Begins editing on a @a cell_editable.
   *
   * The `Gtk::CellRenderer` for the cell creates and returns a `Gtk::CellEditable` from
   * Gtk::CellRenderer::start_editing(), configured for the `Gtk::CellRenderer` type.
   *
   * start_editing() can then set up @a cell_editable suitably for
   * editing a cell, e.g. making the Esc key emit `GtkCellEditable::editing-done`.
   *
   * Note that the @a cell_editable is created on-demand for the current edit; its
   * lifetime is temporary and does not persist across other edits and/or cells.
   *
   * @param event The `Gdk::Event` that began the editing process, or
   * <tt>nullptr</tt> if editing was initiated programmatically.
   */
  void start_editing(const Glib::RefPtr<const Gdk::Event>& event);

  /** Emits the `GtkCellEditable::editing-done` signal.
   */
  void editing_done();

  /** Emits the `GtkCellEditable::remove-widget` signal.
   */
  void remove_widget();


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%editing_done()</tt>
   *
   * Flags: Run Last
   *
   * This signal is a sign for the cell renderer to update its
   * value from the @a cell_editable.
   *
   * Implementations of `Gtk::CellEditable` are responsible for
   * emitting this signal when they are done editing, e.g.
   * `Gtk::Entry` emits this signal when the user presses Enter. Typical things to
   * do in a handler for signal_editing_done() are to capture the edited value,
   * disconnect the @a cell_editable from signals on the `Gtk::CellRenderer`, etc.
   *
   * Gtk::CellEditable::editing_done() is a convenience method
   * for emitting `GtkCellEditable::editing-done`.
   */

  auto signal_editing_done() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%remove_widget()</tt>
   *
   * Flags: Run Last
   *
   * This signal is meant to indicate that the cell is finished
   * editing, and the @a cell_editable widget is being removed and may
   * subsequently be destroyed.
   *
   * Implementations of `Gtk::CellEditable` are responsible for
   * emitting this signal when they are done editing. It must
   * be emitted after the `GtkCellEditable::editing-done` signal,
   * to give the cell renderer a chance to update the cell's value
   * before the widget is removed.
   *
   * Gtk::CellEditable::remove_widget() is a convenience method
   * for emitting `GtkCellEditable::remove-widget`.
   */

  auto signal_remove_widget() -> Glib::SignalProxy<void()>;


  /** Indicates whether editing on the cell has been canceled.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editing_canceled() -> Glib::PropertyProxy< bool > ;

/** Indicates whether editing on the cell has been canceled.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editing_canceled() const -> Glib::PropertyProxy_ReadOnly< bool >;


protected:


    virtual void start_editing_vfunc(const Glib::RefPtr<const Gdk::Event>& event);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_editing_done().
  virtual void on_editing_done();
  /// This is a default handler for the signal signal_remove_widget().
  virtual void on_remove_widget();


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
   * @relates Gtk::CellEditable
   */
  GTKMM_API
  auto wrap(GtkCellEditable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellEditable>;

} // namespace Glib


#endif /* _GTKMM_CELLEDITABLE_H */

