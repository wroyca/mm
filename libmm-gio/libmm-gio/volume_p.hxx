
#ifndef _GIOMM_VOLUME_P_H
#define _GIOMM_VOLUME_P_H


#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

class GIOMM_API Volume_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Volume;
  using BaseObjectType = GVolume;
  using BaseClassType = GVolumeIface;
  using CppClassParent = Interface_Class;

  friend class Volume;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto changed_callback (GVolume *self) -> void;
  static auto removed_callback (GVolume *self) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_VOLUME_P_H */
