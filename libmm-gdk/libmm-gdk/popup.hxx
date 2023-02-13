
#ifndef _GDKMM_POPUP_H
#define _GDKMM_POPUP_H


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

#include <libmm-glib/interface.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/popuplayout.hxx>
#include <libmm-gdk/surface.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GdkPopupInterface GdkPopupInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPopup = struct _GdkPopup;
using GdkPopupClass = struct _GdkPopupClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Popup_Class; } // namespace Gdk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** Interface for popup surfaces.
 *
 * A %Gdk::Popup is a surface that is attached to another surface,
 * called its property_parent(), and is positioned relative to it.
 *
 * %Gdk::Popups are typically used to implement menus and similar popups.
 * They can be modal, which is indicated by the property_autohide() property.
 *
 * @see Gdk::Toplevel, Gdk::Surface
 * @newin{3,98}
 */

class GDKMM_API Popup : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Popup;
  using CppClassType = Popup_Class;
  using BaseObjectType = GdkPopup;
  using BaseClassType = GdkPopupInterface;

  // noncopyable
  Popup(const Popup&) = delete;
  auto operator=(const Popup&) -> Popup& = delete;

private:
  friend class Popup_Class;
  static CppClassType popup_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Popup();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Popup(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Popup(GdkPopup* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Popup(Popup&& src) noexcept;
  auto operator=(Popup&& src) noexcept -> Popup&;

  ~Popup() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkPopup*       { return reinterpret_cast<GdkPopup*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkPopup* { return reinterpret_cast<GdkPopup*>(gobject_); }

private:


public:

  /** Present @a popup after having processed the `Gdk::PopupLayout` rules.
   *
   * If the popup was previously now showing, it will be showed,
   * otherwise it will change position according to @a layout.
   *
   * After calling this function, the result should be handled in response
   * to the Gdk::GdkSurface::signal_layout() signal being emitted. The resulting
   * popup position can be queried using get_position_x(),
   * get_position_y(), and the resulting size will be sent as
   * parameters in the layout signal. Use get_rect_anchor()
   * and get_surface_anchor() to get the resulting anchors.
   *
   * Presenting may fail, for example if the @a popup is set to autohide
   * and is immediately hidden upon being presented. If presenting failed,
   * the Gdk::Surface::signal_layout() signal will not me emitted.
   *
   * @param width The unconstrained popup width to layout.
   * @param height The unconstrained popup height to layout.
   * @param layout The `Gdk::PopupLayout` object used to layout.
   * @return <tt>false</tt> if it failed to be presented, otherwise <tt>true</tt>.
   */
  auto present(int width, int height, const Glib::RefPtr<PopupLayout>& layout) -> bool;

  /** Gets the current popup surface anchor.
   *
   * The value returned may change after calling present(),
   * or after the Gdk::Surface::signal_layout() signal is emitted.
   *
   * @return The current surface anchor value of @a popup.
   */
  auto get_surface_anchor() const -> Gravity;

  /** Gets the current popup rectangle anchor.
   *
   * The value returned may change after calling present(),
   * or after the Gdk::Surface::signal_layout() signal is emitted.
   *
   * @return The current rectangle anchor value of @a popup.
   */
  auto get_rect_anchor() const -> Gravity;

  /** Returns the parent surface of a popup.
   *
   * @return The parent surface.
   */
  auto get_parent() -> Glib::RefPtr<Surface>;

  /** Returns the parent surface of a popup.
   *
   * @return The parent surface.
   */
  auto get_parent() const -> Glib::RefPtr<const Surface>;

  /** Obtains the position of the popup relative to its parent.
   *
   * @return The X coordinate of @a popup position.
   */
  auto get_position_x() const -> int;

  /** Obtains the position of the popup relative to its parent.
   *
   * @return The Y coordinate of @a popup position.
   */
  auto get_position_y() const -> int;

  /** Returns whether this popup is set to hide on outside clicks.
   *
   * @return <tt>true</tt> if @a popup will autohide.
   */
  auto get_autohide() const -> bool;

  /** The parent surface.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_parent() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Surface> >;


  /** Whether to hide on outside clicks.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_autohide() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gdk::Popup
   */
  GDKMM_API
  auto wrap(GdkPopup* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Popup>;

} // namespace Glib


#endif /* _GDKMM_POPUP_H */
