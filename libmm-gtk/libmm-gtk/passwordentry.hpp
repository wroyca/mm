
#ifndef _GTKMM_PASSWORDENTRY_H
#define _GTKMM_PASSWORDENTRY_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The gtkmm Development Team
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

#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/editable.hpp>
#include <libmm-gio/menumodel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPasswordEntry = struct _GtkPasswordEntry;
using GtkPasswordEntryClass = struct _GtkPasswordEntryClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API PasswordEntry_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** An entry for secrets.
 *
 * %Gtk::PasswordEntry is an entry that has been tailored for
 * entering secrets. It does not show its contents in clear text,
 * does not allow to copy it to the clipboard, and it shows a
 * warning when Caps-Lock is engaged.
 *
 * Optionally, it can offer a way to reveal the contents in clear text.
 *
 * %Gtk::PasswordEntry provides only minimal API and should be used with the
 * Gtk::Editable API.
 *
 * @newin{3,96}
 * @ingroup Widgets
 */

class GTKMM_API PasswordEntry : public Widget, public Editable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef PasswordEntry CppObjectType;
  typedef PasswordEntry_Class CppClassType;
  typedef GtkPasswordEntry BaseObjectType;
  typedef GtkPasswordEntryClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  PasswordEntry(PasswordEntry&& src) noexcept;
  auto operator=(PasswordEntry&& src) noexcept -> PasswordEntry&;

  // noncopyable
  PasswordEntry(const PasswordEntry&) = delete;
  auto operator=(const PasswordEntry&) -> PasswordEntry& = delete;

  ~PasswordEntry() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class PasswordEntry_Class;
  static CppClassType passwordentry_class_;

protected:
  explicit PasswordEntry(const Glib::ConstructParams& construct_params);
  explicit PasswordEntry(GtkPasswordEntry* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkPasswordEntry*       { return reinterpret_cast<GtkPasswordEntry*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPasswordEntry* { return reinterpret_cast<GtkPasswordEntry*>(gobject_); }

private:


public:
  PasswordEntry();


  /** Sets whether the entry should have a clickable icon
   * to reveal the contents.
   *
   * Setting this to <tt>false</tt> also hides the text again.
   *
   * @param show_peek_icon Whether to show the peek icon.
   */
  void set_show_peek_icon(bool show_peek_icon =  true);

  /** Returns whether the entry is showing an icon to
   * reveal the contents.
   *
   * @return <tt>true</tt> if an icon is shown.
   */
  auto get_show_peek_icon() const -> bool;


  /** Sets a menu model to add when constructing
   * the context menu for @a entry.
   *
   * @param model A `Gio::MenuModel`.
   */
  void set_extra_menu(const Glib::RefPtr<Gio::MenuModel>& model);

  /** Gets the menu model set with set_extra_menu().
   *
   * @return The menu model.
   */
  auto get_extra_menu() -> Glib::RefPtr<Gio::MenuModel>;

  /** Gets the menu model set with set_extra_menu().
   *
   * @return The menu model.
   */
  auto get_extra_menu() const -> Glib::RefPtr<const Gio::MenuModel>;


  /** The text that will be displayed in the `Gtk::PasswordEntry`
   * when it is empty and unfocused.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text that will be displayed in the `Gtk::PasswordEntry`
   * when it is empty and unfocused.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether to activate the default widget when Enter is pressed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activates_default() -> Glib::PropertyProxy< bool > ;

/** Whether to activate the default widget when Enter is pressed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activates_default() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether to show an icon for revealing the content.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_peek_icon() -> Glib::PropertyProxy< bool > ;

/** Whether to show an icon for revealing the content.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_peek_icon() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** A menu model whose contents will be appended to
   * the context menu.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_extra_menu() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > ;

/** A menu model whose contents will be appended to
   * the context menu.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_extra_menu() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::PasswordEntry
   */
  GTKMM_API
  auto wrap(GtkPasswordEntry* object, bool take_copy = false) -> Gtk::PasswordEntry*;
} //namespace Glib


#endif /* _GTKMM_PASSWORDENTRY_H */

