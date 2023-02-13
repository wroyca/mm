
#ifndef _GIOMM_INPUTSTREAM_P_H
#define _GIOMM_INPUTSTREAM_P_H


#include <libmm-glib/object_p.hpp>

#include <libmm-glib/class.hpp>

namespace Gio
{

class GIOMM_API InputStream_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = InputStream;
  using BaseObjectType = GInputStream;
  using BaseClassType = GInputStreamClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class InputStream;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto read_fn_vfunc_callback (
    GInputStream *self, void *buffer, gsize count, GCancellable *cancellable,
    GError **error) -> gssize;
  static auto skip_vfunc_callback (
    GInputStream *self, gsize count, GCancellable *cancellable, GError **error) -> gssize;
  static auto close_fn_vfunc_callback (
    GInputStream *self, GCancellable *cancellable, GError **error) -> gboolean;
};


} // namespace Gio


#endif /* _GIOMM_INPUTSTREAM_P_H */

