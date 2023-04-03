// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DISPLAY_H
#define _GDKMM_DISPLAY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gdk/applaunchcontext.hxx>
#include <libmm/gdk/event.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDisplay = struct _GdkDisplay;
using GdkDisplayClass = struct _GdkDisplayClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT Display_Class;
}
#endif

namespace Gio
{
  class LIBMM_GDK_SYMEXPORT ListModel;
}

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT Clipboard;
  class LIBMM_GDK_SYMEXPORT Device;
  class LIBMM_GDK_SYMEXPORT GLContext;
  class LIBMM_GDK_SYMEXPORT Seat;
  class LIBMM_GDK_SYMEXPORT Monitor;
  class LIBMM_GDK_SYMEXPORT Surface;

  class LIBMM_GDK_SYMEXPORT Display : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Display;
    using CppClassType = Display_Class;
    using BaseObjectType = GdkDisplay;
    using BaseClassType = GdkDisplayClass;

    Display (const Display&) = delete;
    auto
    operator= (const Display&) -> Display& = delete;

  private:
    friend class Display_Class;
    static CppClassType display_class_;

  protected:
    explicit Display (const Glib::ConstructParams& construct_params);
    explicit Display (GdkDisplay* castitem);

#endif

  public:
    Display (Display&& src) noexcept;
    auto
    operator= (Display&& src) noexcept -> Display&;

    ~Display () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkDisplay*
    {
      return reinterpret_cast<GdkDisplay*> (gobject_);
    }

    auto
    gobj () const -> const GdkDisplay*
    {
      return reinterpret_cast<GdkDisplay*> (gobject_);
    }

    auto
    gobj_copy () -> GdkDisplay*;

  private:
  protected:
    Display ();

  public:
    static auto
    open (const Glib::ustring& display_name) -> Glib::RefPtr<Display>;

    auto
    get_name () const -> Glib::ustring;

    auto
    device_is_grabbed (const Glib::RefPtr<const Gdk::Device>& device) const
        -> bool;

    auto
    beep () -> void;

    auto
    sync () -> void;

    auto
    close () -> void;

    auto
    is_closed () const -> bool;

    auto
    is_composited () const -> bool;

    auto
    is_rgba () const -> bool;

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    put_event (const Glib::RefPtr<const Event>& event) -> void;
#endif

    static auto
    get_default () -> Glib::RefPtr<Display>;

    auto
    flush () -> void;

    auto
    get_clipboard () -> Glib::RefPtr<Clipboard>;

    auto
    get_clipboard () const -> Glib::RefPtr<const Clipboard>;

    auto
    get_primary_clipboard () -> Glib::RefPtr<Clipboard>;

    auto
    get_primary_clipboard () const -> Glib::RefPtr<const Clipboard>;

    auto
    supports_input_shapes () const -> bool;

    auto
    prepare_gl () -> void;

    auto
    create_gl_context () -> Glib::RefPtr<GLContext>;

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    notify_startup_complete (const Glib::ustring& startup_id) -> void;
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    get_startup_notification_id () const -> Glib::ustring;
#endif

    auto
    get_app_launch_context () -> Glib::RefPtr<AppLaunchContext>;

    auto
    get_app_launch_context () const -> Glib::RefPtr<const AppLaunchContext>;

    auto
    get_default_seat () -> Glib::RefPtr<Seat>;

    auto
    get_default_seat () const -> Glib::RefPtr<const Seat>;

    auto
    list_seats () -> std::vector<Glib::RefPtr<Seat>>;

    auto
    list_seats () const -> std::vector<Glib::RefPtr<const Seat>>;

    auto
    get_monitors () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_monitors () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    get_monitor_at_surface (const Glib::RefPtr<Surface>& surface)
        -> Glib::RefPtr<Monitor>;

    auto
    get_monitor_at_surface (const Glib::RefPtr<Surface>& surface) const
        -> Glib::RefPtr<const Monitor>;

    template <class ValueType>
    auto
    get_setting (const Glib::ustring& name, ValueType& value) const -> bool;

    auto
    signal_closed () -> Glib::SignalProxy<void (bool)>;

    auto
    signal_opened () -> Glib::SignalProxy<void ()>;

    auto
    signal_seat_added () -> Glib::SignalProxy<void (const Glib::RefPtr<Seat>&)>;

    auto
    signal_seat_removed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Seat>&)>;

    auto
    signal_setting_changed () -> Glib::SignalProxy<void (const Glib::ustring&)>;

    auto
    property_composited () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_rgba () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_input_shapes () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

  template <class ValueType>
  auto
  Display::get_setting (const Glib::ustring& name, ValueType& value) const -> bool
  {
    Glib::Value<ValueType> glibmmvalue;
    glibmmvalue.init (Glib::Value<ValueType>::value_type ());

    gboolean result = gdk_display_get_setting (
        const_cast<GdkDisplay*> (gobj ()),
        name.c_str (),
        glibmmvalue.gobj ());

    value = glibmmvalue.get ();
    return result;
  }

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDisplay* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Display>;
} // namespace Glib

#endif
