
#ifndef _GTKMM_WIDGET_H
#define _GTKMM_WIDGET_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-pango/context.hxx>
#include <libmm-pango/layout.hxx>

#include <libmm-cairo/region.hxx>
#include <libmm-gdk/clipboard.hxx>
#include <libmm-gdk/cursor.hxx>
#include <libmm-gdk/display.hxx>
#include <libmm-gdk/rectangle.hxx>
#include <libmm-gio/actiongroup.hxx>
#include <libmm-gtk/accessible.hxx>
#include <libmm-gtk/buildable.hxx>
#include <libmm-gtk/constrainttarget.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/object.hxx>
#include <libmm-gtk/requisition.hxx>
#include <libmm-gtk/stylecontext.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkWidget = struct _GtkWidget;
using GtkWidgetClass = struct _GtkWidgetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Widget_Class;
}
#endif

namespace Gio
{
  class GTKMM_API ListModel;
}

namespace Gdk
{
  class GTKMM_API FrameClock;
  class GTKMM_API Paintable;
} // namespace Gdk

namespace Gtk
{

  class GTKMM_API Adjustment;
  class GTKMM_API Window;
  class GTKMM_API Root;
  class GTKMM_API Native;
  class GTKMM_API EventController;
  class GTKMM_API LayoutManager;
  class GTKMM_API Settings;
  class GTKMM_API Snapshot;
  class GTKMM_API Tooltip;

  typedef Gdk::Rectangle Allocation;

  class GTKMM_API Widget : public Object,
                           public Accessible,
                           public Buildable,
                           public ConstraintTarget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Widget CppObjectType;
    typedef Widget_Class CppClassType;
    typedef GtkWidget BaseObjectType;
    typedef GtkWidgetClass BaseClassType;
#endif

    Widget (Widget&& src) noexcept;
    auto
    operator= (Widget&& src) noexcept -> Widget&;

    Widget (const Widget&) = delete;
    auto
    operator= (const Widget&) -> Widget& = delete;

    ~Widget () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Widget_Class;
    static CppClassType widget_class_;

