
#ifndef _GIOMM_ENUMS_H
#define _GIOMM_ENUMS_H

#include <libmm-gio/gioconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <gio/gio.h>
#include <libmm-glib/value.hpp>


namespace Gio
{

// BIG_ENDIAN and LITTLE_ENDIAN are defined as preprocessor macros somewhere.
/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var DataStreamByteOrder BIG_ENDIAN_ORDER
 * Selects Big Endian byte order.
 *
 *  @var DataStreamByteOrder LITTLE_ENDIAN_ORDER
 * Selects Little Endian byte order.
 *
 *  @var DataStreamByteOrder HOST_ENDIAN_ORDER
 * Selects endianness based on host machine's architecture.
 *
 *  @enum DataStreamByteOrder
 *
 * DataStreamByteOrder is used to ensure proper endianness of streaming data sources
 * across various machine architectures.
 *
 * @ingroup giommEnums
 */
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
class GIOMM_API Value<Gio::DataStreamByteOrder> : public Glib::Value_Enum<Gio::DataStreamByteOrder>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/**
 *  @var DataStreamNewlineType LF
 * Selects "LF" line endings, common on most modern UNIX platforms.
 *
 *  @var DataStreamNewlineType CR
 * Selects "CR" line endings.
 *
 *  @var DataStreamNewlineType CR_LF
 * Selects "CR, LF" line ending, common on Microsoft Windows.
 *
 *  @var DataStreamNewlineType ANY
 * Automatically try to handle any line ending type.
 *
 *  @enum DataStreamNewlineType
 *
 * DataStreamNewlineType is used when checking for or setting the line endings for a given file.
 *
 * @ingroup giommEnums
 */
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
class GIOMM_API Value<Gio::DataStreamNewlineType> : public Glib::Value_Enum<Gio::DataStreamNewlineType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/**
 *  @var SocketFamily INVALID
 * No address family.
 *
 *  @var SocketFamily IPV4
 * The IPv4 family.
 *
 *  @var SocketFamily IPV6
 * The IPv6 family.
 *
 *  @var SocketFamily UNIX
 * The UNIX domain family.
 *
 *  @enum SocketFamily
 *
 * The protocol family of a SocketAddress. (These values are
 * identical to the system defines AF_INET, AF_INET6 and AF_UNIX,
 * if available.)
 *
 * @newin{2,22}
 *
 * @ingroup giommEnums
 */
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
class GIOMM_API Value<Gio::SocketFamily> : public Glib::Value_Enum<Gio::SocketFamily>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/**
 *  @var TlsAuthenticationMode NONE
 * Client authentication not required.
 *
 *  @var TlsAuthenticationMode REQUESTED
 * Client authentication is requested.
 *
 *  @var TlsAuthenticationMode REQUIRED
 * Client authentication is required.
 *
 *  @enum TlsAuthenticationMode
 *
 * The client authentication mode for a TlsServerConnection.
 *
 * @newin{2,28}
 *
 * @ingroup giommEnums
 */
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
class GIOMM_API Value<Gio::TlsAuthenticationMode> : public Glib::Value_Enum<Gio::TlsAuthenticationMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/**
 *  @var TlsCertificateFlags NO_FLAGS
 * No flags set. @newin{2,74}
 *
 *  @var TlsCertificateFlags UNKNOWN_CA
 * The signing certificate authority is
 * not known.
 *
 *  @var TlsCertificateFlags BAD_IDENTITY
 * The certificate does not match the
 * expected identity of the site that it was retrieved from.
 *
 *  @var TlsCertificateFlags NOT_ACTIVATED
 * The certificate's activation time
 * is still in the future.
 *
 *  @var TlsCertificateFlags EXPIRED
 * The certificate has expired.
 *
 *  @var TlsCertificateFlags REVOKED
 * The certificate has been revoked
 * according to the TlsConnection's certificate revocation list.
 *
 *  @var TlsCertificateFlags INSECURE
 * The certificate's algorithm is
 * considered insecure.
 *
 *  @var TlsCertificateFlags GENERIC_ERROR
 * Some other error occurred validating
 * the certificate.
 *
 *  @var TlsCertificateFlags VALIDATE_ALL
 * The combination of all of the above
 * flags.
 *
 *  @enum TlsCertificateFlags
 *
 * A set of flags describing TLS certification validation. This can be
 * used to describe why a particular certificate was rejected (for
 * example, in TlsConnection::signal_accept_certificate()).
 *
 * GLib guarantees that if certificate verification fails, at least one
 * flag will be set, but it does not guarantee that all possible flags
 * will be set. Accordingly, you may not safely decide to ignore any
 * particular type of error. For example, it would be incorrect to mask
 * Gio::TlsCertificateFlags::EXPIRED if you want to allow expired certificates,
 * because this could potentially be the only error flag set even if
 * other problems exist with the certificate.
 *
 * @newin{2,28}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>TlsCertificateFlags operator|(TlsCertificateFlags, TlsCertificateFlags)</tt><br>
 * <tt>TlsCertificateFlags operator&(TlsCertificateFlags, TlsCertificateFlags)</tt><br>
 * <tt>TlsCertificateFlags operator^(TlsCertificateFlags, TlsCertificateFlags)</tt><br>
 * <tt>TlsCertificateFlags operator~(TlsCertificateFlags)</tt><br>
 * <tt>TlsCertificateFlags& operator|=(TlsCertificateFlags&, TlsCertificateFlags)</tt><br>
 * <tt>TlsCertificateFlags& operator&=(TlsCertificateFlags&, TlsCertificateFlags)</tt><br>
 * <tt>TlsCertificateFlags& operator^=(TlsCertificateFlags&, TlsCertificateFlags)</tt><br>
 */
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

/** @ingroup giommEnums */
inline auto operator|(TlsCertificateFlags lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags
  { return static_cast<TlsCertificateFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(TlsCertificateFlags lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags
  { return static_cast<TlsCertificateFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(TlsCertificateFlags lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags
  { return static_cast<TlsCertificateFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(TlsCertificateFlags flags) -> TlsCertificateFlags
  { return static_cast<TlsCertificateFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(TlsCertificateFlags& lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags&
  { return (lhs = static_cast<TlsCertificateFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(TlsCertificateFlags& lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags&
  { return (lhs = static_cast<TlsCertificateFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(TlsCertificateFlags& lhs, TlsCertificateFlags rhs) -> TlsCertificateFlags&
  { return (lhs = static_cast<TlsCertificateFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::TlsCertificateFlags> : public Glib::Value_Flags<Gio::TlsCertificateFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{


} // namespace Gio


#endif /* _GIOMM_ENUMS_H */

