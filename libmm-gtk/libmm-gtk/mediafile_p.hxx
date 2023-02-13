
#ifndef _GTKMM_MEDIAFILE_P_H
#define _GTKMM_MEDIAFILE_P_H


#include <libmm-gtk/mediastream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

class GTKMM_API MediaFile_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = MediaFile;
  using BaseObjectType = GtkMediaFile;
  using BaseClassType = GtkMediaFileClass;
  using CppClassParent = MediaStream_Class;
  using BaseClassParent = GtkMediaStreamClass;

  friend class MediaFile;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto open_vfunc_callback (GtkMediaFile *self) -> void;
  static auto close_vfunc_callback (GtkMediaFile *self) -> void;
};


} // namespace Gtk


#endif /* _GTKMM_MEDIAFILE_P_H */

