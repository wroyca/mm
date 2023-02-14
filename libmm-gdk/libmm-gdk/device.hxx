
#ifndef _GDKMM_DEVICE_H
#define _GDKMM_DEVICE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm-gdk/cursor.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/timecoord.hxx>
#include <libmm-pango/context.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDevice = struct _GdkDevice;
using GdkDeviceClass = struct _GdkDeviceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API Device_Class;
}
#endif

namespace Gdk
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

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::InputSource>
    : public Glib::Value_Enum<Gdk::InputSource>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
{

  class GDKMM_API DeviceTool;
  class GDKMM_API DeviceWithPad;
  class GDKMM_API Display;
  class GDKMM_API Seat;
  class GDKMM_API Surface;

  class GDKMM_API Device : public Glib::Object
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
    explicit Device (const Glib::ConstructParams& construct_params);
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
    get_name () const -> Glib::ustring;

    auto
    get_has_cursor () const -> bool;

    auto
    get_source () const -> InputSource;

    auto
    get_display () -> Glib::RefPtr<Display>;

    auto
    get_display () const -> Glib::RefPtr<const Display>;

    auto
    get_surface_at_position (double& win_x, double& win_y)
        -> Glib::RefPtr<Surface>;

    auto
    get_surface_at_position (double& win_x, double& win_y) const
        -> Glib::RefPtr<const Surface>;

    auto
    get_surface_at_position () -> Glib::RefPtr<Surface>;

    auto
    get_surface_at_position () const -> Glib::RefPtr<const Surface>;

    auto
    get_vendor_id () const -> Glib::ustring;

    auto
    get_product_id () -> Glib::ustring;

    auto
    get_seat () -> Glib::RefPtr<Seat>;

    auto
    get_seat () const -> Glib::RefPtr<const Seat>;

    auto
    get_num_touches () const -> guint;

    auto
    get_device_tool () -> Glib::RefPtr<DeviceTool>;

    auto
    get_device_tool () const -> Glib::RefPtr<const DeviceTool>;

    auto
    get_caps_lock_state () const -> bool;

    auto
    get_num_lock_state () const -> bool;

    auto
    get_scroll_lock_state () const -> bool;

    auto
    get_modifier_state () const -> ModifierType;

    auto
    get_direction () const -> Pango::Direction;

    auto
    has_bidi_layouts () const -> bool;

    auto
    get_timestamp () const -> guint32;

    auto
    has_device_pad () const -> bool;

    auto
    device_with_pad_cast () -> Glib::RefPtr<DeviceWithPad>;

    auto
    device_with_pad_cast () const -> Glib::RefPtr<const DeviceWithPad>;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_tool_changed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<DeviceTool>&)>;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_source () const -> Glib::PropertyProxy_ReadOnly<InputSource>;

    auto
    property_has_cursor () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_n_axes () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_vendor_id () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_product_id () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_seat () -> Glib::PropertyProxy<Glib::RefPtr<Seat>>;

    auto
    property_seat () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Seat>>;

    auto
    property_num_touches () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_tool () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<DeviceTool>>;

    auto
    property_direction () const
        -> Glib::PropertyProxy_ReadOnly<Pango::Direction>;

    auto
    property_has_bidi_layouts () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_caps_lock_state () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_num_lock_state () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_scroll_lock_state () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modifier_state () const
        -> Glib::PropertyProxy_ReadOnly<ModifierType>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkDevice* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Device>;
} // namespace Glib

#endif
