
#ifndef _PANGOMM_FONT_H
#define _PANGOMM_FONT_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* font.h
 *
 * Copyright (C) 1998-1999 The gtkmm Development Team
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


#include <libmm-glib/object.hpp>
#include <libmm-pango/rectangle.hpp>
#include <libmm-pango/language.hpp>
#include <libmm-pango/glyph.hpp>
#include <libmm-pango/fontdescription.hpp>
#include <libmm-pango/fontmetrics.hpp>
#include <libmm-pango/coverage.hpp>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFont = struct _PangoFont;
using PangoFontClass = struct _PangoFontClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{ class PANGOMM_API Font_Class; } // namespace Pango
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Pango
{

const int    SCALE          = 1024;
const double SCALE_XX_SMALL = 0.5787037037037;
const double SCALE_X_SMALL  = 0.6444444444444;
const double SCALE_SMALL    = 0.8333333333333;
const double SCALE_MEDIUM   = 1.0;
const double SCALE_LARGE    = 1.2;
const double SCALE_X_LARGE  = 1.4399999999999;
const double SCALE_XX_LARGE = 1.728;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
class PANGOMM_API FontFace;
class PANGOMM_API FontMap;
#endif //DOXYGEN_SHOULD_SKIP_THIS

/** A Pango::Font is used to represent a font in a rendering-system-independent matter.
 */

class PANGOMM_API Font : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Font;
  using CppClassType = Font_Class;
  using BaseObjectType = PangoFont;
  using BaseClassType = PangoFontClass;

  // noncopyable
  Font(const Font&) = delete;
  auto operator=(const Font&) -> Font& = delete;

private:  friend class Font_Class;
  static CppClassType font_class_;

protected:
  explicit Font(const Glib::ConstructParams& construct_params);
  explicit Font(PangoFont* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Font(Font&& src) noexcept;
  auto operator=(Font&& src) noexcept -> Font&;

  ~Font() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> PangoFont*       { return reinterpret_cast<PangoFont*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const PangoFont* { return reinterpret_cast<PangoFont*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> PangoFont*;

private:

   // Deprecated

public:

  /** Returns a description of the font, with font size set in points.
   *
   * Use describe_with_absolute_size() if you want
   * the font size in device units.
   *
   * @return A newly-allocated `Pango::FontDescription` object.
   */
  auto describe() const -> FontDescription;

  /** Returns a description of the font, with absolute font size set
   * in device units.
   *
   * Use describe() if you want the font size in points.
   *
   * @newin{1,14}
   *
   * @return A newly-allocated `Pango::FontDescription` object.
   */
  auto describe_with_absolute_size() const -> FontDescription;

  /** Computes the coverage map for a given font and language tag.
   *
   * @param language The language tag.
   * @return A newly-allocated `Pango::Coverage`
   * object.
   */
  auto get_coverage(const Language& language) const -> Glib::RefPtr<Coverage>;

  /** Gets overall metric information for a font.
   * The metrics may be substantially different for different scripts.
   * However, this function overload returns the metrics for the entire font.
   */
  auto get_metrics() const -> FontMetrics;

  /** Gets overall metric information for a font. Since the metrics may be
   * substantially different for different scripts, a language tag can
   * be provided to indicate that the metrics should be retrieved that
   * correspond to the script(s) used by that language.
   *
   * @param language Language tag used to determine which script to get the metrics
   * for.
   * @return A Pango::Metrics object.
   */
  auto get_metrics(const Language& language) const -> FontMetrics;


  /** Gets the logical and ink extents of a glyph within a font. The
   * coordinate system for each rectangle has its origin at the
   * base line and horizontal origin of the character with increasing
   * coordinates extending to the right and down. The macros PANGO_ASCENT(),
   * PANGO_DESCENT(), PANGO_LBEARING(), and PANGO_RBEARING can be used to convert
   * from the extents rectangle to more traditional font metrics. The units
   * of the rectangles are in 1/PANGO_SCALE of a device unit.
   *
   * @param glyph The glyph index.
   * @param ink_rect Rectangle used to store the extents of the glyph as drawn.
   * @param logical_rect Rectangle used to store the logical extents of the glyph.
   */
  void get_glyph_extents(Glyph glyph, Rectangle& ink_rect, Rectangle& logical_rect) const;


  /** Gets the font map for which the font was created.
   *
   * Note that the font maintains a *weak* reference to
   * the font map, so if all references to font map are
   * dropped, the font map will be finalized even if there
   * are fonts created with the font map that are still alive.
   * In that case this function will return <tt>nullptr</tt>.
   *
   * It is the responsibility of the user to ensure that the
   * font map is kept alive. In most uses this is not an issue
   * as a `Pango::Context` holds a reference to the font map.
   *
   * @newin{1,10}
   *
   * @return The `Pango::FontMap`
   * for the font.
   */
  auto get_font_map() -> Glib::RefPtr<FontMap>;

  /** Gets the font map for which the font was created.
   *
   * Note that the font maintains a *weak* reference to
   * the font map, so if all references to font map are
   * dropped, the font map will be finalized even if there
   * are fonts created with the font map that are still alive.
   * In that case this function will return <tt>nullptr</tt>.
   *
   * It is the responsibility of the user to ensure that the
   * font map is kept alive. In most uses this is not an issue
   * as a `Pango::Context` holds a reference to the font map.
   *
   * @newin{1,10}
   *
   * @return The `Pango::FontMap`
   * for the font.
   */
  auto get_font_map() const -> Glib::RefPtr<const FontMap>;


  /** Gets the `Pango::FontFace` to which @a font belongs.
   *
   * @newin{1,46}
   *
   * @return The `Pango::FontFace`.
   */
  auto get_face() -> Glib::RefPtr<FontFace>;

  /** Gets the `Pango::FontFace` to which @a font belongs.
   *
   * @newin{1,46}
   *
   * @return The `Pango::FontFace`.
   */
  auto get_face() const -> Glib::RefPtr<const FontFace>;


  /** Returns whether the font provides a glyph for this character.
   *
   * @newin{1,44}
   *
   * @param wc A Unicode character.
   * @return <tt>true</tt> if @a font can render @a wc.
   */
  auto has_char(gunichar wc) const -> bool;

  /** Get the ink extents of a glyph within the font.
   * @param glyph The glyph index.
   * @return The extents of the glyph as drawn.
   */
  auto get_glyph_ink_extents(Glyph glyph) const -> Rectangle;

  /** Gets the logical extents of a glyph within the font.
   * @param glyph The glyph index.
   * @return The logical extents of the glyph.
   */
  auto get_glyph_logical_extents(Glyph glyph) const -> Rectangle;

// PangoFontClass is hidden when PANGO_DISABLE_DEPRECATED is defined.
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
   * @relates Pango::Font
   */
  PANGOMM_API
  auto wrap(PangoFont* object, bool take_copy = false) -> Glib::RefPtr<Pango::Font>;
}


#endif /* _PANGOMM_FONT_H */

