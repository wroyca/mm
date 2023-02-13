
#ifndef _GDKMM_DEVICE_H
#define _GDKMM_DEVICE_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2002-2004 The gtkmm Development Team
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

#include <libmm-pango/context.hpp>
#include <libmm-gdk/cursor.hpp>
#include <libmm-gdk/enums.hpp>
#include <libmm-gdk/timecoord.hpp>
#include <gdk/gdk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDevice = struct _GdkDevice;
using GdkDeviceClass = struct _GdkDeviceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Device_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 *  @var InputSource MOUSE
 * The device is a mouse. (This will be reported for the core
 * pointer, even if it is something else, such as a trackball.).
 *
 *  @var InputSource PEN
 * The device is a stylus of a graphics tablet or similar device.
 *
 *  @var InputSource KEYBOARD
 * The device is a keyboard.
 *
 *  @var InputSource TOUCHSCREEN
 * The device is a direct-input touch device, such
 * as a touchscreen or tablet.
 *
 *  @var InputSource TOUCHPAD
 * The device is an indirect touch device, such
 * as a touchpad.
 *
 *  @var InputSource TRACKPOINT
 * The device is a trackpoint.
 *
 *  @var InputSource TABLET_PAD
 * The device is a "pad", a collection of buttons,
 * rings and strips found in drawing tablets.
 *
 *  @enum InputSource
 *
 * An enumeration describing the type of an input device in general terms.
 *
 * @ingroup gdkmmEnums
 */
enum class InputSource
{
  MOUSE,
  PEN,
  KEYBOARD,
  TOUCHSCREEN,
  TOUCHPAD,
  TRACKPOINT,
  TABLET_PAD
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::InputSource> : public Glib::Value_Enum<Gdk::InputSource>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


class GDKMM_API DeviceTool;
class GDKMM_API DeviceWithPad;
class GDKMM_API Display;
class GDKMM_API Seat;
class GDKMM_API Surface;

/** A Gdk::Device instance contains a detailed description of an extended input device.
 */

class GDKMM_API Device : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Device;
  using CppClassType = Device_Class;
  using BaseObjectType = GdkDevice;
  using BaseClassType = GdkDeviceClass;

