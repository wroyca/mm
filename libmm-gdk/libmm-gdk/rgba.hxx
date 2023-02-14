
#ifndef _GDKMM_RGBA_H
#define _GDKMM_RGBA_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm-glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GdkRGBA GdkRGBA;
}
#endif

namespace Gdk
{

  class GDKMM_API RGBA
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

    void
    swap (RGBA& other) noexcept;

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

    explicit RGBA (const Glib::ustring& value);

    RGBA (float red_, float green_, float blue_, float alpha_ = 1.0);

    void
    set_grey_u (gushort value, gushort alpha = 65535);

    void
    set_grey (float g, float alpha = 1.0);

    void
    set_rgba_u (gushort red_,
                gushort green_,
                gushort blue_,
                gushort alpha_ = 65535);

    void
    set_rgba (float red_, float green_, float blue_, float alpha_ = 1.0);

    void
    set_hsv (float h, float s, float v, float alpha = 1.0);

    void
    set_hsl (float h, float s, float l, float alpha = 1.0);

    auto
    set (const Glib::ustring& spec) -> bool;

    auto
    get_red_u () const -> gushort;

    auto
    get_green_u () const -> gushort;

    auto
    get_blue_u () const -> gushort;

    auto
    get_alpha_u () const -> gushort;

    void
    set_red_u (gushort value);

    void
    set_green_u (gushort value);

    void
    set_blue_u (gushort value);

    void
    set_alpha_u (gushort value);

    auto
    get_red () const -> float;

    auto
    get_green () const -> float;

    auto
    get_blue () const -> float;

    auto
    get_alpha () const -> float;

    void
    set_red (float value);

    void
    set_green (float value);

    void
    set_blue (float value);

    void
    set_alpha (float value);

    auto
    to_string () const -> Glib::ustring;

    auto
    is_clear () const -> bool;

    auto
    is_opaque () const -> bool;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  struct RGBATraits
  {
    typedef Gdk::RGBA CppType;
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

    static void
    release_c_type (const CType&)
    {
    }
  };
#endif

} // namespace Gdk

namespace Gdk
{

  GDKMM_API
  auto
  operator== (const RGBA& lhs, const RGBA& rhs) -> bool;

  GDKMM_API
  auto
  operator!= (const RGBA& lhs, const RGBA& rhs) -> bool;

} // namespace Gdk

namespace Gdk
{

  inline void
  swap (RGBA& lhs, RGBA& rhs) noexcept
  {
    lhs.swap (rhs);
  }

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkRGBA* object, bool take_copy = false) -> Gdk::RGBA;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GDKMM_API Value<Gdk::RGBA> : public Glib::Value_Boxed<Gdk::RGBA>
  {
  };
#endif

} // namespace Glib

#endif
