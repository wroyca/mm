
#ifndef _GIOMM_DATAOUTPUTSTREAM_H
#define _GIOMM_DATAOUTPUTSTREAM_H


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

#include <libmm-gio/filteroutputstream.hxx>
#include <libmm-gio/seekable.hxx>
#include <libmm-gio/enums.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDataOutputStream = struct _GDataOutputStream;
using GDataOutputStreamClass = struct _GDataOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API DataOutputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/**
 * An implementation of FilterOutputStream that allows for high-level data
 * manipulation of arbitrary data (including binary operations).
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API DataOutputStream : public Gio::FilterOutputStream, public Gio::Seekable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DataOutputStream;
  using CppClassType = DataOutputStream_Class;
  using BaseObjectType = GDataOutputStream;
  using BaseClassType = GDataOutputStreamClass;

  // noncopyable
  DataOutputStream(const DataOutputStream&) = delete;
  auto operator=(const DataOutputStream&) -> DataOutputStream& = delete;

private:  friend class DataOutputStream_Class;
  static CppClassType dataoutputstream_class_;

protected:
  explicit DataOutputStream(const Glib::ConstructParams& construct_params);
  explicit DataOutputStream(GDataOutputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DataOutputStream(DataOutputStream&& src) noexcept;
  auto operator=(DataOutputStream&& src) noexcept -> DataOutputStream&;

  ~DataOutputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDataOutputStream*       { return reinterpret_cast<GDataOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDataOutputStream* { return reinterpret_cast<GDataOutputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDataOutputStream*;

private:


protected:
    explicit DataOutputStream(const Glib::RefPtr<OutputStream>& base_stream);


public:


  static auto create(const Glib::RefPtr<OutputStream>& base_stream) -> Glib::RefPtr<DataOutputStream>;


  /** Sets the byte order of the data output stream to @a order.
   *
   * @param order A DataStreamByteOrder.
   */
  void set_byte_order(DataStreamByteOrder order);

  /** Gets the byte order for the stream.
   *
   * @return The DataStreamByteOrder for the @a stream.
   */
  auto get_byte_order() const -> DataStreamByteOrder;


  /** Puts a byte into the output stream.
   *
   * @param data A #guchar.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if @a data was successfully added to the @a stream.
   *
   * @throws Glib::Error
   */
  auto put_byte(guchar data, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A put_byte() convenience overload.
  auto put_byte(guchar data) -> bool;


  /** Puts a signed 16-bit integer into the output stream.
   *
   * @param data A #gint16.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if @a data was successfully added to the @a stream.
   *
   * @throws Glib::Error
   */
  auto put_int16(gint16 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A put_int16() convenience overload.
  auto put_int16(gint16 data) -> bool;


  /** Puts an unsigned 16-bit integer into the output stream.
   *
   * @param data A #guint16.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if @a data was successfully added to the @a stream.
   *
   * @throws Glib::Error
   */
  auto put_uint16(guint16 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A put_uint16() convenience overload.
  auto put_uint16(guint16 data) -> bool;


  /** Puts a signed 32-bit integer into the output stream.
   *
   * @param data A #gint32.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if @a data was successfully added to the @a stream.
   *
   * @throws Glib::Error
   */
  auto put_int32(gint32 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A put_int32() convenience overload.
  auto put_int32(gint32 data) -> bool;


  /** Puts an unsigned 32-bit integer into the stream.
   *
   * @param data A #guint32.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if @a data was successfully added to the @a stream.
   *
   * @throws Glib::Error
   */
  auto put_uint32(guint32 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A put_uint32() convenience overload.
  auto put_uint32(guint32 data) -> bool;


  /** Puts a signed 64-bit integer into the stream.
   *
   * @param data A #gint64.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if @a data was successfully added to the @a stream.
   *
   * @throws Glib::Error
   */
  auto put_int64(gint64 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A put_int64() convenience overload.
  auto put_int64(gint64 data) -> bool;


  /** Puts an unsigned 64-bit integer into the stream.
   *
   * @param data A #guint64.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if @a data was successfully added to the @a stream.
   *
   * @throws Glib::Error
   */
  auto put_uint64(guint64 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A put_uint64() convenience overload.
  auto put_uint64(guint64 data) -> bool;


  /** Puts a string into the output stream.
   *
   * @param str A string.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if @a string was successfully added to the @a stream.
   *
   * @throws Glib::Error
   */
  auto put_string(const std::string& str, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A put_string() convenience overload.
  auto put_string(const std::string& str) -> bool;

  /** Determines the byte ordering that is used when writing
   * multi-byte entities (such as integers) to the stream.
   *
   * Default value: Gio::DataStreamByteOrder::BIG_ENDIAN
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_byte_order() -> Glib::PropertyProxy< DataStreamByteOrder > ;

/** Determines the byte ordering that is used when writing
   * multi-byte entities (such as integers) to the stream.
   *
   * Default value: Gio::DataStreamByteOrder::BIG_ENDIAN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_byte_order() const -> Glib::PropertyProxy_ReadOnly< DataStreamByteOrder >;


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
   * @relates Gio::DataOutputStream
   */
  GIOMM_API
  auto wrap(GDataOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::DataOutputStream>;
}


#endif /* _GIOMM_DATAOUTPUTSTREAM_H */
