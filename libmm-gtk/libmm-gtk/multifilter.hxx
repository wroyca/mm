
#ifndef _GTKMM_MULTIFILTER_H
#define _GTKMM_MULTIFILTER_H


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

#include <libmm-gtk/filter.hxx>
#include <libmm-gtk/buildable.hxx>
#include <libmm-gio/listmodel.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMultiFilter = struct _GtkMultiFilter;
using GtkMultiFilterClass = struct _GtkMultiFilterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MultiFilter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAnyFilter = struct _GtkAnyFilter;
using GtkAnyFilterClass = struct _GtkAnyFilterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API AnyFilter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEveryFilter = struct _GtkEveryFilter;
using GtkEveryFilterClass = struct _GtkEveryFilterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API EveryFilter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Combining multiple filters.
 *
 * %Gtk::MultiFilter is the base type that implements support for handling
 * multiple filters.
 *
 * @newin{3,98}
 */

class GTKMM_API MultiFilter : public Filter, public Gio::ListModel, public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MultiFilter;
  using CppClassType = MultiFilter_Class;
  using BaseObjectType = GtkMultiFilter;
  using BaseClassType = GtkMultiFilterClass;

  // noncopyable
  MultiFilter(const MultiFilter&) = delete;
  auto operator=(const MultiFilter&) -> MultiFilter& = delete;

private:  friend class MultiFilter_Class;
  static CppClassType multifilter_class_;

protected:
  explicit MultiFilter(const Glib::ConstructParams& construct_params);
  explicit MultiFilter(GtkMultiFilter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MultiFilter(MultiFilter&& src) noexcept;
  auto operator=(MultiFilter&& src) noexcept -> MultiFilter&;

  ~MultiFilter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkMultiFilter*       { return reinterpret_cast<GtkMultiFilter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMultiFilter* { return reinterpret_cast<GtkMultiFilter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkMultiFilter*;

private:


protected:
  MultiFilter();

public:


  /** Adds a @a filter to @a self to use for matching.
   *
   * @param filter A new filter to use.
   */
  void append(const Glib::RefPtr<Filter>& filter);

  /** Removes the filter at the given @a position from the list of filters used
   * by @a self.
   *
   * If @a position is larger than the number of filters, nothing happens and
   * the function returns.
   *
   * @param position Position of filter to remove.
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

/** Matches when at least one filter matches.
 *
 * %Gtk::AnyFilter is a subclass of Gtk::MultiFilter that matches an item
 * when at least one of its filters matches.
 *
 * @newin{3,98}
 */

class GTKMM_API AnyFilter : public MultiFilter
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = AnyFilter;
  using CppClassType = AnyFilter_Class;
  using BaseObjectType = GtkAnyFilter;
  using BaseClassType = GtkAnyFilterClass;

  // noncopyable
  AnyFilter(const AnyFilter&) = delete;
  auto operator=(const AnyFilter&) -> AnyFilter& = delete;

private:  friend class AnyFilter_Class;
  static CppClassType anyfilter_class_;

protected:
  explicit AnyFilter(const Glib::ConstructParams& construct_params);
  explicit AnyFilter(GtkAnyFilter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  AnyFilter(AnyFilter&& src) noexcept;
  auto operator=(AnyFilter&& src) noexcept -> AnyFilter&;

  ~AnyFilter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkAnyFilter*       { return reinterpret_cast<GtkAnyFilter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAnyFilter* { return reinterpret_cast<GtkAnyFilter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkAnyFilter*;

private:


protected:
  AnyFilter();

public:

  static auto create() -> Glib::RefPtr<AnyFilter>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** Matches when each of its filter matches.
 *
 * %Gtk::EveryFilter is a subclass of Gtk::MultiFilter that matches an item
 * when each of its filters matches.
 *
 * @newin{3,98}
 */

class GTKMM_API EveryFilter : public MultiFilter
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = EveryFilter;
  using CppClassType = EveryFilter_Class;
  using BaseObjectType = GtkEveryFilter;
  using BaseClassType = GtkEveryFilterClass;

  // noncopyable
  EveryFilter(const EveryFilter&) = delete;
  auto operator=(const EveryFilter&) -> EveryFilter& = delete;

private:  friend class EveryFilter_Class;
  static CppClassType everyfilter_class_;

protected:
  explicit EveryFilter(const Glib::ConstructParams& construct_params);
  explicit EveryFilter(GtkEveryFilter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  EveryFilter(EveryFilter&& src) noexcept;
  auto operator=(EveryFilter&& src) noexcept -> EveryFilter&;

  ~EveryFilter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkEveryFilter*       { return reinterpret_cast<GtkEveryFilter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEveryFilter* { return reinterpret_cast<GtkEveryFilter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkEveryFilter*;

private:


protected:
  EveryFilter();

public:

  static auto create() -> Glib::RefPtr<EveryFilter>;


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
   * @relates Gtk::MultiFilter
   */
  GTKMM_API
  auto wrap(GtkMultiFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MultiFilter>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::AnyFilter
   */
  GTKMM_API
  auto wrap(GtkAnyFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::AnyFilter>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::EveryFilter
   */
  GTKMM_API
  auto wrap(GtkEveryFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EveryFilter>;
}


#endif /* _GTKMM_MULTIFILTER_H */

