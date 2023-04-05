// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TABBAR_H
#define _LIBADWAITAMM_TABBAR_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/tabview.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT TabBar_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT TabBar : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef TabBar CppObjectType;
    typedef TabBar_Class CppClassType;
    typedef AdwTabBar BaseObjectType;
    typedef AdwTabBarClass BaseClassType;
#endif

    TabBar (TabBar&& src) noexcept;
    auto
    operator= (TabBar&& src) noexcept -> TabBar&;

    TabBar (const TabBar&) = delete;
    auto
    operator= (const TabBar&) -> TabBar& = delete;

    ~TabBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class TabBar_Class;
    static CppClassType tabbar_class_;

  protected:
    explicit TabBar (const glib::ConstructParams& construct_params);
    explicit TabBar (AdwTabBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwTabBar*
    {
      return reinterpret_cast<AdwTabBar*> (gobject_);
    }

    auto
    gobj () const -> const AdwTabBar*
    {
      return reinterpret_cast<AdwTabBar*> (gobject_);
    }

  private:
  public:
    TabBar ();

    auto
    get_autohide () const -> bool;

    auto
    get_end_action_widget () const -> gtk::Widget*;

    auto
    get_expand_tabs () const -> bool;

    auto
    get_inverted () const -> bool;

    auto
    get_is_overflowing () const -> bool;

    auto
    get_start_action_widget () const -> gtk::Widget*;

    auto
    get_tabs_revealed () const -> bool;

    auto
    get_view () const -> TabView*;

    auto
    set_autohide (bool autohide) -> void;

    auto
    set_end_action_widget (gtk::Widget* widget) -> void;

    auto
    set_expand_tabs (bool expand_tabs) -> void;

    auto
    set_inverted (bool inverted) -> void;

    auto
    set_start_action_widget (gtk::Widget* widget) -> void;

    auto
    set_view (TabView* view) -> void;

    auto
    setup_extra_drop_target (gdk::DragAction actions,
                             const std::vector<GType> types) -> void
    {
      adw_tab_bar_setup_extra_drop_target (
          const_cast<AdwTabBar*> (gobj ()),
          static_cast<GdkDragAction> (actions),
          glib::ArrayHandler<GType>::vector_to_array (types).data (),
          types.size ());
    }

    auto
    property_autohide () -> glib::PropertyProxy<bool>;

    auto
    property_autohide () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_end_action_widget () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_end_action_widget () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_expand_tabs () -> glib::PropertyProxy<bool>;

    auto
    property_expand_tabs () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_inverted () -> glib::PropertyProxy<bool>;

    auto
    property_inverted () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_overflowing () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_start_action_widget () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_start_action_widget () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_tabs_revealed () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_view () -> glib::PropertyProxy<TabView*>;

    auto
    property_view () const -> glib::PropertyProxy_ReadOnly<TabView*>;

    auto
    signal_extra_drag_drop ()
        -> glib::SignalProxy<bool (const glib::RefPtr<TabPage>&,
                                   glib::ValueBase&)>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwTabBar* object, bool take_copy = false) -> adw::TabBar*;
}

#endif
