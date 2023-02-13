
#ifndef _GIOMM_FILEOUTPUTSTREAM_H
#define _GIOMM_FILEOUTPUTSTREAM_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

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

#include <libmm-gio/outputstream.hpp>
#include <libmm-gio/seekable.hpp>
#include <libmm-gio/fileinfo.hpp>
#include <libmm-glib/object.hpp>
#include <libmm-glib/iochannel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileOutputStream = struct _GFileOutputStream;
using GFileOutputStreamClass = struct _GFileOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API FileOutputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{


/** FileOutputStream provides output streams that write their content to a file.
 *
 * FileOutputStream implements Seekable, which allows the output stream to jump
 * to arbitrary positions in the file and to truncate the file, provided the
 * file system of the file supports these operations.
 * Use the methods of the Seekable base class for seeking and positioning.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API FileOutputStream
: public OutputStream,
  public Seekable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileOutputStream;
  using CppClassType = FileOutputStream_Class;
  using BaseObjectType = GFileOutputStream;
  using BaseClassType = GFileOutputStreamClass;

  // noncopyable
  FileOutputStream(const FileOutputStream&) = delete;
  auto operator=(const FileOutputStream&) -> FileOutputStream& = delete;

private:  friend class FileOutputStream_Class;
  static CppClassType fileoutputstream_class_;

protected:
  explicit FileOutputStream(const Glib::ConstructParams& construct_params);
  explicit FileOutputStream(GFileOutputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileOutputStream(FileOutputStream&& src) noexcept;
  auto operator=(FileOutputStream&& src) noexcept -> FileOutputStream&;

  ~FileOutputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFileOutputStream*       { return reinterpret_cast<GFileOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFileOutputStream* { return reinterpret_cast<GFileOutputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GFileOutputStream*;

private:


public:

  /** Queries a file output stream for the given @a attributes .
   * This function blocks while querying the stream. For the asynchronous
   * version of this function, see query_info_async().
   * While the stream is blocked, the stream will set the pending flag
   * internally, and any other operations on the stream will throw a Gio::Error with
   * PENDING.
   *
   * Can fail if the stream was already closed (with a
   * CLOSED error), the stream has pending operations (with a PENDING error),
   * or if querying info is not supported for
   * the stream's interface (with a NOT_SUPPORTED error). In
   * all cases of failure, an empty RefPtr will be returned.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED may be thrown, and an empty RefPtr will
   * be returned.
   *
   * @param cancellable A Cancellable object.
   * @param attributes A file attribute query string.
   * @return A FileInfo for the stream, or an empty RefPtr on error.
   */
  auto query_info(const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*") -> Glib::RefPtr<FileInfo>;

  /** Queries a file output stream for the given @a attributes .
   * This function blocks while querying the stream. For the asynchronous
   * version of this function, see query_info_async().
   * While the stream is blocked, the stream will set the pending flag
   * internally, and any other operations on the stream will throw a Gio::Error with
   * PENDING.
   *
   * Can fail if the stream was already closed (with a CLOSED error),
   * the stream has pending operations (with an PENDING error),
   * or if querying info is not supported for
   * the stream's interface (with a NOT_SUPPORTED error). In
   * all cases of failure, an empty RefPtr will be returned.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED may be thrown, and an empty RefPtr will
   * be returned.
   *
   * @param attributes A file attribute query string.
   * @return A FileInfo for the stream, or an empty RefPtr on error.
   */
  auto query_info(const std::string& attributes = "*") -> Glib::RefPtr<FileInfo>;


  /** Queries the stream information asynchronously.
   * When the operation is finished @a slot will be called.
   * You can then call query_info_finish()
   * to get the result of the operation.
   *
   * For the synchronous version of this function,
   * see query_info().
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED may be thrown
   *
   * @param slot Callback to call when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @param attributes A file attribute query string.
   * @param io_priority The <io-priority of the request.
   */
  void query_info_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*", int io_priority = Glib::PRIORITY_DEFAULT);

  /** Queries the stream information asynchronously.
   * When the operation is finished @a slot will be called.
   * You can then call query_info_finish()
   * to get the result of the operation.
   *
   * For the synchronous version of this function,
   * see query_info().
   *
   * @param slot Callback to call when the request is satisfied.
   * @param attributes A file attribute query string.
   * @param io_priority The <io-priority of the request.
   */
  void query_info_async(const SlotAsyncReady& slot, const std::string& attributes = "*", int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finalizes the asynchronous query started
   * by g_file_output_stream_query_info_async().
   *
   * @param result A AsyncResult.
   * @return A FileInfo for the finished query.
   *
   * @throws Glib::Error
   */
  auto query_info_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<FileInfo>;


  /** Gets the entity tag for the file when it has been written.
   * This must be called after the stream has been written
   * and closed, as the etag can change while writing.
   *
   * @return The entity tag for the stream.
   */
  auto get_etag() const -> Glib::ustring;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::FileOutputStream
   */
  GIOMM_API
  auto wrap(GFileOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileOutputStream>;
}


#endif /* _GIOMM_FILEOUTPUTSTREAM_H */

