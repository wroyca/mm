// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTUREZOOM_P_H
#define _GTKMM_GESTUREZOOM_P_H

#include <libmm/gtk/gesture_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GestureZoom_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GestureZoom;
    using BaseObjectType = GtkGestureZoom;
    using BaseClassType = GtkGestureZoomClass;
    using CppClassParent = Gesture_Class;
    using BaseClassParent = GtkGestureClass;

    friend class GestureZoom;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
