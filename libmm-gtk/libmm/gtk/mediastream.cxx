// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/mediastream.hxx>
#include <libmm/gtk/mediastream_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkMediaStream* object, bool take_copy) -> Glib::RefPtr<Gtk::MediaStream>
  {
    return Glib::make_refptr_for_instance<Gtk::MediaStream> (
        dynamic_cast<Gtk::MediaStream*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MediaStream_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MediaStream_Class::class_init_function;

      register_derived_type (gtk_media_stream_get_type ());

      Gdk::Paintable::add_interface (get_type ());
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->realize_vfunc (Glib::wrap (surface, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->unrealize_vfunc (Glib::wrap (surface, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->unrealize)
      (*base->unrealize) (self, surface);
  }

  auto
  MediaStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MediaStream ((GtkMediaStream*) object);
  }

  auto
  MediaStream::gobj_copy () -> GtkMediaStream*
  {
    reference ();
    return gobj ();
  }

  MediaStream::MediaStream (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  MediaStream::MediaStream (GtkMediaStream* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  MediaStream::MediaStream (MediaStream&& src) noexcept
    : Glib::Object (std::move (src)),
      Gdk::Paintable (std::move (src))
  {
  }

  auto
  MediaStream::operator= (MediaStream&& src) noexcept -> MediaStream&
  {
    Glib::Object::operator= (std::move (src));
    Gdk::Paintable::operator= (std::move (src));
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
  MediaStream::get_error () const -> Glib::Error
  {
    return Glib::Error (const_cast<GError*> (gtk_media_stream_get_error (
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
  MediaStream::realize (const Glib::RefPtr<Gdk::Surface>& surface) -> void
  {
    gtk_media_stream_realize (gobj (), Glib::unwrap (surface));
  }

  auto
  MediaStream::unrealize (const Glib::RefPtr<Gdk::Surface>& surface) -> void
  {
    gtk_media_stream_unrealize (gobj (), Glib::unwrap (surface));
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
  MediaStream::set_error (const Glib::Error& error) -> void
  {
    gtk_media_stream_gerror (gobj (), g_error_copy ((error).gobj ()));
  }

  auto
  MediaStream::property_prepared () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "prepared");
  }

  auto
  MediaStream::property_prepared () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "prepared");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::Error>::value,
      "Type Glib::Error cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MediaStream::property_error () const -> Glib::PropertyProxy_ReadOnly<Glib::Error>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::Error> (this, "error");
  }

  auto
  MediaStream::property_has_audio () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-audio");
  }

  auto
  MediaStream::property_has_video () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-video");
  }

  auto
  MediaStream::property_playing () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "playing");
  }

  auto
  MediaStream::property_playing () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "playing");
  }

  auto
  MediaStream::property_ended () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "ended");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<gint64>::value,
      "Type gint64 cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MediaStream::property_timestamp () const -> Glib::PropertyProxy_ReadOnly<gint64>
  {
    return Glib::PropertyProxy_ReadOnly<gint64> (this, "timestamp");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<gint64>::value,
      "Type gint64 cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MediaStream::property_duration () const -> Glib::PropertyProxy_ReadOnly<gint64>
  {
    return Glib::PropertyProxy_ReadOnly<gint64> (this, "duration");
  }

  auto
  MediaStream::property_seekable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "seekable");
  }

  auto
  MediaStream::property_seeking () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "seeking");
  }

  auto
  MediaStream::property_loop () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "loop");
  }

  auto
  MediaStream::property_loop () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "loop");
  }

  auto
  MediaStream::property_muted () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "muted");
  }

  auto
  MediaStream::property_muted () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "muted");
  }

  auto
  MediaStream::property_volume () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "volume");
  }

  auto
  MediaStream::property_volume () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "volume");
  }

  auto
  Gtk::MediaStream::play_vfunc () -> bool
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
  Gtk::MediaStream::pause_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->pause)
    {
      (*base->pause) (gobj ());
    }
  }

  auto
  Gtk::MediaStream::seek_vfunc (gint64 timestamp) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->seek)
    {
      (*base->seek) (gobj (), timestamp);
    }
  }

  auto
  Gtk::MediaStream::update_audio_vfunc (bool muted, double volume) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->update_audio)
    {
      (*base->update_audio) (gobj (), static_cast<int> (muted), volume);
    }
  }

  auto
  Gtk::MediaStream::realize_vfunc (const Glib::RefPtr<Gdk::Surface>& surface) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->realize)
    {
      (*base->realize) (gobj (), Glib::unwrap (surface));
    }
  }

  auto
  Gtk::MediaStream::unrealize_vfunc (const Glib::RefPtr<Gdk::Surface>& surface) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->unrealize)
    {
      (*base->unrealize) (gobj (), Glib::unwrap (surface));
    }
  }

} // namespace Gtk