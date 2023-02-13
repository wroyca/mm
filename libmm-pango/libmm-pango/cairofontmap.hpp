
#ifndef _PANGOMM_CAIROFONTMAP_H
#define _PANGOMM_CAIROFONTMAP_H

#include <mm/pango/mm-pangoconfig.hpp>


#include <mm/glib/ustring.hpp>
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


#include <mm/glib/interface.hpp>
#include <mm/pango/fontmap.hpp>
#include <mm/cairo/enums.hpp>
#include <pango/pangocairo.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _PangoCairoFontMapIface PangoCairoFontMapIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoCairoFontMap = struct _PangoCairoFontMap;
using PangoCairoFontMapClass = struct _PangoCairoFontMapClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{ class PANGOMM_API CairoFontMap_Class; } // namespace Pango
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Pango
{

/** %Pango::CairoFontMap is an interface implemented by font maps for use with Cairo.
 *
 * The actual type of the font map will depend on the particular
 * font technology Cairo was compiled to use.
 */

class PANGOMM_API CairoFontMap : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CairoFontMap;
  using CppClassType = CairoFontMap_Class;
  using BaseObjectType = PangoCairoFontMap;
  using BaseClassType = PangoCairoFontMapIface;

  // noncopyable
  CairoFontMap(const CairoFontMap&) = delete;
  auto operator=(const CairoFontMap&) -> CairoFontMap& = delete;

private:
  friend class CairoFontMap_Class;
  static CppClassType cairofontmap_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  CairoFontMap();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit CairoFontMap(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit CairoFontMap(PangoCairoFontMap* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CairoFontMap(CairoFontMap&& src) noexcept;
  auto operator=(CairoFontMap&& src) noexcept -> CairoFontMap&;

  ~CairoFontMap() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> PangoCairoFontMap*       { return reinterpret_cast<PangoCairoFontMap*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const PangoCairoFontMap* { return reinterpret_cast<PangoCairoFontMap*>(gobject_); }

private:


public:

  /** Gets a default %Pango::CairoFontMap to use with Cairo.
   *
   * Note that the type of the returned object will depend
   * on the particular font backend Cairo was compiled to use.
   * You generally should only use the Pango::FontMap and
   * %Pango::CairoFontMap API on the returned object.
   *
   * The default Cairo fontmap can be changed by using
   * set_default(). This can be used to change the Cairo font backend
   * that the default fontmap uses for example.
   *
   * Note that since %Pango 1.32.6, the default fontmap is per-thread.
   * Each thread gets its own default fontmap. In this way,
   * PangoCairo can be used safely from multiple threads.
   *
   * To use %Pango::CairoFontMap API, do something like
   * @code
   * auto font_map = Pango::CairoFontMap::get_default();
   * auto cairo_font_map = std::dynamic_pointer_cast<Pango::CairoFontMap>(font_map);
   * if (cairo_font_map)
   *   cairo_font_map->do_something();
   * @endcode
   *
   * @newin{1,10}
   *
   * @return The default PangoCairo fontmap for the current thread.
   */
  static auto get_default() -> Glib::RefPtr<FontMap>;


  /** Sets a default `Pango::CairoFontMap` to use with Cairo.
   *
   * This can be used to change the Cairo font backend that the
   * default fontmap uses for example. The old default font map
   * is unreffed and the new font map referenced.
   *
   * Note that since Pango 1.32.6, the default fontmap is per-thread.
   * This function only changes the default fontmap for
   * the current thread. Default fontmaps of existing threads
   * are not changed. Default fontmaps of any new threads will
   * still be created using new().
   *
   * A value of <tt>nullptr</tt> for @a fontmap will cause the current default
   * font map to be released and a new default font map to be created
   * on demand, using new().
   *
   * @newin{1,22}
   */
  void set_default();


  /** Gets the type of Cairo font backend that @a fontmap uses.
   *
   * @newin{1,18}
   *
   * @return The `cairo_font_type_t` cairo font backend type.
   */
  auto get_font_type() const -> Cairo::FontType;


  /** Sets the resolution for the fontmap.
   *
   * This is a scale factor between
   * points specified in a `Pango::FontDescription` and Cairo units. The
   * default value is 96, meaning that a 10 point font will be 13
   * units high. (10 * 96. / 72. = 13.3).
   *
   * @newin{1,10}
   *
   * @param dpi The resolution in "dots per inch". (Physical inches aren't actually
   * involved; the terminology is conventional.).
   */
  void set_resolution(double dpi);

  /** Gets the resolution for the fontmap.
   *
   * See set_resolution().
   *
   * @newin{1,10}
   *
   * @return The resolution in "dots per inch".
   */
  auto get_resolution() const -> double;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Pango


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Pango::CairoFontMap
   */
  PANGOMM_API
  auto wrap(PangoCairoFontMap* object, bool take_copy = false) -> Glib::RefPtr<Pango::CairoFontMap>;

} // namespace Glib


#endif /* _PANGOMM_CAIROFONTMAP_H */

