
#ifndef _GIOMM_SOCKETADDRESSENUMERATOR_H
#define _GIOMM_SOCKETADDRESSENUMERATOR_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The giomm Development Team
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

#include <libmm-glib/interface.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/asyncresult.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketAddressEnumerator = struct _GSocketAddressEnumerator;
using GSocketAddressEnumeratorClass = struct _GSocketAddressEnumeratorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API SocketAddressEnumerator_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API SocketAddress;

/** Enumerator type for objects that contain or generate SocketAddresses
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API SocketAddressEnumerator : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SocketAddressEnumerator;
  using CppClassType = SocketAddressEnumerator_Class;
  using BaseObjectType = GSocketAddressEnumerator;
  using BaseClassType = GSocketAddressEnumeratorClass;

  // noncopyable
  SocketAddressEnumerator(const SocketAddressEnumerator&) = delete;
  auto operator=(const SocketAddressEnumerator&) -> SocketAddressEnumerator& = delete;

private:  friend class SocketAddressEnumerator_Class;
  static CppClassType socketaddressenumerator_class_;

protected:
  explicit SocketAddressEnumerator(const Glib::ConstructParams& construct_params);
  explicit SocketAddressEnumerator(GSocketAddressEnumerator* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SocketAddressEnumerator(SocketAddressEnumerator&& src) noexcept;
  auto operator=(SocketAddressEnumerator&& src) noexcept -> SocketAddressEnumerator&;

  ~SocketAddressEnumerator() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSocketAddressEnumerator*       { return reinterpret_cast<GSocketAddressEnumerator*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSocketAddressEnumerator* { return reinterpret_cast<GSocketAddressEnumerator*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSocketAddressEnumerator*;

private:


public:

  /** Retrieves the next SocketAddress from @a enumerator. Note that this
   * may block for some amount of time. (Eg, a NetworkAddress may need
   * to do a DNS lookup before it can return an address.) Use
   * g_socket_address_enumerator_next_async() if you need to avoid
   * blocking.
   *
   * If @a enumerator is expected to yield addresses, but for some reason
   * is unable to (eg, because of a DNS error), then the first call to
   * g_socket_address_enumerator_next() will return an appropriate error
   * in * @a error. However, if the first call to
   * g_socket_address_enumerator_next() succeeds, then any further
   * internal errors (other than @a cancellable being triggered) will be
   * ignored.
   *
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return A SocketAddress (owned by the caller), or <tt>nullptr</tt> on
   * error (in which case * @a error will be set) or if there are no
   * more addresses.
   *
   * @throws Glib::Error
   */
  auto next(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketAddress>;

  /// A next() convenience overload.
  auto next() -> Glib::RefPtr<SocketAddress>;

  /** Asynchronously retrieves the next SocketAddress from the enumerator and then calls @a slot,
   * which must call next_finish() to get the result.
   *
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param slot A callback slot to call after the resolution completes.
   */
  void next_async(const Glib::RefPtr<Cancellable>& cancellable, const SlotAsyncReady& slot);

  /** Asynchronously retrieves the next SocketAddress from the enumerator and then calls @a slot,
   * which must call next_finish() to get the result.
   *
   * @param slot A callback slot to call after the resolution completes.
   */
  void next_async(const SlotAsyncReady& slot);


  /** Retrieves the result of a completed call to
   * g_socket_address_enumerator_next_async(). See
   * g_socket_address_enumerator_next() for more information about
   * error handling.
   *
   * @param result A AsyncResult.
   * @return A SocketAddress (owned by the caller), or <tt>nullptr</tt> on
   * error (in which case * @a error will be set) or if there are no
   * more addresses.
   *
   * @throws Glib::Error
   */
  auto next_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<SocketAddress>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::SocketAddressEnumerator
   */
  GIOMM_API
  auto wrap(GSocketAddressEnumerator* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketAddressEnumerator>;
}


#endif /* _GIOMM_SOCKETADDRESSENUMERATOR_H */

