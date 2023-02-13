
#ifndef _GIOMM_TLSINTERACTION_P_H
#define _GIOMM_TLSINTERACTION_P_H


#include <libmm-glib/object_p.hxx>
#include <gio/gio.h>

#include <libmm-glib/class.hxx>

namespace Gio
{

class GIOMM_API TlsInteraction_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TlsInteraction;
  using BaseObjectType = GTlsInteraction;
  using BaseClassType = GTlsInteractionClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class TlsInteraction;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto ask_password_vfunc_callback (
    GTlsInteraction *self, GTlsPassword *password, GCancellable *cancellable,
    GError **error) -> GTlsInteractionResult;
  static auto ask_password_async_vfunc_callback (
    GTlsInteraction *self, GTlsPassword *password, GCancellable *cancellable,
    GAsyncReadyCallback callback, gpointer user_data) -> void;
  static auto ask_password_finish_vfunc_callback (
    GTlsInteraction *self, GAsyncResult *result, GError **error) -> GTlsInteractionResult;
};


} // namespace Gio


#endif /* _GIOMM_TLSINTERACTION_P_H */

