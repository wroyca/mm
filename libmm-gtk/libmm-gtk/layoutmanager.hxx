
#ifndef _GTKMM_LAYOUTMANAGER_H
#define _GTKMM_LAYOUTMANAGER_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-glib/object.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-gtk/enums.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLayoutManager = struct _GtkLayoutManager;
using GtkLayoutManagerClass = struct _GtkLayoutManagerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API LayoutManager_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API LayoutChild;
class GTKMM_API Widget;

/** Base class for layout manager.
 *
 * %Layout managers are delegate classes that handle the preferred size
 * and the allocation of a container widget.
 *
 * You typically subclass %Gtk::LayoutManager if you want to implement a
 * layout policy for the children of a widget, or if you want to determine
 * the size of a widget depending on its contents.
 *
 * Each Gtk::Widget can only have one %Gtk::LayoutManager instance associated to it
 * at any given time; it is possible, though, to replace the layout manager
 * instance using Gtk::Widget::set_layout_manager().
 *
 * ## Layout properties
 *
 * A layout manager can expose properties for controlling the layout of
 * each child, by creating an object type derived from Gtk::LayoutChild
 * and installing the properties on it as normal GObject properties.
 *
 * Each Gtk::LayoutChild instance storing the layout properties for a
 * specific child is created through the get_layout_child()
 * method; a %Gtk::LayoutManager controls the creation of its Gtk::LayoutChild
 * instances by overriding the create_layout_child_vfunc() virtual function.
 *
 * Gtk::LayoutChild::property_layout_manager() and Gtk::LayoutChild::property_child_widget()
 * on the newly created Gtk::LayoutChild instance are mandatory. The
 * %Gtk::LayoutManager will cache the newly created Gtk::LayoutChild instance until
 * the widget is removed from its parent, or the parent removes the layout manager.
 *
 * Each %Gtk::LayoutManager instance creating a Gtk::LayoutChild should use
 * get_layout_child() every time it needs to query the
 * layout properties; each Gtk::LayoutChild instance should call
 * layout_changed() every time a property is updated, in
 * order to queue a new size measuring and allocation.
 *
 * @newin{3,96}
 */

class GTKMM_API LayoutManager : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = LayoutManager;
  using CppClassType = LayoutManager_Class;
  using BaseObjectType = GtkLayoutManager;
  using BaseClassType = GtkLayoutManagerClass;

  // noncopyable
  LayoutManager(const LayoutManager&) = delete;
  auto operator=(const LayoutManager&) -> LayoutManager& = delete;

private:  friend class LayoutManager_Class;
  static CppClassType layoutmanager_class_;

