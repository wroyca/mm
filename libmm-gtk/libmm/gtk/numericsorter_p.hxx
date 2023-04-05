// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NUMERICSORTER_P_H
#define _GTKMM_NUMERICSORTER_P_H

#include <libmm/gtk/sorter_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT NumericSorterBase_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = NumericSorterBase;
    using BaseObjectType = GtkNumericSorter;
    using BaseClassType = GtkNumericSorterClass;
    using CppClassParent = gtk::Sorter_Class;
    using BaseClassParent = GtkSorterClass;

    friend class NumericSorterBase;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
