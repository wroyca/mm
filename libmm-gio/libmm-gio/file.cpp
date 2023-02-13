


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/file.hpp>
#include <mm/gio/private/file_p.hpp>


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

#include <mm/gio/mount.hpp>
#include <gio/gio.h>
#include <utility>
#include <mm/glib/error.hpp>
#include <mm/glib/exceptionhandler.hpp>
#include <mm/gio/slot_async.hpp>

namespace
{

using CopySlots = std::pair<Gio::File::SlotFileProgress*, Gio::SlotAsyncReady*>;
using MeasureSlots = std::pair<Gio::File::SlotFileMeasureProgress*, Gio::SlotAsyncReady*>;
using LoadPartialSlots = std::pair<Gio::File::SlotReadMore*, Gio::SlotAsyncReady*>;

auto SignalProxy_file_progress_callback (
  const goffset current_num_bytes, const goffset total_num_bytes, const gpointer data) -> void
{
  const auto the_slot = static_cast<Gio::File::SlotFileProgress*>(data);

  try
  {

    (*the_slot)(current_num_bytes, total_num_bytes);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
}

// Same as SignalProxy_async_callback, except that this one knows that
// the slot is packed in a pair. The operation is assumed to be finished
// after the callback is triggered, so we delete that pair here.
auto SignalProxy_file_copy_async_callback (GObject *, GAsyncResult *res, void *data) -> void
{
  const auto slot_pair = static_cast<CopySlots*>(data);
  const auto the_slot = slot_pair->second;

  try
  {
    if (*the_slot)
    {
      auto result = Glib::wrap(res, true /* take copy */);
      (*the_slot)(result);
    }
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }

  delete the_slot;
  delete slot_pair->first; // progress slot
  delete slot_pair;
}

// Same as SignalProxy_async_callback, except that this one knows that
// the slot is packed in a pair. The operation is assumed to be finished
// after the callback is triggered, so we delete that pair here.
auto SignalProxy_file_measure_async_callback (GObject *, GAsyncResult *res, void *data) -> void
{
  const auto slot_pair = static_cast<MeasureSlots*>(data);
  const auto the_slot = slot_pair->second;

  try
  {
    if (*the_slot)
    {
      auto result = Glib::wrap(res, true /* take copy */);
      (*the_slot)(result);
    }
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }

  delete the_slot;
  delete slot_pair->first; // progress slot
  delete slot_pair;
}

auto
SignalProxy_load_partial_contents_read_more_callback(
  const char* file_contents, const goffset file_size, const gpointer data) -> gboolean
{
  const auto slot_pair = static_cast<LoadPartialSlots*>(data);
  const auto the_slot = slot_pair->first;

  bool result = false;

  try
  {

    result = (*the_slot)(file_contents, file_size);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }

  return result;
}

// Same as SignalProxy_async_callback, except that this one knows that
// the slot is packed in a pair. The operation is assumed to be finished
// after the callback is triggered, so we delete that pair here.
auto SignalProxy_load_partial_contents_ready_callback (
  GObject *, GAsyncResult *res, void *data) -> void
{
  const LoadPartialSlots* slot_pair = static_cast<LoadPartialSlots*>(data);
  const Gio::SlotAsyncReady* the_slot = slot_pair->second;

  try
  {
    auto result = Glib::wrap(res, true /* take copy */);
    (*the_slot)(result);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }

  delete the_slot;
  delete slot_pair->first; // read_more slot
  delete slot_pair;
}

auto SignalProxy_file_measure_progress_callback (
  const gboolean reporting, const guint64 current_size, const guint64 num_dirs, const guint64 num_files, const gpointer data) -> void
{
  const Gio::File::SlotFileMeasureProgress* the_slot =
    static_cast<Gio::File::SlotFileMeasureProgress*>(data);

  try
  {

    (*the_slot)(reporting, current_size, num_dirs, num_files);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
}

} // anonymous namespace

namespace Gio
{

auto
File::create_for_path(const std::string& path) -> Glib::RefPtr<File>
{
  GFile* cfile = g_file_new_for_path(path.c_str());
  return Glib::wrap(G_FILE(cfile));
}

auto
File::create_for_uri(const std::string& uri) -> Glib::RefPtr<File>
{
  GFile* cfile = g_file_new_for_uri(uri.c_str());
  return Glib::wrap(G_FILE(cfile));
}

auto
File::create_for_commandline_arg(const std::string& arg) -> Glib::RefPtr<File>
{
  GFile* cfile = g_file_new_for_commandline_arg(arg.c_str());
  return Glib::wrap(G_FILE(cfile));
}

auto
File::create_tmp(const std::string& tmpl) -> std::pair<Glib::RefPtr<File>, Glib::RefPtr<FileIOStream>>
{
  GError* gerror = nullptr;
  GFileIOStream* ciostream = nullptr;
  GFile* cfile = g_file_new_tmp(tmpl.empty() ? nullptr : tmpl.c_str(), &ciostream, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return {Glib::wrap(cfile), Glib::wrap(ciostream)};
}

auto
File::create_for_parse_name(const Glib::ustring& parse_name) -> Glib::RefPtr<File>
{
  GFile* cfile = g_file_parse_name(parse_name.c_str());
  return Glib::wrap(G_FILE(cfile));
}

auto File::read_async (const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_read_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::read_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_read_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::append_to_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_append_to_async(gobj(), static_cast<GFileCreateFlags>(flags), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::append_to_async (const SlotAsyncReady &slot, CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_append_to_async(gobj(), static_cast<GFileCreateFlags>(flags), io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto File::create_file_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_create_async(gobj(), static_cast<GFileCreateFlags>(flags), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::create_file_async (
  const SlotAsyncReady &slot, CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_create_async(gobj(), static_cast<GFileCreateFlags>(flags), io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto File::create_file_readwrite_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_create_async(gobj(), static_cast<GFileCreateFlags>(flags), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::create_file_readwrite_async (
  const SlotAsyncReady &slot, CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_create_readwrite_async(gobj(), static_cast<GFileCreateFlags>(flags), io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto File::replace_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  const std::string &etag, const bool make_backup, CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_async(gobj(), Glib::c_str_or_nullptr(etag), make_backup,
    static_cast<GFileCreateFlags>(flags), io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto File::replace_async (
  const SlotAsyncReady &slot, const std::string &etag, const bool make_backup,
  CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_async(gobj(), Glib::c_str_or_nullptr(etag), make_backup,
    static_cast<GFileCreateFlags>(flags), io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto File::open_readwrite_async (const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_open_readwrite_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::open_readwrite_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_open_readwrite_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::replace_readwrite_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const std::string &etag, const bool make_backup,
  CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_readwrite_async(gobj(), Glib::c_str_or_nullptr(etag), make_backup,
    static_cast<GFileCreateFlags>(flags), io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto File::replace_readwrite_async (
  const SlotAsyncReady &slot, const std::string &etag, const bool make_backup,
  CreateFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_readwrite_async(gobj(), Glib::c_str_or_nullptr(etag), make_backup,
    static_cast<GFileCreateFlags>(flags), io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto
File::query_file_type(FileQueryInfoFlags flags) const -> FileType
{
  return (FileType)g_file_query_file_type(
    const_cast<GFile*>(gobj()), (GFileQueryInfoFlags)flags, nullptr);
}

auto
File::query_info(const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes,
  FileQueryInfoFlags flags) const -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_info(const_cast<GFile*>(gobj()), attributes.c_str(),
    (GFileQueryInfoFlags)flags, Glib::unwrap(cancellable),
    &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::query_info(const std::string& attributes, FileQueryInfoFlags flags) const -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_info(const_cast<GFile*>(gobj()), attributes.c_str(),
    (GFileQueryInfoFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto File::query_info_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  const std::string &attributes, FileQueryInfoFlags flags, const int io_priority) const -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_query_info_async(const_cast<GFile*>(gobj()), attributes.c_str(),
    static_cast<GFileQueryInfoFlags>(flags), io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto File::query_info_async (
  const SlotAsyncReady &slot, const std::string &attributes,
  FileQueryInfoFlags flags, const int io_priority) const -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_query_info_async(const_cast<GFile*>(gobj()), attributes.c_str(),
    static_cast<GFileQueryInfoFlags>(flags), io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto
File::query_filesystem_info(
  const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_filesystem_info(
    gobj(), attributes.c_str(), Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::query_filesystem_info(const std::string& attributes) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue =
    Glib::wrap(g_file_query_filesystem_info(gobj(), attributes.c_str(), nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto File::query_filesystem_info_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const std::string &attributes, const int io_priority) const -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_query_filesystem_info_async(const_cast<GFile*>(gobj()), attributes.c_str(), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::query_filesystem_info_async (
  const SlotAsyncReady &slot, const std::string &attributes, const int io_priority) const -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_query_filesystem_info_async(const_cast<GFile*>(gobj()), attributes.c_str(), io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto
File::enumerate_children(const Glib::RefPtr<Cancellable>& cancellable,
  const std::string& attributes, FileQueryInfoFlags flags) -> Glib::RefPtr<FileEnumerator>
{
  GError* gerror = nullptr;
  auto retvalue =
    Glib::wrap(g_file_enumerate_children(gobj(), attributes.c_str(), (GFileQueryInfoFlags)flags,
      Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::enumerate_children(const std::string& attributes, FileQueryInfoFlags flags) -> Glib::RefPtr<FileEnumerator>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_enumerate_children(
    gobj(), attributes.c_str(), (GFileQueryInfoFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto File::enumerate_children_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const std::string &attributes,
  FileQueryInfoFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_enumerate_children_async(gobj(), attributes.c_str(),
    static_cast<GFileQueryInfoFlags>(flags), io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto File::enumerate_children_async (
  const SlotAsyncReady &slot, const std::string &attributes,
  FileQueryInfoFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_enumerate_children_async(gobj(), attributes.c_str(),
    static_cast<GFileQueryInfoFlags>(flags), io_priority, nullptr, &SignalProxy_async_callback,
    slot_copy);
}

auto File::set_display_name_async (
  const Glib::ustring &display_name, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_set_display_name_async(gobj(), display_name.c_str(), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::set_display_name_async (
  const Glib::ustring &display_name, const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_set_display_name_async(
    gobj(), display_name.c_str(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto
File::copy(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot,
  const Glib::RefPtr<Cancellable>& cancellable, CopyFlags flags) -> bool
{
  GError* gerror = nullptr;
  bool res;

  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter.
  SlotFileProgress* slot_copy = new SlotFileProgress(slot);

  res = g_file_copy(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    Glib::unwrap(cancellable), &SignalProxy_file_progress_callback, slot_copy, &gerror);

  delete slot_copy;

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return res;
}

auto
File::copy(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot, CopyFlags flags) -> bool
{
  GError* gerror = nullptr;
  bool res;

  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter.
  SlotFileProgress* slot_copy = new SlotFileProgress(slot);

  res = g_file_copy(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags), nullptr,
    &SignalProxy_file_progress_callback, slot_copy, &gerror);

  delete slot_copy;

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return res;
}

auto
File::copy(const Glib::RefPtr<File>& destination, CopyFlags flags) -> bool
{
  GError* gerror = nullptr;
  const bool res = g_file_copy(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
                               nullptr, nullptr, nullptr, &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return res;
}

auto File::copy_async (
  const Glib::RefPtr <File> &destination, const SlotFileProgress &slot_progress,
  const SlotAsyncReady &slot_ready, const Glib::RefPtr <Cancellable> &cancellable,
  CopyFlags flags, const int io_priority) -> void
{
  // Create a new pair which will hold copies of passed slots.
  // This will be deleted in the SignalProxy_file_copy_async_callback() callback.
  CopySlots* slots = new CopySlots();
  SlotFileProgress* slot_progress_copy = new SlotFileProgress(slot_progress);
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  slots->first = slot_progress_copy;
  slots->second = slot_ready_copy;

  g_file_copy_async(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    io_priority, Glib::unwrap(cancellable), &SignalProxy_file_progress_callback, slot_progress_copy,
    &SignalProxy_file_copy_async_callback, slots);
}

auto File::copy_async (
  const Glib::RefPtr <File> &destination, const SlotAsyncReady &slot_ready,
  const Glib::RefPtr <Cancellable> &cancellable, CopyFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_copy_async(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    io_priority, Glib::unwrap(cancellable), nullptr, nullptr, &SignalProxy_async_callback,
    slot_ready_copy);
}

auto File::copy_async (
  const Glib::RefPtr <File> &destination, const SlotFileProgress &slot_progress,
  const SlotAsyncReady &slot_ready, CopyFlags flags, const int io_priority) -> void
{
  // Create a new pair which will hold copies of passed slots.
  // This will be deleted in the SignalProxy_file_copy_async_callback() callback.
  CopySlots* slots = new CopySlots();
  SlotFileProgress* slot_progress_copy = new SlotFileProgress(slot_progress);
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  slots->first = slot_progress_copy;
  slots->second = slot_ready_copy;

  g_file_copy_async(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    io_priority, nullptr, &SignalProxy_file_progress_callback, slot_progress_copy,
    &SignalProxy_file_copy_async_callback, slots);
}

auto File::copy_async (
  const Glib::RefPtr <File> &destination, const SlotAsyncReady &slot_ready,
  CopyFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_copy_async(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    io_priority, nullptr, nullptr, nullptr, &SignalProxy_async_callback, slot_ready_copy);
}

auto
File::move(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot,
  const Glib::RefPtr<Cancellable>& cancellable, CopyFlags flags) -> bool
{
  GError* gerror = nullptr;
  bool res;

  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter.
  SlotFileProgress* slot_copy = new SlotFileProgress(slot);

  res = g_file_move(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    Glib::unwrap(cancellable), &SignalProxy_file_progress_callback, slot_copy, &gerror);

  delete slot_copy;

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return res;
}

auto
File::move(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot, CopyFlags flags) -> bool
{
  GError* gerror = nullptr;
  bool res;

  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter.
  SlotFileProgress* slot_copy = new SlotFileProgress(slot);

  res = g_file_move(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags), nullptr,
    &SignalProxy_file_progress_callback, slot_copy, &gerror);

  delete slot_copy;

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return res;
}

auto
File::move(const Glib::RefPtr<File>& destination, CopyFlags flags) -> bool
{
  GError* gerror = nullptr;
  bool res;

  res = g_file_move(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags), nullptr,
    nullptr, nullptr, &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return res;
}

auto File::move_async (
  const Glib::RefPtr <File> &destination, const SlotFileProgress &slot_progress,
  const SlotAsyncReady &slot_ready, const Glib::RefPtr <Cancellable> &cancellable,
  CopyFlags flags, const int io_priority) -> void
{
  // Create a new pair which will hold copies of passed slots.
  // This will be deleted in the SignalProxy_file_copy_async_callback() callback.
  CopySlots* slots = new CopySlots();
  SlotFileProgress* slot_progress_copy = new SlotFileProgress(slot_progress);
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  slots->first = slot_progress_copy;
  slots->second = slot_ready_copy;

  g_file_move_async(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    io_priority, Glib::unwrap(cancellable), &SignalProxy_file_progress_callback, slot_progress_copy,
    &SignalProxy_file_copy_async_callback, slots);
}

auto File::move_async (
  const Glib::RefPtr <File> &destination, const SlotAsyncReady &slot_ready,
  const Glib::RefPtr <Cancellable> &cancellable, CopyFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_move_async(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    io_priority, Glib::unwrap(cancellable), nullptr, nullptr, &SignalProxy_async_callback,
    slot_ready_copy);
}

auto File::move_async (
  const Glib::RefPtr <File> &destination, const SlotFileProgress &slot_progress,
  const SlotAsyncReady &slot_ready, CopyFlags flags, const int io_priority) -> void
{
  // Create a new pair which will hold copies of passed slots.
  // This will be deleted in the SignalProxy_file_copy_async_callback() callback.
  CopySlots* slots = new CopySlots();
  SlotFileProgress* slot_progress_copy = new SlotFileProgress(slot_progress);
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  slots->first = slot_progress_copy;
  slots->second = slot_ready_copy;

  g_file_move_async(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    io_priority, nullptr, &SignalProxy_file_progress_callback, slot_progress_copy,
    &SignalProxy_file_copy_async_callback, slots);
}

auto File::move_async (
  const Glib::RefPtr <File> &destination, const SlotAsyncReady &slot_ready,
  CopyFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_move_async(gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags),
    io_priority, nullptr, nullptr, nullptr, &SignalProxy_async_callback, slot_ready_copy);
}
auto File::set_attributes_async (
  const Glib::RefPtr <FileInfo> &info, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, FileQueryInfoFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_set_attributes_async(gobj(), Glib::unwrap(info), static_cast<GFileQueryInfoFlags>(flags),
    io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::set_attributes_async (
  const Glib::RefPtr <FileInfo> &info, const SlotAsyncReady &slot,
  FileQueryInfoFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_set_attributes_async(gobj(), Glib::unwrap(info), static_cast<GFileQueryInfoFlags>(flags),
    io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto
File::set_attributes_finish(
  const Glib::RefPtr<AsyncResult>& result, const Glib::RefPtr<FileInfo>& info) -> bool
{
  GError* gerror = nullptr;
  GFileInfo* cinfo = Glib::unwrap(info);
  bool res;

  res = g_file_set_attributes_finish(gobj(), Glib::unwrap(result), &cinfo, &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return res;
}

auto File::mount_mountable (
  const Glib::RefPtr <MountOperation> &mount_operation,
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  Mount::MountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_mount_mountable(gobj(), static_cast<GMountMountFlags>(flags),
    Glib::unwrap(mount_operation), Glib::unwrap(cancellable), &SignalProxy_async_callback,
    slot_copy);
}

auto File::mount_mountable (
  const Glib::RefPtr <MountOperation> &mount_operation,
  const SlotAsyncReady &slot, Mount::MountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_mount_mountable(gobj(), static_cast<GMountMountFlags>(flags),
    Glib::unwrap(mount_operation), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::mount_mountable (const SlotAsyncReady &slot, Mount::MountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_mount_mountable(gobj(), static_cast<GMountMountFlags>(flags), nullptr, nullptr,
    &SignalProxy_async_callback, slot_copy);
}

auto File::mount_mountable (Mount::MountFlags flags) -> void
{
  g_file_mount_mountable(
    gobj(), static_cast<GMountMountFlags>(flags), nullptr, nullptr, nullptr, nullptr);
}

auto File::unmount_mountable (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_unmount_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags), nullptr,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::unmount_mountable (const SlotAsyncReady &slot, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_unmount_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags), nullptr,
    nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::unmount_mountable (Mount::UnmountFlags flags) -> void
{
  g_file_unmount_mountable_with_operation(
    gobj(), static_cast<GMountUnmountFlags>(flags), nullptr, nullptr, nullptr, nullptr);
}

auto File::unmount_mountable (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  const Glib::RefPtr <MountOperation> &mount_operation, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_unmount_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    Glib::unwrap(mount_operation), Glib::unwrap(cancellable), &SignalProxy_async_callback,
    slot_copy);
}

auto File::unmount_mountable (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <MountOperation> &mount_operation, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_unmount_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    Glib::unwrap(mount_operation), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::unmount_mountable (
  const Glib::RefPtr <MountOperation> &mount_operation, Mount::UnmountFlags flags) -> void
{
  g_file_unmount_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    Glib::unwrap(mount_operation), nullptr, nullptr, nullptr);
}

auto File::mount_enclosing_volume (
  const Glib::RefPtr <MountOperation> &mount_operation,
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  Mount::MountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_mount_enclosing_volume(gobj(), static_cast<GMountMountFlags>(flags),
    Glib::unwrap(mount_operation), Glib::unwrap(cancellable), &SignalProxy_async_callback,
    slot_copy);
}

auto File::mount_enclosing_volume (
  const Glib::RefPtr <MountOperation> &mount_operation,
  const SlotAsyncReady &slot, Mount::MountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_mount_enclosing_volume(gobj(), static_cast<GMountMountFlags>(flags),
    Glib::unwrap(mount_operation), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::mount_enclosing_volume (const SlotAsyncReady &slot, Mount::MountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_mount_enclosing_volume(gobj(), static_cast<GMountMountFlags>(flags), nullptr, nullptr,
    &SignalProxy_async_callback, slot_copy);
}

auto File::mount_enclosing_volume (Mount::MountFlags flags) -> void
{
  g_file_mount_enclosing_volume(
    gobj(), static_cast<GMountMountFlags>(flags), nullptr, nullptr, nullptr, nullptr);
}

auto File::eject_mountable (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  const Glib::RefPtr <MountOperation> &mount_operation, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_eject_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    Glib::unwrap(mount_operation), Glib::unwrap(cancellable), &SignalProxy_async_callback,
    slot_copy);
}

auto File::eject_mountable (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <MountOperation> &mount_operation, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_eject_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    Glib::unwrap(mount_operation), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::eject_mountable (
  const Glib::RefPtr <MountOperation> &mount_operation, Mount::UnmountFlags flags) -> void
{
  g_file_eject_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    Glib::unwrap(mount_operation), nullptr, nullptr, nullptr);
}

auto File::eject_mountable (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_eject_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags), nullptr,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::eject_mountable (const SlotAsyncReady &slot, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_eject_mountable_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags), nullptr,
    nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::eject_mountable (Mount::UnmountFlags flags) -> void
{
  g_file_eject_mountable_with_operation(
    gobj(), static_cast<GMountUnmountFlags>(flags), nullptr, nullptr, nullptr, nullptr);
}

auto File::load_contents_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_load_contents_async(
    gobj(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::load_contents_async (const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_load_contents_async(gobj(), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::load_partial_contents_async (
  const SlotReadMore &slot_read_more,
  const SlotAsyncReady &slot_async_ready, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  // Create a new pair which will hold copies of passed slots.
  // This will be deleted in the SignalProxy_load_partial_contents_ready_callback() callback
  LoadPartialSlots* slots = new LoadPartialSlots();
  SlotReadMore* slot_read_more_copy = new SlotReadMore(slot_read_more);
  SlotAsyncReady* slot_async_copy = new SlotAsyncReady(slot_async_ready);

  slots->first = slot_read_more_copy;
  slots->second = slot_async_copy;

  g_file_load_partial_contents_async(gobj(), Glib::unwrap(cancellable),
    &SignalProxy_load_partial_contents_read_more_callback,
    &SignalProxy_load_partial_contents_ready_callback, slots);
}

auto File::load_partial_contents_async (
  const SlotReadMore &slot_read_more, const SlotAsyncReady &slot_async_ready) -> void
{
  // Create a new pair which will hold copies of passed slots.
  // This will be deleted in the SignalProxy_load_partial_contents_ready_callback() callback
  LoadPartialSlots* slots = new LoadPartialSlots();
  SlotReadMore* slot_read_more_copy = new SlotReadMore(slot_read_more);
  SlotAsyncReady* slot_async_copy = new SlotAsyncReady(slot_async_ready);

  slots->first = slot_read_more_copy;
  slots->second = slot_async_copy;

  g_file_load_partial_contents_async(gobj(), nullptr,
    &SignalProxy_load_partial_contents_read_more_callback,
    &SignalProxy_load_partial_contents_ready_callback, slots);
}

auto File::replace_contents (
  const char *contents, const gsize length, const std::string &etag,
  std::string &new_etag, const Glib::RefPtr <Cancellable> &cancellable, const bool make_backup,
  CreateFlags flags) -> void
{
  GError* gerror = nullptr;
  gchar* c_etag_new = nullptr;
  g_file_replace_contents(gobj(), contents, length, Glib::c_str_or_nullptr(etag),
    make_backup, (GFileCreateFlags)flags, &c_etag_new,
    Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  if (c_etag_new)
    new_etag = c_etag_new;
  else
    new_etag = std::string();
}

auto File::replace_contents (
  const char *contents, const gsize length, const std::string &etag,
  std::string &new_etag, const bool make_backup, CreateFlags flags) -> void
{
  GError* gerror = nullptr;
  gchar* c_etag_new = nullptr;
  g_file_replace_contents(gobj(), contents, length, Glib::c_str_or_nullptr(etag),
    make_backup, (GFileCreateFlags)flags, &c_etag_new, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  if (c_etag_new)
    new_etag = c_etag_new;
  else
    new_etag = std::string();
}

auto File::replace_contents (
  const std::string &contents, const std::string &etag, std::string &new_etag,
  const Glib::RefPtr <Cancellable> &cancellable, const bool make_backup, CreateFlags flags) -> void
{
  GError* gerror = nullptr;
  gchar* c_etag_new = nullptr;
  g_file_replace_contents(gobj(), contents.c_str(), contents.size(), Glib::c_str_or_nullptr(etag),
    make_backup, (GFileCreateFlags)flags, &c_etag_new,
    Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  if (c_etag_new)
    new_etag = c_etag_new;
  else
    new_etag = std::string();
}

auto File::replace_contents (
  const std::string &contents, const std::string &etag, std::string &new_etag, const bool make_backup, CreateFlags flags) -> void
{
  GError* gerror = nullptr;
  gchar* c_etag_new = nullptr;
  g_file_replace_contents(gobj(), contents.c_str(), contents.size(), Glib::c_str_or_nullptr(etag),
    make_backup, (GFileCreateFlags)flags, &c_etag_new, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  if (c_etag_new)
    new_etag = c_etag_new;
  else
    new_etag = std::string();
}

auto File::replace_contents_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const char *contents, const gsize length,
  const std::string &etag, const bool make_backup, CreateFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_contents_async(gobj(), contents, length, Glib::c_str_or_nullptr(etag), make_backup,
    static_cast<GFileCreateFlags>(flags), Glib::unwrap(cancellable), &SignalProxy_async_callback,
    slot_copy);
}

auto File::replace_contents_async (
  const SlotAsyncReady &slot, const char *contents, const gsize length,
  const std::string &etag, const bool make_backup, CreateFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_contents_async(gobj(), contents, length, Glib::c_str_or_nullptr(etag), make_backup,
    static_cast<GFileCreateFlags>(flags), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::replace_contents_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const std::string &contents,
  const std::string &etag, const bool make_backup, CreateFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_contents_async(gobj(), contents.c_str(), contents.size(),
    Glib::c_str_or_nullptr(etag), make_backup, static_cast<GFileCreateFlags>(flags),
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::replace_contents_async (
  const SlotAsyncReady &slot, const std::string &contents,
  const std::string &etag, const bool make_backup, CreateFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_contents_async(gobj(), contents.c_str(), contents.size(),
    Glib::c_str_or_nullptr(etag), make_backup, static_cast<GFileCreateFlags>(flags), nullptr,
    &SignalProxy_async_callback, slot_copy);
}

auto File::replace_contents_finish (
  const Glib::RefPtr <AsyncResult> &result, std::string &new_etag) -> void
{
  GError* gerror = nullptr;
  gchar* c_new_etag = nullptr;
  g_file_replace_contents_finish(gobj(), Glib::unwrap(result), &c_new_etag, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  if (c_new_etag)
    new_etag = c_new_etag;
  else
    new_etag = std::string();
}

auto File::replace_contents_finish (const Glib::RefPtr <AsyncResult> &result) -> void
{
  GError* gerror = nullptr;
  g_file_replace_contents_finish(gobj(), Glib::unwrap(result), nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
}

auto File::replace_contents_bytes_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const Glib::RefPtr <const Glib::Bytes> &contents,
  const std::string &etag, const bool make_backup, CreateFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_contents_bytes_async(gobj(), const_cast<GBytes*>(unwrap(contents)),
    Glib::c_str_or_nullptr(etag), make_backup, static_cast<GFileCreateFlags>(flags),
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::replace_contents_bytes_async (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <const Glib::Bytes> &contents, const std::string &etag, const bool make_backup,
  CreateFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_replace_contents_bytes_async(gobj(), const_cast<GBytes*>(unwrap(contents)),
    Glib::c_str_or_nullptr(etag), make_backup, static_cast<GFileCreateFlags>(flags), nullptr,
    &SignalProxy_async_callback, slot_copy);
}

auto
File::replace(const Glib::RefPtr<Cancellable>& cancellable, const std::string& etag, const bool make_backup, CreateFlags flags) -> Glib::RefPtr<FileOutputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_replace(gobj(), Glib::c_str_or_nullptr(etag),
    make_backup, (GFileCreateFlags)flags,
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::replace(const std::string& etag, const bool make_backup, CreateFlags flags) -> Glib::RefPtr<FileOutputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_replace(gobj(), Glib::c_str_or_nullptr(etag),
    make_backup, (GFileCreateFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::replace_readwrite(const Glib::RefPtr<Cancellable>& cancellable, const std::string& etag, const bool make_backup, CreateFlags flags) -> Glib::RefPtr<FileIOStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_replace_readwrite(gobj(), Glib::c_str_or_nullptr(etag),
    make_backup, (GFileCreateFlags)flags,
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::replace_readwrite(const std::string& etag, const bool make_backup, CreateFlags flags) -> Glib::RefPtr<FileIOStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_replace_readwrite(gobj(), Glib::c_str_or_nullptr(etag),
    make_backup, (GFileCreateFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::monitor_directory(const Glib::RefPtr<Cancellable>& cancellable, FileMonitorFlags flags) -> Glib::RefPtr<FileMonitor>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_monitor_directory(gobj(), (GFileMonitorFlags)flags,
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::monitor_directory(FileMonitorFlags flags) -> Glib::RefPtr<FileMonitor>
{
  GError* gerror = nullptr;
  auto retvalue =
    Glib::wrap(g_file_monitor_directory(gobj(), (GFileMonitorFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::monitor_file(const Glib::RefPtr<Cancellable>& cancellable, FileMonitorFlags flags) -> Glib::RefPtr<FileMonitor>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_monitor_file(gobj(), (GFileMonitorFlags)flags,
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::monitor_file(FileMonitorFlags flags) -> Glib::RefPtr<FileMonitor>
{
  GError* gerror = nullptr;
  auto retvalue =
    Glib::wrap(g_file_monitor_file(gobj(), (GFileMonitorFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::monitor(const Glib::RefPtr<Cancellable>& cancellable, FileMonitorFlags flags) -> Glib::RefPtr<FileMonitor>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_monitor(gobj(), (GFileMonitorFlags)flags,
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::monitor(FileMonitorFlags flags) -> Glib::RefPtr<FileMonitor>
{
  GError* gerror = nullptr;
  auto retvalue =
    Glib::wrap(g_file_monitor(gobj(), (GFileMonitorFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto File::measure_disk_usage (
  const Glib::RefPtr <Cancellable> &cancellable,
  const SlotFileMeasureProgress &slot_progress, guint64 &disk_usage, guint64 &num_dirs,
  guint64 &num_files, MeasureFlags flags) -> void
{
  GError* gerror = nullptr;
  g_file_measure_disk_usage(gobj(), (GFileMeasureFlags)flags,
    Glib::unwrap(cancellable),
    &SignalProxy_file_measure_progress_callback,
    const_cast<SlotFileMeasureProgress*>(&slot_progress), &disk_usage, &num_dirs, &num_files,
    &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
}

auto File::measure_disk_usage_async (
  const SlotAsyncReady &slot_ready,
  const Glib::RefPtr <Cancellable> &cancellable, const SlotFileMeasureProgress &slot_progress,
  MeasureFlags flags, const int io_priority) -> void
{
  // Create a new pair which will hold copies of passed slots.
  // This will be deleted in the SignalProxy_file_measure_async_callback() callback
  MeasureSlots* slots = new MeasureSlots();
  SlotFileMeasureProgress* slot_progress_copy = new SlotFileMeasureProgress(slot_progress);
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  slots->first = slot_progress_copy;
  slots->second = slot_ready_copy;

  g_file_measure_disk_usage_async(gobj(), (GFileMeasureFlags)flags, io_priority,
    Glib::unwrap(cancellable),
    &SignalProxy_file_measure_progress_callback,
    const_cast<SlotFileMeasureProgress*>(&slot_progress), &SignalProxy_file_measure_async_callback,
    slots);
}

auto File::start_mountable (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  const Glib::RefPtr <MountOperation> &start_operation, Drive::StartFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_start_mountable(gobj(), (GDriveStartFlags)flags, Glib::unwrap(start_operation),
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::start_mountable (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <MountOperation> &start_operation, Drive::StartFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_start_mountable(gobj(), (GDriveStartFlags)flags, Glib::unwrap(start_operation),
    nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::stop_mountable (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  const Glib::RefPtr <MountOperation> &start_operation, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_stop_mountable(gobj(), (GMountUnmountFlags)flags, Glib::unwrap(start_operation),
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::stop_mountable (
  const SlotAsyncReady &slot,
  const Glib::RefPtr <MountOperation> &start_operation, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_stop_mountable(gobj(), (GMountUnmountFlags)flags, Glib::unwrap(start_operation),
    nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::poll_mountable (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_poll_mountable(gobj(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::poll_mountable (const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_poll_mountable(gobj(), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto File::find_enclosing_mount_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_find_enclosing_mount_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::find_enclosing_mount_async (const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_file_find_enclosing_mount_async(
    gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto
File::set_attributes_from_info(const Glib::RefPtr<FileInfo>& info,
  const Glib::RefPtr<Cancellable>& cancellable, FileQueryInfoFlags flags) -> bool
{
  GError* gerror = nullptr;
  const bool retvalue =
    g_file_set_attributes_from_info(gobj(), Glib::unwrap(info), (GFileQueryInfoFlags)flags,
      Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::set_attributes_from_info(const Glib::RefPtr<FileInfo>& info, FileQueryInfoFlags flags) -> bool
{
  GError* gerror = nullptr;
  const bool retvalue = g_file_set_attributes_from_info(
    gobj(), Glib::unwrap(info), (GFileQueryInfoFlags)flags, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::copy_attributes(const Glib::RefPtr<File>& destination,
  const Glib::RefPtr<Cancellable>& cancellable, CopyFlags flags) -> bool
{
  GError* gerror = nullptr;
  bool res;

  res = g_file_copy_attributes(gobj(), Glib::unwrap(destination),
    static_cast<GFileCopyFlags>(flags), Glib::unwrap(cancellable), &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return res;
}

auto
File::copy_attributes(const Glib::RefPtr<File>& destination, CopyFlags flags) -> bool
{
  GError* gerror = nullptr;
  bool res;

  res = g_file_copy_attributes(
    gobj(), Glib::unwrap(destination), static_cast<GFileCopyFlags>(flags), nullptr, &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return res;
}

auto
File::create_file(const Glib::RefPtr<Cancellable>& cancellable, CreateFlags flags) -> Glib::RefPtr<FileOutputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_create(gobj(), (GFileCreateFlags)flags,
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::create_file(CreateFlags flags) -> Glib::RefPtr<FileOutputStream>
{
  GError* gerror = nullptr;
  auto retvalue =
    Glib::wrap(g_file_create(gobj(), (GFileCreateFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::create_file_readwrite(const Glib::RefPtr<Cancellable>& cancellable, CreateFlags flags) -> Glib::RefPtr<FileIOStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_create_readwrite(gobj(), (GFileCreateFlags)flags,
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::create_file_readwrite(CreateFlags flags) -> Glib::RefPtr<FileIOStream>
{
  GError* gerror = nullptr;
  auto retvalue =
    Glib::wrap(g_file_create_readwrite(gobj(), (GFileCreateFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::append_to(const Glib::RefPtr<Cancellable>& cancellable, CreateFlags flags) -> Glib::RefPtr<FileOutputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_append_to(gobj(), (GFileCreateFlags)flags,
    Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::append_to(CreateFlags flags) -> Glib::RefPtr<FileOutputStream>
{
  GError* gerror = nullptr;
  auto retvalue =
    Glib::wrap(g_file_append_to(gobj(), (GFileCreateFlags)flags, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::load_contents(const Glib::RefPtr<Cancellable>& cancellable, char*& contents, gsize& length,
  std::string& etag_out) -> bool
{
  GError* gerror = nullptr;
  gchar* cetag_out = nullptr;
  const bool retvalue = g_file_load_contents(
    gobj(), Glib::unwrap(cancellable), &contents, &length, &cetag_out, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  etag_out = Glib::convert_return_gchar_ptr_to_stdstring(cetag_out);

  return retvalue;
}

auto
File::load_contents(const Glib::RefPtr<Cancellable>& cancellable, char*& contents, gsize& length) -> bool
{
  GError* gerror = nullptr;
  const bool retvalue = g_file_load_contents(
    gobj(), Glib::unwrap(cancellable), &contents, &length, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::load_contents(char*& contents, gsize& length, std::string& etag_out) -> bool
{
  GError* gerror = nullptr;
  gchar* cetag_out = nullptr;
  const bool retvalue =
    g_file_load_contents(gobj(), nullptr, &contents, &length, &cetag_out, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  etag_out = Glib::convert_return_gchar_ptr_to_stdstring(cetag_out);

  return retvalue;
}

auto
File::load_contents(char*& contents, gsize& length) -> bool
{
  GError* gerror = nullptr;
  const bool retvalue = g_file_load_contents(gobj(), nullptr, &contents, &length, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::load_contents_finish(
  const Glib::RefPtr<AsyncResult>& result, char*& contents, gsize& length, std::string& etag_out) -> bool
{
  GError* gerror = nullptr;
  gchar* cetag_out = nullptr;
  const bool retvalue = g_file_load_contents_finish(
    gobj(), Glib::unwrap(result), &contents, &length, &cetag_out, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  etag_out = Glib::convert_return_gchar_ptr_to_stdstring(cetag_out);

  return retvalue;
}

auto
File::load_contents_finish(const Glib::RefPtr<AsyncResult>& result, char*& contents, gsize& length) -> bool
{
  GError* gerror = nullptr;
  const bool retvalue = g_file_load_contents_finish(
    gobj(), Glib::unwrap(result), &contents, &length, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::load_partial_contents_finish(
  const Glib::RefPtr<AsyncResult>& result, char*& contents, gsize& length, std::string& etag_out) -> bool
{
  GError* gerror = nullptr;
  gchar* cetag_out = nullptr;
  const bool retvalue = g_file_load_partial_contents_finish(
    gobj(), Glib::unwrap(result), &contents, &length, &cetag_out, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  etag_out = Glib::convert_return_gchar_ptr_to_stdstring(cetag_out);

  return retvalue;
}

auto
File::load_partial_contents_finish(
  const Glib::RefPtr<AsyncResult>& result, char*& contents, gsize& length) -> bool
{
  GError* gerror = nullptr;
  const bool retvalue = g_file_load_partial_contents_finish(
    gobj(), Glib::unwrap(result), &contents, &length, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
File::has_parent() const -> bool
{
  return g_file_has_parent(const_cast<GFile*>(gobj()), nullptr);
}

auto File::remove_async (
  const SlotAsyncReady &slot_ready, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create copies of slots.
  // Pointers to them will be passed through the callbacks' data parameter
  // and deleted in the corresponding callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_delete_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_ready_copy);
}

auto File::remove_async (const SlotAsyncReady &slot_ready, const int io_priority) -> void
{
  // Create copies of slots.
  // Pointers to them will be passed through the callbacks' data parameter
  // and deleted in the corresponding callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_delete_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_ready_copy);
}

auto File::trash_async (
  const SlotAsyncReady &slot_ready, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create copies of slots.
  // Pointers to them will be passed through the callbacks' data parameter
  // and deleted in the corresponding callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_trash_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_ready_copy);
}

auto File::trash_async (const SlotAsyncReady &slot_ready, const int io_priority) -> void
{
  // Create copies of slots.
  // Pointers to them will be passed through the callbacks' data parameter
  // and deleted in the corresponding callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_trash_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_ready_copy);
}

auto File::make_directory_async (
  const SlotAsyncReady &slot_ready, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create copies of slots.
  // Pointers to them will be passed through the callbacks' data parameter
  // and deleted in the corresponding callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_make_directory_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_ready_copy);
}

auto File::make_directory_async (const SlotAsyncReady &slot_ready, const int io_priority) -> void
{
  // Create copies of slots.
  // Pointers to them will be passed through the callbacks' data parameter
  // and deleted in the corresponding callback.
  SlotAsyncReady* slot_ready_copy = new SlotAsyncReady(slot_ready);

  g_file_make_directory_async(
    gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_ready_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GFile* object, const bool take_copy) -> RefPtr<Gio::File>
{
  return Glib::make_refptr_for_instance<Gio::File>( Glib::wrap_auto_interface<Gio::File> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto File_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &File_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_file_get_type();
  }

  return *this;
}

auto File_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto File_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new File((GFile*)object);
}


/* The implementation: */

File::File()
: Interface(file_class_.init())
{}

File::File(GFile* castitem)
: Interface((GObject*)castitem)
{}

File::File(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

File::File(File&& src) noexcept
: Interface(std::move(src))
{}

auto File::operator=(File&& src) noexcept -> File&
{
  Interface::operator=(std::move(src));
  return *this;
}

File::~File() noexcept = default;

// static
auto File::add_interface (
  const GType gtype_implementer) -> void
{
  file_class_.init().add_interface(gtype_implementer);
}

File::CppClassType File::file_class_; // initialize static member

auto File::get_type() -> GType
{
  return file_class_.init().get_type();
}


auto File::get_base_type() -> GType
{
  return g_file_get_type();
}


auto File::dup() const -> Glib::RefPtr<File>
{
  return Glib::wrap(g_file_dup(const_cast<GFile*>(gobj())));
}

auto File::hash() const -> guint
{
  return g_file_hash(gobj());
}

auto File::equal(const Glib::RefPtr<const File>& other) const -> bool
{
  return g_file_equal(const_cast<GFile*>(gobj()), const_cast<GFile*>(Glib::unwrap<File>(other)));
}

auto File::get_basename() const -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_file_get_basename(const_cast<GFile*>(gobj())));
}

auto File::get_path() const -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_file_get_path(const_cast<GFile*>(gobj())));
}

auto File::get_uri() const -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_file_get_uri(const_cast<GFile*>(gobj())));
}

auto File::get_parse_name() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_file_get_parse_name(const_cast<GFile*>(gobj())));
}

auto File::get_parent() const -> Glib::RefPtr<File>
{
  return Glib::wrap(g_file_get_parent(const_cast<GFile*>(gobj())));
}

auto File::has_parent(const Glib::RefPtr<File>& parent) const -> bool
{
  return g_file_has_parent(const_cast<GFile*>(gobj()), Glib::unwrap(parent));
}

auto File::get_child(const std::string& name) const -> Glib::RefPtr<File>
{
  return Glib::wrap(g_file_get_child(const_cast<GFile*>(gobj()), name.c_str()));
}

auto File::get_child_for_display_name(const Glib::ustring& display_name) const -> Glib::RefPtr<File>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_get_child_for_display_name(const_cast<GFile*>(gobj()), display_name.c_str(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::has_prefix(const Glib::RefPtr<const File>& prefix) const -> bool
{
  return g_file_has_prefix(const_cast<GFile*>(gobj()), const_cast<GFile*>(Glib::unwrap<File>(prefix)));
}

auto File::get_relative_path(const Glib::RefPtr<const File>& descendant) const -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_file_get_relative_path(const_cast<GFile*>(gobj()), const_cast<GFile*>(Glib::unwrap<File>(descendant))));
}

auto File::resolve_relative_path(const std::string& relative_path) const -> Glib::RefPtr<File>
{
  return Glib::wrap(g_file_resolve_relative_path(const_cast<GFile*>(gobj()), relative_path.c_str()));
}

auto File::is_native() const -> bool
{
  return g_file_is_native(const_cast<GFile*>(gobj()));
}

auto File::has_uri_scheme(const std::string& uri_scheme) const -> bool
{
  return g_file_has_uri_scheme(const_cast<GFile*>(gobj()), uri_scheme.c_str());
}

auto File::get_uri_scheme() const -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_file_get_uri_scheme(const_cast<GFile*>(gobj())));
}

auto File::read(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<FileInputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_read(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::read() -> Glib::RefPtr<FileInputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_read(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::read_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileInputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_read_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::append_to_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileOutputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_append_to_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::create_file_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileOutputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_create_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::create_file_readwrite_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileIOStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_create_readwrite_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::replace_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileOutputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_replace_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::open_readwrite(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<FileIOStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_open_readwrite(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::open_readwrite() -> Glib::RefPtr<FileIOStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_open_readwrite(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::open_readwrite_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileIOStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_open_readwrite_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::replace_readwrite_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileIOStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_replace_readwrite_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::query_exists(const Glib::RefPtr<Cancellable>& cancellable) const -> bool
{
  return g_file_query_exists(const_cast<GFile*>(gobj()), Glib::unwrap(cancellable));
}

auto File::query_exists() const -> bool
{
  return g_file_query_exists(const_cast<GFile*>(gobj()), nullptr);
}

auto File::query_file_type(FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) const -> FileType
{
  return static_cast<FileType>(g_file_query_file_type(const_cast<GFile*>(gobj()), static_cast<GFileQueryInfoFlags>(flags), Glib::unwrap(cancellable)));
}

auto File::query_info_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_info_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::find_enclosing_mount(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Mount>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_find_enclosing_mount(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::find_enclosing_mount() -> Glib::RefPtr<Mount>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_find_enclosing_mount(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::query_filesystem_info_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_filesystem_info_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::find_enclosing_mount_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Mount>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_find_enclosing_mount_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::enumerate_children_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileEnumerator>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_enumerate_children_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_display_name(const Glib::ustring& display_name, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<File>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_set_display_name(gobj(), display_name.c_str(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_display_name(const Glib::ustring& display_name) -> Glib::RefPtr<File>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_set_display_name(gobj(), display_name.c_str(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_display_name_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<File>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_set_display_name_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::remove(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_delete(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::remove() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_delete(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::remove_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_delete_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::trash(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_trash(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::trash() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_trash(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::trash_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_trash_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::copy_finish(const Glib::RefPtr<AsyncResult>& res) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_copy_finish(gobj(), Glib::unwrap(res), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::move_finish(const Glib::RefPtr<AsyncResult>& res) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_move_finish(gobj(), Glib::unwrap(res), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::make_directory(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_make_directory(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::make_directory() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_make_directory(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::make_directory_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_make_directory_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::make_directory_with_parents(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_make_directory_with_parents(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::make_directory_with_parents() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_make_directory_with_parents(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::make_symbolic_link(const std::string& symlink_value, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_make_symbolic_link(gobj(), symlink_value.c_str(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::make_symbolic_link(const std::string& symlink_value) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_make_symbolic_link(gobj(), symlink_value.c_str(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::make_symbolic_link_async (
  const std::string &symlink_value, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_file_make_symbolic_link_async(gobj(), symlink_value.c_str(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto File::make_symbolic_link_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_make_symbolic_link_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::query_settable_attributes(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<FileAttributeInfoList>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_settable_attributes(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::query_settable_attributes() -> Glib::RefPtr<FileAttributeInfoList>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_settable_attributes(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::query_writable_namespaces(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<FileAttributeInfoList>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_writable_namespaces(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::query_writable_namespaces() -> Glib::RefPtr<FileAttributeInfoList>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_writable_namespaces(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_string(const std::string& attribute, const Glib::ustring& value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_string(gobj(), attribute.c_str(), value.c_str(), static_cast<GFileQueryInfoFlags>(flags), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_string(const std::string& attribute, const Glib::ustring& value, FileQueryInfoFlags flags) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_string(gobj(), attribute.c_str(), value.c_str(), static_cast<GFileQueryInfoFlags>(flags), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_byte_string(const std::string& attribute, const std::string& value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_byte_string(gobj(), attribute.c_str(), value.c_str(), static_cast<GFileQueryInfoFlags>(flags), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_byte_string(const std::string& attribute, const std::string& value, FileQueryInfoFlags flags) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_byte_string(gobj(), attribute.c_str(), value.c_str(), static_cast<GFileQueryInfoFlags>(flags), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_uint32(const std::string& attribute, const guint32 value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_uint32(gobj(), attribute.c_str(), value, static_cast<GFileQueryInfoFlags>(flags), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_uint32(const std::string& attribute, const guint32 value, FileQueryInfoFlags flags) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_uint32(gobj(), attribute.c_str(), value, static_cast<GFileQueryInfoFlags>(flags), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_int32(const std::string& attribute, const gint32 value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_int32(gobj(), attribute.c_str(), value, static_cast<GFileQueryInfoFlags>(flags), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_int32(const std::string& attribute, const gint32 value, FileQueryInfoFlags flags) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_int32(gobj(), attribute.c_str(), value, static_cast<GFileQueryInfoFlags>(flags), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_uint64(const std::string& attribute, const guint64 value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_uint64(gobj(), attribute.c_str(), value, static_cast<GFileQueryInfoFlags>(flags), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_uint64(const std::string& attribute, const guint64 value, FileQueryInfoFlags flags) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_uint64(gobj(), attribute.c_str(), value, static_cast<GFileQueryInfoFlags>(flags), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_int64(const std::string& attribute, const gint64 value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_int64(gobj(), attribute.c_str(), value, static_cast<GFileQueryInfoFlags>(flags), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::set_attribute_int64(const std::string& attribute, const gint64 value, FileQueryInfoFlags flags) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_set_attribute_int64(gobj(), attribute.c_str(), value, static_cast<GFileQueryInfoFlags>(flags), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::mount_enclosing_volume_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_mount_enclosing_volume_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::mount_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<File>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_mount_mountable_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::unmount_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_unmount_mountable_with_operation_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::eject_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_eject_mountable_with_operation_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::measure_disk_usage_finish(const Glib::RefPtr<AsyncResult>& result, guint64& disk_usage, guint64& num_dirs, guint64& num_files) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_measure_disk_usage_finish(gobj(), Glib::unwrap(result), &disk_usage, &num_dirs, &num_files, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::start_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_start_mountable_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::stop_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_stop_mountable_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::poll_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_file_poll_mountable_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::query_default_handler(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<AppInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_default_handler(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::query_default_handler() -> Glib::RefPtr<AppInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_query_default_handler(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto File::supports_thread_contexts() const -> bool
{
  return g_file_supports_thread_contexts(const_cast<GFile*>(gobj()));
}


} // namespace Gio


