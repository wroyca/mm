// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_ASYNCRESULT_P_H
#define _GIOMM_ASYNCRESULT_P_H


#include <glibmm/private/interface_p.h>

#include <glibmm/private/interface_p.h>

namespace Gio
{

class GIOMM_API AsyncResult_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = AsyncResult;
  using BaseObjectType = GAsyncResult;
  using BaseClassType = GAsyncResultIface;
  using CppClassParent = Glib::Interface_Class;

  friend class AsyncResult;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static GObject* get_source_object_vfunc_callback(GAsyncResult* self);
  static gboolean is_tagged_vfunc_callback(GAsyncResult* self, gpointer source_tag);
};


} // namespace Gio


#endif /* _GIOMM_ASYNCRESULT_P_H */

