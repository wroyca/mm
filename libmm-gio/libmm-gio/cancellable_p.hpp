
#ifndef _GIOMM_CANCELLABLE_P_H
#define _GIOMM_CANCELLABLE_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

namespace Gio
{

class GIOMM_API Cancellable_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Cancellable;
  using BaseObjectType = GCancellable;
  using BaseClassType = GCancellableClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class Cancellable;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto cancelled_callback (GCancellable *self) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_CANCELLABLE_P_H */

