// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/notebook.hxx>
#include <libmm/gtk/notebook_p.hxx>

#include <gtk/gtk.h>

#include <algorithm>
#include <gtk/gtk.h>
#include <libmm/gtk/label.hxx>

namespace gtk
{

  auto
  Notebook::prepend_page (Widget& child,
                          const glib::ustring& tab_label,
                          bool use_mnemonic) -> int
  {
    auto pLabel = gtk::manage (new Label (tab_label, use_mnemonic));
    return prepend_page (child, *pLabel);
  }

  auto
  Notebook::prepend_page (Widget& child,
                          const glib::ustring& tab_label,
                          const glib::ustring& menu_label,
                          bool use_mnemonic) -> int
  {
    auto pLabel = gtk::manage (new Label (tab_label, use_mnemonic));
    auto pLabelMenu = gtk::manage (new Label (menu_label, use_mnemonic));
    return prepend_page (child, *pLabel, *pLabelMenu);
  }

  auto
  Notebook::append_page (Widget& child,
                         const glib::ustring& tab_label,
                         bool use_mnemonic) -> int
  {
    auto pLabel = gtk::manage (new Label (tab_label, use_mnemonic));
    return append_page (child, *pLabel);
  }

  auto
  Notebook::append_page (Widget& child,
                         const glib::ustring& tab_label,
                         const glib::ustring& menu_label,
                         bool use_mnemonic) -> int
  {
    auto pLabel = gtk::manage (new Label (tab_label, use_mnemonic));
    auto pLabelMenu = gtk::manage (new Label (menu_label, use_mnemonic));
    return append_page (child, *pLabel, *pLabelMenu);
  }

  auto
  Notebook::insert_page (Widget& child,
                         const glib::ustring& tab_label,
                         int position,
                         bool use_mnemonic) -> int
  {
    auto pLabel = gtk::manage (new Label (tab_label, use_mnemonic));
    return insert_page (child, *pLabel, position);
  }

  auto
  Notebook::insert_page (Widget& child,
                         const glib::ustring& tab_label,
                         const glib::ustring& menu_label,
                         int position,
                         bool use_mnemonic) -> int
  {
    auto pLabel = gtk::manage (new Label (tab_label, use_mnemonic));
    auto pLabelMenu = gtk::manage (new Label (menu_label, use_mnemonic));
    return insert_page (child, *pLabel, *pLabelMenu, position);
  }

  auto
  Notebook::remove_page (Widget& child) -> void
  {
    int pos = page_num (child);
    if (pos != -1)
      remove_page (pos);
  }

  auto
  Notebook::prepend_page (Widget& child) -> int
  {
    return gtk_notebook_prepend_page (gobj (), child.gobj (), nullptr);
  }

  auto
  Notebook::append_page (Widget& child) -> int
  {
    return gtk_notebook_append_page (gobj (), child.gobj (), nullptr);
  }

  auto
  Notebook::insert_page (Widget& child, int position) -> int
  {
    return gtk_notebook_insert_page (gobj (), child.gobj (), nullptr, position);
  }

} // namespace gtk

namespace
{

  static auto
  Notebook_signal_switch_page_callback (GtkNotebook* self,
                                        GtkWidget* p0,
                                        guint p1,
                                        void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Widget*, guint)>;

