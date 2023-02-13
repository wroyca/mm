

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <libmm-glib/mm-glib.hpp>
#include <libmm-gdk/wrap_init.hpp>
#include <libmm-glib/error.hpp>
#include <libmm-glib/object.hpp>

// #include the widget headers so that we can call the get_type() static methods:
#include <libmm-gdk/applaunchcontext.hpp>
#include <libmm-gdk/cairocontext.hpp>
#include <libmm-gdk/clipboard.hpp>
#include <libmm-gdk/contentformats.hpp>
#include <libmm-gdk/contentformatsbuilder.hpp>
#include <libmm-gdk/contentprovider.hpp>
#include <libmm-gdk/cursor.hpp>
#include <libmm-gdk/device.hpp>
#include <libmm-gdk/devicepad.hpp>
#include <libmm-gdk/devicetool.hpp>
#include <libmm-gdk/display.hpp>
#include <libmm-gdk/displaymanager.hpp>
#include <libmm-gdk/drag.hpp>
#include <libmm-gdk/dragsurface.hpp>
#include <libmm-gdk/drawcontext.hpp>
#include <libmm-gdk/drop.hpp>
#include <libmm-gdk/enums.hpp>
#include <libmm-gdk/event.hpp>
#include <libmm-gdk/frameclock.hpp>
#include <libmm-gdk/frametimings.hpp>
#include <libmm-gdk/glcontext.hpp>
#include <libmm-gdk/gltexture.hpp>
#include <libmm-gdk/memorytexture.hpp>
#include <libmm-gdk/monitor.hpp>
#include <libmm-gdk/paintable.hpp>
#include <libmm-gdk/pixbuf.hpp>
#include <libmm-gdk/pixbufanimation.hpp>
#include <libmm-gdk/pixbufanimationiter.hpp>
#include <libmm-gdk/pixbufformat.hpp>
#include <libmm-gdk/pixbufloader.hpp>
#include <libmm-gdk/popup.hpp>
#include <libmm-gdk/popuplayout.hpp>
#include <libmm-gdk/rectangle.hpp>
#include <libmm-gdk/rgba.hpp>
#include <libmm-gdk/seat.hpp>
#include <libmm-gdk/snapshot.hpp>
#include <libmm-gdk/surface.hpp>
#include <libmm-gdk/texture.hpp>
#include <libmm-gdk/timecoord.hpp>
#include <libmm-gdk/toplevel.hpp>
#include <libmm-gdk/toplevellayout.hpp>
#include <libmm-gdk/toplevelsize.hpp>

extern "C"
{
//Declarations of the *_get_type() functions:

auto gdk_app_launch_context_get_type(void) -> GType;
auto gdk_cairo_context_get_type(void) -> GType;
auto gdk_clipboard_get_type(void) -> GType;
auto gdk_content_provider_get_type(void) -> GType;
auto gdk_cursor_get_type(void) -> GType;
auto gdk_device_get_type(void) -> GType;
auto gdk_device_tool_get_type(void) -> GType;
auto gdk_display_get_type(void) -> GType;
auto gdk_display_manager_get_type(void) -> GType;
auto gdk_drag_get_type(void) -> GType;
auto gdk_draw_context_get_type(void) -> GType;
auto gdk_drop_get_type(void) -> GType;
auto gdk_frame_clock_get_type(void) -> GType;
auto gdk_gl_context_get_type(void) -> GType;
auto gdk_gl_texture_get_type(void) -> GType;
auto gdk_memory_texture_get_type(void) -> GType;
auto gdk_monitor_get_type(void) -> GType;
auto gdk_pixbuf_get_type(void) -> GType;
auto gdk_pixbuf_animation_get_type(void) -> GType;
auto gdk_pixbuf_animation_iter_get_type(void) -> GType;
auto gdk_pixbuf_loader_get_type(void) -> GType;
auto gdk_seat_get_type(void) -> GType;
auto gdk_snapshot_get_type(void) -> GType;
auto gdk_surface_get_type(void) -> GType;
auto gdk_texture_get_type(void) -> GType;

//Declarations of the *_error_quark() functions:

auto gdk_gl_error_quark(void) -> GQuark;
auto gdk_pixbuf_error_quark(void) -> GQuark;
auto gdk_texture_error_quark(void) -> GQuark;
} // extern "C"

