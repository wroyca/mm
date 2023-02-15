// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTUREROTATE_P_H
#define _GTKMM_GESTUREROTATE_P_H

#include <libmm-gtk/gesture_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT GestureRotate_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GestureRotate;
    using BaseObjectType = GtkGestureRotate;
    using BaseClassType = GtkGestureRotateClass;
    using CppClassParent = Gesture_Class;
    using BaseClassParent = GtkGestureClass;

    friend class GestureRotate;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
