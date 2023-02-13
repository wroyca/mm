
#ifndef _GIOMM_TLSCONNECTION_P_H
#define _GIOMM_TLSCONNECTION_P_H


#include <libmm-gio/iostream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

class GIOMM_API TlsConnection_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TlsConnection;
  using BaseObjectType = GTlsConnection;
  using BaseClassType = GTlsConnectionClass;
  using CppClassParent = IOStream_Class;
  using BaseClassParent = GIOStreamClass;

  friend class TlsConnection;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto accept_certificate_callback (
    GTlsConnection *self, GTlsCertificate *p0, GTlsCertificateFlags p1) -> gboolean;

  //Callbacks (virtual functions):
  static auto handshake_vfunc_callback (
    GTlsConnection *self, GCancellable *cancellable, GError **error) -> gboolean;
  static auto handshake_async_vfunc_callback (
    GTlsConnection *self, int io_priority, GCancellable *cancellable, GAsyncReadyCallback callback,
    gpointer user_data) -> void;
  static auto handshake_finish_vfunc_callback (
    GTlsConnection *self, GAsyncResult *result, GError **error) -> gboolean;
};


} // namespace Gio


#endif /* _GIOMM_TLSCONNECTION_P_H */
