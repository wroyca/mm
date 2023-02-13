
#ifndef _GIOMM_MEMORYINPUTSTREAM_H
#define _GIOMM_MEMORYINPUTSTREAM_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
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


#include <libmm-gio/inputstream.hxx>
#include <libmm-gio/seekable.hxx>
#include <libmm-gio/pollableinputstream.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMemoryInputStream = struct _GMemoryInputStream;
using GMemoryInputStreamClass = struct _GMemoryInputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API MemoryInputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** MemoryInputStream implements InputStream for arbitrary memory chunks.
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API MemoryInputStream
: public Gio::InputStream,
  public Seekable,
  public PollableInputStream
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MemoryInputStream;
  using CppClassType = MemoryInputStream_Class;
  using BaseObjectType = GMemoryInputStream;
  using BaseClassType = GMemoryInputStreamClass;

  // noncopyable
  MemoryInputStream(const MemoryInputStream&) = delete;
  auto operator=(const MemoryInputStream&) -> MemoryInputStream& = delete;

private:  friend class MemoryInputStream_Class;
  static CppClassType memoryinputstream_class_;

protected:
  explicit MemoryInputStream(const Glib::ConstructParams& construct_params);
  explicit MemoryInputStream(GMemoryInputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MemoryInputStream(MemoryInputStream&& src) noexcept;
  auto operator=(MemoryInputStream&& src) noexcept -> MemoryInputStream&;

  ~MemoryInputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GMemoryInputStream*       { return reinterpret_cast<GMemoryInputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GMemoryInputStream* { return reinterpret_cast<GMemoryInputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GMemoryInputStream*;

private:


protected:
  MemoryInputStream();
  // TODO: *_new_from_data constructor needs to be fixed?

public:

  static auto create() -> Glib::RefPtr<MemoryInputStream>;


  /** Appends @a data to data that can be read from the input stream
   *
   * @param data Input data.
   * @param len Length of the data, may be -1 if @a data is a nul-terminated string.
   * @param destroy Function that is called to free @a data, or <tt>nullptr</tt>.
   */
  void add_data(const void* data, gssize len, GDestroyNotify destroy);

  /** For example,
   * void on_destroy_data(void* data);
   *
   * @param data The data to free.
   *
   * @newin{2,40}
   */
  using SlotDestroyData = sigc::slot<void(void*)>;

  /** Appends to data that can be read from the input stream.
   *
   * @param data Input data.
   * @param len Length of the data, may be -1 if data is a null-terminated string.
   * @param destroy_slot A slot to be called to free the data when it is no longer needed.
   *
   * @newin{2,40}
   */
  void add_data(const void* data, gssize len, const SlotDestroyData& destroy_slot);


  /** Appends @a bytes to data that can be read from the input stream.
   *
   * @newin{2,44}
   *
   * @param bytes Input data.
   */
  void add_bytes(const Glib::RefPtr<const Glib::Bytes>& bytes);


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
   * @relates Gio::MemoryInputStream
   */
  GIOMM_API
  auto wrap(GMemoryInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::MemoryInputStream>;
}


#endif /* _GIOMM_MEMORYINPUTSTREAM_H */

