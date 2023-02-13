


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/fileenumerator.hpp>
#include <libmm-gio/fileenumerator_p.hpp>


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
#include <libmm-gio/file.hpp>
#include <libmm-glib/error.hpp>
#include <libmm-glib/exceptionhandler.hpp>
#include <libmm-gio/slot_async.hpp>

namespace Gio
{

auto FileEnumerator::next_files_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int num_files, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_file_enumerator_next_files_async(gobj(), num_files, io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto FileEnumerator::next_files_async (
  const SlotAsyncReady &slot, const int num_files, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_file_enumerator_next_files_async(gobj(), num_files, io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto FileEnumerator::close_async (
  const int io_priority, const Glib::RefPtr <Cancellable> &cancellable,
  const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_file_enumerator_close_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto FileEnumerator::close_async (
  const int io_priority, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_file_enumerator_close_async(gobj(), io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GFileEnumerator* object, const bool take_copy) -> RefPtr<Gio::FileEnumerator>
{
  return Glib::make_refptr_for_instance<Gio::FileEnumerator>( dynamic_cast<Gio::FileEnumerator*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto FileEnumerator_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileEnumerator_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_file_enumerator_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto FileEnumerator_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FileEnumerator_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FileEnumerator((GFileEnumerator*)object);
}


/* The implementation: */

auto FileEnumerator::gobj_copy() -> GFileEnumerator*
{
  reference();
  return gobj();
}

FileEnumerator::FileEnumerator(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FileEnumerator::FileEnumerator(GFileEnumerator* castitem)
: Object((GObject*)castitem)
{}


FileEnumerator::FileEnumerator(FileEnumerator&& src) noexcept
: Object(std::move(src))
{}

auto FileEnumerator::operator=(FileEnumerator&& src) noexcept -> FileEnumerator&
{
  Object::operator=(std::move(src));
  return *this;
}


FileEnumerator::~FileEnumerator() noexcept = default;

FileEnumerator::CppClassType FileEnumerator::fileenumerator_class_; // initialize static member

auto FileEnumerator::get_type() -> GType
{
  return fileenumerator_class_.init().get_type();
}


auto FileEnumerator::get_base_type() -> GType
{
  return g_file_enumerator_get_type();
}


auto FileEnumerator::next_file(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_enumerator_next_file(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto FileEnumerator::next_file() -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_enumerator_next_file(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto FileEnumerator::close(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_enumerator_close(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto FileEnumerator::close() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_enumerator_close(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto FileEnumerator::next_files_finish(const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::RefPtr<FileInfo>>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::ListHandler<Glib::RefPtr<FileInfo>>::list_to_vector(g_file_enumerator_next_files_finish(gobj(), Glib::unwrap(result), &gerror), Glib::OWNERSHIP_DEEP);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto FileEnumerator::close_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_enumerator_close_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto FileEnumerator::is_closed() const -> bool
{
  return g_file_enumerator_is_closed(const_cast<GFileEnumerator*>(gobj()));
}

auto FileEnumerator::has_pending() const -> bool
{
  return g_file_enumerator_has_pending(const_cast<GFileEnumerator*>(gobj()));
}

auto FileEnumerator::set_pending (
  const bool pending) -> void
{
  g_file_enumerator_set_pending(gobj(), pending);
}

auto FileEnumerator::get_container() -> Glib::RefPtr<File>
{
  auto retvalue = Glib::wrap(g_file_enumerator_get_container(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FileEnumerator::get_container() const -> Glib::RefPtr<const File>
{
  auto retvalue = Glib::wrap(g_file_enumerator_get_container(const_cast<GFileEnumerator*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FileEnumerator::get_child(const Glib::RefPtr<FileInfo>& info) -> Glib::RefPtr<File>
{
  return Glib::wrap(g_file_enumerator_get_child(gobj(), Glib::unwrap(info)));
}

auto FileEnumerator::get_child(const Glib::RefPtr<FileInfo>& info) const -> Glib::RefPtr<const File>
{
  return Glib::wrap(g_file_enumerator_get_child(const_cast<GFileEnumerator*>(gobj()), Glib::unwrap(info)));
}


} // namespace Gio


