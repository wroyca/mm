
#ifndef _GTKMM_FONTCHOOSERWIDGET_H
#define _GTKMM_FONTCHOOSERWIDGET_H


#include <mm/glib/ustring.hpp>
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


#include <mm/gtk/widget.hpp>
#include <mm/gtk/fontchooser.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFontChooserWidget = struct _GtkFontChooserWidget;
using GtkFontChooserWidgetClass = struct _GtkFontChooserWidgetClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FontChooserWidget_Class; } // namespace Gtk
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
 * @ingroup Widgets
 * @newin{3,2}
 */

class GTKMM_API FontChooserWidget
  : public Widget,
    public FontChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FontChooserWidget CppObjectType;
  typedef FontChooserWidget_Class CppClassType;
  typedef GtkFontChooserWidget BaseObjectType;
  typedef GtkFontChooserWidgetClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  FontChooserWidget(FontChooserWidget&& src) noexcept;
  auto operator=(FontChooserWidget&& src) noexcept -> FontChooserWidget&;

  // noncopyable
  FontChooserWidget(const FontChooserWidget&) = delete;
  auto operator=(const FontChooserWidget&) -> FontChooserWidget& = delete;

  ~FontChooserWidget() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class FontChooserWidget_Class;
  static CppClassType fontchooserwidget_class_;

protected:
  explicit FontChooserWidget(const Glib::ConstructParams& construct_params);
  explicit FontChooserWidget(GtkFontChooserWidget* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkFontChooserWidget*       { return reinterpret_cast<GtkFontChooserWidget*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFontChooserWidget* { return reinterpret_cast<GtkFontChooserWidget*>(gobject_); }

private:


public:
  FontChooserWidget();


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
   * @relates Gtk::FontChooserWidget
   */
  GTKMM_API
  auto wrap(GtkFontChooserWidget* object, bool take_copy = false) -> Gtk::FontChooserWidget*;
} //namespace Glib


#endif /* _GTKMM_FONTCHOOSERWIDGET_H */

