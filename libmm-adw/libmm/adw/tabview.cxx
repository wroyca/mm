// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/tabview.hxx>
#include <libmm/adw/tabview_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  auto
  TabView::get_pages () const -> glib::RefPtr<gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_tab_view_get_pages (const_cast<AdwTabView*> (gobj ()));
    g_assert (G_IS_LIST_MODEL (pages));

    glib::ObjectBase* pCppObject =
        glib::ObjectBase::_get_current_wrapper ((GObject*) pages);
    if (!pCppObject)
      pCppObject = new adw::SelectionListModelImpl ((GObject*) pages);
    return glib::make_refptr_for_instance<gtk::SelectionModel> (
        dynamic_cast<gtk::SelectionModel*> (pCppObject));
  }

} // namespace adw

namespace
{

  static auto
  TabView_signal_close_page_callback (AdwTabView* self,
                                      AdwTabPage* p0,
                                      void* data) -> gboolean
  {
    using namespace adw;
    using SlotType = sigc::slot<bool (const glib::RefPtr<TabPage>&)>;

    auto obj = dynamic_cast<TabView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true)));
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
  TabView_signal_close_page_notify_callback (AdwTabView* self,
                                             AdwTabPage* p0,
                                             void* data) -> gboolean
  {
    using namespace adw;
    using SlotType = sigc::slot<void (const glib::RefPtr<TabPage>&)>;

    auto obj = dynamic_cast<TabView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo TabView_signal_close_page_info = {
      "close-page",
      (GCallback) &TabView_signal_close_page_callback,
      (GCallback) &TabView_signal_close_page_notify_callback};

  static auto
  TabView_signal_create_window_callback (AdwTabView* self, void* data) -> AdwTabView*
  {
    using namespace adw;
    using SlotType = sigc::slot<TabView*()>;

    auto obj = dynamic_cast<TabView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return (AdwTabView*) glib::unwrap (
              (*static_cast<SlotType*> (slot)) ());
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = AdwTabView*;
    return RType ();
  }

  static auto
  TabView_signal_create_window_notify_callback (AdwTabView* self, void* data) -> AdwTabView*
  {
    using namespace adw;
    using SlotType = sigc::slot<void ()>;

    auto obj = dynamic_cast<TabView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = AdwTabView*;
    return RType ();
  }

  static const glib::SignalProxyInfo TabView_signal_create_window_info = {
      "create-window",
      (GCallback) &TabView_signal_create_window_callback,
      (GCallback) &TabView_signal_create_window_notify_callback};

  static auto
  TabView_signal_indicator_activated_callback (AdwTabView* self,
                                               AdwTabPage* p0,
                                               void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (const glib::RefPtr<TabPage>&)>;

    auto obj = dynamic_cast<TabView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TabView_signal_indicator_activated_info = {
      "indicator-activated",
      (GCallback) &TabView_signal_indicator_activated_callback,
      (GCallback) &TabView_signal_indicator_activated_callback};

  static auto
  TabView_signal_page_attached_callback (AdwTabView* self,
                                         AdwTabPage* p0,
                                         gint p1,
                                         void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (const glib::RefPtr<TabPage>&, int)>;

    auto obj = dynamic_cast<TabView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TabView_signal_page_attached_info = {
      "page-attached",
      (GCallback) &TabView_signal_page_attached_callback,
      (GCallback) &TabView_signal_page_attached_callback};

  static auto
  TabView_signal_page_detached_callback (AdwTabView* self,
                                         AdwTabPage* p0,
                                         gint p1,
                                         void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (const glib::RefPtr<TabPage>&, int)>;

    auto obj = dynamic_cast<TabView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TabView_signal_page_detached_info = {
      "page-detached",
      (GCallback) &TabView_signal_page_detached_callback,
      (GCallback) &TabView_signal_page_detached_callback};

  static auto
  TabView_signal_page_reordered_callback (AdwTabView* self,
                                          AdwTabPage* p0,
                                          gint p1,
                                          void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (const glib::RefPtr<TabPage>&, int)>;

    auto obj = dynamic_cast<TabView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TabView_signal_page_reordered_info = {
      "page-reordered",
      (GCallback) &TabView_signal_page_reordered_callback,
      (GCallback) &TabView_signal_page_reordered_callback};

  static auto
  TabView_signal_setup_menu_callback (AdwTabView* self,
                                      AdwTabPage* p0,
                                      void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (const glib::RefPtr<TabPage>&)>;

    auto obj = dynamic_cast<TabView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TabView_signal_setup_menu_info = {
      "setup-menu",
      (GCallback) &TabView_signal_setup_menu_callback,
      (GCallback) &TabView_signal_setup_menu_callback};

} // namespace

auto
glib::Value<adw::TabViewShortcuts>::value_type () -> GType
{
  return adw_tab_view_shortcuts_get_type ();
}

namespace glib
{

  auto
  wrap (AdwTabView* object, bool take_copy) -> adw::TabView*
  {
    return dynamic_cast<adw::TabView*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  TabView_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_tab_view_get_type ();
    }

    return *this;
  }

  auto
  TabView_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new TabView ((AdwTabView*) (o)));
  }

  TabView::TabView (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  TabView::TabView (AdwTabView* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  TabView::TabView (TabView&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  TabView::operator= (TabView&& src) noexcept -> TabView&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  TabView::~TabView () noexcept
  {
    destroy_ ();
  }

  TabView::CppClassType TabView::tabview_class_;

  auto
  TabView::get_type () -> GType
  {
    return tabview_class_.init ().get_type ();
  }

  auto
  TabView::get_base_type () -> GType
  {
    return adw_tab_view_get_type ();
  }

  TabView::TabView ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (tabview_class_.init ()))
  {
  }

  auto
  TabView::add_page (gtk::Widget* child, const glib::RefPtr<TabPage>& parent) -> glib::RefPtr<TabPage>
  {
    auto retvalue =
        glib::wrap (adw_tab_view_add_page (gobj (),
                                           (GtkWidget*) glib::unwrap (child),
                                           glib::unwrap (parent)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::add_page (gtk::Widget* child) -> glib::RefPtr<TabPage>
  {
    auto retvalue =
        glib::wrap (adw_tab_view_add_page (gobj (),
                                           (GtkWidget*) glib::unwrap (child),
                                           nullptr));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::add_shortcuts (TabViewShortcuts shortcuts) -> void
  {
    adw_tab_view_add_shortcuts (gobj (),
                                static_cast<AdwTabViewShortcuts> (shortcuts));
  }

  auto
  TabView::append (gtk::Widget* child) -> glib::RefPtr<TabPage>
  {
    auto retvalue = glib::wrap (
        adw_tab_view_append (gobj (), (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::append_pinned (gtk::Widget* child) -> glib::RefPtr<TabPage>
  {
    auto retvalue = glib::wrap (
        adw_tab_view_append_pinned (gobj (),
                                    (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::close_other_pages (const glib::RefPtr<TabPage>& page) -> void
  {
    adw_tab_view_close_other_pages (gobj (), glib::unwrap (page));
  }

  auto
  TabView::close_page (const glib::RefPtr<TabPage>& page) -> void
  {
    adw_tab_view_close_page (gobj (), glib::unwrap (page));
  }

  auto
  TabView::close_page_finish (const glib::RefPtr<TabPage>& page, bool confirm) -> void
  {
    adw_tab_view_close_page_finish (gobj (),
                                    glib::unwrap (page),
                                    static_cast<int> (confirm));
  }

  auto
  TabView::close_pages_after (const glib::RefPtr<TabPage>& page) -> void
  {
    adw_tab_view_close_pages_after (gobj (), glib::unwrap (page));
  }

  auto
  TabView::close_pages_before (const glib::RefPtr<TabPage>& page) -> void
  {
    adw_tab_view_close_pages_before (gobj (), glib::unwrap (page));
  }

  auto
  TabView::get_default_icon () const -> glib::RefPtr<gio::Icon>
  {
    auto retvalue = glib::wrap (
        adw_tab_view_get_default_icon (const_cast<AdwTabView*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::get_is_transferring_page () const -> bool
  {
    return adw_tab_view_get_is_transferring_page (
        const_cast<AdwTabView*> (gobj ()));
  }

  auto
  TabView::get_menu_model () const -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (
        adw_tab_view_get_menu_model (const_cast<AdwTabView*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::get_n_pages () const -> int
  {
    return adw_tab_view_get_n_pages (const_cast<AdwTabView*> (gobj ()));
  }

  auto
  TabView::get_n_pinned_pages () const -> int
  {
    return adw_tab_view_get_n_pinned_pages (const_cast<AdwTabView*> (gobj ()));
  }

  auto
  TabView::get_nth_page (int position) const -> glib::RefPtr<TabPage>
  {
    auto retvalue = glib::wrap (
        adw_tab_view_get_nth_page (const_cast<AdwTabView*> (gobj ()),
                                   position));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::get_page (gtk::Widget* child) const -> glib::RefPtr<TabPage>
  {
    auto retvalue =
        glib::wrap (adw_tab_view_get_page (const_cast<AdwTabView*> (gobj ()),
                                           (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::get_page_position (const glib::RefPtr<TabPage>& page) const -> int
  {
    return adw_tab_view_get_page_position (const_cast<AdwTabView*> (gobj ()),
                                           glib::unwrap (page));
  }

  auto
  TabView::get_selected_page () const -> glib::RefPtr<TabPage>
  {
    auto retvalue = glib::wrap (
        adw_tab_view_get_selected_page (const_cast<AdwTabView*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::get_shortcuts () const -> TabViewShortcuts
  {
    return static_cast<TabViewShortcuts> (
        adw_tab_view_get_shortcuts (const_cast<AdwTabView*> (gobj ())));
  }

  auto
  TabView::insert (gtk::Widget* child, int position) -> glib::RefPtr<TabPage>
  {
    auto retvalue =
        glib::wrap (adw_tab_view_insert (gobj (),
                                         (GtkWidget*) glib::unwrap (child),
                                         position));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::insert_pinned (gtk::Widget* child, int position) -> glib::RefPtr<TabPage>
  {
    auto retvalue = glib::wrap (
        adw_tab_view_insert_pinned (gobj (),
                                    (GtkWidget*) glib::unwrap (child),
                                    position));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::prepend (gtk::Widget* child) -> glib::RefPtr<TabPage>
  {
    auto retvalue = glib::wrap (
        adw_tab_view_prepend (gobj (), (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::prepend_pinned (gtk::Widget* child) -> glib::RefPtr<TabPage>
  {
    auto retvalue = glib::wrap (
        adw_tab_view_prepend_pinned (gobj (),
                                     (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::remove_shortcuts (TabViewShortcuts shortcuts) -> void
  {
    adw_tab_view_remove_shortcuts (
        gobj (),
        static_cast<AdwTabViewShortcuts> (shortcuts));
  }

  auto
  TabView::reorder_backward (const glib::RefPtr<TabPage>& page) -> bool
  {
    return adw_tab_view_reorder_backward (gobj (), glib::unwrap (page));
  }

  auto
  TabView::reorder_first (const glib::RefPtr<TabPage>& page) -> bool
  {
    return adw_tab_view_reorder_first (gobj (), glib::unwrap (page));
  }

  auto
  TabView::reorder_forward (const glib::RefPtr<TabPage>& page) -> bool
  {
    return adw_tab_view_reorder_forward (gobj (), glib::unwrap (page));
  }

  auto
  TabView::reorder_last (const glib::RefPtr<TabPage>& page) -> bool
  {
    return adw_tab_view_reorder_last (gobj (), glib::unwrap (page));
  }

  auto
  TabView::reorder_page (const glib::RefPtr<TabPage>& page, int position) -> bool
  {
    return adw_tab_view_reorder_page (gobj (), glib::unwrap (page), position);
  }

  auto
  TabView::select_next_page () -> bool
  {
    return adw_tab_view_select_next_page (gobj ());
  }

  auto
  TabView::select_previous_page () -> bool
  {
    return adw_tab_view_select_previous_page (gobj ());
  }

  auto
  TabView::set_default_icon (const glib::RefPtr<gio::Icon>& default_icon) -> void
  {
    adw_tab_view_set_default_icon (
        gobj (),
        const_cast<GIcon*> (glib::unwrap<gio::Icon> (default_icon)));
  }

  auto
  TabView::set_menu_model (const glib::RefPtr<gio::MenuModel>& menu_model) -> void
  {
    adw_tab_view_set_menu_model (gobj (), glib::unwrap (menu_model));
  }

  auto
  TabView::set_page_pinned (const glib::RefPtr<TabPage>& page, bool pinned) -> void
  {
    adw_tab_view_set_page_pinned (gobj (),
                                  glib::unwrap (page),
                                  static_cast<int> (pinned));
  }

  auto
  TabView::set_selected_page (const glib::RefPtr<TabPage>& selected_page) -> void
  {
    adw_tab_view_set_selected_page (gobj (), glib::unwrap (selected_page));
  }

  auto
  TabView::set_shortcuts (TabViewShortcuts shortcuts) -> void
  {
    adw_tab_view_set_shortcuts (gobj (),
                                static_cast<AdwTabViewShortcuts> (shortcuts));
  }

  auto
  TabView::transfer_page (const glib::RefPtr<TabPage>& page,
                          TabView* other_view,
                          int position) -> void
  {
    adw_tab_view_transfer_page (gobj (),
                                glib::unwrap (page),
                                (AdwTabView*) glib::unwrap (other_view),
                                position);
  }

  auto
  TabView::signal_close_page () -> glib::SignalProxy<bool (const glib::RefPtr<TabPage>&)>
  {
    return {this, &TabView_signal_close_page_info};
  }

  auto
  TabView::signal_create_window () -> glib::SignalProxy<TabView*()>
  {
    return {this, &TabView_signal_create_window_info};
  }

  auto
  TabView::signal_indicator_activated () -> glib::SignalProxy<void (const glib::RefPtr<TabPage>&)>
  {
    return {this, &TabView_signal_indicator_activated_info};
  }

  auto
  TabView::signal_page_attached () -> glib::SignalProxy<void (const glib::RefPtr<TabPage>&, int)>
  {
    return {this, &TabView_signal_page_attached_info};
  }

  auto
  TabView::signal_page_detached () -> glib::SignalProxy<void (const glib::RefPtr<TabPage>&, int)>
  {
    return {this, &TabView_signal_page_detached_info};
  }

  auto
  TabView::signal_page_reordered () -> glib::SignalProxy<void (const glib::RefPtr<TabPage>&, int)>
  {
    return {this, &TabView_signal_page_reordered_info};
  }

  auto
  TabView::signal_setup_menu () -> glib::SignalProxy<void (const glib::RefPtr<TabPage>&)>
  {
    return {this, &TabView_signal_setup_menu_info};
  }

  auto
  TabView::property_default_icon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>
  {
    return {this, "default-icon"};
  }

  auto
  TabView::property_default_icon () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>
  {
    return {this, "default-icon"};
  }

  auto
  TabView::property_is_transferring_page () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-transferring-page"};
  }

  auto
  TabView::property_menu_model () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return {this, "menu-model"};
  }

  auto
  TabView::property_menu_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return {this, "menu-model"};
  }

  auto
  TabView::property_n_pages () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "n-pages"};
  }

  auto
  TabView::property_n_pinned_pages () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "n-pinned-pages"};
  }

  auto
  TabView::property_pages () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>
  {
    return {this, "pages"};
  }

  auto
  TabView::property_selected_page () -> glib::PropertyProxy<glib::RefPtr<TabPage>>
  {
    return {this, "selected-page"};
  }

  auto
  TabView::property_selected_page () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TabPage>>
  {
    return {
      this,
        "selected-page"
    };
  }

  auto
  TabView::property_shortcuts () -> glib::PropertyProxy<TabViewShortcuts>
  {
    return {this, "shortcuts"};
  }

  auto
  TabView::property_shortcuts () const -> glib::PropertyProxy_ReadOnly<TabViewShortcuts>
  {
    return {this, "shortcuts"};
  }

} // namespace adw
