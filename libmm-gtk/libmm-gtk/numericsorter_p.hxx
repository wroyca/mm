
#ifndef _GTKMM_NUMERICSORTER_P_H
#define _GTKMM_NUMERICSORTER_P_H

#include <libmm-gtk/sorter_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API NumericSorterBase_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = NumericSorterBase;
    using BaseObjectType = GtkNumericSorter;
    using BaseClassType = GtkNumericSorterClass;
    using CppClassParent = Sorter_Class;
    using BaseClassParent = GtkSorterClass;

    friend class NumericSorterBase;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
