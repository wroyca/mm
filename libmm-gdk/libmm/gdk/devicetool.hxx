// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DEVICETOOL_H
#define _GDKMM_DEVICETOOL_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/enums.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDeviceTool = struct _GdkDeviceTool;
using GdkDeviceToolClass = struct _GdkDeviceToolClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT DeviceTool_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DeviceTool : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DeviceTool;
    using CppClassType = DeviceTool_Class;
    using BaseObjectType = GdkDeviceTool;
    using BaseClassType = GdkDeviceToolClass;

    DeviceTool (const DeviceTool&) = delete;
    auto
    operator= (const DeviceTool&) -> DeviceTool& = delete;

  private:
    friend class DeviceTool_Class;
    static CppClassType devicetool_class_;

  protected:
    explicit DeviceTool (const glib::ConstructParams& construct_params);
    explicit DeviceTool (GdkDeviceTool* castitem);

#endif

  public:
    DeviceTool (DeviceTool&& src) noexcept;
    auto
    operator= (DeviceTool&& src) noexcept -> DeviceTool&;

    ~DeviceTool () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkDeviceTool*
    {
      return reinterpret_cast<GdkDeviceTool*> (gobject_);
    }

    auto
    gobj () const -> const GdkDeviceTool*
    {
      return reinterpret_cast<GdkDeviceTool*> (gobject_);
    }

    auto
    gobj_copy () -> GdkDeviceTool*;

  private:
  public:
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

    auto
    get_serial () const -> guint64;

    auto
    get_hardware_id () const -> guint64;

    auto
    get_tool_type () const -> Type;

    auto
    get_axes () const -> AxisFlags;

    auto
    property_serial () const -> glib::PropertyProxy_ReadOnly<guint64>;

    auto
    property_tool_type () const -> glib::PropertyProxy_ReadOnly<Type>;

    auto
    property_axes () const -> glib::PropertyProxy_ReadOnly<AxisFlags>;

    auto
    property_hardware_id () const -> glib::PropertyProxy_ReadOnly<guint64>;

  public:
  public:
  protected:
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::DeviceTool::Type>
    : public glib::Value_Enum<gdk::DeviceTool::Type>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDeviceTool* object, bool take_copy = false) -> glib::RefPtr<gdk::DeviceTool>;
} // namespace glib

#endif
