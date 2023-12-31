// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EVENTCONTROLLERMOTION_H
#define _GTKMM_EVENTCONTROLLERMOTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerMotion = struct _GtkEventControllerMotion;
using GtkEventControllerMotionClass = struct _GtkEventControllerMotionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT EventControllerMotion_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT EventControllerMotion : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EventControllerMotion;
    using CppClassType = EventControllerMotion_Class;
    using BaseObjectType = GtkEventControllerMotion;
    using BaseClassType = GtkEventControllerMotionClass;

    EventControllerMotion (const EventControllerMotion&) = delete;
    auto
    operator= (const EventControllerMotion&) -> EventControllerMotion& = delete;

  private:
    friend class EventControllerMotion_Class;
    static CppClassType eventcontrollermotion_class_;

  protected:
    explicit EventControllerMotion (
        const glib::ConstructParams& construct_params);
    explicit EventControllerMotion (GtkEventControllerMotion* castitem);

#endif

  public:
    EventControllerMotion (EventControllerMotion&& src) noexcept;
    auto
    operator= (EventControllerMotion&& src) noexcept -> EventControllerMotion&;

    ~EventControllerMotion () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEventControllerMotion*
    {
      return reinterpret_cast<GtkEventControllerMotion*> (gobject_);
    }

    auto
    gobj () const -> const GtkEventControllerMotion*
    {
      return reinterpret_cast<GtkEventControllerMotion*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEventControllerMotion*;

  private:
  protected:
    EventControllerMotion ();

  public:
    static auto
    create () -> glib::RefPtr<EventControllerMotion>;

    auto
    contains_pointer () const -> bool;

    auto
    is_pointer () const -> bool;

    auto
    signal_enter () -> glib::SignalProxy<void (double, double)>;

    auto
    signal_leave () -> glib::SignalProxy<void ()>;

    auto
    signal_motion () -> glib::SignalProxy<void (double, double)>;

    auto
    property_is_pointer () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_contains_pointer () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEventControllerMotion* object, bool take_copy = false) -> glib::RefPtr<gtk::EventControllerMotion>;
} // namespace glib

#endif
