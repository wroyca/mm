// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/video.hxx>
#include <libmm/gtk/video_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  Video::Video (const std::string& filename)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (video_class_.init ()))
  {
    gtk_video_set_filename (gobj (), Glib::c_str_or_nullptr (filename));
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkVideo* object, bool take_copy) -> Gtk::Video*
  {
    return dynamic_cast<Gtk::Video*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Video_Class::init () -> const Glib::Class&
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
  Video_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Video ((GtkVideo*) (o)));
  }

  Video::Video (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Video::Video (GtkVideo* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Video::Video (Video&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  Video::operator= (Video&& src) noexcept -> Video&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (video_class_.init ()))
  {
  }

  Video::Video (const Glib::RefPtr<MediaStream>& media_stream)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (video_class_.init (),
                                          "media_stream",
                                          Glib::unwrap (media_stream),
                                          nullptr))
  {
  }

  Video::Video (const Glib::RefPtr<Gio::File>& file)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (
          video_class_.init (),
          "file",
          const_cast<GFile*> (Glib::unwrap<Gio::File> (file)),
          nullptr))
  {
  }

  auto
  Video::get_media_stream () -> Glib::RefPtr<MediaStream>
  {
    auto retvalue = Glib::wrap (gtk_video_get_media_stream (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Video::get_media_stream () const -> Glib::RefPtr<const MediaStream>
  {
    return const_cast<Video*> (this)->get_media_stream ();
  }

  auto
  Video::set_media_stream (const Glib::RefPtr<MediaStream>& stream) -> void
  {
    gtk_video_set_media_stream (gobj (), Glib::unwrap (stream));
  }

  auto
  Video::get_file () -> Glib::RefPtr<Gio::File>
  {
    auto retvalue = Glib::wrap (gtk_video_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Video::get_file () const -> Glib::RefPtr<const Gio::File>
  {
    return const_cast<Video*> (this)->get_file ();
  }

  auto
  Video::set_file (const Glib::RefPtr<const Gio::File>& file) -> void
  {
    gtk_video_set_file (gobj (),
                        const_cast<GFile*> (Glib::unwrap<Gio::File> (file)));
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
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<MediaStream>>::value,
      "Type Glib::RefPtr<MediaStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Video::property_media_stream () -> Glib::PropertyProxy<Glib::RefPtr<MediaStream>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<MediaStream>> (this,
                                                           "media-stream");
  }

  auto
  Video::property_media_stream () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<MediaStream>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<MediaStream>> (
        this,
        "media-stream");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::File>>::value,
      "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Video::property_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::File>> (this, "file");
  }

  auto
  Video::property_file () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>> (this, "file");
  }

  auto
  Video::property_autoplay () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "autoplay");
  }

  auto
  Video::property_autoplay () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "autoplay");
  }

  auto
  Video::property_loop () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "loop");
  }

  auto
  Video::property_loop () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "loop");
  }

} // namespace Gtk
