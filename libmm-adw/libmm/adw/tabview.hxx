// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TABVIEW_H
#define _LIBADWAITAMM_TABVIEW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/tabpage.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT tab_view_class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT TabViewShortcuts
  {
    NONE = 0x0,
    CONTROL_TAB = 1 << 0,
    CONTROL_SHIFT_TAB = 1 << 1,
    CONTROL_PAGE_UP = 1 << 2,
    CONTROL_PAGE_DOWN = 1 << 3,
    CONTROL_HOME = 1 << 4,
    CONTROL_END = 1 << 5,
    CONTROL_SHIFT_PAGE_UP = 1 << 6,
    CONTROL_SHIFT_PAGE_DOWN = 1 << 7,
    CONTROL_SHIFT_HOME = 1 << 8,
    CONTROL_SHIFT_END = 1 << 9,
    ALT_DIGITS = 1 << 10,
    ALT_ZERO = 1 << 11,
    ALL_SHORTCUTS = 0xFFF
  };

  inline auto
  operator| (TabViewShortcuts lhs, TabViewShortcuts rhs) -> TabViewShortcuts
  {
    return static_cast<TabViewShortcuts> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (TabViewShortcuts lhs, TabViewShortcuts rhs) -> TabViewShortcuts
  {
    return static_cast<TabViewShortcuts> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (TabViewShortcuts lhs, TabViewShortcuts rhs) -> TabViewShortcuts
  {
    return static_cast<TabViewShortcuts> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(TabViewShortcuts flags) -> TabViewShortcuts
  {
    return static_cast<TabViewShortcuts> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (TabViewShortcuts& lhs, TabViewShortcuts rhs) -> TabViewShortcuts&
  {
    return (lhs = static_cast<TabViewShortcuts> (static_cast<unsigned> (lhs) |
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (TabViewShortcuts& lhs, TabViewShortcuts rhs) -> TabViewShortcuts&
  {
    return (lhs = static_cast<TabViewShortcuts> (static_cast<unsigned> (lhs) &
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (TabViewShortcuts& lhs, TabViewShortcuts rhs) -> TabViewShortcuts&
  {
    return (lhs = static_cast<TabViewShortcuts> (static_cast<unsigned> (lhs) ^
                                                 static_cast<unsigned> (rhs)));
  }

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::TabViewShortcuts>
    : public glib::Value_Flags<adw::TabViewShortcuts>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT tab_view : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = tab_view;
    using CppClassType = tab_view_class;
    using BaseObjectType = AdwTabView;
    using BaseClassType = AdwTabViewClass;
#endif

    tab_view (tab_view&& src) noexcept;
    auto
    operator= (tab_view&& src) noexcept -> tab_view&;

    tab_view (const tab_view&) = delete;
    auto
    operator= (const tab_view&) -> tab_view& = delete;

    ~tab_view () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class tab_view_class;
    static CppClassType tabview_class_;

  protected:
    explicit tab_view (const glib::ConstructParams& construct_params);
    explicit tab_view (AdwTabView* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwTabView*
    {
      return reinterpret_cast<AdwTabView*> (gobject_);
    }

    auto
    gobj () const -> const AdwTabView*
    {
      return reinterpret_cast<AdwTabView*> (gobject_);
    }

  private:
  public:
    tab_view ();

    auto
    add_page (gtk::Widget* child, const glib::RefPtr<tab_page>& parent)
        -> glib::RefPtr<tab_page>;

    auto
    add_page (gtk::Widget* child) -> glib::RefPtr<tab_page>;

    auto
    add_shortcuts (TabViewShortcuts shortcuts) -> void;

    auto
    append (gtk::Widget* child) -> glib::RefPtr<tab_page>;

    auto
    append_pinned (gtk::Widget* child) -> glib::RefPtr<tab_page>;

    auto
    close_other_pages (const glib::RefPtr<tab_page>& page) -> void;

    auto
    close_page (const glib::RefPtr<tab_page>& page) -> void;

    auto
    close_page_finish (const glib::RefPtr<tab_page>& page, bool confirm) -> void;

    auto
    close_pages_after (const glib::RefPtr<tab_page>& page) -> void;

    auto
    close_pages_before (const glib::RefPtr<tab_page>& page) -> void;

    auto
    get_default_icon () const -> glib::RefPtr<gio::Icon>;

    auto
    get_is_transferring_page () const -> bool;

    auto
    get_menu_model () const -> glib::RefPtr<gio::MenuModel>;

    auto
    get_n_pages () const -> int;

    auto
    get_n_pinned_pages () const -> int;

    auto
    get_nth_page (int position) const -> glib::RefPtr<tab_page>;

    auto
    get_page (gtk::Widget* child) const -> glib::RefPtr<tab_page>;

    auto
    get_page_position (const glib::RefPtr<tab_page>& page) const -> int;

    auto
    get_pages () const -> glib::RefPtr<gtk::SelectionModel>;

    auto
    get_selected_page () const -> glib::RefPtr<tab_page>;

    auto
    get_shortcuts () const -> TabViewShortcuts;

    auto
    insert (gtk::Widget* child, int position) -> glib::RefPtr<tab_page>;

    auto
    insert_pinned (gtk::Widget* child, int position) -> glib::RefPtr<tab_page>;

    auto
    prepend (gtk::Widget* child) -> glib::RefPtr<tab_page>;

    auto
    prepend_pinned (gtk::Widget* child) -> glib::RefPtr<tab_page>;

    auto
    remove_shortcuts (TabViewShortcuts shortcuts) -> void;

    auto
    reorder_backward (const glib::RefPtr<tab_page>& page) -> bool;

    auto
    reorder_first (const glib::RefPtr<tab_page>& page) -> bool;

    auto
    reorder_forward (const glib::RefPtr<tab_page>& page) -> bool;

    auto
    reorder_last (const glib::RefPtr<tab_page>& page) -> bool;

    auto
    reorder_page (const glib::RefPtr<tab_page>& page, int position) -> bool;

    auto
    select_next_page () -> bool;

    auto
    select_previous_page () -> bool;

    auto
    set_default_icon (const glib::RefPtr<gio::Icon>& default_icon) -> void;

    auto
    set_menu_model (const glib::RefPtr<gio::MenuModel>& menu_model) -> void;

    auto
    set_page_pinned (const glib::RefPtr<tab_page>& page, bool pinned) -> void;

    auto
    set_selected_page (const glib::RefPtr<tab_page>& selected_page) -> void;

    auto
    set_shortcuts (TabViewShortcuts shortcuts) -> void;

    auto
    transfer_page (const glib::RefPtr<tab_page>& page,
                   tab_view* other_view,
                   int position) -> void;

    auto
    property_default_icon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>;

    auto
    property_default_icon () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>;

    auto
    property_is_transferring_page () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_menu_model () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_menu_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

    auto
    property_n_pages () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_n_pinned_pages () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pages () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>;

    auto
    property_selected_page () -> glib::PropertyProxy<glib::RefPtr<tab_page>>;

    auto
    property_selected_page () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<tab_page>>;

    auto
    property_shortcuts () -> glib::PropertyProxy<TabViewShortcuts>;

    auto
    property_shortcuts () const
        -> glib::PropertyProxy_ReadOnly<TabViewShortcuts>;

    auto
    signal_close_page ()
        -> glib::SignalProxy<bool (const glib::RefPtr<tab_page>&)>;

    auto
    signal_create_window () -> glib::SignalProxy<tab_view*()>;

    auto
    signal_indicator_activated ()
        -> glib::SignalProxy<void (const glib::RefPtr<tab_page>&)>;

    auto
    signal_page_attached ()
        -> glib::SignalProxy<void (const glib::RefPtr<tab_page>&, int)>;

    auto
    signal_page_detached ()
        -> glib::SignalProxy<void (const glib::RefPtr<tab_page>&, int)>;

    auto
    signal_page_reordered ()
        -> glib::SignalProxy<void (const glib::RefPtr<tab_page>&, int)>;

    auto
    signal_setup_menu ()
        -> glib::SignalProxy<void (const glib::RefPtr<tab_page>&)>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwTabView* object, bool take_copy = false) -> adw::tab_view*;
}

#endif
