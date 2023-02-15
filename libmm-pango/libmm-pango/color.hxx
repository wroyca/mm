// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_COLOR_H
#define _PANGOMM_COLOR_H

#include <libmm-pango/mm-pangoconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/utility.hxx>
#include <libmm-glib/value.hxx>
#include <pango/pango.h>

namespace Pango
{

  class PANGOMM_API Color
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
    parse (const Glib::ustring& spec) -> bool;

    auto
    to_string () const -> Glib::ustring;
  };

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoColor* object) -> Pango::Color&;

  PANGOMM_API
  auto
  wrap (const PangoColor* object) -> const Pango::Color&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class PANGOMM_API Value<Pango::Color> : public Glib::Value_Boxed<Pango::Color>
  {
  };
#endif

} // namespace Glib

#endif
