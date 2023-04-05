// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/display.hxx>
#include <libmm/gdk/display_p.hxx>

#include <gdk/gdk.h>

#include <vector>

#include <gdk/gdk.h>
#include <libmm/gdk/applaunchcontext.hxx>
#include <libmm/gdk/clipboard.hxx>
#include <libmm/gdk/glcontext.hxx>
#include <libmm/gdk/monitor.hxx>
#include <libmm/gdk/seat.hxx>
#include <libmm/gdk/surface.hxx>
#include <libmm/gio/listmodel.hxx>

namespace gdk
{
}

namespace
{

  static auto
  Display_signal_closed_callback (GdkDisplay* self, gboolean p0, void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (bool)>;

    auto obj = dynamic_cast<Display*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Display_signal_closed_info = {
      "closed",
      (GCallback) &Display_signal_closed_callback,
      (GCallback) &Display_signal_closed_callback};

  static const glib::SignalProxyInfo Display_signal_opened_info = {
      "opened",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  Display_signal_seat_added_callback (GdkDisplay* self, GdkSeat* p0, void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<Seat>&)>;

    auto obj = dynamic_cast<Display*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Display_signal_seat_added_info = {
      "seat-added",
      (GCallback) &Display_signal_seat_added_callback,
      (GCallback) &Display_signal_seat_added_callback};

  static auto
  Display_signal_seat_removed_callback (GdkDisplay* self,
                                        GdkSeat* p0,
                                        void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<Seat>&)>;

    auto obj = dynamic_cast<Display*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Display_signal_seat_removed_info = {
      "seat-removed",
      (GCallback) &Display_signal_seat_removed_callback,
      (GCallback) &Display_signal_seat_removed_callback};

  static auto
  Display_signal_setting_changed_callback (GdkDisplay* self,
                                           const gchar* p0,
                                           void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<Display*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Display_signal_setting_changed_info = {
      "setting-changed",
      (GCallback) &Display_signal_setting_changed_callback,
      (GCallback) &Display_signal_setting_changed_callback};

} // namespace

namespace glib
{

  auto
  wrap (GdkDisplay* object, bool take_copy) -> glib::RefPtr<gdk::Display>
  {
    return glib::make_refptr_for_instance<gdk::Display> (
        dynamic_cast<gdk::Display*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Display_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Display_Class::class_init_function;

      register_derived_type (gdk_display_get_type ());
    }

    return *this;
  }

  auto
  Display_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Display_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Display ((GdkDisplay*) object);
  }

  auto
  Display::gobj_copy () -> GdkDisplay*
  {
    reference ();
    return gobj ();
  }

  Display::Display (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Display::Display (GdkDisplay* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Display::Display (Display&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Display::operator= (Display&& src) noexcept -> Display&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Display::~Display () noexcept {}

  Display::CppClassType Display::display_class_;

  auto
  Display::get_type () -> GType
  {
    return display_class_.init ().get_type ();
  }

  auto
  Display::get_base_type () -> GType
  {
    return gdk_display_get_type ();
  }

  Display::Display ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (display_class_.init ()))
  {
  }

  auto
  Display::open (const glib::ustring& display_name) -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_display_open (display_name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Display::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_display_get_name (const_cast<GdkDisplay*> (gobj ())));
  }

  auto
  Display::device_is_grabbed (
      const glib::RefPtr<const gdk::Device>& device) const -> bool
  {
    return gdk_display_device_is_grabbed (
        const_cast<GdkDisplay*> (gobj ()),
        const_cast<GdkDevice*> (glib::unwrap<gdk::Device> (device)));
  }

  auto
  Display::beep () -> void
  {
    gdk_display_beep (gobj ());
  }

  auto
  Display::sync () -> void
  {
    gdk_display_sync (gobj ());
  }

  auto
  Display::close () -> void
  {
    gdk_display_close (gobj ());
  }

  auto
  Display::is_closed () const -> bool
  {
    return gdk_display_is_closed (const_cast<GdkDisplay*> (gobj ()));
  }

  auto
  Display::is_composited () const -> bool
  {
    return gdk_display_is_composited (const_cast<GdkDisplay*> (gobj ()));
  }

  auto
  Display::is_rgba () const -> bool
  {
    return gdk_display_is_rgba (const_cast<GdkDisplay*> (gobj ()));
  }

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Display::put_event (const glib::RefPtr<const Event>& event) -> void
  {
    gdk_display_put_event (gobj (),
                           const_cast<GdkEvent*> (glib::unwrap (event)));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  Display::get_default () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_display_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Display::flush () -> void
  {
    gdk_display_flush (gobj ());
  }

  auto
  Display::get_clipboard () -> glib::RefPtr<Clipboard>
  {
    auto retvalue = glib::wrap (gdk_display_get_clipboard (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Display::get_clipboard () const -> glib::RefPtr<const Clipboard>
  {
    return const_cast<Display*> (this)->get_clipboard ();
  }

  auto
  Display::get_primary_clipboard () -> glib::RefPtr<Clipboard>
  {
    auto retvalue = glib::wrap (gdk_display_get_primary_clipboard (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Display::get_primary_clipboard () const -> glib::RefPtr<const Clipboard>
  {
    return const_cast<Display*> (this)->get_primary_clipboard ();
  }

  auto
  Display::supports_input_shapes () const -> bool
  {
    return gdk_display_supports_input_shapes (
        const_cast<GdkDisplay*> (gobj ()));
  }

  auto
  Display::prepare_gl () -> void
  {
    GError* gerror = nullptr;
    gdk_display_prepare_gl (gobj (), &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
  }

  auto
  Display::create_gl_context () -> glib::RefPtr<GLContext>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (gdk_display_create_gl_context (gobj (), &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Display::notify_startup_complete (const glib::ustring& startup_id) -> void
  {
    gdk_display_notify_startup_complete (gobj (), startup_id.c_str ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Display::get_startup_notification_id () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_display_get_startup_notification_id (
            const_cast<GdkDisplay*> (gobj ())));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  Display::get_app_launch_context () -> glib::RefPtr<AppLaunchContext>
  {
    auto retvalue = glib::wrap (gdk_display_get_app_launch_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Display::get_app_launch_context () const -> glib::RefPtr<const AppLaunchContext>
  {
    return const_cast<Display*> (this)->get_app_launch_context ();
  }

  auto
  Display::get_default_seat () -> glib::RefPtr<Seat>
  {
    auto retvalue = glib::wrap (gdk_display_get_default_seat (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Display::get_default_seat () const -> glib::RefPtr<const Seat>
  {
    return const_cast<Display*> (this)->get_default_seat ();
  }

  auto
  Display::list_seats () -> std::vector<glib::RefPtr<Seat>>
  {
    return glib::ListHandler<glib::RefPtr<Seat>>::list_to_vector (
        gdk_display_list_seats (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Display::list_seats () const -> std::vector<glib::RefPtr<const Seat>>
  {
    return glib::ListHandler<glib::RefPtr<const Seat>>::list_to_vector (
        gdk_display_list_seats (const_cast<GdkDisplay*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Display::get_monitors () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gdk_display_get_monitors (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Display::get_monitors () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<Display*> (this)->get_monitors ();
  }

  auto
  Display::get_monitor_at_surface (const glib::RefPtr<Surface>& surface) -> glib::RefPtr<Monitor>
  {
    auto retvalue = glib::wrap (
        gdk_display_get_monitor_at_surface (gobj (), glib::unwrap (surface)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Display::get_monitor_at_surface (const glib::RefPtr<Surface>& surface) const -> glib::RefPtr<const Monitor>
  {
    return const_cast<Display*> (this)->get_monitor_at_surface (surface);
  }

  auto
  Display::signal_closed () -> glib::SignalProxy<void (bool)>
  {
    return glib::SignalProxy<void (bool)> (this, &Display_signal_closed_info);
  }

  auto
  Display::signal_opened () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Display_signal_opened_info);
  }

  auto
  Display::signal_seat_added () -> glib::SignalProxy<void (const glib::RefPtr<Seat>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<Seat>&)> (
        this,
        &Display_signal_seat_added_info);
  }

  auto
  Display::signal_seat_removed () -> glib::SignalProxy<void (const glib::RefPtr<Seat>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<Seat>&)> (
        this,
        &Display_signal_seat_removed_info);
  }

  auto
  Display::signal_setting_changed () -> glib::SignalProxy<void (const glib::ustring&)>
  {
    return glib::SignalProxy<void (const glib::ustring&)> (
        this,
        &Display_signal_setting_changed_info);
  }

  auto
  Display::property_composited () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "composited");
  }

  auto
  Display::property_rgba () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "rgba");
  }

  auto
  Display::property_input_shapes () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "input-shapes");
  }

} // namespace gdk
