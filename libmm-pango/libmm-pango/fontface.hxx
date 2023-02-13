
#ifndef _PANGOMM_FONTFACE_H
#define _PANGOMM_FONTFACE_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* fontface.h
 *
 * Copyright 2001      The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <libmm-pango/fontdescription.hpp>
#include <libmm-glib/object.hpp>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFontFace = struct _PangoFontFace;
using PangoFontFaceClass = struct _PangoFontFaceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{ class PANGOMM_API FontFace_Class; } // namespace Pango
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Pango
{
class PANGOMM_API FontFamily;

/** A Pango::FontFace is used to represent a group of fonts with the same family, slant, weight, width, but varying sizes.
 */

class PANGOMM_API FontFace : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FontFace;
  using CppClassType = FontFace_Class;
  using BaseObjectType = PangoFontFace;
  using BaseClassType = PangoFontFaceClass;

  // noncopyable
  FontFace(const FontFace&) = delete;
  auto operator=(const FontFace&) -> FontFace& = delete;

private:  friend class FontFace_Class;
  static CppClassType fontface_class_;

protected:
  explicit FontFace(const Glib::ConstructParams& construct_params);
  explicit FontFace(PangoFontFace* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FontFace(FontFace&& src) noexcept;
  auto operator=(FontFace&& src) noexcept -> FontFace&;

  ~FontFace() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> PangoFontFace*       { return reinterpret_cast<PangoFontFace*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const PangoFontFace* { return reinterpret_cast<PangoFontFace*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> PangoFontFace*;

private:


public:

  /** Returns the family, style, variant, weight and stretch of
   * a Pango::FontFace. The size field of the resulting font description
   * will be unset.
   *
   * @return A  Pango::FontDescription
   * holding the description of the face.
   */
  auto describe() const -> FontDescription;

  /** Gets a name representing the style of this face among the
   * different faces in the `Pango::FontFamily` for the face. The
   * name is suitable for displaying to users.
   *
   * @return The face name for the face. This string is
   * owned by the face object and must not be modified or freed.
   */
  auto get_name() const -> Glib::ustring;

  /** List the available sizes for a font. This is only applicable to bitmap fonts.
   * For scalable fonts this returns an empty array.
   * The sizes returned are in Pango units and are sorted in ascending order.
   */
  auto list_sizes() const -> std::vector<int>;


  /** Returns whether a `Pango::FontFace` is synthesized by the underlying
   * font rendering engine from another face, perhaps by shearing, emboldening,
   * or lightening it.
   *
   * @newin{1,18}
   *
   * @return Whether @a face is synthesized.
   */
  auto is_synthesized() const -> bool;

  /** Gets the `Pango::FontFamily` that @a face belongs to.
   *
   * @newin{1,46}
   *
   * @return The `Pango::FontFamily`.
   */
  auto get_family() -> Glib::RefPtr<FontFamily>;

  /** Gets the `Pango::FontFamily` that @a face belongs to.
   *
   * @newin{1,46}
   *
   * @return The `Pango::FontFamily`.
   */
  auto get_family() const -> Glib::RefPtr<const FontFamily>;

// PangoFontFaceClass is hidden when PANGO_DISABLE_DEPRECATED is defined.
// Don't wrap vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Pango */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Pango::FontFace
   */
  PANGOMM_API
  auto wrap(PangoFontFace* object, bool take_copy = false) -> Glib::RefPtr<Pango::FontFace>;
}


#endif /* _PANGOMM_FONTFACE_H */

