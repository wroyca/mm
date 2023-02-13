


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/mediacontrols.hpp>
#include <libmm-gtk/mediacontrols_p.hpp>


/* Copyright (C) 2018 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkMediaControls* object, const bool take_copy) -> Gtk::MediaControls*
{
  return dynamic_cast<Gtk::MediaControls *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto MediaControls_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MediaControls_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_media_controls_get_type();

  }

  return *this;
}


auto MediaControls_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MediaControls_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new MediaControls((GtkMediaControls*)o));

}


/* The implementation: */

MediaControls::MediaControls(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

MediaControls::MediaControls(GtkMediaControls* castitem)
: Widget((GtkWidget*)castitem)
{
  }


MediaControls::MediaControls(MediaControls&& src) noexcept
: Widget(std::move(src))
{}

auto MediaControls::operator=(MediaControls&& src) noexcept -> MediaControls&
{
  Widget::operator=(std::move(src));
  return *this;
}

MediaControls::~MediaControls() noexcept
{
  destroy_();
}

MediaControls::CppClassType MediaControls::mediacontrols_class_; // initialize static member

auto MediaControls::get_type() -> GType
{
  return mediacontrols_class_.init().get_type();
}


auto MediaControls::get_base_type() -> GType
{
  return gtk_media_controls_get_type();
}


MediaControls::MediaControls()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(mediacontrols_class_.init()))
{


}

MediaControls::MediaControls(const Glib::RefPtr<MediaStream>& media_stream)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(mediacontrols_class_.init(), "media_stream", Glib::unwrap(media_stream), nullptr))
{


}

auto MediaControls::get_media_stream() -> Glib::RefPtr<MediaStream>
{
  auto retvalue = Glib::wrap(gtk_media_controls_get_media_stream(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto MediaControls::get_media_stream() const -> Glib::RefPtr<const MediaStream>
{
  return const_cast<MediaControls*>(this)->get_media_stream();
}

auto MediaControls::set_media_stream (const Glib::RefPtr <MediaStream> &stream) -> void
{
  gtk_media_controls_set_media_stream(gobj(), Glib::unwrap(stream));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<MediaStream>>::value,
  "Type Glib::RefPtr<MediaStream> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto MediaControls::property_media_stream() -> Glib::PropertyProxy< Glib::RefPtr<MediaStream> >
{
  return {this, "media-stream"};
}

auto MediaControls::property_media_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<MediaStream> >
{
  return {this, "media-stream"};
}


} // namespace Gtk


