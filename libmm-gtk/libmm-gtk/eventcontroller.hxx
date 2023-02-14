// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EVENTCONTROLLER_H
#define _GTKMM_EVENTCONTROLLER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/device.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/event.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventController = struct _GtkEventController;
using GtkEventControllerClass = struct _GtkEventControllerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API EventController_Class;
}
#endif

namespace Gtk
{

  enum class PropagationPhase
  {
    NONE,
    CAPTURE,
    BUBBLE,
    TARGET
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PropagationPhase>
    : public Glib::Value_Enum<Gtk::PropagationPhase>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  enum class PropagationLimit
  {
    NONE,
    SAME_NATIVE
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PropagationLimit>
    : public Glib::Value_Enum<Gtk::PropagationLimit>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API EventController : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EventController;
    using CppClassType = EventController_Class;
    using BaseObjectType = GtkEventController;
    using BaseClassType = GtkEventControllerClass;

    EventController (const EventController&) = delete;
    auto
    operator= (const EventController&) -> EventController& = delete;

  private:
    friend class EventController_Class;
    static CppClassType eventcontroller_class_;

  protected:
    explicit EventController (const Glib::ConstructParams& construct_params);
    explicit EventController (GtkEventController* castitem);

#endif

  public:
    EventController (EventController&& src) noexcept;
    auto
    operator= (EventController&& src) noexcept -> EventController&;

    ~EventController () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEventController*
    {
      return reinterpret_cast<GtkEventController*> (gobject_);
    }

    auto
    gobj () const -> const GtkEventController*
    {
      return reinterpret_cast<GtkEventController*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEventController*;

  private:
  protected:
    EventController ();

  public:
    auto
    get_widget () -> Widget*;

    auto
    get_widget () const -> const Widget*;

    void
    reset ();

    auto
    get_propagation_phase () const -> PropagationPhase;

    void
    set_propagation_phase (PropagationPhase phase);

    auto
    get_propagation_limit () const -> PropagationLimit;

    void
    set_propagation_limit (PropagationLimit limit);

    auto
    get_name () const -> Glib::ustring;

    void
    set_name (const Glib::ustring& name);

    auto
    get_current_event () const -> Glib::RefPtr<const Gdk::Event>;

    auto
    get_current_event_time () const -> guint32;

    auto
    get_current_event_device () -> Glib::RefPtr<Gdk::Device>;

    auto
    get_current_event_device () const -> Glib::RefPtr<const Gdk::Device>;

    auto
    get_current_event_state () const -> Gdk::ModifierType;

    auto
    property_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_propagation_phase () -> Glib::PropertyProxy<PropagationPhase>;

    auto
    property_propagation_phase () const
        -> Glib::PropertyProxy_ReadOnly<PropagationPhase>;

    auto
    property_propagation_limit () -> Glib::PropertyProxy<PropagationLimit>;

    auto
    property_propagation_limit () const
        -> Glib::PropertyProxy_ReadOnly<PropagationLimit>;

    auto
    property_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkEventController* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EventController>;
} // namespace Glib

#endif
