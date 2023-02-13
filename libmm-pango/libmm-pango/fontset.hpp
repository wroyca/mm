
#ifndef _PANGOMM_FONTSET_H
#define _PANGOMM_FONTSET_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* fontset.h
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

#include <mm/glib/object.hpp>
#include <mm/pango/language.hpp>
#include <mm/pango/font.hpp>
#include <mm/pango/fontmetrics.hpp>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFontset = struct _PangoFontset;
using PangoFontsetClass = struct _PangoFontsetClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{ class PANGOMM_API Fontset_Class; } // namespace Pango
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Pango
{

/** A Pango::Fontset is used to represent a set of fonts.
 */

class PANGOMM_API Fontset : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Fontset;
  using CppClassType = Fontset_Class;
  using BaseObjectType = PangoFontset;
  using BaseClassType = PangoFontsetClass;

  // noncopyable
  Fontset(const Fontset&) = delete;
  auto operator=(const Fontset&) -> Fontset& = delete;

private:  friend class Fontset_Class;
  static CppClassType fontset_class_;

protected:
  explicit Fontset(const Glib::ConstructParams& construct_params);
  explicit Fontset(PangoFontset* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Fontset(Fontset&& src) noexcept;
  auto operator=(Fontset&& src) noexcept -> Fontset&;

  ~Fontset() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> PangoFontset*       { return reinterpret_cast<PangoFontset*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const PangoFontset* { return reinterpret_cast<PangoFontset*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> PangoFontset*;

private:


public:

  /** Returns the font in the fontset that contains the best glyph for a
   * Unicode character.
   *
   * @param wc A Unicode character.
   * @return A `Pango::Font`.
   */
  auto get_font(guint wc) const -> Glib::RefPtr<Font>;

  /** Get overall metric information for the fonts in the fontset.
   *
   * @return A `Pango::FontMetrics` object.
   */
  auto get_metrics() const -> FontMetrics;

  /** For instance,
   * bool on_foreach(const Glib::RefPtr<Pango::Font>& font);
   */
  typedef sigc::slot<bool(const Glib::RefPtr<Font>&)> ForeachSlot;

  /** Iterates through all the fonts in a fontset, calling @a slot for
   * each one. If @a slot returns true, that stops the iteration.
   *
   * @since-1.4
   *
   * @param slot Callback function
   */
  void foreach(const ForeachSlot& slot);


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
   * @relates Pango::Fontset
   */
  PANGOMM_API
  auto wrap(PangoFontset* object, bool take_copy = false) -> Glib::RefPtr<Pango::Fontset>;
}


#endif /* _PANGOMM_FONTSET_H */

