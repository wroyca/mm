
#ifndef _GDKMM_DISPLAYMANAGER_H
#define _GDKMM_DISPLAYMANAGER_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2002 The gtkmm Development Team
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

#include <vector>

#include <libmm-glib/object.hxx>
#include <libmm-gdk/display.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDisplayManager = struct _GdkDisplayManager;
using GdkDisplayManagerClass = struct _GdkDisplayManagerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API DisplayManager_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** The purpose of the GdkDisplayManager singleton object is to offer notification when displays appear or disappear or the
 * default display changes.
 */

class GDKMM_API DisplayManager : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DisplayManager;
  using CppClassType = DisplayManager_Class;
  using BaseObjectType = GdkDisplayManager;
  using BaseClassType = GdkDisplayManagerClass;

  // noncopyable
  DisplayManager(const DisplayManager&) = delete;
  auto operator=(const DisplayManager&) -> DisplayManager& = delete;

private:  friend class DisplayManager_Class;
  static CppClassType displaymanager_class_;

protected:
  explicit DisplayManager(const Glib::ConstructParams& construct_params);
  explicit DisplayManager(GdkDisplayManager* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DisplayManager(DisplayManager&& src) noexcept;
  auto operator=(DisplayManager&& src) noexcept -> DisplayManager&;

  ~DisplayManager() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkDisplayManager*       { return reinterpret_cast<GdkDisplayManager*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkDisplayManager* { return reinterpret_cast<GdkDisplayManager*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkDisplayManager*;

private:

protected:

public:


  /** Gets the singleton `Gdk::DisplayManager` object.
   *
   * When called for the first time, this function consults the
   * `GDK_BACKEND` environment variable to find out which of the
   * supported GDK backends to use (in case GDK has been compiled
   * with multiple backends).
   *
   * Applications can use set_allowed_backends() to limit what
   * backends wil be used.
   *
   * @return The global `Gdk::DisplayManager` singleton.
   */
  static auto get() -> Glib::RefPtr<DisplayManager>;

  /** Gets the default `Gdk::Display`.
   *
   * @return A `Gdk::Display`.
   */
  auto get_default_display() -> Glib::RefPtr<Display>;

  /** Gets the default `Gdk::Display`.
   *
   * @return A `Gdk::Display`.
   */
  auto get_default_display() const -> Glib::RefPtr<const Display>;


  /** Sets @a display as the default display.
   *
   * @param display A `Gdk::Display`.
   */
  void set_default_display(const Glib::RefPtr<Display>& display);


  /** List all currently open displays.
   *
   * @return A vector of Gdk::Display objects.
   */
  auto list_displays() -> std::vector< Glib::RefPtr<Display> >;


  /** Opens a display.
   *
   * @param name The name of the display to open.
   * @return A `Gdk::Display`, or <tt>nullptr</tt>
   * if the display could not be opened.
   */
  auto open_display(const Glib::ustring& name) -> Glib::RefPtr<Display>;

  /** The default display.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_display() -> Glib::PropertyProxy< Glib::RefPtr<Display> > ;

/** The default display.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >;


  //We use no_default_handler because GdkDisplayManagerClass is private.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%display_opened(const Glib::RefPtr<Display>& display)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a display is opened.
   *
   * @param display The opened display.
   */

  auto signal_display_opened() -> Glib::SignalProxy<void(const Glib::RefPtr<Display>&)>;


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
   * @relates Gdk::DisplayManager
   */
  GDKMM_API
  auto wrap(GdkDisplayManager* object, bool take_copy = false) -> Glib::RefPtr<Gdk::DisplayManager>;
}


#endif /* _GDKMM_DISPLAYMANAGER_H */

