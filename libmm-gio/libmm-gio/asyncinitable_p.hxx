
#ifndef _GIOMM_ASYNCINITABLE_P_H
#define _GIOMM_ASYNCINITABLE_P_H


#include <libmm-glib/interface_p.hxx>
#include <gio/gio.h>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

class GIOMM_API AsyncInitable_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = AsyncInitable;
  using BaseObjectType = GAsyncInitable;
  using BaseClassType = GAsyncInitableIface;
  using CppClassParent = Interface_Class;

  friend class AsyncInitable;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto init_async_vfunc_callback (
    GAsyncInitable *self,
    int io_priority, GCancellable *cancellable, GAsyncReadyCallback callback,
    gpointer user_data) -> void;
  static auto init_finish_vfunc_callback (
    GAsyncInitable *self,
    GAsyncResult *res, GError **error) -> gboolean;
  };


} // namespace Gio


#endif /* _GIOMM_ASYNCINITABLE_P_H */
