// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GDKMM_MONITOR_H
#define _GDKMM_MONITOR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2016 The gtkmm Development Team
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

#include <glibmm/object.h>
#include <gdkmm/rectangle.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkMonitor = struct _GdkMonitor;
using GdkMonitorClass = struct _GdkMonitorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Monitor_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/** 
 *  @var SubpixelLayout UNKNOWN
 * The layout is not known.
 * 
 *  @var SubpixelLayout NONE
 * Not organized in this way.
 * 
 *  @var SubpixelLayout HORIZONTAL_RGB
 * The layout is horizontal, the order is RGB.
 * 
 *  @var SubpixelLayout HORIZONTAL_BGR
 * The layout is horizontal, the order is BGR.
 * 
 *  @var SubpixelLayout VERTICAL_RGB
 * The layout is vertical, the order is RGB.
 * 
 *  @var SubpixelLayout VERTICAL_BGR
 * The layout is vertical, the order is BGR.
 * 
 *  @enum SubpixelLayout
 * 
 * This enumeration describes how the red, green and blue components
 * of physical pixels on an output device are laid out.
 *
 * @ingroup gdkmmEnums
 */
enum class SubpixelLayout
{
  UNKNOWN,
  NONE,
  HORIZONTAL_RGB,
  HORIZONTAL_BGR,
  VERTICAL_RGB,
  VERTICAL_BGR
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::SubpixelLayout> : public Glib::Value_Enum<Gdk::SubpixelLayout>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


class GDKMM_API Display;

/** Object representing an output.
 *
 * Gdk::Monitor objects represent the individual outputs that are
 * associated with a Gdk::Display. Display has APIs to enumerate
 * monitors with Display::get_n_monitors() and Display::get_monitor()
 * and to find particular monitors with Display::get_monitor_at_surface().
 *
 * @newin{3,22}
 */

class GDKMM_API Monitor : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Monitor;
  using CppClassType = Monitor_Class;
  using BaseObjectType = GdkMonitor;
  using BaseClassType = GdkMonitorClass;

  // noncopyable
  Monitor(const Monitor&) = delete;
  Monitor& operator=(const Monitor&) = delete;

private:  friend class Monitor_Class;
  static CppClassType monitor_class_;

protected:
  explicit Monitor(const Glib::ConstructParams& construct_params);
  explicit Monitor(GdkMonitor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Monitor(Monitor&& src) noexcept;
  Monitor& operator=(Monitor&& src) noexcept;

  ~Monitor() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkMonitor*       gobj()       { return reinterpret_cast<GdkMonitor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkMonitor* gobj() const { return reinterpret_cast<GdkMonitor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkMonitor* gobj_copy();

private:


protected:
  Monitor();

public:
  
  /** Gets the display that this monitor belongs to.
   * 
   * @return The display.
   */
  Glib::RefPtr<Display> get_display();
  
  /** Gets the display that this monitor belongs to.
   * 
   * @return The display.
   */
  Glib::RefPtr<const Display> get_display() const;
  
  /** Retrieves the size and position of the monitor within the
   * display coordinate space.
   * 
   * The returned geometry is in  ”application pixels”, not in
   * ”device pixels” (see get_scale_factor()).
   * 
   * @param geometry A `Gdk::Rectangle` to be filled with the monitor geometry.
   */
  void get_geometry(Rectangle& geometry) const;
  
  /** Gets the width in millimeters of the monitor.
   * 
   * @return The physical width of the monitor.
   */
  int get_width_mm() const;
  
  /** Gets the height in millimeters of the monitor.
   * 
   * @return The physical height of the monitor.
   */
  int get_height_mm() const;
  
  /** Gets the name or PNP ID of the monitor's manufacturer.
   * 
   * Note that this value might also vary depending on actual
   * display backend.
   * 
   * The PNP ID registry is located at
   * [https://uefi.org/pnp_id_list](https://uefi.org/pnp_id_list).
   * 
   * @return The name of the manufacturer.
   */
  Glib::ustring get_manufacturer() const;
  
  /** Gets the string identifying the monitor model, if available.
   * 
   * @return The monitor model.
   */
  Glib::ustring get_model() const;
  
  /** Gets the name of the monitor's connector, if available.
   * 
   * @return The name of the connector.
   */
  Glib::ustring get_connector() const;
  
  /** Gets the internal scale factor that maps from monitor coordinates
   * to device pixels.
   * 
   * On traditional systems this is 1, but on very high density outputs
   * it can be a higher value (often 2).
   * 
   * This can be used if you want to create pixel based data for a
   * particular monitor, but most of the time you’re drawing to a surface
   * where it is better to use Gdk::Surface::get_scale_factor() instead.
   * 
   * @return The scale factor.
   */
  int get_scale_factor() const;
  
  /** Gets the refresh rate of the monitor, if available.
   * 
   * The value is in milli-Hertz, so a refresh rate of 60Hz
   * is returned as 60000.
   * 
   * @return The refresh rate in milli-Hertz, or 0.
   */
  int get_refresh_rate() const;
  
  /** Gets information about the layout of red, green and blue
   * primaries for pixels.
   * 
   * @return The subpixel layout.
   */
  SubpixelLayout get_subpixel_layout() const;
  
  /** Returns <tt>true</tt> if the @a monitor object corresponds to a
   * physical monitor.
   * 
   * The @a monitor becomes invalid when the physical monitor
   * is unplugged or removed.
   * 
   * @return <tt>true</tt> if the object corresponds to a physical monitor.
   */
  bool is_valid() const;

  // We use no_default_handler because _GdkMonitorClass is private
  // and there is no default handler in gtk+.
  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%invalidate()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the output represented by @a monitor gets disconnected.
   */

  Glib::SignalProxy<void()> signal_invalidate();


  /** The `Gdk::Display` of the monitor.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> > property_display() const;


  /** The manufacturer name.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_manufacturer() const;


  /** The model name.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_model() const;


  /** The connector name.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_connector() const;


  /** The scale factor.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_scale_factor() const;


  /** The geometry of the monitor.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Gdk::Rectangle > property_geometry() const;


  /** The width of the monitor, in millimeters.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_width_mm() const;


  /** The height of the monitor, in millimeters.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_height_mm() const;


  /** The refresh rate, in milli-Hertz.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_refresh_rate() const;


  /** The subpixel layout.
   *
   * Default value: Gdk::SubpixelLayout::UNKNOWN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< SubpixelLayout > property_subpixel_layout() const;


  /** Whether the object is still valid.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_valid() const;


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
   * @relates Gdk::Monitor
   */
  GDKMM_API
  Glib::RefPtr<Gdk::Monitor> wrap(GdkMonitor* object, bool take_copy = false);
}


#endif /* _GDKMM_MONITOR_H */

