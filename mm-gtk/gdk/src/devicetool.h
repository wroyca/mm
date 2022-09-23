// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GDKMM_DEVICETOOL_H
#define _GDKMM_DEVICETOOL_H


#include <glibmm/ustring.h>
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

#include <glibmm/object.h>
#include <gdkmm/enums.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDeviceTool = struct _GdkDeviceTool;
using GdkDeviceToolClass = struct _GdkDeviceToolClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API DeviceTool_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
/** A physical tool associated to a Gdk::Device.
 *
 * @newin{3,94}
 */

class GDKMM_API DeviceTool : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DeviceTool;
  using CppClassType = DeviceTool_Class;
  using BaseObjectType = GdkDeviceTool;
  using BaseClassType = GdkDeviceToolClass;

  // noncopyable
  DeviceTool(const DeviceTool&) = delete;
  DeviceTool& operator=(const DeviceTool&) = delete;

private:  friend class DeviceTool_Class;
  static CppClassType devicetool_class_;

protected:
  explicit DeviceTool(const Glib::ConstructParams& construct_params);
  explicit DeviceTool(GdkDeviceTool* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DeviceTool(DeviceTool&& src) noexcept;
  DeviceTool& operator=(DeviceTool&& src) noexcept;

  ~DeviceTool() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkDeviceTool*       gobj()       { return reinterpret_cast<GdkDeviceTool*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkDeviceTool* gobj() const { return reinterpret_cast<GdkDeviceTool*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkDeviceTool* gobj_copy();

private:


public:
  /** @addtogroup gdkmmEnums gdkmm Enums and Flags */

  /** 
   *  @var Type UNKNOWN
   * Tool is of an unknown type.
   * 
   *  @var Type PEN
   * Tool is a standard tablet stylus.
   * 
   *  @var Type ERASER
   * Tool is standard tablet eraser.
   * 
   *  @var Type BRUSH
   * Tool is a brush stylus.
   * 
   *  @var Type PENCIL
   * Tool is a pencil stylus.
   * 
   *  @var Type AIRBRUSH
   * Tool is an airbrush stylus.
   * 
   *  @var Type MOUSE
   * Tool is a mouse.
   * 
   *  @var Type LENS
   * Tool is a lens cursor.
   * 
   *  @enum Type
   * 
   * Indicates the specific type of tool being used being a tablet. Such as an
   * airbrush, pencil, etc.
   *
   * @ingroup gdkmmEnums
   */
  enum class Type
  {
    UNKNOWN,
    PEN,
    ERASER,
    BRUSH,
    PENCIL,
    AIRBRUSH,
    MOUSE,
    LENS
  };


  /** Gets the serial number of this tool.
   * 
   * This value can be used to identify a physical tool
   * (eg. a tablet pen) across program executions.
   * 
   * @return The serial ID for this tool.
   */
  guint64 get_serial() const;
  
  /** Gets the hardware ID of this tool, or 0 if it's not known.
   * 
   * When non-zero, the identificator is unique for the given tool model,
   * meaning that two identical tools will share the same @a hardware_id,
   * but will have different serial numbers (see
   * get_serial()).
   * 
   * This is a more concrete (and device specific) method to identify
   * a `Gdk::DeviceTool` than get_tool_type(),
   * as a tablet may support multiple devices with the same
   * `Gdk::DeviceTool::Type`, but different hardware identificators.
   * 
   * @return The hardware identificator of this tool.
   */
  guint64 get_hardware_id() const;
  
  /** Gets the `Gdk::DeviceTool::Type` of the tool.
   * 
   * @return The physical type for this tool. This can be used to
   * figure out what sort of pen is being used, such as an airbrush
   * or a pencil.
   */
  Type get_tool_type() const;
  
  /** Gets the axes of the tool.
   * 
   * @return The axes of @a tool.
   */
  AxisFlags get_axes() const;

  /** The serial number of the tool.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< guint64 > property_serial() const;


  /** The type of the tool.
   *
   * Default value: Gdk::DeviceTool::Type::UNKNOWN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Type > property_tool_type() const;


  /** The axes of the tool.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< AxisFlags > property_axes() const;


  /** The hardware ID of the tool.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< guint64 > property_hardware_id() const;


  // There are no signals or vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::DeviceTool::Type> : public Glib::Value_Enum<Gdk::DeviceTool::Type>
{
public:
  static GType value_type() G_GNUC_CONST;
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
   * @relates Gdk::DeviceTool
   */
  GDKMM_API
  Glib::RefPtr<Gdk::DeviceTool> wrap(GdkDeviceTool* object, bool take_copy = false);
}


#endif /* _GDKMM_DEVICETOOL_H */