    auto obj = dynamic_cast<Notebook*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0), p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Notebook_signal_switch_page_info = {
      "switch_page",
      (GCallback) &Notebook_signal_switch_page_callback,
      (GCallback) &Notebook_signal_switch_page_callback};

  static auto
  Notebook_signal_page_reordered_callback (GtkNotebook* self,
                                           GtkWidget* p0,
                                           guint p1,
                                           void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Widget*, guint)>;

    auto obj = dynamic_cast<Notebook*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0), p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Notebook_signal_page_reordered_info = {
      "page_reordered",
      (GCallback) &Notebook_signal_page_reordered_callback,
      (GCallback) &Notebook_signal_page_reordered_callback};

  static auto
  Notebook_signal_page_removed_callback (GtkNotebook* self,
                                         GtkWidget* p0,
                                         guint p1,
                                         void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Widget*, guint)>;

    auto obj = dynamic_cast<Notebook*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0), p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Notebook_signal_page_removed_info = {
      "page_removed",
      (GCallback) &Notebook_signal_page_removed_callback,
      (GCallback) &Notebook_signal_page_removed_callback};

  static auto
  Notebook_signal_page_added_callback (GtkNotebook* self,
                                       GtkWidget* p0,
                                       guint p1,
                                       void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Widget*, guint)>;

    auto obj = dynamic_cast<Notebook*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0), p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Notebook_signal_page_added_info = {
      "page_added",
      (GCallback) &Notebook_signal_page_added_callback,
      (GCallback) &Notebook_signal_page_added_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkNotebook* object, bool take_copy) -> gtk::Notebook*
  {
    return dynamic_cast<gtk::Notebook*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Notebook_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Notebook_Class::class_init_function;

      register_derived_type (gtk_notebook_get_type ());
    }

    return *this;
  }

  auto
  Notebook_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Notebook_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Notebook ((GtkNotebook*) (o)));
  }

  Notebook::Notebook (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Notebook::Notebook (GtkNotebook* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Notebook::Notebook (Notebook&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Notebook::operator= (Notebook&& src) noexcept -> Notebook&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Notebook::~Notebook () noexcept
  {
    destroy_ ();
  }

  Notebook::CppClassType Notebook::notebook_class_;

  auto
  Notebook::get_type () -> GType
  {
    return notebook_class_.init ().get_type ();
  }

  auto
  Notebook::get_base_type () -> GType
  {
    return gtk_notebook_get_type ();
  }

  Notebook::Notebook ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (notebook_class_.init ()))
  {
  }

  auto
  Notebook::prepend_page (Widget& child, Widget& tab_label) -> int
  {
    return gtk_notebook_prepend_page (gobj (),
                                      (child).gobj (),
                                      (tab_label).gobj ());
  }

  auto
  Notebook::prepend_page (Widget& child, Widget& tab_label, Widget& menu_label) -> int
  {
    return gtk_notebook_prepend_page_menu (gobj (),
                                           (child).gobj (),
                                           (tab_label).gobj (),
                                           (menu_label).gobj ());
  }

  auto
  Notebook::append_page (Widget& child, Widget& tab_label) -> int
  {
    return gtk_notebook_append_page (gobj (),
                                     (child).gobj (),
                                     (tab_label).gobj ());
  }

  auto
  Notebook::append_page (Widget& child, Widget& tab_label, Widget& menu_label) -> int
  {
    return gtk_notebook_append_page_menu (gobj (),
                                          (child).gobj (),
                                          (tab_label).gobj (),
                                          (menu_label).gobj ());
  }

  auto
  Notebook::insert_page (Widget& child, Widget& tab_label, int position) -> int
  {
    return gtk_notebook_insert_page (gobj (),
                                     (child).gobj (),
                                     (tab_label).gobj (),
                                     position);
  }

  auto
  Notebook::insert_page (Widget& child,
                         Widget& tab_label,
                         Widget& menu_label,
                         int position) -> int
  {
    return gtk_notebook_insert_page_menu (gobj (),
                                          (child).gobj (),
                                          (tab_label).gobj (),
                                          (menu_label).gobj (),
                                          position);
  }

  auto
  Notebook::remove_page (int page_number) -> void
  {
    gtk_notebook_remove_page (gobj (), page_number);
  }

  auto
  Notebook::set_group_name (const glib::ustring& group_name) -> void
  {
    gtk_notebook_set_group_name (gobj (), group_name.c_str ());
  }

  auto
  Notebook::get_group_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_notebook_get_group_name (const_cast<GtkNotebook*> (gobj ())));
  }

  auto
  Notebook::get_current_page () const -> int
  {
    return gtk_notebook_get_current_page (const_cast<GtkNotebook*> (gobj ()));
  }

  auto
  Notebook::get_nth_page (int page_number) -> Widget*
  {
    return glib::wrap (gtk_notebook_get_nth_page (gobj (), page_number));
  }

  auto
  Notebook::get_nth_page (int page_number) const -> const Widget*
  {
    return const_cast<Notebook*> (this)->get_nth_page (page_number);
  }

  auto
  Notebook::get_n_pages () const -> int
  {
    return gtk_notebook_get_n_pages (const_cast<GtkNotebook*> (gobj ()));
  }

  auto
  Notebook::page_num (const Widget& child) const -> int
  {
    return gtk_notebook_page_num (const_cast<GtkNotebook*> (gobj ()),
                                  const_cast<GtkWidget*> ((child).gobj ()));
  }

  auto
  Notebook::set_current_page (int page_number) -> void
  {
    gtk_notebook_set_current_page (gobj (), page_number);
  }

  auto
  Notebook::next_page () -> void
  {
    gtk_notebook_next_page (gobj ());
  }

  auto
  Notebook::prev_page () -> void
  {
    gtk_notebook_prev_page (gobj ());
  }

  auto
  Notebook::set_show_border (bool show_border) -> void
  {
    gtk_notebook_set_show_border (gobj (), static_cast<int> (show_border));
  }

  auto
  Notebook::get_show_border () const -> bool
  {
    return gtk_notebook_get_show_border (const_cast<GtkNotebook*> (gobj ()));
  }

  auto
  Notebook::set_show_tabs (bool show_tabs) -> void
  {
    gtk_notebook_set_show_tabs (gobj (), static_cast<int> (show_tabs));
  }

  auto
  Notebook::get_show_tabs () const -> bool
  {
    return gtk_notebook_get_show_tabs (const_cast<GtkNotebook*> (gobj ()));
  }

  auto
  Notebook::set_tab_pos (PositionType pos) -> void
  {
    gtk_notebook_set_tab_pos (gobj (), static_cast<GtkPositionType> (pos));
  }

  auto
  Notebook::get_tab_pos () const -> PositionType
  {
    return static_cast<PositionType> (
        gtk_notebook_get_tab_pos (const_cast<GtkNotebook*> (gobj ())));
  }

  auto
  Notebook::set_scrollable (bool scrollable) -> void
  {
    gtk_notebook_set_scrollable (gobj (), static_cast<int> (scrollable));
  }

  auto
  Notebook::get_scrollable () const -> bool
  {
    return gtk_notebook_get_scrollable (const_cast<GtkNotebook*> (gobj ()));
  }

  auto
  Notebook::popup_enable () -> void
  {
    gtk_notebook_popup_enable (gobj ());
  }

  auto
  Notebook::popup_disable () -> void
  {
    gtk_notebook_popup_disable (gobj ());
  }

  auto
  Notebook::get_tab_label (Widget& child) -> Widget*
  {
    return glib::wrap (gtk_notebook_get_tab_label (gobj (), (child).gobj ()));
  }

  auto
  Notebook::get_tab_label (Widget& child) const -> const Widget*
  {
    return const_cast<Notebook*> (this)->get_tab_label (child);
  }

  auto
  Notebook::set_tab_label (Widget& child, Widget& tab_label) -> void
  {
    gtk_notebook_set_tab_label (gobj (), (child).gobj (), (tab_label).gobj ());
  }

  auto
  Notebook::set_tab_label_text (Widget& child, const glib::ustring& tab_text) -> void
  {
    gtk_notebook_set_tab_label_text (gobj (),
                                     (child).gobj (),
                                     tab_text.c_str ());
  }

  auto
  Notebook::get_tab_label_text (Widget& child) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_notebook_get_tab_label_text (const_cast<GtkNotebook*> (gobj ()),
                                         (child).gobj ()));
  }

  auto
  Notebook::get_menu_label (Widget& child) -> Widget*
  {
    return glib::wrap (gtk_notebook_get_menu_label (gobj (), (child).gobj ()));
  }

  auto
  Notebook::get_menu_label (Widget& child) const -> const Widget*
  {
    return const_cast<Notebook*> (this)->get_menu_label (child);
  }

  auto
  Notebook::set_menu_label (Widget& child, Widget& menu_label) -> void
  {
    gtk_notebook_set_menu_label (gobj (),
                                 (child).gobj (),
                                 (menu_label).gobj ());
  }

  auto
  Notebook::set_menu_label_text (Widget& child, const glib::ustring& menu_text) -> void
  {
    gtk_notebook_set_menu_label_text (gobj (),
                                      (child).gobj (),
                                      menu_text.c_str ());
  }

  auto
  Notebook::get_menu_label_text (Widget& child) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_notebook_get_menu_label_text (const_cast<GtkNotebook*> (gobj ()),
                                          (child).gobj ()));
  }

  auto
  Notebook::reorder_child (Widget& child, int position) -> void
  {
    gtk_notebook_reorder_child (gobj (), (child).gobj (), position);
  }

  auto
  Notebook::get_tab_reorderable (Widget& child) const -> bool
  {
    return gtk_notebook_get_tab_reorderable (const_cast<GtkNotebook*> (gobj ()),
                                             (child).gobj ());
  }

  auto
  Notebook::set_tab_reorderable (Widget& child, bool reorderable) -> void
  {
    gtk_notebook_set_tab_reorderable (gobj (),
                                      (child).gobj (),
                                      static_cast<int> (reorderable));
  }

  auto
  Notebook::get_tab_detachable (Widget& child) const -> bool
  {
    return gtk_notebook_get_tab_detachable (const_cast<GtkNotebook*> (gobj ()),
                                            (child).gobj ());
  }

  auto
  Notebook::set_tab_detachable (Widget& child, bool detachable) -> void
  {
    gtk_notebook_set_tab_detachable (gobj (),
                                     (child).gobj (),
                                     static_cast<int> (detachable));
  }

  auto
  Notebook::detach_tab (Widget& child) -> void
  {
    gtk_notebook_detach_tab (gobj (), (child).gobj ());
  }

  auto
  Notebook::get_action_widget (PackType pack_type) -> Widget*
  {
    return glib::wrap (
        gtk_notebook_get_action_widget (gobj (),
                                        static_cast<GtkPackType> (pack_type)));
  }

  auto
  Notebook::set_action_widget (Widget* widget, PackType pack_type) -> void
  {
    gtk_notebook_set_action_widget (gobj (),
                                    (GtkWidget*) glib::unwrap (widget),
                                    static_cast<GtkPackType> (pack_type));
  }

  auto
  Notebook::get_page (Widget& child) -> glib::RefPtr<NotebookPage>
  {
    auto retvalue =
        glib::wrap (gtk_notebook_get_page (gobj (), (child).gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Notebook::get_page (const Widget& child) const -> glib::RefPtr<const NotebookPage>
  {
    auto retvalue = glib::wrap (
        gtk_notebook_get_page (const_cast<GtkNotebook*> (gobj ()),
                               const_cast<GtkWidget*> ((child).gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Notebook::get_pages () -> glib::RefPtr<gio::ListModel>
  {
    return glib::wrap (gtk_notebook_get_pages (gobj ()));
  }

  auto
  Notebook::get_pages () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<Notebook*> (this)->get_pages ();
  }

  auto
  Notebook::signal_switch_page () -> glib::SignalProxy<void (Widget*, guint)>
  {
    return glib::SignalProxy<void (Widget*, guint)> (
        this,
        &Notebook_signal_switch_page_info);
  }

  auto
  Notebook::signal_page_reordered () -> glib::SignalProxy<void (Widget*, guint)>
  {
    return glib::SignalProxy<void (Widget*, guint)> (
        this,
        &Notebook_signal_page_reordered_info);
  }

  auto
  Notebook::signal_page_removed () -> glib::SignalProxy<void (Widget*, guint)>
  {
    return glib::SignalProxy<void (Widget*, guint)> (
        this,
        &Notebook_signal_page_removed_info);
  }

  auto
  Notebook::signal_page_added () -> glib::SignalProxy<void (Widget*, guint)>
  {
    return glib::SignalProxy<void (Widget*, guint)> (
        this,
        &Notebook_signal_page_added_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<PositionType>::value,
      "Type PositionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Notebook::property_tab_pos () -> glib::PropertyProxy<PositionType>
  {
    return glib::PropertyProxy<PositionType> (this, "tab-pos");
  }

  auto
  Notebook::property_tab_pos () const -> glib::PropertyProxy_ReadOnly<PositionType>
  {
    return glib::PropertyProxy_ReadOnly<PositionType> (this, "tab-pos");
  }

  auto
  Notebook::property_show_tabs () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-tabs");
  }

  auto
  Notebook::property_show_tabs () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-tabs");
  }

  auto
  Notebook::property_show_border () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-border");
  }

  auto
  Notebook::property_show_border () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-border");
  }

  auto
  Notebook::property_scrollable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "scrollable");
  }

  auto
  Notebook::property_scrollable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "scrollable");
  }

  auto
  Notebook::property_page () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "page");
  }

  auto
  Notebook::property_page () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "page");
  }

  auto
  Notebook::property_group_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "group-name");
  }

  auto
  Notebook::property_group_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "group-name");
  }

  auto
  Notebook::property_enable_popup () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "enable-popup");
  }

  auto
  Notebook::property_enable_popup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "enable-popup");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Notebook::property_pages () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "pages");
  }

} // namespace gtk
