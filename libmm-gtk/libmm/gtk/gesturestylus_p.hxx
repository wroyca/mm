// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTURESTYLUS_P_H
#define _GTKMM_GESTURESTYLUS_P_H

#include <libmm/gtk/gesturesingle_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GestureStylus_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GestureStylus;
    using BaseObjectType = GtkGestureStylus;
    using BaseClassType = GtkGestureStylusClass;
    using CppClassParent = GestureSingle_Class;
    using BaseClassParent = GtkGestureSingleClass;

    friend class GestureStylus;
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
