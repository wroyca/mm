
#ifndef _GIOMM_CONVERTEROUTPUTSTREAM_H
#define _GIOMM_CONVERTEROUTPUTSTREAM_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gio/filteroutputstream.hxx>
#include <libmm-gio/pollableoutputstream.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GConverterOutputStream = struct _GConverterOutputStream;
using GConverterOutputStreamClass = struct _GConverterOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API ConverterOutputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API Converter;
class GIOMM_API OutputStream;

/** ConverterOutputstream - Converter Output Stream.
 * Converter output stream implements OutputStream and allows conversion of
 * data of various types during reading.  ConverterOutputStream also implements
 * the PollableOutputStream interface.
 * @newin{2,34}
 */

class GIOMM_API ConverterOutputStream : public FilterOutputStream,
                                        public PollableOutputStream
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ConverterOutputStream;
  using CppClassType = ConverterOutputStream_Class;
  using BaseObjectType = GConverterOutputStream;
  using BaseClassType = GConverterOutputStreamClass;

  // noncopyable
  ConverterOutputStream(const ConverterOutputStream&) = delete;
  auto operator=(const ConverterOutputStream&) -> ConverterOutputStream& = delete;

private:  friend class ConverterOutputStream_Class;
  static CppClassType converteroutputstream_class_;

protected:
  explicit ConverterOutputStream(const Glib::ConstructParams& construct_params);
  explicit ConverterOutputStream(GConverterOutputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ConverterOutputStream(ConverterOutputStream&& src) noexcept;
  auto operator=(ConverterOutputStream&& src) noexcept -> ConverterOutputStream&;

  ~ConverterOutputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GConverterOutputStream*       { return reinterpret_cast<GConverterOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GConverterOutputStream* { return reinterpret_cast<GConverterOutputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GConverterOutputStream*;

private:


protected:
    explicit ConverterOutputStream(const Glib::RefPtr<OutputStream>& base_stream, const Glib::RefPtr<Converter>& converter);


public:

  /** Creates a new converter output stream for the @a base_stream.
   *
   * @param base_stream A OutputStream.
   * @param converter A Converter.
   * @return A new OutputStream.
   */


  static auto create(const Glib::RefPtr<OutputStream>& base_stream, const Glib::RefPtr<Converter>& converter) -> Glib::RefPtr<ConverterOutputStream>;


  // The C function returns an unreffed private member.

  /** Gets the Converter that is used by @a converter_stream.
   *
   * @newin{2,24}
   *
   * @return The converter of the converter output stream.
   */
  auto get_converter() -> Glib::RefPtr<Converter>;

  /** Gets the Converter that is used by @a converter_stream.
   *
   * @newin{2,24}
   *
   * @return The converter of the converter output stream.
   */
  auto get_converter() const -> Glib::RefPtr<const Converter>;

  /** The converter object.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_converter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Converter> >;


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
   * @relates Gio::ConverterOutputStream
   */
  GIOMM_API
  auto wrap(GConverterOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::ConverterOutputStream>;
}


#endif /* _GIOMM_CONVERTEROUTPUTSTREAM_H */
