
#ifndef _GIOMM_BUFFEREDOUTPUTSTREAM_H
#define _GIOMM_BUFFEREDOUTPUTSTREAM_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2008 The gtkmm Development Team
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

#include <libmm-gio/filteroutputstream.hpp>
#include <libmm-gio/seekable.hpp>
#include <libmm-glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GBufferedOutputStream = struct _GBufferedOutputStream;
using GBufferedOutputStreamClass = struct _GBufferedOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API BufferedOutputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** The buffered output stream implements FilterOutputStream and provides for buffered writes.
 * By default, BufferedOutputStream's buffer size is set at 4 kilobytes, but you
 * can specify this to the constructor.
 *
 * To get the size of a buffer within a buffered input stream, use get_buffer_size().
 * To change the size of a buffered output stream's buffer, use set_buffer_size().
 * Note that the buffer's size cannot be reduced below the size of the data within the buffer.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API BufferedOutputStream : public Gio::FilterOutputStream, public Gio::Seekable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = BufferedOutputStream;
  using CppClassType = BufferedOutputStream_Class;
  using BaseObjectType = GBufferedOutputStream;
  using BaseClassType = GBufferedOutputStreamClass;

  // noncopyable
  BufferedOutputStream(const BufferedOutputStream&) = delete;
  auto operator=(const BufferedOutputStream&) -> BufferedOutputStream& = delete;

private:  friend class BufferedOutputStream_Class;
  static CppClassType bufferedoutputstream_class_;

protected:
  explicit BufferedOutputStream(const Glib::ConstructParams& construct_params);
  explicit BufferedOutputStream(GBufferedOutputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  BufferedOutputStream(BufferedOutputStream&& src) noexcept;
  auto operator=(BufferedOutputStream&& src) noexcept -> BufferedOutputStream&;

  ~BufferedOutputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GBufferedOutputStream*       { return reinterpret_cast<GBufferedOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GBufferedOutputStream* { return reinterpret_cast<GBufferedOutputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GBufferedOutputStream*;

private:


protected:
    explicit BufferedOutputStream(const Glib::RefPtr<OutputStream>& base_stream);


  //Note that we rename the size parameter to buffer_size because that is the actual name of the property.
    explicit BufferedOutputStream(const Glib::RefPtr<OutputStream>& base_stream, gsize buffer_size);


public:
  /** Creates a new buffered output stream for a base stream.
   *
   * @param base_stream An InputStream.
   * @result an OutputStream for the given base stream.
	 */

  static auto create(const Glib::RefPtr<OutputStream>& base_stream) -> Glib::RefPtr<BufferedOutputStream>;


  /** Creates a new buffered output stream with a given buffer size.
   *
   * @param base_stream An InputStream.
   * @param buffer_size A size.
   * @result an OutputStream with an internal buffer set to size.
	 */
  static auto create_sized(const Glib::RefPtr<OutputStream>& base_stream, gsize buffer_size) -> Glib::RefPtr<BufferedOutputStream>;


  /** Gets the size of the buffer in the @a stream.
   *
   * @return The current size of the buffer.
   */
  auto get_buffer_size() const -> gsize;

  /** Sets the size of the internal buffer to @a size.
   *
   * @param size A #gsize.
   */
  void set_buffer_size(gsize size);


  /** Sets whether or not the @a stream's buffer should automatically grow.
   * If @a auto_grow is true, then each write will just make the buffer
   * larger, and you must manually flush the buffer to actually write out
   * the data to the underlying stream.
   *
   * @param auto_grow A <tt>bool</tt>.
   */
  void set_auto_grow(bool auto_grow = true);

  /** Checks if the buffer automatically grows as data is added.
   *
   * @return <tt>true</tt> if the @a stream's buffer automatically grows,
   * <tt>false</tt> otherwise.
   */
  auto get_auto_grow() const -> bool;

  /** The size of the backend buffer.
   *
   * Default value: 4096
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_buffer_size() -> Glib::PropertyProxy< guint > ;

/** The size of the backend buffer.
   *
   * Default value: 4096
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_buffer_size() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** Whether the buffer should automatically grow.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_auto_grow() -> Glib::PropertyProxy< bool > ;

/** Whether the buffer should automatically grow.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_auto_grow() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gio::BufferedOutputStream
   */
  GIOMM_API
  auto wrap(GBufferedOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::BufferedOutputStream>;
}


#endif /* _GIOMM_BUFFEREDOUTPUTSTREAM_H */

