// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/mediafile.hxx>
#include <libmm/gtk/mediafile_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gio/file.hxx>
#include <libmm/gio/inputstream.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkMediaFile* object, bool take_copy) -> Glib::RefPtr<Gtk::MediaFile>
  {
    return Glib::make_refptr_for_instance<Gtk::MediaFile> (
        dynamic_cast<Gtk::MediaFile*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MediaFile_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MediaFile_Class::class_init_function;

      register_derived_type (gtk_media_file_get_type ());
    }

    return *this;
  }

  auto
  MediaFile_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->open = &open_vfunc_callback;
    klass->close = &close_vfunc_callback;
  }

  auto
  MediaFile_Class::open_vfunc_callback (GtkMediaFile* self) -> void
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
          obj->open_vfunc ();
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

    if (base && base->open)
      (*base->open) (self);
  }

  auto
  MediaFile_Class::close_vfunc_callback (GtkMediaFile* self) -> void
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
          obj->close_vfunc ();
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

    if (base && base->close)
      (*base->close) (self);
  }

  auto
  MediaFile_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MediaFile ((GtkMediaFile*) object);
  }

  auto
  MediaFile::gobj_copy () -> GtkMediaFile*
  {
    reference ();
    return gobj ();
  }

  MediaFile::MediaFile (const Glib::ConstructParams& construct_params)
    : Gtk::MediaStream (construct_params)
  {
  }

  MediaFile::MediaFile (GtkMediaFile* castitem)
    : Gtk::MediaStream ((GtkMediaStream*) (castitem))
  {
  }

  MediaFile::MediaFile (MediaFile&& src) noexcept
    : Gtk::MediaStream (std::move (src))
  {
  }

  auto
  MediaFile::operator= (MediaFile&& src) noexcept -> MediaFile&
  {
    Gtk::MediaStream::operator= (std::move (src));
    return *this;
  }

  MediaFile::~MediaFile () noexcept {}

  MediaFile::CppClassType MediaFile::mediafile_class_;

  auto
  MediaFile::get_type () -> GType
  {
    return mediafile_class_.init ().get_type ();
  }

  auto
  MediaFile::get_base_type () -> GType
  {
    return gtk_media_file_get_type ();
  }

  MediaFile::MediaFile ()
    : Glib::ObjectBase (nullptr),
      Gtk::MediaStream (Glib::ConstructParams (mediafile_class_.init ()))
  {
  }

  auto
  MediaFile::create () -> Glib::RefPtr<MediaFile>
  {
    return Glib::wrap (GTK_MEDIA_FILE (gtk_media_file_new ()));
  }

  auto
  MediaFile::create_for_filename (const std::string& filename) -> Glib::RefPtr<MediaFile>
  {
    return Glib::wrap (
        GTK_MEDIA_FILE (gtk_media_file_new_for_filename (filename.c_str ())));
  }

  auto
  MediaFile::create_for_resource (const std::string& resource_path) -> Glib::RefPtr<MediaFile>
  {
    return Glib::wrap (GTK_MEDIA_FILE (
        gtk_media_file_new_for_resource (resource_path.c_str ())));
  }

  auto
  MediaFile::create (const Glib::RefPtr<Gio::File>& file) -> Glib::RefPtr<MediaFile>
  {
    return Glib::wrap (GTK_MEDIA_FILE (gtk_media_file_new_for_file (
        const_cast<GFile*> (Glib::unwrap<Gio::File> (file)))));
  }

  auto
  MediaFile::create (const Glib::RefPtr<Gio::InputStream>& stream) -> Glib::RefPtr<MediaFile>
  {
    return Glib::wrap (GTK_MEDIA_FILE (gtk_media_file_new_for_input_stream (
        const_cast<GInputStream*> (Glib::unwrap (stream)))));
  }

  auto
  MediaFile::clear () -> void
  {
    gtk_media_file_clear (gobj ());
  }

  auto
  MediaFile::set_filename (const std::string& filename) -> void
  {
    gtk_media_file_set_filename (gobj (), filename.c_str ());
  }

  auto
  MediaFile::set_resource (const std::string& resource_path) -> void
  {
    gtk_media_file_set_resource (gobj (), resource_path.c_str ());
  }

  auto
  MediaFile::set_file (const Glib::RefPtr<Gio::File>& file) -> void
  {
    gtk_media_file_set_file (
        gobj (),
        const_cast<GFile*> (Glib::unwrap<Gio::File> (file)));
  }

  auto
  MediaFile::get_file () -> Glib::RefPtr<Gio::File>
  {
    auto retvalue = Glib::wrap (gtk_media_file_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  MediaFile::get_file () const -> Glib::RefPtr<const Gio::File>
  {
    return const_cast<MediaFile*> (this)->get_file ();
  }

  auto
  MediaFile::set_input_stream (const Glib::RefPtr<Gio::InputStream>& stream) -> void
  {
    gtk_media_file_set_input_stream (
        gobj (),
        const_cast<GInputStream*> (Glib::unwrap (stream)));
  }

  auto
  MediaFile::get_input_stream () -> Glib::RefPtr<Gio::InputStream>
  {
    auto retvalue = Glib::wrap (gtk_media_file_get_input_stream (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  MediaFile::get_input_stream () const -> Glib::RefPtr<const Gio::InputStream>
  {
    return const_cast<MediaFile*> (this)->get_input_stream ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::File>>::value,
      "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MediaFile::property_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::File>> (this, "file");
  }

  auto
  MediaFile::property_file () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>> (this, "file");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::InputStream>>::value,
      "Type Glib::RefPtr<Gio::InputStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MediaFile::property_input_stream () -> Glib::PropertyProxy<Glib::RefPtr<Gio::InputStream>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::InputStream>> (this,
                                                                "input-stream");
  }

  auto
  MediaFile::property_input_stream () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::InputStream>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::InputStream>> (
        this,
        "input-stream");
  }

  auto
  Gtk::MediaFile::open_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->open)
    {
      (*base->open) (gobj ());
    }
  }

  auto
  Gtk::MediaFile::close_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->close)
    {
      (*base->close) (gobj ());
    }
  }

} // namespace Gtk
