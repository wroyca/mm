
#ifndef _GIOMM_FILENAMECOMPLETER_P_H
#define _GIOMM_FILENAMECOMPLETER_P_H


#include <libmm-glib/object_p.hpp>
#include <gio/gio.h>

#include <libmm-glib/class.hpp>

namespace Gio
{

class GIOMM_API FilenameCompleter_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FilenameCompleter;
  using BaseObjectType = GFilenameCompleter;
  using BaseClassType = GFilenameCompleterClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class FilenameCompleter;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto got_completion_data_callback (GFilenameCompleter *self) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_FILENAMECOMPLETER_P_H */

