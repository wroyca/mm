// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/video.hxx>
#include <libmm/gtk/video_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  Video::Video (const std::string& filename)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (video_class_.init ()))
  {
    gtk_video_set_filename (gobj (), glib::c_str_or_nullptr (filename));
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkVideo* object, bool take_copy) -> gtk::Video*
  {
    return dynamic_cast<gtk::Video*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Video_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Video_Class::class_init_function;

      gtype_ = gtk_video_get_type ();
    }

    return *this;
  }

  auto
  Video_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Video_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Video ((GtkVideo*) (o)));
  }

  Video::Video (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Video::Video (GtkVideo* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Video::Video (Video&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Video::operator= (Video&& src) noexcept -> Video&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Video::~Video () noexcept
  {
    destroy_ ();
  }

  Video::CppClassType Video::video_class_;

  auto
  Video::get_type () -> GType
  {
    return video_class_.init ().get_type ();
  }

  auto
  Video::get_base_type () -> GType
  {
    return gtk_video_get_type ();
  }

  Video::Video ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (video_class_.init ()))
  {
  }

  Video::Video (const glib::RefPtr<MediaStream>& media_stream)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (video_class_.init (),
                                          "media_stream",
                                          glib::unwrap (media_stream),
                                          nullptr))
  {
  }

  Video::Video (const glib::RefPtr<gio::File>& file)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (
          video_class_.init (),
          "file",
          const_cast<GFile*> (glib::unwrap<gio::File> (file)),
          nullptr))
  {
  }

  auto
  Video::get_media_stream () -> glib::RefPtr<MediaStream>
  {
    auto retvalue = glib::wrap (gtk_video_get_media_stream (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Video::get_media_stream () const -> glib::RefPtr<const MediaStream>
  {
    return const_cast<Video*> (this)->get_media_stream ();
  }

  auto
  Video::set_media_stream (const glib::RefPtr<MediaStream>& stream) -> void
  {
    gtk_video_set_media_stream (gobj (), glib::unwrap (stream));
  }

  auto
  Video::get_file () -> glib::RefPtr<gio::File>
  {
    auto retvalue = glib::wrap (gtk_video_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Video::get_file () const -> glib::RefPtr<const gio::File>
  {
    return const_cast<Video*> (this)->get_file ();
  }

  auto
  Video::set_file (const glib::RefPtr<const gio::File>& file) -> void
  {
    gtk_video_set_file (gobj (),
                        const_cast<GFile*> (glib::unwrap<gio::File> (file)));
  }

  auto
  Video::set_filename (const std::string& filename) -> void
  {
    gtk_video_set_filename (gobj (), filename.c_str ());
  }

  auto
  Video::set_resource (const std::string& resource_path) -> void
  {
    gtk_video_set_resource (gobj (), resource_path.c_str ());
  }

  auto
  Video::get_autoplay () const -> bool
  {
    return gtk_video_get_autoplay (const_cast<GtkVideo*> (gobj ()));
  }

  auto
  Video::set_autoplay (bool autoplay) -> void
  {
    gtk_video_set_autoplay (gobj (), static_cast<int> (autoplay));
  }

  auto
  Video::get_loop () const -> bool
  {
    return gtk_video_get_loop (const_cast<GtkVideo*> (gobj ()));
  }

  auto
  Video::set_loop (bool loop) -> void
  {
    gtk_video_set_loop (gobj (), static_cast<int> (loop));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<MediaStream>>::value,
      "Type glib::RefPtr<MediaStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Video::property_media_stream () -> glib::PropertyProxy<glib::RefPtr<MediaStream>>
  {
    return glib::PropertyProxy<glib::RefPtr<MediaStream>> (this,
                                                           "media-stream");
  }

  auto
  Video::property_media_stream () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<MediaStream>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<MediaStream>> (
        this,
        "media-stream");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::File>>::value,
      "Type glib::RefPtr<gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Video::property_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::File>> (this, "file");
  }

  auto
  Video::property_file () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>> (this, "file");
  }

  auto
  Video::property_autoplay () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "autoplay");
  }

  auto
  Video::property_autoplay () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "autoplay");
  }

  auto
  Video::property_loop () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "loop");
  }

  auto
  Video::property_loop () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "loop");
  }

} // namespace gtk
