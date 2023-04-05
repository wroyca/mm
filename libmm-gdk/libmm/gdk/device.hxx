// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DEVICE_H
#define _GDKMM_DEVICE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm/gdk/cursor.hxx>
#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/timecoord.hxx>
#include <libmm/pango/context.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDevice = struct _GdkDevice;
using GdkDeviceClass = struct _GdkDeviceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Device_Class;
}
#endif

namespace gdk
{

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

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::InputSource>
    : public glib::Value_Enum<gdk::InputSource>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DeviceTool;
  class LIBMM_GDK_SYMEXPORT DeviceWithPad;
  class LIBMM_GDK_SYMEXPORT Display;
  class LIBMM_GDK_SYMEXPORT Seat;
  class LIBMM_GDK_SYMEXPORT Surface;

  class LIBMM_GDK_SYMEXPORT Device : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Device;
    using CppClassType = Device_Class;
    using BaseObjectType = GdkDevice;
    using BaseClassType = GdkDeviceClass;

    Device (const Device&) = delete;
    auto
    operator= (const Device&) -> Device& = delete;

  private:
    friend class Device_Class;
    static CppClassType device_class_;

  protected:
    explicit Device (const glib::ConstructParams& construct_params);
    explicit Device (GdkDevice* castitem);

#endif

  public:
    Device (Device&& src) noexcept;
    auto
    operator= (Device&& src) noexcept -> Device&;

    ~Device () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkDevice*
    {
      return reinterpret_cast<GdkDevice*> (gobject_);
    }

    auto
    gobj () const -> const GdkDevice*
    {
      return reinterpret_cast<GdkDevice*> (gobject_);
    }

    auto
    gobj_copy () -> GdkDevice*;

  private:
  protected:
    Device ();

  public:
    auto
    get_name () const -> glib::ustring;

    auto
    get_has_cursor () const -> bool;

    auto
    get_source () const -> InputSource;

    auto
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    get_surface_at_position (double& win_x, double& win_y)
        -> glib::RefPtr<Surface>;

    auto
    get_surface_at_position (double& win_x, double& win_y) const
        -> glib::RefPtr<const Surface>;

    auto
    get_surface_at_position () -> glib::RefPtr<Surface>;

    auto
    get_surface_at_position () const -> glib::RefPtr<const Surface>;

    auto
    get_vendor_id () const -> glib::ustring;

    auto
    get_product_id () -> glib::ustring;

    auto
    get_seat () -> glib::RefPtr<Seat>;

    auto
    get_seat () const -> glib::RefPtr<const Seat>;

    auto
    get_num_touches () const -> guint;

    auto
    get_device_tool () -> glib::RefPtr<DeviceTool>;

    auto
    get_device_tool () const -> glib::RefPtr<const DeviceTool>;

    auto
    get_caps_lock_state () const -> bool;

    auto
    get_num_lock_state () const -> bool;

    auto
    get_scroll_lock_state () const -> bool;

    auto
    get_modifier_state () const -> ModifierType;

    auto
    get_direction () const -> pango::Direction;

    auto
    has_bidi_layouts () const -> bool;

    auto
    get_timestamp () const -> guint32;

    auto
    has_device_pad () const -> bool;

    auto
    device_with_pad_cast () -> glib::RefPtr<DeviceWithPad>;

    auto
    device_with_pad_cast () const -> glib::RefPtr<const DeviceWithPad>;

    auto
    signal_changed () -> glib::SignalProxy<void ()>;

    auto
    signal_tool_changed ()
        -> glib::SignalProxy<void (const glib::RefPtr<DeviceTool>&)>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_source () const -> glib::PropertyProxy_ReadOnly<InputSource>;

    auto
    property_has_cursor () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_n_axes () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_vendor_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_product_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_seat () -> glib::PropertyProxy<glib::RefPtr<Seat>>;

    auto
    property_seat () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Seat>>;

    auto
    property_num_touches () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_tool () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<DeviceTool>>;

    auto
    property_direction () const
        -> glib::PropertyProxy_ReadOnly<pango::Direction>;

    auto
    property_has_bidi_layouts () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_caps_lock_state () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_num_lock_state () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_scroll_lock_state () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modifier_state () const
        -> glib::PropertyProxy_ReadOnly<ModifierType>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDevice* object, bool take_copy = false) -> glib::RefPtr<gdk::Device>;
} // namespace glib

#endif
