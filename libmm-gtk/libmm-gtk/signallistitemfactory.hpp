
#ifndef _GTKMM_SIGNALLISTITEMFACTORY_H
#define _GTKMM_SIGNALLISTITEMFACTORY_H


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

#include <mm/gtk/listitem.hpp>
#include <mm/gtk/listitemfactory.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSignalListItemFactory = struct _GtkSignalListItemFactory;
using GtkSignalListItemFactoryClass = struct _GtkSignalListItemFactoryClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SignalListItemFactory_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A listitem factory providing signals.
 *
 * %Gtk::SignalListItemFactory is a Gtk::ListItemFactory that provides signals
 * that user code can connect to to manage listitems.
 * Signals are emitted for every listitem in the same order:
 *
 *  1. signal_setup() is emitted to set up permanent things
 *  on the listitem. This usually means constructing the widgets used in the
 *  row and adding them to the listitem.
 *
 *  2. signal_bind() is emitted to bind the item passed via
 *  Gtk::ListItem::property_item() to the widgets that have been
 *  created in step 1 or to add item-specific widgets. Signals are
 *  connected to listen to changes - both to changes in the item to
 *  update the widgets or to changes in the widgets to update the
 *  item. After this signal has been called, the listitem may be shown
 *  in a list widget.
 *
 *  3. signal_unbind() is emitted to undo everything done in step 2.
 *  Usually this means disconnecting signal handlers. Once this signal
 *  has been called, the listitem will no longer be used in a list
 *  widget.
 *
 *  4. signal_bind() and signal_unbind() may be emitted multiple times
 *  again to bind the listitem for use with new items. By reusing
 *  listitems, potentially costly setup can be avoided. However, it
 *  means code needs to make sure to properly clean up the listitem in
 *  step 3 so that no information from the previous use leaks into the
 *  next use.
 *
 * 5. signal_teardown() is emitted to allow undoing the effects of
 * signal_setup(). After this signal was emitted on a listitem, the
 * listitem will be destroyed and not be used again.
 *
 * Note that during the signal emissions, changing properties on the
 * Gtk::ListItems passed will not trigger notify signals as the listitem's
 * notifications are frozen. See Glib::ObjectBase::freeze_notify() for details.
 *
 * For tracking changes in other properties in the Gtk::ListItem, the
 * Gtk::ListItem notify signal is recommended. The signal can be connected
 * in the signal_setup() signal and removed again during signal_teardown().
 *
 * @see Gtk::ListItemFactory
 * @newin{3,98}
 */

class GTKMM_API SignalListItemFactory : public ListItemFactory
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SignalListItemFactory;
  using CppClassType = SignalListItemFactory_Class;
  using BaseObjectType = GtkSignalListItemFactory;
  using BaseClassType = GtkSignalListItemFactoryClass;

  // noncopyable
  SignalListItemFactory(const SignalListItemFactory&) = delete;
  auto operator=(const SignalListItemFactory&) -> SignalListItemFactory& = delete;

private:  friend class SignalListItemFactory_Class;
  static CppClassType signallistitemfactory_class_;

protected:
  explicit SignalListItemFactory(const Glib::ConstructParams& construct_params);
  explicit SignalListItemFactory(GtkSignalListItemFactory* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SignalListItemFactory(SignalListItemFactory&& src) noexcept;
  auto operator=(SignalListItemFactory&& src) noexcept -> SignalListItemFactory&;

  ~SignalListItemFactory() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSignalListItemFactory*       { return reinterpret_cast<GtkSignalListItemFactory*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSignalListItemFactory* { return reinterpret_cast<GtkSignalListItemFactory*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSignalListItemFactory*;

private:


protected:
  SignalListItemFactory();

public:

  static auto create() -> Glib::RefPtr<SignalListItemFactory>;


  // no_default_handler because GtkSignalListItemFactoryClass is private.
  // Gtk now declares these signals as taking a GObject*. We can't make such a
  // change in gtkmm. It would break API, and perhaps ABI.
  // Fixed by gtk/src/gtk_signals.defs.patch
  // https://gitlab.gnome.org/GNOME/gtk/-/issues/5056


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%setup(const Glib::RefPtr<ListItem>& list_item)</tt>
   *
   * Flags: Run First
   *
   * Emitted when a new listitem has been created and needs to be setup for use.
   *
   * It is the first signal emitted for every listitem.
   *
   * The signal_teardown() signal is the opposite
   * of this signal and can be used to undo everything done in this signal.
   *
   * @param list_item The `Glib::Object` to set up.
   */

  auto signal_setup() -> Glib::SignalProxy<void(const Glib::RefPtr<ListItem>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%bind(const Glib::RefPtr<ListItem>& list_item)</tt>
   *
   * Flags: Run First
   *
   * Emitted when an object has been bound, for example when a
   * new Gtk::ListItem::property_item() has been set on a
   * `Gtk::ListItem` and should be bound for use.
   *
   * After this signal was emitted, the object might be shown in
   * a Gtk::ListView or other widget.
   *
   * The signal_unbind() signal is the
   * opposite of this signal and can be used to undo everything done
   * in this signal.
   *
   * @param list_item The `Glib::Object` to bind.
   */

  auto signal_bind() -> Glib::SignalProxy<void(const Glib::RefPtr<ListItem>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%unbind(const Glib::RefPtr<ListItem>& list_item)</tt>
   *
   * Flags: Run First
   *
   * Emitted when a object has been unbound from its item, for example when
   * a listitem was removed from use in a list widget
   * and its new Gtk::ListItem::property_item() is about to be unset.
   *
   * This signal is the opposite of the signal_bind()
   * signal and should be used to undo everything done in that signal.
   *
   * @param list_item The `Glib::Object` to unbind.
   */

  auto signal_unbind() -> Glib::SignalProxy<void(const Glib::RefPtr<ListItem>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%teardown(const Glib::RefPtr<ListItem>& list_item)</tt>
   *
   * Flags: Run First
   *
   * Emitted when an object is about to be destroyed.
   *
   * It is the last signal ever emitted for this @a list_item.
   *
   * This signal is the opposite of the signal_setup()
   * signal and should be used to undo everything done in that signal.
   *
   * @param list_item The `Glib::Object` to tear down.
   */

  auto signal_teardown() -> Glib::SignalProxy<void(const Glib::RefPtr<ListItem>&)>;


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
   * @relates Gtk::SignalListItemFactory
   */
  GTKMM_API
  auto wrap(GtkSignalListItemFactory* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SignalListItemFactory>;
}


#endif /* _GTKMM_SIGNALLISTITEMFACTORY_H */