namespace Gdk {

//Declarations of the *_Class::wrap_new() methods, instead of including all the private headers:

class AppLaunchContext_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CairoContext_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Clipboard_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ContentProvider_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Cursor_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Device_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DeviceTool_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Display_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DisplayManager_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Drag_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DrawContext_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Drop_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FrameClock_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GLContext_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GLTexture_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MemoryTexture_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Monitor_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Pixbuf_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PixbufAnimation_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PixbufAnimationIter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PixbufLoader_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Seat_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Snapshot_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Surface_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Texture_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };

auto wrap_init () -> void
{
  // Register Error domains in the main namespace:
  Glib::Error::register_domain(gdk_gl_error_quark(), &GLError::throw_func);
  Glib::Error::register_domain(gdk_pixbuf_error_quark(), &PixbufError::throw_func);
  Glib::Error::register_domain(gdk_texture_error_quark(), &TextureError::throw_func);

  // Map gtypes to gtkmm wrapper-creation functions:
  wrap_register(gdk_app_launch_context_get_type(), &AppLaunchContext_Class::wrap_new);
  wrap_register(gdk_cairo_context_get_type(), &CairoContext_Class::wrap_new);
  wrap_register(gdk_clipboard_get_type(), &Clipboard_Class::wrap_new);
  wrap_register(gdk_content_provider_get_type(), &ContentProvider_Class::wrap_new);
  wrap_register(gdk_cursor_get_type(), &Cursor_Class::wrap_new);
  wrap_register(gdk_device_get_type(), &Device_Class::wrap_new);
  wrap_register(gdk_device_tool_get_type(), &DeviceTool_Class::wrap_new);
  wrap_register(gdk_display_get_type(), &Display_Class::wrap_new);
  wrap_register(gdk_display_manager_get_type(), &DisplayManager_Class::wrap_new);
  wrap_register(gdk_drag_get_type(), &Drag_Class::wrap_new);
  wrap_register(gdk_draw_context_get_type(), &DrawContext_Class::wrap_new);
  wrap_register(gdk_drop_get_type(), &Drop_Class::wrap_new);
  wrap_register(gdk_frame_clock_get_type(), &FrameClock_Class::wrap_new);
  wrap_register(gdk_gl_context_get_type(), &GLContext_Class::wrap_new);
  wrap_register(gdk_gl_texture_get_type(), &GLTexture_Class::wrap_new);
  wrap_register(gdk_memory_texture_get_type(), &MemoryTexture_Class::wrap_new);
  wrap_register(gdk_monitor_get_type(), &Monitor_Class::wrap_new);
  wrap_register(gdk_pixbuf_get_type(), &Pixbuf_Class::wrap_new);
  wrap_register(gdk_pixbuf_animation_get_type(), &PixbufAnimation_Class::wrap_new);
  wrap_register(gdk_pixbuf_animation_iter_get_type(), &PixbufAnimationIter_Class::wrap_new);
  wrap_register(gdk_pixbuf_loader_get_type(), &PixbufLoader_Class::wrap_new);
  wrap_register(gdk_seat_get_type(), &Seat_Class::wrap_new);
  wrap_register(gdk_snapshot_get_type(), &Snapshot_Class::wrap_new);
  wrap_register(gdk_surface_get_type(), &Surface_Class::wrap_new);
  wrap_register(gdk_texture_get_type(), &Texture_Class::wrap_new);

  // Register the gtkmm gtypes:
  g_type_ensure(AppLaunchContext::get_type());
  g_type_ensure(CairoContext::get_type());
  g_type_ensure(Clipboard::get_type());
  g_type_ensure(ContentProvider::get_type());
  g_type_ensure(Cursor::get_type());
  g_type_ensure(Device::get_type());
  g_type_ensure(DeviceTool::get_type());
  g_type_ensure(Display::get_type());
  g_type_ensure(DisplayManager::get_type());
  g_type_ensure(Drag::get_type());
  g_type_ensure(DrawContext::get_type());
  g_type_ensure(Drop::get_type());
  g_type_ensure(FrameClock::get_type());
  g_type_ensure(GLContext::get_type());
  g_type_ensure(GLTexture::get_type());
  g_type_ensure(MemoryTexture::get_type());
  g_type_ensure(Monitor::get_type());
  g_type_ensure(Pixbuf::get_type());
  g_type_ensure(PixbufAnimation::get_type());
  g_type_ensure(PixbufAnimationIter::get_type());
  g_type_ensure(PixbufLoader::get_type());
  g_type_ensure(Seat::get_type());
  g_type_ensure(Snapshot::get_type());
  g_type_ensure(Surface::get_type());
  g_type_ensure(Texture::get_type());

} // wrap_init()

} // Gdk

