
#ifndef _PANGOMM_FONTMAP_H
#define _PANGOMM_FONTMAP_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* fontmap.h
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

#include <libmm-glib/object.hpp>
#include <libmm-gio/listmodel.hpp>
#include <libmm-pango/font.hpp>
#include <libmm-pango/fontset.hpp>
#include <libmm-pango/fontfamily.hpp>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFontMap = struct _PangoFontMap;
using PangoFontMapClass = struct _PangoFontMapClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{ class PANGOMM_API FontMap_Class; } // namespace Pango
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Pango
{

class PANGOMM_API Context;

/** A %Pango::FontMap represents the set of fonts available for a particular rendering system.
 *
 * This is an abstract base class with implementations being specific to
 * particular rendering systems.
 *
 * @see Pango::CairoFontMap::get_default()
 */

class PANGOMM_API FontMap : public Glib::Object, public Gio::ListModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FontMap;
  using CppClassType = FontMap_Class;
  using BaseObjectType = PangoFontMap;
  using BaseClassType = PangoFontMapClass;

  // noncopyable
  FontMap(const FontMap&) = delete;
  auto operator=(const FontMap&) -> FontMap& = delete;

private:  friend class FontMap_Class;
  static CppClassType fontmap_class_;

protected:
  explicit FontMap(const Glib::ConstructParams& construct_params);
  explicit FontMap(PangoFontMap* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FontMap(FontMap&& src) noexcept;
  auto operator=(FontMap&& src) noexcept -> FontMap&;

  ~FontMap() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> PangoFontMap*       { return reinterpret_cast<PangoFontMap*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const PangoFontMap* { return reinterpret_cast<PangoFontMap*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> PangoFontMap*;

private:


public:

  /** Load the font in the fontmap that is the closest match for @a desc.
   *
   * @param context The `Pango::Context` the font will be used with.
   * @param desc A `Pango::FontDescription` describing the font to load.
   * @return The newly allocated `Pango::Font`
   * loaded, or <tt>nullptr</tt> if no font matched.
   */
  auto load_font(const Glib::RefPtr<Context>& context, const FontDescription& desc) const -> Glib::RefPtr<Font>;

  /** Load a set of fonts in the fontmap that can be used to render
   * a font matching @a desc.
   *
   * @param context The `Pango::Context` the font will be used with.
   * @param desc A `Pango::FontDescription` describing the font to load.
   * @param language A `Pango::Language` the fonts will be used for.
   * @return The newly allocated
   * `Pango::Fontset` loaded, or <tt>nullptr</tt> if no font matched.
   */
  auto load_fontset(const Glib::RefPtr<Context>& context, const FontDescription& desc, const Language& language) const -> Glib::RefPtr<Fontset>;


  /** Creates a `Pango::Context` connected to @a fontmap.
   *
   * This is equivalent to Pango::Context::new() followed by
   * Pango::Context::set_font_map().
   *
   * If you are using Pango as part of a higher-level system,
   * that system may have it's own way of create a `Pango::Context`.
   * For instance, the GTK toolkit has, among others,
   * gtk_widget_get_pango_context(). Use those instead.
   *
   * @newin{1,22}
   *
   * @return The newly allocated `Pango::Context`,
   * which should be freed with Glib::object_unref().
   */
  auto create_context() -> Glib::RefPtr<Context>;

  /** List all families for the fontmap.
   * @return an array of pointers to Pango::FontFamily objects.
   */
  auto list_families() const -> std::vector<Glib::RefPtr<FontFamily>>;


  /** Returns the current serial number of @a fontmap.
   *
   * The serial number is initialized to an small number larger than zero
   * when a new fontmap is created and is increased whenever the fontmap
   * is changed. It may wrap, but will never have the value 0. Since it can
   * wrap, never compare it with "less than", always use "not equals".
   *
   * The fontmap can only be changed using backend-specific API, like changing
   * fontmap resolution.
   *
   * This can be used to automatically detect changes to a `Pango::FontMap`,
   * like in `Pango::Context`.
   *
   * @newin{1,32,4}
   *
   * @return The current serial number of @a fontmap.
   */
  auto get_serial() const -> guint;


  /** Gets a font family by name.
   *
   * @newin{2,50}
   *
   * @param name A family name.
   * @return The `Pango::FontFamily`.
   */
  auto get_family(const Glib::ustring& name) -> Glib::RefPtr<FontFamily>;

  /** Gets a font family by name.
   *
   * @newin{2,50}
   *
   * @param name A family name.
   * @return The `Pango::FontFamily`.
   */
  auto get_family(const Glib::ustring& name) const -> Glib::RefPtr<const FontFamily>;


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
   * @relates Pango::FontMap
   */
  PANGOMM_API
  auto wrap(PangoFontMap* object, bool take_copy = false) -> Glib::RefPtr<Pango::FontMap>;
}


#endif /* _PANGOMM_FONTMAP_H */