  protected:
    explicit Widget (const Glib::ConstructParams& construct_params);
    explicit Widget (GtkWidget* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkWidget*
    {
      return reinterpret_cast<GtkWidget*> (gobject_);
    }

    auto
    gobj () const -> const GtkWidget*
    {
      return reinterpret_cast<GtkWidget*> (gobject_);
    }

  private:
  public:
    auto
    make_refptr_constrainttarget () -> Glib::RefPtr<ConstraintTarget>;

    auto
    make_refptr_constrainttarget () const
        -> Glib::RefPtr<const ConstraintTarget>;

    void
    show ();

    void
    hide ();

    void
    queue_draw ();

    void
    queue_resize ();

    void
    queue_allocate ();

    void
    size_allocate (const Allocation& allocation, int baseline);

    auto
    get_request_mode () const -> SizeRequestMode;

    void
    measure (Orientation orientation,
             int for_size,
             int& minimum,
             int& natural,
             int& minimum_baseline,
             int& natural_baseline) const;

    void
    get_preferred_size (Requisition& minimum_size,
                        Requisition& natural_size) const;

    void
    set_layout_manager (const Glib::RefPtr<LayoutManager>& layout_manager);

    void
    unset_layout_manager ();

    auto
    get_layout_manager () -> Glib::RefPtr<LayoutManager>;

    auto
    get_layout_manager () const -> Glib::RefPtr<const LayoutManager>;

    auto
    mnemonic_activate (bool group_cycling) -> bool;

    auto
    activate () -> bool;

    void
    set_can_focus (bool can_focus = true);

    auto
    get_can_focus () const -> bool;

    void
    set_focusable (bool focusable = true);

    auto
    get_focusable () const -> bool;

    auto
    has_focus () const -> bool;

    auto
    is_focus () const -> bool;

    auto
    has_visible_focus () const -> bool;

    auto
    grab_focus () -> bool;

    void
    set_focus_on_click (bool focus_on_click = true);

    auto
    get_focus_on_click () const -> bool;

    void
    set_can_target (bool can_target = true);

    auto
    get_can_target () const -> bool;

    auto
    has_default () const -> bool;

    void
    set_receives_default (bool receives_default = true);

    auto
    get_receives_default () const -> bool;

    void
    set_name (const Glib::ustring& name);
    void
    unset_name ();

    auto
    get_name () const -> Glib::ustring;

    void
    set_state_flags (StateFlags flags, bool clear = true);

    void
    unset_state_flags (StateFlags flags);

    auto
    get_state_flags () const -> StateFlags;

    void
    set_sensitive (bool sensitive = true);

    auto
    get_sensitive () const -> bool;

    auto
    is_sensitive () const -> bool;

    void
    set_visible (bool visible = true);

    auto
    get_visible () const -> bool;

    auto
    is_visible () const -> bool;

    auto
    is_drawable () const -> bool;

    auto
    get_realized () const -> bool;

    auto
    get_mapped () const -> bool;

    void
    set_child_visible (bool visible = true);

    auto
    get_child_visible () const -> bool;

    auto
    get_allocated_width () const -> int;

    auto
    get_allocated_height () const -> int;

    auto
    get_allocated_baseline () const -> int;

    auto
    get_allocation () const -> Allocation;

    auto
    get_width () const -> int;

    auto
    get_height () const -> int;

    auto
    get_size (Orientation orientation) const -> int;

    auto
    get_parent () -> Widget*;

    auto
    get_parent () const -> const Widget*;

    auto
    get_root () -> Root*;

    auto
    get_root () const -> const Root*;

    auto
    get_native () -> Native*;

    auto
    get_native () const -> const Native*;

    auto
    child_focus (DirectionType direction) -> bool;

    auto
    keynav_failed (DirectionType direction) -> bool;

    void
    error_bell ();

    void
    set_size_request (int width = -1, int height = -1);

    void
    get_size_request (int& width, int& height) const;

    void
    set_opacity (double opacity);

    auto
    get_opacity () const -> double;

    void
    set_overflow (Overflow overflow);

    auto
    get_overflow () const -> Overflow;

    auto
    get_ancestor (GType widget_type) -> Widget*;

    auto
    get_ancestor (GType widget_type) const -> const Widget*;

    auto
    get_scale_factor () const -> int;

    auto
    get_display () -> Glib::RefPtr<Gdk::Display>;

    auto
    get_display () const -> Glib::RefPtr<const Gdk::Display>;

    auto
    get_settings () -> Glib::RefPtr<Settings>;

    auto
    get_clipboard () -> Glib::RefPtr<Gdk::Clipboard>;

    auto
    get_clipboard () const -> Glib::RefPtr<const Gdk::Clipboard>;

    auto
    get_primary_clipboard () -> Glib::RefPtr<Gdk::Clipboard>;

    auto
    get_primary_clipboard () const -> Glib::RefPtr<const Gdk::Clipboard>;

    auto
    get_hexpand () const -> bool;

    void
    set_hexpand (bool expand = true);

    auto
    get_hexpand_set () const -> bool;

    void
    set_hexpand_set (bool set = true);

    auto
    get_vexpand () const -> bool;

    void
    set_vexpand (bool expand = true);

    auto
    get_vexpand_set () const -> bool;

    void
    set_vexpand_set (bool set = true);

    auto
    compute_expand (Orientation orientation) -> bool;

    void
    set_expand (bool expand = true);

    auto
    get_halign () const -> Align;

    void
    set_halign (Align align);

    auto
    get_valign () const -> Align;

    void
    set_valign (Align align);

    auto
    get_margin_start () const -> int;

    void
    set_margin_start (int margin);

    auto
    get_margin_end () const -> int;

    void
    set_margin_end (int margin);

    auto
    get_margin_top () const -> int;

    void
    set_margin_top (int margin);

    auto
    get_margin_bottom () const -> int;

    void
    set_margin_bottom (int margin);

    void
    set_margin (int margin);

    auto
    is_ancestor (Widget& ancestor) const -> bool;

    auto
    translate_coordinates (Widget& dest_widget,
                           double src_x,
                           double src_y,
                           double& dest_x,
                           double& dest_y) -> bool;

    auto
    contains (double x, double y) const -> bool;

    auto
    pick (double x, double y, PickFlags flags = PickFlags::DEFAULT) -> Widget*;

    auto
    pick (double x, double y, PickFlags flags = PickFlags::DEFAULT) const
        -> const Widget*;

    void
    add_controller (const Glib::RefPtr<EventController>& controller);

    void
    remove_controller (const Glib::RefPtr<EventController>& controller);

    auto
    create_pango_context () -> Glib::RefPtr<Pango::Context>;

    auto
    get_pango_context () -> Glib::RefPtr<Pango::Context>;

    void
    set_font_options (const Cairo::FontOptions& options);

    void
    unset_font_options ();

    auto
    get_font_options () const -> Cairo::FontOptions;

    auto
    create_pango_layout (const Glib::ustring& text)
        -> Glib::RefPtr<Pango::Layout>;

    void
    set_direction (TextDirection dir);

    auto
    get_direction () const -> TextDirection;

    static void
    set_default_direction (TextDirection dir);

    static auto
    get_default_direction () -> TextDirection;

    void
    set_cursor (const Glib::RefPtr<Gdk::Cursor>& cursor);

    void
    set_cursor (const Glib::ustring& name = {});

    auto
    get_cursor () -> Glib::RefPtr<Gdk::Cursor>;

    auto
    get_cursor () const -> Glib::RefPtr<const Gdk::Cursor>;

    auto
    list_mnemonic_labels () -> std::vector<Widget*>;

    auto
    list_mnemonic_labels () const -> std::vector<const Widget*>;

    void
    add_mnemonic_label (Widget& label);

    void
    remove_mnemonic_label (Widget& label);

    auto
    drag_check_threshold (int start_x,
                          int start_y,
                          int current_x,
                          int current_y) -> bool;

    auto
    get_frame_clock () -> Glib::RefPtr<Gdk::FrameClock>;

    auto
    get_frame_clock () const -> Glib::RefPtr<const Gdk::FrameClock>;

    void
    set_parent (Widget& parent);

    void
    unparent ();

    void
    map ();

    void
    unmap ();

    void
    trigger_tooltip_query ();

    void
    set_tooltip_text (const Glib::ustring& text);

    auto
    get_tooltip_text () const -> Glib::ustring;

    void
    set_tooltip_markup (const Glib::ustring& markup);

    auto
    get_tooltip_markup () const -> Glib::ustring;

    void
    set_has_tooltip (bool has_tooltip = TRUE);

    auto
    get_has_tooltip () const -> bool;

    auto
    in_destruction () const -> bool;

    auto
    get_style_context () -> Glib::RefPtr<StyleContext>;

    auto
    get_style_context () const -> Glib::RefPtr<const StyleContext>;

    using SlotTick = sigc::slot<bool (const Glib::RefPtr<Gdk::FrameClock>&)>;

    auto
    add_tick_callback (const SlotTick& slot) -> guint;

    void
    remove_tick_callback (guint id);

    void
    insert_action_group (const Glib::ustring& name,
                         const Glib::RefPtr<Gio::ActionGroup>& group);

    void
    remove_action_group (const Glib::ustring& name);

    auto
    activate_action (const Glib::ustring& name,
                     const Glib::VariantBase& args = {}) -> bool;

    void
    activate_default ();

    void
    set_font_map (const Glib::RefPtr<Pango::FontMap>& font_map);

    auto
    get_font_map () -> Glib::RefPtr<Pango::FontMap>;

    auto
    get_font_map () const -> Glib::RefPtr<const Pango::FontMap>;

    auto
    get_first_child () -> Widget*;

    auto
    get_first_child () const -> const Widget*;

    auto
    get_last_child () -> Widget*;

    auto
    get_last_child () const -> const Widget*;

    auto
    get_next_sibling () -> Widget*;

    auto
    get_next_sibling () const -> const Widget*;

    auto
    get_prev_sibling () -> Widget*;

    auto
    get_prev_sibling () const -> const Widget*;

    auto
    observe_children () -> Glib::RefPtr<Gio::ListModel>;

    auto
    observe_children () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    observe_controllers () -> Glib::RefPtr<Gio::ListModel>;

    auto
    observe_controllers () const -> Glib::RefPtr<const Gio::ListModel>;

    void
    insert_after (Widget& parent, const Widget& previous_sibling);

    void
    insert_before (Widget& parent, const Widget& next_sibling);

    void
    insert_at_start (Widget& parent);

    void
    insert_at_end (Widget& parent);

    void
    snapshot_child (Widget& child, const Glib::RefPtr<Gtk::Snapshot>& snapshot);

    auto
    should_layout () const -> bool;

    auto
    get_css_name () const -> Glib::ustring;

    void
    add_css_class (const Glib::ustring& css_class);

    void
    remove_css_class (const Glib::ustring& css_class);

    auto
    has_css_class (const Glib::ustring& css_class) const -> bool;

    auto
    get_css_classes () const -> std::vector<Glib::ustring>;

    void
    set_css_classes (const std::vector<Glib::ustring>& classes);

    auto
    signal_show () -> Glib::SignalProxy<void ()>;

    auto
    signal_hide () -> Glib::SignalProxy<void ()>;

    auto
    signal_map () -> Glib::SignalProxy<void ()>;

    auto
    signal_unmap () -> Glib::SignalProxy<void ()>;

    auto
    signal_realize () -> Glib::SignalProxy<void ()>;

    auto
    signal_unrealize () -> Glib::SignalProxy<void ()>;

    auto
    signal_state_flags_changed () -> Glib::SignalProxy<void (Gtk::StateFlags)>;

    auto
    signal_direction_changed () -> Glib::SignalProxy<void (TextDirection)>;

    auto
    signal_mnemonic_activate () -> Glib::SignalProxy<bool (bool)>;

    auto
    signal_destroy () -> Glib::SignalProxy<void ()>;

    auto
    signal_query_tooltip () -> Glib::SignalProxy<
        bool (int, int, bool, const Glib::RefPtr<Tooltip>&)>;

    auto
    property_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_parent () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_root () const -> Glib::PropertyProxy_ReadOnly<Root*>;

    auto
    property_width_request () -> Glib::PropertyProxy<int>;

    auto
    property_width_request () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height_request () -> Glib::PropertyProxy<int>;

    auto
    property_height_request () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sensitive () -> Glib::PropertyProxy<bool>;

    auto
    property_sensitive () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_focus () -> Glib::PropertyProxy<bool>;

    auto
    property_can_focus () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_focus () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_target () -> Glib::PropertyProxy<bool>;

    auto
    property_can_target () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_focus_on_click () -> Glib::PropertyProxy<bool>;

    auto
    property_focus_on_click () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_focusable () -> Glib::PropertyProxy<bool>;

    auto
    property_focusable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_default () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_receives_default () -> Glib::PropertyProxy<bool>;

    auto
    property_receives_default () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_cursor () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Cursor>>;

    auto
    property_cursor () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Cursor>>;

    auto
    property_has_tooltip () -> Glib::PropertyProxy<bool>;

    auto
    property_has_tooltip () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_tooltip_markup () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_tooltip_markup () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_tooltip_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_tooltip_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_halign () -> Glib::PropertyProxy<Align>;

    auto
    property_halign () const -> Glib::PropertyProxy_ReadOnly<Align>;

    auto
    property_valign () -> Glib::PropertyProxy<Align>;

    auto
    property_valign () const -> Glib::PropertyProxy_ReadOnly<Align>;

    auto
    property_margin_start () -> Glib::PropertyProxy<int>;

    auto
    property_margin_start () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_margin_end () -> Glib::PropertyProxy<int>;

    auto
    property_margin_end () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_margin_top () -> Glib::PropertyProxy<int>;

    auto
    property_margin_top () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_margin_bottom () -> Glib::PropertyProxy<int>;

    auto
    property_margin_bottom () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_hexpand () -> Glib::PropertyProxy<bool>;

    auto
    property_hexpand () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_hexpand_set () -> Glib::PropertyProxy<bool>;

    auto
    property_hexpand_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_vexpand () -> Glib::PropertyProxy<bool>;

    auto
    property_vexpand () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_vexpand_set () -> Glib::PropertyProxy<bool>;

    auto
    property_vexpand_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_opacity () -> Glib::PropertyProxy<double>;

    auto
    property_opacity () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_overflow () -> Glib::PropertyProxy<Overflow>;

    auto
    property_overflow () const -> Glib::PropertyProxy_ReadOnly<Overflow>;

    auto
    property_scale_factor () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_css_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_css_classes () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_css_classes () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_layout_manager ()
        -> Glib::PropertyProxy<Glib::RefPtr<LayoutManager>>;

    auto
    property_layout_manager () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<LayoutManager>>;

  protected:
    virtual void
    root_vfunc ();

    virtual void
    unroot_vfunc ();

    virtual void
    size_allocate_vfunc (int width, int height, int baseline);

    virtual auto
    get_request_mode_vfunc () const -> SizeRequestMode;

    virtual void
    measure_vfunc (Orientation orientation,
                   int for_size,
                   int& minimum,
                   int& natural,
                   int& minimum_baseline,
                   int& natural_baseline) const;

    virtual auto
    grab_focus_vfunc () -> bool;

    virtual void
    set_focus_child_vfunc (Widget* child);

    virtual void
    compute_expand_vfunc (bool& hexpand_p, bool& vexpand_p);

    virtual auto
    contains_vfunc (double x, double y) const -> bool;

    virtual void
    snapshot_vfunc (const Glib::RefPtr<Gtk::Snapshot>& snapshot);

  protected:
    Widget ();

    void
    realize ();

    void
    unrealize ();

    void
    realize_if_needed ();

    void
    set_focus_child (Widget& child);

    void
    unset_focus_child ();

    auto
    get_focus_child () -> Widget*;

    auto
    get_focus_child () const -> const Widget*;

  public:
  public:
  protected:
    virtual void
    on_show ();

    virtual void
    on_hide ();

    virtual void
    on_map ();

    virtual void
    on_unmap ();

    virtual void
    on_realize ();

    virtual void
    on_unrealize ();

    virtual void
    on_state_flags_changed (Gtk::StateFlags previous_state_flags);

    virtual void
    on_direction_changed (TextDirection direction);

    virtual auto
    on_mnemonic_activate (bool group_cycling) -> bool;

    virtual auto
    on_query_tooltip (int x,
                      int y,
                      bool keyboard_tooltip,
                      const Glib::RefPtr<Tooltip>& tooltip) -> bool;
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkWidget* object, bool take_copy = false) -> Gtk::Widget*;
} // namespace Glib

#endif
