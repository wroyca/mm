// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DRAG_P_H
#define _GDKMM_DRAG_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gdk
{

  class GDKMM_API Drag_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Drag;
    using BaseObjectType = GdkDrag;
    using BaseClassType = GdkDragClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Drag;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gdk

#endif
