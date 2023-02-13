
#ifndef _GTKMM_MEDIASTREAM_P_H
#define _GTKMM_MEDIASTREAM_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API MediaStream_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = MediaStream;
  using BaseObjectType = GtkMediaStream;
  using BaseClassType = GtkMediaStreamClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class MediaStream;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto play_vfunc_callback (GtkMediaStream *self) -> gboolean;
  static auto pause_vfunc_callback (GtkMediaStream *self) -> void;
  static auto seek_vfunc_callback (GtkMediaStream *self, gint64 timestamp) -> void;
  static auto update_audio_vfunc_callback (
    GtkMediaStream *self, gboolean muted, double volume) -> void;
  static auto realize_vfunc_callback (GtkMediaStream *self, GdkSurface *surface) -> void;
  static auto unrealize_vfunc_callback (GtkMediaStream *self, GdkSurface *surface) -> void;
};


} // namespace Gtk


#endif /* _GTKMM_MEDIASTREAM_P_H */

