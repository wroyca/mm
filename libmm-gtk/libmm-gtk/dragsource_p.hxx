// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DRAGSOURCE_P_H
#define _GTKMM_DRAGSOURCE_P_H

#include <libmm-gtk/gesturesingle_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API DragSource_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = DragSource;
    using BaseObjectType = GtkDragSource;
    using BaseClassType = GtkDragSourceClass;
    using CppClassParent = GestureSingle_Class;
    using BaseClassParent = GtkGestureSingleClass;

    friend class DragSource;
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
