
#ifndef _GIOMM_DBUSOBJECTMANAGERCLIENT_P_H
#define _GIOMM_DBUSOBJECTMANAGERCLIENT_P_H


#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

namespace DBus
{

class GIOMM_API ObjectManagerClient_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ObjectManagerClient;
  using BaseObjectType = GDBusObjectManagerClient;
  using BaseClassType = GDBusObjectManagerClientClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class ObjectManagerClient;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto interface_proxy_signal_callback (
    GDBusObjectManagerClient *self, GDBusObjectProxy *p0, GDBusProxy *p1, const gchar *p2,
    const gchar *p3, GVariant *p4) -> void;
  static auto interface_proxy_properties_changed_callback (
    GDBusObjectManagerClient *self, GDBusObjectProxy *p0, GDBusProxy *p1, GVariant *p2,
    const gchar *const*p3) -> void;

  //Callbacks (virtual functions):
};


} // namespace DBus

} // namespace Gio


#endif /* _GIOMM_DBUSOBJECTMANAGERCLIENT_P_H */

