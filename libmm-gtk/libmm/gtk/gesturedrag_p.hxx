// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTUREDRAG_P_H
#define _GTKMM_GESTUREDRAG_P_H

#include <libmm/gtk/gesturesingle_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GestureDrag_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GestureDrag;
    using BaseObjectType = GtkGestureDrag;
    using BaseClassType = GtkGestureDragClass;
    using CppClassParent = GestureSingle_Class;
    using BaseClassParent = GtkGestureSingleClass;

    friend class GestureDrag;
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
