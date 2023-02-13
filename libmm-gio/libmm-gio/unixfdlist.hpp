
#ifndef _GIOMM_UNIXFDLIST_H
#define _GIOMM_UNIXFDLIST_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
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


#include <mm/glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixFDList = struct _GUnixFDList;
using GUnixFDListClass = struct _GUnixFDListClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API UnixFDList_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** UnixFDList - An object containing a set of UNIX file descriptors.
 * A UnixFDList contains a list of file descriptors. It owns the file
 * descriptors that it contains, closing them when finalized.
 *
 * It may be wrapped in a UnixFDMessage and sent over a Socket in the
 * G_SOCKET_ADDRESS_UNIX family by using Gio::Socket::send() and received
 * using Gio::Socket::receive().
 *
 * @ingroup NetworkIO
 * @newin{2,28}
 */

class GIOMM_API UnixFDList : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = UnixFDList;
  using CppClassType = UnixFDList_Class;
  using BaseObjectType = GUnixFDList;
  using BaseClassType = GUnixFDListClass;

  // noncopyable
  UnixFDList(const UnixFDList&) = delete;
  auto operator=(const UnixFDList&) -> UnixFDList& = delete;

private:  friend class UnixFDList_Class;
  static CppClassType unixfdlist_class_;

protected:
  explicit UnixFDList(const Glib::ConstructParams& construct_params);
  explicit UnixFDList(GUnixFDList* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  UnixFDList(UnixFDList&& src) noexcept;
  auto operator=(UnixFDList&& src) noexcept -> UnixFDList&;

  ~UnixFDList() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GUnixFDList*       { return reinterpret_cast<GUnixFDList*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GUnixFDList* { return reinterpret_cast<GUnixFDList*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GUnixFDList*;

private:

  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


protected:
  UnixFDList();


  explicit UnixFDList(const std::vector<int>&  fds);

  explicit UnixFDList(const std::vector<int>&  fds, int n_fds);


public:

  /** Creates a new UnixFDList containing no file descriptors.
   *
   * @newin{2,24}
   *
   * @return A new UnixFDList.
   */


  static auto create() -> Glib::RefPtr<UnixFDList>;


  /** Creates a new UnixFDList containing the file descriptors given in @a
   * fds.  The file descriptors become the property of the new list and may no
   * longer be used by the caller. The array itself is owned by the caller.
   *
   * Each file descriptor in the array should be set to close-on-exec.
   * @param fds The list of file descriptors to use for creation.
   * @return A new UnixFDList.
   */

  static auto create(const std::vector<int>& fds) -> Glib::RefPtr<UnixFDList>;


  /** Creates a new UnixFDList containing the file descriptors given in
   *  @a fds.  The file descriptors become the property of the new list and
   * may no longer be used by the caller.  The array itself is owned by
   * the caller.
   *
   * Each file descriptor in the array should be set to close-on-exec.
   *
   * If @a n_fds is -1 then @a fds must be terminated with -1.
   *
   * @newin{2,24}
   *
   * @param fds The initial list of file descriptors.
   * @param n_fds The length of #fds, or -1.
   * @return A new UnixFDList.
   */


  static auto create(const std::vector<int>& fds, int n_fds) -> Glib::RefPtr<UnixFDList>;


  /** Gets the length of @a list (ie: the number of file descriptors
   * contained within).
   *
   * @newin{2,24}
   *
   * @return The length of @a list.
   */
  auto get_length() const -> int;

  /** Gets a file descriptor out of @a list.
   *
   *  @a index specifies the index of the file descriptor to get.  It is a
   * programmer error for @a index to be out of range; see
   * g_unix_fd_list_get_length().
   *
   * The file descriptor is duplicated using dup() and set as
   * close-on-exec before being returned.  You must call close() on it
   * when you are done.
   *
   * A possible cause of failure is exceeding the per-process or
   * system-wide file descriptor limit.
   *
   * @newin{2,24}
   *
   * @param index The index into the list.
   * @return The file descriptor, or -1 in case of error.
   *
   * @throws Gio::Error
   */
  auto get(int index) const -> int;

  /** Returns the array of file descriptors that is contained in this object.
   *
   * After this call, the descriptors remain the property of the list. The
   * caller must not close them. The array is valid only until list is changed
   * in any way.
   * @return The list of file descriptors.
   *
   * @newin{2,28}
   */
  auto peek_fds() const -> const std::vector<int>;


  /** Returns the array of file descriptors that is contained in this object.
   *
   * After this call, the descriptors are no longer contained in the list.
   * Further calls will return an empty list (unless more descriptors have
   * been added).
   *
   * The caller is responsible for closing all of the file descriptors. The
   * file descriptors in the array are set to close-on-exec.
   * @return The list of file descriptors.
   *
   * @newin{2,28}
   */
  auto steal_fds() -> std::vector<int>;


  /** Adds a file descriptor to @a list.
   *
   * The file descriptor is duplicated using dup(). You keep your copy
   * of the descriptor and the copy contained in @a list will be closed
   * when @a list is finalized.
   *
   * A possible cause of failure is exceeding the per-process or
   * system-wide file descriptor limit.
   *
   * The index of the file descriptor in the list is returned.  If you use
   * this index with g_unix_fd_list_get() then you will receive back a
   * duplicated copy of the same file descriptor.
   *
   * @newin{2,24}
   *
   * @param fd A valid open file descriptor.
   * @return The index of the appended fd in case of success, else -1
   * (and @a error is set).
   */


  /**@throw Glib::Error.
   */
  auto append(int fd) -> int;


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
   * @relates Gio::UnixFDList
   */
  GIOMM_API
  auto wrap(GUnixFDList* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixFDList>;
}


#endif /* _GIOMM_UNIXFDLIST_H */

