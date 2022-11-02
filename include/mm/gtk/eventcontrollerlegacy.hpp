// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_EVENTCONTROLLERLEGACY_H
#define _GTKMM_EVENTCONTROLLERLEGACY_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2021 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/gtk/eventcontroller.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerLegacy = struct _GtkEventControllerLegacy;
using GtkEventControllerLegacyClass = struct _GtkEventControllerLegacyClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API EventControllerLegacy_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Event controller that provides raw access to the event stream.
 *
 * %Gtk::EventControllerLegacy is an event controller that provides raw
 * access to the event stream.
 *
 * It should only be used as a last resort if none of the other event
 * controllers or gestures do the job.
 *
 * @newin{4,4}
 *
 * @ingroup Gestures
 */

class GTKMM_API EventControllerLegacy : public EventController
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = EventControllerLegacy;
  using CppClassType = EventControllerLegacy_Class;
  using BaseObjectType = GtkEventControllerLegacy;
  using BaseClassType = GtkEventControllerLegacyClass;

  // noncopyable
  EventControllerLegacy(const EventControllerLegacy&) = delete;
  auto operator=(const EventControllerLegacy&) -> EventControllerLegacy& = delete;

private:  friend class EventControllerLegacy_Class;
  static CppClassType eventcontrollerlegacy_class_;

protected:
  explicit EventControllerLegacy(const Glib::ConstructParams& construct_params);
  explicit EventControllerLegacy(GtkEventControllerLegacy* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  EventControllerLegacy(EventControllerLegacy&& src) noexcept;
  auto operator=(EventControllerLegacy&& src) noexcept -> EventControllerLegacy&;

  ~EventControllerLegacy() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkEventControllerLegacy*       { return reinterpret_cast<GtkEventControllerLegacy*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEventControllerLegacy* { return reinterpret_cast<GtkEventControllerLegacy*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkEventControllerLegacy*;

private:


protected:
  EventControllerLegacy();

public:

  static auto create() -> Glib::RefPtr<EventControllerLegacy>;


  // no_default_handler because GtkEventControllerLegacyClass is private.


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%event(const Glib::RefPtr<const Gdk::Event>& event)</tt>
   *
   * Flags: Run Last
   *
   * Emitted for each GDK event delivered to @a controller.
   *
   * @param event The `Gdk::Event` which triggered this signal.
   * @return <tt>true</tt> to stop other handlers from being invoked for the event
   * and the emission of this signal. <tt>false</tt> to propagate the event further.
   */

  auto signal_event() -> Glib::SignalProxy<bool(const Glib::RefPtr<const Gdk::Event>&)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::EventControllerLegacy
   */
  GTKMM_API
  auto wrap(GtkEventControllerLegacy* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EventControllerLegacy>;
}


#endif /* _GTKMM_EVENTCONTROLLERLEGACY_H */
