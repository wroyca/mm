
#ifndef _GTKMM_CELLRENDERERTEXT_P_H
#define _GTKMM_CELLRENDERERTEXT_P_H

#include <libmm-gtk/cellrenderer_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API CellRendererText_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CellRendererText;
    using BaseObjectType = GtkCellRendererText;
    using BaseClassType = GtkCellRendererTextClass;
    using CppClassParent = CellRenderer_Class;
    using BaseClassParent = GtkCellRendererClass;

    friend class CellRendererText;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    edited_callback (GtkCellRendererText* self,
                     const gchar* p0,
                     const gchar* p1) -> void;
  };

} // namespace Gtk

#endif
