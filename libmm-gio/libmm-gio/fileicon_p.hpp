
#ifndef _GIOMM_FILEICON_P_H
#define _GIOMM_FILEICON_P_H


#include <libmm-glib/object_p.hpp>

#include <libmm-glib/class.hpp>

namespace Gio
{

class GIOMM_API FileIcon_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FileIcon;
  using BaseObjectType = GFileIcon;
  using BaseClassType = GFileIconClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class FileIcon;
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


#endif /* _GIOMM_FILEICON_P_H */

