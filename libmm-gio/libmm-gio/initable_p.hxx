
#ifndef _GIOMM_INITABLE_P_H
#define _GIOMM_INITABLE_P_H


#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

class GIOMM_API Initable_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Initable;
  using BaseObjectType = GInitable;
  using BaseClassType = GInitableIface;
  using CppClassParent = Interface_Class;

  friend class Initable;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto init_vfunc_callback (
    GInitable *self, GCancellable *cancellable, GError **error) -> gboolean;
};


} // namespace Gio


#endif /* _GIOMM_INITABLE_P_H */

