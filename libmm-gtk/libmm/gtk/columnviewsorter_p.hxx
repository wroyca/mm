// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLUMNVIEWSORTER_P_H
#define _GTKMM_COLUMNVIEWSORTER_P_H

#include <libmm/gtk/sorter_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ColumnViewSorter_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ColumnViewSorter;
    using BaseObjectType = GtkColumnViewSorter;
    using CppClassParent = gtk::Sorter_Class;

    friend class ColumnViewSorter;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
