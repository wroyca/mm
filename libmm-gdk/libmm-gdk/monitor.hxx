// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_MONITOR_H
#define _GDKMM_MONITOR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/rectangle.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkMonitor = struct _GdkMonitor;
using GdkMonitorClass = struct _GdkMonitorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT Monitor_Class;
}
#endif

namespace Gdk
{

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
  class LIBMM_GDK_SYMEXPORT Value<Gdk::SubpixelLayout>
    : public Glib::Value_Enum<Gdk::SubpixelLayout>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT Display;

  class LIBMM_GDK_SYMEXPORT Monitor : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Monitor;
    using CppClassType = Monitor_Class;
    using BaseObjectType = GdkMonitor;
    using BaseClassType = GdkMonitorClass;

    Monitor (const Monitor&) = delete;
    auto
    operator= (const Monitor&) -> Monitor& = delete;

  private:
    friend class Monitor_Class;
    static CppClassType monitor_class_;

  protected:
    explicit Monitor (const Glib::ConstructParams& construct_params);
    explicit Monitor (GdkMonitor* castitem);

#endif

  public:
    Monitor (Monitor&& src) noexcept;
    auto
    operator= (Monitor&& src) noexcept -> Monitor&;

    ~Monitor () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkMonitor*
    {
      return reinterpret_cast<GdkMonitor*> (gobject_);
    }

    auto
    gobj () const -> const GdkMonitor*
    {
      return reinterpret_cast<GdkMonitor*> (gobject_);
    }

    auto
    gobj_copy () -> GdkMonitor*;

  private:
  protected:
    Monitor ();

  public:
    auto
    get_display () -> Glib::RefPtr<Display>;

    auto
    get_display () const -> Glib::RefPtr<const Display>;

    auto
    get_geometry (Rectangle& geometry) const -> void;

    auto
    get_width_mm () const -> int;

    auto
    get_height_mm () const -> int;

    auto
    get_manufacturer () const -> Glib::ustring;

    auto
    get_model () const -> Glib::ustring;

    auto
    get_connector () const -> Glib::ustring;

    auto
    get_scale_factor () const -> int;

    auto
    get_refresh_rate () const -> int;

    auto
    get_subpixel_layout () const -> SubpixelLayout;

    auto
    is_valid () const -> bool;

    auto
    get_description () const -> Glib::ustring;

    auto
    signal_invalidate () -> Glib::SignalProxy<void ()>;

    auto
    property_description () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>;

    auto
    property_manufacturer () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_connector () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_scale_factor () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_geometry () const -> Glib::PropertyProxy_ReadOnly<Gdk::Rectangle>;

    auto
    property_width_mm () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height_mm () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_refresh_rate () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_subpixel_layout () const
        -> Glib::PropertyProxy_ReadOnly<SubpixelLayout>;

    auto
    property_valid () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkMonitor* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Monitor>;
} // namespace Glib

#endif
