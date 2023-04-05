// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PIXBUFFORMAT_H
#define _GDKMM_PIXBUFFORMAT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/mm-gdkconfig.hxx>
#include <libmm/glib/value.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GdkPixbufFormat GdkPixbufFormat;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT PixbufFormat
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PixbufFormat;
    using BaseObjectType = GdkPixbufFormat;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    explicit PixbufFormat (GdkPixbufFormat* gobject, bool make_a_copy = true);

    PixbufFormat (const PixbufFormat& other);
    auto
    operator= (const PixbufFormat& other) -> PixbufFormat&;

    PixbufFormat (PixbufFormat&& other) noexcept;
    auto
    operator= (PixbufFormat&& other) noexcept -> PixbufFormat&;

    ~PixbufFormat () noexcept;

    auto
    swap (PixbufFormat& other) noexcept -> void;

    auto
    gobj () -> GdkPixbufFormat*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GdkPixbufFormat*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GdkPixbufFormat*;

  protected:
    GdkPixbufFormat* gobject_;

  private:
  public:
    PixbufFormat ();

    auto
    get_name () const -> glib::ustring;

    auto
    get_description () const -> glib::ustring;

    auto
    get_mime_types () const -> std::vector<glib::ustring>;

    auto
    get_extensions () const -> std::vector<glib::ustring>;

    auto
    is_save_option_supported (const glib::ustring& option_key) const -> bool;

    auto
    is_writable () const -> bool;

    auto
    is_scalable () const -> bool;

    auto
    is_disabled () const -> bool;

    auto
    set_disabled (bool disabled = true) -> void;

    auto
    get_license () const -> glib::ustring;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  struct PixbufFormatTraits
  {
    typedef PixbufFormat CppType;
    typedef const GdkPixbufFormat* CType;
    typedef GdkPixbufFormat* CTypeNonConst;

    static auto
    to_c_type (const CppType& obj) -> CType
    {
      return obj.gobj ();
    }

    static auto
    to_c_type (CType ptr) -> CType
    {
      return ptr;
    }

    static auto
    to_cpp_type (CType ptr) -> CppType
    {
      return PixbufFormat (const_cast<GdkPixbufFormat*> (ptr), true);
    }

    static auto
    release_c_type (CType) -> void
    {
    }
  };
#endif

} // namespace gdk

namespace gdk
{

  inline auto
  swap (PixbufFormat& lhs, PixbufFormat& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkPixbufFormat* object, bool take_copy = false) -> gdk::PixbufFormat;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::PixbufFormat>
    : public glib::Value_Boxed<gdk::PixbufFormat>
  {
  };
#endif

} // namespace glib

#endif
