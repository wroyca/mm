
#ifndef _GIOMM_OUTPUTSTREAM_P_H
#define _GIOMM_OUTPUTSTREAM_P_H


#include <libmm-glib/object_p.hxx>
#include <gio/gio.h>

#include <libmm-glib/class.hxx>

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

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto write_fn_vfunc_callback (
    GOutputStream *self, const void *buffer, gsize count, GCancellable *cancellable,
    GError **error) -> gssize;
  static auto splice_vfunc_callback (
    GOutputStream *self, GInputStream *source, GOutputStreamSpliceFlags flags,
    GCancellable *cancellable, GError **error) -> gssize;
  static auto flush_vfunc_callback (
    GOutputStream *self, GCancellable *cancellable, GError **error) -> gboolean;
  static auto close_fn_vfunc_callback (
    GOutputStream *self, GCancellable *cancellable, GError **error) -> gboolean;
};


} // namespace Gio


#endif /* _GIOMM_OUTPUTSTREAM_P_H */

