
#ifndef _GDKMM_PAINTABLE_H
#define _GDKMM_PAINTABLE_H

#include <libmm-gdk/mm-gdkconfig.hxx>


#include <libmm-glib/ustring.hxx>
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


#include <libmm-glib/interface.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GdkPaintableInterface GdkPaintableInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPaintable = struct _GdkPaintable;
using GdkPaintableClass = struct _GdkPaintableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Paintable_Class; } // namespace Gdk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GDKMM_API Snapshot;

/** An interface for a paintable region.
 *
 * %Gdk::Paintable is a simple interface used by GDK and GTK to represent
 * objects that can be painted anywhere at any size without requiring any
 * sort of layout. The interface is inspired by similar concepts elsewhere,
 * such as ClutterContent,
 * <a href="https://www.w3.org/TR/css-images-4/#paint-source">HTML/CSS Paint Sources</a>
 * or <a href="https://www.w3.org/TR/SVG2/pservers.html">SVG Paint Servers</a>.
 *
 * A %Paintable can be snapshot at any time and size using
 * snapshot(). How the paintable interprets that size and if it
 * scales or centers itself into the given rectangle is implementation defined,
 * though if you are implementing a %Paintable and don't know what to do, it
 * is suggested that you scale your paintable ignoring any potential aspect ratio.
 *
 * The contents that a %Paintable produces may depend on the %Snapshot passed
 * to it. For example, paintables may decide to use more detailed images on higher
 * resolution screens or when OpenGL is available. A %Paintable will however
 * always produce the same output for the same snapshot.
 *
 * A %Paintable may change its contents, meaning that it will now produce a
 * different output with the same snpashot. Once that happens, it will call
 * invalidate_contents() which will emit the signal_invalidate_contents() signal.
 * If a paintable is known to never change its contents, it will set the
 * Flags::STATIC_CONTENTS flag. If a consumer cannot deal with changing
 * contents, it may call get_current_image() which will return a
 * static paintable and use that.
 *
 * A paintable can report an intrinsic (or preferred) size or aspect ratio it
 * wishes to be rendered at, though it doesn't have to. Consumers of the interface
 * can use this information to layout the paintable appropriately.
 * Just like the contents, the size of a paintable can change. A paintable will
 * indicate this by calling invalidate_size() which will emit the
 * signal_invalidate_size() signal.
 * And just like for contents, if a paintable is known to never change its size,
 * it will set the Flags::STATIC_SIZE flag.
 *
 * @see Gtk::Image, Gdk::Texture, Gtk::Snapshot
 *
 * @newin{3,94}
 */

class GDKMM_API Paintable : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Paintable;
  using CppClassType = Paintable_Class;
  using BaseObjectType = GdkPaintable;
  using BaseClassType = GdkPaintableInterface;

  // noncopyable
  Paintable(const Paintable&) = delete;
  auto operator=(const Paintable&) -> Paintable& = delete;

