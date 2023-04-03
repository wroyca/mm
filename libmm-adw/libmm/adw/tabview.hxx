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
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT TabView_Class;
}
#endif

namespace Adw
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

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<Adw::TabViewShortcuts>
    : public Glib::Value_Flags<Adw::TabViewShortcuts>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT TabView : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef TabView CppObjectType;
    typedef TabView_Class CppClassType;
    typedef AdwTabView BaseObjectType;
    typedef AdwTabViewClass BaseClassType;
#endif

    TabView (TabView&& src) noexcept;
    auto
    operator= (TabView&& src) noexcept -> TabView&;

    TabView (const TabView&) = delete;
    auto
    operator= (const TabView&) -> TabView& = delete;

    ~TabView () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class TabView_Class;
    static CppClassType tabview_class_;

  protected:
    explicit TabView (const Glib::ConstructParams& construct_params);
    explicit TabView (AdwTabView* castitem);

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
    TabView ();

    auto
    add_page (Gtk::Widget* child, const Glib::RefPtr<TabPage>& parent)
        -> Glib::RefPtr<TabPage>;

    auto
    add_page (Gtk::Widget* child) -> Glib::RefPtr<TabPage>;

    auto
    add_shortcuts (TabViewShortcuts shortcuts) -> void;

    auto
    append (Gtk::Widget* child) -> Glib::RefPtr<TabPage>;

    auto
    append_pinned (Gtk::Widget* child) -> Glib::RefPtr<TabPage>;

    auto
    close_other_pages (const Glib::RefPtr<TabPage>& page) -> void;

    auto
    close_page (const Glib::RefPtr<TabPage>& page) -> void;

    auto
    close_page_finish (const Glib::RefPtr<TabPage>& page, bool confirm) -> void;

    auto
    close_pages_after (const Glib::RefPtr<TabPage>& page) -> void;

    auto
    close_pages_before (const Glib::RefPtr<TabPage>& page) -> void;

    auto
    get_default_icon () const -> Glib::RefPtr<Gio::Icon>;

    auto
    get_is_transferring_page () const -> bool;

    auto
    get_menu_model () const -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_n_pages () const -> int;

    auto
    get_n_pinned_pages () const -> int;

    auto
    get_nth_page (int position) const -> Glib::RefPtr<TabPage>;

    auto
    get_page (Gtk::Widget* child) const -> Glib::RefPtr<TabPage>;

    auto
    get_page_position (const Glib::RefPtr<TabPage>& page) const -> int;

    auto
    get_pages () const -> Glib::RefPtr<Gtk::SelectionModel>;

    auto
    get_selected_page () const -> Glib::RefPtr<TabPage>;

    auto
    get_shortcuts () const -> TabViewShortcuts;

    auto
    insert (Gtk::Widget* child, int position) -> Glib::RefPtr<TabPage>;

    auto
    insert_pinned (Gtk::Widget* child, int position) -> Glib::RefPtr<TabPage>;

    auto
    prepend (Gtk::Widget* child) -> Glib::RefPtr<TabPage>;

    auto
    prepend_pinned (Gtk::Widget* child) -> Glib::RefPtr<TabPage>;

    auto
    remove_shortcuts (TabViewShortcuts shortcuts) -> void;

    auto
    reorder_backward (const Glib::RefPtr<TabPage>& page) -> bool;

    auto
    reorder_first (const Glib::RefPtr<TabPage>& page) -> bool;

    auto
    reorder_forward (const Glib::RefPtr<TabPage>& page) -> bool;

    auto
    reorder_last (const Glib::RefPtr<TabPage>& page) -> bool;

    auto
    reorder_page (const Glib::RefPtr<TabPage>& page, int position) -> bool;

    auto
    select_next_page () -> bool;

    auto
    select_previous_page () -> bool;

    auto
    set_default_icon (const Glib::RefPtr<Gio::Icon>& default_icon) -> void;

    auto
    set_menu_model (const Glib::RefPtr<Gio::MenuModel>& menu_model) -> void;

    auto
    set_page_pinned (const Glib::RefPtr<TabPage>& page, bool pinned) -> void;

    auto
    set_selected_page (const Glib::RefPtr<TabPage>& selected_page) -> void;

    auto
    set_shortcuts (TabViewShortcuts shortcuts) -> void;

    auto
    transfer_page (const Glib::RefPtr<TabPage>& page,
                   TabView* other_view,
                   int position) -> void;

    auto
    property_default_icon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>;

    auto
    property_default_icon () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>;

    auto
    property_is_transferring_page () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_menu_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_menu_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_n_pages () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_n_pinned_pages () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pages () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>>;

    auto
    property_selected_page () -> Glib::PropertyProxy<Glib::RefPtr<TabPage>>;

    auto
    property_selected_page () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TabPage>>;

    auto
    property_shortcuts () -> Glib::PropertyProxy<TabViewShortcuts>;

    auto
    property_shortcuts () const
        -> Glib::PropertyProxy_ReadOnly<TabViewShortcuts>;

    auto
    signal_close_page ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<TabPage>&)>;

    auto
    signal_create_window () -> Glib::SignalProxy<TabView*()>;

    auto
    signal_indicator_activated ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&)>;

    auto
    signal_page_attached ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&, int)>;

    auto
    signal_page_detached ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&, int)>;

    auto
    signal_page_reordered ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&, int)>;

    auto
    signal_setup_menu ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&)>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwTabView* object, bool take_copy = false) -> Adw::TabView*;
}

#endif
