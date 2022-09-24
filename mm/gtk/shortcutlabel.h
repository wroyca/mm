// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_SHORTCUTLABEL_H
#define _GTKMM_SHORTCUTLABEL_H


#include <mm/glib/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2016 The gtkmm Development Team
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

#include <mm/gtk/widget.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutLabel = struct _GtkShortcutLabel;
using GtkShortcutLabelClass = struct _GtkShortcutLabelClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ShortcutLabel_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Displays a keyboard shortcut.
 *
 * %Gtk::ShortcutLabel is a widget that represents a single keyboard shortcut
 * or gesture in the user interface.
 *
 * @see CellRendererAccel
 * @newin{3,22}
 *
 * @ingroup Widgets
 */

class GTKMM_API ShortcutLabel : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ShortcutLabel CppObjectType;
  typedef ShortcutLabel_Class CppClassType;
  typedef GtkShortcutLabel BaseObjectType;
  typedef GtkShortcutLabelClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ShortcutLabel(ShortcutLabel&& src) noexcept;
  auto operator=(ShortcutLabel&& src) noexcept -> ShortcutLabel&;

  // noncopyable
  ShortcutLabel(const ShortcutLabel&) = delete;
  auto operator=(const ShortcutLabel&) -> ShortcutLabel& = delete;

  ~ShortcutLabel() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ShortcutLabel_Class;
  static CppClassType shortcutlabel_class_;

protected:
  explicit ShortcutLabel(const Glib::ConstructParams& construct_params);
  explicit ShortcutLabel(GtkShortcutLabel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkShortcutLabel*       { return reinterpret_cast<GtkShortcutLabel*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkShortcutLabel* { return reinterpret_cast<GtkShortcutLabel*>(gobject_); }

private:


public:
  ShortcutLabel();

  /** Creates a %ShortcutLabel with accelerator set.
   *
   * @param accelerator The initial accelerator.
   *   See ShortcutsShortcut::property_accelerator() for the accepted syntax.
   *
   * @newin{3,22}
   */
    explicit ShortcutLabel(const Glib::ustring& accelerator);


  /** Retrieves the current accelerator of @a self.
   *
   * @return The current accelerator.
   */
  auto get_accelerator() const -> Glib::ustring;

  /** Sets the accelerator to be displayed by @a self.
   *
   * @param accelerator The new accelerator.
   */
  void set_accelerator(const Glib::ustring& accelerator);

  /** Retrieves the text that is displayed when no accelerator is set.
   *
   * @return The current text displayed when no
   * accelerator is set.
   */
  auto get_disabled_text() const -> Glib::ustring;

  /** Sets the text to be displayed by @a self when no accelerator is set.
   *
   * @param disabled_text The text to be displayed when no accelerator is set.
   */
  void set_disabled_text(const Glib::ustring& disabled_text);

  /** The accelerator that @a self displays.
   *
   * See Gtk::ShortcutsShortcut::property_accelerator()
   * for the accepted syntax.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accelerator() -> Glib::PropertyProxy< Glib::ustring > ;

/** The accelerator that @a self displays.
   *
   * See Gtk::ShortcutsShortcut::property_accelerator()
   * for the accepted syntax.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accelerator() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The text that is displayed when no accelerator is set.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_disabled_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text that is displayed when no accelerator is set.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_disabled_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  // There are no signals or vfuncs.


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
   * @relates Gtk::ShortcutLabel
   */
  GTKMM_API
  auto wrap(GtkShortcutLabel* object, bool take_copy = false) -> Gtk::ShortcutLabel*;
} //namespace Glib


#endif /* _GTKMM_SHORTCUTLABEL_H */

