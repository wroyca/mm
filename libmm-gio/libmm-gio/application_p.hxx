
#ifndef _GIOMM_APPLICATION_P_H
#define _GIOMM_APPLICATION_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API Application_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Application;
    using BaseObjectType = GApplication;
    using BaseClassType = GApplicationClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Application;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    startup_callback (GApplication* self) -> void;
    static auto
    shutdown_callback (GApplication* self) -> void;
    static auto
    activate_callback (GApplication* self) -> void;
    static auto
    command_line_callback (GApplication* self, GApplicationCommandLine* p0)
        -> gint;
    static auto
    handle_local_options_callback (GApplication* self, GVariantDict* p0)
        -> gint;
    static auto
    name_lost_callback (GApplication* self) -> gboolean;
    static auto
    open_callback (GApplication* self,
                   GFile** files,
                   gint n_files,
                   const gchar* hint) -> void;

    static auto
    local_command_line_vfunc_callback (GApplication* self,
                                       gchar*** arguments,
                                       int* exit_status) -> gboolean;
    static auto
    before_emit_vfunc_callback (GApplication* self, GVariant* platform_data)
        -> void;
    static auto
    after_emit_vfunc_callback (GApplication* self, GVariant* platform_data)
        -> void;
    static auto
    quit_mainloop_vfunc_callback (GApplication* self) -> void;
    static auto
    run_mainloop_vfunc_callback (GApplication* self) -> void;
    static auto
    dbus_register_vfunc_callback (GApplication* self,
                                  GDBusConnection* connection,
                                  const gchar* object_path,
                                  GError** error) -> gboolean;
    static auto
    dbus_unregister_vfunc_callback (GApplication* self,
                                    GDBusConnection* connection,
                                    const gchar* object_path) -> void;
  };

} // namespace Gio

#endif
