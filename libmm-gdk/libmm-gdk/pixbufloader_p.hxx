
#ifndef _GDKMM_PIXBUFLOADER_P_H
#define _GDKMM_PIXBUFLOADER_P_H


#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gdk
{

class GDKMM_API PixbufLoader_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = PixbufLoader;
  using BaseObjectType = GdkPixbufLoader;
  using BaseClassType = GdkPixbufLoaderClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class PixbufLoader;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto area_prepared_callback (GdkPixbufLoader *self) -> void;
  static auto area_updated_callback (
    GdkPixbufLoader *self, gint p0, gint p1, gint p2, gint p3) -> void;
  static auto closed_callback (GdkPixbufLoader *self) -> void;
  static auto size_prepared_callback (GdkPixbufLoader *self, gint p0, gint p1) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gdk


#endif /* _GDKMM_PIXBUFLOADER_P_H */

