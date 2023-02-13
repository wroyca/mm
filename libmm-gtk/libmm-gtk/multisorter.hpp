
#ifndef _GTKMM_MULTISORTER_H
#define _GTKMM_MULTISORTER_H


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

#include <libmm-gtk/sorter.hpp>
#include <libmm-gtk/buildable.hpp>
#include <libmm-gio/listmodel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MultiSorter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Combining multiple sorters.
 *
 * %Gtk::MultiSorter combines multiple sorters by trying them
 * in turn. If the first sorter compares two items as equal,
 * the second is tried next, and so on.
 *
 * @newin{3,98}
 */

class GTKMM_API MultiSorter : public Sorter, public Gio::ListModel, public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MultiSorter;
  using CppClassType = MultiSorter_Class;
  using BaseObjectType = GtkMultiSorter;
  using BaseClassType = GtkMultiSorterClass;

  // noncopyable
  MultiSorter(const MultiSorter&) = delete;
  auto operator=(const MultiSorter&) -> MultiSorter& = delete;

private:  friend class MultiSorter_Class;
  static CppClassType multisorter_class_;

protected:
  explicit MultiSorter(const Glib::ConstructParams& construct_params);
  explicit MultiSorter(GtkMultiSorter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MultiSorter(MultiSorter&& src) noexcept;
  auto operator=(MultiSorter&& src) noexcept -> MultiSorter&;

  ~MultiSorter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkMultiSorter*       { return reinterpret_cast<GtkMultiSorter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMultiSorter* { return reinterpret_cast<GtkMultiSorter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkMultiSorter*;

private:


protected:
  MultiSorter();

public:

  static auto create() -> Glib::RefPtr<MultiSorter>;


  /** Add @a sorter to @a self to use for sorting at the end.
   *
   *  @a self will consult all existing sorters before it will
   * sort with the given @a sorter.
   *
   * @param sorter A sorter to add.
   */
  void append(const Glib::RefPtr<Sorter>& sorter);

  /** Removes the sorter at the given @a position from the list of sorter
   * used by @a self.
   *
   * If @a position is larger than the number of sorters, nothing happens.
   *
   * @param position Position of sorter to remove.
   */
  void remove(guint position);

  /** The type of items. See Gio::ListModel::get_item_type().
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >;


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
   * @relates Gtk::MultiSorter
   */
  GTKMM_API
  auto wrap(GtkMultiSorter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MultiSorter>;
}


#endif /* _GTKMM_MULTISORTER_H */

