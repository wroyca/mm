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
        sigc::slot<bool (const glib::RefPtr<tab_page>&, glib::ValueBase&)>;

    auto obj = dynamic_cast<tab_bar*> (
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
        sigc::slot<void (const glib::RefPtr<tab_page>&, glib::ValueBase&)>;

    auto obj = dynamic_cast<tab_bar*> (
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
  wrap (AdwTabBar* object, bool take_copy) -> adw::tab_bar*
  {
    return dynamic_cast<adw::tab_bar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  tab_bar_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_tab_bar_get_type ();
    }

    return *this;
  }

  auto
  tab_bar_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new tab_bar ((AdwTabBar*) (o)));
  }

  tab_bar::tab_bar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  tab_bar::tab_bar (AdwTabBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  tab_bar::tab_bar (tab_bar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  tab_bar::operator= (tab_bar&& src) noexcept -> tab_bar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  tab_bar::~tab_bar () noexcept
  {
    destroy_ ();
  }

  tab_bar::CppClassType tab_bar::tabbar_class_;

  auto
  tab_bar::get_type () -> GType
  {
    return tabbar_class_.init ().get_type ();
  }

  auto
  tab_bar::get_base_type () -> GType
  {
    return adw_tab_bar_get_type ();
  }

  tab_bar::tab_bar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (tabbar_class_.init ()))
  {
  }

  auto
  tab_bar::get_autohide () const -> bool
  {
    return adw_tab_bar_get_autohide (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  tab_bar::get_end_action_widget () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_tab_bar_get_end_action_widget (const_cast<AdwTabBar*> (gobj ())));
  }

  auto
  tab_bar::get_expand_tabs () const -> bool
  {
    return adw_tab_bar_get_expand_tabs (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  tab_bar::get_inverted () const -> bool
  {
    return adw_tab_bar_get_inverted (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  tab_bar::get_is_overflowing () const -> bool
  {
    return adw_tab_bar_get_is_overflowing (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  tab_bar::get_start_action_widget () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_tab_bar_get_start_action_widget (const_cast<AdwTabBar*> (gobj ())));
  }

  auto
  tab_bar::get_tabs_revealed () const -> bool
  {
    return adw_tab_bar_get_tabs_revealed (const_cast<AdwTabBar*> (gobj ()));
  }

  auto
  tab_bar::get_view () const -> tab_view*
  {
    return glib::wrap (adw_tab_bar_get_view (const_cast<AdwTabBar*> (gobj ())));
  }

  auto
  tab_bar::set_autohide (bool autohide) -> void
  {
    adw_tab_bar_set_autohide (gobj (), static_cast<int> (autohide));
  }

  auto
  tab_bar::set_end_action_widget (gtk::Widget* widget) -> void
  {
    adw_tab_bar_set_end_action_widget (gobj (),
                                       (GtkWidget*) glib::unwrap (widget));
  }

  auto
  tab_bar::set_expand_tabs (bool expand_tabs) -> void
  {
    adw_tab_bar_set_expand_tabs (gobj (), static_cast<int> (expand_tabs));
  }

  auto
  tab_bar::set_inverted (bool inverted) -> void
  {
    adw_tab_bar_set_inverted (gobj (), static_cast<int> (inverted));
  }

  auto
  tab_bar::set_start_action_widget (gtk::Widget* widget) -> void
  {
    adw_tab_bar_set_start_action_widget (gobj (),
                                         (GtkWidget*) glib::unwrap (widget));
  }

  auto
  tab_bar::set_view (tab_view* view) -> void
  {
    adw_tab_bar_set_view (gobj (), (AdwTabView*) glib::unwrap (view));
  }

  auto
  tab_bar::signal_extra_drag_drop () -> glib::SignalProxy<bool (const glib::RefPtr<tab_page>&,
                                 glib::ValueBase&)>
  {
    return {
      this,
        &TabBar_signal_extra_drag_drop_info
    };
  }

  auto
  tab_bar::property_autohide () -> glib::PropertyProxy<bool>
  {
    return {this, "autohide"};
  }

  auto
  tab_bar::property_autohide () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "autohide"};
  }

  auto
  tab_bar::property_end_action_widget () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "end-action-widget"};
  }

  auto
  tab_bar::property_end_action_widget () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "end-action-widget"};
  }

  auto
  tab_bar::property_expand_tabs () -> glib::PropertyProxy<bool>
  {
    return {this, "expand-tabs"};
  }

  auto
  tab_bar::property_expand_tabs () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "expand-tabs"};
  }

  auto
  tab_bar::property_inverted () -> glib::PropertyProxy<bool>
  {
    return {this, "inverted"};
  }

  auto
  tab_bar::property_inverted () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "inverted"};
  }

  auto
  tab_bar::property_is_overflowing () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-overflowing"};
  }

  auto
  tab_bar::property_start_action_widget () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "start-action-widget"};
  }

  auto
  tab_bar::property_start_action_widget () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "start-action-widget"};
  }

  auto
  tab_bar::property_tabs_revealed () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "tabs-revealed"};
  }

  auto
  tab_bar::property_view () -> glib::PropertyProxy<tab_view*>
  {
    return {this, "view"};
  }

  auto
  tab_bar::property_view () const -> glib::PropertyProxy_ReadOnly<tab_view*>
  {
    return {this, "view"};
  }

} // namespace adw
