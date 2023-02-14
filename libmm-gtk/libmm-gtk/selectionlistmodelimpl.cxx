// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-gtk/selectionlistmodelimpl.hxx>
#include <utility>

namespace Gtk
{
  SelectionListModelImpl::SelectionListModelImpl (GObject* castitem)
    : ObjectBase (nullptr),
      Object (castitem)
  {
  }

  SelectionListModelImpl::SelectionListModelImpl (
      SelectionListModelImpl&& src) noexcept
    : ListModel (std::move (src)),
      SelectionModel (std::move (src)),
      Object (std::move (src))
  {
  }

  auto
  SelectionListModelImpl::operator= (SelectionListModelImpl&& src) noexcept -> SelectionListModelImpl&
  {
    ListModel::operator= (std::move (src));
    SelectionModel::operator= (std::move (src));
    Object::operator= (std::move (src));
    return *this;
  }

  SelectionListModelImpl::~SelectionListModelImpl () noexcept = default;
} // namespace Gtk
