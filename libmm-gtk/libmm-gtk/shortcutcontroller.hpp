
#ifndef _GTKMM_SHORTCUTCONTROLLER_H
#define _GTKMM_SHORTCUTCONTROLLER_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gtk/eventcontroller.hpp>
#include <libmm-gtk/buildable.hpp>
#include <libmm-gio/listmodel.hpp>
#include <libmm-gdk/enums.hpp>
#include <libmm-gtk/enums.hpp>
#include <libmm-gtk/shortcut.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutController = struct _GtkShortcutController;
using GtkShortcutControllerClass = struct _GtkShortcutControllerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ShortcutController_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Event controller for shortcuts.
 *
 * %Gtk::ShortcutController is an event controller that manages shortcuts.
 *
 * Most common shortcuts are using this controller implicitly, e.g. by
 * adding a mnemonic underline to a Gtk::Label, or by installing a key
 * binding using gtk_widget_class_add_binding(), or by adding accelerators
 * to global actions using Gtk::Application::set_accels_for_action().
 *
 * But it is possible to create your own shortcut controller, and add
 * shortcuts to it.
 *
 * %Gtk::ShortcutController implements Gio::ListModel for querying the shortcuts that
 * have been added to it.
 *
 * ## ShortcutController as a Buildable
 *
 * ShortcutControllers can be created in ui files to set up shortcuts
 * in the same place as the widgets.
 *
 * An example of a UI definition fragment with GtkShortcutController:
 * @code
 *   <object class='GtkButton'>
 *     <child>
 *       <object class='GtkShortcutController'>
 *         <property name='scope'>managed</property>
 *         <child>
 *           <object class='GtkShortcut'>
 *             <property name='trigger'>&lt;Control&gt;k</property>
 *             <property name='action'>activate</property>
 *           </object>
 *         </child>
 *       </object>
 *     </child>
 *   </object>
 * @endcode
 *
 * @newin{3,98}
 *
 * @ingroup Gestures
 */

class GTKMM_API ShortcutController : public EventController, public Gio::ListModel, public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ShortcutController;
  using CppClassType = ShortcutController_Class;
  using BaseObjectType = GtkShortcutController;
  using BaseClassType = GtkShortcutControllerClass;

  // noncopyable
  ShortcutController(const ShortcutController&) = delete;
  auto operator=(const ShortcutController&) -> ShortcutController& = delete;

private:  friend class ShortcutController_Class;
  static CppClassType shortcutcontroller_class_;

