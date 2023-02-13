

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <mm/glib/mm-glib.hpp>
#include <mm/gdk/wrap_init.hpp>
#include <mm/glib/error.hpp>
#include <mm/glib/object.hpp>

// #include the widget headers so that we can call the get_type() static methods:
#include <mm/gdk/applaunchcontext.hpp>
#include <mm/gdk/cairocontext.hpp>
#include <mm/gdk/clipboard.hpp>
#include <mm/gdk/contentformats.hpp>
#include <mm/gdk/contentformatsbuilder.hpp>
#include <mm/gdk/contentprovider.hpp>
#include <mm/gdk/cursor.hpp>
#include <mm/gdk/device.hpp>
#include <mm/gdk/devicepad.hpp>
#include <mm/gdk/devicetool.hpp>
#include <mm/gdk/display.hpp>
#include <mm/gdk/displaymanager.hpp>
#include <mm/gdk/drag.hpp>
#include <mm/gdk/dragsurface.hpp>
#include <mm/gdk/drawcontext.hpp>
#include <mm/gdk/drop.hpp>
#include <mm/gdk/enums.hpp>
#include <mm/gdk/event.hpp>
#include <mm/gdk/frameclock.hpp>
#include <mm/gdk/frametimings.hpp>
#include <mm/gdk/glcontext.hpp>
#include <mm/gdk/gltexture.hpp>
#include <mm/gdk/memorytexture.hpp>
#include <mm/gdk/monitor.hpp>
#include <mm/gdk/paintable.hpp>
#include <mm/gdk/pixbuf.hpp>
#include <mm/gdk/pixbufanimation.hpp>
#include <mm/gdk/pixbufanimationiter.hpp>
#include <mm/gdk/pixbufformat.hpp>
#include <mm/gdk/pixbufloader.hpp>
#include <mm/gdk/popup.hpp>
#include <mm/gdk/popuplayout.hpp>
#include <mm/gdk/rectangle.hpp>
#include <mm/gdk/rgba.hpp>
#include <mm/gdk/seat.hpp>
#include <mm/gdk/snapshot.hpp>
#include <mm/gdk/surface.hpp>
#include <mm/gdk/texture.hpp>
#include <mm/gdk/timecoord.hpp>
#include <mm/gdk/toplevel.hpp>
#include <mm/gdk/toplevellayout.hpp>
#include <mm/gdk/toplevelsize.hpp>

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

