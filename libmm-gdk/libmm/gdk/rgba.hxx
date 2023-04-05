// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_RGBA_H
#define _GDKMM_RGBA_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm/glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GdkRGBA GdkRGBA;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT RGBA
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = RGBA;
    using BaseObjectType = GdkRGBA;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    explicit RGBA (GdkRGBA* gobject, bool make_a_copy = true);

    RGBA (const RGBA& other);
    auto
    operator= (const RGBA& other) -> RGBA&;

    RGBA (RGBA&& other) noexcept;
    auto
    operator= (RGBA&& other) noexcept -> RGBA&;

    ~RGBA () noexcept;

    auto
    swap (RGBA& other) noexcept -> void;

    auto
    gobj () -> GdkRGBA*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GdkRGBA*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GdkRGBA*;

  protected:
    GdkRGBA* gobject_;

  private:
  public:
    RGBA ();

    explicit RGBA (const glib::ustring& value);

    RGBA (float red_, float green_, float blue_, float alpha_ = 1.0);

    auto
    set_grey_u (gushort value, gushort alpha = 65535) -> void;

    auto
    set_grey (float g, float alpha = 1.0) -> void;

    auto
    set_rgba_u (gushort red_,
                gushort green_,
                gushort blue_,
                gushort alpha_ = 65535) -> void;

    auto
    set_rgba (float red_, float green_, float blue_, float alpha_ = 1.0)
        -> void;

    auto
    set_hsv (float h, float s, float v, float alpha = 1.0) -> void;

    auto
    set_hsl (float h, float s, float l, float alpha = 1.0) -> void;

    auto
    set (const glib::ustring& spec) -> bool;

    auto
    get_red_u () const -> gushort;

    auto
    get_green_u () const -> gushort;

    auto
    get_blue_u () const -> gushort;

    auto
    get_alpha_u () const -> gushort;

    auto
    set_red_u (gushort value) -> void;

    auto
    set_green_u (gushort value) -> void;

    auto
    set_blue_u (gushort value) -> void;

    auto
    set_alpha_u (gushort value) -> void;

    auto
    get_red () const -> float;

    auto
    get_green () const -> float;

    auto
    get_blue () const -> float;

    auto
    get_alpha () const -> float;

    auto
    set_red (float value) -> void;

    auto
    set_green (float value) -> void;

    auto
    set_blue (float value) -> void;

    auto
    set_alpha (float value) -> void;

    auto
    to_string () const -> glib::ustring;

    auto
    is_clear () const -> bool;

    auto
    is_opaque () const -> bool;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  struct RGBATraits
  {
    typedef gdk::RGBA CppType;
    typedef GdkRGBA CType;
    typedef GdkRGBA CTypeNonConst;

    static auto
    to_c_type (const CppType& obj) -> CType
    {
      return *obj.gobj ();
    }

    static auto
    to_c_type (const CType& obj) -> CType
    {
      return obj;
    }

    static auto
    to_cpp_type (const CType& obj) -> CppType
    {
      return CppType (const_cast<CType*> (&obj), true);
    }

    static auto
    release_c_type (const CType&) -> void
    {
    }
  };
#endif

} // namespace gdk

namespace gdk
{
  LIBMM_GDK_SYMEXPORT auto
  operator== (const RGBA& lhs, const RGBA& rhs) -> bool;

  LIBMM_GDK_SYMEXPORT auto
  operator!= (const RGBA& lhs, const RGBA& rhs) -> bool;

} // namespace gdk

namespace gdk
{

  inline auto
  swap (RGBA& lhs, RGBA& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkRGBA* object, bool take_copy = false) -> gdk::RGBA;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::RGBA> : public glib::Value_Boxed<gdk::RGBA>
  {
  };
#endif

} // namespace glib

#endif
