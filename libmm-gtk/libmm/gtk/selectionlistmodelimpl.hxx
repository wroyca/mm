// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SELECTIONLISTMODELIMPL_H
#define _GTKMM_SELECTIONLISTMODELIMPL_H

#include <libmm/gio/listmodel.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/mm-gtkconfig.hxx>
#include <libmm/gtk/selectionmodel.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT SelectionListModelImpl : public Gio::ListModel,
                                           public SelectionModel,
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
    friend class Stack;

#endif

  public:
    SelectionListModelImpl (SelectionListModelImpl&& src) noexcept;
    auto
    operator= (SelectionListModelImpl&& src) noexcept
        -> SelectionListModelImpl&;

    ~SelectionListModelImpl () noexcept override;
  };

} // namespace Gtk

#endif
