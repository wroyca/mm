// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_SEAT_H
#define _GDKMM_SEAT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/cursor.hxx>
#include <libmm/gdk/device.hxx>
#include <libmm/gdk/event.hxx>
#include <libmm/glib/object.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkSeat = struct _GdkSeat;
using GdkSeatClass = struct _GdkSeatClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Seat_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DeviceTool;
  class LIBMM_GDK_SYMEXPORT Display;
  class LIBMM_GDK_SYMEXPORT Surface;

  class LIBMM_GDK_SYMEXPORT Seat : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Seat;
    using CppClassType = Seat_Class;
    using BaseObjectType = GdkSeat;
    using BaseClassType = GdkSeatClass;

    Seat (const Seat&) = delete;
    auto
    operator= (const Seat&) -> Seat& = delete;

  private:
    friend class Seat_Class;
    static CppClassType seat_class_;

  protected:
    explicit Seat (const glib::ConstructParams& construct_params);
    explicit Seat (GdkSeat* castitem);

#endif

  public:
    Seat (Seat&& src) noexcept;
    auto
    operator= (Seat&& src) noexcept -> Seat&;

    ~Seat () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkSeat*
    {
      return reinterpret_cast<GdkSeat*> (gobject_);
    }

    auto
    gobj () const -> const GdkSeat*
    {
      return reinterpret_cast<GdkSeat*> (gobject_);
    }

    auto
    gobj_copy () -> GdkSeat*;

  private:
  protected:
    Seat ();

  public:
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

    auto
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    get_capabilities () const -> Capabilities;

    auto
    get_devices (Capabilities capabilities)
        -> std::vector<glib::RefPtr<Device>>;

    auto
    get_devices (Capabilities capabilities) const
        -> std::vector<glib::RefPtr<const Device>>;

    auto
    get_tools () -> std::vector<glib::RefPtr<DeviceTool>>;

    auto
    get_tools () const -> std::vector<glib::RefPtr<const DeviceTool>>;

    auto
    get_pointer () -> glib::RefPtr<Device>;

    auto
    get_pointer () const -> glib::RefPtr<const Device>;

    auto
    get_keyboard () -> glib::RefPtr<Device>;

    auto
    get_keyboard () const -> glib::RefPtr<const Device>;

    auto
    signal_device_added ()
        -> glib::SignalProxy<void (const glib::RefPtr<Device>&)>;

    auto
    signal_device_removed ()
        -> glib::SignalProxy<void (const glib::RefPtr<Device>&)>;

    auto
    signal_tool_added ()
        -> glib::SignalProxy<void (const glib::RefPtr<DeviceTool>&)>;

    auto
    signal_tool_removed ()
        -> glib::SignalProxy<void (const glib::RefPtr<DeviceTool>&)>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace gdk
{

  inline auto
  operator| (Seat::Capabilities lhs, Seat::Capabilities rhs) -> Seat::Capabilities
  {
    return static_cast<Seat::Capabilities> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Seat::Capabilities lhs, Seat::Capabilities rhs) -> Seat::Capabilities
  {
    return static_cast<Seat::Capabilities> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Seat::Capabilities lhs, Seat::Capabilities rhs) -> Seat::Capabilities
  {
    return static_cast<Seat::Capabilities> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Seat::Capabilities flags) -> Seat::Capabilities
  {
    return static_cast<Seat::Capabilities> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Seat::Capabilities& lhs, Seat::Capabilities rhs) -> Seat::Capabilities&
  {
    return (lhs = static_cast<Seat::Capabilities> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Seat::Capabilities& lhs, Seat::Capabilities rhs) -> Seat::Capabilities&
  {
    return (lhs = static_cast<Seat::Capabilities> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Seat::Capabilities& lhs, Seat::Capabilities rhs) -> Seat::Capabilities&
  {
    return (lhs = static_cast<Seat::Capabilities> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::Seat::Capabilities>
    : public glib::Value_Flags<gdk::Seat::Capabilities>
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
  wrap (GdkSeat* object, bool take_copy = false) -> glib::RefPtr<gdk::Seat>;
} // namespace glib

#endif
