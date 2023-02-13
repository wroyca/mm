
#ifndef _GDKMM_DEVICETOOL_H
#define _GDKMM_DEVICETOOL_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-glib/object.hpp>
#include <libmm-gdk/enums.hpp>


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
  auto operator=(const DeviceTool&) -> DeviceTool& = delete;

private:  friend class DeviceTool_Class;
  static CppClassType devicetool_class_;

protected:
  explicit DeviceTool(const Glib::ConstructParams& construct_params);
  explicit DeviceTool(GdkDeviceTool* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DeviceTool(DeviceTool&& src) noexcept;
  auto operator=(DeviceTool&& src) noexcept -> DeviceTool&;

  ~DeviceTool() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkDeviceTool*       { return reinterpret_cast<GdkDeviceTool*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkDeviceTool* { return reinterpret_cast<GdkDeviceTool*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkDeviceTool*;

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
  auto get_serial() const -> guint64;

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
  auto get_hardware_id() const -> guint64;

  /** Gets the `Gdk::DeviceTool::Type` of the tool.
   *
   * @return The physical type for this tool. This can be used to
   * figure out what sort of pen is being used, such as an airbrush
   * or a pencil.
   */
  auto get_tool_type() const -> Type;

  /** Gets the axes of the tool.
   *
   * @return The axes of @a tool.
   */
  auto get_axes() const -> AxisFlags;

  /** The serial number of the tool.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_serial() const -> Glib::PropertyProxy_ReadOnly< guint64 >;


  /** The type of the tool.
   *
   * Default value: Gdk::DeviceTool::Type::UNKNOWN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tool_type() const -> Glib::PropertyProxy_ReadOnly< Type >;


  /** The axes of the tool.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_axes() const -> Glib::PropertyProxy_ReadOnly< AxisFlags >;


  /** The hardware ID of the tool.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hardware_id() const -> Glib::PropertyProxy_ReadOnly< guint64 >;


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
   * @relates Gdk::DeviceTool
   */
  GDKMM_API
  auto wrap(GdkDeviceTool* object, bool take_copy = false) -> Glib::RefPtr<Gdk::DeviceTool>;
}


#endif /* _GDKMM_DEVICETOOL_H */

