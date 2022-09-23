// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_NATIVEDIALOG_H
#define _GTKMM_NATIVEDIALOG_H

#include <gtkmmconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The gtkmm Development Team
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


#include <glibmm/object.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNativeDialog = struct _GtkNativeDialog;
using GtkNativeDialogClass = struct _GtkNativeDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API NativeDialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Window;

/** Integrate with native dialogs.
 *
 * Native dialogs are platform dialogs that don't use Gtk::Dialog or
 * Gtk::Window. They are used in order to integrate better with a
 * platform, by looking the same as other native applications and
 * supporting platform specific features.
 *
 * The Gtk::Dialog functions cannot be used on such objects, but we
 * need a similar API in order to drive them. The %NativeDialog
 * object is an API that allows you to do this. It allows you to set
 * various common properties on the dialog, as well as show and hide
 * it and get a response signal when the user finished with the dialog.
 *
 * @see Gtk::FileChooserNative, Gtk::Dialog
 * @newin{3,24}
 */

class GTKMM_API NativeDialog : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = NativeDialog;
  using CppClassType = NativeDialog_Class;
  using BaseObjectType = GtkNativeDialog;
  using BaseClassType = GtkNativeDialogClass;

  // noncopyable
  NativeDialog(const NativeDialog&) = delete;
  NativeDialog& operator=(const NativeDialog&) = delete;

private:  friend class NativeDialog_Class;
  static CppClassType nativedialog_class_;

protected:
  explicit NativeDialog(const Glib::ConstructParams& construct_params);
  explicit NativeDialog(GtkNativeDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  NativeDialog(NativeDialog&& src) noexcept;
  NativeDialog& operator=(NativeDialog&& src) noexcept;

  ~NativeDialog() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkNativeDialog*       gobj()       { return reinterpret_cast<GtkNativeDialog*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkNativeDialog* gobj() const { return reinterpret_cast<GtkNativeDialog*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkNativeDialog* gobj_copy();

private:

  
protected:
  /** There is no create() method that corresponds to this constructor,
   * because only derived classes shall be created.
   */
  NativeDialog();

public:
  // No create() because only derived classes shall be instantiated.

  
  /** Shows the dialog on the display.
   * 
   * When the user accepts the state of the dialog the dialog will
   * be automatically hidden and the signal_response()
   * signal will be emitted.
   * 
   * Multiple calls while the dialog is visible will be ignored.
   * 
   * @newin{3,24}
   */
  void show();
  
  /** Hides the dialog if it is visible, aborting any interaction.
   * 
   * Once this is called the signal_response() signal
   * will *not* be emitted until after the next call to
   * show().
   * 
   * If the dialog is not visible this does nothing.
   * 
   * @newin{3,24}
   */
  void hide();
  
  /** Determines whether the dialog is visible.
   * 
   * @newin{3,24}
   * 
   * @return <tt>true</tt> if the dialog is visible.
   */
  bool get_visible() const;
  
  /** Sets a dialog modal or non-modal.
   * 
   * Modal dialogs prevent interaction with other windows in the same
   * application. To keep modal dialogs on top of main application
   * windows, use set_transient_for() to make
   * the dialog transient for the parent; most window managers will
   * then disallow lowering the dialog below the parent.
   * 
   * @newin{3,24}
   * 
   * @param modal Whether the window is modal.
   */
  void set_modal(bool modal =  true);
  
  /** Returns whether the dialog is modal.
   * 
   * @newin{3,24}
   * 
   * @return <tt>true</tt> if the dialog is set to be modal.
   */
  bool get_modal() const;
  
  /** Sets the title of the `GtkNativeDialog.`
   * 
   * @newin{3,24}
   * 
   * @param title Title of the dialog.
   */
  void set_title(const Glib::ustring& title);
  
  /** Gets the title of the `Gtk::NativeDialog`.
   * 
   * @newin{3,24}
   * 
   * @return The title of the dialog, or <tt>nullptr</tt> if none has
   * been set explicitly. The returned string is owned by the widget
   * and must not be modified or freed.
   */
  Glib::ustring get_title() const;

  
  /** Dialog windows should be set transient for the main application
   * window they were spawned from.
   * 
   * This allows window managers to e.g. keep the dialog on top of the
   * main window, or center the dialog over the main window.
   * 
   * Passing <tt>nullptr</tt> for @a parent unsets the current transient window.
   * 
   * @newin{3,24}
   * 
   * @param parent Parent window.
   */
  void set_transient_for(Window& parent);

  /** Unsets the current transient window.
   * @see set_transient_for().
   * @newin{3,24}
   */
  void unset_transient_for();

  
  /** Fetches the transient parent for this window.
   * 
   * @newin{3,24}
   * 
   * @return The transient parent for this window,
   * or <tt>nullptr</tt> if no transient parent has been set.
   */
  Window* get_transient_for();
  
  /** Fetches the transient parent for this window.
   * 
   * @newin{3,24}
   * 
   * @return The transient parent for this window,
   * or <tt>nullptr</tt> if no transient parent has been set.
   */
  const Window* get_transient_for() const;

  /** The title of the dialog window
   * 
   * @newin{3,24}
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::ustring > property_title() ;

/** The title of the dialog window
   * 
   * @newin{3,24}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_title() const;

  /** Whether the window should be modal with respect to its transient parent.
   * 
   * @newin{3,24}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_modal() ;

/** Whether the window should be modal with respect to its transient parent.
   * 
   * @newin{3,24}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_modal() const;

  /** Whether the window is currently visible.
   * 
   * @newin{3,24}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_visible() ;

/** Whether the window is currently visible.
   * 
   * @newin{3,24}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_visible() const;

  /** The transient parent of the dialog, or <tt>nullptr</tt> for none.
   * 
   * @newin{3,24}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Window* > property_transient_for() ;

/** The transient parent of the dialog, or <tt>nullptr</tt> for none.
   * 
   * @newin{3,24}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Window* > property_transient_for() const;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%response(int response_id)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the user responds to the dialog.
   * 
   * When this is called the dialog has been hidden.
   * 
   * If you call Gtk::NativeDialog::hide() before the user
   * responds to the dialog this signal will not be emitted.
   * 
   * @newin{3,24}
   * 
   * @param response_id The response ID.
   */

  Glib::SignalProxy<void(int)> signal_response();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_response().
  virtual void on_response(int response_id);


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
   * @relates Gtk::NativeDialog
   */
  GTKMM_API
  Glib::RefPtr<Gtk::NativeDialog> wrap(GtkNativeDialog* object, bool take_copy = false);
}


#endif /* _GTKMM_NATIVEDIALOG_H */

