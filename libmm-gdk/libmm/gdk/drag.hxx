// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DRAG_H
#define _GDKMM_DRAG_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm/gdk/enums.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDrag = struct _GdkDrag;
using GdkDragClass = struct _GdkDragClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Drag_Class;
}
#endif

namespace gdk
{
  class LIBMM_GDK_SYMEXPORT ContentFormats;
  class LIBMM_GDK_SYMEXPORT ContentProvider;
  class LIBMM_GDK_SYMEXPORT Device;
  class LIBMM_GDK_SYMEXPORT Display;
  class LIBMM_GDK_SYMEXPORT Surface;

  enum class DragCancelReason
  {
    NO_TARGET,
    USER_CANCELLED,
    ERROR
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::DragCancelReason>
    : public glib::Value_Enum<gdk::DragCancelReason>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Drag : public glib::Object
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
    explicit Drag (const glib::ConstructParams& construct_params);
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
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    get_device () -> glib::RefPtr<Device>;

    auto
    get_device () const -> glib::RefPtr<const Device>;

    auto
    get_formats () -> glib::RefPtr<ContentFormats>;

    auto
    get_formats () const -> glib::RefPtr<const ContentFormats>;

    auto
    get_actions () const -> DragAction;

    auto
    get_selected_action () const -> DragAction;

    static auto
    action_is_unique (DragAction action) -> bool;

    auto
    drag_drop_done (bool success) -> void;

    auto
    get_drag_surface () -> glib::RefPtr<Surface>;

    auto
    get_drag_surface () const -> glib::RefPtr<const Surface>;

    auto
    set_hotspot (int hot_x, int hot_y) -> void;

    auto
    get_content () -> glib::RefPtr<ContentProvider>;

    auto
    get_content () const -> glib::RefPtr<const ContentProvider>;

    auto
    get_surface () -> glib::RefPtr<Surface>;

    auto
    get_surface () const -> glib::RefPtr<const Surface>;

    auto
    property_content () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentProvider>>;

    auto
    property_device () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Device>>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

    auto
    property_formats () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>;

    auto
    property_selected_action () -> glib::PropertyProxy<DragAction>;

    auto
    property_selected_action () const
        -> glib::PropertyProxy_ReadOnly<DragAction>;

    auto
    property_actions () -> glib::PropertyProxy<DragAction>;

    auto
    property_actions () const -> glib::PropertyProxy_ReadOnly<DragAction>;

    auto
    property_surface () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>;

    auto
    signal_cancel () -> glib::SignalProxy<void (DragCancelReason)>;

    auto
    signal_drop_performed () -> glib::SignalProxy<void ()>;

    auto
    signal_dnd_finished () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDrag* object, bool take_copy = false) -> glib::RefPtr<gdk::Drag>;
} // namespace glib

#endif
