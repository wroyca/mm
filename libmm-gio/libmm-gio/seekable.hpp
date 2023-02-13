
#ifndef _GIOMM_SEEKABLE_H
#define _GIOMM_SEEKABLE_H


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

#include <libmm-gio/cancellable.hpp>
#include <libmm-glib/interface.hpp>
#include <libmm-glib/iochannel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSeekableIface GSeekableIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSeekable = struct _GSeekable;
using GSeekableClass = struct _GSeekableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Seekable_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Stream seeking interface.
 * Seekable is implemented by streams (implementations of InputStream or OutputStream) that support seeking.
 * To find the position of a stream, use tell(). To find
 * out if a stream supports seeking, use can_seek(). To position a
 * stream, use seek(). To find out if a stream supports
 * truncating, use can_truncate(). To truncate a stream, use
 * truncate().
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API Seekable : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Seekable;
  using CppClassType = Seekable_Class;
  using BaseObjectType = GSeekable;
  using BaseClassType = GSeekableIface;

  // noncopyable
  Seekable(const Seekable&) = delete;
  auto operator=(const Seekable&) -> Seekable& = delete;

private:
  friend class Seekable_Class;
  static CppClassType seekable_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Seekable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Seekable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Seekable(GSeekable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Seekable(Seekable&& src) noexcept;
  auto operator=(Seekable&& src) noexcept -> Seekable&;

  ~Seekable() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSeekable*       { return reinterpret_cast<GSeekable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSeekable* { return reinterpret_cast<GSeekable*>(gobject_); }

private:


public:

  /** Tells the current position within the stream.
   *
   * @return The (positive or zero) offset from the beginning of the
   * buffer, zero if the target is not seekable.
   */
  auto tell() const -> goffset;

  /** Tests if the stream supports the SeekableIface.
   *
   * @return <tt>true</tt> if @a seekable can be seeked. <tt>false</tt> otherwise.
   */
  auto can_seek() const -> bool;


  /** Seeks in the stream by the given @a offset, modified by @a type.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param offset A #goffset.
   * @param type A SeekType.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if successful. If an error
   * has occurred, this function will return <tt>false</tt> and set @a error
   * appropriately if present.
   *
   * @throws Glib::Error
   */
  auto seek(goffset offset, Glib::SeekType type, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A seek() convenience overload.
  auto seek(goffset offset, Glib::SeekType type) -> bool;

  //TODO: Document the exception in the C API: https://bugzilla.gnome.org/show_bug.cgi?id=509990#c1


  /** Tests if the length of the stream can be adjusted with
   * g_seekable_truncate().
   *
   * @return <tt>true</tt> if the stream can be truncated, <tt>false</tt> otherwise.
   */
  auto can_truncate() const -> bool;


  /** Truncates a stream with a given #offset.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED. If an
   * operation was partially finished when the operation was cancelled the
   * partial result will be returned, without an error.
   *
   * @param offset A #goffset.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if successful. If an error
   * has occurred, this function will return <tt>false</tt> and set @a error
   * appropriately if present.
   *
   * @throws Glib::Error
   */
  auto truncate(goffset offset, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A truncate() convenience overload.
  auto truncate(goffset offset) -> bool;

  //TODO: Document the exception in the C API: https://bugzilla.gnome.org/show_bug.cgi?id=509990#c1

protected:
  //_WRAP_VFUNC(goffset tell() const, tell)
  //_WRAP_VFUNC(goffset can_seek() const, can_seek)
  //_WRAP_VFUNC(goffset seek(goffset offset, Glib::SeekType type, const Glib::RefPtr<Cancellable>& cancellable, GError** error), seek)
  //_WRAP_VFUNC(goffset can_truncate() const, can_truncate)

  //Renamed to truncate() - we don't know why it's called truncate_fn in C.
  //_WRAP_VFUNC(goffset truncate(goffset offset, const Glib::RefPtr<Cancellable>& cancellable, GError** error), truncate_fn)

  //There are no properties or signals.


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
   * @relates Gio::Seekable
   */
  GIOMM_API
  auto wrap(GSeekable* object, bool take_copy = false) -> Glib::RefPtr<Gio::Seekable>;

} // namespace Glib


#endif /* _GIOMM_SEEKABLE_H */

