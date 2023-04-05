// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SETTINGS_P_H
#define _GIOMM_SETTINGS_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Settings_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Settings;
    using BaseObjectType = GSettings;
    using BaseClassType = GSettingsClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Settings;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GSettings* self, const gchar* p0) -> void;
    static auto
    writable_change_event_callback (GSettings* self, GQuark p0) -> gboolean;
    static auto
    writable_changed_callback (GSettings* self, const gchar* p0) -> void;
  };

} // namespace gio

#endif
