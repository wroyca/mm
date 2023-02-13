
#ifndef _GDKMM_DRAGSURFACE_H
#define _GDKMM_DRAGSURFACE_H

#include <libmm-gdk/mm-gdkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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


#include <libmm-glib/interface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GdkDragSurfaceInterface GdkDragSurfaceInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDragSurface = struct _GdkDragSurface;
using GdkDragSurfaceClass = struct _GdkDragSurfaceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API DragSurface_Class; } // namespace Gdk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** Interface for drag surface surfaces.
 *
 * A %Gdk::DragSurface is a surface that is used during a DnD operation.
 *
 * @newin{3,98}
 */

class GDKMM_API DragSurface : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DragSurface;
  using CppClassType = DragSurface_Class;
  using BaseObjectType = GdkDragSurface;
  using BaseClassType = GdkDragSurfaceInterface;

  // noncopyable
  DragSurface(const DragSurface&) = delete;
  auto operator=(const DragSurface&) -> DragSurface& = delete;

private:
  friend class DragSurface_Class;
  static CppClassType dragsurface_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  DragSurface();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit DragSurface(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit DragSurface(GdkDragSurface* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DragSurface(DragSurface&& src) noexcept;
  auto operator=(DragSurface&& src) noexcept -> DragSurface&;

  ~DragSurface() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkDragSurface*       { return reinterpret_cast<GdkDragSurface*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkDragSurface* { return reinterpret_cast<GdkDragSurface*>(gobject_); }

private:


public:

  /** Present @a drag_surface.
   *
   * @param width The unconstrained drag_surface width to layout.
   * @param height The unconstrained drag_surface height to layout.
   * @return <tt>false</tt> if it failed to be presented, otherwise <tt>true</tt>.
   */
  auto present(int width, int height) -> bool;

  // There are no properties, signals or public vfuncs.


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
   * @relates Gdk::DragSurface
   */
  GDKMM_API
  auto wrap(GdkDragSurface* object, bool take_copy = false) -> Glib::RefPtr<Gdk::DragSurface>;

} // namespace Glib


#endif /* _GDKMM_DRAGSURFACE_H */

