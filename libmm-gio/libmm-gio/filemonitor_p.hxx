// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEMONITOR_P_H
#define _GIOMM_FILEMONITOR_P_H

#include <gio/gio.h>
#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API FileMonitor_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileMonitor;
    using BaseObjectType = GFileMonitor;
    using BaseClassType = GFileMonitorClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class FileMonitor;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GFileMonitor* self,
                      GFile* p0,
                      GFile* p1,
                      GFileMonitorEvent p2) -> void;
  };

} // namespace Gio

#endif
