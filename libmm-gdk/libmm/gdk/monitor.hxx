// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_MONITOR_H
#define _GDKMM_MONITOR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/rectangle.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkMonitor = struct _GdkMonitor;
using GdkMonitorClass = struct _GdkMonitorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Monitor_Class;
}
#endif

namespace gdk
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

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::SubpixelLayout>
    : public glib::Value_Enum<gdk::SubpixelLayout>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Display;

  class LIBMM_GDK_SYMEXPORT Monitor : public glib::Object
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
    explicit Monitor (const glib::ConstructParams& construct_params);
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
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    get_geometry (Rectangle& geometry) const -> void;

    auto
    get_width_mm () const -> int;

    auto
    get_height_mm () const -> int;

    auto
    get_manufacturer () const -> glib::ustring;

    auto
    get_model () const -> glib::ustring;

    auto
    get_connector () const -> glib::ustring;

    auto
    get_scale_factor () const -> int;

    auto
    get_refresh_rate () const -> int;

    auto
    get_subpixel_layout () const -> SubpixelLayout;

    auto
    is_valid () const -> bool;

    auto
    get_description () const -> glib::ustring;

    auto
    signal_invalidate () -> glib::SignalProxy<void ()>;

    auto
    property_description () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

    auto
    property_manufacturer () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_model () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_connector () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_scale_factor () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_geometry () const -> glib::PropertyProxy_ReadOnly<gdk::Rectangle>;

    auto
    property_width_mm () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height_mm () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_refresh_rate () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_subpixel_layout () const
        -> glib::PropertyProxy_ReadOnly<SubpixelLayout>;

    auto
    property_valid () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkMonitor* object, bool take_copy = false) -> glib::RefPtr<gdk::Monitor>;
} // namespace glib

#endif
