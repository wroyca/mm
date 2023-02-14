// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DRAG_H
#define _GDKMM_DRAG_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm-gdk/enums.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDrag = struct _GdkDrag;
using GdkDragClass = struct _GdkDragClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API Drag_Class;
}
#endif

namespace Gdk
{
  class GDKMM_API ContentFormats;
  class GDKMM_API ContentProvider;
  class GDKMM_API Device;
  class GDKMM_API Display;
  class GDKMM_API Surface;

  enum class DragCancelReason
  {
    NO_TARGET,
    USER_CANCELLED,
    ERROR
  };

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::DragCancelReason>
    : public Glib::Value_Enum<Gdk::DragCancelReason>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
{

  class GDKMM_API Drag : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Drag;
    using CppClassType = Drag_Class;
    using BaseObjectType = GdkDrag;
    using BaseClassType = GdkDragClass;

    Drag (const Drag&) = delete;
    auto
    operator= (const Drag&) -> Drag& = delete;

  private:
    friend class Drag_Class;
    static CppClassType drag_class_;

  protected:
    explicit Drag (const Glib::ConstructParams& construct_params);
    explicit Drag (GdkDrag* castitem);

#endif

  public:
    Drag (Drag&& src) noexcept;
    auto
    operator= (Drag&& src) noexcept -> Drag&;

    ~Drag () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkDrag*
    {
      return reinterpret_cast<GdkDrag*> (gobject_);
    }

    auto
    gobj () const -> const GdkDrag*
    {
      return reinterpret_cast<GdkDrag*> (gobject_);
    }

    auto
    gobj_copy () -> GdkDrag*;

  private:
  public:
    auto
    get_display () -> Glib::RefPtr<Display>;

    auto
    get_display () const -> Glib::RefPtr<const Display>;

    auto
    get_device () -> Glib::RefPtr<Device>;

    auto
    get_device () const -> Glib::RefPtr<const Device>;

    auto
    get_formats () -> Glib::RefPtr<ContentFormats>;

    auto
    get_formats () const -> Glib::RefPtr<const ContentFormats>;

    auto
    get_actions () const -> DragAction;

    auto
    get_selected_action () const -> DragAction;

    static auto
    action_is_unique (DragAction action) -> bool;

    void
    drag_drop_done (bool success);

    auto
    get_drag_surface () -> Glib::RefPtr<Surface>;

    auto
    get_drag_surface () const -> Glib::RefPtr<const Surface>;

    void
    set_hotspot (int hot_x, int hot_y);

    auto
    get_content () -> Glib::RefPtr<ContentProvider>;

    auto
    get_content () const -> Glib::RefPtr<const ContentProvider>;

    auto
    get_surface () -> Glib::RefPtr<Surface>;

    auto
    get_surface () const -> Glib::RefPtr<const Surface>;

    auto
    property_content () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentProvider>>;

    auto
    property_device () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Device>>;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>;

    auto
    property_formats () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>;

    auto
    property_selected_action () -> Glib::PropertyProxy<DragAction>;

    auto
    property_selected_action () const
        -> Glib::PropertyProxy_ReadOnly<DragAction>;

    auto
    property_actions () -> Glib::PropertyProxy<DragAction>;

    auto
    property_actions () const -> Glib::PropertyProxy_ReadOnly<DragAction>;

    auto
    property_surface () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>>;

    auto
    signal_cancel () -> Glib::SignalProxy<void (DragCancelReason)>;

    auto
    signal_drop_performed () -> Glib::SignalProxy<void ()>;

    auto
    signal_dnd_finished () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkDrag* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Drag>;
} // namespace Glib

#endif
