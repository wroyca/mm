
#ifndef _GTKMM_MEDIASTREAM_H
#define _GTKMM_MEDIASTREAM_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/paintable.hxx>
#include <libmm-gdk/surface.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMediaStream = struct _GtkMediaStream;
using GtkMediaStreamClass = struct _GtkMediaStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API MediaStream_Class;
}
#endif

namespace Glib
{
  class GTKMM_API Error;
}

namespace Gtk
{

  class GTKMM_API MediaStream : public Glib::Object,
                                public Gdk::Paintable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MediaStream;
    using CppClassType = MediaStream_Class;
    using BaseObjectType = GtkMediaStream;
    using BaseClassType = GtkMediaStreamClass;

    MediaStream (const MediaStream&) = delete;
    auto
    operator= (const MediaStream&) -> MediaStream& = delete;

  private:
    friend class MediaStream_Class;
    static CppClassType mediastream_class_;

  protected:
    explicit MediaStream (const Glib::ConstructParams& construct_params);
    explicit MediaStream (GtkMediaStream* castitem);

#endif

  public:
    MediaStream (MediaStream&& src) noexcept;
    auto
    operator= (MediaStream&& src) noexcept -> MediaStream&;

    ~MediaStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkMediaStream*
    {
      return reinterpret_cast<GtkMediaStream*> (gobject_);
    }

    auto
    gobj () const -> const GtkMediaStream*
    {
      return reinterpret_cast<GtkMediaStream*> (gobject_);
    }

    auto
    gobj_copy () -> GtkMediaStream*;

  private:
  public:
    auto
    is_prepared () const -> bool;

    auto
    get_error () const -> Glib::Error;

    auto
    has_audio () const -> bool;

    auto
    has_video () const -> bool;

    void
    play ();

    void
    pause ();

    auto
    get_playing () const -> bool;

    void
    set_playing (bool playing = true);

    auto
    get_ended () const -> bool;

    auto
    get_timestamp () const -> gint64;

    auto
    get_duration () const -> gint64;

    auto
    is_seekable () const -> bool;

    auto
    is_seeking () const -> bool;

    void
    seek (gint64 timestamp);

    auto
    get_loop () const -> bool;

    void
    set_loop (bool loop = true);

    auto
    get_muted () const -> bool;

    void
    set_muted (bool muted = true);

    auto
    get_volume () const -> double;

    void
    set_volume (double volume);

    void
    realize (const Glib::RefPtr<Gdk::Surface>& surface);

    void
    unrealize (const Glib::RefPtr<Gdk::Surface>& surface);

#ifndef GTKMM_DISABLE_DEPRECATED

    void
    prepared (bool has_audio, bool has_video, bool seekable, gint64 duration);
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    void
    unprepared ();
#endif

    void
    stream_prepared (bool has_audio,
                     bool has_video,
                     bool seekable,
                     gint64 duration);

    void
    stream_unprepared ();

    void
    update (gint64 timestamp);

#ifndef GTKMM_DISABLE_DEPRECATED

    void
    ended ();
#endif

    void
    stream_ended ();

    void
    seek_success ();

    void
    seek_failed ();

    void
    set_error (const Glib::Error& error);

    auto
    property_prepared () -> Glib::PropertyProxy<bool>;

    auto
    property_prepared () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_error () const -> Glib::PropertyProxy_ReadOnly<Glib::Error>;

    auto
    property_has_audio () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_video () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_playing () -> Glib::PropertyProxy<bool>;

    auto
    property_playing () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_ended () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_timestamp () const -> Glib::PropertyProxy_ReadOnly<gint64>;

    auto
    property_duration () const -> Glib::PropertyProxy_ReadOnly<gint64>;

    auto
    property_seekable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_seeking () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_loop () -> Glib::PropertyProxy<bool>;

    auto
    property_loop () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_muted () -> Glib::PropertyProxy<bool>;

    auto
    property_muted () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_volume () -> Glib::PropertyProxy<double>;

    auto
    property_volume () const -> Glib::PropertyProxy_ReadOnly<double>;

  protected:
    virtual auto
    play_vfunc () -> bool;

    virtual void
    pause_vfunc ();

    virtual void
    seek_vfunc (gint64 timestamp);

    virtual void
    update_audio_vfunc (bool muted, double volume);

    virtual void
    realize_vfunc (const Glib::RefPtr<Gdk::Surface>& surface);

    virtual void
    unrealize_vfunc (const Glib::RefPtr<Gdk::Surface>& surface);

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkMediaStream* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MediaStream>;
} // namespace Glib

#endif
