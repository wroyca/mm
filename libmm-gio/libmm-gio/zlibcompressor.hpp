
#ifndef _GIOMM_ZLIBCOMPRESSOR_H
#define _GIOMM_ZLIBCOMPRESSOR_H

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


#include <mm/glib/object.hpp>
#include <mm/gio/converter.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GZlibCompressor = struct _GZlibCompressor;
using GZlibCompressorClass = struct _GZlibCompressorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API ZlibCompressor_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var ZlibCompressorFormat ZLIB
 * Deflate compression with zlib header.
 *
 *  @var ZlibCompressorFormat GZIP
 * Gzip file format.
 *
 *  @var ZlibCompressorFormat RAW
 * Deflate compression with no header.
 *
 *  @enum ZlibCompressorFormat
 *
 * Used to select the type of data format to use for ZlibDecompressor
 * and ZlibCompressor.
 *
 * @newin{2,24}
 *
 * @ingroup giommEnums
 */
enum class ZlibCompressorFormat
{
  ZLIB,
  GZIP,
  RAW
};


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::ZlibCompressorFormat> : public Glib::Value_Enum<Gio::ZlibCompressorFormat>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{


class GIOMM_API FileInfo;

/** ZlibCompressor - Zlib compressor.
 * ZlibCompressor is an implementation of Converter that compresses data using
 * zlib.
 * @newin{2,34}
 */

class GIOMM_API ZlibCompressor : public Glib::Object, public Converter
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ZlibCompressor;
  using CppClassType = ZlibCompressor_Class;
  using BaseObjectType = GZlibCompressor;
  using BaseClassType = GZlibCompressorClass;

  // noncopyable
  ZlibCompressor(const ZlibCompressor&) = delete;
  auto operator=(const ZlibCompressor&) -> ZlibCompressor& = delete;

private:  friend class ZlibCompressor_Class;
  static CppClassType zlibcompressor_class_;

protected:
  explicit ZlibCompressor(const Glib::ConstructParams& construct_params);
  explicit ZlibCompressor(GZlibCompressor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ZlibCompressor(ZlibCompressor&& src) noexcept;
  auto operator=(ZlibCompressor&& src) noexcept -> ZlibCompressor&;

  ~ZlibCompressor() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GZlibCompressor*       { return reinterpret_cast<GZlibCompressor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GZlibCompressor* { return reinterpret_cast<GZlibCompressor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GZlibCompressor*;

private:


protected:
    explicit ZlibCompressor(ZlibCompressorFormat format, int level);


public:

  /** Creates a new ZlibCompressor.
   *
   * @newin{2,24}
   *
   * @param format The format to use for the compressed data.
   * @param level Compression level (0-9), -1 for default.
   * @return A new ZlibCompressor.
   */


  static auto create(ZlibCompressorFormat format, int level) -> Glib::RefPtr<ZlibCompressor>;


  /** Returns the ZlibCompressor::property_file_info() property.
   *
   * @newin{2,26}
   *
   * @return A FileInfo, or <tt>nullptr</tt>.
   */
  auto get_file_info() -> Glib::RefPtr<FileInfo>;

  /** Returns the ZlibCompressor::property_file_info() property.
   *
   * @newin{2,26}
   *
   * @return A FileInfo, or <tt>nullptr</tt>.
   */
  auto get_file_info() const -> Glib::RefPtr<const FileInfo>;


  /** Sets @a file_info in @a compressor. If non-<tt>nullptr</tt>, and @a compressor's
   * ZlibCompressor::property_format() property is Gio::ZlibCompressorFormat::GZIP,
   * it will be used to set the file name and modification time in
   * the GZIP header of the compressed data.
   *
   * @note it is an error to call this function while a compression is in
   * progress; it may only be called immediately after creation of @a compressor,
   * or after resetting it with g_converter_reset().
   *
   * @newin{2,26}
   *
   * @param file_info A FileInfo.
   */
  void set_file_info(const Glib::RefPtr<FileInfo>& file_info);

  /** If set to a non-<tt>nullptr</tt> FileInfo object, and ZlibCompressor::property_format() is
   * Gio::ZlibCompressorFormat::GZIP, the compressor will write the file name
   * and modification time from the file info to the GZIP header.
   *
   * @newin{2,26}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file_info() -> Glib::PropertyProxy< Glib::RefPtr<FileInfo> > ;

/** If set to a non-<tt>nullptr</tt> FileInfo object, and ZlibCompressor::property_format() is
   * Gio::ZlibCompressorFormat::GZIP, the compressor will write the file name
   * and modification time from the file info to the GZIP header.
   *
   * @newin{2,26}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file_info() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<FileInfo> >;

  /** The format of the compressed data.
   *
   * Default value: Gio::ZlibCompressorFormat::ZLIB
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_format() const -> Glib::PropertyProxy_ReadOnly< ZlibCompressorFormat >;


  /** The level of compression from 0 (no compression) to 9 (most compression), -1 for the default level.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_level() const -> Glib::PropertyProxy_ReadOnly< int >;


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
   * @relates Gio::ZlibCompressor
   */
  GIOMM_API
  auto wrap(GZlibCompressor* object, bool take_copy = false) -> Glib::RefPtr<Gio::ZlibCompressor>;
}


#endif /* _GIOMM_ZLIBCOMPRESSOR_H */

