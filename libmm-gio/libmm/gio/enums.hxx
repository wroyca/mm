// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ENUMS_H
#define _GIOMM_ENUMS_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/glib/value.hxx>

namespace gio
{

  enum class DataStreamByteOrder
  {
    BIG_ENDIAN_ORDER,
    LITTLE_ENDIAN_ORDER,
    HOST_ENDIAN_ORDER
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DataStreamByteOrder>
    : public glib::Value_Enum<gio::DataStreamByteOrder>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  enum class DataStreamNewlineType
  {
    LF,
    CR,
    CR_LF,
    ANY
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DataStreamNewlineType>
    : public glib::Value_Enum<gio::DataStreamNewlineType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  enum class SocketFamily
  {
    INVALID = 0,
    UNIX = GLIB_SYSDEF_AF_UNIX,
    IPV4 = GLIB_SYSDEF_AF_INET,
    IPV6 = GLIB_SYSDEF_AF_INET6
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::SocketFamily>
    : public glib::Value_Enum<gio::SocketFamily>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  enum class TlsAuthenticationMode
  {
    NONE,
    REQUESTED,
    REQUIRED
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::TlsAuthenticationMode>
    : public glib::Value_Enum<gio::TlsAuthenticationMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  enum class TlsCertificateFlags
  {
    NO_FLAGS = 0x0,
    UNKNOWN_CA = (1 << 0),
    BAD_IDENTITY = (1 << 1),
    NOT_ACTIVATED = (1 << 2),
    EXPIRED = (1 << 3),
    REVOKED = (1 << 4),
    INSECURE = (1 << 5),
    GENERIC_ERROR = (1 << 6),
    VALIDATE_ALL = 0x007f
  };

  inline auto
  operator| (TlsCertificateFlags lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (static_cast<unsigned> (lhs) |
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (TlsCertificateFlags lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (static_cast<unsigned> (lhs) &
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (TlsCertificateFlags lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (static_cast<unsigned> (lhs) ^
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(TlsCertificateFlags flags) -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (TlsCertificateFlags& lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags&
  {
    return (lhs = static_cast<TlsCertificateFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (TlsCertificateFlags& lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags&
  {
    return (lhs = static_cast<TlsCertificateFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (TlsCertificateFlags& lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags&
  {
    return (lhs = static_cast<TlsCertificateFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::TlsCertificateFlags>
    : public glib::Value_Flags<gio::TlsCertificateFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

}

#endif
