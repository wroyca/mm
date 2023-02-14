

#include <libmm-gtk/treemodelcolumn.hxx>

namespace Gtk
{

  TreeModelColumnRecord::TreeModelColumnRecord ()
    : column_types_ ()
  {
  }

  TreeModelColumnRecord::~TreeModelColumnRecord () noexcept = default;

  auto
  TreeModelColumnRecord::add (TreeModelColumnBase& column) -> void
  {
    g_return_if_fail (column.index_ == -1);

    column.index_ = column_types_.size ();
    column_types_.push_back (column.type_);
  }

  auto
  TreeModelColumnRecord::size () const -> unsigned int
  {
    return column_types_.size ();
  }

  auto
  TreeModelColumnRecord::types () const -> const GType*
  {
    g_return_val_if_fail (!column_types_.empty (), 0);

    return &column_types_.front ();
  }

  TreeModelColumnBase::TreeModelColumnBase (const GType g_type)
    : type_ (g_type),
      index_ (-1)
  {
  }

} // namespace Gtk
