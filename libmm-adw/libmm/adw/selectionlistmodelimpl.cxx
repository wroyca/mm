// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>
#include <utility>

namespace adw
{

  selection_list_model_impl::selection_list_model_impl (GObject* castitem)
    : glib::ObjectBase (nullptr),
      glib::Object (castitem)
  {
  }

  selection_list_model_impl::selection_list_model_impl (
      selection_list_model_impl&& src) noexcept
    : gio::ListModel (std::move (src)),
      gtk::SelectionModel (std::move (src)),
      glib::Object (std::move (src))
  {
  }

  auto
  selection_list_model_impl::operator= (selection_list_model_impl&& src) noexcept -> selection_list_model_impl&
  {
    gio::ListModel::operator= (std::move (src));
    gtk::SelectionModel::operator= (std::move (src));
    glib::Object::operator= (std::move (src));
    return *this;
  }

  selection_list_model_impl::~selection_list_model_impl () noexcept {}

} // namespace adw
