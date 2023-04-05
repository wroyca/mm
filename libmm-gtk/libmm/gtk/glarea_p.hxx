// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GLAREA_P_H
#define _GTKMM_GLAREA_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GLArea_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GLArea;
    using BaseObjectType = GtkGLArea;
    using BaseClassType = GtkGLAreaClass;
    using CppClassParent = gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class GLArea;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    create_context_callback (GtkGLArea* self) -> GdkGLContext*;
    static auto
    render_callback (GtkGLArea* self, GdkGLContext* p0) -> gboolean;
    static auto
    resize_callback (GtkGLArea* self, gint p0, gint p1) -> void;
  };

} // namespace gtk

#endif
