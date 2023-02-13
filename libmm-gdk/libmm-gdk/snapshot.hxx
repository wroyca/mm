
#ifndef _GDKMM_SNAPSHOT_H
#define _GDKMM_SNAPSHOT_H

#include <libmm-gdk/mm-gdkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2018 The gtkmm Development Team
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


#include <libmm-glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkSnapshot = struct _GdkSnapshot;
using GdkSnapshotClass = struct _GdkSnapshotClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Snapshot_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** Base type for snapshot operations.
 *
 * @see Gtk::Snapshot
 *
 * @newin{3,94}
 */

class GDKMM_API Snapshot : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Snapshot;
  using CppClassType = Snapshot_Class;
  using BaseObjectType = GdkSnapshot;
  using BaseClassType = GdkSnapshotClass;

  // noncopyable
  Snapshot(const Snapshot&) = delete;
  auto operator=(const Snapshot&) -> Snapshot& = delete;

private:  friend class Snapshot_Class;
  static CppClassType snapshot_class_;

protected:
  explicit Snapshot(const Glib::ConstructParams& construct_params);
  explicit Snapshot(GdkSnapshot* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Snapshot(Snapshot&& src) noexcept;
  auto operator=(Snapshot&& src) noexcept -> Snapshot&;

  ~Snapshot() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkSnapshot*       { return reinterpret_cast<GdkSnapshot*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkSnapshot* { return reinterpret_cast<GdkSnapshot*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkSnapshot*;

private:


public:
  // This class is almost empty


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Snapshot
   */
  GDKMM_API
  auto wrap(GdkSnapshot* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Snapshot>;
}


#endif /* _GDKMM_SNAPSHOT_H */

