// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_FONTCHOOSERDIALOG_H
#define _GTKMM_FONTCHOOSERDIALOG_H


#include <mm/glib/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2011 The gtkmm Development Team
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


#include <mm/gtk/dialog.h>
#include <mm/gtk/fontchooser.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFontChooserDialog = struct _GtkFontChooserDialog;
using GtkFontChooserDialogClass = struct _GtkFontChooserDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FontChooserDialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A dialog box for selecting fonts. It implements the #GtkFontChooser interface.
 *
 * To set the font which is initially selected, use set_font_name().
 *
 * To get the selected font use get_font_name().
 *
 * To change the text which is shown in the preview area, use set_preview_text().
 *
 * @ingroup Dialogs
 * @ingroup FontChooser
 * @newin{3,2}
 */

class GTKMM_API FontChooserDialog
  : public Dialog,
    public FontChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FontChooserDialog CppObjectType;
  typedef FontChooserDialog_Class CppClassType;
  typedef GtkFontChooserDialog BaseObjectType;
  typedef GtkFontChooserDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  FontChooserDialog(FontChooserDialog&& src) noexcept;
  auto operator=(FontChooserDialog&& src) noexcept -> FontChooserDialog&;

  // noncopyable
  FontChooserDialog(const FontChooserDialog&) = delete;
  auto operator=(const FontChooserDialog&) -> FontChooserDialog& = delete;

  ~FontChooserDialog() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class FontChooserDialog_Class;
  static CppClassType fontchooserdialog_class_;

protected:
  explicit FontChooserDialog(const Glib::ConstructParams& construct_params);
  explicit FontChooserDialog(GtkFontChooserDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkFontChooserDialog*       { return reinterpret_cast<GtkFontChooserDialog*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFontChooserDialog* { return reinterpret_cast<GtkFontChooserDialog*>(gobject_); }

private:


public:
  FontChooserDialog();
  explicit FontChooserDialog(const Glib::ustring& title);

  //Note: We renamed the parent parameter to transient_for because that is the property name.
    explicit FontChooserDialog(const Glib::ustring& title, Window& transient_for);


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
   * @relates Gtk::FontChooserDialog
   */
  GTKMM_API
  auto wrap(GtkFontChooserDialog* object, bool take_copy = false) -> Gtk::FontChooserDialog*;
} //namespace Glib


#endif /* _GTKMM_FONTCHOOSERDIALOG_H */

