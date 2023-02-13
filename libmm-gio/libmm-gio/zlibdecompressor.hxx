
#ifndef _GIOMM_ZLIBDECOMPRESSOR_H
#define _GIOMM_ZLIBDECOMPRESSOR_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-glib/object.hpp>
#include <libmm-gio/converter.hpp>
#include <libmm-gio/zlibcompressor.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GZlibDecompressor = struct _GZlibDecompressor;
using GZlibDecompressorClass = struct _GZlibDecompressorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API ZlibDecompressor_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API FileInfo;

/** ZlibDecompressor - Zlib decompressor.
 * ZlibDecompressor is an implementation of Converter that decompresses data
 * compressed with zlib.
 * @newin{2,34}
 */

class GIOMM_API ZlibDecompressor : public Glib::Object, public Converter
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ZlibDecompressor;
  using CppClassType = ZlibDecompressor_Class;
  using BaseObjectType = GZlibDecompressor;
  using BaseClassType = GZlibDecompressorClass;

  // noncopyable
  ZlibDecompressor(const ZlibDecompressor&) = delete;
  auto operator=(const ZlibDecompressor&) -> ZlibDecompressor& = delete;

private:  friend class ZlibDecompressor_Class;
  static CppClassType zlibdecompressor_class_;

protected:
  explicit ZlibDecompressor(const Glib::ConstructParams& construct_params);
  explicit ZlibDecompressor(GZlibDecompressor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ZlibDecompressor(ZlibDecompressor&& src) noexcept;
  auto operator=(ZlibDecompressor&& src) noexcept -> ZlibDecompressor&;

  ~ZlibDecompressor() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GZlibDecompressor*       { return reinterpret_cast<GZlibDecompressor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GZlibDecompressor* { return reinterpret_cast<GZlibDecompressor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GZlibDecompressor*;

private:


protected:
    explicit ZlibDecompressor(ZlibCompressorFormat format);


public:

  /** Creates a new ZlibDecompressor.
   *
   * @newin{2,24}
   *
   * @param format The format to use for the compressed data.
   * @return A new ZlibDecompressor.
   */


  static auto create(ZlibCompressorFormat format) -> Glib::RefPtr<ZlibDecompressor>;


  /** Retrieves the FileInfo constructed from the GZIP header data
   * of compressed data processed by @a compressor, or <tt>nullptr</tt> if @a decompressor's
   * ZlibDecompressor::property_format() property is not Gio::ZlibCompressorFormat::GZIP,
   * or the header data was not fully processed yet, or it not present in the
   * data stream at all.
   *
   * @newin{2,26}
   *
   * @return A FileInfo, or <tt>nullptr</tt>.
   */
  auto get_file_info() -> Glib::RefPtr<FileInfo>;

  /** Retrieves the FileInfo constructed from the GZIP header data
   * of compressed data processed by @a compressor, or <tt>nullptr</tt> if @a decompressor's
   * ZlibDecompressor::property_format() property is not Gio::ZlibCompressorFormat::GZIP,
   * or the header data was not fully processed yet, or it not present in the
   * data stream at all.
   *
   * @newin{2,26}
   *
   * @return A FileInfo, or <tt>nullptr</tt>.
   */
  auto get_file_info() const -> Glib::RefPtr<const FileInfo>;

  /** A FileInfo containing the information found in the GZIP header
   * of the data stream processed, or <tt>nullptr</tt> if the header was not yet
   * fully processed, is not present at all, or the compressor's
   * ZlibDecompressor::property_format() property is not Gio::ZlibCompressorFormat::GZIP.
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
   * @relates Gio::ZlibDecompressor
   */
  GIOMM_API
  auto wrap(GZlibDecompressor* object, bool take_copy = false) -> Glib::RefPtr<Gio::ZlibDecompressor>;
}


#endif /* _GIOMM_ZLIBDECOMPRESSOR_H */

