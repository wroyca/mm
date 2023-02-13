
#ifndef _GTKMM_CONSTRAINTLAYOUT_H
#define _GTKMM_CONSTRAINTLAYOUT_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/layoutmanager.hpp>
#include <mm/gtk/buildable.hpp>
#include <mm/gtk/constraint.hpp>
#include <mm/gtk/constraintguide.hpp>
#include <mm/gio/listmodel.hpp>
#include <vector>
#include <map>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ConstraintLayout_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class ConstraintVflParserError : public Glib::Error
{
public:
  /**  @var Code INVALID_SYMBOL
   * Invalid or unknown symbol.
   *
   *  @var Code INVALID_ATTRIBUTE
   * Invalid or unknown attribute.
   *
   *  @var Code INVALID_VIEW
   * Invalid or unknown view.
   *
   *  @var Code INVALID_METRIC
   * Invalid or unknown metric.
   *
   *  @var Code INVALID_PRIORITY
   * Invalid or unknown priority.
   *
   *  @var Code INVALID_RELATION
   * Invalid or unknown relation.
   *
   *  @enum Code
   *
   * Domain for VFL parsing errors.
   */
  enum Code
  {
    INVALID_SYMBOL,
    INVALID_ATTRIBUTE,
    INVALID_VIEW,
    INVALID_METRIC,
    INVALID_PRIORITY,
    INVALID_RELATION
  };

  GTKMM_API ConstraintVflParserError(Code error_code, const Glib::ustring& error_message);
  GTKMM_API explicit ConstraintVflParserError(GError* gobject);
  GTKMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GTKMM_API static void throw_func(GError* gobject);

  friend GTKMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::ConstraintVflParserError::Code> : public Glib::Value_Enum<Gtk::ConstraintVflParserError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** A layout manager using constraints.
 *
 * %ConstraintLayout is a layout manager that uses relations between
 * widget attributes, expressed via Gtk::Constraint instances, to measure
 * and allocate widgets.
 *
 * See the description of GtkConstraintLayout in GTK for a detailed description
 * of how constraints work.
 *
 * @newin{3,96}
 */

class GTKMM_API ConstraintLayout : public LayoutManager, public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ConstraintLayout;
  using CppClassType = ConstraintLayout_Class;
  using BaseObjectType = GtkConstraintLayout;
  using BaseClassType = GtkConstraintLayoutClass;

  // noncopyable
  ConstraintLayout(const ConstraintLayout&) = delete;
  auto operator=(const ConstraintLayout&) -> ConstraintLayout& = delete;

private:  friend class ConstraintLayout_Class;
  static CppClassType constraintlayout_class_;

protected:
  explicit ConstraintLayout(const Glib::ConstructParams& construct_params);
  explicit ConstraintLayout(GtkConstraintLayout* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ConstraintLayout(ConstraintLayout&& src) noexcept;
  auto operator=(ConstraintLayout&& src) noexcept -> ConstraintLayout&;

  ~ConstraintLayout() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkConstraintLayout*       { return reinterpret_cast<GtkConstraintLayout*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkConstraintLayout* { return reinterpret_cast<GtkConstraintLayout*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkConstraintLayout*;

private:


protected:
  ConstraintLayout();

public:

  static auto create() -> Glib::RefPtr<ConstraintLayout>;


  /** Adds a constraint to the layout manager.
   *
   * The Gtk::Constraint::property_source() and Gtk::Constraint::property_target()
   * properties of `constraint` can be:
   *
   * - set to <tt>nullptr</tt> to indicate that the constraint refers to the
   * widget using `layout`
   * - set to the Gtk::Widget using `layout`
   * - set to a child of the Gtk::Widget using `layout`
   * - set to a Gtk::ConstraintGuide that is part of `layout`
   *
   * The @a layout acquires the ownership of @a constraint after calling
   * this function.
   *
   * @param constraint A Gtk::Constraint.
   */

  void add_constraint(const Glib::RefPtr<Constraint>& constraint);

  /** Removes `constraint` from the layout manager,
   * so that it no longer influences the layout.
   *
   * @param constraint A Gtk::Constraint.
   */
  void remove_constraint(const Glib::RefPtr<Constraint>& constraint);

  /** Removes all constraints from the layout manager.
   */
  void remove_all_constraints();


  /** Adds a guide to `layout`.
   *
   * A guide can be used as the source or target of constraints,
   * like a widget, but it is not visible.
   *
   * The `layout` acquires the ownership of `guide` after calling
   * this function.
   *
   * @param guide A Gtk::ConstraintGuide object.
   */

  void add_guide(const Glib::RefPtr<ConstraintGuide>& guide);

  /** Removes `guide` from the layout manager,
   * so that it no longer influences the layout.
   *
   * @param guide A Gtk::ConstraintGuide object.
   */
  void remove_guide(const Glib::RefPtr<ConstraintGuide>& guide);

  /** A map type, used by add_constraints_from_description().
   */
  using VFLmap = std::map<Glib::ustring, Glib::RefPtr<ConstraintTarget>>;

  /** Creates a list of constraints from a formal description using a compact
   * description syntax called VFL, or "Visual Format Language".
   *
   * The Visual Format Language is based on Apple's AutoLayout
   * <a href="https://developer.apple.com/library/content/documentation/UserExperience/Conceptual/AutolayoutPG/VisualFormatLanguage.html">VFL</a>.
   * See also the description of gtk_constraint_layout_add_constraints_from_descriptionv()
   * in GTK.
   *
   * The @a views dictionary is used to match Gtk::ConstraintTargets to the symbolic
   * view name inside the VFL.
   *
   * **Note**: The VFL grammar used by GTK is slightly different than the one
   * defined by Apple, as it can use symbolic values for the constraint's
   * strength instead of numeric values; additionally, GTK allows adding
   * simple arithmetic operations inside predicates.
   *
   * @param lines A vector of Visual Format Language lines defining a set of constraints.
   * @param hspacing Default horizontal spacing value, or -1 for the fallback value.
   * @param vspacing Default vertical spacing value, or -1 for the fallback value.
   * @param views A dictionary of [ name, target ] pairs; the `name` keys map
   *   to the view names in the VFL lines, while the `target` values map to
   *   children of the widget using a Gtk::ConstraintLayout, or guides.
   * @return The vector of Gtk::Constraints that were added to the layout.
   * @throws Gtk::ConstraintVflParserError
   */
  auto add_constraints_from_description(
    const std::vector<Glib::ustring>& lines, int hspacing, int vspacing, const VFLmap& views) -> std::vector<Glib::RefPtr<Constraint>>;


  /** Returns a `Gio::ListModel` to track the constraints that are
   * part of the layout.
   *
   * Calling this function will enable extra internal bookkeeping
   * to track constraints and emit signals on the returned listmodel.
   * It may slow down operations a lot.
   *
   * Applications should try hard to avoid calling this function
   * because of the slowdowns.
   *
   * @return A
   * `Gio::ListModel` tracking the layout's constraints.
   */
  auto observe_constraints() -> Glib::RefPtr<Gio::ListModel>;

  /** Returns a `Gio::ListModel` to track the constraints that are
   * part of the layout.
   *
   * Calling this function will enable extra internal bookkeeping
   * to track constraints and emit signals on the returned listmodel.
   * It may slow down operations a lot.
   *
   * Applications should try hard to avoid calling this function
   * because of the slowdowns.
   *
   * @return A
   * `Gio::ListModel` tracking the layout's constraints.
   */
  auto observe_constraints() const -> Glib::RefPtr<const Gio::ListModel>;

  /** Returns a `Gio::ListModel` to track the guides that are
   * part of the layout.
   *
   * Calling this function will enable extra internal bookkeeping
   * to track guides and emit signals on the returned listmodel.
   * It may slow down operations a lot.
   *
   * Applications should try hard to avoid calling this function
   * because of the slowdowns.
   *
   * @return A
   * `Gio::ListModel` tracking the layout's guides.
   */
  auto observe_guides() -> Glib::RefPtr<Gio::ListModel>;

  /** Returns a `Gio::ListModel` to track the guides that are
   * part of the layout.
   *
   * Calling this function will enable extra internal bookkeeping
   * to track guides and emit signals on the returned listmodel.
   * It may slow down operations a lot.
   *
   * Applications should try hard to avoid calling this function
   * because of the slowdowns.
   *
   * @return A
   * `Gio::ListModel` tracking the layout's guides.
   */
  auto observe_guides() const -> Glib::RefPtr<const Gio::ListModel>;


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
   * @relates Gtk::ConstraintLayout
   */
  GTKMM_API
  auto wrap(GtkConstraintLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ConstraintLayout>;
}


#endif /* _GTKMM_CONSTRAINTLAYOUT_H */

