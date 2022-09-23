// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_FILECHOOSERDIALOG_H
#define _GTKMM_FILECHOOSERDIALOG_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <gtkmm/dialog.h>
#include <gtkmm/filechooser.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileChooserDialog = struct _GtkFileChooserDialog;
using GtkFileChooserDialogClass = struct _GtkFileChooserDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FileChooserDialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Convenient file chooser window.
 *
 * A FileChooserDialog looks like this:
 * @image html filechooserdialog1.png
 *
 * @ingroup Dialogs
 */

class GTKMM_API FileChooserDialog
  : public Dialog,
    public FileChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FileChooserDialog CppObjectType;
  typedef FileChooserDialog_Class CppClassType;
  typedef GtkFileChooserDialog BaseObjectType;
  typedef GtkFileChooserDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  FileChooserDialog(FileChooserDialog&& src) noexcept;
  FileChooserDialog& operator=(FileChooserDialog&& src) noexcept;

  // noncopyable
  FileChooserDialog(const FileChooserDialog&) = delete;
  FileChooserDialog& operator=(const FileChooserDialog&) = delete;

  ~FileChooserDialog() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class FileChooserDialog_Class;
  static CppClassType filechooserdialog_class_;

protected:
  explicit FileChooserDialog(const Glib::ConstructParams& construct_params);
  explicit FileChooserDialog(GtkFileChooserDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GtkFileChooserDialog*       gobj()       { return reinterpret_cast<GtkFileChooserDialog*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GtkFileChooserDialog* gobj() const { return reinterpret_cast<GtkFileChooserDialog*>(gobject_); }

private:

  
public:
  
  FileChooserDialog(Gtk::Window& parent, const Glib::ustring& title, Action action = Action::OPEN, bool use_header_bar = false);
  explicit FileChooserDialog(const Glib::ustring& title, Action action = Action::OPEN, bool use_header_bar = false);


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
   * @relates Gtk::FileChooserDialog
   */
  GTKMM_API
  Gtk::FileChooserDialog* wrap(GtkFileChooserDialog* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_FILECHOOSERDIALOG_H */