private:
  friend class Paintable_Class;
  static CppClassType paintable_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Paintable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Paintable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Paintable(GdkPaintable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Paintable(Paintable&& src) noexcept;
  auto operator=(Paintable&& src) noexcept -> Paintable&;

  ~Paintable() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkPaintable*       { return reinterpret_cast<GdkPaintable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkPaintable* { return reinterpret_cast<GdkPaintable*>(gobject_); }

private:


public:
  /** @addtogroup gdkmmEnums gdkmm Enums and Flags */

  /**
   *  @var Flags STATIC_SIZE
   * The size is immutable.
   * The Gdk::GdkPaintable::signal_invalidate_size() signal will never be
   * emitted.
   *
   *  @var Flags STATIC_CONTENTS
   * The content is immutable.
   * The Gdk::GdkPaintable::signal_invalidate_contents() signal will never be
   * emitted.
   *
   *  @enum Flags
   *
   * Flags about a paintable object.
   *
   * Implementations use these for optimizations such as caching.
   *
   * @ingroup gdkmmEnums
   * @par Bitwise operators:
   * <tt>Paintable::Flags operator|(Paintable::Flags, Paintable::Flags)</tt><br>
   * <tt>Paintable::Flags operator&(Paintable::Flags, Paintable::Flags)</tt><br>
   * <tt>Paintable::Flags operator^(Paintable::Flags, Paintable::Flags)</tt><br>
   * <tt>Paintable::Flags operator~(Paintable::Flags)</tt><br>
   * <tt>Paintable::Flags& operator|=(Paintable::Flags&, Paintable::Flags)</tt><br>
   * <tt>Paintable::Flags& operator&=(Paintable::Flags&, Paintable::Flags)</tt><br>
   * <tt>Paintable::Flags& operator^=(Paintable::Flags&, Paintable::Flags)</tt><br>
   */
  enum class Flags
  {
    STATIC_SIZE = 1 << 0,
    STATIC_CONTENTS = 1 << 1
  };


  /** Snapshots the given paintable with the given @a width and @a height.
   *
   * The paintable is drawn at the current (0,0) offset of the @a snapshot.
   * If @a width and @a height are not larger than zero, this function will
   * do nothing.
   *
   * @param snapshot A `Gdk::Snapshot` to snapshot to.
   * @param width Width to snapshot in.
   * @param height Height to snapshot in.
   */
  void snapshot(const Glib::RefPtr<Gdk::Snapshot>& snapshot, double width, double height);

  /** Gets an immutable paintable for the current contents displayed by @a paintable.
   *
   * This is useful when you want to retain the current state of an animation,
   * for example to take a screenshot of a running animation.
   *
   * If the @a paintable is already immutable, it will return itself.
   *
   * @return An immutable paintable for the current
   * contents of @a paintable.
   */
  auto get_current_image() const -> Glib::RefPtr<const Paintable>;

  /** Get flags for the paintable.
   *
   * This is oftentimes useful for optimizations.
   *
   * See Gdk::PaintableFlags for the flags and what they mean.
   *
   * @return The `Gdk::PaintableFlags` for this paintable.
   */
  auto get_flags() const -> Flags;

  /** Gets the preferred width the @a paintable would like to be displayed at.
   *
   * Consumers of this interface can use this to reserve enough space to draw
   * the paintable.
   *
   * This is a purely informational value and does not in any way limit the
   * values that may be passed to snapshot().
   *
   * If the @a paintable does not have a preferred width, it returns 0.
   * Negative values are never returned.
   *
   * @return The intrinsic width of @a paintable or 0 if none.
   */
  auto get_intrinsic_width() const -> int;

  /** Gets the preferred height the @a paintable would like to be displayed at.
   *
   * Consumers of this interface can use this to reserve enough space to draw
   * the paintable.
   *
   * This is a purely informational value and does not in any way limit the
   * values that may be passed to snapshot().
   *
   * If the @a paintable does not have a preferred height, it returns 0.
   * Negative values are never returned.
   *
   * @return The intrinsic height of @a paintable or 0 if none.
   */
  auto get_intrinsic_height() const -> int;

  /** Gets the preferred aspect ratio the @a paintable would like to be displayed at.
   *
   * The aspect ratio is the width divided by the height, so a value of 0.5
   * means that the @a paintable prefers to be displayed twice as high as it
   * is wide. Consumers of this interface can use this to preserve aspect
   * ratio when displaying the paintable.
   *
   * This is a purely informational value and does not in any way limit the
   * values that may be passed to snapshot().
   *
   * Usually when a @a paintable returns nonzero values from
   * get_intrinsic_width() and
   * get_intrinsic_height() the aspect ratio
   * should conform to those values, though that is not required.
   *
   * If the @a paintable does not have a preferred aspect ratio,
   * it returns 0. Negative values are never returned.
   *
   * @return The intrinsic aspect ratio of @a paintable or 0 if none.
   */
  auto get_intrinsic_aspect_ratio() const -> double;

  /** Compute a concrete size for the `Gdk::Paintable`.
   *
   * Applies the sizing algorithm outlined in the
   * [CSS Image spec](https://drafts.csswg.org/css-images-3/#default-sizing)
   * to the given @a paintable. See that link for more details.
   *
   * It is not necessary to call this function when both @a specified_width
   * and @a specified_height are known, but it is useful to call this
   * function in GtkWidget:measure implementations to compute the
   * other dimension when only one dimension is given.
   *
   * @param specified_width The width @a paintable could be drawn into or
   * 0.0 if unknown.
   * @param specified_height The height @a paintable could be drawn into or
   * 0.0 if unknown.
   * @param default_width The width @a paintable would be drawn into if
   * no other constraints were given.
   * @param default_height The height @a paintable would be drawn into if
   * no other constraints were given.
   * @param concrete_width Will be set to the concrete width computed.
   * @param concrete_height Will be set to the concrete height computed.
   */
  void compute_concrete_size(double specified_width, double specified_height, double default_width, double default_height, double& concrete_width, double& concrete_height) const;

  /** Called by implementations of `Gdk::Paintable` to invalidate their contents.
   *
   * Unless the contents are invalidated, implementations must guarantee that
   * multiple calls of snapshot() produce the same output.
   *
   * This function will emit the signal_invalidate_contents()
   * signal.
   *
   * If a @a paintable reports the Gdk::Paintable::Flags::STATIC_CONTENTS flag,
   * it must not call this function.
   */
  void invalidate_contents();

  /** Called by implementations of `Gdk::Paintable` to invalidate their size.
   *
   * As long as the size is not invalidated, @a paintable must return the same
   * values for its intrinsic width, height and aspect ratio.
   *
   * This function will emit the signal_invalidate_size()
   * signal.
   *
   * If a @a paintable reports the Gdk::Paintable::Flags::STATIC_SIZE flag,
   * it must not call this function.
   */
  void invalidate_size();

  // no_default_handler because the wrapped C signals have no default handlers.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%invalidate_contents()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the contents of the @a paintable change.
   *
   * Examples for such an event would be videos changing to the next frame or
   * the icon theme for an icon changing.
   */

  auto signal_invalidate_contents() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%invalidate_size()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the intrinsic size of the @a paintable changes.
   *
   * This means the values reported by at least one of
   * Gdk::Paintable::get_intrinsic_width(),
   * Gdk::Paintable::get_intrinsic_height() or
   * Gdk::Paintable::get_intrinsic_aspect_ratio()
   * has changed.
   *
   * Examples for such an event would be a paintable displaying
   * the contents of a toplevel surface being resized.
   */

  auto signal_invalidate_size() -> Glib::SignalProxy<void()>;


protected:


    virtual void snapshot_vfunc(const Glib::RefPtr<Gdk::Snapshot>& snapshot, double width, double height);


    virtual auto get_current_image_vfunc() const -> Glib::RefPtr<Paintable>;

    virtual auto get_flags_vfunc() const -> Flags;

    virtual auto get_intrinsic_width_vfunc() const -> int;

    virtual auto get_intrinsic_height_vfunc() const -> int;

    virtual auto get_intrinsic_aspect_ratio_vfunc() const -> double;


  // There are no properties.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk

namespace Gdk
{

/** @ingroup gdkmmEnums */
inline auto operator|(Paintable::Flags lhs, Paintable::Flags rhs) -> Paintable::Flags
  { return static_cast<Paintable::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(Paintable::Flags lhs, Paintable::Flags rhs) -> Paintable::Flags
  { return static_cast<Paintable::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(Paintable::Flags lhs, Paintable::Flags rhs) -> Paintable::Flags
  { return static_cast<Paintable::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(Paintable::Flags flags) -> Paintable::Flags
  { return static_cast<Paintable::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(Paintable::Flags& lhs, Paintable::Flags rhs) -> Paintable::Flags&
  { return (lhs = static_cast<Paintable::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(Paintable::Flags& lhs, Paintable::Flags rhs) -> Paintable::Flags&
  { return (lhs = static_cast<Paintable::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(Paintable::Flags& lhs, Paintable::Flags rhs) -> Paintable::Flags&
  { return (lhs = static_cast<Paintable::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::Paintable::Flags> : public Glib::Value_Flags<Gdk::Paintable::Flags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Paintable
   */
  GDKMM_API
  auto wrap(GdkPaintable* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Paintable>;

} // namespace Glib


#endif /* _GDKMM_PAINTABLE_H */

