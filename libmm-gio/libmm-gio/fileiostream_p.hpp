
#ifndef _GIOMM_FILEIOSTREAM_P_H
#define _GIOMM_FILEIOSTREAM_P_H


#include <mm/gio/private/iostream_p.hpp>

#include <mm/glib/class.hpp>

namespace Gio
{

class GIOMM_API FileIOStream_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FileIOStream;
  using BaseObjectType = GFileIOStream;
  using BaseClassType = GFileIOStreamClass;
  using CppClassParent = IOStream_Class;
  using BaseClassParent = GIOStreamClass;

  friend class FileIOStream;
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


#endif /* _GIOMM_FILEIOSTREAM_P_H */

