
#ifndef _GTKMM_MEDIASTREAM_P_H
#define _GTKMM_MEDIASTREAM_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

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
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    play_vfunc_callback (GtkMediaStream* self) -> gboolean;
    static auto
    pause_vfunc_callback (GtkMediaStream* self) -> void;
    static auto
    seek_vfunc_callback (GtkMediaStream* self, gint64 timestamp) -> void;
    static auto
    update_audio_vfunc_callback (GtkMediaStream* self,
                                 gboolean muted,
                                 double volume) -> void;
    static auto
    realize_vfunc_callback (GtkMediaStream* self, GdkSurface* surface) -> void;
    static auto
    unrealize_vfunc_callback (GtkMediaStream* self, GdkSurface* surface)
        -> void;
  };

} // namespace Gtk

#endif
