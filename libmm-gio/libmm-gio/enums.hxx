// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ENUMS_H
#define _GIOMM_ENUMS_H

#include <libmm-gio/mm-gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm-glib/value.hxx>

namespace Gio
{

  enum class DataStreamByteOrder
  {
    BIG_ENDIAN_ORDER,
    LITTLE_ENDIAN_ORDER,
    HOST_ENDIAN_ORDER
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::DataStreamByteOrder>
    : public Glib::Value_Enum<Gio::DataStreamByteOrder>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  enum class DataStreamNewlineType
  {
    LF,
    CR,
    CR_LF,
    ANY
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::DataStreamNewlineType>
    : public Glib::Value_Enum<Gio::DataStreamNewlineType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  enum class SocketFamily
  {
    INVALID = 0,
    UNIX = GLIB_SYSDEF_AF_UNIX,
    IPV4 = GLIB_SYSDEF_AF_INET,
    IPV6 = GLIB_SYSDEF_AF_INET6
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::SocketFamily>
    : public Glib::Value_Enum<Gio::SocketFamily>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  enum class TlsAuthenticationMode
  {
    NONE,
    REQUESTED,
    REQUIRED
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::TlsAuthenticationMode>
    : public Glib::Value_Enum<Gio::TlsAuthenticationMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
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

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::TlsCertificateFlags>
    : public Glib::Value_Flags<Gio::TlsCertificateFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

}

#endif
