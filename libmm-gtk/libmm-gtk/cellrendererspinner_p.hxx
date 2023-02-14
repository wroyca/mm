
#ifndef _GTKMM_CELLRENDERERSPINNER_P_H
#define _GTKMM_CELLRENDERERSPINNER_P_H

#include <libmm-gtk/cellrenderer_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API CellRendererSpinner_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CellRendererSpinner;
    using BaseObjectType = GtkCellRendererSpinner;
    using BaseClassType = GtkCellRendererSpinnerClass;
    using CppClassParent = CellRenderer_Class;
    using BaseClassParent = GtkCellRendererClass;

    friend class CellRendererSpinner;
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
