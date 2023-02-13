


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/fileiostream.hpp>
#include <libmm-gio/fileiostream_p.hpp>


/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <libmm-gio/slot_async.hpp>
#include <libmm-glib/exceptionhandler.hpp>

namespace Gio
{

auto
FileIOStream::query_info(
  const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_io_stream_query_info(gobj(), g_strdup(attributes.c_str()),
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
FileIOStream::query_info(const std::string& attributes) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(
    g_file_io_stream_query_info(gobj(), g_strdup(attributes.c_str()), nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto FileIOStream::query_info_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const std::string &attributes, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_file_io_stream_query_info_async(gobj(), attributes.c_str(), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto FileIOStream::query_info_async (
  const SlotAsyncReady &slot, const std::string &attributes, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_file_io_stream_query_info_async(gobj(), attributes.c_str(), io_priority,
    nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GFileIOStream* object, const bool take_copy) -> RefPtr<Gio::FileIOStream>
{
  return Glib::make_refptr_for_instance<Gio::FileIOStream>( dynamic_cast<Gio::FileIOStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto FileIOStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileIOStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_file_io_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Seekable::add_interface(get_type());

  }

  return *this;
}


auto FileIOStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FileIOStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FileIOStream((GFileIOStream*)object);
}


/* The implementation: */

auto FileIOStream::gobj_copy() -> GFileIOStream*
{
  reference();
  return gobj();
}

FileIOStream::FileIOStream(const Glib::ConstructParams& construct_params)
: IOStream(construct_params)
{

}

FileIOStream::FileIOStream(GFileIOStream* castitem)
: IOStream((GIOStream*)castitem)
{}


FileIOStream::FileIOStream(FileIOStream&& src) noexcept
: IOStream(std::move(src))
  , Seekable(std::move(src))
{}

auto FileIOStream::operator=(FileIOStream&& src) noexcept -> FileIOStream&
{
  IOStream::operator=(std::move(src));
  Seekable::operator=(std::move(src));
  return *this;
}


FileIOStream::~FileIOStream() noexcept = default;

FileIOStream::CppClassType FileIOStream::fileiostream_class_; // initialize static member

auto FileIOStream::get_type() -> GType
{
  return fileiostream_class_.init().get_type();
}


auto FileIOStream::get_base_type() -> GType
{
  return g_file_io_stream_get_type();
}


auto FileIOStream::query_info_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_io_stream_query_info_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto FileIOStream::get_etag() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_file_io_stream_get_etag(const_cast<GFileIOStream*>(gobj())));
}


} // namespace Gio


