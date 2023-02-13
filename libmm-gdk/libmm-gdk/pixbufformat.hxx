
#ifndef _GDKMM_PIXBUFFORMAT_H
#define _GDKMM_PIXBUFFORMAT_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <libmm-gdk/mm-gdkconfig.hxx>
#include <libmm-glib/value.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GdkPixbufFormat GdkPixbufFormat; }
#endif

namespace Gdk
{

class GDKMM_API PixbufFormat
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = PixbufFormat;
  using BaseObjectType = GdkPixbufFormat;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;


  explicit PixbufFormat(GdkPixbufFormat* gobject, bool make_a_copy = true);

  PixbufFormat(const PixbufFormat& other);
  auto operator=(const PixbufFormat& other) -> PixbufFormat&;

  PixbufFormat(PixbufFormat&& other) noexcept;
  auto operator=(PixbufFormat&& other) noexcept -> PixbufFormat&;

  ~PixbufFormat() noexcept;

  void swap(PixbufFormat& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GdkPixbufFormat*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GdkPixbufFormat* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GdkPixbufFormat*;

protected:
  GdkPixbufFormat* gobject_;

private:


public:

  PixbufFormat();


  /** Returns the name of the format.
   *
   * @newin{2,2}
   *
   * @return The name of the format.
   */
  auto get_name() const -> Glib::ustring;

  /** Returns a description of the format.
   *
   * @newin{2,2}
   *
   * @return A description of the format.
   */
  auto get_description() const -> Glib::ustring;


  /** Returns the mime types supported by the format.
   *
   * @newin{2,2}
   *
   * @return An array of mime types.
   */
  auto get_mime_types() const -> std::vector<Glib::ustring>;

  /** Returns the filename extensions typically used for files in the
   * given format.
   *
   * @newin{2,2}
   *
   * @return An array of
   * filename extensions.
   */
  auto get_extensions() const -> std::vector<Glib::ustring>;

  /** Returns <tt>true</tt> if the save option specified by @a option_key is supported when
   * saving a pixbuf using the module implementing @a format.
   *
   * See save() for more information about option keys.
   *
   * @newin{2,36}
   *
   * @param option_key The name of an option.
   * @return <tt>true</tt> if the specified option is supported.
   */
  auto is_save_option_supported(const Glib::ustring& option_key) const -> bool;

  /** Returns whether pixbufs can be saved in the given format.
   *
   * @newin{2,2}
   *
   * @return Whether pixbufs can be saved in the given format.
   */
  auto is_writable() const -> bool;


  /** Returns whether this image format is scalable.
   *
   * If a file is in a scalable format, it is preferable to load it at
   * the desired size, rather than loading it at the default size and
   * scaling the resulting pixbuf to the desired size.
   *
   * @newin{2,6}
   *
   * @return Whether this image format is scalable.
   */
  auto is_scalable() const -> bool;

  /** Returns whether this image format is disabled.
   *
   * See set_disabled().
   *
   * @newin{2,6}
   *
   * @return Whether this image format is disabled.
   */
  auto is_disabled() const -> bool;

  /** Disables or enables an image format.
   *
   * If a format is disabled, GdkPixbuf won't use the image loader for
   * this format to load images.
   *
   * Applications can use this to avoid using image loaders with an
   * inappropriate license, see get_license().
   *
   * @newin{2,6}
   *
   * @param disabled <tt>true</tt> to disable the format @a format.
   */
  void set_disabled(bool disabled =  true);

  /** Returns information about the license of the image loader for the format.
   *
   * The returned string should be a shorthand for a well known license, e.g.
   * "LGPL", "GPL", "QPL", "GPL/QPL", or "other" to indicate some other license.
   *
   * @newin{2,6}
   *
   * @return A string describing the license of the pixbuf format.
   */
  auto get_license() const -> Glib::ustring;


};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct PixbufFormatTraits
{
  typedef PixbufFormat  CppType;
  typedef const GdkPixbufFormat*      CType;
  typedef GdkPixbufFormat*            CTypeNonConst;

  static auto   to_c_type      (const CppType& obj) -> CType { return obj.gobj();     }
  static auto   to_c_type      (CType          ptr) -> CType { return ptr;                   }
  static auto to_cpp_type    (CType          ptr) -> CppType { return PixbufFormat(const_cast<GdkPixbufFormat*>(ptr), true); }
  static void    release_c_type (CType          /* ptr */) { /* Doesn't happen */ }
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gdk


namespace Gdk
{

/** @relates Gdk::PixbufFormat
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(PixbufFormat& lhs, PixbufFormat& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Gdk

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gdk::PixbufFormat
 */
GDKMM_API
auto wrap(GdkPixbufFormat* object, bool take_copy = false) -> Gdk::PixbufFormat;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GDKMM_API Value<Gdk::PixbufFormat> : public Glib::Value_Boxed<Gdk::PixbufFormat>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GDKMM_PIXBUFFORMAT_H */

