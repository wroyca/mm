
#ifndef _GTKMM_LISTVIEW_H
#define _GTKMM_LISTVIEW_H


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

#include <libmm-gtk/listbase.hxx>
#include <libmm-gtk/selectionmodel.hxx>
#include <libmm-gtk/listitemfactory.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListView = struct _GtkListView;
using GtkListViewClass = struct _GtkListViewClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ListView_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget for displaying lists.
 *
 * %Gtk::ListView is a widget to present a view into a large dynamic list of items.
 *
 * %Gtk::ListView uses its factory to generate one row widget for each visible item
 * and shows them in a linear display, either vertically or horizontally. The
 * property_show_separators() property offers a simple way to display separators
 * between the rows.
 *
 * %Gtk::ListView allows the user to select items according to the selection
 * characteristics of the model. For models that allow
 * multiple selected items, it is possible to turn on _rubberband selection_,
 * using set_enable_rubberband().
 *
 * If you need multiple columns with headers, see Gtk::ColumnView.
 *
 * An example of using %Gtk::ListView:
 * ~~~
 * void setup_listitem_cb(const Glib::RefPtr<Gtk::ListItem>& list_item)
 * {
 *   auto image = Gtk::make_managed<Gtk::Image>();
 *   image->set_icon_size(Gtk::IconSize::LARGE);
 *   list_item->set_child(*image);
 * }
 *
 * void bind_listitem_cb(const Glib::RefPtr<Gtk::ListItem>& list_item)
 * {
 *   auto item = list_item->get_item();
 *   if (auto app_info = std::dynamic_pointer_cast<Gio::AppInfo>(item))
 *     if (auto image = dynamic_cast<Gtk::Image*>(list_item->get_child()))
 *       image->set(app_info->get_icon());
 * }
 *
 * void activate_cb(Gtk::ListView* list, guint position)
 * {
 *   if (auto model = std::dynamic_pointer_cast<Gio::ListModel>(list->get_model()))
 *   {
 *     auto item = model->get_object(position);
 *     if (auto app_info = std::dynamic_pointer_cast<Gio::AppInfo>(item))
 *       app_info->launch(std::vector<Glib::RefPtr<Gio::File>>());
 *   }
 * }
 *
 * ...
 *
 *   auto factory = Gtk::SignalListItemFactory::create();
 *   factory->signal_setup().connect(sigc::ptr_fun(setup_listitem_cb));
 *   factory->signal_bind().connect(sigc::ptr_fun(bind_listitem_cb));
 *
 *   Glib::RefPtr<Gio::ListModel> model = create_application_list();
 *
 *   auto list = Gtk::make_managed<Gtk::ListView>(
 *               Gtk::SingleSelection::create(model), factory);
 *
 *   list->signal_activate().connect(
 *     sigc::bind<0>(sigc::ptr_fun(activate_cb), list));
 *
 *   scrolled_window.set_child(*list);
 * ~~~
 * @see Gtk::SelectionModel, Gtk::ColumnView, Gtk::GridView
 *
 * @ingroup Widgets
 *
 * @newin{3,98}
 */

class GTKMM_API ListView : public ListBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ListView CppObjectType;
  typedef ListView_Class CppClassType;
  typedef GtkListView BaseObjectType;
  typedef GtkListViewClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ListView(ListView&& src) noexcept;
  auto operator=(ListView&& src) noexcept -> ListView&;

  // noncopyable
  ListView(const ListView&) = delete;
  auto operator=(const ListView&) -> ListView& = delete;

  ~ListView() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ListView_Class;
  static CppClassType listview_class_;

protected:
  explicit ListView(const Glib::ConstructParams& construct_params);
  explicit ListView(GtkListView* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkListView*       { return reinterpret_cast<GtkListView*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkListView* { return reinterpret_cast<GtkListView*>(gobject_); }

private:


public:
    explicit ListView(const Glib::RefPtr<SelectionModel>& model =  {}, const Glib::RefPtr<ListItemFactory>& factory =  {});


  /** Gets the model that's currently used to read the items displayed.
   *
   * @return The model in use.
   */
  auto get_model() -> Glib::RefPtr<SelectionModel>;

  /** Gets the model that's currently used to read the items displayed.
   *
   * @return The model in use.
   */
  auto get_model() const -> Glib::RefPtr<const SelectionModel>;

  /** Sets the model to use.
   *
   * This must be a Gtk::SelectionModel to use.
   *
   * @param model The model to use.
   */
  void set_model(const Glib::RefPtr<SelectionModel>& model);

  /** Sets the `Gtk::ListItemFactory` to use for populating list items.
   *
   * @param factory The factory to use.
   */
  void set_factory(const Glib::RefPtr<ListItemFactory>& factory);

  /** Gets the factory that's currently used to populate list items.
   *
   * @return The factory in use.
   */
  auto get_factory() -> Glib::RefPtr<ListItemFactory>;

  /** Gets the factory that's currently used to populate list items.
   *
   * @return The factory in use.
   */
  auto get_factory() const -> Glib::RefPtr<const ListItemFactory>;

  /** Sets whether the list box should show separators
   * between rows.
   *
   * @param show_separators <tt>true</tt> to show separators.
   */
  void set_show_separators(bool show_separators =  true);

  /** Returns whether the list box should show separators
   * between rows.
   *
   * @return <tt>true</tt> if the list box shows separators.
   */
  auto get_show_separators() const -> bool;

  /** Sets whether rows should be activated on single click and
   * selected on hover.
   *
   * @param single_click_activate <tt>true</tt> to activate items on single click.
   */
  void set_single_click_activate(bool single_click_activate =  true);

  /** Returns whether rows will be activated on single click and
   * selected on hover.
   *
   * @return <tt>true</tt> if rows are activated on single click.
   */
  auto get_single_click_activate() const -> bool;

  /** Sets whether selections can be changed by dragging with the mouse.
   *
   * @param enable_rubberband <tt>true</tt> to enable rubberband selection.
   */
  void set_enable_rubberband(bool enable_rubberband =  true);

  /** Returns whether rows can be selected by dragging with the mouse.
   *
   * @return <tt>true</tt> if rubberband selection is enabled.
   */
  auto get_enable_rubberband() const -> bool;

  /** Factory for populating list items.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_factory() -> Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> > ;

/** Factory for populating list items.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_factory() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >;

  /** Model for the items displayed.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<SelectionModel> > ;

/** Model for the items displayed.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >;

  /** Show separators between rows.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_separators() -> Glib::PropertyProxy< bool > ;

/** Show separators between rows.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_separators() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Activate rows on single click and select them on hover.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_single_click_activate() -> Glib::PropertyProxy< bool > ;

/** Activate rows on single click and select them on hover.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_single_click_activate() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Allow rubberband selection.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_rubberband() -> Glib::PropertyProxy< bool > ;

/** Allow rubberband selection.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_rubberband() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // no_default_handler because GtkListViewClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%activate(guint position)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a row has been activated by the user,
   * usually via activating the GtkListView|list.activate-item action.
   *
   * This allows for a convenient way to handle activation in a listview.
   * See Gtk::ListItem::set_activatable() for details on how to use
   * this signal.
   *
   * @param position Position of item to activate.
   */

  auto signal_activate() -> Glib::SignalProxy<void(guint)>;


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
   * @relates Gtk::ListView
   */
  GTKMM_API
  auto wrap(GtkListView* object, bool take_copy = false) -> Gtk::ListView*;
} //namespace Glib


#endif /* _GTKMM_LISTVIEW_H */
