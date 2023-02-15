// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_SURFACE_H
#define _GDKMM_SURFACE_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm-cairo/context.hxx>
#include <libmm-cairo/region.hxx>
#include <libmm-gdk/device.hxx>
#include <libmm-gdk/drag.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/event.hxx>
#include <libmm-gdk/popuplayout.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT Surface_Class;
}
#endif

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT ContentProvider;
  class LIBMM_GDK_SYMEXPORT Cursor;
  class LIBMM_GDK_SYMEXPORT CairoContext;
  class LIBMM_GDK_SYMEXPORT GLContext;
  class LIBMM_GDK_SYMEXPORT FrameClock;
  class LIBMM_GDK_SYMEXPORT Monitor;

  class LIBMM_GDK_SYMEXPORT Surface : public Glib::Object
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
    explicit Surface (const Glib::ConstructParams& construct_params);
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
    create_toplevel (const Glib::RefPtr<Display>& display)
        -> Glib::RefPtr<Surface>;

    static auto
    create_popup (const Glib::RefPtr<Surface>& parent, bool autohide)
        -> Glib::RefPtr<Surface>;

    auto
    get_display () -> Glib::RefPtr<Display>;

    auto
    get_display () const -> Glib::RefPtr<const Display>;

    auto
    hide () -> void;

    auto
    set_input_region (const ::Cairo::RefPtr<::Cairo::Region>& region) -> void;

    auto
    get_mapped () const -> bool;

    auto
    set_cursor (const Glib::RefPtr<Cursor>& cursor) -> void;

    auto
    set_cursor () -> void;

    auto
    set_device_cursor (const Glib::RefPtr<Device>& device,
                       const Glib::RefPtr<Cursor>& cursor) -> void;

    auto
    get_device_cursor (const Glib::RefPtr<Device>& device)
        -> Glib::RefPtr<Cursor>;

    auto
    get_device_cursor (const Glib::RefPtr<const Device>& device) const
        -> Glib::RefPtr<const Cursor>;

    auto
    get_cursor () -> Glib::RefPtr<Cursor>;

    auto
    get_cursor () const -> Glib::RefPtr<const Cursor>;

    auto
    get_width () const -> int;

    auto
    get_height () const -> int;

    auto
    get_scale_factor () const -> int;

    auto
    get_device_position (const Glib::RefPtr<const Device>& device,
                         double& x,
                         double& y,
                         ModifierType& mask) const -> bool;

    auto
    create_similar_surface (::Cairo::Content content, int width, int height)
        -> ::Cairo::RefPtr<::Cairo::Surface>;

    auto
    beep () -> void;

    auto
    drag_begin_from_point (const Glib::RefPtr<Device>& device,
                           const Glib::RefPtr<ContentProvider>& content,
                           DragAction actions,
                           double dx,
                           double dy) -> Glib::RefPtr<Drag>;

    auto
    queue_render () -> void;

    auto
    request_layout () -> void;

    auto
    get_frame_clock () -> Glib::RefPtr<FrameClock>;

    auto
    get_frame_clock () const -> Glib::RefPtr<const FrameClock>;

    auto
    set_opaque_region (const ::Cairo::RefPtr<const ::Cairo::Region>& region)
        -> void;

    auto
    create_gl_context () -> Glib::RefPtr<Gdk::GLContext>;

    auto
    create_cairo_context () -> Glib::RefPtr<Gdk::CairoContext>;

    auto
    signal_layout () -> Glib::SignalProxy<void (int, int)>;

    auto
    signal_render () -> Glib::SignalProxy<
        bool (const ::Cairo::RefPtr<const ::Cairo::Region>&)>;

    auto
    signal_event ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<const Event>&)>;

    auto
    signal_enter_monitor ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Monitor>&)>;

    auto
    signal_leave_monitor ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Monitor>&)>;

    auto
    property_cursor () -> Glib::PropertyProxy<Glib::RefPtr<Cursor>>;

    auto
    property_cursor () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Cursor>>;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>;

    auto
    property_frame_clock () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FrameClock>>;

    auto
    property_mapped () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_scale_factor () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkSurface* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Surface>;
} // namespace Glib

#endif
