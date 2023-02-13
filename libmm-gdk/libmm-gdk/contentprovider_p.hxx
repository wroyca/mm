
#ifndef _GDKMM_CONTENTPROVIDER_P_H
#define _GDKMM_CONTENTPROVIDER_P_H


#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gdk
{

class GDKMM_API ContentProvider_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ContentProvider;
  using BaseObjectType = GdkContentProvider;
  using BaseClassType = GdkContentProviderClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class ContentProvider;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto content_changed_callback (GdkContentProvider *self) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gdk


#endif /* _GDKMM_CONTENTPROVIDER_P_H */

