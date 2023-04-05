// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/gtk/listviewtext.hxx>

namespace gtk
{

  ListViewText::TextModelColumns::TextModelColumns (guint columns_count)
    : m_columns_count (columns_count)
  {
    m_columns = new gtk::TreeModelColumn<glib::ustring>[m_columns_count];

    if (m_columns)
    {
      for (guint i = 0; i < m_columns_count; ++i)
      {
        add (m_columns[i]);
      }
    }
  }

  ListViewText::TextModelColumns::~TextModelColumns () noexcept
  {
    if (m_columns)
      delete[] m_columns;
  }

  auto
  ListViewText::TextModelColumns::get_num_columns () const -> guint
  {
    return m_columns_count;
  }

  ListViewText::ListViewText (guint columns_count,
                              bool editable,
                              gtk::SelectionMode mode)
    : m_model_columns (columns_count)
  {
    char column_title[20];

    m_model = gtk::ListStore::create (m_model_columns);
    set_model (m_model);

    for (guint i = 0; i < columns_count; ++i)
    {
      sprintf (column_title, "%d", i);

      if (editable)
        append_column_editable (column_title, m_model_columns.m_columns[i]);
      else
        append_column (column_title, m_model_columns.m_columns[i]);
    }

    get_selection ()->set_mode (mode);
  }

  ListViewText::~ListViewText () noexcept {}

  auto
  ListViewText::set_column_title (guint column, const glib::ustring& title) -> void
  {
    g_return_if_fail (column < get_columns ().size ());

    get_column (column)->set_title (title);
  }

  auto
  ListViewText::get_column_title (guint column) const -> glib::ustring
  {
    g_return_val_if_fail (column < get_columns ().size (), "");

    return get_column (column)->get_title ();
  }

  auto
  ListViewText::append (const glib::ustring& column_one_value) -> guint
  {
    auto newRow = *(m_model->append ());

    newRow[m_model_columns.m_columns[0]] = column_one_value;

    return size () - 1;
  }

  auto
  ListViewText::prepend (const glib::ustring& column_one_value) -> void
  {
    auto newRow = *(m_model->prepend ());

    newRow[m_model_columns.m_columns[0]] = column_one_value;
  }

  auto
  ListViewText::insert (guint row, const glib::ustring& column_one_value) -> void
  {
    g_return_if_fail (row < size ());

    auto iter = m_model->children ()[row].get_iter ();
    auto newRow = *(m_model->insert (iter));

    if (!column_one_value.empty ())
    {
      newRow[m_model_columns.m_columns[0]] = column_one_value;
    }
  }

  auto
  ListViewText::clear_items () -> void
  {
    m_model->clear ();
  }

  auto
  ListViewText::get_text (guint row, guint column) const -> glib::ustring
  {
    glib::ustring result;

    g_return_val_if_fail (row < size (), result);

    const auto childrow = m_model->children ()[row];
    childrow.get_value (column, result);

    return result;
  }

  auto
  ListViewText::set_text (guint row, guint column, const glib::ustring& value) -> void
  {
    g_return_if_fail (row < size ());

    auto childrow = m_model->children ()[row];
    childrow.set_value (column, value);
  }

  auto
  ListViewText::set_text (guint row, const glib::ustring& value) -> void
  {
    g_return_if_fail (row < size ());

    auto childrow = m_model->children ()[row];
    childrow.set_value (0, value);
  }

  auto
  ListViewText::size () const -> guint
  {
    return (guint) m_model->children ().size ();
  }

  auto
  ListViewText::get_num_columns () const -> guint
  {
    return m_model_columns.get_num_columns ();
  }

  auto
  ListViewText::get_selected () -> ListViewText::SelectionList
  {
    glib::RefPtr<gtk::TreeSelection> selected = get_selection ();
    std::vector<TreeModel::Path> selectedRows = selected->get_selected_rows ();

    SelectionList selectionList;
    selectionList.reserve (selected->count_selected_rows ());

    for (std::vector<TreeModel::Path>::const_iterator iter =
             selectedRows.begin ();
         iter != selectedRows.end ();
         ++iter)
    {
      selectionList.push_back (*((*iter).begin ()));
    }

    return selectionList;
  }

} // namespace gtk

#endif
