// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLLAYOUT_H
#define _GTKMM_CELLLAYOUT_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <vector>

  #include <libmm/glib/interface.hxx>

  #include <libmm/gtk/cellrenderer.hxx>
  #include <libmm/gtk/cellrenderer_generation.hxx>
  #include <libmm/gtk/treemodel.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkCellLayoutIface GtkCellLayoutIface;
}
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellLayout = struct _GtkCellLayout;
using GtkCellLayoutClass = struct _GtkCellLayoutClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT CellLayout_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT CellArea;

  class LIBMM_GTK_SYMEXPORT CellLayout : public Glib::Interface
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CellLayout;
    using CppClassType = CellLayout_Class;
    using BaseObjectType = GtkCellLayout;
    using BaseClassType = GtkCellLayoutIface;

    CellLayout (const CellLayout&) = delete;
    auto
    operator= (const CellLayout&) -> CellLayout& = delete;

  private:
    friend class CellLayout_Class;
    static CppClassType celllayout_class_;

  #endif
  protected:
    CellLayout ();

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit CellLayout (const Glib::Interface_Class& interface_class);

  public:
    explicit CellLayout (GtkCellLayout* castitem);

  protected:
  #endif

  public:
    CellLayout (CellLayout&& src) noexcept;
    auto
    operator= (CellLayout&& src) noexcept -> CellLayout&;

    ~CellLayout () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellLayout*
    {
      return reinterpret_cast<GtkCellLayout*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellLayout*
    {
      return reinterpret_cast<GtkCellLayout*> (gobject_);
    }

  private:
  public:
    template <class ColumnType>
    inline auto
    pack_start (const TreeModelColumn<ColumnType>& model_column,
                bool expand = true) -> void;

    auto
    pack_start (CellRenderer& cell, bool expand = true) -> void;

    auto
    pack_end (CellRenderer& cell, bool expand = true) -> void;

    auto
    get_cells () -> std::vector<CellRenderer*>;

    auto
    get_cells () const -> std::vector<const CellRenderer*>;

    auto
    get_first_cell () -> CellRenderer*;

    auto
    get_first_cell () const -> const CellRenderer*;

    auto
    clear () -> void;

    auto
    add_attribute (CellRenderer& cell,
                   const Glib::ustring& attribute,
                   int column) -> void;

    auto
    add_attribute (const Glib::PropertyProxy_Base& property,
                   const TreeModelColumnBase& column) -> void;

    auto
    add_attribute (CellRenderer& cell,
                   const Glib::ustring& attribute,
                   const TreeModelColumnBase& column) -> void;

    typedef sigc::slot<void (const TreeModel::const_iterator&)> SlotCellData;

    auto
    set_cell_data_func (CellRenderer& cell, const SlotCellData& slot) -> void;

    auto
    clear_attributes (CellRenderer& cell) -> void;

    auto
    reorder (CellRenderer& cell, int position) -> void;

    auto
    get_area () -> Glib::RefPtr<CellArea>;

    auto
    get_area () const -> Glib::RefPtr<const CellArea>;

  protected:
    virtual auto
    pack_start_vfunc (CellRenderer* cell, bool expand) -> void;

    virtual auto
    pack_end_vfunc (CellRenderer* cell, bool expand) -> void;

    virtual auto
    clear_vfunc () -> void;

    virtual auto
    add_attribute_vfunc (CellRenderer* cell,
                         const Glib::ustring& attribute,
                         int column) -> void;

    virtual auto
    clear_attributes_vfunc (CellRenderer* cell) -> void;

    virtual auto
    reorder_vfunc (CellRenderer* cell, int position) -> void;

  public:
  public:
  protected:
  };

  template <class T_ModelColumnType>
  auto
  CellLayout::pack_start (const TreeModelColumn<T_ModelColumnType>& column,
                          bool expand) -> void
  {
    CellRenderer* pCellRenderer = manage (
        CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType> ());

    pack_start (*pCellRenderer, expand);

    add_attribute (pCellRenderer->_property_renderable (), column);
  }

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellLayout>;

} // namespace Glib

#endif

#endif
