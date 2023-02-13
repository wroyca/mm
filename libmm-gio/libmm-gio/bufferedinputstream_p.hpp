
#ifndef _GIOMM_BUFFEREDINPUTSTREAM_P_H
#define _GIOMM_BUFFEREDINPUTSTREAM_P_H


#include <mm/gio/private/filterinputstream_p.hpp>

#include <mm/glib/class.hpp>

namespace Gio
{

class GIOMM_API BufferedInputStream_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = BufferedInputStream;
  using BaseObjectType = GBufferedInputStream;
  using BaseClassType = GBufferedInputStreamClass;
  using CppClassParent = FilterInputStream_Class;
  using BaseClassParent = GFilterInputStreamClass;

  friend class BufferedInputStream;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto fill_vfunc_callback (
    GBufferedInputStream *self, gssize count, GCancellable *cancellable, GError **error) -> gssize;
};


} // namespace Gio


#endif /* _GIOMM_BUFFEREDINPUTSTREAM_P_H */

