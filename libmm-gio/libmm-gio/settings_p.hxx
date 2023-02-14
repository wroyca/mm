
#ifndef _GIOMM_SETTINGS_P_H
#define _GIOMM_SETTINGS_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API Settings_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Settings;
    using BaseObjectType = GSettings;
    using BaseClassType = GSettingsClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Settings;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GSettings* self, const gchar* p0) -> void;
    static auto
    writable_change_event_callback (GSettings* self, GQuark p0) -> gboolean;
    static auto
    writable_changed_callback (GSettings* self, const gchar* p0) -> void;
  };

} // namespace Gio

#endif
