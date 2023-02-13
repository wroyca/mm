
#ifndef _GTKMM_COLORCHOOSERDIALOG_H
#define _GTKMM_COLORCHOOSERDIALOG_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The gtkmm Development Team
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

#include <mm/gtk/dialog.hpp>
#include <mm/gtk/colorchooser.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColorChooserDialog = struct _GtkColorChooserDialog;
using GtkColorChooserDialogClass = struct _GtkColorChooserDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ColorChooserDialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** This dialog is for choosing a color. It implements the ColorChooser interface.
 *
 * A ColorChooserDialog looks like this:
 * @image html colorchooserdialog1.png
 *
 * @ingroup Dialogs
 */

class GTKMM_API ColorChooserDialog
: public Dialog,
  public ColorChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ColorChooserDialog CppObjectType;
  typedef ColorChooserDialog_Class CppClassType;
  typedef GtkColorChooserDialog BaseObjectType;
  typedef GtkColorChooserDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ColorChooserDialog(ColorChooserDialog&& src) noexcept;
  auto operator=(ColorChooserDialog&& src) noexcept -> ColorChooserDialog&;

  // noncopyable
  ColorChooserDialog(const ColorChooserDialog&) = delete;
  auto operator=(const ColorChooserDialog&) -> ColorChooserDialog& = delete;

  ~ColorChooserDialog() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ColorChooserDialog_Class;
  static CppClassType colorchooserdialog_class_;

protected:
  explicit ColorChooserDialog(const Glib::ConstructParams& construct_params);
  explicit ColorChooserDialog(GtkColorChooserDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkColorChooserDialog*       { return reinterpret_cast<GtkColorChooserDialog*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkColorChooserDialog* { return reinterpret_cast<GtkColorChooserDialog*>(gobject_); }

private:


public:

  ColorChooserDialog();

  explicit ColorChooserDialog(const Glib::ustring& title);

  //Note: We renamed the parent parameter to transient_for because that is the property name.
    explicit ColorChooserDialog(const Glib::ustring& title, Window& transient_for);


  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_editor() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_editor() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::ColorChooserDialog
   */
  GTKMM_API
  auto wrap(GtkColorChooserDialog* object, bool take_copy = false) -> Gtk::ColorChooserDialog*;
} //namespace Glib


#endif /* _GTKMM_COLORCHOOSERDIALOG_H */

