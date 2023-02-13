
#ifndef _GIOMM_CHARSETCONVERTER_H
#define _GIOMM_CHARSETCONVERTER_H


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

#include <libmm-glib/object.hxx>
#include <libmm-gio/converter.hxx>
#include <libmm-gio/initable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GCharsetConverter = struct _GCharsetConverter;
using GCharsetConverterClass = struct _GCharsetConverterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API CharsetConverter_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** CharsetConverter - Convert between charsets.
 * CharsetConverter is an implementation of Converter based on GIConv.
 * @newin{2,34}
 */

class GIOMM_API CharsetConverter
: public Glib::Object, public Converter, public Initable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CharsetConverter;
  using CppClassType = CharsetConverter_Class;
  using BaseObjectType = GCharsetConverter;
  using BaseClassType = GCharsetConverterClass;

  // noncopyable
  CharsetConverter(const CharsetConverter&) = delete;
  auto operator=(const CharsetConverter&) -> CharsetConverter& = delete;

private:  friend class CharsetConverter_Class;
  static CppClassType charsetconverter_class_;

protected:
  explicit CharsetConverter(const Glib::ConstructParams& construct_params);
  explicit CharsetConverter(GCharsetConverter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CharsetConverter(CharsetConverter&& src) noexcept;
  auto operator=(CharsetConverter&& src) noexcept -> CharsetConverter&;

  ~CharsetConverter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GCharsetConverter*       { return reinterpret_cast<GCharsetConverter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GCharsetConverter* { return reinterpret_cast<GCharsetConverter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GCharsetConverter*;

private:


protected:
  // Handwritten to ignore the final GError** parameter in the *_new() function.
  // But it can throw, due to its call to Initable::init().
  explicit CharsetConverter(const Glib::ustring& to_charset, const Glib::ustring& from_charset);


public:
  /** Creates a new CharsetConverter.
   *
   * @newin{2,24}
   *
   * @param to_charset Destination charset.
   * @param from_charset Source charset.
   * @return A new CharsetConverter, or <tt>nullptr</tt> on error.
   * @throw Gio::Error
   */

  static auto create(const Glib::ustring& to_charset, const Glib::ustring& from_charset) -> Glib::RefPtr<CharsetConverter>;


  /** Sets the CharsetConverter::property_use_fallback() property.
   *
   * @newin{2,24}
   *
   * @param use_fallback <tt>true</tt> to use fallbacks.
   */
  void set_use_fallback(bool use_fallback);

  /** Gets the CharsetConverter::property_use_fallback() property.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if fallbacks are used by @a converter.
   */
  auto get_use_fallback() const -> bool;

  /** Gets the number of fallbacks that @a converter has applied so far.
   *
   * @newin{2,24}
   *
   * @return The number of fallbacks that @a converter has applied.
   */
  auto get_num_fallbacks() const -> guint;

  /** The character encoding to convert from.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_from_charset() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The character encoding to convert to.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_to_charset() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Use fallback (of form \\<hexval>) for invalid bytes.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_fallback() -> Glib::PropertyProxy< bool > ;

/** Use fallback (of form \\<hexval>) for invalid bytes.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_fallback() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gio::CharsetConverter
   */
  GIOMM_API
  auto wrap(GCharsetConverter* object, bool take_copy = false) -> Glib::RefPtr<Gio::CharsetConverter>;
}


#endif /* _GIOMM_CHARSETCONVERTER_H */

