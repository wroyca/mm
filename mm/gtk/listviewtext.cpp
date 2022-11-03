/* Copyright(C) 2006 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or(at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <mm/gtk/listviewtext.hpp>

namespace Gtk
{

ListViewText::TextModelColumns::TextModelColumns(const guint columns_count)
: m_columns_count(columns_count)
{
  m_columns = new TreeModelColumn<Glib::ustring>[m_columns_count];

  if(m_columns)
  {
    for(guint i = 0; i < m_columns_count; ++i)
    {
      add(m_columns[i]);
    }
  }
}

ListViewText::TextModelColumns::~TextModelColumns() noexcept
{
  if(m_columns)
    delete[] m_columns;
}

auto ListViewText::TextModelColumns::get_num_columns() const -> guint
{
  return m_columns_count;
}

ListViewText::ListViewText(const guint columns_count, const bool editable, const SelectionMode mode)
: m_model_columns(columns_count)
{
  char column_title[20];

  // Create model
  m_model = ListStore::create(m_model_columns);
  set_model(m_model);

  // Append columns
  for(guint i = 0; i < columns_count; ++i)
  {
    //Get text for the number:
    sprintf(column_title, "%d", i);

    if(editable)
      append_column_editable(column_title, m_model_columns.m_columns[i]);
    else
      append_column(column_title, m_model_columns.m_columns[i]);
  }

  // Set multiple or simple selection
  get_selection()->set_mode(mode);
}

ListViewText::~ListViewText() noexcept = default;

auto ListViewText::set_column_title (
  const guint column, const Glib::ustring &title) -> void
{
  g_return_if_fail( column < get_columns().size() );

  get_column(column)->set_title(title);
}

auto ListViewText::get_column_title(
  const guint column) const -> Glib::ustring
{
  g_return_val_if_fail( column < get_columns().size(), "" ); //Using Glib::ustring() fails sometimes: Bug #352226

  return get_column(column)->get_title();
}

auto ListViewText::append(const Glib::ustring& column_one_value) -> guint
{
  auto newRow = *m_model->append();

  newRow[m_model_columns.m_columns[0]] = column_one_value;

  return size() - 1;
}

auto ListViewText::prepend (const Glib::ustring &column_one_value) -> void
{
  auto newRow = *m_model->prepend();

  newRow[m_model_columns.m_columns[0]] = column_one_value;
}

auto ListViewText::insert (
  const guint row, const Glib::ustring &column_one_value) -> void
{
  g_return_if_fail( row < size() );

  const auto iter = m_model->children()[row].get_iter();
  auto newRow = *m_model->insert(iter);

  if(!column_one_value.empty())
  {
    newRow[m_model_columns.m_columns[0]] = column_one_value;
  }
}

auto ListViewText::clear_items () -> void
{
  m_model->clear();
}

auto ListViewText::get_text(
  const guint row, const guint column) const -> Glib::ustring
{
  Glib::ustring result;

  g_return_val_if_fail( row < size(), result );

  const auto childrow = m_model->children()[row];
  childrow.get_value(column, result);

  return result;
}

auto ListViewText::set_text (
  const guint row, const guint column, const Glib::ustring &value) -> void
{
  g_return_if_fail( row < size() );

  auto childrow = m_model->children()[row];
  childrow.set_value(column, value);
}

auto ListViewText::set_text (
  const guint row, const Glib::ustring &value) -> void
{
  g_return_if_fail( row < size() );

  auto childrow = m_model->children()[row];
  childrow.set_value(0, value);
}

auto ListViewText::size() const -> guint
{
  return m_model->children().size();
}

auto ListViewText::get_num_columns() const -> guint
{
  return m_model_columns.get_num_columns();
}

auto ListViewText::get_selected() -> SelectionList
{
  const Glib::RefPtr<TreeSelection> selected = get_selection();
  std::vector<TreeModel::Path> selectedRows = selected->get_selected_rows();

  // Reserve space
  SelectionList selectionList;
  selectionList.reserve( selected->count_selected_rows() );

  // Save selected rows

  for (std::vector<TreeModel::Path>::const_iterator iter = selectedRows.begin(); iter != selectedRows.end(); ++iter)
  {
    selectionList.push_back( *(*iter).begin() );
  }

  return selectionList;
}

} //namespace Gtk

