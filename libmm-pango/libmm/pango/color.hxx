// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_COLOR_H
#define _PANGOMM_COLOR_H

#include <libmm/pango/mm-pangoconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/utility.hxx>
#include <libmm/glib/value.hxx>
#include <pango/pango.h>

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT Color
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Color;
    using BaseObjectType = PangoColor;
#endif

    Color (const Color& other) noexcept;
    auto
    operator= (const Color& other) noexcept -> Color&;

    Color (Color&& other) noexcept;
    auto
    operator= (Color&& other) noexcept -> Color&;

    static auto
    get_type () -> GType G_GNUC_CONST;

    Color ();

    explicit Color (const PangoColor* gobject);

    auto
    gobj () -> PangoColor*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const PangoColor*
    {
      return &gobject_;
    }

  protected:
    PangoColor gobject_;

  private:
  public:
    explicit operator bool () const;

    auto
    get_red () const -> guint16;

    auto
    get_green () const -> guint16;

    auto
    get_blue () const -> guint16;

    auto
    set_red (const guint16& value) -> void;

    auto
    set_green (const guint16& value) -> void;

    auto
    set_blue (const guint16& value) -> void;

    auto
    parse (const glib::ustring& spec) -> bool;

    auto
    to_string () const -> glib::ustring;
  };

} // namespace pango

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoColor* object) -> pango::Color&;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (const PangoColor* object) -> const pango::Color&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_PANGO_SYMEXPORT Value<pango::Color> : public glib::Value_Boxed<pango::Color>
  {
  };
#endif

} // namespace glib

#endif
