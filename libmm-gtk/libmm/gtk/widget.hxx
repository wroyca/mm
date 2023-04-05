// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WIDGET_H
#define _GTKMM_WIDGET_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/pango/context.hxx>
#include <libmm/pango/layout.hxx>

#include <libmm/cairo/region.hxx>
#include <libmm/gdk/clipboard.hxx>
#include <libmm/gdk/cursor.hxx>
#include <libmm/gdk/display.hxx>
#include <libmm/gdk/rectangle.hxx>
#include <libmm/gdk/rgba.hxx>
#include <libmm/gio/actiongroup.hxx>
#include <libmm/gtk/accessible.hxx>
#include <libmm/gtk/buildable.hxx>
#include <libmm/gtk/constrainttarget.hxx>
#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/object.hxx>
#include <libmm/gtk/requisition.hxx>
#include <libmm/gtk/stylecontext.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkWidget = struct _GtkWidget;
using GtkWidgetClass = struct _GtkWidgetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Widget_Class;
}
#endif

namespace gio
{
  class LIBMM_GTK_SYMEXPORT ListModel;
}

namespace gdk
{
  class LIBMM_GTK_SYMEXPORT FrameClock;
  class LIBMM_GTK_SYMEXPORT Paintable;
} // namespace gdk

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Adjustment;
  class LIBMM_GTK_SYMEXPORT Window;
  class LIBMM_GTK_SYMEXPORT Root;
  class LIBMM_GTK_SYMEXPORT Native;
  class LIBMM_GTK_SYMEXPORT EventController;
  class LIBMM_GTK_SYMEXPORT LayoutManager;
  class LIBMM_GTK_SYMEXPORT Settings;
  class LIBMM_GTK_SYMEXPORT Snapshot;
  class LIBMM_GTK_SYMEXPORT Tooltip;

  typedef gdk::Rectangle Allocation;

  class LIBMM_GTK_SYMEXPORT Widget : public Object,
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
    friend LIBMM_GTK_SYMEXPORT class Widget_Class;
    static CppClassType widget_class_;

  protected:
    explicit Widget (const glib::ConstructParams& construct_params);
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
    make_refptr_constrainttarget () -> glib::RefPtr<ConstraintTarget>;

    auto
    make_refptr_constrainttarget () const
        -> glib::RefPtr<const ConstraintTarget>;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    show () -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    hide () -> void;
