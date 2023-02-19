// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _ADW_SELECTIONLISTMODELIMPL_H
#define _ADW_SELECTIONLISTMODELIMPL_H

#include <libmm-adw/export.hxx>
#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT SelectionListModelImpl : public Gio::ListModel,
                                 public Gtk::SelectionModel,
                                 public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  public:
    SelectionListModelImpl (const SelectionListModelImpl&) = delete;
    auto
    operator= (const SelectionListModelImpl&)
        -> SelectionListModelImpl& = delete;

  protected:
    explicit SelectionListModelImpl (GObject* castitem);
    friend class Leaflet;
    friend class Squeezer;
    friend class TabView;
    friend class ViewStack;

#endif

  public:
    SelectionListModelImpl (SelectionListModelImpl&& src) noexcept;
    auto
    operator= (SelectionListModelImpl&& src) noexcept
        -> SelectionListModelImpl&;

    ~SelectionListModelImpl () noexcept override;
  };

} // namespace Adw

#endif
