
#ifndef _GIOMM_FILTERINPUTSTREAM_H
#define _GIOMM_FILTERINPUTSTREAM_H


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

#include <libmm-gio/inputstream.hpp>
#include <libmm-glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFilterInputStream = struct _GFilterInputStream;
using GFilterInputStreamClass = struct _GFilterInputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API FilterInputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Filter Input Stream.
 * This is a base class for input stream implementations that perform some kind of filtering operation on a base stream.
 & Typical examples of filtering operations are character set conversion, compression and byte order flipping.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API FilterInputStream : public Gio::InputStream
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FilterInputStream;
  using CppClassType = FilterInputStream_Class;
  using BaseObjectType = GFilterInputStream;
  using BaseClassType = GFilterInputStreamClass;

  // noncopyable
  FilterInputStream(const FilterInputStream&) = delete;
  auto operator=(const FilterInputStream&) -> FilterInputStream& = delete;

private:  friend class FilterInputStream_Class;
  static CppClassType filterinputstream_class_;

protected:
  explicit FilterInputStream(const Glib::ConstructParams& construct_params);
  explicit FilterInputStream(GFilterInputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FilterInputStream(FilterInputStream&& src) noexcept;
  auto operator=(FilterInputStream&& src) noexcept -> FilterInputStream&;

  ~FilterInputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFilterInputStream*       { return reinterpret_cast<GFilterInputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFilterInputStream* { return reinterpret_cast<GFilterInputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GFilterInputStream*;

private:


protected:
  // This needs to be hand-coded because there is no public GFilterInputStream constructor.
  explicit FilterInputStream(const Glib::RefPtr<InputStream>& base_stream);

public:

  /** Gets the base stream for the filter stream.
   *
   * @return A InputStream.
   */
  auto get_base_stream() -> Glib::RefPtr<InputStream>;


  /** Gets the base stream for the filter stream.
   *
   * @return A InputStream.
   */
  auto get_base_stream() const -> Glib::RefPtr<const InputStream>;


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
  auto property_base_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InputStream> >;


  /** If the base stream should be closed when the filter stream is closed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_close_base_stream() -> Glib::PropertyProxy< bool > ;

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
   * @relates Gio::FilterInputStream
   */
  GIOMM_API
  auto wrap(GFilterInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::FilterInputStream>;
}


#endif /* _GIOMM_FILTERINPUTSTREAM_H */

