// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/mediastream.hxx>
#include <libmm/gtk/mediastream_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkMediaStream* object, bool take_copy) -> glib::RefPtr<gtk::MediaStream>
  {
    return glib::make_refptr_for_instance<gtk::MediaStream> (
        dynamic_cast<gtk::MediaStream*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  MediaStream_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MediaStream_Class::class_init_function;

      register_derived_type (gtk_media_stream_get_type ());

      gdk::Paintable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  MediaStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->play = &play_vfunc_callback;
    klass->pause = &pause_vfunc_callback;
    klass->seek = &seek_vfunc_callback;
    klass->update_audio = &update_audio_vfunc_callback;
    klass->realize = &realize_vfunc_callback;
    klass->unrealize = &unrealize_vfunc_callback;
  }

  auto
  MediaStream_Class::play_vfunc_callback (GtkMediaStream* self) -> gboolean
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<int> (obj->play_vfunc ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->play)
      return (*base->play) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  MediaStream_Class::pause_vfunc_callback (GtkMediaStream* self) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->pause_vfunc ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->pause)
      (*base->pause) (self);
  }

  auto
  MediaStream_Class::seek_vfunc_callback (GtkMediaStream* self,
                                          gint64 timestamp) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->seek_vfunc (timestamp);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->seek)
      (*base->seek) (self, timestamp);
  }

  auto
  MediaStream_Class::update_audio_vfunc_callback (GtkMediaStream* self,
                                                  gboolean muted,
                                                  double volume) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->update_audio_vfunc (muted, volume);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->update_audio)
      (*base->update_audio) (self, muted, volume);
  }

  auto
  MediaStream_Class::realize_vfunc_callback (GtkMediaStream* self,
                                             GdkSurface* surface) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->realize_vfunc (glib::wrap (surface, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->realize)
      (*base->realize) (self, surface);
  }

  auto
  MediaStream_Class::unrealize_vfunc_callback (GtkMediaStream* self,
                                               GdkSurface* surface) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->unrealize_vfunc (glib::wrap (surface, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->unrealize)
      (*base->unrealize) (self, surface);
  }

  auto
  MediaStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MediaStream ((GtkMediaStream*) object);
  }

  auto
  MediaStream::gobj_copy () -> GtkMediaStream*
  {
    reference ();
    return gobj ();
  }

  MediaStream::MediaStream (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  MediaStream::MediaStream (GtkMediaStream* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  MediaStream::MediaStream (MediaStream&& src) noexcept
    : glib::Object (std::move (src)),
      gdk::Paintable (std::move (src))
  {
  }

  auto
  MediaStream::operator= (MediaStream&& src) noexcept -> MediaStream&
  {
    glib::Object::operator= (std::move (src));
    gdk::Paintable::operator= (std::move (src));
    return *this;
  }

  MediaStream::~MediaStream () noexcept {}

  MediaStream::CppClassType MediaStream::mediastream_class_;

  auto
  MediaStream::get_type () -> GType
  {
    return mediastream_class_.init ().get_type ();
  }

  auto
  MediaStream::get_base_type () -> GType
  {
    return gtk_media_stream_get_type ();
  }

  auto
  MediaStream::is_prepared () const -> bool
  {
    return gtk_media_stream_is_prepared (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::get_error () const -> glib::Error
  {
    return glib::Error (const_cast<GError*> (gtk_media_stream_get_error (
                            const_cast<GtkMediaStream*> (gobj ()))),
                        true);
  }

  auto
  MediaStream::has_audio () const -> bool
  {
    return gtk_media_stream_has_audio (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::has_video () const -> bool
  {
    return gtk_media_stream_has_video (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::play () -> void
  {
    gtk_media_stream_play (gobj ());
  }

  auto
  MediaStream::pause () -> void
  {
    gtk_media_stream_pause (gobj ());
  }

  auto
  MediaStream::get_playing () const -> bool
  {
    return gtk_media_stream_get_playing (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::set_playing (bool playing) -> void
  {
    gtk_media_stream_set_playing (gobj (), static_cast<int> (playing));
  }

  auto
  MediaStream::get_ended () const -> bool
  {
    return gtk_media_stream_get_ended (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::get_timestamp () const -> gint64
  {
    return gtk_media_stream_get_timestamp (
        const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::get_duration () const -> gint64
  {
    return gtk_media_stream_get_duration (
        const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::is_seekable () const -> bool
  {
    return gtk_media_stream_is_seekable (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::is_seeking () const -> bool
  {
    return gtk_media_stream_is_seeking (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::seek (gint64 timestamp) -> void
  {
    gtk_media_stream_seek (gobj (), timestamp);
  }

  auto
  MediaStream::get_loop () const -> bool
  {
    return gtk_media_stream_get_loop (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::set_loop (bool loop) -> void
  {
    gtk_media_stream_set_loop (gobj (), static_cast<int> (loop));
  }

  auto
  MediaStream::get_muted () const -> bool
  {
    return gtk_media_stream_get_muted (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::set_muted (bool muted) -> void
  {
    gtk_media_stream_set_muted (gobj (), static_cast<int> (muted));
  }

  auto
  MediaStream::get_volume () const -> double
  {
    return gtk_media_stream_get_volume (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::set_volume (double volume) -> void
  {
    gtk_media_stream_set_volume (gobj (), volume);
  }

  auto
  MediaStream::realize (const glib::RefPtr<gdk::Surface>& surface) -> void
  {
    gtk_media_stream_realize (gobj (), glib::unwrap (surface));
  }

  auto
  MediaStream::unrealize (const glib::RefPtr<gdk::Surface>& surface) -> void
  {
    gtk_media_stream_unrealize (gobj (), glib::unwrap (surface));
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  MediaStream::prepared (bool has_audio,
                         bool has_video,
                         bool seekable,
                         gint64 duration) -> void
  {
    gtk_media_stream_prepared (gobj (),
                               static_cast<int> (has_audio),
                               static_cast<int> (has_video),
                               static_cast<int> (seekable),
                               duration);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  MediaStream::unprepared () -> void
  {
    gtk_media_stream_unprepared (gobj ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  MediaStream::stream_prepared (bool has_audio,
                                bool has_video,
                                bool seekable,
                                gint64 duration) -> void
  {
    gtk_media_stream_stream_prepared (gobj (),
                                      static_cast<int> (has_audio),
                                      static_cast<int> (has_video),
                                      static_cast<int> (seekable),
                                      duration);
  }

  auto
  MediaStream::stream_unprepared () -> void
  {
    gtk_media_stream_stream_unprepared (gobj ());
  }

  auto
  MediaStream::update (gint64 timestamp) -> void
  {
    gtk_media_stream_update (gobj (), timestamp);
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  MediaStream::ended () -> void
  {
    gtk_media_stream_ended (gobj ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  MediaStream::stream_ended () -> void
  {
    gtk_media_stream_stream_ended (gobj ());
  }

  auto
  MediaStream::seek_success () -> void
  {
    gtk_media_stream_seek_success (gobj ());
  }

  auto
  MediaStream::seek_failed () -> void
  {
    gtk_media_stream_seek_failed (gobj ());
  }

  auto
  MediaStream::set_error (const glib::Error& error) -> void
  {
    gtk_media_stream_gerror (gobj (), g_error_copy ((error).gobj ()));
  }

  auto
  MediaStream::property_prepared () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "prepared");
  }

  auto
  MediaStream::property_prepared () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "prepared");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::Error>::value,
      "Type glib::Error cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MediaStream::property_error () const -> glib::PropertyProxy_ReadOnly<glib::Error>
  {
    return glib::PropertyProxy_ReadOnly<glib::Error> (this, "error");
  }

  auto
  MediaStream::property_has_audio () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-audio");
  }

  auto
  MediaStream::property_has_video () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-video");
  }

  auto
  MediaStream::property_playing () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "playing");
  }

  auto
  MediaStream::property_playing () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "playing");
  }

  auto
  MediaStream::property_ended () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "ended");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gint64>::value,
      "Type gint64 cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MediaStream::property_timestamp () const -> glib::PropertyProxy_ReadOnly<gint64>
  {
    return glib::PropertyProxy_ReadOnly<gint64> (this, "timestamp");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gint64>::value,
      "Type gint64 cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MediaStream::property_duration () const -> glib::PropertyProxy_ReadOnly<gint64>
  {
    return glib::PropertyProxy_ReadOnly<gint64> (this, "duration");
  }

  auto
  MediaStream::property_seekable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "seekable");
  }

  auto
  MediaStream::property_seeking () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "seeking");
  }

  auto
  MediaStream::property_loop () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "loop");
  }

  auto
  MediaStream::property_loop () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "loop");
  }

  auto
  MediaStream::property_muted () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "muted");
  }

  auto
  MediaStream::property_muted () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "muted");
  }

  auto
  MediaStream::property_volume () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "volume");
  }

  auto
  MediaStream::property_volume () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "volume");
  }

  auto
  gtk::MediaStream::play_vfunc () -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->play)
    {
      bool retval ((*base->play) (gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  gtk::MediaStream::pause_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->pause)
    {
      (*base->pause) (gobj ());
    }
  }

  auto
  gtk::MediaStream::seek_vfunc (gint64 timestamp) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->seek)
    {
      (*base->seek) (gobj (), timestamp);
    }
  }

  auto
  gtk::MediaStream::update_audio_vfunc (bool muted, double volume) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->update_audio)
    {
      (*base->update_audio) (gobj (), static_cast<int> (muted), volume);
    }
  }

  auto
  gtk::MediaStream::realize_vfunc (const glib::RefPtr<gdk::Surface>& surface) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->realize)
    {
      (*base->realize) (gobj (), glib::unwrap (surface));
    }
  }

  auto
  gtk::MediaStream::unrealize_vfunc (const glib::RefPtr<gdk::Surface>& surface) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->unrealize)
    {
      (*base->unrealize) (gobj (), glib::unwrap (surface));
    }
  }

} // namespace gtk
