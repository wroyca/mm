
#ifndef _GIOMM_FILEINPUTSTREAM_P_H
#define _GIOMM_FILEINPUTSTREAM_P_H


#include <mm/gio/private/inputstream_p.hpp>

#include <mm/glib/class.hpp>

namespace Gio
{

class GIOMM_API FileInputStream_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FileInputStream;
  using BaseObjectType = GFileInputStream;
  using BaseClassType = GFileInputStreamClass;
  using CppClassParent = InputStream_Class;
  using BaseClassParent = GInputStreamClass;

  friend class FileInputStream;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_FILEINPUTSTREAM_P_H */

