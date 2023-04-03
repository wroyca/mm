// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTURESTYLUS_P_H
#define _GTKMM_GESTURESTYLUS_P_H

#include <libmm/gtk/gesturesingle_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT GestureStylus_Class : public Glib::Class
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
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
