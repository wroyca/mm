// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LISTVIEW_TEXT_H
#define _GTKMM_LISTVIEW_TEXT_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/gtk/liststore.hxx>
  #include <libmm/gtk/treeview.hxx>

  #include <vector>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ListViewText : public gtk::TreeView
  {
  public:
    ListViewText (guint columns_count,
                  bool editable = false,
                  gtk::SelectionMode mode = gtk::SelectionMode::SINGLE);
    ~ListViewText () noexcept override;

    auto
    set_column_title (guint column, const glib::ustring& title) -> void;

    auto
    get_column_title (guint column) const -> glib::ustring;

    auto
    append (const glib::ustring& column_one_value = {}) -> guint;

    auto
    prepend (const glib::ustring& column_one_value = {}) -> void;

    auto
    insert (guint row, const glib::ustring& column_one_value = {}) -> void;

    auto
    clear_items () -> void;

    auto
    get_text (guint row, guint column = 0) const -> glib::ustring;

    auto
    set_text (guint row, guint column, const glib::ustring& value) -> void;

    auto
    set_text (guint row, const glib::ustring& value) -> void;

    auto
    size () const -> guint;

    auto
    get_num_columns () const -> guint;

    typedef std::vector<int> SelectionList;

    auto
    get_selected () -> SelectionList;

  protected:
    class TextModelColumns : public gtk::TreeModel::ColumnRecord
    {
    public:
      TextModelColumns (guint columns_count);
      ~TextModelColumns () noexcept;

      auto
      get_num_columns () const -> guint;

      gtk::TreeModelColumn<glib::ustring>* m_columns;

    protected:
      guint m_columns_count;
    };

    glib::RefPtr<gtk::ListStore> m_model;
    TextModelColumns m_model_columns;
  };

} // namespace gtk

#endif

#endif
