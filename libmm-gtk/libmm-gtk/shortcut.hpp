
#ifndef _GTKMM_SHORTCUT_H
#define _GTKMM_SHORTCUT_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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


#include <mm/glib/object.hpp>
#include <mm/gtk/shortcutaction.hpp>
#include <mm/gtk/shortcuttrigger.hpp>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Shortcut_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** An object describing a keyboard shortcut.
 *
 * %Gtk::Shortcut is the low level object used for managing keyboard shortcuts.
 * It contains a description of how to trigger the shortcut via a
 * Gtk::ShortcutTrigger and a way to activate the shortcut on a widget
 * via Gtk::ShortcutAction.
 *
 * The actual work is usually done via Gtk::ShortcutController, which
 * decides if and when to activate a shortcut. Using that controller
 * directly however is rarely necessary as various higher level
 * convenience APIs exist on Widgets that make it easier to use
 * shortcuts in GTK.
 *
 * %Gtk::Shortcut does provide functionality to make it easy for users
 * to work with shortcuts, either by providing informational strings
 * for display purposes or by allowing shortcuts to be configured.
 *
 * @see Gtk::ShortcutController, Gtk::ShortcutAction, Gtk::ShortcutTrigger

 * @ingroup Gestures
 * @newin{3,98}
 */

class GTKMM_API Shortcut : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Shortcut;
  using CppClassType = Shortcut_Class;
  using BaseObjectType = GtkShortcut;
  using BaseClassType = GtkShortcutClass;

  // noncopyable
  Shortcut(const Shortcut&) = delete;
  auto operator=(const Shortcut&) -> Shortcut& = delete;

private:  friend class Shortcut_Class;
  static CppClassType shortcut_class_;

protected:
  explicit Shortcut(const Glib::ConstructParams& construct_params);
  explicit Shortcut(GtkShortcut* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Shortcut(Shortcut&& src) noexcept;
  auto operator=(Shortcut&& src) noexcept -> Shortcut&;

  ~Shortcut() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkShortcut*       { return reinterpret_cast<GtkShortcut*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkShortcut* { return reinterpret_cast<GtkShortcut*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkShortcut*;

private:


protected:
    explicit Shortcut(const Glib::RefPtr<const ShortcutTrigger>& trigger, const Glib::RefPtr<const ShortcutAction>& action);


public:

  static auto create(const Glib::RefPtr<const ShortcutTrigger>& trigger, const Glib::RefPtr<const ShortcutAction>& action) -> Glib::RefPtr<Shortcut>;


  // gtk_shortcut_set_trigger() and gtk_shortcut_set_action() don't take a ref (transfer full).


  // ShortcutTrigger, ShortcutAction and Glib::VariantBase are immutable.
  // No need for non-const get-methods.

  /** Gets the trigger used to trigger @a self.
   *
   * @return The trigger used.
   */
  auto get_trigger() const -> Glib::RefPtr<ShortcutTrigger>;

  /** Sets the new trigger for @a self to be @a trigger.
   *
   * @param trigger The new trigger.
   * If the @a trigger is <tt>nullptr</tt>, the never trigger will be used.
   */
  void set_trigger(const Glib::RefPtr<const ShortcutTrigger>& trigger);

  /** Gets the action that is activated by this shortcut.
   *
   * @return The action.
   */
  auto get_action() const -> Glib::RefPtr<ShortcutAction>;

  /** Sets the new action for @a self to be @a action.
   *
   * @param action The new action.
   * If the @a action is <tt>nullptr</tt>, the nothing action will be used.
   */
  void set_trigger(const Glib::RefPtr<const ShortcutAction>& action);

  /** Gets the arguments that are passed when activating the shortcut.
   *
   * @return The arguments.
   */
  auto get_arguments() const -> Glib::VariantBase;

  /** Sets the arguments to pass when activating the shortcut.
   *
   * @param args Arguments to pass when activating @a self.
   */
  void set_arguments(const Glib::VariantBase& args) const;

  /** The trigger that triggers this shortcut.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_trigger() -> Glib::PropertyProxy< Glib::RefPtr<ShortcutTrigger> > ;

/** The trigger that triggers this shortcut.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_trigger() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ShortcutTrigger> >;

  /** The action that gets activated by this shortcut.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_action() -> Glib::PropertyProxy< Glib::RefPtr<ShortcutAction> > ;

/** The action that gets activated by this shortcut.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_action() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ShortcutAction> >;

  /** Arguments passed to activation.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_arguments() -> Glib::PropertyProxy< Glib::VariantBase > ;

/** Arguments passed to activation.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_arguments() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantBase >;


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
   * @relates Gtk::Shortcut
   */
  GTKMM_API
  auto wrap(GtkShortcut* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Shortcut>;
}


#endif /* _GTKMM_SHORTCUT_H */

