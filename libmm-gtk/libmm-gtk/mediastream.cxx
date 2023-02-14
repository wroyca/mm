// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/mediastream.hxx>
#include <libmm-gtk/mediastream_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkMediaStream* object, const bool take_copy) -> RefPtr<Gtk::MediaStream>
  {
    return Glib::make_refptr_for_instance<Gtk::MediaStream> (
        dynamic_cast<Gtk::MediaStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MediaStream_Class::init () -> const Class&
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
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->play_vfunc ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->play)
      return (*base->play) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  MediaStream_Class::pause_vfunc_callback (GtkMediaStream* self) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->pause)
      (*base->pause) (self);
  }

  auto
  MediaStream_Class::seek_vfunc_callback (GtkMediaStream* self,
                                          const gint64 timestamp) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->seek)
      (*base->seek) (self, timestamp);
  }

  auto
  MediaStream_Class::update_audio_vfunc_callback (GtkMediaStream* self,
                                                  const gboolean muted,
                                                  const double volume) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->update_audio)
      (*base->update_audio) (self, muted, volume);
  }

  auto
  MediaStream_Class::realize_vfunc_callback (GtkMediaStream* self,
                                             GdkSurface* surface) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->realize)
      (*base->realize) (self, surface);
  }

  auto
  MediaStream_Class::unrealize_vfunc_callback (GtkMediaStream* self,
                                               GdkSurface* surface) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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

    const BaseClassType* const base = static_cast<BaseClassType*> (
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
    : Object (construct_params)
  {
  }

  MediaStream::MediaStream (GtkMediaStream* castitem)
    : Object ((GObject*) castitem)
  {
  }

  MediaStream::MediaStream (MediaStream&& src) noexcept
    : Object (std::move (src)),
      Paintable (std::move (src))
  {
  }

  auto
  MediaStream::operator= (MediaStream&& src) noexcept -> MediaStream&
  {
    Object::operator= (std::move (src));
    Paintable::operator= (std::move (src));
    return *this;
  }

  MediaStream::~MediaStream () noexcept = default;

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
  MediaStream::set_playing (const bool playing) -> void
  {
    gtk_media_stream_set_playing (gobj (), playing);
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
  MediaStream::seek (const gint64 timestamp) -> void
  {
    gtk_media_stream_seek (gobj (), timestamp);
  }

  auto
  MediaStream::get_loop () const -> bool
  {
    return gtk_media_stream_get_loop (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::set_loop (const bool loop) -> void
  {
    gtk_media_stream_set_loop (gobj (), loop);
  }

  auto
  MediaStream::get_muted () const -> bool
  {
    return gtk_media_stream_get_muted (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::set_muted (const bool muted) -> void
  {
    gtk_media_stream_set_muted (gobj (), muted);
  }

  auto
  MediaStream::get_volume () const -> double
  {
    return gtk_media_stream_get_volume (const_cast<GtkMediaStream*> (gobj ()));
  }

  auto
  MediaStream::set_volume (const double volume) -> void
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
  MediaStream::prepared (const bool has_audio,
                         const bool has_video,
                         const bool seekable,
                         const gint64 duration) -> void
  {
    gtk_media_stream_prepared (gobj (),
                               has_audio,
                               has_video,
                               seekable,
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
  MediaStream::stream_prepared (const bool has_audio,
                                const bool has_video,
                                const bool seekable,
                                const gint64 duration) -> void
  {
    gtk_media_stream_stream_prepared (gobj (),
                                      has_audio,
                                      has_video,
                                      seekable,
                                      duration);
  }

  auto
  MediaStream::stream_unprepared () -> void
  {
    gtk_media_stream_stream_unprepared (gobj ());
  }

  auto
  MediaStream::update (const gint64 timestamp) -> void
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
    gtk_media_stream_gerror (gobj (), g_error_copy (error.gobj ()));
  }

  auto
  MediaStream::property_prepared () -> Glib::PropertyProxy<bool>
  {
    return {this, "prepared"};
  }

  auto
  MediaStream::property_prepared () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "prepared"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::Error>::value,
      "Type Glib::Error cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MediaStream::property_error () const -> Glib::PropertyProxy_ReadOnly<Glib::Error>
  {
    return {this, "error"};
  }

  auto
  MediaStream::property_has_audio () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "has-audio"};
  }

  auto
  MediaStream::property_has_video () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "has-video"};
  }

  auto
  MediaStream::property_playing () -> Glib::PropertyProxy<bool>
  {
    return {this, "playing"};
  }

  auto
  MediaStream::property_playing () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "playing"};
  }

  auto
  MediaStream::property_ended () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "ended"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<gint64>::value,
      "Type gint64 cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MediaStream::property_timestamp () const -> Glib::PropertyProxy_ReadOnly<gint64>
  {
    return {this, "timestamp"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<gint64>::value,
      "Type gint64 cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MediaStream::property_duration () const -> Glib::PropertyProxy_ReadOnly<gint64>
  {
    return {this, "duration"};
  }

  auto
  MediaStream::property_seekable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "seekable"};
  }

  auto
  MediaStream::property_seeking () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "seeking"};
  }

  auto
  MediaStream::property_loop () -> Glib::PropertyProxy<bool>
  {
    return {this, "loop"};
  }

  auto
  MediaStream::property_loop () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "loop"};
  }

  auto
  MediaStream::property_muted () -> Glib::PropertyProxy<bool>
  {
    return {this, "muted"};
  }

  auto
  MediaStream::property_muted () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "muted"};
  }

  auto
  MediaStream::property_volume () -> Glib::PropertyProxy<double>
  {
    return {this, "volume"};
  }

  auto
  MediaStream::property_volume () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "volume"};
  }

  auto
  MediaStream::play_vfunc () -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->play)
    {
      const bool retval ((*base->play) (gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  MediaStream::pause_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->pause)
    {
      (*base->pause) (gobj ());
    }
  }

  auto
  MediaStream::seek_vfunc (const gint64 timestamp) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->seek)
    {
      (*base->seek) (gobj (), timestamp);
    }
  }

  auto
  MediaStream::update_audio_vfunc (const bool muted, const double volume) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->update_audio)
    {
      (*base->update_audio) (gobj (), static_cast<int> (muted), volume);
    }
  }

  auto
  MediaStream::realize_vfunc (const Glib::RefPtr<Gdk::Surface>& surface) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->realize)
    {
      (*base->realize) (gobj (), Glib::unwrap (surface));
    }
  }

  auto
  MediaStream::unrealize_vfunc (const Glib::RefPtr<Gdk::Surface>& surface) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->unrealize)
    {
      (*base->unrealize) (gobj (), Glib::unwrap (surface));
    }
  }

} // namespace Gtk