#endif

    auto
    queue_draw () -> void;

    auto
    queue_resize () -> void;

    auto
    queue_allocate () -> void;

    auto
    size_allocate (const Allocation& allocation, int baseline) -> void;

    auto
    get_request_mode () const -> SizeRequestMode;

    auto
    measure (Orientation orientation,
             int for_size,
             int& minimum,
             int& natural,
             int& minimum_baseline,
             int& natural_baseline) const -> void;

    auto
    get_preferred_size (Requisition& minimum_size,
                        Requisition& natural_size) const -> void;

    auto
    set_layout_manager (const glib::RefPtr<LayoutManager>& layout_manager)
        -> void;

    auto
    unset_layout_manager () -> void;

    auto
    get_layout_manager () -> glib::RefPtr<LayoutManager>;

    auto
    get_layout_manager () const -> glib::RefPtr<const LayoutManager>;

    auto
    mnemonic_activate (bool group_cycling) -> bool;

    auto
    activate () -> bool;

    auto
    set_can_focus (bool can_focus = true) -> void;

    auto
    get_can_focus () const -> bool;

    auto
    set_focusable (bool focusable = true) -> void;

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

    auto
    set_focus_on_click (bool focus_on_click = true) -> void;

    auto
    get_focus_on_click () const -> bool;

    auto
    set_can_target (bool can_target = true) -> void;

    auto
    get_can_target () const -> bool;

    auto
    has_default () const -> bool;

    auto
    set_receives_default (bool receives_default = true) -> void;

    auto
    get_receives_default () const -> bool;

    auto
    set_name (const glib::ustring& name) -> void;
    auto
    unset_name () -> void;

    auto
    get_name () const -> glib::ustring;

    auto
    set_state_flags (StateFlags flags, bool clear = true) -> void;

    auto
    unset_state_flags (StateFlags flags) -> void;

    auto
    get_state_flags () const -> StateFlags;

    auto
    set_sensitive (bool sensitive = true) -> void;

    auto
    get_sensitive () const -> bool;

    auto
    is_sensitive () const -> bool;

    auto
    set_visible (bool visible = true) -> void;

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

    auto
    set_child_visible (bool visible = true) -> void;

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

    auto
    error_bell () -> void;

    auto
    set_size_request (int width = -1, int height = -1) -> void;

    auto
    get_size_request (int& width, int& height) const -> void;

    auto
    set_opacity (double opacity) -> void;

    auto
    get_opacity () const -> double;

    auto
    set_overflow (Overflow overflow) -> void;

    auto
    get_overflow () const -> Overflow;

    auto
    get_ancestor (GType widget_type) -> Widget*;

    auto
    get_ancestor (GType widget_type) const -> const Widget*;

    auto
    get_scale_factor () const -> int;

    auto
    get_display () -> glib::RefPtr<gdk::Display>;

    auto
    get_display () const -> glib::RefPtr<const gdk::Display>;

    auto
    get_settings () -> glib::RefPtr<Settings>;

    auto
    get_clipboard () -> glib::RefPtr<gdk::Clipboard>;

    auto
    get_clipboard () const -> glib::RefPtr<const gdk::Clipboard>;

    auto
    get_primary_clipboard () -> glib::RefPtr<gdk::Clipboard>;

    auto
    get_primary_clipboard () const -> glib::RefPtr<const gdk::Clipboard>;

    auto
    get_hexpand () const -> bool;

    auto
    set_hexpand (bool expand = true) -> void;

    auto
    get_hexpand_set () const -> bool;

    auto
    set_hexpand_set (bool set = true) -> void;

    auto
    get_vexpand () const -> bool;

    auto
    set_vexpand (bool expand = true) -> void;

    auto
    get_vexpand_set () const -> bool;

    auto
    set_vexpand_set (bool set = true) -> void;

    auto
    compute_expand (Orientation orientation) -> bool;

    auto
    set_expand (bool expand = true) -> void;

    auto
    get_halign () const -> Align;

    auto
    set_halign (Align align) -> void;

    auto
    get_valign () const -> Align;

    auto
    set_valign (Align align) -> void;

    auto
    get_margin_start () const -> int;

    auto
    set_margin_start (int margin) -> void;

    auto
    get_margin_end () const -> int;

    auto
    set_margin_end (int margin) -> void;

    auto
    get_margin_top () const -> int;

    auto
    set_margin_top (int margin) -> void;

    auto
    get_margin_bottom () const -> int;

    auto
    set_margin_bottom (int margin) -> void;

    auto
    set_margin (int margin) -> void;

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

    auto
    add_controller (const glib::RefPtr<EventController>& controller) -> void;

    auto
    remove_controller (const glib::RefPtr<EventController>& controller) -> void;

    auto
    create_pango_context () -> glib::RefPtr<pango::Context>;

    auto
    get_pango_context () -> glib::RefPtr<pango::Context>;

    auto
    set_font_options (const cairo::FontOptions& options) -> void;

    auto
    unset_font_options () -> void;

    auto
    get_font_options () const -> cairo::FontOptions;

    auto
    create_pango_layout (const glib::ustring& text)
        -> glib::RefPtr<pango::Layout>;

    auto
    set_direction (TextDirection dir) -> void;

    auto
    get_direction () const -> TextDirection;

    static auto
    set_default_direction (TextDirection dir) -> void;

    static auto
    get_default_direction () -> TextDirection;

    auto
    set_cursor (const glib::RefPtr<gdk::Cursor>& cursor) -> void;

    auto
    set_cursor (const glib::ustring& name = {}) -> void;

    auto
    get_cursor () -> glib::RefPtr<gdk::Cursor>;

    auto
    get_cursor () const -> glib::RefPtr<const gdk::Cursor>;

    auto
    list_mnemonic_labels () -> std::vector<Widget*>;

    auto
    list_mnemonic_labels () const -> std::vector<const Widget*>;

    auto
    add_mnemonic_label (Widget& label) -> void;

    auto
    remove_mnemonic_label (Widget& label) -> void;

    auto
    drag_check_threshold (int start_x,
                          int start_y,
                          int current_x,
                          int current_y) -> bool;

    auto
    get_frame_clock () -> glib::RefPtr<gdk::FrameClock>;

    auto
    get_frame_clock () const -> glib::RefPtr<const gdk::FrameClock>;

    auto
    set_parent (Widget& parent) -> void;

    auto
    unparent () -> void;

    auto
    map () -> void;

    auto
    unmap () -> void;

    auto
    trigger_tooltip_query () -> void;

    auto
    set_tooltip_text (const glib::ustring& text) -> void;

    auto
    get_tooltip_text () const -> glib::ustring;

    auto
    set_tooltip_markup (const glib::ustring& markup) -> void;

    auto
    get_tooltip_markup () const -> glib::ustring;

    auto
    set_has_tooltip (bool has_tooltip = TRUE) -> void;

    auto
    get_has_tooltip () const -> bool;

    auto
    in_destruction () const -> bool;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_style_context () -> glib::RefPtr<StyleContext>;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_style_context () const -> glib::RefPtr<const StyleContext>;
