
#ifndef _GIOMM_UNIXOUTPUTSTREAM_H
#define _GIOMM_UNIXOUTPUTSTREAM_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gio/outputstream.hpp>
#include <mm/gio/pollableoutputstream.hpp>
#include <mm/gio/filedescriptorbased.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixOutputStream = struct _GUnixOutputStream;
using GUnixOutputStreamClass = struct _GUnixOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API UnixOutputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** UnixOutputStream implements OutputStream for writing to a a unix file
 * descriptor, including asynchronous operations. The file descriptor much be
 * selectable, so it doesn't work with opened files.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API UnixOutputStream
: public Gio::OutputStream, public PollableOutputStream, public FileDescriptorBased
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = UnixOutputStream;
  using CppClassType = UnixOutputStream_Class;
  using BaseObjectType = GUnixOutputStream;
  using BaseClassType = GUnixOutputStreamClass;

  // noncopyable
  UnixOutputStream(const UnixOutputStream&) = delete;
  auto operator=(const UnixOutputStream&) -> UnixOutputStream& = delete;

private:  friend class UnixOutputStream_Class;
  static CppClassType unixoutputstream_class_;

protected:
  explicit UnixOutputStream(const Glib::ConstructParams& construct_params);
  explicit UnixOutputStream(GUnixOutputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  UnixOutputStream(UnixOutputStream&& src) noexcept;
  auto operator=(UnixOutputStream&& src) noexcept -> UnixOutputStream&;

  ~UnixOutputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GUnixOutputStream*       { return reinterpret_cast<GUnixOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GUnixOutputStream* { return reinterpret_cast<GUnixOutputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GUnixOutputStream*;

private:


  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


protected:
    explicit UnixOutputStream(int fd, bool close_fd);


public:

  static auto create(int fd, bool close_fd) -> Glib::RefPtr<UnixOutputStream>;


  /** Sets whether the file descriptor of @a stream shall be closed
   * when the stream is closed.
   *
   * @newin{2,20}
   *
   * @param close_fd <tt>true</tt> to close the file descriptor when done.
   */
  void set_close_fd(bool close_fd =  true);

  /** Returns whether the file descriptor of @a stream will be
   * closed when the stream is closed.
   *
   * @newin{2,20}
   *
   * @return <tt>true</tt> if the file descriptor is closed when done.
   */
  auto get_close_fd() const -> bool;

  /** Return the UNIX file descriptor that the stream writes to.
   *
   * @newin{2,20}
   *
   * @return The file descriptor of @a stream.
   */
  auto get_fd() const -> int;

  /** The file descriptor that the stream writes to.
   *
   * @newin{2,20}
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fd() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Whether to close the file descriptor when the stream is closed.
   *
   * @newin{2,20}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_close_fd() -> Glib::PropertyProxy< bool > ;

/** Whether to close the file descriptor when the stream is closed.
   *
   * @newin{2,20}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_close_fd() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gio::UnixOutputStream
   */
  GIOMM_API
  auto wrap(GUnixOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixOutputStream>;
}


#endif /* _GIOMM_UNIXOUTPUTSTREAM_H */

