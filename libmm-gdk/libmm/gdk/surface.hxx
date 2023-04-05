// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_SURFACE_H
#define _GDKMM_SURFACE_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm/cairo/context.hxx>
#include <libmm/cairo/region.hxx>
#include <libmm/gdk/device.hxx>
#include <libmm/gdk/drag.hxx>
#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/event.hxx>
#include <libmm/gdk/popuplayout.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Surface_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT ContentProvider;
  class LIBMM_GDK_SYMEXPORT Cursor;
  class LIBMM_GDK_SYMEXPORT CairoContext;
  class LIBMM_GDK_SYMEXPORT GLContext;
  class LIBMM_GDK_SYMEXPORT FrameClock;
  class LIBMM_GDK_SYMEXPORT Monitor;

  class LIBMM_GDK_SYMEXPORT Surface : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Surface;
    using CppClassType = Surface_Class;
    using BaseObjectType = GdkSurface;
    using BaseClassType = GdkSurfaceClass;

    Surface (const Surface&) = delete;
    auto
    operator= (const Surface&) -> Surface& = delete;

  private:
    friend class Surface_Class;
    static CppClassType surface_class_;

  protected:
    explicit Surface (const glib::ConstructParams& construct_params);
    explicit Surface (GdkSurface* castitem);

#endif

  public:
    Surface (Surface&& src) noexcept;
    auto
    operator= (Surface&& src) noexcept -> Surface&;

    ~Surface () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkSurface*
    {
      return reinterpret_cast<GdkSurface*> (gobject_);
    }

    auto
    gobj () const -> const GdkSurface*
    {
      return reinterpret_cast<GdkSurface*> (gobject_);
    }

    auto
    gobj_copy () -> GdkSurface*;

  private:
  public:
    static auto
    create_toplevel (const glib::RefPtr<Display>& display)
        -> glib::RefPtr<Surface>;

    static auto
    create_popup (const glib::RefPtr<Surface>& parent, bool autohide)
        -> glib::RefPtr<Surface>;

    auto
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    hide () -> void;

    auto
    set_input_region (const ::cairo::RefPtr<::cairo::Region>& region) -> void;

    auto
    get_mapped () const -> bool;

    auto
    set_cursor (const glib::RefPtr<Cursor>& cursor) -> void;

    auto
    set_cursor () -> void;

    auto
    set_device_cursor (const glib::RefPtr<Device>& device,
                       const glib::RefPtr<Cursor>& cursor) -> void;

    auto
    get_device_cursor (const glib::RefPtr<Device>& device)
        -> glib::RefPtr<Cursor>;

    auto
    get_device_cursor (const glib::RefPtr<const Device>& device) const
        -> glib::RefPtr<const Cursor>;

    auto
    get_cursor () -> glib::RefPtr<Cursor>;

    auto
    get_cursor () const -> glib::RefPtr<const Cursor>;

    auto
    get_width () const -> int;

    auto
    get_height () const -> int;

    auto
    get_scale_factor () const -> int;

    auto
    get_device_position (const glib::RefPtr<const Device>& device,
                         double& x,
                         double& y,
                         ModifierType& mask) const -> bool;

    auto
    create_similar_surface (::cairo::Content content, int width, int height)
        -> ::cairo::RefPtr<::cairo::Surface>;

    auto
    beep () -> void;

    auto
    drag_begin_from_point (const glib::RefPtr<Device>& device,
                           const glib::RefPtr<ContentProvider>& content,
                           DragAction actions,
                           double dx,
                           double dy) -> glib::RefPtr<Drag>;

    auto
    queue_render () -> void;

    auto
    request_layout () -> void;

    auto
    get_frame_clock () -> glib::RefPtr<FrameClock>;

    auto
    get_frame_clock () const -> glib::RefPtr<const FrameClock>;

    auto
    set_opaque_region (const ::cairo::RefPtr<const ::cairo::Region>& region)
        -> void;

    auto
    create_gl_context () -> glib::RefPtr<gdk::GLContext>;

    auto
    create_cairo_context () -> glib::RefPtr<gdk::CairoContext>;

    auto
    signal_layout () -> glib::SignalProxy<void (int, int)>;

    auto
    signal_render () -> glib::SignalProxy<
        bool (const ::cairo::RefPtr<const ::cairo::Region>&)>;

    auto
    signal_event ()
        -> glib::SignalProxy<bool (const glib::RefPtr<const Event>&)>;

    auto
    signal_enter_monitor ()
        -> glib::SignalProxy<void (const glib::RefPtr<Monitor>&)>;

    auto
    signal_leave_monitor ()
        -> glib::SignalProxy<void (const glib::RefPtr<Monitor>&)>;

    auto
    property_cursor () -> glib::PropertyProxy<glib::RefPtr<Cursor>>;

    auto
    property_cursor () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Cursor>>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

    auto
    property_frame_clock () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FrameClock>>;

    auto
    property_mapped () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_scale_factor () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkSurface* object, bool take_copy = false) -> glib::RefPtr<gdk::Surface>;
} // namespace glib

#endif
