// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MULTISORTER_P_H
#define _GTKMM_MULTISORTER_P_H

#include <libmm/gtk/sorter_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT MultiSorter_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MultiSorter;
    using BaseObjectType = GtkMultiSorter;
    using BaseClassType = GtkMultiSorterClass;
    using CppClassParent = Gtk::Sorter_Class;
    using BaseClassParent = GtkSorterClass;

    friend class MultiSorter;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif