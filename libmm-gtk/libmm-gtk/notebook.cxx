// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/notebook.hxx>
#include <libmm-gtk/notebook_p.hxx>

#include <gtk/gtk.h>

#include <algorithm>
#include <gtk/gtk.h>
#include <libmm-gtk/label.hxx>

namespace Gtk
{

  auto
  Notebook::prepend_page (Widget& child,
                          const Glib::ustring& tab_label,
                          bool use_mnemonic) -> int
  {
    auto pLabel = Gtk::manage (new Label (tab_label, use_mnemonic));
    return prepend_page (child, *pLabel);
  }

  auto
  Notebook::prepend_page (Widget& child,
                          const Glib::ustring& tab_label,
                          const Glib::ustring& menu_label,
                          bool use_mnemonic) -> int
  {
    auto pLabel = Gtk::manage (new Label (tab_label, use_mnemonic));
    auto pLabelMenu = Gtk::manage (new Label (menu_label, use_mnemonic));
    return prepend_page (child, *pLabel, *pLabelMenu);
  }

  auto
  Notebook::append_page (Widget& child,
                         const Glib::ustring& tab_label,
                         bool use_mnemonic) -> int
  {
    auto pLabel = Gtk::manage (new Label (tab_label, use_mnemonic));
    return append_page (child, *pLabel);
  }

  auto
  Notebook::append_page (Widget& child,
                         const Glib::ustring& tab_label,
                         const Glib::ustring& menu_label,
                         bool use_mnemonic) -> int
  {
    auto pLabel = Gtk::manage (new Label (tab_label, use_mnemonic));
    auto pLabelMenu = Gtk::manage (new Label (menu_label, use_mnemonic));
    return append_page (child, *pLabel, *pLabelMenu);
  }

  auto
  Notebook::insert_page (Widget& child,
                         const Glib::ustring& tab_label,
                         int position,
                         bool use_mnemonic) -> int
  {
    auto pLabel = Gtk::manage (new Label (tab_label, use_mnemonic));
    return insert_page (child, *pLabel, position);
  }

  auto
  Notebook::insert_page (Widget& child,
                         const Glib::ustring& tab_label,
                         const Glib::ustring& menu_label,
                         int position,
                         bool use_mnemonic) -> int
  {
    auto pLabel = Gtk::manage (new Label (tab_label, use_mnemonic));
    auto pLabelMenu = Gtk::manage (new Label (menu_label, use_mnemonic));
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

} // namespace Gtk

namespace
{

  static auto
  Notebook_signal_switch_page_callback (GtkNotebook* self,
                                        GtkWidget* p0,
                                        guint p1,
                                        void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Widget*, guint)>;

    auto obj = dynamic_cast<Notebook*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Notebook_signal_switch_page_info = {
      "switch_page",
      (GCallback) &Notebook_signal_switch_page_callback,
      (GCallback) &Notebook_signal_switch_page_callback};

  static auto
  Notebook_signal_page_reordered_callback (GtkNotebook* self,
                                           GtkWidget* p0,
                                           guint p1,
                                           void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Widget*, guint)>;

    auto obj = dynamic_cast<Notebook*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Notebook_signal_page_reordered_info = {
      "page_reordered",
      (GCallback) &Notebook_signal_page_reordered_callback,
      (GCallback) &Notebook_signal_page_reordered_callback};

  static auto
  Notebook_signal_page_removed_callback (GtkNotebook* self,
                                         GtkWidget* p0,
                                         guint p1,
                                         void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Widget*, guint)>;

    auto obj = dynamic_cast<Notebook*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Notebook_signal_page_removed_info = {
      "page_removed",
      (GCallback) &Notebook_signal_page_removed_callback,
      (GCallback) &Notebook_signal_page_removed_callback};

  static auto
  Notebook_signal_page_added_callback (GtkNotebook* self,
                                       GtkWidget* p0,
                                       guint p1,
                                       void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Widget*, guint)>;

    auto obj = dynamic_cast<Notebook*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Notebook_signal_page_added_info = {
      "page_added",
      (GCallback) &Notebook_signal_page_added_callback,
      (GCallback) &Notebook_signal_page_added_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkNotebook* object, bool take_copy) -> Gtk::Notebook*
  {
    return dynamic_cast<Gtk::Notebook*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Notebook_Class::init () -> const Glib::Class&
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
  Notebook_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Notebook ((GtkNotebook*) (o)));
  }

