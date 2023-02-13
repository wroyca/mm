
#ifndef _PANGOMM_LAYOUT_P_H
#define _PANGOMM_LAYOUT_P_H


#include <libmm-glib/object_p.hpp>

#include <libmm-glib/class.hpp>

namespace Pango
{

class PANGOMM_API Layout_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Layout;
  using BaseObjectType = PangoLayout;
  using BaseClassType = PangoLayoutClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class Layout;
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


} // namespace Pango


#endif /* _PANGOMM_LAYOUT_P_H */

