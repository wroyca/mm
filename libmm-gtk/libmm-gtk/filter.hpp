
#ifndef _GTKMM_FILTER_H
#define _GTKMM_FILTER_H

#include <libmm-gtk/mm-gtkconfig.hpp>


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


#include <libmm-glib/object.hpp>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Filter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Filtering items.
 *
 * A %Gtk::Filter object describes the filtering to be performed by a
 * Gtk::FilterListModel.
 *
 * The model will use the filter to determine if it should include items
 * or not by calling match() for each item and only keeping the
 * ones that the function returns <tt>true</tt> for.
 *
 * Filters may change what items they match through their lifetime. In that
 * case, they will emit the signal_changed() signal to notify that previous
 * filter results are no longer valid and that items should be checked again
 * via match().
 *
 * GTK provides various pre-made filter implementations for common filtering
 * operations. These filters often include properties that can be linked to
 * various widgets to easily allow searches.
 *
 * However, in particular for large lists or complex search methods, it is
 * also possible to subclass %Gtk::Filter and provide one's own filter.
 *
 * @see Gtk::FilterListModel
 * @newin{3,98}
 */

class GTKMM_API Filter : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Filter;
  using CppClassType = Filter_Class;
  using BaseObjectType = GtkFilter;
  using BaseClassType = GtkFilterClass;

  // noncopyable
  Filter(const Filter&) = delete;
  auto operator=(const Filter&) -> Filter& = delete;

private:  friend class Filter_Class;
  static CppClassType filter_class_;

protected:
  explicit Filter(const Glib::ConstructParams& construct_params);
  explicit Filter(GtkFilter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Filter(Filter&& src) noexcept;
  auto operator=(Filter&& src) noexcept -> Filter&;

  ~Filter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkFilter*       { return reinterpret_cast<GtkFilter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFilter* { return reinterpret_cast<GtkFilter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkFilter*;

private:


protected:
  Filter();

public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Match SOME
   * The filter matches some items,
   * Gtk::Filter::match() may return <tt>true</tt> or <tt>false</tt>.
   *
   *  @var Match NONE
   * The filter does not match any item,
   * Gtk::Filter::match() will always return <tt>false</tt>.
   *
   *  @var Match ALL
   * The filter matches all items,
   * Gtk::Filter::match() will alays return <tt>true</tt>.
   *
   *  @enum Match
   *
   * Describes the known strictness of a filter.
   *
   * Note that for filters where the strictness is not known,
   * Gtk::Filter::Match::SOME is always an acceptable value,
   * even if a filter does match all or no items.
   *
   * @ingroup gtkmmEnums
   */
  enum class Match
  {
    SOME,
    NONE,
    ALL
  };


  /**
   *  @var Change DIFFERENT
   * The filter change cannot be
   * described with any of the other enumeration values.
   *
   *  @var Change LESS_STRICT
   * The filter is less strict than
   * it was before: All items that it used to return <tt>true</tt> for
   * still return <tt>true</tt>, others now may, too.
   *
   *  @var Change MORE_STRICT
   * The filter is more strict than
   * it was before: All items that it used to return <tt>false</tt> for
   * still return <tt>false</tt>, others now may, too.
   *
   *  @enum Change
   *
   * Describes changes in a filter in more detail and allows objects
   * using the filter to optimize refiltering items.
   *
   * If you are writing an implementation and are not sure which
   * value to pass, Gtk::Filter::Change::DIFFERENT is always a correct
   * choice.
   *
   * @ingroup gtkmmEnums
   */
  enum class Change
  {
    DIFFERENT,
    LESS_STRICT,
    MORE_STRICT
  };


  /** Checks if the given @a item is matched by the filter or not.
   *
   * @param item The item to check.
   * @return <tt>true</tt> if the filter matches the item and a filter model should
   * keep it, <tt>false</tt> if not.
   */
  auto match(const Glib::RefPtr<Glib::ObjectBase>& item) -> bool;

  /** Gets the known strictness of @a filters.
   *
   * If the strictness is not known, Gtk::Filter::Match::SOME is returned.
   *
   * This value may change after emission of the signal_changed()
   * signal.
   *
   * This function is meant purely for optimization purposes, filters can
   * choose to omit implementing it, but `Gtk::FilterListModel` uses it.
   *
   * @return The strictness of @a self.
   */
  auto get_strictness() -> Match;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed(Change change)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever the filter changed.
   *
   * Users of the filter should then check items again via
   * Gtk::Filter::match().
   *
   * `Gtk::FilterListModel` handles this signal automatically.
   *
   * Depending on the @a change parameter, not all items need
   * to be checked, but only some. Refer to the Gtk::FilterChange
   * documentation for details.
   *
   * @param change How the filter changed.
   */

  auto signal_changed() -> Glib::SignalProxy<void(Change)>;


protected:
  // for filter implementations

  /** Notifies all users of the filter that it has changed.
   *
   * This emits the signal_changed() signal. Users
   * of the filter should then check items again via
   * match().
   *
   * Depending on the @a change parameter, not all items need to
   * be changed, but only some. Refer to the Gtk::FilterChange
   * documentation for details.
   *
   * This function is intended for implementors of `Gtk::Filter`
   * subclasses and should not be called from other functions.
   *
   * @param change How the filter changed.
   */
  void changed(Change change =  Change::DIFFERENT);


    virtual auto match_vfunc(const Glib::RefPtr<Glib::ObjectBase>& item) -> bool;

    virtual auto get_strictness_vfunc() -> Match;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Filter::Match> : public Glib::Value_Enum<Gtk::Filter::Match>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Filter::Change> : public Glib::Value_Enum<Gtk::Filter::Change>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Filter
   */
  GTKMM_API
  auto wrap(GtkFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Filter>;
}


#endif /* _GTKMM_FILTER_H */

