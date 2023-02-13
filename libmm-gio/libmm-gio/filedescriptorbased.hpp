
#ifndef _GIOMM_FILEDESCRIPTORBASED_H
#define _GIOMM_FILEDESCRIPTORBASED_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The giomm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */


#include <mm/glib/interface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GFileDescriptorBasedIface GFileDescriptorBasedIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileDescriptorBased = struct _GFileDescriptorBased;
using GFileDescriptorBasedClass = struct _GFileDescriptorBasedClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API FileDescriptorBased_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Interface for file descriptor based IO.
 *
 * %FileDescriptorBased is implemented by streams (implementations of
 * Gio::InputStream or Gio::OutputStream) that are based on file descriptors.
 *
 * @ingroup Streams
 *
 * @newin{2,58}
 */

class FileDescriptorBased : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileDescriptorBased;
  using CppClassType = FileDescriptorBased_Class;
  using BaseObjectType = GFileDescriptorBased;
  using BaseClassType = GFileDescriptorBasedIface;

  // noncopyable
  FileDescriptorBased(const FileDescriptorBased&) = delete;
  auto operator=(const FileDescriptorBased&) -> FileDescriptorBased& = delete;

private:
  friend class FileDescriptorBased_Class;
  static CppClassType filedescriptorbased_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  FileDescriptorBased();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit FileDescriptorBased(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit FileDescriptorBased(GFileDescriptorBased* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileDescriptorBased(FileDescriptorBased&& src) noexcept;
  auto operator=(FileDescriptorBased&& src) noexcept -> FileDescriptorBased&;

  ~FileDescriptorBased() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFileDescriptorBased*       { return reinterpret_cast<GFileDescriptorBased*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFileDescriptorBased* { return reinterpret_cast<GFileDescriptorBased*>(gobject_); }

private:

  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


public:

  /** Gets the underlying file descriptor.
   *
   * @newin{2,58}
   *
   * @return The file descriptor.
   */
  auto get_fd() const -> int;

protected:
    virtual auto get_fd_vfunc() const -> int;


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
   * @relates Gio::FileDescriptorBased
   */
  GIOMM_API
  auto wrap(GFileDescriptorBased* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileDescriptorBased>;

} // namespace Glib


#endif /* _GIOMM_FILEDESCRIPTORBASED_H */

