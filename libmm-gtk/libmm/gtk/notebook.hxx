// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NOTEBOOK_H
#define _GTKMM_NOTEBOOK_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/label.hxx>
#include <libmm/gtk/notebookpage.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNotebook = struct _GtkNotebook;
using GtkNotebookClass = struct _GtkNotebookClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Notebook_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Notebook : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Notebook CppObjectType;
    typedef Notebook_Class CppClassType;
    typedef GtkNotebook BaseObjectType;
    typedef GtkNotebookClass BaseClassType;
#endif

    Notebook (Notebook&& src) noexcept;
    auto
    operator= (Notebook&& src) noexcept -> Notebook&;

    Notebook (const Notebook&) = delete;
    auto
    operator= (const Notebook&) -> Notebook& = delete;

    ~Notebook () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Notebook_Class;
    static CppClassType notebook_class_;

  protected:
    explicit Notebook (const Glib::ConstructParams& construct_params);
    explicit Notebook (GtkNotebook* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkNotebook*
    {
      return reinterpret_cast<GtkNotebook*> (gobject_);
    }

    auto
    gobj () const -> const GtkNotebook*
    {
      return reinterpret_cast<GtkNotebook*> (gobject_);
    }

  private:
  public:
    Notebook ();

    auto
    prepend_page (Widget& child, Widget& tab_label) -> int;
    auto
    prepend_page (Widget& child) -> int;

    auto
    prepend_page (Widget& child,
                  const Glib::ustring& tab_label,
                  bool use_mnemonic = false) -> int;

    auto
    prepend_page (Widget& child, Widget& tab_label, Widget& menu_label) -> int;

    auto
    prepend_page (Widget& child,
                  const Glib::ustring& tab_label,
                  const Glib::ustring& menu_label,
                  bool use_mnemonic) -> int;

    auto
    append_page (Widget& child, Widget& tab_label) -> int;
    auto
    append_page (Widget& child) -> int;
    auto
    append_page (Widget& child,
                 const Glib::ustring& tab_label,
                 bool use_mnemonic = false) -> int;

    auto
    append_page (Widget& child, Widget& tab_label, Widget& menu_label) -> int;

    auto
    append_page (Widget& child,
                 const Glib::ustring& tab_label,
                 const Glib::ustring& menu_label,
                 bool use_mnemonic = false) -> int;

    auto
    insert_page (Widget& child, Widget& tab_label, int position) -> int;
    auto
    insert_page (Widget& child, int position) -> int;

    auto
    insert_page (Widget& child,
                 const Glib::ustring& tab_label,
                 int position,
                 bool use_mnemonic = false) -> int;

    auto
    insert_page (Widget& child,
                 Widget& tab_label,
                 Widget& menu_label,
                 int position) -> int;

    auto
    insert_page (Widget& child,
                 const Glib::ustring& tab_label,
                 const Glib::ustring& menu_label,
                 int position,
                 bool use_mnemonic = false) -> int;

    auto
    remove_page (int page_number = 0) -> void;
    auto
    remove_page (Widget& child) -> void;

    auto
    set_group_name (const Glib::ustring& group_name) -> void;

    auto
    get_group_name () const -> Glib::ustring;

    auto
    get_current_page () const -> int;

    auto
    get_nth_page (int page_number) -> Widget*;

    auto
    get_nth_page (int page_number) const -> const Widget*;

    auto
    get_n_pages () const -> int;

    auto
    page_num (const Widget& child) const -> int;

    auto
    set_current_page (int page_number) -> void;

    auto
    next_page () -> void;

    auto
    prev_page () -> void;

    auto
    set_show_border (bool show_border = true) -> void;

    auto
    get_show_border () const -> bool;

    auto
    set_show_tabs (bool show_tabs = true) -> void;

    auto
    get_show_tabs () const -> bool;

    auto
    set_tab_pos (PositionType pos) -> void;

    auto
    get_tab_pos () const -> PositionType;

    auto
    set_scrollable (bool scrollable = true) -> void;

    auto
    get_scrollable () const -> bool;

    auto
    popup_enable () -> void;

    auto
    popup_disable () -> void;

    auto
    get_tab_label (Widget& child) -> Widget*;

    auto
    get_tab_label (Widget& child) const -> const Widget*;

    auto
    set_tab_label (Widget& child, Widget& tab_label) -> void;

    auto
    set_tab_label_text (Widget& child, const Glib::ustring& tab_text) -> void;

    auto
    get_tab_label_text (Widget& child) const -> Glib::ustring;

    auto
    get_menu_label (Widget& child) -> Widget*;

    auto
    get_menu_label (Widget& child) const -> const Widget*;

    auto
    set_menu_label (Widget& child, Widget& menu_label) -> void;

    auto
    set_menu_label_text (Widget& child, const Glib::ustring& menu_text) -> void;

    auto
    get_menu_label_text (Widget& child) const -> Glib::ustring;

    auto
    reorder_child (Widget& child, int position) -> void;

    auto
    get_tab_reorderable (Widget& child) const -> bool;

    auto
    set_tab_reorderable (Widget& child, bool reorderable = true) -> void;

    auto
    get_tab_detachable (Widget& child) const -> bool;

    auto
    set_tab_detachable (Widget& child, bool detachable = true) -> void;

    auto
    detach_tab (Widget& child) -> void;

    auto
    get_action_widget (PackType pack_type = PackType::START) -> Widget*;

    auto
    set_action_widget (Widget* widget, PackType pack_type = PackType::START)
        -> void;

    auto
    get_page (Widget& child) -> Glib::RefPtr<NotebookPage>;

    auto
    get_page (const Widget& child) const -> Glib::RefPtr<const NotebookPage>;

    auto
    get_pages () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_pages () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    signal_switch_page () -> Glib::SignalProxy<void (Widget*, guint)>;

    auto
    signal_page_reordered () -> Glib::SignalProxy<void (Widget*, guint)>;

    auto
    signal_page_removed () -> Glib::SignalProxy<void (Widget*, guint)>;

    auto
    signal_page_added () -> Glib::SignalProxy<void (Widget*, guint)>;

    auto
    property_tab_pos () -> Glib::PropertyProxy<PositionType>;

    auto
    property_tab_pos () const -> Glib::PropertyProxy_ReadOnly<PositionType>;

    auto
    property_show_tabs () -> Glib::PropertyProxy<bool>;

    auto
    property_show_tabs () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_border () -> Glib::PropertyProxy<bool>;

    auto
    property_show_border () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_scrollable () -> Glib::PropertyProxy<bool>;

    auto
    property_scrollable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_page () -> Glib::PropertyProxy<int>;

    auto
    property_page () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_group_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_group_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_enable_popup () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_popup () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pages () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkNotebook* object, bool take_copy = false) -> Gtk::Notebook*;
} // namespace Glib

#endif