#endif

    using SlotTick = sigc::slot<bool (const glib::RefPtr<gdk::FrameClock>&)>;

    auto
    add_tick_callback (const SlotTick& slot) -> guint;

    auto
    remove_tick_callback (guint id) -> void;

    auto
    insert_action_group (const glib::ustring& name,
                         const glib::RefPtr<gio::ActionGroup>& group) -> void;

    auto
    remove_action_group (const glib::ustring& name) -> void;

    auto
    activate_action (const glib::ustring& name,
                     const glib::VariantBase& args = {}) -> bool;

    auto
    activate_default () -> void;

    auto
    set_font_map (const glib::RefPtr<pango::FontMap>& font_map) -> void;

    auto
    get_font_map () -> glib::RefPtr<pango::FontMap>;

    auto
    get_font_map () const -> glib::RefPtr<const pango::FontMap>;

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
    observe_children () -> glib::RefPtr<gio::ListModel>;

    auto
    observe_children () const -> glib::RefPtr<const gio::ListModel>;

    auto
    observe_controllers () -> glib::RefPtr<gio::ListModel>;

    auto
    observe_controllers () const -> glib::RefPtr<const gio::ListModel>;

    auto
    insert_after (Widget& parent, const Widget& previous_sibling) -> void;

    auto
    insert_before (Widget& parent, const Widget& next_sibling) -> void;

    auto
    insert_at_start (Widget& parent) -> void;

    auto
    insert_at_end (Widget& parent) -> void;

    auto
    snapshot_child (Widget& child, const glib::RefPtr<gtk::Snapshot>& snapshot)
        -> void;

    auto
    should_layout () const -> bool;

    auto
    get_css_name () const -> glib::ustring;

    auto
    add_css_class (const glib::ustring& css_class) -> void;

    auto
    remove_css_class (const glib::ustring& css_class) -> void;

    auto
    has_css_class (const glib::ustring& css_class) const -> bool;

    auto
    get_css_classes () const -> std::vector<glib::ustring>;

    auto
    set_css_classes (const std::vector<glib::ustring>& classes) -> void;

    auto
    get_color () const -> gdk::RGBA;

    auto
    signal_show () -> glib::SignalProxy<void ()>;

    auto
    signal_hide () -> glib::SignalProxy<void ()>;

    auto
    signal_map () -> glib::SignalProxy<void ()>;

    auto
    signal_unmap () -> glib::SignalProxy<void ()>;

    auto
    signal_realize () -> glib::SignalProxy<void ()>;

    auto
    signal_unrealize () -> glib::SignalProxy<void ()>;

    auto
    signal_state_flags_changed () -> glib::SignalProxy<void (gtk::StateFlags)>;

    auto
    signal_direction_changed () -> glib::SignalProxy<void (TextDirection)>;

    auto
    signal_mnemonic_activate () -> glib::SignalProxy<bool (bool)>;

    auto
    signal_destroy () -> glib::SignalProxy<void ()>;

    auto
    signal_query_tooltip () -> glib::SignalProxy<
        bool (int, int, bool, const glib::RefPtr<Tooltip>&)>;

    auto
    property_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_parent () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_root () const -> glib::PropertyProxy_ReadOnly<Root*>;

    auto
    property_width_request () -> glib::PropertyProxy<int>;

    auto
    property_width_request () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height_request () -> glib::PropertyProxy<int>;

    auto
    property_height_request () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_visible () -> glib::PropertyProxy<bool>;

    auto
    property_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sensitive () -> glib::PropertyProxy<bool>;

    auto
    property_sensitive () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_focus () -> glib::PropertyProxy<bool>;

    auto
    property_can_focus () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_focus () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_target () -> glib::PropertyProxy<bool>;

    auto
    property_can_target () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_focus_on_click () -> glib::PropertyProxy<bool>;

    auto
    property_focus_on_click () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_focusable () -> glib::PropertyProxy<bool>;

    auto
    property_focusable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_default () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_receives_default () -> glib::PropertyProxy<bool>;

    auto
    property_receives_default () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_cursor () -> glib::PropertyProxy<glib::RefPtr<gdk::Cursor>>;

    auto
    property_cursor () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Cursor>>;

    auto
    property_has_tooltip () -> glib::PropertyProxy<bool>;

    auto
    property_has_tooltip () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_tooltip_markup () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_tooltip_markup () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_tooltip_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_tooltip_text () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_halign () -> glib::PropertyProxy<Align>;

    auto
    property_halign () const -> glib::PropertyProxy_ReadOnly<Align>;

    auto
    property_valign () -> glib::PropertyProxy<Align>;

    auto
    property_valign () const -> glib::PropertyProxy_ReadOnly<Align>;

    auto
    property_margin_start () -> glib::PropertyProxy<int>;

    auto
    property_margin_start () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_margin_end () -> glib::PropertyProxy<int>;

    auto
    property_margin_end () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_margin_top () -> glib::PropertyProxy<int>;

    auto
    property_margin_top () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_margin_bottom () -> glib::PropertyProxy<int>;

    auto
    property_margin_bottom () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_hexpand () -> glib::PropertyProxy<bool>;

    auto
    property_hexpand () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_hexpand_set () -> glib::PropertyProxy<bool>;

    auto
    property_hexpand_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_vexpand () -> glib::PropertyProxy<bool>;

    auto
    property_vexpand () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_vexpand_set () -> glib::PropertyProxy<bool>;

    auto
    property_vexpand_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_opacity () -> glib::PropertyProxy<double>;

    auto
    property_opacity () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_overflow () -> glib::PropertyProxy<Overflow>;

    auto
    property_overflow () const -> glib::PropertyProxy_ReadOnly<Overflow>;

    auto
    property_scale_factor () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_css_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_css_classes () -> glib::PropertyProxy<std::vector<glib::ustring>>;

    auto
    property_css_classes () const
        -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;

    auto
    property_layout_manager ()
        -> glib::PropertyProxy<glib::RefPtr<LayoutManager>>;

    auto
    property_layout_manager () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<LayoutManager>>;

  protected:
    virtual auto
    root_vfunc () -> void;

    virtual auto
    unroot_vfunc () -> void;

    virtual auto
    size_allocate_vfunc (int width, int height, int baseline) -> void;

    virtual auto
    get_request_mode_vfunc () const -> SizeRequestMode;

    virtual auto
    measure_vfunc (Orientation orientation,
                   int for_size,
                   int& minimum,
                   int& natural,
                   int& minimum_baseline,
                   int& natural_baseline) const -> void;

    virtual auto
    grab_focus_vfunc () -> bool;

    virtual auto
    set_focus_child_vfunc (Widget* child) -> void;

    virtual auto
    compute_expand_vfunc (bool& hexpand_p, bool& vexpand_p) -> void;

    virtual auto
    contains_vfunc (double x, double y) const -> bool;

    virtual auto
    snapshot_vfunc (const glib::RefPtr<gtk::Snapshot>& snapshot) -> void;

  protected:
    Widget ();

    auto
    realize () -> void;

    auto
    unrealize () -> void;

    auto
    realize_if_needed () -> void;

    auto
    set_focus_child (Widget& child) -> void;

    auto
    unset_focus_child () -> void;

    auto
    get_focus_child () -> Widget*;

    auto
    get_focus_child () const -> const Widget*;

  public:
  public:
  protected:
    virtual auto
    on_show () -> void;

    virtual auto
    on_hide () -> void;

    virtual auto
    on_map () -> void;

    virtual auto
    on_unmap () -> void;

    virtual auto
    on_realize () -> void;

    virtual auto
    on_unrealize () -> void;

    virtual auto
    on_state_flags_changed (gtk::StateFlags previous_state_flags) -> void;

    virtual auto
    on_direction_changed (TextDirection direction) -> void;

    virtual auto
    on_mnemonic_activate (bool group_cycling) -> bool;

    virtual auto
    on_query_tooltip (int x,
                      int y,
                      bool keyboard_tooltip,
                      const glib::RefPtr<Tooltip>& tooltip) -> bool;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkWidget* object, bool take_copy = false) -> gtk::Widget*;
} // namespace glib

#endif
