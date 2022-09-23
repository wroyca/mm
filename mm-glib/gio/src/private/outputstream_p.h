// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_OUTPUTSTREAM_P_H
#define _GIOMM_OUTPUTSTREAM_P_H


#include <glibmm/private/object_p.h>
#include <gio/gio.h>

#include <glibmm/class.h>

namespace Gio
{

class GIOMM_API OutputStream_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = OutputStream;
  using BaseObjectType = GOutputStream;
  using BaseClassType = GOutputStreamClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class OutputStream;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static gssize write_fn_vfunc_callback(GOutputStream* self, const void* buffer, gsize count, GCancellable* cancellable, GError** error);
  static gssize splice_vfunc_callback(GOutputStream* self, GInputStream* source, GOutputStreamSpliceFlags flags, GCancellable* cancellable, GError** error);
  static gboolean flush_vfunc_callback(GOutputStream* self, GCancellable* cancellable, GError** error);
  static gboolean close_fn_vfunc_callback(GOutputStream* self, GCancellable* cancellable, GError** error);
};


} // namespace Gio


#endif /* _GIOMM_OUTPUTSTREAM_P_H */

