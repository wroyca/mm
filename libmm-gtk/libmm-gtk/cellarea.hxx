
#ifndef _GTKMM_CELLAREA_H
#define _GTKMM_CELLAREA_H

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
  class GTKMM_API CellArea_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API Snapshot;

  class GTKMM_API CellArea : public Glib::Object,
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
    void
    add (CellRenderer& renderer);

    void
    remove (CellRenderer& renderer);

    auto
    has_renderer (CellRenderer& renderer) -> bool;

    typedef sigc::slot<bool (CellRenderer*)> SlotForeach;

    void foreach (const SlotForeach& slot);

    typedef sigc::slot<
        bool (CellRenderer*, const Gdk::Rectangle&, const Gdk::Rectangle&)>
        SlotForeachAlloc;

    void foreach (const Glib::RefPtr<CellAreaContext>& context,
                  Widget * widget,
                  const Gdk::Rectangle& cell_area,
                  const Gdk::Rectangle& background_area,
                  const SlotForeachAlloc& slot);

    auto
    event (const Glib::RefPtr<CellAreaContext>& context,
           Widget& widget,
           const Glib::RefPtr<const Gdk::Event>& gdk_event,
           const Gdk::Rectangle& cell_area,
           GtkCellRendererState flags) -> int;

    void
    snapshot (const Glib::RefPtr<CellAreaContext>& context,
              Widget& widget,
              const Glib::RefPtr<Gtk::Snapshot>& snapshot,
              const Gdk::Rectangle& background_area,
              const Gdk::Rectangle& cell_area,
              CellRendererState flags,
              bool paint_focus);

    void
    get_cell_allocation (const Glib::RefPtr<CellAreaContext>& context,
                         Widget& widget,
                         CellRenderer& renderer,
                         const Gdk::Rectangle& cell_area,
                         Gdk::Rectangle& allocation);

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

    void
    get_preferred_width (const Glib::RefPtr<CellAreaContext>& context,
                         Widget& widget,
                         int& minimum_width,
                         int& natural_width);

    void
    get_preferred_height_for_width (
        const Glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int width,
        int& minimum_height,
        int& natural_height);

    void
    get_preferred_height (const Glib::RefPtr<CellAreaContext>& context,
                          Widget& widget,
                          int& minimum_height,
                          int& natural_height);

    void
    get_preferred_width_for_height (
        const Glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int height,
        int& minimum_width,
        int& natural_width);

    auto
    get_current_path_string () const -> Glib::ustring;

    void
    apply_attributes (const Glib::RefPtr<TreeModel>& tree_model,
                      const TreeModel::iterator& iter,
                      bool is_expander,
                      bool is_expanded);

    void
    attribute_connect (CellRenderer& renderer,
                       const Glib::ustring& attribute,
                       int column);

    void
    attribute_disconnect (CellRenderer& renderer,
                          const Glib::ustring& attribute);

    auto
    attribute_get_column (CellRenderer& renderer,
                          const Glib::ustring& attribute) const -> int;

    void
    cell_set_property (CellRenderer& renderer,
                       const Glib::ustring& property_name,
                       const Glib::ValueBase& value);

    void
    cell_get_property (CellRenderer& renderer,
                       const Glib::ustring& property_name,
                       Glib::ValueBase& value);

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

    void
    set_focus_cell (CellRenderer& renderer);

    auto
    get_focus_cell () -> CellRenderer*;

    auto
    get_focus_cell () const -> const CellRenderer*;

    void
    add_focus_sibling (CellRenderer& renderer, CellRenderer& sibling);

    void
    remove_focus_sibling (CellRenderer& renderer, CellRenderer& sibling);

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

    void
    stop_editing (bool canceled);

    void
    inner_cell_area (Widget& widget,
                     const Gdk::Rectangle& cell_area,
                     Gdk::Rectangle& inner_area);

    void
    request_renderer (CellRenderer& renderer,
                      Orientation orientation,
                      Widget& widget,
                      int for_size,
                      int& minimum_size,
                      int& natural_size);

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

    virtual void
    snapshot_vfunc (const Glib::RefPtr<CellAreaContext>& context,
                    Widget& widget,
                    const Glib::RefPtr<Gtk::Snapshot>& snapshot,
                    const Gdk::Rectangle& background_area,
                    const Gdk::Rectangle& cell_area,
                    CellRendererState flags,
                    bool paint_focus);

    virtual auto
    get_request_mode_vfunc () const -> SizeRequestMode;

    virtual void
    get_preferred_width_vfunc (const Glib::RefPtr<CellAreaContext>& context,
                               Widget& widget,
                               int& minimum_width,
                               int& natural_width);

    virtual void
    get_preferred_height_for_width_vfunc (
        const Glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int width,
        int& minimum_height,
        int& natural_height);

    virtual void
    get_preferred_height_vfunc (const Glib::RefPtr<CellAreaContext>& context,
                                Widget& widget,
                                int& minimum_height,
                                int& natural_height);

    virtual void
    get_preferred_width_for_height_vfunc (
        const Glib::RefPtr<CellAreaContext>& context,
        Widget& widget,
        int height,
        int& minimum_width,
        int& natural_width);

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
    virtual void
    on_apply_attributes (const Glib::RefPtr<TreeModel>& tree_model,
                         const TreeModel::iterator& iter,
                         bool is_expander,
                         bool is_expanded);
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkCellArea* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellArea>;
} // namespace Glib

#endif
