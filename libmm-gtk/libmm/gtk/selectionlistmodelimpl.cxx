// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gtk/selectionlistmodelimpl.hxx>
#include <utility>

namespace Gtk
{
  SelectionListModelImpl::SelectionListModelImpl (GObject* castitem)
    : Glib::ObjectBase (nullptr),
      Glib::Object (castitem)
  {
  }

  SelectionListModelImpl::SelectionListModelImpl (
      SelectionListModelImpl&& src) noexcept
    : Gio::ListModel (std::move (src)),
      SelectionModel (std::move (src)),
      Glib::Object (std::move (src))
  {
  }

  auto
  SelectionListModelImpl::operator= (SelectionListModelImpl&& src) noexcept -> SelectionListModelImpl&
  {
    Gio::ListModel::operator= (std::move (src));
    SelectionModel::operator= (std::move (src));
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  SelectionListModelImpl::~SelectionListModelImpl () noexcept {}

} // namespace Gtk