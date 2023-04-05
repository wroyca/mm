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
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Display_Class;
}
#endif

namespace gio
{
  class LIBMM_GDK_SYMEXPORT ListModel;
}

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Clipboard;
  class LIBMM_GDK_SYMEXPORT Device;
  class LIBMM_GDK_SYMEXPORT GLContext;
  class LIBMM_GDK_SYMEXPORT Seat;
  class LIBMM_GDK_SYMEXPORT Monitor;
  class LIBMM_GDK_SYMEXPORT Surface;

  class LIBMM_GDK_SYMEXPORT Display : public glib::Object
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
    explicit Display (const glib::ConstructParams& construct_params);
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
    open (const glib::ustring& display_name) -> glib::RefPtr<Display>;

    auto
    get_name () const -> glib::ustring;

    auto
    device_is_grabbed (const glib::RefPtr<const gdk::Device>& device) const
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
    put_event (const glib::RefPtr<const Event>& event) -> void;
#endif

    static auto
    get_default () -> glib::RefPtr<Display>;

    auto
    flush () -> void;

    auto
    get_clipboard () -> glib::RefPtr<Clipboard>;

    auto
    get_clipboard () const -> glib::RefPtr<const Clipboard>;

    auto
    get_primary_clipboard () -> glib::RefPtr<Clipboard>;

    auto
    get_primary_clipboard () const -> glib::RefPtr<const Clipboard>;

    auto
    supports_input_shapes () const -> bool;

    auto
    prepare_gl () -> void;

    auto
    create_gl_context () -> glib::RefPtr<GLContext>;

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    notify_startup_complete (const glib::ustring& startup_id) -> void;
#endif

#ifndef GDKMM_DISABLE_DEPRECATED

    auto
    get_startup_notification_id () const -> glib::ustring;
#endif

    auto
    get_app_launch_context () -> glib::RefPtr<AppLaunchContext>;

    auto
    get_app_launch_context () const -> glib::RefPtr<const AppLaunchContext>;

    auto
    get_default_seat () -> glib::RefPtr<Seat>;

    auto
    get_default_seat () const -> glib::RefPtr<const Seat>;

    auto
    list_seats () -> std::vector<glib::RefPtr<Seat>>;

    auto
    list_seats () const -> std::vector<glib::RefPtr<const Seat>>;

    auto
    get_monitors () -> glib::RefPtr<gio::ListModel>;

    auto
    get_monitors () const -> glib::RefPtr<const gio::ListModel>;

    auto
    get_monitor_at_surface (const glib::RefPtr<Surface>& surface)
        -> glib::RefPtr<Monitor>;

    auto
    get_monitor_at_surface (const glib::RefPtr<Surface>& surface) const
        -> glib::RefPtr<const Monitor>;

    template <class ValueType>
    auto
    get_setting (const glib::ustring& name, ValueType& value) const -> bool;

    auto
    signal_closed () -> glib::SignalProxy<void (bool)>;

    auto
    signal_opened () -> glib::SignalProxy<void ()>;

    auto
    signal_seat_added () -> glib::SignalProxy<void (const glib::RefPtr<Seat>&)>;

    auto
    signal_seat_removed ()
        -> glib::SignalProxy<void (const glib::RefPtr<Seat>&)>;

    auto
    signal_setting_changed () -> glib::SignalProxy<void (const glib::ustring&)>;

    auto
    property_composited () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_rgba () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_input_shapes () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

  template <class ValueType>
  auto
  Display::get_setting (const glib::ustring& name, ValueType& value) const -> bool
  {
    glib::Value<ValueType> glibmmvalue;
    glibmmvalue.init (glib::Value<ValueType>::value_type ());

    gboolean result = gdk_display_get_setting (
        const_cast<GdkDisplay*> (gobj ()),
        name.c_str (),
        glibmmvalue.gobj ());

    value = glibmmvalue.get ();
    return result;
  }

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDisplay* object, bool take_copy = false) -> glib::RefPtr<gdk::Display>;
} // namespace glib

#endif
