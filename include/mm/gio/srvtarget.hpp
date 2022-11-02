// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_SRVTARGET_H
#define _GIOMM_SRVTARGET_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2009 Jonathon Jongsma
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


#include <mm/glib/value.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GSrvTarget GSrvTarget; }
#endif

namespace Gio
{

/** DNS SRV record target
 *
 * SRV (service) records are used by some network protocols to provide
 * service-specific aliasing and load-balancing. For example, XMPP (Jabber) uses
 * SRV records to locate the XMPP server for a domain; rather than connecting
 * directly to "example.com" or assuming a specific server hostname like
 * "xmpp.example.com", an XMPP client would look up the "xmpp-client" SRV record
 * for "example.com", and then connect to whatever host was pointed to by that
 * record.
 *
 * You can use Resolver::lookup_service() or Resolver::lookup_service_async()
 * to find the SrvTargets for a given service. However, if you are simply
 * planning to connect to the remote service, you can use NetworkService's
 * SocketConnectable interface and not need to worry about SrvTarget at all.
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */
class GIOMM_API SrvTarget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SrvTarget;
  using BaseObjectType = GSrvTarget;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  SrvTarget();

  explicit SrvTarget(GSrvTarget* gobject, bool make_a_copy = true);

  SrvTarget(const SrvTarget& other);
  auto operator=(const SrvTarget& other) -> SrvTarget&;

  SrvTarget(SrvTarget&& other) noexcept;
  auto operator=(SrvTarget&& other) noexcept -> SrvTarget&;

  ~SrvTarget() noexcept;

  void swap(SrvTarget& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GSrvTarget*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GSrvTarget* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GSrvTarget*;

protected:
  GSrvTarget* gobject_;

private:

public:
  SrvTarget(const Glib::ustring& hostname, guint16 port, guint16 priority, guint16 weight);


  /** Gets @a target's hostname (in ASCII form; if you are going to present
   * this to the user, you should use Glib::hostname_is_ascii_encoded() to
   * check if it contains encoded Unicode segments, and use
   * Glib::hostname_to_unicode() to convert it if it does.)
   *
   * @newin{2,22}
   *
   * @return  @a target's hostname.
   */
  auto get_hostname() const -> Glib::ustring;

  /** Gets @a target's port
   *
   * @newin{2,22}
   *
   * @return  @a target's port.
   */
  auto get_port() const -> guint16;

  /** Gets @a target's priority. You should not need to look at this;
   * Resolver already sorts the targets according to the algorithm in
   * RFC 2782.
   *
   * @newin{2,22}
   *
   * @return  @a target's priority.
   */
  auto get_priority() const -> guint16;

  /** Gets @a target's weight. You should not need to look at this;
   * Resolver already sorts the targets according to the algorithm in
   * RFC 2782.
   *
   * @newin{2,22}
   *
   * @return  @a target's weight.
   */
  auto get_weight() const -> guint16;


};


} // namespace Gio


namespace Gio
{

/** @relates Gio::SrvTarget
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(SrvTarget& lhs, SrvTarget& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Gio

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::SrvTarget
 */
GIOMM_API
auto wrap(GSrvTarget* object, bool take_copy = false) -> Gio::SrvTarget;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GIOMM_API Value<Gio::SrvTarget> : public Glib::Value_Boxed<Gio::SrvTarget>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GIOMM_SRVTARGET_H */
