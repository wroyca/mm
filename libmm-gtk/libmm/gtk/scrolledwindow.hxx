// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCROLLEDWINDOW_H
#define _GTKMM_SCROLLEDWINDOW_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScrolledWindow = struct _GtkScrolledWindow;
using GtkScrolledWindowClass = struct _GtkScrolledWindowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ScrolledWindow_Class;
}
#endif

namespace Gtk
{

  class Adjustment;
  class Scrollbar;

  class LIBMM_GTK_SYMEXPORT ScrolledWindow : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ScrolledWindow CppObjectType;
    typedef ScrolledWindow_Class CppClassType;
    typedef GtkScrolledWindow BaseObjectType;
    typedef GtkScrolledWindowClass BaseClassType;
#endif

    ScrolledWindow (ScrolledWindow&& src) noexcept;
    auto
    operator= (ScrolledWindow&& src) noexcept -> ScrolledWindow&;

    ScrolledWindow (const ScrolledWindow&) = delete;
    auto
    operator= (const ScrolledWindow&) -> ScrolledWindow& = delete;

    ~ScrolledWindow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class ScrolledWindow_Class;
    static CppClassType scrolledwindow_class_;

  protected:
    explicit ScrolledWindow (const Glib::ConstructParams& construct_params);
    explicit ScrolledWindow (GtkScrolledWindow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkScrolledWindow*
    {
      return reinterpret_cast<GtkScrolledWindow*> (gobject_);
    }

    auto
    gobj () const -> const GtkScrolledWindow*
    {
      return reinterpret_cast<GtkScrolledWindow*> (gobject_);
    }

  private:
  public:
    ScrolledWindow ();

    auto
    set_hadjustment (const Glib::RefPtr<Adjustment>& hadjustment) -> void;

    auto
    set_vadjustment (const Glib::RefPtr<Adjustment>& vadjustment) -> void;

    auto
    get_hadjustment () -> Glib::RefPtr<Adjustment>;

    auto
    get_hadjustment () const -> Glib::RefPtr<const Adjustment>;

    auto
    get_vadjustment () -> Glib::RefPtr<Adjustment>;

    auto
    get_vadjustment () const -> Glib::RefPtr<const Adjustment>;

    auto
    set_policy (PolicyType hscrollbar_policy, PolicyType vscrollbar_policy)
        -> void;

    auto
    get_policy (PolicyType& hscrollbar_policy,
                PolicyType& vscrollbar_policy) const -> void;

    auto
    set_placement (CornerType window_placement) -> void;

    auto
    unset_placement () -> void;

    auto
    get_placement () const -> CornerType;

    auto
    set_has_frame (bool has_frame = true) -> void;

    auto
    get_has_frame () const -> bool;

    auto
    get_vscrollbar () -> Scrollbar*;

    auto
    get_vscrollbar () const -> const Scrollbar*;

    auto
    get_hscrollbar () -> Scrollbar*;

    auto
    get_hscrollbar () const -> const Scrollbar*;

    auto
    get_min_content_width () const -> int;

    auto
    set_min_content_width (int width) -> void;

    auto
    get_min_content_height () const -> int;

    auto
    set_min_content_height (int height) -> void;

    auto
    set_kinetic_scrolling (bool kinetic_scrolling = true) -> void;

    auto
    get_kinetic_scrolling () const -> bool;

    auto
    set_overlay_scrolling (bool overlay_scrolling = true) -> void;

    auto
    get_overlay_scrolling () const -> bool;

    auto
    set_max_content_width (int width) -> void;

    auto
    get_max_content_width () const -> int;

    auto
    set_max_content_height (int height) -> void;

    auto
    get_max_content_height () const -> int;

    auto
    set_propagate_natural_width (bool propagate = true) -> void;

    auto
    get_propagate_natural_width () const -> bool;

    auto
    set_propagate_natural_height (bool propagate = true) -> void;

    auto
    get_propagate_natural_height () const -> bool;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    signal_edge_overshot () -> Glib::SignalProxy<void (Gtk::PositionType)>;

    auto
    signal_edge_reached () -> Glib::SignalProxy<void (Gtk::PositionType)>;

    auto
    property_hadjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>;

    auto
    property_hadjustment () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>;

    auto
    property_vadjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>;

    auto
    property_vadjustment () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>;

    auto
    property_hscrollbar_policy () -> Glib::PropertyProxy<PolicyType>;

    auto
    property_hscrollbar_policy () const
        -> Glib::PropertyProxy_ReadOnly<PolicyType>;

    auto
    property_vscrollbar_policy () -> Glib::PropertyProxy<PolicyType>;

    auto
    property_vscrollbar_policy () const
        -> Glib::PropertyProxy_ReadOnly<PolicyType>;

    auto
    property_window_placement () -> Glib::PropertyProxy<CornerType>;

    auto
    property_window_placement () const
        -> Glib::PropertyProxy_ReadOnly<CornerType>;

    auto
    property_has_frame () -> Glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_min_content_width () -> Glib::PropertyProxy<int>;

    auto
    property_min_content_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_min_content_height () -> Glib::PropertyProxy<int>;

    auto
    property_min_content_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_kinetic_scrolling () -> Glib::PropertyProxy<bool>;

    auto
    property_kinetic_scrolling () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_overlay_scrolling () -> Glib::PropertyProxy<bool>;

    auto
    property_overlay_scrolling () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_max_content_width () -> Glib::PropertyProxy<int>;

    auto
    property_max_content_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_max_content_height () -> Glib::PropertyProxy<int>;

    auto
    property_max_content_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_propagate_natural_width () -> Glib::PropertyProxy<bool>;

    auto
    property_propagate_natural_width () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_propagate_natural_height () -> Glib::PropertyProxy<bool>;

    auto
    property_propagate_natural_height () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkScrolledWindow* object, bool take_copy = false) -> Gtk::ScrolledWindow*;
} // namespace Glib

#endif
