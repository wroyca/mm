// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MEDIASTREAM_H
#define _GTKMM_MEDIASTREAM_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/paintable.hxx>
#include <libmm/gdk/surface.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMediaStream = struct _GtkMediaStream;
using GtkMediaStreamClass = struct _GtkMediaStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT MediaStream_Class;
}
#endif

namespace glib
{
  class LIBMM_GTK_SYMEXPORT Error;
}

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT MediaStream : public glib::Object,
                                public gdk::Paintable
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
    explicit MediaStream (const glib::ConstructParams& construct_params);
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
    get_error () const -> glib::Error;

    auto
    has_audio () const -> bool;

    auto
    has_video () const -> bool;

    auto
    play () -> void;

    auto
    pause () -> void;

    auto
    get_playing () const -> bool;

    auto
    set_playing (bool playing = true) -> void;

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

    auto
    seek (gint64 timestamp) -> void;

    auto
    get_loop () const -> bool;

    auto
    set_loop (bool loop = true) -> void;

    auto
    get_muted () const -> bool;

    auto
    set_muted (bool muted = true) -> void;

    auto
    get_volume () const -> double;

    auto
    set_volume (double volume) -> void;

    auto
    realize (const glib::RefPtr<gdk::Surface>& surface) -> void;

    auto
    unrealize (const glib::RefPtr<gdk::Surface>& surface) -> void;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    prepared (bool has_audio, bool has_video, bool seekable, gint64 duration)
        -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    unprepared () -> void;
#endif

    auto
    stream_prepared (bool has_audio,
                     bool has_video,
                     bool seekable,
                     gint64 duration) -> void;

    auto
    stream_unprepared () -> void;

    auto
    update (gint64 timestamp) -> void;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    ended () -> void;
#endif

    auto
    stream_ended () -> void;

    auto
    seek_success () -> void;

    auto
    seek_failed () -> void;

    auto
    set_error (const glib::Error& error) -> void;

    auto
    property_prepared () -> glib::PropertyProxy<bool>;

    auto
    property_prepared () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_error () const -> glib::PropertyProxy_ReadOnly<glib::Error>;

    auto
    property_has_audio () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_video () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_playing () -> glib::PropertyProxy<bool>;

    auto
    property_playing () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_ended () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_timestamp () const -> glib::PropertyProxy_ReadOnly<gint64>;

    auto
    property_duration () const -> glib::PropertyProxy_ReadOnly<gint64>;

    auto
    property_seekable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_seeking () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_loop () -> glib::PropertyProxy<bool>;

    auto
    property_loop () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_muted () -> glib::PropertyProxy<bool>;

    auto
    property_muted () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_volume () -> glib::PropertyProxy<double>;

    auto
    property_volume () const -> glib::PropertyProxy_ReadOnly<double>;

  protected:
    virtual auto
    play_vfunc () -> bool;

    virtual auto
    pause_vfunc () -> void;

    virtual auto
    seek_vfunc (gint64 timestamp) -> void;

    virtual auto
    update_audio_vfunc (bool muted, double volume) -> void;

    virtual auto
    realize_vfunc (const glib::RefPtr<gdk::Surface>& surface) -> void;

    virtual auto
    unrealize_vfunc (const glib::RefPtr<gdk::Surface>& surface) -> void;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkMediaStream* object, bool take_copy = false) -> glib::RefPtr<gtk::MediaStream>;
} // namespace glib

#endif
