

#ifndef _GTKMM_LISTVIEW_TEXT_H
#define _GTKMM_LISTVIEW_TEXT_H

#include <libmm-gtk/liststore.hxx>
#include <libmm-gtk/treeview.hxx>

#include <vector>

namespace Gtk
{

  class GTKMM_API ListViewText : public Gtk::TreeView
  {
  public:
    ListViewText (guint columns_count,
                  bool editable = false,
                  Gtk::SelectionMode mode = Gtk::SelectionMode::SINGLE);
    ~ListViewText () noexcept override;

    void
    set_column_title (guint column, const Glib::ustring& title);

    auto
    get_column_title (guint column) const -> Glib::ustring;

    auto
    append (const Glib::ustring& column_one_value = {}) -> guint;

    void
    prepend (const Glib::ustring& column_one_value = {});

    void
    insert (guint row, const Glib::ustring& column_one_value = {});

    void
    clear_items ();

    auto
    get_text (guint row, guint column = 0) const -> Glib::ustring;

    void
    set_text (guint row, guint column, const Glib::ustring& value);

    void
    set_text (guint row, const Glib::ustring& value);

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
      ~TextModelColumns () noexcept override;

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
