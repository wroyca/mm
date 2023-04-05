// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_CHECKSUM_H
#define _GLIBMM_CHECKSUM_H

#include <glib.h>
#include <libmm/glib/value.hxx>
#include <string>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GChecksum GChecksum;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GChecksum GChecksum;
}
#endif

namespace glib
{

  class LIBMM_GLIB_SYMEXPORT Checksum
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Checksum;
    using BaseObjectType = GChecksum;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    Checksum ();

    explicit Checksum (GChecksum* gobject, bool make_a_copy = true);

    Checksum (const Checksum& other);
    auto
    operator= (const Checksum& other) -> Checksum&;

    Checksum (Checksum&& other) noexcept;
    auto
    operator= (Checksum&& other) noexcept -> Checksum&;

    ~Checksum () noexcept;

    auto
    swap (Checksum& other) noexcept -> void;

    auto
    gobj () -> GChecksum*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GChecksum*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GChecksum*;

  protected:
    GChecksum* gobject_;

  private:
  public:
    enum class Type
    {
      MD5,
      SHA1,
      SHA256,
      SHA512,
      SHA384
    };

    explicit Checksum (Type checksum_type);

    explicit operator bool () const;

    auto
    reset () -> void;

    auto
    update (const guchar* data, gssize length) -> void;

    auto
    update (const std::string& data) -> void;

    auto
    get_digest (guint8* buffer, gsize* digest_len) const -> void;

    auto
    get_string () const -> std::string;

    static auto
    compute_checksum (Type checksum_type, const guchar* data, gsize length)
        -> std::string;

    static auto
    compute_checksum (Type checksum_type, const std::string& str)
        -> std::string;

    static auto
    get_length (Type checksum_type) -> gssize;
  };

} // namespace glib

namespace glib
{

  inline auto
  swap (Checksum& lhs, Checksum& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace glib

namespace glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GChecksum* object, bool take_copy = false) -> glib::Checksum;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GLIB_SYMEXPORT Value<glib::Checksum>
    : public glib::Value_Boxed<glib::Checksum>
  {
  };
#endif

} // namespace glib

#endif
