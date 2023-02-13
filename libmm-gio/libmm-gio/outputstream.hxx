
#ifndef _GIOMM_OUTPUTSTREAM_H
#define _GIOMM_OUTPUTSTREAM_H


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

#include <libmm-glib/object.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/inputstream.hxx>


 // for GOutputStreamSpliceFlags

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GOutputStream = struct _GOutputStream;
using GOutputStreamClass = struct _GOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API OutputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{


/** Base class for implementing streaming output.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API OutputStream : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = OutputStream;
  using CppClassType = OutputStream_Class;
  using BaseObjectType = GOutputStream;
  using BaseClassType = GOutputStreamClass;

  // noncopyable
  OutputStream(const OutputStream&) = delete;
  auto operator=(const OutputStream&) -> OutputStream& = delete;

private:  friend class OutputStream_Class;
  static CppClassType outputstream_class_;

protected:
  explicit OutputStream(const Glib::ConstructParams& construct_params);
  explicit OutputStream(GOutputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  OutputStream(OutputStream&& src) noexcept;
  auto operator=(OutputStream&& src) noexcept -> OutputStream&;

  ~OutputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GOutputStream*       { return reinterpret_cast<GOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GOutputStream* { return reinterpret_cast<GOutputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GOutputStream*;

private:


protected:
  OutputStream();

public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var SpliceFlags NONE
   * Do not close either stream.
   *
   *  @var SpliceFlags CLOSE_SOURCE
   * Close the source stream after
   * the splice.
   *
   *  @var SpliceFlags CLOSE_TARGET
   * Close the target stream after
   * the splice.
   *
   *  @enum SpliceFlags
   *
   * GOutputStreamSpliceFlags determine how streams should be spliced.
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>OutputStream::SpliceFlags operator|(OutputStream::SpliceFlags, OutputStream::SpliceFlags)</tt><br>
   * <tt>OutputStream::SpliceFlags operator&(OutputStream::SpliceFlags, OutputStream::SpliceFlags)</tt><br>
   * <tt>OutputStream::SpliceFlags operator^(OutputStream::SpliceFlags, OutputStream::SpliceFlags)</tt><br>
   * <tt>OutputStream::SpliceFlags operator~(OutputStream::SpliceFlags)</tt><br>
   * <tt>OutputStream::SpliceFlags& operator|=(OutputStream::SpliceFlags&, OutputStream::SpliceFlags)</tt><br>
   * <tt>OutputStream::SpliceFlags& operator&=(OutputStream::SpliceFlags&, OutputStream::SpliceFlags)</tt><br>
   * <tt>OutputStream::SpliceFlags& operator^=(OutputStream::SpliceFlags&, OutputStream::SpliceFlags)</tt><br>
   */
  enum class SpliceFlags
  {
    NONE = 0x0,
    CLOSE_SOURCE = (1 << 0),
    CLOSE_TARGET = (1 << 1)
  };


  /** Tries to write @a count bytes from @a buffer into the stream. Will block
   * during the operation.
   *
   * If count is zero returns zero and does nothing. A value of @a count
   * larger than G_MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes written to the stream is returned.
   * It is not an error if this is not the same as the requested size, as it
   * can happen e.g. on a partial i/o error, or if there is not enough
   * storage in the stream. All writes either block until at least one byte
   * is written, so zero is never returned (unless @a count is zero).
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED. If an
   * operation was partially finished when the operation was cancelled the
   * partial result will be returned, without an error.
   *
   * @param buffer The buffer containing the data to write.
   * @param count The number of bytes to write.
   * @param cancellable Cancellable object.
   * @return Number of bytes written, or -1 on error.
   *
   * @throws Glib::Error
   */
  auto write(const void* buffer, gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// A write() convenience overload.
  auto write(const void* buffer, gsize count) -> gssize;

  /** Tries to write @a count  bytes from @a buffer  into the stream. Will block
   * during the operation.
   *
   * If count is zero returns zero and does nothing. A value of @a count
   * larger than MAXSSIZE will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes written to the stream is returned.
   * It is not an error if this is not the same as the requested size, as it
   * can happen e.g. on a partial i/o error, or if the there is not enough
   * storage in the stream. All writes either block until at least one byte
   * is written, so zero is never returned (unless @a count  is zero).
   *
   * On error -1 is returned.
   * @param buffer The buffer containing the data to write.
   * @param cancellable Cancellable object.
   * @return Number of bytes written, or -1 on error.
   */
  auto write(const std::string& buffer, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /** Tries to write @a count  bytes from @a buffer  into the stream. Will block
   * during the operation.
   *
   * If string that is larger than MAXSSIZE bytes will cause a Gio::Error with INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes written to the stream is returned.
   * It is not an error if this is not the same as the requested size, as it
   * can happen e.g. on a partial i/o error, or if the there is not enough
   * storage in the stream. All writes either block until at least one byte
   * is written, so zero is never returned (unless @a count  is zero).
   *
   * On error -1 is returned.
   * @param buffer The buffer containing the data to write.
   * @return Number of bytes written, or -1 on error.
   */
  auto write(const std::string& buffer) -> gssize;


  /** Tries to write @a count bytes from @a buffer into the stream. Will block
   * during the operation.
   *
   * This function is similar to g_output_stream_write(), except it tries to
   * write as many bytes as requested, only stopping on an error.
   *
   * On a successful write of @a count bytes, <tt>true</tt> is returned, and @a bytes_written
   * is set to @a count.
   *
   * If there is an error during the operation <tt>false</tt> is returned and @a error
   * is set to indicate the error status.
   *
   * As a special exception to the normal conventions for functions that
   * use Error, if this function returns <tt>false</tt> (and sets @a error) then
   *  @a bytes_written will be set to the number of bytes that were
   * successfully written before the error was encountered.  This
   * functionality is only available from C.  If you need it from another
   * language then you must write your own loop around
   * g_output_stream_write().
   *
   * @param buffer The buffer containing the data to write.
   * @param count The number of bytes to write.
   * @param bytes_written Location to store the number of bytes that was
   * written to the stream.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> on success, <tt>false</tt> if there was an error.
   *
   * @throws Glib::Error
   */
  auto write_all(const void* buffer, gsize count, gsize& bytes_written, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A write_all() convenience overload.
  auto write_all(const void* buffer, gsize count, gsize& bytes_written) -> bool;

  /** Tries to write @a count  bytes from @a buffer into the stream. Will block
   * during the operation.
   *
   * This function is similar to write(), except it tries to
   * write as many bytes as requested, only stopping on an error.
   *
   * On a successful write of @a count  bytes, <tt>true</tt> is returned, and @a bytes_written
   * is set to @a count .
   *
   * If there is an error during the operation <tt>false</tt> is returned and @a error
   * is set to indicate the error status, @a bytes_written  is updated to contain
   * the number of bytes written into the stream before the error occured.
   * @param buffer The buffer containing the data to write.
   * @param bytes_written Location to store the number of bytes that was
   * written to the stream.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> on success, <tt>false</tt> if there was an error.
   */
  auto write_all(const std::string& buffer, gsize& bytes_written, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /** Tries to write @a count  bytes from @a buffer into the stream. Will block
   * during the operation.
   *
   * This function is similar to write(), except it tries to
   * write as many bytes as requested, only stopping on an error.
   *
   * On a successful write of @a count  bytes, <tt>true</tt> is returned, and @a bytes_written
   * is set to @a count .
   *
   * If there is an error during the operation <tt>false</tt> is returned and @a error
   * is set to indicate the error status, @a bytes_written  is updated to contain
   * the number of bytes written into the stream before the error occured.
   * @param buffer The buffer containing the data to write.
   * @param bytes_written Location to store the number of bytes that was
   * written to the stream.
   * @return <tt>true</tt> on success, <tt>false</tt> if there was an error.
   */
  auto write_all(const std::string& buffer, gsize& bytes_written) -> bool;


  /** A wrapper function for g_output_stream_write() which takes a
   * Bytes as input.  This can be more convenient for use by language
   * bindings or in other cases where the refcounted nature of Bytes
   * is helpful over a bare pointer interface.
   *
   * However, note that this function may still perform partial writes,
   * just like g_output_stream_write().  If that occurs, to continue
   * writing, you will need to create a new Bytes containing just the
   * remaining bytes, using Glib::bytes_new_from_bytes(). Passing the same
   * Bytes instance multiple times potentially can result in duplicated
   * data in the output stream.
   *
   * @param bytes The Bytes to write.
   * @param cancellable Optional cancellable object.
   * @return Number of bytes written, or -1 on error.
   *
   * @throws Glib::Error
   */
  auto write_bytes(const Glib::RefPtr<const Glib::Bytes>& bytes, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// A write_bytes() convenience overload.
  auto write_bytes(const Glib::RefPtr<const Glib::Bytes>& bytes) -> gssize;

  /** Request an asynchronous write of the data in @a bytes to the stream.
   * When the operation is finished @a slot will be called. You can
   * then call write_bytes_finish() to get the result of
   * the operation.
   *
   * During an async request no other sync and async calls are allowed,
   * and will result in Gio::Error with PENDING being thrown.
   *
   * A Glib:Bytes larger than MAXSSIZE will cause a Gio::Error with
   * INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes written will be passed to the
   * callback @a slot. It is not an error if this is not the same as the
   * requested size, as it can happen e.g. on a partial I/O error,
   * but generally we try to write as many bytes as requested.
   *
   * You are guaranteed that this method will never fail with
   * IO_ERROR_WOULD_BLOCK - if the stream can't accept more data, the
   * method will just wait until this changes.
   *
   * Any outstanding I/O request with higher priority (lower numerical
   * value) will be executed before an outstanding request with lower
   * priority. Default priority is Glib::PRIORITY_DEFAULT.
   *
   * For the synchronous, blocking version of this function, see write_bytes().
   *
   * @param bytes The bytes to
   * @param slot Callback slot to call when the request is satisfied.
   * @param cancellable Cancellable object.
   * @param io_priority The io priority of the request.
   *
   * @newin{2,34}
   */
  void write_bytes_async(const Glib::RefPtr<const Glib::Bytes>& bytes, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Request an asynchronous write of the data in @a bytes to the stream.
   * When the operation is finished @a slot will be called. You can
   * then call write_bytes_finish() to get the result of
   * the operation.
   *
   * During an async request no other sync and async calls are allowed,
   * and will result in Gio::Error with PENDING being thrown.
   *
   * A Glib:Bytes larger than MAXSSIZE will cause a Gio::Error with
   * INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes written will be passed to the
   * callback @a slot. It is not an error if this is not the same as the
   * requested size, as it can happen e.g. on a partial I/O error,
   * but generally we try to write as many bytes as requested.
   *
   * You are guaranteed that this method will never fail with
   * IO_ERROR_WOULD_BLOCK - if the stream can't accept more data, the
   * method will just wait until this changes.
   *
   * Any outstanding I/O request with higher priority (lower numerical
   * value) will be executed before an outstanding request with lower
   * priority. Default priority is Glib::PRIORITY_DEFAULT.
   *
   * For the synchronous, blocking version of this function, see write_bytes().
   *
   * @param bytes The bytes to
   * @param slot Callback slot to call when the request is satisfied.
   * @param io_priority The io priority of the request.
   *
   * @newin{2,34}
   */
  void write_bytes_async(const Glib::RefPtr<const Glib::Bytes>& bytes, const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes a stream write-from-Bytes operation.
   *
   * @param result A AsyncResult.
   * @return A #gssize containing the number of bytes written to the stream.
   *
   * @throws Glib::Error
   */
  auto write_bytes_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize;

  /** Splices an input stream into an output stream.
   *
   * @param source An InputStream.
   * @param flags A set of SpliceFlags.
   * @param cancellable A Cancellable object.
   * ignore.
   * @return A #gssize containing the size of the data spliced.
   */
  auto splice(const Glib::RefPtr<InputStream>& source, const Glib::RefPtr<Cancellable>& cancellable, SpliceFlags flags = SpliceFlags::NONE) -> gssize;

  /** Splices an input stream into an output stream.
   *
   * @param source An InputStream.
   * @param flags A set of SpliceFlags.
   * ignore.
   * @return A #gssize containing the size of the data spliced.
   */
  auto splice(const Glib::RefPtr<InputStream>& source, SpliceFlags flags = SpliceFlags::NONE) -> gssize;


  /** Flushed any outstanding buffers in the stream. Will block during
   * the operation. Closing the stream will implicitly cause a flush.
   *
   * This function is optional for inherited classes.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> on success, <tt>false</tt> on error.
   *
   * @throws Glib::Error
   */
  auto flush(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A flush() convenience overload.
  auto flush() -> bool;


  /** Closes the stream, releasing resources related to it.
   *
   * Once the stream is closed, all other operations will throw a Gio::Error with
   * CLOSED. Closing a stream multiple times will not cause an error to be
   * thrown.
   *
   * Closing a stream will automatically flush any outstanding buffers in the
   * stream.
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
   * is important to check and report the error to the user, otherwise
   * there might be a loss of data as all data might not be written.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   * Cancelling a close will still leave the stream closed, but there some streams
   * can use a faster close that doesn't block to e.g. check errors. On
   * cancellation (as with any error) there is no guarantee that all written
   * data will reach the target.
   *
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> on success, <tt>false</tt> on failure.
   *
   * @throws Glib::Error
   */
  auto close(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A close() convenience overload.
  auto close() -> bool;

  /** Request an asynchronous write of @a count bytes from @a buffer into
   * the stream. When the operation is finished @a slot will be called.
   * You can then call write_finish() to get the result of the
   * operation.
   *
   * During an async request no other sync and async calls are allowed,
   * and will result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with
   * INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes written will be passed to the
   * callback @a slot. It is not an error if this is not the same as the
   * requested size, as it can happen e.g. on a partial I/O error,
   * but generally we try to write as many bytes as requested.
   *
   * Any outstanding I/O request with higher priority (lower numerical
   * value) will be executed before an outstanding request with lower
   * priority. Default priority is Glib::PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads
   * to implement asynchronicity, so they are optional for inheriting
   * classes. However, if you override one you must override all.
   *
   * For the synchronous, blocking version of this function, see
   * write().
   *
   * Note that no copy of @a buffer will be made, so it must stay valid
   * until @a slot is called. See write_bytes_async()
   * for a Glib::Bytes version that will automatically hold a reference to
   * the contents (without copying) for the duration of the call.
   *
   * @param buffer The buffer containing the data to write.
   * @param count The number of bytes to write
   * @param slot Callback slot to call when the request is satisfied.
   * @param cancellable Cancellable object.
   * @param io_priority The io priority of the request.
   */
  void write_async(const void* buffer, gsize count, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Request an asynchronous write of @a count bytes from @a buffer into
   * the stream. When the operation is finished @a slot will be called.
   * You can then call write_finish() to get the result of the
   * operation.
   *
   * During an async request no other sync and async calls are allowed,
   * and will result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with
   * INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes written will be passed to the
   * callback @a slot. It is not an error if this is not the same as the
   * requested size, as it can happen e.g. on a partial I/O error,
   * but generally we try to write as many bytes as requested.
   *
   * Any outstanding I/O request with higher priority (lower numerical
   * value) will be executed before an outstanding request with lower
   * priority. Default priority is Glib::PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads
   * to implement asynchronicity, so they are optional for inheriting
   * classes. However, if you override one you must override all.
   *
   * For the synchronous, blocking version of this function, see
   * write().

   * Note that no copy of @a buffer will be made, so it must stay valid
   * until @a slot is called. See write_bytes_async()
   * for a Glib::Bytes version that will automatically hold a reference to
   * the contents (without copying) for the duration of the call.
   *
   * @param buffer The buffer containing the data to write.
   * @param count The number of bytes to write
   * @param slot Callback slot to call when the request is satisfied.
   * @param io_priority The io priority of the request.
   */
  void write_async(const void* buffer, gsize count, const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes a stream write operation.
   *
   * @param result A AsyncResult.
   * @return A #gssize containing the number of bytes written to the stream.
   *
   * @throws Glib::Error
   */
  auto write_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize;


  /** Request an asynchronous write of @a count bytes from @a buffer into
   * the stream. When the operation is finished @a slot will be called.
   * You can then call write_all_finish() to get the result of the
   * operation.
   *
   * This is the asynchronous version of write_all().
   *
   * During an async request no other sync and async calls are allowed,
   * and will result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with
   * INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes written will be passed to the
   * callback @a slot. It is not an error if this is not the same as the
   * requested size, as it can happen e.g. on a partial I/O error,
   * but generally we try to write as many bytes as requested.
   *
   * Any outstanding I/O request with higher priority (lower numerical
   * value) will be executed before an outstanding request with lower
   * priority. Default priority is Glib::PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads
   * to implement asynchronicity, so they are optional for inheriting
   * classes. However, if you override one you must override all.
   *
   * For the synchronous, blocking version of this function, see
   * write().
   *
   * Note that no copy of @a buffer will be made, so it must stay valid
   * until @a slot is called.
   *
   * @param buffer The buffer containing the data to write.
   * @param count The number of bytes to write
   * @param slot Callback slot to call when the request is satisfied.
   * @param cancellable Cancellable object.
   * @param io_priority The io priority of the request.
   */
  void write_all_async(const void* buffer, gsize count, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Request an asynchronous write of @a count bytes from @a buffer into
   * the stream. When the operation is finished @a slot will be called.
   * You can then call write_finish() to get the result of the
   * operation.
   *
   * This is the asynchronous version of write_all().
   *
   * During an async request no other sync and async calls are allowed,
   * and will result in Gio::Error with PENDING being thrown.
   *
   * A value of @a count larger than MAXSSIZE will cause a Gio::Error with
   * INVALID_ARGUMENT to be thrown.
   *
   * On success, the number of bytes written will be passed to the
   * callback @a slot. It is not an error if this is not the same as the
   * requested size, as it can happen e.g. on a partial I/O error,
   * but generally we try to write as many bytes as requested.
   *
   * Any outstanding I/O request with higher priority (lower numerical
   * value) will be executed before an outstanding request with lower
   * priority. Default priority is Glib::PRIORITY_DEFAULT.
   *
   * The asyncronous methods have a default fallback that uses threads
   * to implement asynchronicity, so they are optional for inheriting
   * classes. However, if you override one you must override all.
   *
   * For the synchronous, blocking version of this function, see
   * write().
   *
   * Note that no copy of @a buffer will be made, so it must stay valid
   * until @a slot is called.
   *
   * @param buffer The buffer containing the data to write.
   * @param count The number of bytes to write
   * @param slot Callback slot to call when the request is satisfied.
   * @param io_priority The io priority of the request.
   */
  void write_all_async(const void* buffer, gsize count, const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous stream write operation started with
   * g_output_stream_write_all_async().
   *
   * As a special exception to the normal conventions for functions that
   * use Error, if this function returns <tt>false</tt> (and sets @a error) then
   *  @a bytes_written will be set to the number of bytes that were
   * successfully written before the error was encountered.  This
   * functionality is only available from C.  If you need it from another
   * language then you must write your own loop around
   * g_output_stream_write_async().
   *
   * @newin{2,44}
   *
   * @param result A AsyncResult.
   * @param bytes_written Location to store the number of bytes that was written to the stream.
   * @return <tt>true</tt> on success, <tt>false</tt> if there was an error.
   *
   * @throws Glib::Error
   */
  auto write_all_finish(const Glib::RefPtr<AsyncResult>& result, gsize& bytes_written) -> bool;


  /** Splices a stream asynchronously.
   *  When the operation is finished @a slot will be called.
   * You can then call splice_finish() to get the result of the
   * operation.
   *
   * For the synchronous, blocking version of this function, see
   * splice().
   *
   * @param source An InputStream.
   * @param slot Callback slot to call when the request is satisfied.
   * @param cancellable Cancellable object.
   * @param flags A set of SpliceFlags.
   * @param io_priority The io priority of the request.
   */
  void splice_async(const Glib::RefPtr<InputStream>& source, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, SpliceFlags flags = SpliceFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Splices a stream asynchronously.
   *  When the operation is finished @a slot will be called.
   * You can then call splice_finish() to get the result of the
   * operation.
   *
   * For the synchronous, blocking version of this function, see
   * splice().
   *
   * @param source An InputStream.
   * @param slot Callback slot to call when the request is satisfied.
   * @param flags A set of SpliceFlags.
   * @param io_priority The io priority of the request.
   */
  void splice_async(const Glib::RefPtr<InputStream>& source, const SlotAsyncReady& slot, SpliceFlags flags = SpliceFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous stream splice operation.
   *
   * @param result A AsyncResult.
   * @return A #gssize of the number of bytes spliced. Note that if the
   * number of bytes spliced is greater than G_MAXSSIZE, then that
   * will be returned, and there is no way to determine the actual
   * number of bytes spliced.
   *
   * @throws Glib::Error
   */
  auto splice_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize;

  /** Flushes a stream asynchronously.
   * When the operation is finished the @a slot will be called, giving the results.
   * You can then call flush_finish() to get the result of the operation.
   * For behaviour details see flush().
   *
   * @param slot Callback slot to call when the request is satisfied.
   * @param cancellable Cancellable object.
   * @param io_priority The io priority of the request.
   */
  void flush_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Flushes a stream asynchronously.
   * When the operation is finished the @a slot will be called, giving the results.
   * You can then call flush_finish() to get the result of the operation.
   * For behaviour details see flush().
   *
   * @param slot Callback slot to call when the request is satisfied.
   * @param io_priority The io priority of the request.
   */
  void flush_async(const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes flushing an output stream.
   *
   * @param result A GAsyncResult.
   * @return <tt>true</tt> if flush operation succeeded, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto flush_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;

  /** Requests an asynchronous close of the stream, releasing resources related to it.
   * When the operation is finished the @a slot will be called, giving the results.
   * You can then call close_finish() to get the result of the operation.
   * For behaviour details see close().
   *
   * The asyncronous methods have a default fallback that uses threads to implement asynchronicity,
   * so they are optional for inheriting classes. However, if you override one you must override all.
   *
   * @param slot Callback slot to call when the request is satisfied.
   * @param cancellable Cancellable object.
   * @param io_priority The io priority of the request.
   */
  void close_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Requests an asynchronous close of the stream, releasing resources related to it.
   * When the operation is finished the @a slot will be called, giving the results.
   * You can then call close_finish() to get the result of the operation.
   * For behaviour details see close().
   *
   * The asyncronous methods have a default fallback that uses threads to implement asynchronicity,
   * so they are optional for inheriting classes. However, if you override one you must override all.
   *
   * @param slot Callback slot to call when the request is satisfied.
   * @param io_priority The io priority of the request.
   */
  void close_async(const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Closes an output stream.
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if stream was successfully closed, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto close_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Checks if an output stream has already been closed.
   *
   * @newin{2,50}
   *
   * @return <tt>true</tt> if @a stream is closed. <tt>false</tt> otherwise.
   */
  auto is_closed() const -> bool;

  /** Checks if an output stream is being closed. This can be
   * used inside e.g. a flush implementation to see if the
   * flush (or other i/o operation) is called from within
   * the closing operation.
   *
   * @newin{2,50}
   *
   * @return <tt>true</tt> if @a stream is being closed. <tt>false</tt> otherwise.
   */
  auto is_closing() const -> bool;

  /** Checks if an output stream has pending actions.
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
  virtual auto write_vfunc(const void* buffer, gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// @throws Glib::Error.
  virtual auto splice_vfunc(const Glib::RefPtr<InputStream>& source, const Glib::RefPtr<Cancellable>& cancellable, SpliceFlags flags) -> gssize;

  /// @throws Glib::Error.
  virtual auto flush_vfunc(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

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

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(OutputStream::SpliceFlags lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags
  { return static_cast<OutputStream::SpliceFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(OutputStream::SpliceFlags lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags
  { return static_cast<OutputStream::SpliceFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(OutputStream::SpliceFlags lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags
  { return static_cast<OutputStream::SpliceFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(OutputStream::SpliceFlags flags) -> OutputStream::SpliceFlags
  { return static_cast<OutputStream::SpliceFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(OutputStream::SpliceFlags& lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags&
  { return (lhs = static_cast<OutputStream::SpliceFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(OutputStream::SpliceFlags& lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags&
  { return (lhs = static_cast<OutputStream::SpliceFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(OutputStream::SpliceFlags& lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags&
  { return (lhs = static_cast<OutputStream::SpliceFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::OutputStream
   */
  GIOMM_API
  auto wrap(GOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::OutputStream>;
}


#endif /* _GIOMM_OUTPUTSTREAM_H */

