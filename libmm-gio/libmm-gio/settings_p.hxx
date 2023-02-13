
#ifndef _GIOMM_SETTINGS_P_H
#define _GIOMM_SETTINGS_P_H


#include <libmm-glib/object_p.hpp>

#include <libmm-glib/class.hpp>

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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto changed_callback (GSettings *self, const gchar *p0) -> void;
  static auto writable_change_event_callback (GSettings *self, GQuark p0) -> gboolean;
  static auto writable_changed_callback (GSettings *self, const gchar *p0) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_SETTINGS_P_H */

