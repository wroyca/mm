// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>
#include <utility>

namespace adw
{

  SelectionListModelImpl::SelectionListModelImpl (GObject* castitem)
    : glib::ObjectBase (nullptr),
      glib::Object (castitem)
  {
  }

  SelectionListModelImpl::SelectionListModelImpl (
      SelectionListModelImpl&& src) noexcept
    : gio::ListModel (std::move (src)),
      gtk::SelectionModel (std::move (src)),
      glib::Object (std::move (src))
  {
  }

  auto
  SelectionListModelImpl::operator= (SelectionListModelImpl&& src) noexcept -> SelectionListModelImpl&
  {
    gio::ListModel::operator= (std::move (src));
    gtk::SelectionModel::operator= (std::move (src));
    glib::Object::operator= (std::move (src));
    return *this;
  }

  SelectionListModelImpl::~SelectionListModelImpl () noexcept {}

} // namespace adw
