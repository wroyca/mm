
#ifndef _GTKMM_PADCONTROLLER_H
#define _GTKMM_PADCONTROLLER_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The gtkmm Development Team
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

#include <libmm-gio/actiongroup.hxx>
#include <libmm-gdk/device.hxx>
#include <libmm-gtk/eventcontroller.hxx>
#include <libmm-gtk/padactionentry.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPadController = struct _GtkPadController;
using GtkPadControllerClass = struct _GtkPadControllerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API PadController_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Event controller for drawing tablet pads.
 *
 * %Gtk::PadController is an event controller for the pads found in drawing
 * tablets (The collection of buttons and tactile sensors often found around
 * the stylus-sensitive area).
 *
 * These buttons and sensors have no implicit meaning, and by default they
 * perform no action. This event controller is provided to map those to
 * Gio::Action objects, thus letting the application give those a more semantic
 * meaning.
 *
 * Buttons and sensors are not constrained to triggering a single action, some
 * Gdk::InputSource::TABLET_PAD devices feature multiple "modes". All these input
 * elements have one current mode, which may determine the final action
 * being triggered. Pad devices often divide buttons and sensors into groups.
 * All elements in a group share the same current mode, but different groups
 * may have different modes. See Gdk::DevicePad::get_n_groups() and
 * Gdk::DevicePad::get_group_n_modes().
 *
 * Each of the actions that a given button/strip/ring performs for a given
 * mode is defined by a Gtk::PadActionEntry. It contains an action name that
 * will be looked up in the given Gio::ActionGroup and activated whenever the
 * specified input element and mode are triggered.
 *
 * A simple example of %Gtk::PadController usage, assigning button 1 in all
 * modes and pad devices to a "black" action and button 2 to a "pink" action:
 *
 * @code
 * auto action_group = Gio::SimpleActionGroup::create();
 * auto pad_controller = Gtk::PadController::create(action_group);
 * std::vector<Gtk::PadActionEntry> entries = {
 *   { Gtk::PadActionType::BUTTON, 1, -1, "Black", "pad.black" },
 *   { Gtk::PadActionType::BUTTON, 2, -1, "Pink", "pad.pink" },
 * };
 * for (const auto& entry : entries)
 *   action_group->add_action(entry.get_action_name(), sigc::mem_fun(*this, &MyWindow::on_pad_activated));
 * pad_controller->set_action_entries(entries);
 * // Assuming the code is in the MyWindow constructor.
 * add_controller(pad_controller);
 * @endcode
 *
 * The actions belonging to rings/strips will be activated with a parameter
 * of type Glib::Variant<double> bearing the value of the given axis. It
 * is required that those are made stateful and accepting this Glib::VariantType.
 *
 * @see Gtk::EventController, Gdk::DevicePad
 * @newin{3,96}
 *
 * @ingroup Gestures
 */

class GTKMM_API PadController : public EventController
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PadController;
  using CppClassType = PadController_Class;
  using BaseObjectType = GtkPadController;
  using BaseClassType = GtkPadControllerClass;

  // noncopyable
  PadController(const PadController&) = delete;
  auto operator=(const PadController&) -> PadController& = delete;

private:  friend class PadController_Class;
  static CppClassType padcontroller_class_;

protected:
  explicit PadController(const Glib::ConstructParams& construct_params);
  explicit PadController(GtkPadController* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PadController(PadController&& src) noexcept;
  auto operator=(PadController&& src) noexcept -> PadController&;

  ~PadController() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkPadController*       { return reinterpret_cast<GtkPadController*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPadController* { return reinterpret_cast<GtkPadController*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkPadController*;

private:


protected:
  explicit PadController(const Glib::RefPtr<Gio::ActionGroup>& action_group,
    const Glib::RefPtr<Gdk::Device>& pad = {});


public:
  /** Creates a new %Gtk::PadController that will associate events from @a pad to actions.
   *
   * An empty %Glib::RefPtr pad may be provided so the controller manages all pad devices
   * generically. It is discouraged to mix %Gtk::PadController objects with empty
   * and non-empty @a pad argument on the same toplevel window, as execution order
   * is not guaranteed.
   *
   * The %Gtk::PadController is created with no mapped actions. In order to map pad
   * events to actions, use set_action_entries() or set_action().
   *
   * Be aware that pad events will only be delivered to Gtk::Windows, so adding a pad
   * controller to any other type of widget will not have an effect.
   *
   * @param group Gio::ActionGroup to trigger actions from.
   * @param pad A Gdk::InputSource::TABLET_PAD device, or an empty %Glib::RefPtr to handle all pads.
   * @return A newly created %Gtk::PadController.
   */

  static auto create(const Glib::RefPtr<Gio::ActionGroup>& action_group, const Glib::RefPtr<Gdk::Device>& pad =  {}) -> Glib::RefPtr<PadController>;


  /** This is a convenience function to add a group of action entries on the pad controller.
   *
   * See Gtk::PadActionEntry and set_action().
   *
   * @param entries The action entries to set on the controller.
   */
  void set_action_entries(const std::vector<PadActionEntry>& entries);


  /** Adds an individual action to @a controller.
   *
   * This action will only be activated if the given button/ring/strip number
   * in @a index is interacted while the current mode is @a mode. -1 may be used
   * for simple cases, so the action is triggered on all modes.
   *
   * The given @a label should be considered user-visible, so internationalization
   * rules apply. Some windowing systems may be able to use those for user
   * feedback.
   *
   * @param type The type of pad feature that will trigger this action.
   * @param index The 0-indexed button/ring/strip number that will trigger this action.
   * @param mode The mode that will trigger this action, or -1 for all modes.
   * @param label Human readable description of this action, this string should
   * be deemed user-visible.
   * @param action_name Action name that will be activated in the `Gio::ActionGroup`.
   */
  void set_action(PadActionType type, int index, int mode, const Glib::ustring& label, const Glib::ustring& action_name);

  /**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_action_group() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ActionGroup> >;


  /**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pad() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Device> >;


  // There are no signals or vfuncs.


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
   * @relates Gtk::PadController
   */
  GTKMM_API
  auto wrap(GtkPadController* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PadController>;
}


#endif /* _GTKMM_PADCONTROLLER_H */

