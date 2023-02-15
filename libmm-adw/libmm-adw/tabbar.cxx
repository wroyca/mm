// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/tabbar.hxx>
#include <libmm-adw/tabbar_p.hxx>

#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
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
    using namespace Adw;
    using SlotType =
        sigc::slot<bool (const Glib::RefPtr<TabPage>&, Glib::ValueBase&)>;

    auto obj = dynamic_cast<TabBar*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              Glib::wrap (p0, true),
              *reinterpret_cast<Glib::ValueBase*> (p1)));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
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
    using namespace Adw;
    using SlotType =
        sigc::slot<void (const Glib::RefPtr<TabPage>&, Glib::ValueBase&)>;

    auto obj = dynamic_cast<TabBar*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::wrap (p0, true),
              *reinterpret_cast<Glib::ValueBase*> (p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const Glib::SignalProxyInfo TabBar_signal_extra_drag_drop_info = {
      "extra-drag-drop",
      (GCallback) &TabBar_signal_extra_drag_drop_callback,
      (GCallback) &TabBar_signal_extra_drag_drop_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (AdwTabBar* object, bool take_copy) -> Adw::TabBar*
  {
    return dynamic_cast<Adw::TabBar*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  TabBar_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_tab_bar_get_type ();
    }

    return *this;
  }

  auto
  TabBar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new TabBar ((AdwTabBar*) (o)));
  }

  TabBar::TabBar (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  TabBar::TabBar (AdwTabBar* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  TabBar::TabBar (TabBar&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  TabBar::operator= (TabBar&& src) noexcept -> TabBar&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (tabbar_class_.init ()))
  {
  }

  auto
  TabBar::get_autohide () const -> bool
  {
    return adw_tab_bar_get_autohide (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  TabBar::get_end_action_widget () const -> Gtk::Widget*
  {
    return Glib::wrap (
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
  TabBar::get_start_action_widget () const -> Gtk::Widget*
  {
    return Glib::wrap (
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
    return Glib::wrap (adw_tab_bar_get_view (const_cast<AdwTabBar*> (gobj ())));
  }

  auto
  TabBar::set_autohide (bool autohide) -> void
  {
    adw_tab_bar_set_autohide (gobj (), static_cast<int> (autohide));
  }

  auto
  TabBar::set_end_action_widget (Gtk::Widget* widget) -> void
  {
    adw_tab_bar_set_end_action_widget (gobj (),
                                       (GtkWidget*) Glib::unwrap (widget));
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
  TabBar::set_start_action_widget (Gtk::Widget* widget) -> void
  {
    adw_tab_bar_set_start_action_widget (gobj (),
                                         (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  TabBar::set_view (TabView* view) -> void
  {
    adw_tab_bar_set_view (gobj (), (AdwTabView*) Glib::unwrap (view));
  }

  auto
  TabBar::signal_extra_drag_drop () -> Glib::SignalProxy<bool (const Glib::RefPtr<TabPage>&,
                                 Glib::ValueBase&)>
  {
    return Glib::SignalProxy<bool (const Glib::RefPtr<TabPage>&,
                                   Glib::ValueBase&)> (
        this,
        &TabBar_signal_extra_drag_drop_info);
  }

  auto
  TabBar::property_autohide () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "autohide");
  }

  auto
  TabBar::property_autohide () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "autohide");
  }

  auto
  TabBar::property_end_action_widget () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "end-action-widget");
  }

  auto
  TabBar::property_end_action_widget () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this,
                                                       "end-action-widget");
  }

  auto
  TabBar::property_expand_tabs () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "expand-tabs");
  }

  auto
  TabBar::property_expand_tabs () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "expand-tabs");
  }

  auto
  TabBar::property_inverted () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "inverted");
  }

  auto
  TabBar::property_inverted () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "inverted");
  }

  auto
  TabBar::property_is_overflowing () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "is-overflowing");
  }

  auto
  TabBar::property_start_action_widget () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "start-action-widget");
  }

  auto
  TabBar::property_start_action_widget () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this,
                                                       "start-action-widget");
  }

  auto
  TabBar::property_tabs_revealed () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "tabs-revealed");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<TabView*>::value,
      "Type TabView* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TabBar::property_view () -> Glib::PropertyProxy<TabView*>
  {
    return Glib::PropertyProxy<TabView*> (this, "view");
  }

  auto
  TabBar::property_view () const -> Glib::PropertyProxy_ReadOnly<TabView*>
  {
    return Glib::PropertyProxy_ReadOnly<TabView*> (this, "view");
  }

} // namespace Adw
