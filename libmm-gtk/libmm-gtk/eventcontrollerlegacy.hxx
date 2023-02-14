// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EVENTCONTROLLERLEGACY_H
#define _GTKMM_EVENTCONTROLLERLEGACY_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerLegacy = struct _GtkEventControllerLegacy;
using GtkEventControllerLegacyClass = struct _GtkEventControllerLegacyClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API EventControllerLegacy_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API EventControllerLegacy : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EventControllerLegacy;
    using CppClassType = EventControllerLegacy_Class;
    using BaseObjectType = GtkEventControllerLegacy;
    using BaseClassType = GtkEventControllerLegacyClass;

    EventControllerLegacy (const EventControllerLegacy&) = delete;
    auto
    operator= (const EventControllerLegacy&) -> EventControllerLegacy& = delete;

  private:
    friend class EventControllerLegacy_Class;
    static CppClassType eventcontrollerlegacy_class_;

  protected:
    explicit EventControllerLegacy (
        const Glib::ConstructParams& construct_params);
    explicit EventControllerLegacy (GtkEventControllerLegacy* castitem);

#endif

  public:
    EventControllerLegacy (EventControllerLegacy&& src) noexcept;
    auto
    operator= (EventControllerLegacy&& src) noexcept -> EventControllerLegacy&;

    ~EventControllerLegacy () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEventControllerLegacy*
    {
      return reinterpret_cast<GtkEventControllerLegacy*> (gobject_);
    }

    auto
    gobj () const -> const GtkEventControllerLegacy*
    {
      return reinterpret_cast<GtkEventControllerLegacy*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEventControllerLegacy*;

  private:
  protected:
    EventControllerLegacy ();

  public:
    static auto
    create () -> Glib::RefPtr<EventControllerLegacy>;

    auto
    signal_event ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<const Gdk::Event>&)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkEventControllerLegacy* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EventControllerLegacy>;
} // namespace Glib

#endif
