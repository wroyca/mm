// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_STATUSBAR_H
#define _GTKMM_STATUSBAR_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <mm/gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStatusbar = struct _GtkStatusbar;
using GtkStatusbarClass = struct _GtkStatusbarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Statusbar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Text status indicator
 * This widget is used to display status information.
 * Messages are pushed and poped onto a message stack.
 * When text is pushed it replaces the old contents.
 * The old text is restored when popped.
 *
 * It derives from Gtk::Box so that additional information can be added easily.
 *
 * The Statusbar widget looks like this:
 * @image html statusbar1.png
 *
 * @ingroup Widgets
 */

class GTKMM_API Statusbar : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Statusbar CppObjectType;
  typedef Statusbar_Class CppClassType;
  typedef GtkStatusbar BaseObjectType;
  typedef GtkStatusbarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Statusbar(Statusbar&& src) noexcept;
  auto operator=(Statusbar&& src) noexcept -> Statusbar&;

  // noncopyable
  Statusbar(const Statusbar&) = delete;
  auto operator=(const Statusbar&) -> Statusbar& = delete;

  ~Statusbar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Statusbar_Class;
  static CppClassType statusbar_class_;

protected:
  explicit Statusbar(const Glib::ConstructParams& construct_params);
  explicit Statusbar(GtkStatusbar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkStatusbar*       { return reinterpret_cast<GtkStatusbar*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkStatusbar* { return reinterpret_cast<GtkStatusbar*>(gobject_); }

private:


public:
  Statusbar();


  /** Returns a new context identifier, given a description
   * of the actual context.
   *
   * Note that the description is not shown in the UI.
   *
   * @param context_description Textual description of what context
   * the new message is being used in.
   * @return An integer id.
   */
  auto get_context_id(const Glib::ustring& context_description) -> guint;

  /** Pushes a new message onto a statusbar's stack.
   * @param text The message to add to the statusbar.
   * @param context_id The message's context id, as returned by get_context_id()
   */
  auto push(const Glib::ustring& text, guint context_id = 0) -> guint;


  /** Removes the first message in the `Gtk::Statusbar`’s stack
   * with the given context id.
   *
   * Note that this may not change the displayed message,
   * if the message at the top of the stack has a different
   * context id.
   *
   * @param context_id A context identifier.
   */
  void pop(guint context_id =  0);

  /** Forces the removal of a message from a statusbar's stack.
   * The exact context_id and message_id must be specified.
   * @param message_id A message identifier, as returned by push().
   * @param context_id A context identifier.
   */
  void remove_message(guint message_id, guint context_id = 0);


  /** Forces the removal of all messages from a statusbar's
   * stack with the exact @a context_id.
   *
   * @param context_id A context identifier.
   */
  void remove_all_messages(guint context_id =  0);

  // no_default_handler because GtkStatusbarClass is private.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%text_pushed(guint context_id, const Glib::ustring& text)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a new message gets pushed onto a statusbar's stack.
   *
   * @param context_id The context id of the relevant message/statusbar.
   * @param text The message that was pushed.
   */

  auto signal_text_pushed() -> Glib::SignalProxy<void(guint, const Glib::ustring&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%text_popped(guint context_id, const Glib::ustring& text)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a new message is popped off a statusbar's stack.
   *
   * @param context_id The context id of the relevant message/statusbar.
   * @param text The message that was just popped.
   */

  auto signal_text_popped() -> Glib::SignalProxy<void(guint, const Glib::ustring&)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Statusbar
   */
  GTKMM_API
  auto wrap(GtkStatusbar* object, bool take_copy = false) -> Gtk::Statusbar*;
} //namespace Glib


#endif /* _GTKMM_STATUSBAR_H */