protected:
  explicit LayoutManager(const Glib::ConstructParams& construct_params);
  explicit LayoutManager(GtkLayoutManager* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  LayoutManager(LayoutManager&& src) noexcept;
  auto operator=(LayoutManager&& src) noexcept -> LayoutManager&;

  ~LayoutManager() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkLayoutManager*       { return reinterpret_cast<GtkLayoutManager*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkLayoutManager* { return reinterpret_cast<GtkLayoutManager*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkLayoutManager*;

private:


protected:
  /** There is no create() method that corresponds to this constructor,
   * because only derived classes shall be created.
   */
  LayoutManager();

public:
  // No create() because only derived classes shall be instantiated.


  /** Measures the size of the @a widget using @a manager, for the
   * given @a orientation and size.
   *
   * See the Gtk::Widget documentation on layout management for
   * more details.
   *
   * @param widget The `Gtk::Widget` using @a manager.
   * @param orientation The orientation to measure.
   * @param for_size Size for the opposite of @a orientation; for instance, if
   * the @a orientation is Gtk::Orientation::HORIZONTAL, this is the height
   * of the widget; if the @a orientation is Gtk::Orientation::VERTICAL, this
   * is the width of the widget. This allows to measure the height for the
   * given width, and the width for the given height. Use -1 if the size
   * is not known.
   * @param minimum The minimum size for the given size and
   * orientation.
   * @param natural The natural, or preferred size for the
   * given size and orientation.
   * @param minimum_baseline The baseline position for the
   * minimum size.
   * @param natural_baseline The baseline position for the
   * natural size.
   */
  void measure(Widget& widget, Orientation orientation, int for_size, int& minimum, int& natural, int& minimum_baseline, int& natural_baseline) const;

  /** Assigns the given @a width, @a height, and @a baseline to
   * a @a widget, and computes the position and sizes of the children of
   * the @a widget using the layout management policy of @a manager.
   *
   * @param widget The `Gtk::Widget` using @a manager.
   * @param width The new width of the @a widget.
   * @param height The new height of the @a widget.
   * @param baseline The baseline position of the @a widget, or -1.
   */
  void allocate(Widget& widget, int width, int height, int baseline);

  /** Retrieves the request mode of @a manager.
   *
   * @return A `Gtk::SizeRequestMode`.
   */
  auto get_request_mode() const -> SizeRequestMode;

  /** Retrieves the `Gtk::Widget` using the given `Gtk::LayoutManager`.
   *
   * @return A `Gtk::Widget`.
   */
  auto get_widget() -> Widget*;

  /** Retrieves the `Gtk::Widget` using the given `Gtk::LayoutManager`.
   *
   * @return A `Gtk::Widget`.
   */
  auto get_widget() const -> const Widget*;

  /** Queues a resize on the `Gtk::Widget` using @a manager, if any.
   *
   * This function should be called by subclasses of `Gtk::LayoutManager`
   * in response to changes to their layout management policies.
   */
  void layout_changed();

  /** Retrieves a `Gtk::LayoutChild` instance for the `Gtk::LayoutManager`,
   * creating one if necessary.
   *
   * The @a child widget must be a child of the widget using @a manager.
   *
   * The `Gtk::LayoutChild` instance is owned by the `Gtk::LayoutManager`,
   * and is guaranteed to exist as long as @a child is a child of the
   * `Gtk::Widget` using the given `Gtk::LayoutManager`.
   *
   * @param child A `Gtk::Widget`.
   * @return A `Gtk::LayoutChild`.
   */
  auto get_layout_child(Widget& child) -> Glib::RefPtr<LayoutChild>;

  /** Retrieves a `Gtk::LayoutChild` instance for the `Gtk::LayoutManager`,
   * creating one if necessary.
   *
   * The @a child widget must be a child of the widget using @a manager.
   *
   * The `Gtk::LayoutChild` instance is owned by the `Gtk::LayoutManager`,
   * and is guaranteed to exist as long as @a child is a child of the
   * `Gtk::Widget` using the given `Gtk::LayoutManager`.
   *
   * @param child A `Gtk::Widget`.
   * @return A `Gtk::LayoutChild`.
   */
  auto get_layout_child(Widget& child) const -> Glib::RefPtr<const LayoutChild>;

protected:
    virtual auto get_request_mode_vfunc(const Widget& widget) const -> SizeRequestMode;

    virtual void measure_vfunc(const Widget& widget, Orientation orientation, int for_size, int& minimum, int& natural, int& minimum_baseline, int& natural_baseline) const;

    virtual void allocate_vfunc(const Widget& widget, int width, int height, int baseline);


    virtual auto create_layout_child_vfunc(const Widget& widget, const Widget& for_child) -> Glib::RefPtr<LayoutChild>;

    virtual void root_vfunc();

    virtual void unroot_vfunc();


  // There are no signals or properties.


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
   * @relates Gtk::LayoutManager
   */
  GTKMM_API
  auto wrap(GtkLayoutManager* object, bool take_copy = false) -> Glib::RefPtr<Gtk::LayoutManager>;
}


#endif /* _GTKMM_LAYOUTMANAGER_H */

