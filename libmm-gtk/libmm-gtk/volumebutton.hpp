
#ifndef _GTKMM_VOLUMEBUTTON_H
#define _GTKMM_VOLUMEBUTTON_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2007 The gtkmm Development Team
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

#include <libmm-gtk/scalebutton.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkVolumeButton = struct _GtkVolumeButton;
using GtkVolumeButtonClass = struct _GtkVolumeButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API VolumeButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A button which pops up a volume control.
 *
 * %Gtk::VolumeButton is a subclass of Gtk::ScaleButton that has been tailored
 * for use as a volume control widget with suitable icons, tooltips and
 * accessible labels.
 *
 * @ingroup Widgets
 * @newin{2,12}
 */

class GTKMM_API VolumeButton : public ScaleButton
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef VolumeButton CppObjectType;
  typedef VolumeButton_Class CppClassType;
  typedef GtkVolumeButton BaseObjectType;
  typedef GtkVolumeButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  VolumeButton(VolumeButton&& src) noexcept;
  auto operator=(VolumeButton&& src) noexcept -> VolumeButton&;

  // noncopyable
  VolumeButton(const VolumeButton&) = delete;
  auto operator=(const VolumeButton&) -> VolumeButton& = delete;

  ~VolumeButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class VolumeButton_Class;
  static CppClassType volumebutton_class_;

protected:
  explicit VolumeButton(const Glib::ConstructParams& construct_params);
  explicit VolumeButton(GtkVolumeButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkVolumeButton*       { return reinterpret_cast<GtkVolumeButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkVolumeButton* { return reinterpret_cast<GtkVolumeButton*>(gobject_); }

private:

public:

  /** Creates a VolumeButton, with a range between 0 and 100, with
   * a stepping of 2. Volume values can be obtained and modified using
   * the methods from the ScaleButton base class.
   */
  VolumeButton();


  /** Whether to use symbolic icons as the icons.
   *
   * Note that if the symbolic icons are not available in your installed
   * theme, then the normal (potentially colorful) icons will be used.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_symbolic() -> Glib::PropertyProxy< bool > ;

/** Whether to use symbolic icons as the icons.
   *
   * Note that if the symbolic icons are not available in your installed
   * theme, then the normal (potentially colorful) icons will be used.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_symbolic() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::VolumeButton
   */
  GTKMM_API
  auto wrap(GtkVolumeButton* object, bool take_copy = false) -> Gtk::VolumeButton*;
} //namespace Glib


#endif /* _GTKMM_VOLUMEBUTTON_H */

