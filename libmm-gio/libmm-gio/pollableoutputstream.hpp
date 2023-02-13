
#ifndef _GIOMM_POLLABLEOUTPUTSTREAM_H
#define _GIOMM_POLLABLEOUTPUTSTREAM_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The giomm Development Team
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


#include <mm/glib/interface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GPollableOutputStreamInterface GPollableOutputStreamInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GPollableOutputStream = struct _GPollableOutputStream;
using GPollableOutputStreamClass = struct _GPollableOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API PollableOutputStream_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API Cancellable;

// GPollableOutputStream requires GOutputStream (a GObject), but Gio::PollableOutputStream
// shall not be derived from Gio::OutputStream, like the Gio::Tls[Client|Server]Connection
// interfaces are derived from Gio::TlsConnection. The unusual Gio::TlsConnection class
// hierarchy is possible only because no subclass of Glib::Object implements
// Gio::Tls[Client|Server]Connection.
// See https://bugzilla.gnome.org/show_bug.cgi?id=776537

/** PollableOutputStream - Interface for pollable output streams.
 * PollableOutputStream is implemented by OutputStreams that can be polled for
 * readiness to write. This can be used when interfacing with a non-GIO API
 * that expects UNIX-file-descriptor-style asynchronous I/O rather than
 * GIO-style.
 * @newin{2,34}
 */

class GIOMM_API PollableOutputStream : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PollableOutputStream;
  using CppClassType = PollableOutputStream_Class;
  using BaseObjectType = GPollableOutputStream;
  using BaseClassType = GPollableOutputStreamInterface;

  // noncopyable
  PollableOutputStream(const PollableOutputStream&) = delete;
  auto operator=(const PollableOutputStream&) -> PollableOutputStream& = delete;

private:
  friend class PollableOutputStream_Class;
  static CppClassType pollableoutputstream_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  PollableOutputStream();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit PollableOutputStream(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit PollableOutputStream(GPollableOutputStream* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PollableOutputStream(PollableOutputStream&& src) noexcept;
  auto operator=(PollableOutputStream&& src) noexcept -> PollableOutputStream&;

  ~PollableOutputStream() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GPollableOutputStream*       { return reinterpret_cast<GPollableOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GPollableOutputStream* { return reinterpret_cast<GPollableOutputStream*>(gobject_); }

private:


public:

  /** Checks if @a stream is actually pollable. Some classes may implement
   * PollableOutputStream but have only certain instances of that
   * class be pollable. If this method returns <tt>false</tt>, then the behavior
   * of other PollableOutputStream methods is undefined.
   *
   * For any given stream, the value returned by this method is constant;
   * a stream cannot switch from pollable to non-pollable or vice versa.
   *
   * @newin{2,28}
   *
   * @return <tt>true</tt> if @a stream is pollable, <tt>false</tt> if not.
   */
  auto can_poll() const -> bool;

  /** Checks if @a stream can be written.
   *
   * Note that some stream types may not be able to implement this 100%
   * reliably, and it is possible that a call to g_output_stream_write()
   * after this returns <tt>true</tt> would still block. To guarantee
   * non-blocking behavior, you should always use
   * g_pollable_output_stream_write_nonblocking(), which will return a
   * Gio::Error::WOULD_BLOCK error rather than blocking.
   *
   * @newin{2,28}
   *
   * @return <tt>true</tt> if @a stream is writable, <tt>false</tt> if not. If an error
   * has occurred on @a stream, this will result in
   * g_pollable_output_stream_is_writable() returning <tt>true</tt>, and the
   * next attempt to write will return the error.
   */
  auto is_writable() const -> bool;

  //TODO: _WRAP_METHOD(Glib::RefPtr<Source> create_source(const Glib::RefPtr<Cancellable>& cancellable), g_pollable_output_stream_create_source)


  /** Attempts to write up to @a count bytes from @a buffer to @a stream, as
   * with g_output_stream_write(). If @a stream is not currently writable,
   * this will immediately return Gio::Error::WOULD_BLOCK, and you can
   * use g_pollable_output_stream_create_source() to create a Source
   * that will be triggered when @a stream is writable.
   *
   * Note that since this method never blocks, you cannot actually
   * use @a cancellable to cancel it. However, it will return an error
   * if @a cancellable has already been cancelled when you call, which
   * may happen if you call this method after a source triggers due
   * to having been cancelled.
   *
   * Also note that if Gio::Error::WOULD_BLOCK is returned some underlying
   * transports like D/TLS require that you re-send the same @a buffer and
   *  @a count in the next write call.
   *
   * Virtual: write_nonblocking
   *
   * @param buffer A buffer to write
   * data from.
   * @param count The number of bytes you want to write.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return The number of bytes written, or -1 on error (including
   * Gio::Error::WOULD_BLOCK).
   *
   * @throws Glib::Error
   */
  auto write_nonblocking(const void* buffer, gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// A write_nonblocking() convenience overload.
  auto write_nonblocking(const void* buffer, gsize count) -> gssize;

protected:
    virtual auto can_poll_vfunc() const -> bool;

    virtual auto is_writable_vfunc() const -> bool;


  //TODO:_WRAP_VFUNC(Glib::RefPtr<Source> create_source(const Glib::RefPtr<Cancellable>& cancellable), "create_source")

  /// @throws Glib::Error.
  virtual auto write_nonblocking_vfunc(const void* buffer, gsize count) -> gssize;


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
   * @relates Gio::PollableOutputStream
   */
  GIOMM_API
  auto wrap(GPollableOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::PollableOutputStream>;

} // namespace Glib


#endif /* _GIOMM_POLLABLEOUTPUTSTREAM_H */

