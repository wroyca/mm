
#ifndef _GDKMM_CONTENTFORMATSBUILDER_H
#define _GDKMM_CONTENTFORMATSBUILDER_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The gtkmm Development Team
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


#include <libmm-gdk/contentformats.hxx>

namespace Gdk
{

/** Helper class for building Gdk::ContentFormats.
 *
 * @newin{3,94}
 */
class GDKMM_API ContentFormatsBuilder final
{
  // ContentFormatsBuilder is registered as a boxed type, but it has custom
  // reference-counting instead of copy/free functions, so we use it via RefPtr.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ContentFormatsBuilder;
  using BaseObjectType = GdkContentFormatsBuilder;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GdkContentFormatsBuilder*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GdkContentFormatsBuilder*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GdkContentFormatsBuilder*;

  ContentFormatsBuilder() = delete;

  // noncopyable
  ContentFormatsBuilder(const ContentFormatsBuilder&) = delete;
  auto operator=(const ContentFormatsBuilder&) -> ContentFormatsBuilder& = delete;

protected:
  // Do not derive this.  Gdk::ContentFormatsBuilder can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:
  // It's possible to specify gdk_content_formats_builder_new in the _CLASS_OPAQUE_REFCOUNTED()
  // macro, and have the create() method generated from there, but then it would not
  // be possible to add documentation to create().

  /** Creates a new %ContentFormatsBuilder object.
   *
   * The resulting builder would create an empty ContentFormats.
   * Use addition functions to add types to it.
   *
   * @return A new %ContentFormatsBuilder.
   */
  static auto create() -> Glib::RefPtr<ContentFormatsBuilder>;


  /** Appends all formats from @a formats to @a builder, skipping those that
   * already exist.
   *
   * @param formats The formats to add.
   */
  void add_formats(const Glib::RefPtr<const ContentFormats>& formats);

  /** Appends @a mime_type to @a builder if it has not already been added.
   *
   * @param mime_type A mime type.
   */
  void add_mime_type(const Glib::ustring& mime_type);

  /** Appends @a gtype to @a builder if it has not already been added.
   *
   * @param gtype A `GType`.
   */
  void add_gtype(GType gtype);


  /** Creates a new Gdk::ContentFormats.
   *
   * The %ContentFormatsBuilder is reset once this function returns;
   * you cannot call this function multiple times on the same builder instance.
   *
   * @return A newly created Gdk::ContentFormats with all the formats added to the builder.
   */
  auto to_formats() -> Glib::RefPtr<ContentFormats>;


};

} // namespace Gdk


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gdk::ContentFormatsBuilder
 */
GDKMM_API
auto wrap(GdkContentFormatsBuilder* object, bool take_copy = false) -> Glib::RefPtr<Gdk::ContentFormatsBuilder>;

} // namespace Glib


#endif /* _GDKMM_CONTENTFORMATSBUILDER_H */

