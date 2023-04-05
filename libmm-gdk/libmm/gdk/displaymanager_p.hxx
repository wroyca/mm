// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DISPLAYMANAGER_P_H
#define _GDKMM_DISPLAYMANAGER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DisplayManager_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = DisplayManager;
    using BaseObjectType = GdkDisplayManager;
    using BaseClassType = GdkDisplayManagerClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class DisplayManager;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gdk

#endif
