// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/tabview.hxx>
#include <libmm/adw/tabview_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

  auto
  TabView::get_pages () const -> Glib::RefPtr<Gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_tab_view_get_pages (const_cast<AdwTabView*> (gobj ()));
    g_assert (G_IS_LIST_MODEL (pages));

    Glib::ObjectBase* pCppObject =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) pages);
    if (!pCppObject)
      pCppObject = new Adw::SelectionListModelImpl ((GObject*) pages);
    return Glib::make_refptr_for_instance<Gtk::SelectionModel> (
        dynamic_cast<Gtk::SelectionModel*> (pCppObject));
  }

} // namespace Adw

namespace
{

  static auto
  TabView_signal_close_page_callback (AdwTabView* self,
                                      AdwTabPage* p0,
                                      void* data) -> gboolean
  {
    using namespace Adw;
    using SlotType = sigc::slot<bool (const Glib::RefPtr<TabPage>&)>;

    auto obj = dynamic_cast<TabView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true)));
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
  TabView_signal_close_page_notify_callback (AdwTabView* self,
                                             AdwTabPage* p0,
                                             void* data) -> gboolean
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (const Glib::RefPtr<TabPage>&)>;

    auto obj = dynamic_cast<TabView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const Glib::SignalProxyInfo TabView_signal_close_page_info = {
      "close-page",
      (GCallback) &TabView_signal_close_page_callback,
      (GCallback) &TabView_signal_close_page_notify_callback};

  static auto
  TabView_signal_create_window_callback (AdwTabView* self, void* data) -> AdwTabView*
  {
    using namespace Adw;
    using SlotType = sigc::slot<TabView*()>;

    auto obj = dynamic_cast<TabView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (AdwTabView*) Glib::unwrap (
              (*static_cast<SlotType*> (slot)) ());
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = AdwTabView*;
    return RType ();
  }

  static auto
  TabView_signal_create_window_notify_callback (AdwTabView* self, void* data) -> AdwTabView*
  {
    using namespace Adw;
    using SlotType = sigc::slot<void ()>;

    auto obj = dynamic_cast<TabView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = AdwTabView*;
    return RType ();
  }

  static const Glib::SignalProxyInfo TabView_signal_create_window_info = {
      "create-window",
      (GCallback) &TabView_signal_create_window_callback,
      (GCallback) &TabView_signal_create_window_notify_callback};

  static auto
  TabView_signal_indicator_activated_callback (AdwTabView* self,
                                               AdwTabPage* p0,
                                               void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (const Glib::RefPtr<TabPage>&)>;

    auto obj = dynamic_cast<TabView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TabView_signal_indicator_activated_info = {
      "indicator-activated",
      (GCallback) &TabView_signal_indicator_activated_callback,
      (GCallback) &TabView_signal_indicator_activated_callback};

  static auto
  TabView_signal_page_attached_callback (AdwTabView* self,
                                         AdwTabPage* p0,
                                         gint p1,
                                         void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (const Glib::RefPtr<TabPage>&, int)>;

    auto obj = dynamic_cast<TabView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TabView_signal_page_attached_info = {
      "page-attached",
      (GCallback) &TabView_signal_page_attached_callback,
      (GCallback) &TabView_signal_page_attached_callback};

  static auto
  TabView_signal_page_detached_callback (AdwTabView* self,
                                         AdwTabPage* p0,
                                         gint p1,
                                         void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (const Glib::RefPtr<TabPage>&, int)>;

    auto obj = dynamic_cast<TabView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TabView_signal_page_detached_info = {
      "page-detached",
      (GCallback) &TabView_signal_page_detached_callback,
      (GCallback) &TabView_signal_page_detached_callback};

  static auto
  TabView_signal_page_reordered_callback (AdwTabView* self,
                                          AdwTabPage* p0,
                                          gint p1,
                                          void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (const Glib::RefPtr<TabPage>&, int)>;

    auto obj = dynamic_cast<TabView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TabView_signal_page_reordered_info = {
      "page-reordered",
      (GCallback) &TabView_signal_page_reordered_callback,
      (GCallback) &TabView_signal_page_reordered_callback};

  static auto
  TabView_signal_setup_menu_callback (AdwTabView* self,
                                      AdwTabPage* p0,
                                      void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (const Glib::RefPtr<TabPage>&)>;

    auto obj = dynamic_cast<TabView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TabView_signal_setup_menu_info = {
      "setup-menu",
      (GCallback) &TabView_signal_setup_menu_callback,
      (GCallback) &TabView_signal_setup_menu_callback};

} // namespace

auto
Glib::Value<Adw::TabViewShortcuts>::value_type () -> GType
{
  return adw_tab_view_shortcuts_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwTabView* object, bool take_copy) -> Adw::TabView*
  {
    return dynamic_cast<Adw::TabView*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  TabView_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_tab_view_get_type ();
    }

    return *this;
  }

  auto
  TabView_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new TabView ((AdwTabView*) (o)));
  }

  TabView::TabView (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  TabView::TabView (AdwTabView* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  TabView::TabView (TabView&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  TabView::operator= (TabView&& src) noexcept -> TabView&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (tabview_class_.init ()))
  {
  }

  auto
  TabView::add_page (Gtk::Widget* child, const Glib::RefPtr<TabPage>& parent) -> Glib::RefPtr<TabPage>
  {
    auto retvalue =
        Glib::wrap (adw_tab_view_add_page (gobj (),
                                           (GtkWidget*) Glib::unwrap (child),
                                           Glib::unwrap (parent)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::add_page (Gtk::Widget* child) -> Glib::RefPtr<TabPage>
  {
    auto retvalue =
        Glib::wrap (adw_tab_view_add_page (gobj (),
                                           (GtkWidget*) Glib::unwrap (child),
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
  TabView::append (Gtk::Widget* child) -> Glib::RefPtr<TabPage>
  {
    auto retvalue = Glib::wrap (
        adw_tab_view_append (gobj (), (GtkWidget*) Glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::append_pinned (Gtk::Widget* child) -> Glib::RefPtr<TabPage>
  {
    auto retvalue = Glib::wrap (
        adw_tab_view_append_pinned (gobj (),
                                    (GtkWidget*) Glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::close_other_pages (const Glib::RefPtr<TabPage>& page) -> void
  {
    adw_tab_view_close_other_pages (gobj (), Glib::unwrap (page));
  }

  auto
  TabView::close_page (const Glib::RefPtr<TabPage>& page) -> void
  {
    adw_tab_view_close_page (gobj (), Glib::unwrap (page));
  }

  auto
  TabView::close_page_finish (const Glib::RefPtr<TabPage>& page, bool confirm) -> void
  {
    adw_tab_view_close_page_finish (gobj (),
                                    Glib::unwrap (page),
                                    static_cast<int> (confirm));
  }

  auto
  TabView::close_pages_after (const Glib::RefPtr<TabPage>& page) -> void
  {
    adw_tab_view_close_pages_after (gobj (), Glib::unwrap (page));
  }

  auto
  TabView::close_pages_before (const Glib::RefPtr<TabPage>& page) -> void
  {
    adw_tab_view_close_pages_before (gobj (), Glib::unwrap (page));
  }

  auto
  TabView::get_default_icon () const -> Glib::RefPtr<Gio::Icon>
  {
    auto retvalue = Glib::wrap (
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
  TabView::get_menu_model () const -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (
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
  TabView::get_nth_page (int position) const -> Glib::RefPtr<TabPage>
  {
    auto retvalue = Glib::wrap (
        adw_tab_view_get_nth_page (const_cast<AdwTabView*> (gobj ()),
                                   position));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::get_page (Gtk::Widget* child) const -> Glib::RefPtr<TabPage>
  {
    auto retvalue =
        Glib::wrap (adw_tab_view_get_page (const_cast<AdwTabView*> (gobj ()),
                                           (GtkWidget*) Glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::get_page_position (const Glib::RefPtr<TabPage>& page) const -> int
  {
    return adw_tab_view_get_page_position (const_cast<AdwTabView*> (gobj ()),
                                           Glib::unwrap (page));
  }

  auto
  TabView::get_selected_page () const -> Glib::RefPtr<TabPage>
  {
    auto retvalue = Glib::wrap (
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
  TabView::insert (Gtk::Widget* child, int position) -> Glib::RefPtr<TabPage>
  {
    auto retvalue =
        Glib::wrap (adw_tab_view_insert (gobj (),
                                         (GtkWidget*) Glib::unwrap (child),
                                         position));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::insert_pinned (Gtk::Widget* child, int position) -> Glib::RefPtr<TabPage>
  {
    auto retvalue = Glib::wrap (
        adw_tab_view_insert_pinned (gobj (),
                                    (GtkWidget*) Glib::unwrap (child),
                                    position));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::prepend (Gtk::Widget* child) -> Glib::RefPtr<TabPage>
  {
    auto retvalue = Glib::wrap (
        adw_tab_view_prepend (gobj (), (GtkWidget*) Glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabView::prepend_pinned (Gtk::Widget* child) -> Glib::RefPtr<TabPage>
  {
    auto retvalue = Glib::wrap (
        adw_tab_view_prepend_pinned (gobj (),
                                     (GtkWidget*) Glib::unwrap (child)));
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
  TabView::reorder_backward (const Glib::RefPtr<TabPage>& page) -> bool
  {
    return adw_tab_view_reorder_backward (gobj (), Glib::unwrap (page));
  }

  auto
  TabView::reorder_first (const Glib::RefPtr<TabPage>& page) -> bool
  {
    return adw_tab_view_reorder_first (gobj (), Glib::unwrap (page));
  }

  auto
  TabView::reorder_forward (const Glib::RefPtr<TabPage>& page) -> bool
  {
    return adw_tab_view_reorder_forward (gobj (), Glib::unwrap (page));
  }

  auto
  TabView::reorder_last (const Glib::RefPtr<TabPage>& page) -> bool
  {
    return adw_tab_view_reorder_last (gobj (), Glib::unwrap (page));
  }

  auto
  TabView::reorder_page (const Glib::RefPtr<TabPage>& page, int position) -> bool
  {
    return adw_tab_view_reorder_page (gobj (), Glib::unwrap (page), position);
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
  TabView::set_default_icon (const Glib::RefPtr<Gio::Icon>& default_icon) -> void
  {
    adw_tab_view_set_default_icon (
        gobj (),
        const_cast<GIcon*> (Glib::unwrap<Gio::Icon> (default_icon)));
  }

  auto
  TabView::set_menu_model (const Glib::RefPtr<Gio::MenuModel>& menu_model) -> void
  {
    adw_tab_view_set_menu_model (gobj (), Glib::unwrap (menu_model));
  }

  auto
  TabView::set_page_pinned (const Glib::RefPtr<TabPage>& page, bool pinned) -> void
  {
    adw_tab_view_set_page_pinned (gobj (),
                                  Glib::unwrap (page),
                                  static_cast<int> (pinned));
  }

  auto
  TabView::set_selected_page (const Glib::RefPtr<TabPage>& selected_page) -> void
  {
    adw_tab_view_set_selected_page (gobj (), Glib::unwrap (selected_page));
  }

  auto
  TabView::set_shortcuts (TabViewShortcuts shortcuts) -> void
  {
    adw_tab_view_set_shortcuts (gobj (),
                                static_cast<AdwTabViewShortcuts> (shortcuts));
  }

  auto
  TabView::transfer_page (const Glib::RefPtr<TabPage>& page,
                          TabView* other_view,
                          int position) -> void
  {
    adw_tab_view_transfer_page (gobj (),
                                Glib::unwrap (page),
                                (AdwTabView*) Glib::unwrap (other_view),
                                position);
  }

  auto
  TabView::signal_close_page () -> Glib::SignalProxy<bool (const Glib::RefPtr<TabPage>&)>
  {
    return Glib::SignalProxy<bool (const Glib::RefPtr<TabPage>&)> (
        this,
        &TabView_signal_close_page_info);
  }

  auto
  TabView::signal_create_window () -> Glib::SignalProxy<TabView*()>
  {
    return Glib::SignalProxy<TabView*()> (this,
                                          &TabView_signal_create_window_info);
  }

  auto
  TabView::signal_indicator_activated () -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&)> (
        this,
        &TabView_signal_indicator_activated_info);
  }

  auto
  TabView::signal_page_attached () -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&, int)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&, int)> (
        this,
        &TabView_signal_page_attached_info);
  }

  auto
  TabView::signal_page_detached () -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&, int)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&, int)> (
        this,
        &TabView_signal_page_detached_info);
  }

  auto
  TabView::signal_page_reordered () -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&, int)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&, int)> (
        this,
        &TabView_signal_page_reordered_info);
  }

  auto
  TabView::signal_setup_menu () -> Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<TabPage>&)> (
        this,
        &TabView_signal_setup_menu_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::Icon>>::value,
      "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TabView::property_default_icon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>> (this, "default-icon");
  }

  auto
  TabView::property_default_icon () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>> (
        this,
        "default-icon");
  }

  auto
  TabView::property_is_transferring_page () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "is-transferring-page");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TabView::property_menu_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>> (this,
                                                              "menu-model");
  }

  auto
  TabView::property_menu_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>> (
        this,
        "menu-model");
  }

  auto
  TabView::property_n_pages () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "n-pages");
  }

  auto
  TabView::property_n_pinned_pages () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "n-pinned-pages");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gtk::SelectionModel>>::value,
      "Type Glib::RefPtr<Gtk::SelectionModel> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TabView::property_pages () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>> (
        this,
        "pages");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TabPage>>::value,
      "Type Glib::RefPtr<TabPage> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TabView::property_selected_page () -> Glib::PropertyProxy<Glib::RefPtr<TabPage>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<TabPage>> (this, "selected-page");
  }

  auto
  TabView::property_selected_page () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TabPage>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TabPage>> (
        this,
        "selected-page");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<TabViewShortcuts>::value,
      "Type TabViewShortcuts cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TabView::property_shortcuts () -> Glib::PropertyProxy<TabViewShortcuts>
  {
    return Glib::PropertyProxy<TabViewShortcuts> (this, "shortcuts");
  }

  auto
  TabView::property_shortcuts () const -> Glib::PropertyProxy_ReadOnly<TabViewShortcuts>
  {
    return Glib::PropertyProxy_ReadOnly<TabViewShortcuts> (this, "shortcuts");
  }

} // namespace Adw
