


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/mediafile.hxx>
#include <libmm-gtk/mediafile_p.hxx>


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

#include <libmm-gio/file.hxx>
#include <libmm-gio/inputstream.hxx>
#include <gtk/gtk.h>


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkMediaFile* object, const bool take_copy) -> RefPtr<Gtk::MediaFile>
{
  return Glib::make_refptr_for_instance<Gtk::MediaFile>( dynamic_cast<Gtk::MediaFile*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto MediaFile_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MediaFile_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_media_file_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto MediaFile_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->open = &open_vfunc_callback;
  klass->close = &close_vfunc_callback;

}

auto MediaFile_Class::open_vfunc_callback (GtkMediaFile *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->open_vfunc();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->open)
    (*base->open)(self);
}
auto MediaFile_Class::close_vfunc_callback (GtkMediaFile *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->close_vfunc();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->close)
    (*base->close)(self);
}


auto MediaFile_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MediaFile((GtkMediaFile*)object);
}


/* The implementation: */

auto MediaFile::gobj_copy() -> GtkMediaFile*
{
  reference();
  return gobj();
}

MediaFile::MediaFile(const Glib::ConstructParams& construct_params)
: MediaStream(construct_params)
{

}

MediaFile::MediaFile(GtkMediaFile* castitem)
: MediaStream((GtkMediaStream*)castitem)
{}


MediaFile::MediaFile(MediaFile&& src) noexcept
: MediaStream(std::move(src))
{}

auto MediaFile::operator=(MediaFile&& src) noexcept -> MediaFile&
{
  MediaStream::operator=(std::move(src));
  return *this;
}


MediaFile::~MediaFile() noexcept = default;

MediaFile::CppClassType MediaFile::mediafile_class_; // initialize static member

auto MediaFile::get_type() -> GType
{
  return mediafile_class_.init().get_type();
}


auto MediaFile::get_base_type() -> GType
{
  return gtk_media_file_get_type();
}


MediaFile::MediaFile()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
MediaStream(Glib::ConstructParams(mediafile_class_.init()))
{


}

auto MediaFile::create() -> Glib::RefPtr<MediaFile>
{
  return Glib::wrap(GTK_MEDIA_FILE(gtk_media_file_new()));
}

auto MediaFile::create_for_filename(const std::string& filename) -> Glib::RefPtr<MediaFile>
{
  return Glib::wrap(GTK_MEDIA_FILE(gtk_media_file_new_for_filename(filename.c_str())));
}

auto MediaFile::create_for_resource(const std::string& resource_path) -> Glib::RefPtr<MediaFile>
{
  return Glib::wrap(GTK_MEDIA_FILE(gtk_media_file_new_for_resource(resource_path.c_str())));
}

auto MediaFile::create(const Glib::RefPtr<Gio::File>& file) -> Glib::RefPtr<MediaFile>
{
  return Glib::wrap(GTK_MEDIA_FILE(gtk_media_file_new_for_file(Glib::unwrap<Gio::File>(file))));
}

auto MediaFile::create(const Glib::RefPtr<Gio::InputStream>& stream) -> Glib::RefPtr<MediaFile>
{
  return Glib::wrap(GTK_MEDIA_FILE(gtk_media_file_new_for_input_stream(Glib::unwrap(stream))));
}

auto MediaFile::clear () -> void
{
  gtk_media_file_clear(gobj());
}

auto MediaFile::set_filename (const std::string &filename) -> void
{
  gtk_media_file_set_filename(gobj(), filename.c_str());
}

auto MediaFile::set_resource (const std::string &resource_path) -> void
{
  gtk_media_file_set_resource(gobj(), resource_path.c_str());
}

auto MediaFile::set_file (const Glib::RefPtr <Gio::File> &file) -> void
{
  gtk_media_file_set_file(gobj(), Glib::unwrap<Gio::File>(file));
}

auto MediaFile::get_file() -> Glib::RefPtr<Gio::File>
{
  auto retvalue = Glib::wrap(gtk_media_file_get_file(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto MediaFile::get_file() const -> Glib::RefPtr<const Gio::File>
{
  return const_cast<MediaFile*>(this)->get_file();
}

auto MediaFile::set_input_stream (const Glib::RefPtr <Gio::InputStream> &stream) -> void
{
  gtk_media_file_set_input_stream(gobj(), Glib::unwrap(stream));
}

auto MediaFile::get_input_stream() -> Glib::RefPtr<Gio::InputStream>
{
  auto retvalue = Glib::wrap(gtk_media_file_get_input_stream(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto MediaFile::get_input_stream() const -> Glib::RefPtr<const Gio::InputStream>
{
  return const_cast<MediaFile*>(this)->get_input_stream();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::File>>::value,
  "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto MediaFile::property_file() -> Glib::PropertyProxy< Glib::RefPtr<Gio::File> >
{
  return {this, "file"};
}

auto MediaFile::property_file() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::File> >
{
  return {this, "file"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::InputStream>>::value,
  "Type Glib::RefPtr<Gio::InputStream> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto MediaFile::property_input_stream() -> Glib::PropertyProxy< Glib::RefPtr<Gio::InputStream> >
{
  return {this, "input-stream"};
}

auto MediaFile::property_input_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::InputStream> >
{
  return {this, "input-stream"};
}


auto MediaFile::open_vfunc () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->open)
  {
    (*base->open)(gobj());
  }
}
auto MediaFile::close_vfunc () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->close)
  {
    (*base->close)(gobj());
  }
}


} // namespace Gtk


