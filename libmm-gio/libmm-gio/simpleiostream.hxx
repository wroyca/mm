
#ifndef _GIOMM_SIMPLEIOSTREAM_H
#define _GIOMM_SIMPLEIOSTREAM_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2015 The giomm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-gio/iostream.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSimpleIOStream = struct _GSimpleIOStream;
using GSimpleIOStreamClass = struct _GSimpleIOStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API SimpleIOStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
/** A wrapper around an input and an output stream.
 *
 * SimpleIOStream creates an IOStream from an arbitrary InputStream and
 * OutputStream. This allows any pair of input and output streams to be used
 * with IOStream methods.
 *
 * This is useful when you obtained an InputStream and an OutputStream
 * by other means, for instance creating them with platform specific methods
 * such as Gio::UnixInputStream::create(), and you want
 * to take advantage of the methods provided by IOStream.
 *
 * @ingroup Streams
 *
 * @newin{2,46}
 */

class GIOMM_API SimpleIOStream : public Gio::IOStream
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SimpleIOStream;
  using CppClassType = SimpleIOStream_Class;
  using BaseObjectType = GSimpleIOStream;
  using BaseClassType = GSimpleIOStreamClass;

  // noncopyable
  SimpleIOStream(const SimpleIOStream&) = delete;
  auto operator=(const SimpleIOStream&) -> SimpleIOStream& = delete;

private:  friend class SimpleIOStream_Class;
  static CppClassType simpleiostream_class_;

protected:
  explicit SimpleIOStream(const Glib::ConstructParams& construct_params);
  explicit SimpleIOStream(GSimpleIOStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SimpleIOStream(SimpleIOStream&& src) noexcept;
  auto operator=(SimpleIOStream&& src) noexcept -> SimpleIOStream&;

  ~SimpleIOStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSimpleIOStream*       { return reinterpret_cast<GSimpleIOStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSimpleIOStream* { return reinterpret_cast<GSimpleIOStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSimpleIOStream*;

private:


protected:
  /** Creates a new SimpleIOStream wrapping @a input_stream and @a output_stream.
   *
   * @see IOStream
   *
   * @newin{2,46}
   *
   * @param input_stream An InputStream.
   * @param output_stream An OutputStream.
   * @returns A new SimpleIOStream instance.
	 */
    explicit SimpleIOStream(const Glib::RefPtr<InputStream>& input_stream, const Glib::RefPtr<OutputStream>& output_stream);


public:
  /** Creates a new SimpleIOStream wrapping @a input_stream and @a output_stream.
   *
   * @see IOStream
   *
   * @newin{2,46}
   *
   * @param input_stream An InputStream.
   * @param output_stream An OutputStream.
   * @returns A new SimpleIOStream instance.
	 */

  static auto create(const Glib::RefPtr<InputStream>& input_stream, const Glib::RefPtr<OutputStream>& output_stream) -> Glib::RefPtr<SimpleIOStream>;


  /** The GInputStream to read from.
   *
   * @newin{2,46}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InputStream> >;


  /** The GOutputStream to write to.
   *
   * @newin{2,46}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_output_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<OutputStream> >;


  // SimpleIOStream has no methods other than create(), signals nor vfuncs.


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
   * @relates Gio::SimpleIOStream
   */
  GIOMM_API
  auto wrap(GSimpleIOStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::SimpleIOStream>;
}


#endif /* _GIOMM_SIMPLEIOSTREAM_H */

