// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/video.h>
#include <gtkmm/private/video_p.h>


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

namespace Gtk
{

Video::Video(const std::string& filename)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(video_class_.init()))
{
  gtk_video_set_filename(gobj(), Glib::c_str_or_nullptr(filename));
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::Video* wrap(GtkVideo* object, bool take_copy)
{
  return dynamic_cast<Gtk::Video *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Video_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Video_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_video_get_type();

  }

  return *this;
}


void Video_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Video_Class::wrap_new(GObject* o)
{
  return manage(new Video((GtkVideo*)(o)));

}


/* The implementation: */

Video::Video(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

Video::Video(GtkVideo* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


Video::Video(Video&& src) noexcept
: Gtk::Widget(std::move(src))
{}

Video& Video::operator=(Video&& src) noexcept
{
  Gtk::Widget::operator=(std::move(src));
  return *this;
}

Video::~Video() noexcept
{
  destroy_();
}

Video::CppClassType Video::video_class_; // initialize static member

GType Video::get_type()
{
  return video_class_.init().get_type();
}


GType Video::get_base_type()
{
  return gtk_video_get_type();
}


Video::Video()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(video_class_.init()))
{
  

}

Video::Video(const Glib::RefPtr<MediaStream>& media_stream)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(video_class_.init(), "media_stream", Glib::unwrap(media_stream), nullptr))
{
  

}

Video::Video(const Glib::RefPtr<Gio::File>& file)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(video_class_.init(), "file", const_cast<GFile*>(Glib::unwrap<Gio::File>(file)), nullptr))
{
  

}

Glib::RefPtr<MediaStream> Video::get_media_stream()
{
  auto retvalue = Glib::wrap(gtk_video_get_media_stream(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const MediaStream> Video::get_media_stream() const
{
  return const_cast<Video*>(this)->get_media_stream();
}

void Video::set_media_stream(const Glib::RefPtr<MediaStream>& stream)
{
  gtk_video_set_media_stream(gobj(), Glib::unwrap(stream));
}

Glib::RefPtr<Gio::File> Video::get_file()
{
  auto retvalue = Glib::wrap(gtk_video_get_file(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gio::File> Video::get_file() const
{
  return const_cast<Video*>(this)->get_file();
}

void Video::set_file(const Glib::RefPtr<const Gio::File>& file)
{
  gtk_video_set_file(gobj(), const_cast<GFile*>(Glib::unwrap<Gio::File>(file)));
}

void Video::set_filename(const std::string& filename)
{
  gtk_video_set_filename(gobj(), filename.c_str());
}

void Video::set_resource(const std::string& resource_path)
{
  gtk_video_set_resource(gobj(), resource_path.c_str());
}

bool Video::get_autoplay() const
{
  return gtk_video_get_autoplay(const_cast<GtkVideo*>(gobj()));
}

void Video::set_autoplay(bool autoplay)
{
  gtk_video_set_autoplay(gobj(), static_cast<int>(autoplay));
}

bool Video::get_loop() const
{
  return gtk_video_get_loop(const_cast<GtkVideo*>(gobj()));
}

void Video::set_loop(bool loop)
{
  gtk_video_set_loop(gobj(), static_cast<int>(loop));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<MediaStream>>::value,
  "Type Glib::RefPtr<MediaStream> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< Glib::RefPtr<MediaStream> > Video::property_media_stream() 
{
  return Glib::PropertyProxy< Glib::RefPtr<MediaStream> >(this, "media-stream");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<MediaStream> > Video::property_media_stream() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<MediaStream> >(this, "media-stream");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::File>>::value,
  "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< Glib::RefPtr<Gio::File> > Video::property_file() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gio::File> >(this, "file");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::File> > Video::property_file() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::File> >(this, "file");
}

Glib::PropertyProxy< bool > Video::property_autoplay() 
{
  return Glib::PropertyProxy< bool >(this, "autoplay");
}

Glib::PropertyProxy_ReadOnly< bool > Video::property_autoplay() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "autoplay");
}

Glib::PropertyProxy< bool > Video::property_loop() 
{
  return Glib::PropertyProxy< bool >(this, "loop");
}

Glib::PropertyProxy_ReadOnly< bool > Video::property_loop() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "loop");
}


} // namespace Gtk


