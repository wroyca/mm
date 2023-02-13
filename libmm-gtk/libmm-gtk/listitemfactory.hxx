
#ifndef _GTKMM_LISTITEMFACTORY_H
#define _GTKMM_LISTITEMFACTORY_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
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


#include <libmm-glib/object.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListItemFactory = struct _GtkListItemFactory;
using GtkListItemFactoryClass = struct _GtkListItemFactoryClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ListItemFactory_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Mapping list items to widgets.
 *
 * %Gtk::ListItemFactory is one of the core concepts of handling list widgets.
 * It is the object tasked with creating widgets for items taken from a
 * Gio::ListModel when the views need them and updating them as the items
 * displayed by the view change.
 *
 * A view is usually only able to display anything after both a factory
 * and a model have been set on the view. So it is important that you do
 * not skip this step when setting up your first view.
 *
 * Because views do not display the whole list at once but only a few
 * items, they only need to maintain a few widgets at a time. They will
 * instruct the %Gtk::ListItemFactory to create these widgets and bind them
 * to the items that are currently displayed.
 * As the list model changes or the user scrolls to the list, the items will
 * change and the view will instruct the factory to bind the widgets to those
 * new items.
 *
 * The actual widgets used for displaying those widgets is provided by you.
 *
 * When the factory needs widgets created, it will create a Gtk::ListItem and
 * hand it to your code to set up a widget for. This list item will provide
 * various properties with information about what item to display and provide
 * you with some opportunities to configure its behavior. See the Gtk::ListItem
 * documentation for further details.
 *
 * Various implementations of %Gtk::ListItemFactory exist to allow you different
 * ways to provide those widgets. The most common implementations are
 * Gtk::BuilderListItemFactory which takes a Gtk::Builder .ui file and then creates
 * widgets and manages everything automatically from the information in that file
 * and Gtk::SignalListItemFactory which allows you to connect to signals with your
 * own code and retain full control over how the widgets are setup and managed.
 *
 * A %Gtk::ListItemFactory is supposed to be final - that means its behavior should
 * not change and the first widget created from it should behave the same way as
 * the last widget created from it.
 * If you intend to do changes to the behavior, it is recommended that you create
 * a new %Gtk::ListItemFactory which will allow the views to recreate its widgets.
 *
 * Once you have chosen your factory and created it, you need to set it on the
 * view widget you want to use it with, such as via Gtk::ListView::set_factory().
 * Reusing factories across different views is allowed, but very uncommon.
 *
 * @newin{3,98}
 */

class GTKMM_API ListItemFactory : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ListItemFactory;
  using CppClassType = ListItemFactory_Class;
  using BaseObjectType = GtkListItemFactory;
  using BaseClassType = GtkListItemFactoryClass;

  // noncopyable
  ListItemFactory(const ListItemFactory&) = delete;
  auto operator=(const ListItemFactory&) -> ListItemFactory& = delete;

private:  friend class ListItemFactory_Class;
  static CppClassType listitemfactory_class_;

protected:
  explicit ListItemFactory(const Glib::ConstructParams& construct_params);
  explicit ListItemFactory(GtkListItemFactory* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ListItemFactory(ListItemFactory&& src) noexcept;
  auto operator=(ListItemFactory&& src) noexcept -> ListItemFactory&;

  ~ListItemFactory() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkListItemFactory*       { return reinterpret_cast<GtkListItemFactory*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkListItemFactory* { return reinterpret_cast<GtkListItemFactory*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkListItemFactory*;

private:


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
   * @relates Gtk::ListItemFactory
   */
  GTKMM_API
  auto wrap(GtkListItemFactory* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ListItemFactory>;
}


#endif /* _GTKMM_LISTITEMFACTORY_H */

