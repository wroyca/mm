// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEMONITOR_P_H
#define _GIOMM_FILEMONITOR_P_H

#include <gio/gio.h>
#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT FileMonitor_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileMonitor;
    using BaseObjectType = GFileMonitor;
    using BaseClassType = GFileMonitorClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class FileMonitor;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GFileMonitor* self,
                      GFile* p0,
                      GFile* p1,
                      GFileMonitorEvent p2) -> void;
  };

} // namespace gio

#endif
