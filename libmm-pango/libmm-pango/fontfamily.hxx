
#ifndef _PANGOMM_FONTFAMILY_H
#define _PANGOMM_FONTFAMILY_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* fontfamily.h
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

#include <libmm-glib/object.hxx>
#include <libmm-gio/listmodel.hxx>
#include <libmm-pango/fontface.hxx>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFontFamily = struct _PangoFontFamily;
using PangoFontFamilyClass = struct _PangoFontFamilyClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{ class PANGOMM_API FontFamily_Class; } // namespace Pango
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Pango
{

/** A Pango::FontFamily is used to represent a family of related font faces.
 * The faces in a family share a common design, but differ in slant, weight, width and other aspects.
 */

class PANGOMM_API FontFamily : public Glib::Object, public Gio::ListModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FontFamily;
  using CppClassType = FontFamily_Class;
  using BaseObjectType = PangoFontFamily;
  using BaseClassType = PangoFontFamilyClass;

  // noncopyable
  FontFamily(const FontFamily&) = delete;
  auto operator=(const FontFamily&) -> FontFamily& = delete;

private:  friend class FontFamily_Class;
  static CppClassType fontfamily_class_;

protected:
  explicit FontFamily(const Glib::ConstructParams& construct_params);
  explicit FontFamily(PangoFontFamily* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FontFamily(FontFamily&& src) noexcept;
  auto operator=(FontFamily&& src) noexcept -> FontFamily&;

  ~FontFamily() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> PangoFontFamily*       { return reinterpret_cast<PangoFontFamily*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const PangoFontFamily* { return reinterpret_cast<PangoFontFamily*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> PangoFontFamily*;

private:


public:
  /** Lists the different font faces that make up family.
   * The faces in a family share a common design, but differ in slant, weight, width and other aspects.
   * @return an array of pointers to Pango::FontFace objects.
   */
  auto list_faces() const -> std::vector<Glib::RefPtr<FontFace>>;


  /** Gets the name of the family.
   *
   * The name is unique among all fonts for the font backend and can
   * be used in a `Pango::FontDescription` to specify that a face from
   * this family is desired.
   *
   * @return The name of the family. This string is owned
   * by the family object and must not be modified or freed.
   */
  auto get_name() const -> Glib::ustring;

  /** A monospace font is a font designed for text display where the the
   * characters form a regular grid.
   *
   * For Western languages this would
   * mean that the advance width of all characters are the same, but
   * this categorization also includes Asian fonts which include
   * double-width characters: characters that occupy two grid cells.
   * Glib::unichar_iswide() returns a result that indicates whether a
   * character is typically double-width in a monospace font.
   *
   * The best way to find out the grid-cell size is to call
   * Pango::FontMetrics::get_approximate_digit_width(), since the
   * results of Pango::FontMetrics::get_approximate_char_width() may
   * be affected by double-width characters.
   *
   * @newin{1,4}
   *
   * @return <tt>true</tt> if the family is monospace.
   */
  auto is_monospace() const -> bool;

  /** A variable font is a font which has axes that can be modified to
   * produce different faces.
   *
   * @newin{1,44}
   *
   * @return <tt>true</tt> if the family is variable.
   */
  auto is_variable() const -> bool;


  /** Gets the `Pango::FontFace` of @a family with the given name.
   *
   * @newin{1,46}
   *
   * @param name The name of a face. If the name is <tt>nullptr</tt>,
   * the family's default face (fontconfig calls it "Regular")
   * will be returned.
   * @return The `Pango::FontFace`,
   * or <tt>nullptr</tt> if no face with the given name exists.
   */
  auto get_face(const Glib::ustring& name =  {}) -> Glib::RefPtr<FontFace>;

  /** Gets the `Pango::FontFace` of @a family with the given name.
   *
   * @newin{1,46}
   *
   * @param name The name of a face. If the name is <tt>nullptr</tt>,
   * the family's default face (fontconfig calls it "Regular")
   * will be returned.
   * @return The `Pango::FontFace`,
   * or <tt>nullptr</tt> if no face with the given name exists.
   */
  auto get_face(const Glib::ustring& name =  {}) const -> Glib::RefPtr<const FontFace>;

// PangoFontFamilyClass is hidden when PANGO_DISABLE_DEPRECATED is defined.
// Don't wrap vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/*
struct FontFamilyRefPtrTraits
{
  typedef Glib::RefPtr<FontFamily> CppType;
  typedef PangoFontFamily *        CType;
  typedef PangoFontFamily *        CTypeNonConst;

  static CType   to_c_type      (const CppType& ptr) { return Glib::unwrap (ptr);                   }
  static CType   to_c_type      (CType          ptr) { return ptr;                                  }
  static CppType to_cpp_type    (CType          ptr) { return FontFamily::wrap_specific_type (ptr); }
  static void    release_c_type (CType          ptr) { g_object_unref (ptr);                        }
};
*/

} // namespace Pango


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Pango::FontFamily
   */
  PANGOMM_API
  auto wrap(PangoFontFamily* object, bool take_copy = false) -> Glib::RefPtr<Pango::FontFamily>;
}


#endif /* _PANGOMM_FONTFAMILY_H */

