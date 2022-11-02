// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_TLSINTERACTION_P_H
#define _GIOMM_TLSINTERACTION_P_H


#include <mm/glib/private/object_p.hpp>
#include <gio/gio.h>

#include <mm/glib/class.hpp>

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

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static GTlsInteractionResult ask_password_vfunc_callback(GTlsInteraction* self, GTlsPassword* password, GCancellable* cancellable, GError** error);
  static void ask_password_async_vfunc_callback(GTlsInteraction* self, GTlsPassword* password, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data);
  static GTlsInteractionResult ask_password_finish_vfunc_callback(GTlsInteraction* self, GAsyncResult* result, GError** error);
};


} // namespace Gio


#endif /* _GIOMM_TLSINTERACTION_P_H */

