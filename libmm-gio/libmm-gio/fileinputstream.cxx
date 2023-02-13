


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/fileinputstream.hxx>
#include <libmm-gio/fileinputstream_p.hxx>


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
#include <libmm-gio/slot_async.hxx>
#include <libmm-glib/exceptionhandler.hxx>

namespace Gio
{

auto
FileInputStream::query_info(
  const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_input_stream_query_info(gobj(), g_strdup(attributes.c_str()),
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
FileInputStream::query_info(const std::string& attributes) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(
    g_file_input_stream_query_info(gobj(), g_strdup(attributes.c_str()), nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto FileInputStream::query_info_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const std::string &attributes, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_file_input_stream_query_info_async(gobj(), attributes.c_str(), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto FileInputStream::query_info_async (
  const SlotAsyncReady &slot, const std::string &attributes, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_file_input_stream_query_info_async(gobj(), attributes.c_str(), io_priority,
    nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GFileInputStream* object, const bool take_copy) -> RefPtr<Gio::FileInputStream>
{
  return Glib::make_refptr_for_instance<Gio::FileInputStream>( dynamic_cast<Gio::FileInputStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto FileInputStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileInputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_file_input_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Seekable::add_interface(get_type());

  }

  return *this;
}


auto FileInputStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FileInputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FileInputStream((GFileInputStream*)object);
}


/* The implementation: */

auto FileInputStream::gobj_copy() -> GFileInputStream*
{
  reference();
  return gobj();
}

FileInputStream::FileInputStream(const Glib::ConstructParams& construct_params)
: InputStream(construct_params)
{

}

FileInputStream::FileInputStream(GFileInputStream* castitem)
: InputStream((GInputStream*)castitem)
{}


FileInputStream::FileInputStream(FileInputStream&& src) noexcept
: InputStream(std::move(src))
  , Seekable(std::move(src))
{}

auto FileInputStream::operator=(FileInputStream&& src) noexcept -> FileInputStream&
{
  InputStream::operator=(std::move(src));
  Seekable::operator=(std::move(src));
  return *this;
}


FileInputStream::~FileInputStream() noexcept = default;

FileInputStream::CppClassType FileInputStream::fileinputstream_class_; // initialize static member

auto FileInputStream::get_type() -> GType
{
  return fileinputstream_class_.init().get_type();
}


auto FileInputStream::get_base_type() -> GType
{
  return g_file_input_stream_get_type();
}


auto FileInputStream::query_info_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_input_stream_query_info_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


