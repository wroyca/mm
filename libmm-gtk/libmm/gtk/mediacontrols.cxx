// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/mediacontrols.hxx>
#include <libmm/gtk/mediacontrols_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkMediaControls* object, bool take_copy) -> gtk::MediaControls*
  {
    return dynamic_cast<gtk::MediaControls*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  MediaControls_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MediaControls_Class::class_init_function;

      gtype_ = gtk_media_controls_get_type ();
    }

    return *this;
  }

  auto
  MediaControls_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MediaControls_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new MediaControls ((GtkMediaControls*) (o)));
  }

  MediaControls::MediaControls (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  MediaControls::MediaControls (GtkMediaControls* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  MediaControls::MediaControls (MediaControls&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  MediaControls::operator= (MediaControls&& src) noexcept -> MediaControls&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  MediaControls::~MediaControls () noexcept
  {
    destroy_ ();
  }

  MediaControls::CppClassType MediaControls::mediacontrols_class_;

  auto
  MediaControls::get_type () -> GType
  {
    return mediacontrols_class_.init ().get_type ();
  }

  auto
  MediaControls::get_base_type () -> GType
  {
    return gtk_media_controls_get_type ();
  }

  MediaControls::MediaControls ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (mediacontrols_class_.init ()))
  {
  }

  MediaControls::MediaControls (const glib::RefPtr<MediaStream>& media_stream)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (mediacontrols_class_.init (),
                                          "media_stream",
                                          glib::unwrap (media_stream),
                                          nullptr))
  {
  }

  auto
  MediaControls::get_media_stream () -> glib::RefPtr<MediaStream>
  {
    auto retvalue = glib::wrap (gtk_media_controls_get_media_stream (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  MediaControls::get_media_stream () const -> glib::RefPtr<const MediaStream>
  {
    return const_cast<MediaControls*> (this)->get_media_stream ();
  }

  auto
  MediaControls::set_media_stream (const glib::RefPtr<MediaStream>& stream) -> void
  {
    gtk_media_controls_set_media_stream (gobj (), glib::unwrap (stream));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<MediaStream>>::value,
      "Type glib::RefPtr<MediaStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MediaControls::property_media_stream () -> glib::PropertyProxy<glib::RefPtr<MediaStream>>
  {
    return glib::PropertyProxy<glib::RefPtr<MediaStream>> (this,
                                                           "media-stream");
  }

  auto
  MediaControls::property_media_stream () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<MediaStream>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<MediaStream>> (
        this,
        "media-stream");
  }

} // namespace gtk
