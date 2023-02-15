// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DRAWINGAREA_P_H
#define _GTKMM_DRAWINGAREA_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API DrawingArea_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = DrawingArea;
    using BaseObjectType = GtkDrawingArea;
    using BaseClassType = GtkDrawingAreaClass;
    using CppClassParent = Gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class DrawingArea;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    resize_callback (GtkDrawingArea* self, gint p0, gint p1) -> void;
  };

} // namespace Gtk

#endif
