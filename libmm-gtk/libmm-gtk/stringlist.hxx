
#ifndef _GTKMM_STRINGLIST_H
#define _GTKMM_STRINGLIST_H


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

#include <libmm-gtk/buildable.hxx>
#include <libmm-gio/listmodel.hxx>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API StringList_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A list model for strings.
 *
 * %Gtk::StringList is a list model that wraps an array of strings.
 *
 * The objects in the model have a "string" property.
 *
 * GtkStringList is well-suited for any place where you would
 * typically use a vector or array of Glib::ustring, but need a list model.
 *
 * @par %Gtk::StringList as Gtk::Buildable
 * The %Gtk::StringList implementation of the Gtk::Buildable interface
 * supports adding items directly using the <items> element and
 * specifying <item> elements for each item. Each <item> element
 * supports the regular translation attributes “translatable”,
 * “context” and “comments”.
 *
 * @par
 * Here is a UI definition fragment specifying a %Gtk::StringList
 * ~~~{.xml}
 * <object class="GtkStringList">
 *   <items>
 *     <item translatable="yes">Factory</item>
 *     <item translatable="yes">Home</item>
 *     <item translatable="yes">Subway</item>
 *   </items>
 * </object>
 * ~~~
 *
 * @see Gio::ListModel
 * @newin{3,98}
 */

class GTKMM_API StringList : public Glib::Object, public Gio::ListModel, public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = StringList;
  using CppClassType = StringList_Class;
  using BaseObjectType = GtkStringList;
  using BaseClassType = GtkStringListClass;

  // noncopyable
  StringList(const StringList&) = delete;
  auto operator=(const StringList&) -> StringList& = delete;

private:  friend class StringList_Class;
  static CppClassType stringlist_class_;

protected:
  explicit StringList(const Glib::ConstructParams& construct_params);
  explicit StringList(GtkStringList* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  StringList(StringList&& src) noexcept;
  auto operator=(StringList&& src) noexcept -> StringList&;

  ~StringList() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkStringList*       { return reinterpret_cast<GtkStringList*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkStringList* { return reinterpret_cast<GtkStringList*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkStringList*;

private:


protected:
  StringList(const std::vector<Glib::ustring>& strings);

public:

  static auto create(const std::vector<Glib::ustring>& strings) -> Glib::RefPtr<StringList>;


  /** Appends @a string to @a self.
   *
   * The @a string will be copied. See
   * take() for a way to avoid that.
   *
   * @param string The string to insert.
   */
  void append(const Glib::ustring& string);


  /** Removes the string at @a position from @a self.
   *
   *  @a position must be smaller than the current
   * length of the list.
   *
   * @param position The position of the string that is to be removed.
   */
  void remove(guint position);


  /** Changes @a self by removing @a n_removals strings and adding @a additions
   * to it.
   *
   * This function is more efficient than append()
   * and remove(), because it only emits the
   * signal_items_changed() signal once for the change.
   *
   * This function copies the strings in @a additions.
   *
   * The parameters @a position and @a n_removals must be correct (ie:
   *  @a position + @a n_removals must be less than or equal to the length
   * of the list at the time this function is called).
   *
   * @param position The position at which to make the change.
   * @param n_removals The number of strings to remove.
   * @param additions The strings to add.
   */
  void splice(guint position, guint n_removals, const std::vector<Glib::ustring>& additions);

  /** Gets the string that is at @a position in @a self.
   *
   * If @a self does not contain @a position items, <tt>nullptr</tt> is returned.
   *
   * This function returns the const char *. To get the
   * object wrapping it, use Glib::list_model_get_item().
   *
   * @param position The position to get the string for.
   * @return The string at the given position.
   */
  auto get_string(guint position) const -> Glib::ustring;


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
   * @relates Gtk::StringList
   */
  GTKMM_API
  auto wrap(GtkStringList* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StringList>;
}


#endif /* _GTKMM_STRINGLIST_H */

