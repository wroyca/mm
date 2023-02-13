
#ifndef _GDKMM_TOPLEVELLAYOUT_H
#define _GDKMM_TOPLEVELLAYOUT_H


#include <libmm-glib/ustring.hxx>
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


#include <libmm-glib/refptr.hxx>
#include <libmm-gdk/monitor.hxx>


namespace Gdk
{

/** Information for presenting toplevels.
 *
 * %Toplevel surfaces are sovereign windows that can be presented
 * to the user in various states (maximized, on all workspaces, etc).
 *
 * The %Gdk::ToplevelLayout class contains information that
 * is necessary to do so, and is passed to Gdk::Toplevel::present().
 *
 * @newin{3,98}
 */
class GDKMM_API ToplevelLayout final
{
  // GdkToplevelLayout is actually registered as a boxed type, but it has custom
  // reference-counting instead of copy/free functions, so we use it via RefPtr.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ToplevelLayout;
  using BaseObjectType = GdkToplevelLayout;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GdkToplevelLayout*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GdkToplevelLayout*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GdkToplevelLayout*;

  ToplevelLayout() = delete;

  // noncopyable
  ToplevelLayout(const ToplevelLayout&) = delete;
  auto operator=(const ToplevelLayout&) -> ToplevelLayout& = delete;

protected:
  // Do not derive this.  Gdk::ToplevelLayout can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:


  /** Create a toplevel layout description.
   *
   * Used together with present() to describe
   * how a toplevel surface should be placed and behave on-screen.
   *
   * The size is in ”application pixels”, not
   * ”device pixels” (see Gdk::Surface::get_scale_factor()).
   *
   * @return Newly created instance of `Gdk::ToplevelLayout`.
   */
  static auto create() -> Glib::RefPtr<ToplevelLayout>;

  /** Create a new `Gdk::ToplevelLayout` and copy the contents of @a layout into it.
   *
   * @return A copy of @a layout.
   */
  auto copy() const -> Glib::RefPtr<ToplevelLayout>;

  /** Check whether @a layout and @a other has identical layout properties.
   *
   * @param other Another `Gdk::ToplevelLayout`.
   * @return <tt>true</tt> if @a layout and @a other have identical layout properties,
   * otherwise <tt>false</tt>.
   */
  auto equal(const Glib::RefPtr<const ToplevelLayout>& other) const -> bool;

  /** Sets whether the layout should cause the surface
   * to be maximized when presented.
   *
   * @param maximized <tt>true</tt> to maximize.
   */
  void set_maximized(bool maximized =  true);

  /** Sets whether the layout should cause the surface
   * to be fullscreen when presented.
   *
   * @param fullscreen <tt>true</tt> to fullscreen the surface.
   * @param monitor The monitor to fullscreen on.
   */
  void set_fullscreen(bool fullscreen =  true, const Glib::RefPtr<Monitor>& monitor =  {});

  /** If the layout specifies whether to the toplevel should go maximized,
   * the value pointed to by @a maximized is set to <tt>true</tt> if it should go
   * fullscreen, or <tt>false</tt>, if it should go unmaximized.
   *
   * @param maximized Set to <tt>true</tt> if the toplevel should be maximized.
   * @return Whether the @a layout specifies the maximized state for the toplevel.
   */
  auto get_maximized(bool& maximized) const -> bool;

  /** If the layout specifies whether to the toplevel should go fullscreen,
   * the value pointed to by @a fullscreen is set to <tt>true</tt> if it should go
   * fullscreen, or <tt>false</tt>, if it should go unfullscreen.
   *
   * @param fullscreen Location to store whether the toplevel should be fullscreen.
   * @return Whether the @a layout specifies the fullscreen state for the toplevel.
   */
  auto get_fullscreen(bool& fullscreen) const -> bool;

  /** Returns the monitor that the layout is fullscreening
   * the surface on.
   *
   * @return The monitor on which @a layout fullscreens.
   */
  auto get_fullscreen_monitor() -> Glib::RefPtr<Monitor>;

  /** Returns the monitor that the layout is fullscreening
   * the surface on.
   *
   * @return The monitor on which @a layout fullscreens.
   */
  auto get_fullscreen_monitor() const -> Glib::RefPtr<const Monitor>;

  /** Sets whether the layout should allow the user
   * to resize the surface after it has been presented.
   *
   * @param resizable <tt>true</tt> to allow resizing.
   */
  void set_resizable(bool resizable =  true);

  /** Returns whether the layout should allow the user
   * to resize the surface.
   *
   * @return <tt>true</tt> if the layout is resizable.
   */
  auto get_resizable() const -> bool;


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
 * @relates Gdk::ToplevelLayout
 */
GDKMM_API
auto wrap(GdkToplevelLayout* object, bool take_copy = false) -> Glib::RefPtr<Gdk::ToplevelLayout>;

} // namespace Glib


#endif /* _GDKMM_TOPLEVELLAYOUT_H */