  // noncopyable
  Device(const Device&) = delete;
  auto operator=(const Device&) -> Device& = delete;

private:  friend class Device_Class;
  static CppClassType device_class_;

protected:
  explicit Device(const Glib::ConstructParams& construct_params);
  explicit Device(GdkDevice* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Device(Device&& src) noexcept;
  auto operator=(Device&& src) noexcept -> Device&;

  ~Device() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkDevice*       { return reinterpret_cast<GdkDevice*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkDevice* { return reinterpret_cast<GdkDevice*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkDevice*;

private:


protected:
  Device();

public:

  /** The name of the device, suitable for showing in a user interface.
   *
   * @return A name.
   */
  auto get_name() const -> Glib::ustring;

  /** Determines whether the pointer follows device motion.
   *
   * This is not meaningful for keyboard devices, which
   * don't have a pointer.
   *
   * @return <tt>true</tt> if the pointer follows device motion.
   */
  auto get_has_cursor() const -> bool;


  /** Determines the type of the device.
   *
   * @return A `Gdk::InputSource`.
   */
  auto get_source() const -> InputSource;


  /** Returns the `Gdk::Display` to which @a device pertains.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Returns the `Gdk::Display` to which @a device pertains.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;


  /** Obtains the surface underneath @a device, returning the location of the
   * device in @a win_x and @a win_y.
   *
   * @param win_x Return location for the X coordinate
   * of the device location relative to the surface origin.
   * @param win_y Return location for the Y coordinate
   * of the device location relative to the surface origin.
   * @return The `Gdk::Surface` under the
   * device position.
   */
  auto get_surface_at_position(double& win_x, double& win_y) -> Glib::RefPtr<Surface>;

  /** Obtains the surface underneath @a device, returning the location of the
   * device in @a win_x and @a win_y.
   *
   * @param win_x Return location for the X coordinate
   * of the device location relative to the surface origin.
   * @param win_y Return location for the Y coordinate
   * of the device location relative to the surface origin.
   * @return The `Gdk::Surface` under the
   * device position.
   */
  auto get_surface_at_position(double& win_x, double& win_y) const -> Glib::RefPtr<const Surface>;

  /** Obtains the surface underneath the device.
   * Returns an empty RefPtr if the surface tree under the device is not known to GDK (for example, belongs to another application).
   *
   * @newin{3,0}
   *
   * @return The Gdk::Surface under the device position.
   */
  auto get_surface_at_position() -> Glib::RefPtr<Surface>;

  /** Obtains the surface underneath the device.
   * Returns an empty RefPtr if the surface tree under the device is not known to GDK (for example, belongs to another application).
   *
   * @newin{3,0}
   *
   * @return The Gdk::Surface under the device position.
   */
  auto get_surface_at_position() const -> Glib::RefPtr<const Surface>;


  /** Returns the vendor ID of this device.
   *
   * This ID is retrieved from the device, and does not change.
   *
   * This function, together with get_product_id(),
   * can be used to eg. compose `Gio::Settings` paths to store settings
   * for this device.
   *
   *
   * [C example ellipted]
   *
   * @return The vendor ID.
   */
  auto get_vendor_id() const -> Glib::ustring;

  /** Returns the product ID of this device.
   *
   * This ID is retrieved from the device, and does not change.
   * See get_vendor_id() for more information.
   *
   * @return The product ID.
   */
  auto get_product_id() -> Glib::ustring;


  /** Returns the `Gdk::Seat` the device belongs to.
   *
   * @return A `Gdk::Seat`.
   */
  auto get_seat() -> Glib::RefPtr<Seat>;

  /** Returns the `Gdk::Seat` the device belongs to.
   *
   * @return A `Gdk::Seat`.
   */
  auto get_seat() const -> Glib::RefPtr<const Seat>;


  /** Retrieves the number of touch points associated to @a device.
   *
   * @return The number of touch points.
   */
  auto get_num_touches() const -> guint;

  //TODO: Has gdk_device_get_device_tool() been deprecated by mistake?
  //_WRAP_METHOD(Glib::RefPtr<DeviceTool> get_device_tool(), gdk_device_get_device_tool, refreturn)
  //_WRAP_METHOD(Glib::RefPtr<const DeviceTool> get_device_tool() const, gdk_device_get_device_tool, refreturn, constversion)

  /** Retrieves the current tool for @a device.
   *
   * @return The `Gdk::DeviceTool`.
   */

  auto get_device_tool() -> Glib::RefPtr<DeviceTool>;

  /** Retrieves the current tool for @a device.
   *
   * @return The `Gdk::DeviceTool`.
   */

  auto get_device_tool() const -> Glib::RefPtr<const DeviceTool>;


  /** Retrieves whether the Caps Lock modifier of the keyboard is locked.
   *
   * This is only relevant for keyboard devices.
   *
   * @return <tt>true</tt> if Caps Lock is on for @a device.
   */
  auto get_caps_lock_state() const -> bool;

  /** Retrieves whether the Num Lock modifier of the keyboard is locked.
   *
   * This is only relevant for keyboard devices.
   *
   * @return <tt>true</tt> if Num Lock is on for @a device.
   */
  auto get_num_lock_state() const -> bool;

  /** Retrieves whether the Scroll Lock modifier of the keyboard is locked.
   *
   * This is only relevant for keyboard devices.
   *
   * @return <tt>true</tt> if Scroll Lock is on for @a device.
   */
  auto get_scroll_lock_state() const -> bool;

  /** Retrieves the current modifier state of the keyboard.
   *
   * This is only relevant for keyboard devices.
   *
   * @return The current modifier state.
   */
  auto get_modifier_state() const -> ModifierType;

  /** Returns the direction of effective layout of the keyboard.
   *
   * This is only relevant for keyboard devices.
   *
   * The direction of a layout is the direction of the majority
   * of its symbols. See pango_unichar_direction().
   *
   * @return Pango::Direction::LTR or Pango::Direction::RTL
   * if it can determine the direction. Pango::Direction::NEUTRAL
   * otherwise.
   */
  auto get_direction() const -> Pango::Direction;

  /** Determines if layouts for both right-to-left and
   * left-to-right languages are in use on the keyboard.
   *
   * This is only relevant for keyboard devices.
   *
   * @return <tt>true</tt> if there are layouts with both directions, <tt>false</tt> otherwise.
   */
  auto has_bidi_layouts() const -> bool;

  /** Returns the timestamp of the last activity for this device.
   *
   * In practice, this means the timestamp of the last event that was
   * received from the OS for this device. (GTK may occasionally produce
   * events for a device that are not received from the OS, and will not
   * update the timestamp).
   *
   * @newin{4,2}
   *
   * @return The timestamp of the last activity for this device.
   */
  auto get_timestamp() const -> guint32;

  /** Checks if this %Device instance is a DeviceWithPad.
   *
   * The underlying C object is usually a subclass of GdkDevice. If that subclass
   * implements the GdkDevicePad interface, this C++ %Gdk::Device instance is
   * a Gdk::DeviceWithPad instance, and can be cast to a Gdk::DeviceWithPad
   * by device_with_pad_cast().
   *
   * @return <tt>true</tt> if this instance is a DeviceWithPad.
   *
   * @newin{3,96}
   */
  auto has_device_pad() const -> bool;

  /** Casts this %Device instance to a DeviceWithPad, if possible.
   *
   * @return A DeviceWithPad pointer, or an empty Glib::RefPtr if this %Device
   *         can't be dynamic_cast to a %DeviceWithPad.
   *
   * @newin{3,96}
   */
  auto device_with_pad_cast() -> Glib::RefPtr<DeviceWithPad>;

  /** Casts this %Device instance to a DeviceWithPad, if possible.
   *
   * @return A DeviceWithPad pointer, or an empty Glib::RefPtr if this %Device
   *         can't be dynamic_cast to a %DeviceWithPad.
   *
   * @newin{3,96}
   */
  auto device_with_pad_cast() const -> Glib::RefPtr<const DeviceWithPad>;

  // We use no_default_handler because _GdkDeviceClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted either when the number of either axes or keys changes.
   *
   * On X11 this will normally happen when the physical device
   * routing events through the logical device changes (for
   * example, user switches from the USB mouse to a tablet); in
   * that case the logical device will change to reflect the axes
   * and keys on the new physical device.
   *
   * @newin{3,22}
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%tool_changed(const Glib::RefPtr<DeviceTool>& tool)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on pen/eraser devices whenever tools enter or leave proximity.
   *
   * @newin{3,94}
   *
   * @param tool The new current tool.
   */

  auto signal_tool_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<DeviceTool>&)>;


  /** The `Gdk::Display` the `Gdk::Device` pertains to.
   *
   * @newin{3,22}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >;


  /** The device name.
   *
   * @newin{3,22}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Source type for the device.
   *
   * @newin{3,22}
   *
   * Default value: Gdk::InputSource::MOUSE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_source() const -> Glib::PropertyProxy_ReadOnly< InputSource >;


  /** Whether the device is represented by a cursor on the screen.
   *
   * @newin{3,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_cursor() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Number of axes in the device.
   *
   * @newin{3,22}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_n_axes() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** Vendor ID of this device.
   *
   * See Gdk::Device::get_vendor_id().
   *
   * @newin{3,22}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vendor_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Product ID of this device.
   *
   * See Gdk::Device::get_product_id().
   *
   * @newin{3,22}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_product_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** `Gdk::Seat` of this device.
   *
   * @newin{3,22}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_seat() -> Glib::PropertyProxy< Glib::RefPtr<Seat> > ;

/** `Gdk::Seat` of this device.
   *
   * @newin{3,22}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_seat() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Seat> >;

  /** The maximal number of concurrent touches on a touch device.
   *
   * Will be 0 if the device is not a touch device or if the number
   * of touches is unknown.
   *
   * @newin{3,22}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_num_touches() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** The `Gdk::DeviceTool` that is currently used with this device.
   *
   * @newin{3,94}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tool() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<DeviceTool> >;


  /** The direction of the current layout.
   *
   * This is only relevant for keyboard devices.
   *
   * Default value: Pango::Direction::NEUTRAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_direction() const -> Glib::PropertyProxy_ReadOnly< Pango::Direction >;


  /** Whether the device has both right-to-left and left-to-right layouts.
   *
   * This is only relevant for keyboard devices.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_bidi_layouts() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether Caps Lock is on.
   *
   * This is only relevant for keyboard devices.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_caps_lock_state() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether Num Lock is on.
   *
   * This is only relevant for keyboard devices.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_num_lock_state() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether Scroll Lock is on.
   *
   * This is only relevant for keyboard devices.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scroll_lock_state() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The current modifier state of the device.
   *
   * This is only relevant for keyboard devices.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modifier_state() const -> Glib::PropertyProxy_ReadOnly< ModifierType >;


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
   * @relates Gdk::Device
   */
  GDKMM_API
  auto wrap(GdkDevice* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Device>;
}


#endif /* _GDKMM_DEVICE_H */

