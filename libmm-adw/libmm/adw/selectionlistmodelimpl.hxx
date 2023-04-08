// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _ADW_SELECTIONLISTMODELIMPL_H
#define _ADW_SELECTIONLISTMODELIMPL_H

#include <libmm/adw/export.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT selection_list_model_impl : public gio::ListModel,
                                 public gtk::SelectionModel,
                                 public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  public:
    selection_list_model_impl (const selection_list_model_impl&) = delete;
    auto
    operator= (const selection_list_model_impl&)
        -> selection_list_model_impl& = delete;

  protected:
    explicit selection_list_model_impl (GObject* castitem);
    friend class leaflet;
    friend class squeezer;
    friend class tab_view;
    friend class view_stack;

#endif

  public:
    selection_list_model_impl (selection_list_model_impl&& src) noexcept;
    auto
    operator= (selection_list_model_impl&& src) noexcept
        -> selection_list_model_impl&;

    ~selection_list_model_impl () noexcept override;
  };

} // namespace adw

#endif
