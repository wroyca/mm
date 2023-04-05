// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/tabbar.hxx>
#include <libmm/adw/tabbar_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{

  static auto
  TabBar_signal_extra_drag_drop_callback (AdwTabBar* self,
                                          AdwTabPage* p0,
                                          GValue* p1,
                                          void* data) -> gboolean
  {
    using namespace adw;
    using SlotType =
        sigc::slot<bool (const glib::RefPtr<TabPage>&, glib::ValueBase&)>;

    auto obj = dynamic_cast<TabBar*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              glib::wrap (p0, true),
              *reinterpret_cast<glib::ValueBase*> (p1)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  TabBar_signal_extra_drag_drop_notify_callback (AdwTabBar* self,
                                                 AdwTabPage* p0,
                                                 GValue* p1,
                                                 void* data) -> gboolean
  {
    using namespace adw;
    using SlotType =
        sigc::slot<void (const glib::RefPtr<TabPage>&, glib::ValueBase&)>;

    auto obj = dynamic_cast<TabBar*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::wrap (p0, true),
              *reinterpret_cast<glib::ValueBase*> (p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo TabBar_signal_extra_drag_drop_info = {
      "extra-drag-drop",
      (GCallback) &TabBar_signal_extra_drag_drop_callback,
      (GCallback) &TabBar_signal_extra_drag_drop_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (AdwTabBar* object, bool take_copy) -> adw::TabBar*
  {
    return dynamic_cast<adw::TabBar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  TabBar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_tab_bar_get_type ();
    }

    return *this;
  }

  auto
  TabBar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new TabBar ((AdwTabBar*) (o)));
  }

  TabBar::TabBar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  TabBar::TabBar (AdwTabBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  TabBar::TabBar (TabBar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  TabBar::operator= (TabBar&& src) noexcept -> TabBar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  TabBar::~TabBar () noexcept
  {
    destroy_ ();
  }

  TabBar::CppClassType TabBar::tabbar_class_;

  auto
  TabBar::get_type () -> GType
  {
    return tabbar_class_.init ().get_type ();
  }

  auto
  TabBar::get_base_type () -> GType
  {
    return adw_tab_bar_get_type ();
  }

  TabBar::TabBar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (tabbar_class_.init ()))
  {
  }

  auto
  TabBar::get_autohide () const -> bool
  {
    return adw_tab_bar_get_autohide (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  TabBar::get_end_action_widget () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_tab_bar_get_end_action_widget (const_cast<AdwTabBar*> (gobj ())));
  }

  auto
  TabBar::get_expand_tabs () const -> bool
  {
    return adw_tab_bar_get_expand_tabs (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  TabBar::get_inverted () const -> bool
  {
    return adw_tab_bar_get_inverted (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  TabBar::get_is_overflowing () const -> bool
  {
    return adw_tab_bar_get_is_overflowing (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  TabBar::get_start_action_widget () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_tab_bar_get_start_action_widget (const_cast<AdwTabBar*> (gobj ())));
  }

  auto
  TabBar::get_tabs_revealed () const -> bool
  {
    return adw_tab_bar_get_tabs_revealed (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  TabBar::get_view () const -> TabView*
  {
    return glib::wrap (adw_tab_bar_get_view (const_cast<AdwTabBar*> (gobj ())));
  }

  auto
  TabBar::set_autohide (bool autohide) -> void
  {
    adw_tab_bar_set_autohide (gobj (), static_cast<int> (autohide));
  }

  auto
  TabBar::set_end_action_widget (gtk::Widget* widget) -> void
  {
    adw_tab_bar_set_end_action_widget (gobj (),
                                       (GtkWidget*) glib::unwrap (widget));
  }

  auto
  TabBar::set_expand_tabs (bool expand_tabs) -> void
  {
    adw_tab_bar_set_expand_tabs (gobj (), static_cast<int> (expand_tabs));
  }

  auto
  TabBar::set_inverted (bool inverted) -> void
  {
    adw_tab_bar_set_inverted (gobj (), static_cast<int> (inverted));
  }

  auto
  TabBar::set_start_action_widget (gtk::Widget* widget) -> void
  {
    adw_tab_bar_set_start_action_widget (gobj (),
                                         (GtkWidget*) glib::unwrap (widget));
  }

  auto
  TabBar::set_view (TabView* view) -> void
  {
    adw_tab_bar_set_view (gobj (), (AdwTabView*) glib::unwrap (view));
  }

  auto
  TabBar::signal_extra_drag_drop () -> glib::SignalProxy<bool (const glib::RefPtr<TabPage>&,
                                 glib::ValueBase&)>
  {
    return glib::SignalProxy<bool (const glib::RefPtr<TabPage>&,
                                   glib::ValueBase&)> (
        this,
        &TabBar_signal_extra_drag_drop_info);
  }

  auto
  TabBar::property_autohide () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "autohide");
  }

  auto
  TabBar::property_autohide () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "autohide");
  }

  auto
  TabBar::property_end_action_widget () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "end-action-widget");
  }

  auto
  TabBar::property_end_action_widget () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this,
                                                       "end-action-widget");
  }

  auto
  TabBar::property_expand_tabs () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "expand-tabs");
  }

  auto
  TabBar::property_expand_tabs () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "expand-tabs");
  }

  auto
  TabBar::property_inverted () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "inverted");
  }

  auto
  TabBar::property_inverted () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "inverted");
  }

  auto
  TabBar::property_is_overflowing () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "is-overflowing");
  }

  auto
  TabBar::property_start_action_widget () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "start-action-widget");
  }

  auto
  TabBar::property_start_action_widget () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this,
                                                       "start-action-widget");
  }

  auto
  TabBar::property_tabs_revealed () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "tabs-revealed");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<TabView*>::value,
      "Type TabView* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TabBar::property_view () -> glib::PropertyProxy<TabView*>
  {
    return glib::PropertyProxy<TabView*> (this, "view");
  }

  auto
  TabBar::property_view () const -> glib::PropertyProxy_ReadOnly<TabView*>
  {
    return glib::PropertyProxy_ReadOnly<TabView*> (this, "view");
  }

} // namespace adw
