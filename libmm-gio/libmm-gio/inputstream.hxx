
#ifndef _GIOMM_INPUTSTREAM_H
#define _GIOMM_INPUTSTREAM_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The giomm Development Team
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

#include <libmm-glib/object.hxx>
#include <libmm-glib/priorities.hxx>
#include <libmm-glib/bytes.hxx>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GInputStream = struct _GInputStream;
using GInputStreamClass = struct _GInputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API InputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

//TODO: Implement operator << and >> for streams?

/** Base class for implementing streaming input.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API InputStream : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = InputStream;
  using CppClassType = InputStream_Class;
  using BaseObjectType = GInputStream;
  using BaseClassType = GInputStreamClass;

  // noncopyable
  InputStream(const InputStream&) = delete;
  auto operator=(const InputStream&) -> InputStream& = delete;

private:  friend class InputStream_Class;
  static CppClassType inputstream_class_;

protected:
  explicit InputStream(const Glib::ConstructParams& construct_params);
  explicit InputStream(GInputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  InputStream(InputStream&& src) noexcept;
  auto operator=(InputStream&& src) noexcept -> InputStream&;

  ~InputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GInputStream*       { return reinterpret_cast<GInputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GInputStream* { return reinterpret_cast<GInputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GInputStream*;

private:


protected:
  InputStream();

public:

  /** Tries to read @a count bytes from the stream into the buffer starting at
   *  @a buffer. Will block during this read.
   *
   * If count is zero returns zero and does nothing. A value of @a count
   * larger than G_MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes read into the buffer is returned.
   * It is not an error if this is not the same as the requested size, as it
   * can happen e.g. near the end of a file. Zero is returned on end of file
   * (or if @a count is zero),  but never otherwise.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED. If an
   * operation was partially finished when the operation was cancelled the
   * partial result will be returned, without an error.
   *
   * @param buffer A buffer to read data into (which should be at least count bytes long).
   * @param count The number of bytes that will be read from the stream.
   * @param cancellable Cancellable object.
   * @return Number of bytes read, or -1 on error.
   *
   * @throws Glib::Error
   */
  auto read(void* buffer, gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// A read() convenience overload.
  auto read(void* buffer, gsize count) -> gssize;

  //TODO: for glibmm 2.17/18, we should decide whether to provide a read()
  // function as below, which would presumably read until EOL, or one with
  // an additional size parameter, at the same time taking into account
  // what operators >> and << (for OutputStream) will do.
  //TODO: gssize read(std::string& buffer, const Glib::RefPtr<Cancellable>& cancellable);
  //TODO: gssize read(std::string& buffer);


  /** Tries to read @a count bytes from the stream into the buffer starting at
   *  @a buffer. Will block during this read.
   *
   * This function is similar to g_input_stream_read(), except it tries to
   * read as many bytes as requested, only stopping on an error or end of stream.
   *
   * On a successful read of @a count bytes, or if we reached the end of the
   * stream,  <tt>true</tt> is returned, and @a bytes_read is set to the number of bytes
   * read into @a buffer.
   *
   * If there is an error during the operation <tt>false</tt> is returned and @a error
   * is set to indicate the error status.
   *
   * As a special exception to the normal conventions for functions that
   * use Error, if this function returns <tt>false</tt> (and sets @a error) then
   *  @a bytes_read will be set to the number of bytes that were successfully
   * read before the error was encountered.  This functionality is only
   * available from C.  If you need it from another language then you must
   * write your own loop around g_input_stream_read().
   *
   * @param buffer A buffer to read data into (which should be at least count bytes long).
   * @param count The number of bytes that will be read from the stream.
   * @param bytes_read Location to store the number of bytes that was read from the stream.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> on success, <tt>false</tt> if there was an error.
   *
   * @throws Glib::Error
   */
  auto read_all(void* buffer, gsize count, gsize& bytes_read, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A read_all() convenience overload.
  auto read_all(void* buffer, gsize count, gsize& bytes_read) -> bool;

  //TODO: bool read_all(std::string& buffer, gsize count, gsize& bytes_read, const Glib::RefPtr<Cancellable>& cancellable);
  //TODO: bool read_all(std::string& buffer, gsize count, gsize& bytes_read)


  /** Like g_input_stream_read(), this tries to read @a count bytes from
   * the stream in a blocking fashion. However, rather than reading into
   * a user-supplied buffer, this will create a new Bytes containing
   * the data that was read. This may be easier to use from language
   * bindings.
   *
   * If count is zero, returns a zero-length Bytes and does nothing. A
   * value of @a count larger than G_MAXSSIZE will cause a
   * Gio::Error::INVALID_ARGUMENT error.
   *
   * On success, a new Bytes is returned. It is not an error if the
   * size of this object is not the same as the requested size, as it
   * can happen e.g. near the end of a file. A zero-length Bytes is
   * returned on end of file (or if @a count is zero), but never
   * otherwise.
   *
   * If @a cancellable is not <tt>nullptr</tt>, then the operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, the error Gio::Error::CANCELLED will be returned. If an
   * operation was partially finished when the operation was cancelled the
   * partial result will be returned, without an error.
   *
   * On error <tt>nullptr</tt> is returned and @a error is set accordingly.
   *
   * @newin{2,34}
   *
   * @param count Maximum number of bytes that will be read from the stream. Common
   * values include 4096 and 8192.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return A new Bytes, or <tt>nullptr</tt> on error.
   *
   * @throws Glib::Error
   */
  auto read_bytes(gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Glib::Bytes>;

  //TODO: Why not use _WRAP_METHOD() for this?
  /** Request an asynchronous read of @a count bytes from the stream into a
   * new Glib::Bytes. When the operation is finished @a slot will be called.
   * You can then call read_bytes_finish() to get the result of the
   * operation.
   *
   * During an async request no other sync and async calls are allowed, and will
   * result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the new Glib::Bytes will be passed to the callback. It is
   * not an error if this is smaller than the requested size, as it can
   * happen e.g. near the end of a file, but generally we try to read as
   * many bytes as requested. Zero is returned on end of file (or if
   * @a count is zero), but never otherwise.
   *
   * Any outstanding I/O request with higher priority (lower numerical
   * value) will be executed before an outstanding request with lower
   * priority. The default priority is PRIORITY_DEFAULT.
   *
   * @param count The number of bytes that will be read from the stream.
   * @param slot Callback to call when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @param io_priority The I/O priority of the request.
   *
   * @newin{2,34}
   */
  void read_bytes_async(gsize count, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Request an asynchronous read of @a count bytes from the stream into a
   * new Glib::Bytes. When the operation is finished @a slot will be called.
   * You can then call read_bytes_finish() to get the result of the
   * operation.
   *
   * During an async request no other sync and async calls are allowed, and will
   * result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the new Glib::Bytes will be passed to the callback. It is
   * not an error if this is smaller than the requested size, as it can
   * happen e.g. near the end of a file, but generally we try to read as
   * many bytes as requested. Zero is returned on end of file (or if
   * @a count is zero), but never otherwise.
   *
   * Any outstanding I/O request with higher priority (lower numerical
   * value) will be executed before an outstanding request with lower
   * priority. The default priority is PRIORITY_DEFAULT.
   *
   * @param count The number of bytes that will be read from the stream.
   * @param slot Callback to call when the request is satisfied.h
   * @param io_priority The I/O priority of the request.
   *
   * @newin{2,34}
   */
  void read_bytes_async(gsize count, const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous stream read-into-Bytes operation.
   *
   * @newin{2,34}
   *
   * @param result A AsyncResult.
   * @return The newly-allocated Bytes, or <tt>nullptr</tt> on error.
   *
   * @throws Glib::Error
   */
  auto read_bytes_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<Glib::Bytes>;


  /** Tries to skip @a count bytes from the stream. Will block during the operation.
   *
   * This is identical to g_input_stream_read(), from a behaviour standpoint,
   * but the bytes that are skipped are not returned to the user. Some
   * streams have an implementation that is more efficient than reading the data.
   *
   * This function is optional for inherited classes, as the default implementation
   * emulates it using read.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED. If an
   * operation was partially finished when the operation was cancelled the
   * partial result will be returned, without an error.
   *
   * @param count The number of bytes that will be skipped from the stream.
   * @param cancellable Cancellable object.
   * @return Number of bytes skipped, or -1 on error.
   *
   * @throws Glib::Error
   */
  auto skip(gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// A skip() convenience overload.
  auto skip(gsize count) -> gssize;


  /** Closes the stream, releasing resources related to it.
   *
   * Once the stream is closed, all other operations will throw a Gio::Error with CLOSED.
   * Closing a stream multiple times will not return an error.
   *
   * Streams will be automatically closed when the last reference
   * is dropped, but you might want to call this function to make sure
   * resources are released as early as possible.
   *
   * Some streams might keep the backing store of the stream (e.g. a file descriptor)
   * open after the stream is closed. See the documentation for the individual
   * stream for details.
   *
   * On failure the first error that happened will be reported, but the close
   * operation will finish as much as possible. A stream that failed to
   * close will still throw a Gio::Error with CLOSED for all operations. Still, it
   * is important to check and report the error to the user.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   * Cancelling a close will still leave the stream closed, but some streams
   * can use a faster close that doesn't block to e.g. check errors.
   *
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> on success, <tt>false</tt> on failure.
   *
   * @throws Glib::Error
   */
  auto close(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A close() convenience overload.
  auto close() -> bool;


  /** Request an asynchronous read of @a count bytes from the stream into the buffer
   * starting at @a buffer. When the operation is finished @a slot will be called.
   * You can then call read_finish() to get the result of the
   * operation.
   *
   * During an async request no other sync and async calls are allowed, and will
   * result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes read into the buffer will be passed to the
   * @a slot callback. It is not an error if this is not the same as the requested size, as it
   * can happen e.g. near the end of a file, but generally we try to read
   * as many bytes as requested. Zero is returned on end of file
   * (or if @a count is zero), but never otherwise.
   *
   * Any outstanding i/o request with higher priority (lower numerical value) will
   * be executed before an outstanding request with lower priority. Default
   * priority is PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads to implement
   * asynchronicity, so they are optional for inheriting classes. However, if you
   * override one you must override all.
   *
   * @param buffer A buffer to read data into (which should be at least count bytes long).
   * @param count The number of bytes that will be read from the stream.
   * @param slot Callback to call when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @param io_priority The I/O priority of the request.
   */
  void read_async(void* buffer, gsize count, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Request an asynchronous read of @a count bytes from the stream into the buffer
   * starting at @a buffer. When the operation is finished @a slot will be called.
   * You can then call read_finish() to get the result of the
   * operation.
   *
   * During an async request no other sync and async calls are allowed, and will
   * result in a Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes read into the buffer will be passed to the
   * @a slot callback. It is not an error if this is not the same as the requested size, as it
   * can happen e.g. near the end of a file, but generally we try to read
   * as many bytes as requested. Zero is returned on end of file
   * (or if @a count is zero), but never otherwise.
   *
   * Any outstanding i/o request with higher priority (lower numerical value) will
   * be executed before an outstanding request with lower priority. Default
   * priority is PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads to implement
   * asynchronicity, so they are optional for inheriting classes. However, if you
   * override one you must override all.
   *
   * @param buffer A buffer to read data into (which should be at least count bytes long).
   * @param count The number of bytes that will be read from the stream.
   * @param slot Callback to call when the request is satisfied.
   * @param io_priority The I/O priority of the request.
   */
  void read_async(void* buffer, gsize count, const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous stream read operation.
   *
   * @param result A AsyncResult.
   * @return Number of bytes read in, or -1 on error, or 0 on end of file.
   *
   * @throws Glib::Error
   */
  auto read_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize;


  /** Request an asynchronous read of @a count bytes from the stream into the buffer
   * starting at @a buffer. This is the asynchronous equivalent of read_all().
   *
   * When the operation is finished @a slot will be called.
   * You can then call read_all_finish() to get the result of the
   * operation.
   *
   * During an async request no other sync and async calls are allowed, and will
   * result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes read into the buffer will be passed to the
   * @a slot callback. It is not an error if this is not the same as the requested size, as it
   * can happen e.g. near the end of a file, but generally we try to read
   * as many bytes as requested. Zero is returned on end of file
   * (or if @a count is zero), but never otherwise.
   *
   * Any outstanding i/o request with higher priority (lower numerical value) will
   * be executed before an outstanding request with lower priority. Default
   * priority is PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads to implement
   * asynchronicity, so they are optional for inheriting classes. However, if you
   * override one you must override all.
   *
   * @param buffer A buffer to read data into (which should be at least count bytes long).
   * @param count The number of bytes that will be read from the stream.
   * @param slot Callback to call when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @param io_priority The I/O priority of the request.
   */
  void read_all_async(void* buffer, gsize count, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Request an asynchronous read of @a count bytes from the stream into the buffer
   * starting at @a buffer. This is the asynchronous equivalent of read_all().
   *
   * When the operation is finished @a slot will be called.
   * You can then call read_all_finish() to get the result of the
   * operation.
   *
   * During an async request no other sync and async calls are allowed, and will
   * result in a Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes read into the buffer will be passed to the
   * @a slot callback. It is not an error if this is not the same as the requested size, as it
   * can happen e.g. near the end of a file, but generally we try to read
   * as many bytes as requested. Zero is returned on end of file
   * (or if @a count is zero), but never otherwise.
   *
   * Any outstanding i/o request with higher priority (lower numerical value) will
   * be executed before an outstanding request with lower priority. Default
   * priority is PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads to implement
   * asynchronicity, so they are optional for inheriting classes. However, if you
   * override one you must override all.
   *
   * @param buffer A buffer to read data into (which should be at least count bytes long).
   * @param count The number of bytes that will be read from the stream.
   * @param slot Callback to call when the request is satisfied.
   * @param io_priority The I/O priority of the request.
   */
  void read_all_async(void* buffer, gsize count, const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous stream read operation started with
   * g_input_stream_read_all_async().
   *
   * As a special exception to the normal conventions for functions that
   * use Error, if this function returns <tt>false</tt> (and sets @a error) then
   *  @a bytes_read will be set to the number of bytes that were successfully
   * read before the error was encountered.  This functionality is only
   * available from C.  If you need it from another language then you must
   * write your own loop around g_input_stream_read_async().
   *
   * @newin{2,44}
   *
   * @param result A AsyncResult.
   * @param bytes_read Location to store the number of bytes that was read from the stream.
   * @return <tt>true</tt> on success, <tt>false</tt> if there was an error.
   *
   * @throws Glib::Error
   */
  auto read_all_finish(const Glib::RefPtr<AsyncResult>& result, gsize& bytes_read) -> bool;


  //TODO: Use std::size_type instead of gsize?

  /** Request an asynchronous skip of @a count bytes from the stream into the buffer
   * starting at @a buffer. When the operation is finished @a slot will be called.
   * You can then call skip_finish() to get the result of the operation.
   *
   * During an async request no other sync and async calls are allowed, and will
   * result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes skipped will be passed to the
   * callback. It is not an error if this is not the same as the requested size, as it
   * can happen e.g. near the end of a file, but generally we try to skip
   * as many bytes as requested. Zero is returned on end of file
   * (or if @a count is zero), but never otherwise.
   *
   * Any outstanding i/o request with higher priority (lower numerical value) will
   * be executed before an outstanding request with lower priority. Default
   * priority is PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads to implement
   * asynchronicity, so they are optional for inheriting classes. However, if you
   * override one you must override all.
   *
   * @param count The number of bytes that will be skipped from the stream.
   * @param slot Callback to call when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @param io_priority The I/O priority of the request.
   */
  void skip_async(gsize count, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Request an asynchronous skip of @a count bytes from the stream into the buffer
   * starting at @a buffer. When the operation is finished @a slot will be called.
   * You can then call skip_finish() to get the result of the operation.
   *
   * During an async request no other sync and async calls are allowed, and will
   * result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes skipped will be passed to the
   * callback. It is not an error if this is not the same as the requested size, as it
   * can happen e.g. near the end of a file, but generally we try to skip
   * as many bytes as requested. Zero is returned on end of file
   * (or if @a count is zero), but never otherwise.
   *
   * Any outstanding i/o request with higher priority (lower numerical value) will
   * be executed before an outstanding request with lower priority. Default
   * priority is PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads to implement
   * asynchronicity, so they are optional for inheriting classes. However, if you
   * override one you must override all.
   *
   * @param count The number of bytes that will be skipped from the stream.
   * @param slot Callback to call when the request is satisfied.
   * @param io_priority The I/O priority of the request.
   */
  void skip_async(gsize count, const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes a stream skip operation.
   *
   * @param result A AsyncResult.
   * @return The size of the bytes skipped, or `-1` on error.
   *
   * @throws Glib::Error
   */
  auto skip_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize;

  /** Requests an asynchronous closes of the stream, releasing resources related to it.
   * When the operation is finished @a slot will be called.
   * You can then call close_finish() to get the result of the
   * operation.
   *
   * For behaviour details see close().
   *
   * The asyncronous methods have a default fallback that uses threads to implement
   * asynchronicity, so they are optional for inheriting classes. However, if you
   * override one you must override all.
   *
   * @param slot Callback to call when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @param io_priority The I/O priority of the request.
   */
  void close_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Requests an asynchronous closes of the stream, releasing resources related to it.
   * When the operation is finished @a slot will be called.
   * You can then call close_finish() to get the result of the
   * operation.
   *
   * For behaviour details see close().
   *
   * The asyncronous methods have a default fallback that uses threads to implement
   * asynchronicity, so they are optional for inheriting classes. However, if you
   * override one you must override all.
   *
   * @param slot Callback to call when the request is satisfied.
   * @param io_priority The I/O priority of the request.
   */
  void close_async(const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes closing a stream asynchronously, started from g_input_stream_close_async().
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the stream was closed successfully.
   *
   * @throws Glib::Error
   */
  auto close_finish(const Glib::RefPtr<AsyncResult>& result) -> gboolean;


  /** Checks if an input stream is closed.
   *
   * @newin{2,50}
   *
   * @return <tt>true</tt> if the stream is closed.
   */
  auto is_closed() const -> bool;

  /** Checks if an input stream has pending actions.
   *
   * @newin{2,50}
   *
   * @return <tt>true</tt> if @a stream has pending actions.
   */
  auto has_pending() const -> bool;

protected:

  /** Sets @a stream to have actions pending. If the pending flag is
   * already set or @a stream is closed, it will return <tt>false</tt> and set
   *  @a error.
   *
   * @newin{2,50}
   *
   * @return <tt>true</tt> if pending was previously unset and is now set.
   *
   * @throws Glib::Error
   */
  auto set_pending() -> bool;

  /** Clears the pending flag on @a stream.
   *
   * @newin{2,50}
   */
  void clear_pending();


  /// @throws Glib::Error.
  virtual auto read_vfunc(void* buffer, gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// @throws Glib::Error.
  virtual auto skip_vfunc(gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// @throws Glib::Error.
  virtual auto close_vfunc(const Glib::RefPtr<Cancellable>& cancellable) -> bool;


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
   * @relates Gio::InputStream
   */
  GIOMM_API
  auto wrap(GInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::InputStream>;
}


#endif /* _GIOMM_INPUTSTREAM_H */

