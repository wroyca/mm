// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gtk/selectionlistmodelimpl.hxx>
#include <utility>

namespace gtk
{
  SelectionListModelImpl::SelectionListModelImpl (GObject* castitem)
    : glib::ObjectBase (nullptr),
      glib::Object (castitem)
  {
  }

  SelectionListModelImpl::SelectionListModelImpl (
      SelectionListModelImpl&& src) noexcept
    : gio::ListModel (std::move (src)),
      SelectionModel (std::move (src)),
      glib::Object (std::move (src))
  {
  }

  auto
  SelectionListModelImpl::operator= (SelectionListModelImpl&& src) noexcept -> SelectionListModelImpl&
  {
    gio::ListModel::operator= (std::move (src));
    SelectionModel::operator= (std::move (src));
    glib::Object::operator= (std::move (src));
    return *this;
  }

  SelectionListModelImpl::~SelectionListModelImpl () noexcept {}

} // namespace gtk