  Notebook::Notebook (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Notebook::Notebook (GtkNotebook* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Notebook::Notebook (Notebook&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  Notebook::operator= (Notebook&& src) noexcept -> Notebook&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (notebook_class_.init ()))
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
  Notebook::set_group_name (const Glib::ustring& group_name) -> void
  {
    gtk_notebook_set_group_name (gobj (), group_name.c_str ());
  }

  auto
  Notebook::get_group_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
    return Glib::wrap (gtk_notebook_get_nth_page (gobj (), page_number));
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
    return Glib::wrap (gtk_notebook_get_tab_label (gobj (), (child).gobj ()));
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
  Notebook::set_tab_label_text (Widget& child, const Glib::ustring& tab_text) -> void
  {
    gtk_notebook_set_tab_label_text (gobj (),
                                     (child).gobj (),
                                     tab_text.c_str ());
  }

  auto
  Notebook::get_tab_label_text (Widget& child) const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_notebook_get_tab_label_text (const_cast<GtkNotebook*> (gobj ()),
                                         (child).gobj ()));
  }

  auto
  Notebook::get_menu_label (Widget& child) -> Widget*
  {
    return Glib::wrap (gtk_notebook_get_menu_label (gobj (), (child).gobj ()));
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
  Notebook::set_menu_label_text (Widget& child, const Glib::ustring& menu_text) -> void
  {
    gtk_notebook_set_menu_label_text (gobj (),
                                      (child).gobj (),
                                      menu_text.c_str ());
  }

  auto
  Notebook::get_menu_label_text (Widget& child) const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
    return Glib::wrap (
        gtk_notebook_get_action_widget (gobj (),
                                        static_cast<GtkPackType> (pack_type)));
  }

  auto
  Notebook::set_action_widget (Widget* widget, PackType pack_type) -> void
  {
    gtk_notebook_set_action_widget (gobj (),
                                    (GtkWidget*) Glib::unwrap (widget),
                                    static_cast<GtkPackType> (pack_type));
  }

  auto
  Notebook::get_page (Widget& child) -> Glib::RefPtr<NotebookPage>
  {
    auto retvalue =
        Glib::wrap (gtk_notebook_get_page (gobj (), (child).gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Notebook::get_page (const Widget& child) const -> Glib::RefPtr<const NotebookPage>
  {
    auto retvalue = Glib::wrap (
        gtk_notebook_get_page (const_cast<GtkNotebook*> (gobj ()),
                               const_cast<GtkWidget*> ((child).gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Notebook::get_pages () -> Glib::RefPtr<Gio::ListModel>
  {
    return Glib::wrap (gtk_notebook_get_pages (gobj ()));
  }

  auto
  Notebook::get_pages () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return const_cast<Notebook*> (this)->get_pages ();
  }

  auto
  Notebook::signal_switch_page () -> Glib::SignalProxy<void (Widget*, guint)>
  {
    return Glib::SignalProxy<void (Widget*, guint)> (
        this,
        &Notebook_signal_switch_page_info);
  }

  auto
  Notebook::signal_page_reordered () -> Glib::SignalProxy<void (Widget*, guint)>
  {
    return Glib::SignalProxy<void (Widget*, guint)> (
        this,
        &Notebook_signal_page_reordered_info);
  }

  auto
  Notebook::signal_page_removed () -> Glib::SignalProxy<void (Widget*, guint)>
  {
    return Glib::SignalProxy<void (Widget*, guint)> (
        this,
        &Notebook_signal_page_removed_info);
  }

  auto
  Notebook::signal_page_added () -> Glib::SignalProxy<void (Widget*, guint)>
  {
    return Glib::SignalProxy<void (Widget*, guint)> (
        this,
        &Notebook_signal_page_added_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<PositionType>::value,
      "Type PositionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Notebook::property_tab_pos () -> Glib::PropertyProxy<PositionType>
  {
    return Glib::PropertyProxy<PositionType> (this, "tab-pos");
  }

  auto
  Notebook::property_tab_pos () const -> Glib::PropertyProxy_ReadOnly<PositionType>
  {
    return Glib::PropertyProxy_ReadOnly<PositionType> (this, "tab-pos");
  }

  auto
  Notebook::property_show_tabs () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-tabs");
  }

  auto
  Notebook::property_show_tabs () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-tabs");
  }

  auto
  Notebook::property_show_border () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-border");
  }

  auto
  Notebook::property_show_border () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-border");
  }

  auto
  Notebook::property_scrollable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "scrollable");
  }

  auto
  Notebook::property_scrollable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "scrollable");
  }

  auto
  Notebook::property_page () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "page");
  }

  auto
  Notebook::property_page () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "page");
  }

  auto
  Notebook::property_group_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "group-name");
  }

  auto
  Notebook::property_group_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "group-name");
  }

  auto
  Notebook::property_enable_popup () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enable-popup");
  }

  auto
  Notebook::property_enable_popup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enable-popup");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Notebook::property_pages () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (this,
                                                                       "pages");
  }

} // namespace Gtk
