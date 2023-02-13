
#ifndef _GIOMM_ASYNCRESULT_P_H
#define _GIOMM_ASYNCRESULT_P_H


#include <libmm-glib/interface_p.hpp>

#include <libmm-glib/interface_p.hpp>

namespace Gio
{

class GIOMM_API AsyncResult_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = AsyncResult;
  using BaseObjectType = GAsyncResult;
  using BaseClassType = GAsyncResultIface;
  using CppClassParent = Interface_Class;

  friend class AsyncResult;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto get_source_object_vfunc_callback (GAsyncResult *self) -> GObject*;
  static auto is_tagged_vfunc_callback (GAsyncResult *self, gpointer source_tag) -> gboolean;
};


} // namespace Gio


#endif /* _GIOMM_ASYNCRESULT_P_H */

