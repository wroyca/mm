// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLAREA_H
#define _GTKMM_CELLAREA_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/glib/object.hxx>
  #include <libmm/gtk/buildable.hxx>
  #include <libmm/gtk/cellareacontext.hxx>
  #include <libmm/gtk/celllayout.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellArea = struct _GtkCellArea;
using GtkCellAreaClass = struct _GtkCellAreaClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CellArea_Class;
}
  #endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Snapshot;

  class LIBMM_GTK_SYMEXPORT CellArea : public glib::Object,
                             public Buildable,
                             public CellLayout
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CellArea;
    using CppClassType = CellArea_Class;
    using BaseObjectType = GtkCellArea;
    using BaseClassType = GtkCellAreaClass;

    CellArea (const CellArea&) = delete;
    auto
    operator= (const CellArea&) -> CellArea& = delete;

  private:
    friend class CellArea_Class;
    static CppClassType cellarea_class_;

  protected:
    explicit CellArea (const glib::ConstructParams& construct_params);
    explicit CellArea (GtkCellArea* castitem);

  #endif

  public:
    CellArea (CellArea&& src) noexcept;
    auto
    operator= (CellArea&& src) noexcept -> CellArea&;

    ~CellArea () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellArea*
    {
      return reinterpret_cast<GtkCellArea*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellArea*
    {
      return reinterpret_cast<GtkCellArea*> (gobject_);
    }

    auto
    gobj_copy () -> GtkCellArea*;

  private:
  protected:
    CellArea ();

  public:
    auto
    add (CellRenderer& renderer) -> void;

    auto
    remove (CellRenderer& renderer) -> void;

    auto
    has_renderer (CellRenderer& renderer) -> bool;

    typedef sigc::slot<bool (CellRenderer*)> SlotForeach;

    auto foreach (const SlotForeach& slot) -> void;

    typedef sigc::slot<
        bool (CellRenderer*, const gdk::Rectangle&, const gdk::Rectangle&)>
        SlotForeachAlloc;

    auto foreach (const glib::RefPtr<CellAreaContext>& context,
                  Widget * widget,
                  const gdk::Rectangle& cell_area,
                  const gdk::Rectangle& background_area,
                  const SlotForeachAlloc& slot) -> void;

    auto
    event (const glib::RefPtr<CellAreaContext>& context,
           Widget& widget,
           const glib::RefPtr<const gdk::Event>& gdk_event,
           const gdk::Rectangle& cell_area,
           GtkCellRendererState flags) -> int;

    auto
    snapshot (const glib::RefPtr<CellAreaContext>& context,
              Widget& widget,
              const glib::RefPtr<gtk::Snapshot>& snapshot,
              const gdk::Rectangle& background_area,
              const gdk::Rectangle& cell_area,
              CellRendererState flags,
              bool paint_focus) -> void;

    auto
    get_cell_allocation (const glib::RefPtr<CellAreaContext>& context,
                         Widget& widget,
                         CellRenderer& renderer,
                         const gdk::Rectangle& cell_area,
                         gdk::Rectangle& allocation) -> void;

    auto
    get_cell_at_position (const glib::RefPtr<CellAreaContext>& context,
                          Widget& widget,
                          const gdk::Rectangle& cell_area,
                          int x,
                          int y,
                          gdk::Rectangle& alloc_area) -> CellRenderer*;

    auto
    get_cell_at_position (const glib::RefPtr<CellAreaContext>& context,
                          Widget& widget,
                          const gdk::Rectangle& cell_area,
                          int x,
                          int y,
                          gdk::Rectangle& alloc_area) const
        -> const CellRenderer*;

    auto
    create_context () const -> glib::RefPtr<CellAreaContext>;

    auto
    copy_context (const glib::RefPtr<const CellAreaContext>& context)
        -> glib::RefPtr<CellAreaContext>;

    auto
    get_request_mode () const -> SizeRequestMode;

    auto
    get_preferred_width (const glib::RefPtr<CellAreaContext>& context,
                         Widget& widget,
                         int& minimum_width,
                         int& natural_width) -> void;

    auto
    get_preferred_height_for_width (
        const glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int width,
        int& minimum_height,
        int& natural_height) -> void;

    auto
    get_preferred_height (const glib::RefPtr<CellAreaContext>& context,
                          Widget& widget,
                          int& minimum_height,
                          int& natural_height) -> void;

    auto
    get_preferred_width_for_height (
        const glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int height,
        int& minimum_width,
        int& natural_width) -> void;

    auto
    get_current_path_string () const -> glib::ustring;

    auto
    apply_attributes (const glib::RefPtr<TreeModel>& tree_model,
                      const TreeModel::iterator& iter,
                      bool is_expander,
                      bool is_expanded) -> void;

    auto
    attribute_connect (CellRenderer& renderer,
                       const glib::ustring& attribute,
                       int column) -> void;

    auto
    attribute_disconnect (CellRenderer& renderer,
                          const glib::ustring& attribute) -> void;

    auto
    attribute_get_column (CellRenderer& renderer,
                          const glib::ustring& attribute) const -> int;

    auto
    cell_set_property (CellRenderer& renderer,
                       const glib::ustring& property_name,
                       const glib::ValueBase& value) -> void;

    auto
    cell_get_property (CellRenderer& renderer,
                       const glib::ustring& property_name,
                       glib::ValueBase& value) -> void;

    auto
    is_activatable () const -> bool;

    auto
    activate (const glib::RefPtr<CellAreaContext>& context,
              Widget& widget,
              const gdk::Rectangle& cell_area,
              CellRendererState flags,
              bool edit_only) -> bool;

    auto
    focus (DirectionType direction) -> bool;

    auto
    set_focus_cell (CellRenderer& renderer) -> void;

    auto
    get_focus_cell () -> CellRenderer*;

    auto
    get_focus_cell () const -> const CellRenderer*;

    auto
    add_focus_sibling (CellRenderer& renderer, CellRenderer& sibling) -> void;

    auto
    remove_focus_sibling (CellRenderer& renderer, CellRenderer& sibling)
        -> void;

    auto
    is_focus_sibling (CellRenderer& renderer, CellRenderer& sibling) -> bool;

    auto
    get_focus_siblings (CellRenderer& renderer) -> std::vector<CellRenderer*>;

    auto
    get_focus_siblings (const CellRenderer& renderer) const
        -> std::vector<const CellRenderer*>;

    auto
    get_focus_from_sibling (CellRenderer& renderer) -> CellRenderer*;

    auto
    get_focus_from_sibling (CellRenderer& renderer) const
        -> const CellRenderer*;

    auto
    get_edited_cell () -> CellRenderer*;

    auto
    get_edited_cell () const -> const CellRenderer*;

    auto
    get_edit_widget () -> CellEditable*;

    auto
    get_edit_widget () const -> const CellEditable*;

    auto
    activate_cell (Widget& widget,
                   CellRenderer& renderer,
                   const glib::RefPtr<const gdk::Event>& gdk_event,
                   const gdk::Rectangle& cell_area,
                   CellRendererState flags) -> bool;

    auto
    stop_editing (bool canceled) -> void;

    auto
    inner_cell_area (Widget& widget,
                     const gdk::Rectangle& cell_area,
                     gdk::Rectangle& inner_area) -> void;

    auto
    request_renderer (CellRenderer& renderer,
                      Orientation orientation,
                      Widget& widget,
                      int for_size,
                      int& minimum_size,
                      int& natural_size) -> void;

  protected:
    auto
    signal_apply_attributes ()
        -> glib::SignalProxy<void (const glib::RefPtr<TreeModel>&,
                                   const TreeModel::iterator&,
                                   bool,
                                   bool)>;

    auto
    signal_add_editable () -> glib::SignalProxy<void (CellRenderer*,
                                                      CellEditable*,
                                                      const gdk::Rectangle&,
                                                      const glib::ustring&)>;

    auto
    signal_remove_editable ()
        -> glib::SignalProxy<void (CellRenderer*, CellEditable*)>;

    auto
    signal_focus_changed ()
        -> glib::SignalProxy<void (CellRenderer*, const glib::ustring&)>;

    virtual auto
    snapshot_vfunc (const glib::RefPtr<CellAreaContext>& context,
                    Widget& widget,
                    const glib::RefPtr<gtk::Snapshot>& snapshot,
                    const gdk::Rectangle& background_area,
                    const gdk::Rectangle& cell_area,
                    CellRendererState flags,
                    bool paint_focus) -> void;

    virtual auto
    get_request_mode_vfunc () const -> SizeRequestMode;

    virtual auto
    get_preferred_width_vfunc (const glib::RefPtr<CellAreaContext>& context,
                               Widget& widget,
                               int& minimum_width,
                               int& natural_width) -> void;

    virtual auto
    get_preferred_height_for_width_vfunc (
        const glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int width,
        int& minimum_height,
        int& natural_height) -> void;

    virtual auto
    get_preferred_height_vfunc (const glib::RefPtr<CellAreaContext>& context,
                                Widget& widget,
                                int& minimum_height,
                                int& natural_height) -> void;

    virtual auto
    get_preferred_width_for_height_vfunc (
        const glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int height,
        int& minimum_width,
        int& natural_width) -> void;

    auto
    property_focus_cell () -> glib::PropertyProxy<CellRenderer*>;

    auto
    property_focus_cell () const -> glib::PropertyProxy_ReadOnly<CellRenderer*>;

    auto
    property_edited_cell () const
        -> glib::PropertyProxy_ReadOnly<CellRenderer*>;

    auto
    property_edit_widget () const
        -> glib::PropertyProxy_ReadOnly<CellEditable*>;

  public:
  public:
  protected:
    virtual auto
    on_apply_attributes (const glib::RefPtr<TreeModel>& tree_model,
                         const TreeModel::iterator& iter,
                         bool is_expander,
                         bool is_expanded) -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellArea* object, bool take_copy = false) -> glib::RefPtr<gtk::CellArea>;
} // namespace glib

#endif

#endif
