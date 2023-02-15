// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LISTVIEW_TEXT_H
#define _GTKMM_LISTVIEW_TEXT_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-gtk/liststore.hxx>
  #include <libmm-gtk/treeview.hxx>

  #include <vector>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ListViewText : public Gtk::TreeView
  {
  public:
    ListViewText (guint columns_count,
                  bool editable = false,
                  Gtk::SelectionMode mode = Gtk::SelectionMode::SINGLE);
    ~ListViewText () noexcept override;

    auto
    set_column_title (guint column, const Glib::ustring& title) -> void;

    auto
    get_column_title (guint column) const -> Glib::ustring;

    auto
    append (const Glib::ustring& column_one_value = {}) -> guint;

    auto
    prepend (const Glib::ustring& column_one_value = {}) -> void;

    auto
    insert (guint row, const Glib::ustring& column_one_value = {}) -> void;

    auto
    clear_items () -> void;

    auto
    get_text (guint row, guint column = 0) const -> Glib::ustring;

    auto
    set_text (guint row, guint column, const Glib::ustring& value) -> void;

    auto
    set_text (guint row, const Glib::ustring& value) -> void;

    auto
    size () const -> guint;

    auto
    get_num_columns () const -> guint;

    typedef std::vector<int> SelectionList;

    auto
    get_selected () -> SelectionList;

  protected:
    class TextModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:
      TextModelColumns (guint columns_count);
      ~TextModelColumns () noexcept;

      auto
      get_num_columns () const -> guint;

      Gtk::TreeModelColumn<Glib::ustring>* m_columns;

    protected:
      guint m_columns_count;
    };

    Glib::RefPtr<Gtk::ListStore> m_model;
    TextModelColumns m_model_columns;
  };

} // namespace Gtk

#endif

#endif
