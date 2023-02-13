
#ifndef _GDKMM_CAIROCONTEXT_H
#define _GDKMM_CAIROCONTEXT_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gdk/drawcontext.hpp>
#include <mm/cairo/context.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkCairoContext = struct _GdkCairoContext;
using GdkCairoContextClass = struct _GdkCairoContextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API CairoContext_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** Cairo draw context.
 *
 * %Gdk::CairoContext is an object representing the platform-specific draw context.
 *
 * %Gdk::CairoContexts are created for a Gdk::Display using
 * Gdk::Surface::create_cairo_context(), and the context can then be used
 * to draw on that Gdk::Surface.
 *
 * @newin{3,94}
 */

class GDKMM_API CairoContext : public Gdk::DrawContext
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CairoContext;
  using CppClassType = CairoContext_Class;
  using BaseObjectType = GdkCairoContext;
  using BaseClassType = GdkCairoContextClass;

  // noncopyable
  CairoContext(const CairoContext&) = delete;
  auto operator=(const CairoContext&) -> CairoContext& = delete;

private:  friend class CairoContext_Class;
  static CppClassType cairocontext_class_;

protected:
  explicit CairoContext(const Glib::ConstructParams& construct_params);
  explicit CairoContext(GdkCairoContext* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CairoContext(CairoContext&& src) noexcept;
  auto operator=(CairoContext&& src) noexcept -> CairoContext&;

  ~CairoContext() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkCairoContext*       { return reinterpret_cast<GdkCairoContext*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkCairoContext* { return reinterpret_cast<GdkCairoContext*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkCairoContext*;

private:


protected:
  CairoContext();

public:

  /** Retrieves a Cairo context to be used to draw on the `Gdk::Surface`
   * of @a context.
   *
   * A call to Gdk::DrawContext::begin_frame() with this
   *  @a context must have been done or this function will return <tt>nullptr</tt>.
   *
   * The returned context is guaranteed to be valid until
   * Gdk::DrawContext::end_frame() is called.
   *
   * @return A Cairo context
   * to draw on `GdkSurface.
   */
  auto cairo_create() -> ::Cairo::RefPtr< ::Cairo::Context>;

  // There are no public signals, properties or vfuncs.


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
   * @relates Gdk::CairoContext
   */
  GDKMM_API
  auto wrap(GdkCairoContext* object, bool take_copy = false) -> Glib::RefPtr<Gdk::CairoContext>;
}


#endif /* _GDKMM_CAIROCONTEXT_H */

