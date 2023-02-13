
#ifndef _GIOMM_FILEIOSTREAM_H
#define _GIOMM_FILEIOSTREAM_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gio/fileinfo.hxx>
#include <libmm-gio/iostream.hxx>
#include <libmm-gio/seekable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileIOStream = struct _GFileIOStream;
using GFileIOStreamClass = struct _GFileIOStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API FileIOStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** FileIOStream provides input streams that take their content from a file.
 *
 * FileInputStream implements Seekable, which allows the input stream to jump to arbitrary positions in the file,
 * provided the file system of the file allows it.
 * Use the methods of the Seekable base class for seeking and positioning.
 *
 * @ingroup Streams
 *
 * @newin{2,22}
 */

class GIOMM_API FileIOStream
: public Gio::IOStream,
    public Gio::Seekable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileIOStream;
  using CppClassType = FileIOStream_Class;
  using BaseObjectType = GFileIOStream;
  using BaseClassType = GFileIOStreamClass;

  // noncopyable
  FileIOStream(const FileIOStream&) = delete;
  auto operator=(const FileIOStream&) -> FileIOStream& = delete;

private:  friend class FileIOStream_Class;
  static CppClassType fileiostream_class_;

protected:
  explicit FileIOStream(const Glib::ConstructParams& construct_params);
  explicit FileIOStream(GFileIOStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileIOStream(FileIOStream&& src) noexcept;
  auto operator=(FileIOStream&& src) noexcept -> FileIOStream&;

  ~FileIOStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFileIOStream*       { return reinterpret_cast<GFileIOStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFileIOStream* { return reinterpret_cast<GFileIOStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GFileIOStream*;

private:


public:

  /** Queries a file input stream the given @a attributes. This function blocks
   * while querying the stream. For the asynchronous (non-blocking) version
   * of this function, see query_info_async(). While the
   * stream is blocked, the stream will set the pending flag internally, and
   * any other operations on the stream will throw a Gio::Error with PENDING.
   *
   * @param attributes A file attribute query string.
   * @param cancellable A Cancellable object.
   * @return A FileInfo, or an empty RefPtr on error.
   */
  auto query_info(const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*") -> Glib::RefPtr<FileInfo>;

  /** Queries a file input stream the given @a attributes. This function blocks
   * while querying the stream. For the asynchronous (non-blocking) version
   * of this function, see query_info_async(). While the
   * stream is blocked, the stream will set the pending flag internally, and
   * any other operations on the stream will throw a Gio::Error with PENDING.
   *
   * @param attributes A file attribute query string.
   * @return A FileInfo, or an empty RefPtr on error.
   */
  auto query_info(const std::string& attributes = "*") -> Glib::RefPtr<FileInfo>;


  /** Queries the stream information asynchronously. For the synchronous version of this function, see query_info().
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * When the operation is finished, @a slot will be called. You can then call query_info_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param attributes A file attribute query string.
   * @param io_priority The I/O priority of the request.
   */
  void query_info_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*", int io_priority = Glib::PRIORITY_DEFAULT);

  /** Queries the stream information asynchronously. For the synchronous version of this function, see query_info().
   *
   * When the operation is finished, @a slot will be called. You can then call query_info_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param attributes A file attribute query string.
   * @param io_priority The I/O priority of the request.
   */
  void query_info_async(const SlotAsyncReady& slot, const std::string& attributes = "*", int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finalizes the asynchronous query started
   * by g_file_io_stream_query_info_async().
   *
   * @newin{2,22}
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
   * @newin{2,22}
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
   * @relates Gio::FileIOStream
   */
  GIOMM_API
  auto wrap(GFileIOStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileIOStream>;
}


#endif /* _GIOMM_FILEIOSTREAM_H */

