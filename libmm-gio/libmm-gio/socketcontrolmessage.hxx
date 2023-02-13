
#ifndef _GIOMM_SOCKETCONTROLMESSAGE_H
#define _GIOMM_SOCKETCONTROLMESSAGE_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The giomm Development Team
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


#include <libmm-glib/object.hxx>
#include <set>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketControlMessage = struct _GSocketControlMessage;
using GSocketControlMessageClass = struct _GSocketControlMessageClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API SocketControlMessage_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** A Socket control message.
 * A %SocketControlMessage is a special-purpose utility message that can be
 * sent to or received from a Socket. These types of messages are often
 * called "ancillary data".
 *
 * The message can represent some sort of special instruction to or
 * information from the socket or can represent a special kind of transfer to
 * the peer (for example, sending a file description over a UNIX socket).
 *
 * These messages are sent with Gio::Socket::send() and received with
 * Gio::Socket::receive().
 *
 * To extend the set of control message that can be sent, subclass this class
 * and override the get_size_vfunc(), get_level_vfunc(), get_type_vfunc() and
 * serialize_vfunc() methods.
 *
 * To extend the set of control messages that can be received, subclass this
 * class and implement a DeserializeFunc function. Typically it would be a
 * static class method. Also, make sure you register the DeserializeFunc
 * function with a call to add_deserialize_func() before calling
 * Gio::Socket::receive() to read such a message.
 *
 * @ingroup NetworkIO
 * @newin{2,28}
 */

class GIOMM_API SocketControlMessage : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SocketControlMessage;
  using CppClassType = SocketControlMessage_Class;
  using BaseObjectType = GSocketControlMessage;
  using BaseClassType = GSocketControlMessageClass;

  // noncopyable
  SocketControlMessage(const SocketControlMessage&) = delete;
  auto operator=(const SocketControlMessage&) -> SocketControlMessage& = delete;

private:  friend class SocketControlMessage_Class;
  static CppClassType socketcontrolmessage_class_;

protected:
  explicit SocketControlMessage(const Glib::ConstructParams& construct_params);
  explicit SocketControlMessage(GSocketControlMessage* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SocketControlMessage(SocketControlMessage&& src) noexcept;
  auto operator=(SocketControlMessage&& src) noexcept -> SocketControlMessage&;

  ~SocketControlMessage() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSocketControlMessage*       { return reinterpret_cast<GSocketControlMessage*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSocketControlMessage* { return reinterpret_cast<GSocketControlMessage*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSocketControlMessage*;

private:


protected:
  SocketControlMessage();

public:

  /** Tries to deserialize a socket control message of a given
   *  @a level and @a type. This will ask all known (to GType) subclasses
   * of SocketControlMessage if they can understand this kind
   * of message and if so deserialize it into a SocketControlMessage.
   *
   * If there is no implementation for this kind of control message, <tt>nullptr</tt>
   * will be returned.
   *
   * @newin{2,22}
   *
   * @param level A socket level.
   * @param type A socket control message type for the given @a level.
   * @param size The size of the data in bytes.
   * @param data Pointer to the message data.
   * @return The deserialized message or <tt>nullptr</tt>.
   */
  static auto deserialize(int level, int type, gsize size, gpointer data) -> Glib::RefPtr<SocketControlMessage>;

  /** Returns the "level" (i.e.\ the originating protocol) of the control message.
   * This is often SOL_SOCKET.
   *
   * @newin{2,22}
   *
   * @return An integer describing the level.
   */
  auto get_level() const -> int;

  /** Returns the protocol specific type of the control message.
   * For instance, for UNIX fd passing this would be SCM_RIGHTS.
   *
   * @newin{2,22}
   *
   * @return An integer describing the type of control message.
   */
  auto get_msg_type() const -> int;

  /** Returns the space required for the control message, not including
   * headers or alignment.
   *
   * @newin{2,22}
   *
   * @return The number of bytes required.
   */
  auto get_size() const -> gsize;

  /** Converts the data in the message to bytes placed in the
   * message.
   *
   *  @a data is guaranteed to have enough space to fit the size
   * returned by g_socket_control_message_get_size() on this
   * object.
   *
   * @newin{2,22}
   *
   * @param data A buffer to write data to.
   */
  void serialize(gpointer data);

protected:
  // The deserialize vfunc in GLib is a class virtual function (not associated
  // with an instance). Such functions don't exist in C++.
  // But it must be wrapped in one way or another. g_socket_control_message_deserialize()
  // assumes that all subclasses of GSocketControlMessage override this vfunc.
  // A user-program can crash, if any subclass does not.
  // https://gitlab.gnome.org/GNOME/glibmm/issues/52


  /** Pointer to a function that can be called from deserialize() or
   * g_socket_control_message_deserialize().
   *
   * For instance,
   * @code
   * Glib::RefPtr<SocketControlMessage> my_deserialize_func(
   *   int level, int type, gsize size, gpointer data);
   * @endcode
   *
   * @param level A socket level.
   * @param type A socket control message type for the given @a level.
   * @param size The size of the data in bytes.
   * @param data Pointer to the message data (element-type guint8).
   * @return The deserialized message or an empty Glib::RefPtr.
   *         The returned message can be a subclass of %SocketControlMessage.
   */
  using DeserializeFunc = Glib::RefPtr<SocketControlMessage> (*)
    (int level, int type, gsize size, gpointer data);

  /** Register a deserialize function.
   *
   * If the same function is registered multiple times, only the first
   * registration has an effect.
   *
   * In GLib, %deserialize() is a class virtual function (not associated
   * with an instance). Such functions don't exist in C++. A function registered
   * with %add_deserialize_func() is a kind of replacement.
   */
  static void add_deserialize_func(DeserializeFunc func);

    virtual auto get_size_vfunc() const -> gsize;

    virtual auto get_level_vfunc() const -> int;

    virtual auto get_type_vfunc() const -> int;

    virtual void serialize_vfunc(gpointer data);


private:
  // Functions registered with add_deserialize_func().
  static std::set<DeserializeFunc> m_deserialize_funcs;


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
   * @relates Gio::SocketControlMessage
   */
  GIOMM_API
  auto wrap(GSocketControlMessage* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketControlMessage>;
}


#endif /* _GIOMM_SOCKETCONTROLMESSAGE_H */

