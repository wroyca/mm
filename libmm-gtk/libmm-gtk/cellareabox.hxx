
#ifndef _GTKMM_CELLAREABOX_H
#define _GTKMM_CELLAREABOX_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The gtkmm Development Team
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

#include <libmm-gtk/cellarea.hpp>
#include <libmm-gtk/orientable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellAreaBox = struct _GtkCellAreaBox;
using GtkCellAreaBoxClass = struct _GtkCellAreaBoxClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellAreaBox_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A cell area that renders CellRenderers into a row or a colum, depending on its orientation.
 *
 * This class uses a notion of packing. Packing
 * refers to adding cell renderers with reference to a particular position
 * in a CellAreaBox. There are two reference positions: the
 * start and the end of the box.
 * When the CellAreaBox is oriented in the Gtk::Orientation::VERTICAL
 * orientation, the start is defined as the top of the box and the end is
 * defined as the bottom. In the  Gtk::Orientation::HORIZONTAL orientation
 * start is defined as the left side and the end is defined as the right
 * side.
 *
 * Alignments of CellRenderers rendered in adjacent rows can be
 * configured by configuring the align_child cell property
 * with CellArea::cell_set_property() or by specifying the "align"
 * argument to pack_start() or pack_end().
 *
 * @newin{3,0}
 */

class GTKMM_API CellAreaBox
  : public Gtk::CellArea,
    public Orientable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CellAreaBox;
  using CppClassType = CellAreaBox_Class;
  using BaseObjectType = GtkCellAreaBox;
  using BaseClassType = GtkCellAreaBoxClass;

  // noncopyable
  CellAreaBox(const CellAreaBox&) = delete;
  auto operator=(const CellAreaBox&) -> CellAreaBox& = delete;

private:  friend class CellAreaBox_Class;
  static CppClassType cellareabox_class_;

protected:
  explicit CellAreaBox(const Glib::ConstructParams& construct_params);
  explicit CellAreaBox(GtkCellAreaBox* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CellAreaBox(CellAreaBox&& src) noexcept;
  auto operator=(CellAreaBox&& src) noexcept -> CellAreaBox&;

  ~CellAreaBox() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellAreaBox*       { return reinterpret_cast<GtkCellAreaBox*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellAreaBox* { return reinterpret_cast<GtkCellAreaBox*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkCellAreaBox*;

private:


protected:
  CellAreaBox();
public:

  static auto create() -> Glib::RefPtr<CellAreaBox>;


  // The default values of expand, align and fixed are the default values of
  // CELL_PROP_[EXPAND,ALIGN,FIXED_SIZE] in gtkcellareabox.c.

  /** Adds @a renderer to @a box, packed with reference to the start of @a box.
   *
   * The @a renderer is packed after any other `Gtk::CellRenderer` packed
   * with reference to the start of @a box.
   *
   * @param renderer The `Gtk::CellRenderer` to add.
   * @param expand Whether @a renderer should receive extra space when the area receives
   * more than its natural size.
   * @param align Whether @a renderer should be aligned in adjacent rows.
   * @param fixed Whether @a renderer should have the same size in all rows.
   */
  void pack_start(CellRenderer& renderer, bool expand =  false, bool align =  false, bool fixed =  true);

  /** Adds @a renderer to @a box, packed with reference to the end of @a box.
   *
   * The @a renderer is packed after (away from end of) any other
   * `Gtk::CellRenderer` packed with reference to the end of @a box.
   *
   * @param renderer The `Gtk::CellRenderer` to add.
   * @param expand Whether @a renderer should receive extra space when the area receives
   * more than its natural size.
   * @param align Whether @a renderer should be aligned in adjacent rows.
   * @param fixed Whether @a renderer should have the same size in all rows.
   */
  void pack_end(CellRenderer& renderer, bool expand =  false, bool align =  false, bool fixed =  true);

  /** Gets the spacing added between cell renderers.
   *
   * @return The space added between cell renderers in @a box.
   */
  auto get_spacing() const -> int;

  /** Sets the spacing to add between cell renderers in @a box.
   *
   * @param spacing The space to add between `Gtk::CellRenderer`s.
   */
  void set_spacing(int spacing);

  /** The amount of space to reserve between cells.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() -> Glib::PropertyProxy< int > ;

/** The amount of space to reserve between cells.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;


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
   * @relates Gtk::CellAreaBox
   */
  GTKMM_API
  auto wrap(GtkCellAreaBox* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellAreaBox>;
}


#endif /* _GTKMM_CELLAREABOX_H */

