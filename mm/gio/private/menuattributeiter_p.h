// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_MENUATTRIBUTEITER_P_H
#define _GIOMM_MENUATTRIBUTEITER_P_H


#include <mm/glib/private/object_p.h>

#include <mm/glib/class.h>

namespace Gio
{

class GIOMM_API MenuAttributeIter_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = MenuAttributeIter;
  using BaseObjectType = GMenuAttributeIter;
  using BaseClassType = GMenuAttributeIterClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class MenuAttributeIter;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_MENUATTRIBUTEITER_P_H */

