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

namespace glib
{

  auto
  wrap (GtkMediaFile* object, bool take_copy) -> glib::RefPtr<gtk::MediaFile>
  {
    return glib::make_refptr_for_instance<gtk::MediaFile> (
        dynamic_cast<gtk::MediaFile*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  MediaFile_Class::init () -> const glib::Class&
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->close)
      (*base->close) (self);
  }

  auto
  MediaFile_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MediaFile ((GtkMediaFile*) object);
  }

  auto
  MediaFile::gobj_copy () -> GtkMediaFile*
  {
    reference ();
    return gobj ();
  }

  MediaFile::MediaFile (const glib::ConstructParams& construct_params)
    : gtk::MediaStream (construct_params)
  {
  }

  MediaFile::MediaFile (GtkMediaFile* castitem)
    : gtk::MediaStream ((GtkMediaStream*) (castitem))
  {
  }

  MediaFile::MediaFile (MediaFile&& src) noexcept
    : gtk::MediaStream (std::move (src))
  {
  }

  auto
  MediaFile::operator= (MediaFile&& src) noexcept -> MediaFile&
  {
    gtk::MediaStream::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::MediaStream (glib::ConstructParams (mediafile_class_.init ()))
  {
  }

  auto
  MediaFile::create () -> glib::RefPtr<MediaFile>
  {
    return glib::wrap (GTK_MEDIA_FILE (gtk_media_file_new ()));
  }

  auto
  MediaFile::create_for_filename (const std::string& filename) -> glib::RefPtr<MediaFile>
  {
    return glib::wrap (
        GTK_MEDIA_FILE (gtk_media_file_new_for_filename (filename.c_str ())));
  }

  auto
  MediaFile::create_for_resource (const std::string& resource_path) -> glib::RefPtr<MediaFile>
  {
    return glib::wrap (GTK_MEDIA_FILE (
        gtk_media_file_new_for_resource (resource_path.c_str ())));
  }

  auto
  MediaFile::create (const glib::RefPtr<gio::File>& file) -> glib::RefPtr<MediaFile>
  {
    return glib::wrap (GTK_MEDIA_FILE (gtk_media_file_new_for_file (
        const_cast<GFile*> (glib::unwrap<gio::File> (file)))));
  }

  auto
  MediaFile::create (const glib::RefPtr<gio::InputStream>& stream) -> glib::RefPtr<MediaFile>
  {
    return glib::wrap (GTK_MEDIA_FILE (gtk_media_file_new_for_input_stream (
        const_cast<GInputStream*> (glib::unwrap (stream)))));
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
  MediaFile::set_file (const glib::RefPtr<gio::File>& file) -> void
  {
    gtk_media_file_set_file (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (file)));
  }

  auto
  MediaFile::get_file () -> glib::RefPtr<gio::File>
  {
    auto retvalue = glib::wrap (gtk_media_file_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  MediaFile::get_file () const -> glib::RefPtr<const gio::File>
  {
    return const_cast<MediaFile*> (this)->get_file ();
  }

  auto
  MediaFile::set_input_stream (const glib::RefPtr<gio::InputStream>& stream) -> void
  {
    gtk_media_file_set_input_stream (
        gobj (),
        const_cast<GInputStream*> (glib::unwrap (stream)));
  }

  auto
  MediaFile::get_input_stream () -> glib::RefPtr<gio::InputStream>
  {
    auto retvalue = glib::wrap (gtk_media_file_get_input_stream (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  MediaFile::get_input_stream () const -> glib::RefPtr<const gio::InputStream>
  {
    return const_cast<MediaFile*> (this)->get_input_stream ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::File>>::value,
      "Type glib::RefPtr<gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MediaFile::property_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::File>> (this, "file");
  }

  auto
  MediaFile::property_file () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>> (this, "file");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::InputStream>>::value,
      "Type glib::RefPtr<gio::InputStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MediaFile::property_input_stream () -> glib::PropertyProxy<glib::RefPtr<gio::InputStream>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::InputStream>> (this,
                                                                "input-stream");
  }

  auto
  MediaFile::property_input_stream () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::InputStream>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::InputStream>> (
        this,
        "input-stream");
  }

  auto
  gtk::MediaFile::open_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->open)
    {
      (*base->open) (gobj ());
    }
  }

  auto
  gtk::MediaFile::close_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->close)
    {
      (*base->close) (gobj ());
    }
  }

} // namespace gtk
