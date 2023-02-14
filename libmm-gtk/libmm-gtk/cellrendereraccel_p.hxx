
#ifndef _GTKMM_CELLRENDERERACCEL_P_H
#define _GTKMM_CELLRENDERERACCEL_P_H

#include <libmm-gtk/cellrenderertext_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API CellRendererAccel_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CellRendererAccel;
    using BaseObjectType = GtkCellRendererAccel;
    using BaseClassType = GtkCellRendererAccelClass;
    using CppClassParent = CellRendererText_Class;
    using BaseClassParent = GtkCellRendererTextClass;

    friend class CellRendererAccel;
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
