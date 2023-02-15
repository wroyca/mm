// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLAREA_H
#define _GTKMM_CELLAREA_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-glib/object.hxx>
  #include <libmm-gtk/buildable.hxx>
  #include <libmm-gtk/cellareacontext.hxx>
  #include <libmm-gtk/celllayout.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellArea = struct _GtkCellArea;
using GtkCellAreaClass = struct _GtkCellAreaClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT CellArea_Class;
}
  #endif

namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Snapshot;

  class LIBMM_GTK_SYMEXPORT CellArea : public Glib::Object,
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
    explicit CellArea (const Glib::ConstructParams& construct_params);
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
        bool (CellRenderer*, const Gdk::Rectangle&, const Gdk::Rectangle&)>
        SlotForeachAlloc;

    auto foreach (const Glib::RefPtr<CellAreaContext>& context,
                  Widget * widget,
                  const Gdk::Rectangle& cell_area,
                  const Gdk::Rectangle& background_area,
                  const SlotForeachAlloc& slot) -> void;

    auto
    event (const Glib::RefPtr<CellAreaContext>& context,
           Widget& widget,
           const Glib::RefPtr<const Gdk::Event>& gdk_event,
           const Gdk::Rectangle& cell_area,
           GtkCellRendererState flags) -> int;

    auto
    snapshot (const Glib::RefPtr<CellAreaContext>& context,
              Widget& widget,
              const Glib::RefPtr<Gtk::Snapshot>& snapshot,
              const Gdk::Rectangle& background_area,
              const Gdk::Rectangle& cell_area,
              CellRendererState flags,
              bool paint_focus) -> void;

    auto
    get_cell_allocation (const Glib::RefPtr<CellAreaContext>& context,
                         Widget& widget,
                         CellRenderer& renderer,
                         const Gdk::Rectangle& cell_area,
                         Gdk::Rectangle& allocation) -> void;

    auto
    get_cell_at_position (const Glib::RefPtr<CellAreaContext>& context,
                          Widget& widget,
                          const Gdk::Rectangle& cell_area,
                          int x,
                          int y,
                          Gdk::Rectangle& alloc_area) -> CellRenderer*;

    auto
    get_cell_at_position (const Glib::RefPtr<CellAreaContext>& context,
                          Widget& widget,
                          const Gdk::Rectangle& cell_area,
                          int x,
                          int y,
                          Gdk::Rectangle& alloc_area) const
        -> const CellRenderer*;

    auto
    create_context () const -> Glib::RefPtr<CellAreaContext>;

    auto
    copy_context (const Glib::RefPtr<const CellAreaContext>& context)
        -> Glib::RefPtr<CellAreaContext>;

    auto
    get_request_mode () const -> SizeRequestMode;

    auto
    get_preferred_width (const Glib::RefPtr<CellAreaContext>& context,
                         Widget& widget,
                         int& minimum_width,
                         int& natural_width) -> void;

    auto
    get_preferred_height_for_width (
        const Glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int width,
        int& minimum_height,
        int& natural_height) -> void;

    auto
    get_preferred_height (const Glib::RefPtr<CellAreaContext>& context,
                          Widget& widget,
                          int& minimum_height,
                          int& natural_height) -> void;

    auto
    get_preferred_width_for_height (
        const Glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int height,
        int& minimum_width,
        int& natural_width) -> void;

    auto
    get_current_path_string () const -> Glib::ustring;

    auto
    apply_attributes (const Glib::RefPtr<TreeModel>& tree_model,
                      const TreeModel::iterator& iter,
                      bool is_expander,
                      bool is_expanded) -> void;

    auto
    attribute_connect (CellRenderer& renderer,
                       const Glib::ustring& attribute,
                       int column) -> void;

    auto
    attribute_disconnect (CellRenderer& renderer,
                          const Glib::ustring& attribute) -> void;

    auto
    attribute_get_column (CellRenderer& renderer,
                          const Glib::ustring& attribute) const -> int;

    auto
    cell_set_property (CellRenderer& renderer,
                       const Glib::ustring& property_name,
                       const Glib::ValueBase& value) -> void;

    auto
    cell_get_property (CellRenderer& renderer,
                       const Glib::ustring& property_name,
                       Glib::ValueBase& value) -> void;

    auto
    is_activatable () const -> bool;

    auto
    activate (const Glib::RefPtr<CellAreaContext>& context,
              Widget& widget,
              const Gdk::Rectangle& cell_area,
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
                   const Glib::RefPtr<const Gdk::Event>& gdk_event,
                   const Gdk::Rectangle& cell_area,
                   CellRendererState flags) -> bool;

    auto
    stop_editing (bool canceled) -> void;

    auto
    inner_cell_area (Widget& widget,
                     const Gdk::Rectangle& cell_area,
                     Gdk::Rectangle& inner_area) -> void;

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
        -> Glib::SignalProxy<void (const Glib::RefPtr<TreeModel>&,
                                   const TreeModel::iterator&,
                                   bool,
                                   bool)>;

    auto
    signal_add_editable () -> Glib::SignalProxy<void (CellRenderer*,
                                                      CellEditable*,
                                                      const Gdk::Rectangle&,
                                                      const Glib::ustring&)>;

    auto
    signal_remove_editable ()
        -> Glib::SignalProxy<void (CellRenderer*, CellEditable*)>;

    auto
    signal_focus_changed ()
        -> Glib::SignalProxy<void (CellRenderer*, const Glib::ustring&)>;

    virtual auto
    snapshot_vfunc (const Glib::RefPtr<CellAreaContext>& context,
                    Widget& widget,
                    const Glib::RefPtr<Gtk::Snapshot>& snapshot,
                    const Gdk::Rectangle& background_area,
                    const Gdk::Rectangle& cell_area,
                    CellRendererState flags,
                    bool paint_focus) -> void;

    virtual auto
    get_request_mode_vfunc () const -> SizeRequestMode;

    virtual auto
    get_preferred_width_vfunc (const Glib::RefPtr<CellAreaContext>& context,
                               Widget& widget,
                               int& minimum_width,
                               int& natural_width) -> void;

    virtual auto
    get_preferred_height_for_width_vfunc (
        const Glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int width,
        int& minimum_height,
        int& natural_height) -> void;

    virtual auto
    get_preferred_height_vfunc (const Glib::RefPtr<CellAreaContext>& context,
                                Widget& widget,
                                int& minimum_height,
                                int& natural_height) -> void;

    virtual auto
    get_preferred_width_for_height_vfunc (
        const Glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int height,
        int& minimum_width,
        int& natural_width) -> void;

    auto
    property_focus_cell () -> Glib::PropertyProxy<CellRenderer*>;

    auto
    property_focus_cell () const -> Glib::PropertyProxy_ReadOnly<CellRenderer*>;

    auto
    property_edited_cell () const
        -> Glib::PropertyProxy_ReadOnly<CellRenderer*>;

    auto
    property_edit_widget () const
        -> Glib::PropertyProxy_ReadOnly<CellEditable*>;

  public:
  public:
  protected:
    virtual auto
    on_apply_attributes (const Glib::RefPtr<TreeModel>& tree_model,
                         const TreeModel::iterator& iter,
                         bool is_expander,
                         bool is_expanded) -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellArea* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellArea>;
} // namespace Glib

#endif

#endif
