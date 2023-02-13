
#ifndef _GDKMM_CURSOR_H
#define _GDKMM_CURSOR_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-gdk/texture.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkCursor = struct _GdkCursor;
using GdkCursorClass = struct _GdkCursorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Cursor_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** This represents a cursor.
 */

class GDKMM_API Cursor : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Cursor;
  using CppClassType = Cursor_Class;
  using BaseObjectType = GdkCursor;
  using BaseClassType = GdkCursorClass;

  // noncopyable
  Cursor(const Cursor&) = delete;
  auto operator=(const Cursor&) -> Cursor& = delete;

private:  friend class Cursor_Class;
  static CppClassType cursor_class_;

protected:
  explicit Cursor(const Glib::ConstructParams& construct_params);
  explicit Cursor(GdkCursor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Cursor(Cursor&& src) noexcept;
  auto operator=(Cursor&& src) noexcept -> Cursor&;

  ~Cursor() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkCursor*       { return reinterpret_cast<GdkCursor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkCursor* { return reinterpret_cast<GdkCursor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkCursor*;

private:

   //We use DO_NOT_DERIVE_GTYPE because glib does not allow us to derive from a non-fundamental (abstract) type, for some reason.

protected:

public:
  //We use _WRAP_METHOD() instead of _WRAP_CREATE() and constructors,
  //because the gdk_cursor_new_*() functions actually return existing instances sometimes,
  //but constructors assume that they own the instance.
  //And we would have to have to use the gdk_cursor_new_*() functions in the constructors anyway,
  //because they do more than just call g_object_new().

  /** Creates a new cursor from a `Gdk::Texture`.
   *
   * @param texture The texture providing the pixel data.
   * @param hotspot_x The horizontal offset of the “hotspot” of the cursor.
   * @param hotspot_y The vertical offset of the “hotspot” of the cursor.
   * @param fallback The `Gdk::Cursor` to fall back to when
   * this one cannot be supported.
   * @return A new `Gdk::Cursor`.
   */
  static auto create(const Glib::RefPtr<const Texture>& texture, int hotspot_x, int hotspot_y, const Glib::RefPtr<Cursor>& fallback =  {}) -> Glib::RefPtr<Cursor>;

  /** Creates a new cursor by looking up @a name in the current cursor
   * theme.
   *
   * A recommended set of cursor names that will work across different
   * platforms can be found in the CSS specification:
   *
   * | | | | |
   * | --- | --- | ---- | --- |
   * | "none" | ![](default_cursor.png) "default" | ![](help_cursor.png) "help" | ![](pointer_cursor.png) "pointer" |
   * | ![](context_menu_cursor.png) "context-menu" | ![](progress_cursor.png) "progress" | ![](wait_cursor.png) "wait" | ![](cell_cursor.png) "cell" |
   * | ![](crosshair_cursor.png) "crosshair" | ![](text_cursor.png) "text" | ![](vertical_text_cursor.png) "vertical-text" | ![](alias_cursor.png) "alias" |
   * | ![](copy_cursor.png) "copy" | ![](no_drop_cursor.png) "no-drop" | ![](move_cursor.png) "move" | ![](not_allowed_cursor.png) "not-allowed" |
   * | ![](grab_cursor.png) "grab" | ![](grabbing_cursor.png) "grabbing" | ![](all_scroll_cursor.png) "all-scroll" | ![](col_resize_cursor.png) "col-resize" |
   * | ![](row_resize_cursor.png) "row-resize" | ![](n_resize_cursor.png) "n-resize" | ![](e_resize_cursor.png) "e-resize" | ![](s_resize_cursor.png) "s-resize" |
   * | ![](w_resize_cursor.png) "w-resize" | ![](ne_resize_cursor.png) "ne-resize" | ![](nw_resize_cursor.png) "nw-resize" | ![](sw_resize_cursor.png) "sw-resize" |
   * | ![](se_resize_cursor.png) "se-resize" | ![](ew_resize_cursor.png) "ew-resize" | ![](ns_resize_cursor.png) "ns-resize" | ![](nesw_resize_cursor.png) "nesw-resize" |
   * | ![](nwse_resize_cursor.png) "nwse-resize" | ![](zoom_in_cursor.png) "zoom-in" | ![](zoom_out_cursor.png) "zoom-out" | |
   *
   * @param name The name of the cursor.
   * @param fallback <tt>nullptr</tt> or the `Gdk::Cursor` to fall back to when
   * this one cannot be supported.
   * @return A new `Gdk::Cursor`, or <tt>nullptr</tt> if there is no
   * cursor with the given name.
   */
  static auto create(const Glib::ustring& name, const Glib::RefPtr<Cursor>& fallback =  {}) -> Glib::RefPtr<Cursor>;


  /** Returns the fallback for this @a cursor.
   *
   * The fallback will be used if this cursor is not available on a given
   * `Gdk::Display`. For named cursors, this can happen when using nonstandard
   * names or when using an incomplete cursor theme. For textured cursors,
   * this can happen when the texture is too large or when the `Gdk::Display`
   * it is used on does not support textured cursors.
   *
   * @return The fallback of the cursor or <tt>nullptr</tt>
   * to use the default cursor as fallback.
   */
  auto get_fallback() -> Glib::RefPtr<Cursor>;

  /** Returns the fallback for this @a cursor.
   *
   * The fallback will be used if this cursor is not available on a given
   * `Gdk::Display`. For named cursors, this can happen when using nonstandard
   * names or when using an incomplete cursor theme. For textured cursors,
   * this can happen when the texture is too large or when the `Gdk::Display`
   * it is used on does not support textured cursors.
   *
   * @return The fallback of the cursor or <tt>nullptr</tt>
   * to use the default cursor as fallback.
   */
  auto get_fallback() const -> Glib::RefPtr<const Cursor>;


  /** Returns the name of the cursor.
   *
   * If the cursor is not a named cursor, <tt>nullptr</tt> will be returned.
   *
   * @return The name of the cursor or <tt>nullptr</tt>
   * if it is not a named cursor.
   */
  auto get_name() const -> Glib::ustring;


  /** Returns the texture for the cursor.
   *
   * If the cursor is a named cursor, <tt>nullptr</tt> will be returned.
   *
   * @return The texture for cursor or <tt>nullptr</tt>
   * if it is a named cursor.
   */
  auto get_texture() -> Glib::RefPtr<Texture>;

  /** Returns the texture for the cursor.
   *
   * If the cursor is a named cursor, <tt>nullptr</tt> will be returned.
   *
   * @return The texture for cursor or <tt>nullptr</tt>
   * if it is a named cursor.
   */
  auto get_texture() const -> Glib::RefPtr<const Texture>;


  /** Returns the horizontal offset of the hotspot.
   *
   * The hotspot indicates the pixel that will be directly above the cursor.
   *
   * Note that named cursors may have a nonzero hotspot, but this function
   * will only return the hotspot position for cursors created with
   * new_from_texture().
   *
   * @return The horizontal offset of the hotspot or 0 for named cursors.
   */
  auto get_hotspot_x() const -> int;

  /** Returns the vertical offset of the hotspot.
   *
   * The hotspot indicates the pixel that will be directly above the cursor.
   *
   * Note that named cursors may have a nonzero hotspot, but this function
   * will only return the hotspot position for cursors created with
   * new_from_texture().
   *
   * @return The vertical offset of the hotspot or 0 for named cursors.
   */
  auto get_hotspot_y() const -> int;

  /** Cursor to fall back to if this cursor cannot be displayed.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fallback() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Cursor> >;


  /** X position of the cursor hotspot in the cursor image.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hotspot_x() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Y position of the cursor hotspot in the cursor image.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hotspot_y() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Name of this this cursor.
   *
   * The name will be <tt>nullptr</tt> if the cursor was created from a texture.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The texture displayed by this cursor.
   *
   * The texture will be <tt>nullptr</tt> if the cursor was created from a name.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_texture() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Texture> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Cursor
   */
  GDKMM_API
  auto wrap(GdkCursor* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Cursor>;
}


#endif /* _GDKMM_CURSOR_H */

