
#ifndef _GLIBMM_BINDING_P_H
#define _GLIBMM_BINDING_P_H


#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Glib
{

class GLIBMM_API Binding_Class : public Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Binding;
  using BaseObjectType = GBinding;
  using BaseClassType = GBindingClass;
  using CppClassParent = Object_Class;
  using BaseClassParent = GObjectClass;

  friend class Binding;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Glib


#endif /* _GLIBMM_BINDING_P_H */

