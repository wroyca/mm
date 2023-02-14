
#ifndef _GDKMM_PIXBUFFORMAT_H
#define _GDKMM_PIXBUFFORMAT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/mm-gdkconfig.hxx>
#include <libmm-glib/value.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GdkPixbufFormat GdkPixbufFormat;
}
#endif

namespace Gdk
{

  class GDKMM_API PixbufFormat
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

    void
    swap (PixbufFormat& other) noexcept;

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
    get_name () const -> Glib::ustring;

    auto
    get_description () const -> Glib::ustring;

    auto
    get_mime_types () const -> std::vector<Glib::ustring>;

    auto
    get_extensions () const -> std::vector<Glib::ustring>;

    auto
    is_save_option_supported (const Glib::ustring& option_key) const -> bool;

    auto
    is_writable () const -> bool;

    auto
    is_scalable () const -> bool;

    auto
    is_disabled () const -> bool;

    void
    set_disabled (bool disabled = true);

    auto
    get_license () const -> Glib::ustring;
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

    static void
    release_c_type (CType)
    {
    }
  };
#endif

} // namespace Gdk

namespace Gdk
{

  inline void
  swap (PixbufFormat& lhs, PixbufFormat& rhs) noexcept
  {
    lhs.swap (rhs);
  }

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkPixbufFormat* object, bool take_copy = false) -> Gdk::PixbufFormat;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GDKMM_API Value<Gdk::PixbufFormat>
    : public Glib::Value_Boxed<Gdk::PixbufFormat>
  {
  };
#endif

} // namespace Glib

#endif
