
#ifndef _GIOMM_CONVERTEROUTPUTSTREAM_P_H
#define _GIOMM_CONVERTEROUTPUTSTREAM_P_H


#include <mm/gio/private/filteroutputstream_p.hpp>

#include <mm/glib/class.hpp>

namespace Gio
{

class GIOMM_API ConverterOutputStream_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ConverterOutputStream;
  using BaseObjectType = GConverterOutputStream;
  using BaseClassType = GConverterOutputStreamClass;
  using CppClassParent = FilterOutputStream_Class;
  using BaseClassParent = GFilterOutputStreamClass;

  friend class ConverterOutputStream;
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


#endif /* _GIOMM_CONVERTEROUTPUTSTREAM_P_H */

