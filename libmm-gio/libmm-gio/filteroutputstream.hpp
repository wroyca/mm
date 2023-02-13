
#ifndef _GIOMM_FILTEROUTPUTSTREAM_H
#define _GIOMM_FILTEROUTPUTSTREAM_H


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

#include <libmm-gio/outputstream.hpp>
#include <libmm-glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFilterOutputStream = struct _GFilterOutputStream;
using GFilterOutputStreamClass = struct _GFilterOutputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API FilterOutputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Filter Output Stream.
 *
 * This is a base class for output stream implementations that perform some kind of filtering operation on a base stream.
 * Typical examples of filtering operations are character set conversion, compression and byte order flipping.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API FilterOutputStream : public Gio::OutputStream
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FilterOutputStream;
  using CppClassType = FilterOutputStream_Class;
  using BaseObjectType = GFilterOutputStream;
  using BaseClassType = GFilterOutputStreamClass;

  // noncopyable
  FilterOutputStream(const FilterOutputStream&) = delete;
  auto operator=(const FilterOutputStream&) -> FilterOutputStream& = delete;

private:  friend class FilterOutputStream_Class;
  static CppClassType filteroutputstream_class_;

protected:
  explicit FilterOutputStream(const Glib::ConstructParams& construct_params);
  explicit FilterOutputStream(GFilterOutputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FilterOutputStream(FilterOutputStream&& src) noexcept;
  auto operator=(FilterOutputStream&& src) noexcept -> FilterOutputStream&;

  ~FilterOutputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFilterOutputStream*       { return reinterpret_cast<GFilterOutputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFilterOutputStream* { return reinterpret_cast<GFilterOutputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GFilterOutputStream*;

private:


protected:
  // This needs to be hand-coded because there is no public GFilterOutputStream constructor.
  explicit FilterOutputStream(const Glib::RefPtr<OutputStream>& base_stream);

public:

  /** Gets the base stream for the filter stream.
   *
   * @return A OutputStream.
   */
  auto get_base_stream() -> Glib::RefPtr<OutputStream>;


  /** Gets the base stream for the filter stream.
   *
   * @return A OutputStream.
   */
  auto get_base_stream() const -> Glib::RefPtr<const OutputStream>;


  /** Returns whether the base stream will be closed when @a stream is
   * closed.
   *
   * @return <tt>true</tt> if the base stream will be closed.
   */
  auto get_close_base_stream() const -> bool;

  /** Sets whether the base stream will be closed when @a stream is closed.
   *
   * @param close_base <tt>true</tt> to close the base stream.
   */
  void set_close_base_stream(bool close_base =  true);

  /** The underlying base stream on which the io ops will be done.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_base_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<OutputStream> >;


  /** If the base stream should be closed when the filter stream is closed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_close_base_stream() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gio::FilterOutputStream
   */
  GIOMM_API
  auto wrap(GFilterOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::FilterOutputStream>;
}


#endif /* _GIOMM_FILTEROUTPUTSTREAM_H */

