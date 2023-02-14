
#ifndef _GTKMM_CELLRENDERERTOGGLE_P_H
#define _GTKMM_CELLRENDERERTOGGLE_P_H

#include <libmm-gtk/cellrenderer_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API CellRendererToggle_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CellRendererToggle;
    using BaseObjectType = GtkCellRendererToggle;
    using BaseClassType = GtkCellRendererToggleClass;
    using CppClassParent = CellRenderer_Class;
    using BaseClassParent = GtkCellRendererClass;

    friend class CellRendererToggle;
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
