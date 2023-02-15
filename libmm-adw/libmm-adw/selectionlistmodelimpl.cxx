// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-adw/selectionlistmodelimpl.hxx>
#include <libmm-gtk/mm-gtk.hxx>
#include <utility>

namespace Adw
{

  SelectionListModelImpl::SelectionListModelImpl (GObject* castitem)
    : Glib::ObjectBase (nullptr),
      Glib::Object (castitem)
  {
  }

  SelectionListModelImpl::SelectionListModelImpl (
      SelectionListModelImpl&& src) noexcept
    : Gio::ListModel (std::move (src)),
      Gtk::SelectionModel (std::move (src)),
      Glib::Object (std::move (src))
  {
  }

  auto
  SelectionListModelImpl::operator= (SelectionListModelImpl&& src) noexcept -> SelectionListModelImpl&
  {
    Gio::ListModel::operator= (std::move (src));
    Gtk::SelectionModel::operator= (std::move (src));
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  SelectionListModelImpl::~SelectionListModelImpl () noexcept {}

} // namespace Adw