protected:
  explicit ShortcutController(const Glib::ConstructParams& construct_params);
  explicit ShortcutController(GtkShortcutController* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ShortcutController(ShortcutController&& src) noexcept;
  auto operator=(ShortcutController&& src) noexcept -> ShortcutController&;

  ~ShortcutController() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkShortcutController*       { return reinterpret_cast<GtkShortcutController*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkShortcutController* { return reinterpret_cast<GtkShortcutController*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkShortcutController*;

private:


protected:
  ShortcutController();
    explicit ShortcutController(const Glib::RefPtr<Gio::ListModel>& model);


public:

  static auto create() -> Glib::RefPtr<ShortcutController>;


  /** Creates a new shortcut controller that takes its shortcuts from
   * the given list model.
   *
   * A controller created by this function does not let you add or
   * remove individual shortcuts using the shortcut controller api,
   * but you can change the contents of the model.
   *
   * @param model A ListModel containing shortcuts.
   * @return A newly created shortcut controller.
   */

  static auto create(const Glib::RefPtr<Gio::ListModel>& model) -> Glib::RefPtr<ShortcutController>;


  /** Sets the controller to use the given modifier for mnemonics.
   *
   * The mnemonics modifiers determines which modifiers need to be pressed to allow
   * activation of shortcuts with mnemonics triggers.
   *
   * GTK normally uses the Alt modifier for mnemonics, except in `Gtk::PopoverMenu`s,
   * where mnemonics can be triggered without any modifiers. It should be very
   * rarely necessary to change this, and doing so is likely to interfere with
   * other shortcuts.
   *
   * This value is only relevant for local shortcut controllers. Global and managed
   * shortcut controllers will have their shortcuts activated from other places which
   * have their own modifiers for activating mnemonics.
   *
   * @param modifiers The new mnemonics_modifiers to use.
   */
  void set_mnemonics_modifiers(Gdk::ModifierType modifiers);

  /** Gets the mnemonics modifiers for when this controller activates its shortcuts.
   *
   * @return The controller's mnemonics modifiers.
   */
  auto get_mnemonics_modifiers() const -> Gdk::ModifierType;


  /** Sets the controller to have the given @a scope.
   *
   * The scope allows shortcuts to be activated outside of the normal
   * event propagation. In particular, it allows installing global
   * keyboard shortcuts that can be activated even when a widget does
   * not have focus.
   *
   * With Gtk::ShortcutScope::LOCAL, shortcuts will only be activated
   * when the widget has focus.
   *
   * @param scope The new scope to use.
   */
  void set_scope(ShortcutScope scope);

#ifndef GTKMM_DISABLE_DEPRECATED

  /** Gets the scope for when this controller activates its shortcuts.
   *
   * See set_scope() for details.
   *
   * @deprecated Use get_scope() instead.
   *
   * @return The controller's scope.
   */
  auto set_scope() const -> ShortcutScope;
#endif // GTKMM_DISABLE_DEPRECATED


  /** Gets the scope for when this controller activates its shortcuts.
   *
   * See set_scope() for details.
   *
   * @newin{4,2}
   *
   * @return The controller's scope.
   */
  auto get_scope() const -> ShortcutScope;

  // gtk_shortcut_controller_add_shortcut() does not take a ref (transfer full).


  /** Adds @a shortcut to the list of shortcuts handled by @a self.
   *
   * If this controller uses an external shortcut list, this
   * function does nothing.
   *
   * @param shortcut A `Gtk::Shortcut`.
   */
  void add_shortcut(const Glib::RefPtr<Shortcut>& shortcut);


  /** Removes @a shortcut from the list of shortcuts handled by @a self.
   *
   * If @a shortcut had not been added to @a controller or this controller
   * uses an external shortcut list, this function does nothing.
   *
   * @param shortcut A `Gtk::Shortcut`.
   */
  void remove_shortcut(const Glib::RefPtr<const Shortcut>& shortcut);

  /** The type of items. See Gio::ListModel::get_item_type().
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >;


  /** The modifiers that need to be pressed to allow mnemonics activation.
   *
   * Default value: Gdk::ModifierType::ALT_MASK
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mnemonic_modifiers() -> Glib::PropertyProxy< Gdk::ModifierType > ;

/** The modifiers that need to be pressed to allow mnemonics activation.
   *
   * Default value: Gdk::ModifierType::ALT_MASK
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mnemonic_modifiers() const -> Glib::PropertyProxy_ReadOnly< Gdk::ModifierType >;

  /** The number of items. See Gio::ListModel::get_n_items().
   *
   * @newin{4,8}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;


  /** What scope the shortcuts will be handled in.
   *
   * Default value: Gtk::ShortcutScope::LOCAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scope() -> Glib::PropertyProxy< ShortcutScope > ;

/** What scope the shortcuts will be handled in.
   *
   * Default value: Gtk::ShortcutScope::LOCAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scope() const -> Glib::PropertyProxy_ReadOnly< ShortcutScope >;

  // The "model" property is write-pnly, construct-only. Can't be wrapped.


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
   * @relates Gtk::ShortcutController
   */
  GTKMM_API
  auto wrap(GtkShortcutController* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ShortcutController>;
}


#endif /* _GTKMM_SHORTCUTCONTROLLER_H */

