
#ifndef _GDKMM_SEAT_H
#define _GDKMM_SEAT_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2015 The gtkmm Development Team
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

#include <vector>
#include <libmm-glib/object.hxx>
#include <libmm-gdk/cursor.hxx>
#include <libmm-gdk/device.hxx>
#include <libmm-gdk/event.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkSeat = struct _GdkSeat;
using GdkSeatClass = struct _GdkSeatClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Seat_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

class GDKMM_API DeviceTool;
class GDKMM_API Display;
class GDKMM_API Surface;

/** A Gdk::Seat object represents a collection of input devices that belong to a user.
 *
 * @newin{3,20}
 */

class GDKMM_API Seat : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Seat;
  using CppClassType = Seat_Class;
  using BaseObjectType = GdkSeat;
  using BaseClassType = GdkSeatClass;

  // noncopyable
  Seat(const Seat&) = delete;
  auto operator=(const Seat&) -> Seat& = delete;

private:  friend class Seat_Class;
  static CppClassType seat_class_;

protected:
  explicit Seat(const Glib::ConstructParams& construct_params);
  explicit Seat(GdkSeat* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Seat(Seat&& src) noexcept;
  auto operator=(Seat&& src) noexcept -> Seat&;

  ~Seat() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkSeat*       { return reinterpret_cast<GdkSeat*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkSeat* { return reinterpret_cast<GdkSeat*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkSeat*;

private:


protected:
  Seat();

public:
  /** @addtogroup gdkmmEnums gdkmm Enums and Flags */

  /**
   *  @var Capabilities NONE
   * No input capabilities.
   *
   *  @var Capabilities POINTER
   * The seat has a pointer (e.g. mouse).
   *
   *  @var Capabilities TOUCH
   * The seat has touchscreen(s) attached.
   *
   *  @var Capabilities TABLET_STYLUS
   * The seat has drawing tablet(s) attached.
   *
   *  @var Capabilities KEYBOARD
   * The seat has keyboard(s) attached.
   *
   *  @var Capabilities TABLET_PAD
   * The seat has drawing tablet pad(s) attached.
   *
   *  @var Capabilities ALL_POINTING
   * The union of all pointing capabilities.
   *
   *  @var Capabilities ALL
   * The union of all capabilities.
   *
   *  @enum Capabilities
   *
   * Flags describing the seat capabilities.
   *
   * @ingroup gdkmmEnums
   * @par Bitwise operators:
   * <tt>Seat::Capabilities operator|(Seat::Capabilities, Seat::Capabilities)</tt><br>
   * <tt>Seat::Capabilities operator&(Seat::Capabilities, Seat::Capabilities)</tt><br>
   * <tt>Seat::Capabilities operator^(Seat::Capabilities, Seat::Capabilities)</tt><br>
   * <tt>Seat::Capabilities operator~(Seat::Capabilities)</tt><br>
   * <tt>Seat::Capabilities& operator|=(Seat::Capabilities&, Seat::Capabilities)</tt><br>
   * <tt>Seat::Capabilities& operator&=(Seat::Capabilities&, Seat::Capabilities)</tt><br>
   * <tt>Seat::Capabilities& operator^=(Seat::Capabilities&, Seat::Capabilities)</tt><br>
   */
  enum class Capabilities
  {
    NONE = 0x0,
    POINTER = 1 << 0,
    TOUCH = 1 << 1,
    TABLET_STYLUS = 1 << 2,
    KEYBOARD = 1 << 3,
    TABLET_PAD = 1 << 4,
    ALL_POINTING = 0x7,
    ALL = 0xF
  };


  /** Returns the `Gdk::Display` this seat belongs to.
   *
   * @return A `Gdk::Display`. This object
   * is owned by GTK and must not be freed.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Returns the `Gdk::Display` this seat belongs to.
   *
   * @return A `Gdk::Display`. This object
   * is owned by GTK and must not be freed.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;

  /** Returns the capabilities this `Gdk::Seat` currently has.
   *
   * @return The seat capabilities.
   */
  auto get_capabilities() const -> Capabilities;


  /** Returns the devices that match the given capabilities.
   *
   * @param capabilities Capabilities to get devices for.
   * @return A list
   * of `Gdk::Devices`.
   */
  auto get_devices(Capabilities capabilities) -> std::vector<Glib::RefPtr<Device>>;


  /** Returns the devices that match the given capabilities.
   *
   * @param capabilities Capabilities to get devices for.
   * @return A list
   * of `Gdk::Devices`.
   */
  auto get_devices(Capabilities capabilities) const -> std::vector<Glib::RefPtr<const Device>>;


  /** Returns all `Gdk::DeviceTools` that are known to the application.
   *
   * @return A list of tools.
   */
  auto get_tools() -> std::vector<Glib::RefPtr<DeviceTool>>;


  /** Returns all `Gdk::DeviceTools` that are known to the application.
   *
   * @return A list of tools.
   */
  auto get_tools() const -> std::vector<Glib::RefPtr<const DeviceTool>>;


  /** Returns the device that routes pointer events.
   *
   * @return A `Gdk::Device` with pointer
   * capabilities. This object is owned by GTK and must not be freed.
   */
  auto get_pointer() -> Glib::RefPtr<Device>;

  /** Returns the device that routes pointer events.
   *
   * @return A `Gdk::Device` with pointer
   * capabilities. This object is owned by GTK and must not be freed.
   */
  auto get_pointer() const -> Glib::RefPtr<const Device>;

  /** Returns the device that routes keyboard events.
   *
   * @return A `Gdk::Device` with keyboard
   * capabilities. This object is owned by GTK and must not be freed.
   */
  auto get_keyboard() -> Glib::RefPtr<Device>;

  /** Returns the device that routes keyboard events.
   *
   * @return A `Gdk::Device` with keyboard
   * capabilities. This object is owned by GTK and must not be freed.
   */
  auto get_keyboard() const -> Glib::RefPtr<const Device>;

  // We use no_default_handler because GdkSeatClass is private.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%device_added(const Glib::RefPtr<Device>& device)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a new input device is related to this seat.
   *
   * @param device The newly added `Gdk::Device`.
   */

  auto signal_device_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Device>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%device_removed(const Glib::RefPtr<Device>& device)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when an input device is removed (e.g.\ unplugged).
   *
   * @param device The just removed `Gdk::Device`.
   */

  auto signal_device_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Device>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%tool_added(const Glib::RefPtr<DeviceTool>& device)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a new tool is made known to the seat.
   *
   * The tool may later be assigned to a device (i.e. on
   * proximity with a tablet). The device will emit the
   * Gdk::Device::signal_tool_changed() signal accordingly.
   *
   * A same tool may be used by several devices.
   *
   * @newin{3,94}
   *
   * @param device The new `Gdk::DeviceTool` known to the seat.
   */

  auto signal_tool_added() -> Glib::SignalProxy<void(const Glib::RefPtr<DeviceTool>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%tool_removed(const Glib::RefPtr<DeviceTool>& device)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a tool is no longer known to this @a seat.
   *
   * @newin{3,94}
   *
   * @param device The just removed `Gdk::DeviceTool`.
   */

  auto signal_tool_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<DeviceTool>&)>;


  /** `Gdk::Display` of this seat.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >;


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
inline auto operator|(Seat::Capabilities lhs, Seat::Capabilities rhs) -> Seat::Capabilities
  { return static_cast<Seat::Capabilities>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(Seat::Capabilities lhs, Seat::Capabilities rhs) -> Seat::Capabilities
  { return static_cast<Seat::Capabilities>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(Seat::Capabilities lhs, Seat::Capabilities rhs) -> Seat::Capabilities
  { return static_cast<Seat::Capabilities>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(Seat::Capabilities flags) -> Seat::Capabilities
  { return static_cast<Seat::Capabilities>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(Seat::Capabilities& lhs, Seat::Capabilities rhs) -> Seat::Capabilities&
  { return (lhs = static_cast<Seat::Capabilities>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(Seat::Capabilities& lhs, Seat::Capabilities rhs) -> Seat::Capabilities&
  { return (lhs = static_cast<Seat::Capabilities>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(Seat::Capabilities& lhs, Seat::Capabilities rhs) -> Seat::Capabilities&
  { return (lhs = static_cast<Seat::Capabilities>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::Seat::Capabilities> : public Glib::Value_Flags<Gdk::Seat::Capabilities>
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
   * @relates Gdk::Seat
   */
  GDKMM_API
  auto wrap(GdkSeat* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Seat>;
}


#endif /* _GDKMM_SEAT_H */
