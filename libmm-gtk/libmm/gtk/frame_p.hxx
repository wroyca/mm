// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FRAME_P_H
#define _GTKMM_FRAME_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Frame_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Frame;
    using BaseObjectType = GtkFrame;
    using BaseClassType = GtkFrameClass;
    using CppClassParent = gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class Frame;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    compute_child_allocation_vfunc_callback (GtkFrame* self,
                                             GtkAllocation* allocation) -> void;
  };

} // namespace gtk

#endif
