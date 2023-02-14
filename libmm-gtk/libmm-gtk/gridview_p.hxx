
#ifndef _GTKMM_GRIDVIEW_P_H
#define _GTKMM_GRIDVIEW_P_H

#include <libmm-gtk/listbase_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API GridView_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GridView;
    using BaseObjectType = GtkGridView;
    using BaseClassType = GtkGridViewClass;
    using CppClassParent = ListBase_Class;
    using BaseClassParent = GtkListBaseClass;

    friend class GridView;
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
