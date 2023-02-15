// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FRAME_P_H
#define _GTKMM_FRAME_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Frame_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Frame;
    using BaseObjectType = GtkFrame;
    using BaseClassType = GtkFrameClass;
    using CppClassParent = Gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class Frame;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    compute_child_allocation_vfunc_callback (GtkFrame* self,
                                             GtkAllocation* allocation) -> void;
  };

} // namespace Gtk

#endif
