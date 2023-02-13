
#ifndef _GTKMM_SIZEGROUP_H
#define _GTKMM_SIZEGROUP_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <vector>

#include <mm/glib/object.hpp>
#include <mm/gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSizeGroup = struct _GtkSizeGroup;
using GtkSizeGroupClass = struct _GtkSizeGroupClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SizeGroup_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** Gtk::SizeGroup provides a mechanism for grouping a number of widgets together so they all request the same amount of space.
 * This is typically useful when you want a column of widgets to have the same size, but you can't use a Gtk::Grid widget.
 *
 * In detail, the size requested for each widget in a Gtk::SizeGroup is the maximum of the sizes that would have been
 * requested for each widget in the size group if they were not in the size group. The mode of the size group (see
 * set_mode()) determines whether this applies to the horizontal size, the vertical size, or both sizes.
 *
 * Note that size groups only affect the amount of space requested, not the size that the widgets finally receive. If
 * you want the widgets in a GtkSizeGroup to actually be the same size, you need to pack them in such a way that they
 * get the size they request and not more. For example, if you are packing your widgets into a table, you would not
 * include the Gtk::FILL flag.
 *
 * Widgets can be part of multiple size groups; GTK+ will compute the horizontal size of a widget from the horizontal
 * requisition of all widgets that can be reached from the widget by a chain of size groups of type
 * Gtk::SizeGroup::Mode::HORIZONTAL or Gtk::SizeGroup::Mode::BOTH, and the vertical size from the vertical requisition of all widgets
 * that can be reached from the widget by a chain of size groups of type Gtk::SizeGroup::Mode::VERTICAL or Gtk::SizeGroup::Mode::BOTH.
 */

class GTKMM_API SizeGroup
  : public Glib::Object,
    public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SizeGroup;
  using CppClassType = SizeGroup_Class;
  using BaseObjectType = GtkSizeGroup;
  using BaseClassType = GtkSizeGroupClass;

  // noncopyable
  SizeGroup(const SizeGroup&) = delete;
  auto operator=(const SizeGroup&) -> SizeGroup& = delete;

private:  friend class SizeGroup_Class;
  static CppClassType sizegroup_class_;

protected:
  explicit SizeGroup(const Glib::ConstructParams& construct_params);
  explicit SizeGroup(GtkSizeGroup* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SizeGroup(SizeGroup&& src) noexcept;
  auto operator=(SizeGroup&& src) noexcept -> SizeGroup&;

  ~SizeGroup() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSizeGroup*       { return reinterpret_cast<GtkSizeGroup*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSizeGroup* { return reinterpret_cast<GtkSizeGroup*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSizeGroup*;

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Mode NONE
   * Group has no effect.
   *
   *  @var Mode HORIZONTAL
   * Group affects horizontal requisition.
   *
   *  @var Mode VERTICAL
   * Group affects vertical requisition.
   *
   *  @var Mode BOTH
   * Group affects both horizontal and vertical requisition.
   *
   *  @enum Mode
   *
   * The mode of the size group determines the directions in which the size
   * group affects the requested sizes of its component widgets.
   *
   * @ingroup gtkmmEnums
   */
  enum class Mode
  {
    NONE,
    HORIZONTAL,
    VERTICAL,
    BOTH
  };


protected:
  explicit SizeGroup(Mode mode);

public:


  static auto create(Mode mode) -> Glib::RefPtr<SizeGroup>;


  /** Sets the `Gtk::SizeGroup::Mode` of the size group.
   *
   * The mode of the size group determines whether the widgets in the
   * size group should all have the same horizontal requisition
   * (Gtk::SizeGroup::Mode::HORIZONTAL) all have the same vertical requisition
   * (Gtk::SizeGroup::Mode::VERTICAL), or should all have the same requisition
   * in both directions (Gtk::SizeGroup::Mode::BOTH).
   *
   * @param mode The mode to set for the size group.
   */
  void set_mode(Mode mode);

  /** Gets the current mode of the size group.
   *
   * @return The current mode of the size group.
   */
  auto get_mode() const -> Mode;


  /** Adds a widget to a `Gtk::SizeGroup`.
   *
   * In the future, the requisition
   * of the widget will be determined as the maximum of its requisition
   * and the requisition of the other widgets in the size group.
   * Whether this applies horizontally, vertically, or in both directions
   * depends on the mode of the size group.
   * See set_mode().
   *
   * When the widget is destroyed or no longer referenced elsewhere, it
   * will be removed from the size group.
   *
   * @param widget The `Gtk::Widget` to add.
   */
  void add_widget(Widget& widget);

  /** Removes a widget from a `Gtk::SizeGroup`.
   *
   * @param widget The `Gtk::Widget` to remove.
   */
  void remove_widget(Widget& widget);


  /** Returns the list of widgets associated with @a size_group.
   *
   * @return A `SList` of
   * widgets. The list is owned by GTK and should not be modified.
   */
  auto get_widgets() -> std::vector<Widget*>;


  /** Returns the list of widgets associated with @a size_group.
   *
   * @return A `SList` of
   * widgets. The list is owned by GTK and should not be modified.
   */
  auto get_widgets() const -> std::vector<const Widget*>;

  /** The direction in which the size group affects requested sizes.
   *
   * Default value: Gtk::SizeGroup::Mode::HORIZONTAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mode() -> Glib::PropertyProxy< Mode > ;

/** The direction in which the size group affects requested sizes.
   *
   * Default value: Gtk::SizeGroup::Mode::HORIZONTAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mode() const -> Glib::PropertyProxy_ReadOnly< Mode >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::SizeGroup::Mode> : public Glib::Value_Enum<Gtk::SizeGroup::Mode>
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
   * @relates Gtk::SizeGroup
   */
  GTKMM_API
  auto wrap(GtkSizeGroup* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SizeGroup>;
}


#endif /* _GTKMM_SIZEGROUP_H */

