
#ifndef _GTKMM_CELLLAYOUT_H
#define _GTKMM_CELLLAYOUT_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2003 The gtkmm Development Team
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

#include <libmm-glib/interface.hxx>
//#include <libmm-gtk/cellarea.hxx>
#include <libmm-gtk/cellrenderer.hxx>
#include <libmm-gtk/cellrenderer_generation.hxx>
#include <libmm-gtk/treemodel.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkCellLayoutIface GtkCellLayoutIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellLayout = struct _GtkCellLayout;
using GtkCellLayoutClass = struct _GtkCellLayoutClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellLayout_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class GTKMM_API CellArea;

/** An interface for packing cells.
 * CellLayout is an interface to be implemented by all objects which want to provide a TreeView::Column-like API
 * for packing cells, setting attributes and data funcs.
 */

class GTKMM_API CellLayout : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CellLayout;
  using CppClassType = CellLayout_Class;
  using BaseObjectType = GtkCellLayout;
  using BaseClassType = GtkCellLayoutIface;

  // noncopyable
  CellLayout(const CellLayout&) = delete;
  auto operator=(const CellLayout&) -> CellLayout& = delete;

private:
  friend class CellLayout_Class;
  static CppClassType celllayout_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  CellLayout();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit CellLayout(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit CellLayout(GtkCellLayout* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CellLayout(CellLayout&& src) noexcept;
  auto operator=(CellLayout&& src) noexcept -> CellLayout&;

  ~CellLayout() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellLayout*       { return reinterpret_cast<GtkCellLayout*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellLayout* { return reinterpret_cast<GtkCellLayout*>(gobject_); }

private:


public:

  template <class ColumnType> inline
  void pack_start(const TreeModelColumn<ColumnType>& model_column, bool expand = true);


  /** Packs the @a cell into the beginning of @a cell_layout. If @a expand is <tt>false</tt>,
   * then the @a cell is allocated no more space than it needs. Any unused space
   * is divided evenly between cells for which @a expand is <tt>true</tt>.
   *
   * Note that reusing the same cell renderer is not supported.
   *
   * @param cell A `Gtk::CellRenderer`.
   * @param expand <tt>true</tt> if @a cell is to be given extra space allocated to @a cell_layout.
   */
  void pack_start(CellRenderer& cell, bool expand =  true);

  /** Adds the @a cell to the end of @a cell_layout. If @a expand is <tt>false</tt>, then the
   *  @a cell is allocated no more space than it needs. Any unused space is
   * divided evenly between cells for which @a expand is <tt>true</tt>.
   *
   * Note that reusing the same cell renderer is not supported.
   *
   * @param cell A `Gtk::CellRenderer`.
   * @param expand <tt>true</tt> if @a cell is to be given extra space allocated to @a cell_layout.
   */
  void pack_end(CellRenderer& cell, bool expand =  true);


  /** Returns the cell renderers which have been added to @a cell_layout.
   *
   * @return A vector of cell renderers.
   */
  auto get_cells() -> std::vector<CellRenderer*>;

  /** Returns the cell renderers which have been added to @a cell_layout.
   *
   * @return A vector of cell renderers.
   */
  auto get_cells() const -> std::vector<const CellRenderer*>;

  /** Gets the CellRenderer for the first column if any has been added, or
    * nullptr otherwise.
    * You should dynamic_cast<> to the expected derived CellRenderer type.
    */
  auto get_first_cell() -> CellRenderer*;

  /** Gets the CellRenderer for the first column if any has been added, or
    * nullptr otherwise.
    * You should dynamic_cast<> to the expected derived CellRenderer type.
    */
  auto get_first_cell() const -> const CellRenderer*;


  /** Unsets all the mappings on all renderers on @a cell_layout and
   * removes all renderers from @a cell_layout.
   */
  void clear();

   //I think this is just a convenience method, equivalent to clear() and multiple add_attribute()s. murrayc.


  /** Adds an attribute mapping to the list in @a cell_layout.
   *
   * The @a column is the column of the model to get a value from, and the
   *  @a attribute is the property on @a cell to be set from that value. So for
   * example if column 2 of the model contains strings, you could have the
   * “text” attribute of a `Gtk::CellRendererText` get its values from column 2.
   * In this context "attribute" and "property" are used interchangeably.
   *
   * @param cell A `Gtk::CellRenderer`.
   * @param attribute A property on the renderer.
   * @param column The column position on the model to get the attribute from.
   */
  void add_attribute(CellRenderer& cell, const Glib::ustring& attribute, int column);

  void add_attribute(const Glib::PropertyProxy_Base& property, const TreeModelColumnBase& column);

  void add_attribute(CellRenderer& cell, const Glib::ustring& attribute, const TreeModelColumnBase& column);

  //For instance, void on_cell_data(const TreeModel::const_iterator& iter)
  typedef sigc::slot<void(const TreeModel::const_iterator&)> SlotCellData;

  void set_cell_data_func(CellRenderer& cell, const SlotCellData& slot);


  /** Clears all existing attributes previously set with
   * set_attributes().
   *
   * @param cell A `Gtk::CellRenderer` to clear the attribute mapping on.
   */
  void clear_attributes(CellRenderer& cell);


  /** Re-inserts @a cell at @a position.
   *
   * Note that @a cell has already to be packed into @a cell_layout
   * for this to function properly.
   *
   * @param cell A `Gtk::CellRenderer` to reorder.
   * @param position New position to insert @a cell at.
   */
  void reorder(CellRenderer& cell, int position);


  /** Returns the underlying `Gtk::CellArea` which might be @a cell_layout
   * if called on a `Gtk::CellArea` or might be <tt>nullptr</tt> if no `Gtk::CellArea`
   * is used by @a cell_layout.
   *
   * @return The cell area used by @a cell_layout.
   */
  auto get_area() -> Glib::RefPtr<CellArea>;

  /** Returns the underlying `Gtk::CellArea` which might be @a cell_layout
   * if called on a `Gtk::CellArea` or might be <tt>nullptr</tt> if no `Gtk::CellArea`
   * is used by @a cell_layout.
   *
   * @return The cell area used by @a cell_layout.
   */
  auto get_area() const -> Glib::RefPtr<const CellArea>;

protected:
    virtual void pack_start_vfunc(CellRenderer* cell, bool expand);

    virtual void pack_end_vfunc(CellRenderer* cell, bool expand);

    virtual void clear_vfunc();


    virtual void add_attribute_vfunc(CellRenderer* cell, const Glib::ustring& attribute, int column);


//TODO when we can break ABI(added in GTK+ 2.4):  _WRAP_VFUNC(void set_cell_data_func(CellRenderer* cell, GtkCellLayoutDataFunc func, gpointer func_data, GDestroyNotify destroy), gtk_cell_layout_set_cell_data_func)
    virtual void clear_attributes_vfunc(CellRenderer* cell);

    virtual void reorder_vfunc(CellRenderer* cell, int position);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

template<class T_ModelColumnType>
void CellLayout::pack_start(const TreeModelColumn<T_ModelColumnType>& column, bool expand)
{
  //Generate appropriate Renderer for the column:
  CellRenderer* pCellRenderer = manage( CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType>() );

  //Use the renderer:
  pack_start(*pCellRenderer, expand);

  //Make the renderer render the column:
  add_attribute(pCellRenderer->_property_renderable(), column);
}

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::CellLayout
   */
  GTKMM_API
  auto wrap(GtkCellLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellLayout>;

} // namespace Glib


#endif /* _GTKMM_CELLLAYOUT_H */

