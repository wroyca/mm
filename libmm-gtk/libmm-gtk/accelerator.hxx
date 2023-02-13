#ifndef _GTKMM_ACCELERATOR_H
#define _GTKMM_ACCELERATOR_H
/* Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <libmm-gtk/mm-gtkconfig.hpp>

#include <libmm-glib/ustring.hpp>
#include <libmm-gdk/enums.hpp>

// The corresponding gtk functions are declared in gtkaccelgroup.h.

namespace Gtk::Accelerator
{
  /** Determines whether a given keyval and modifier mask constitute
   * a valid keyboard accelerator.
   *
   * For example, the 'a' keyval plus Gdk::ModifierType::CONTROL_MASK is valid -
   * this is a "Ctrl+a" accelerator. But you can't, for instance, use the
   * GDK_KEY_Control_L keyval as an accelerator.
   *
   * @return <tt>true</tt> if the accelerator is valid.
   */
  GTKMM_API
  auto valid(guint keyval, Gdk::ModifierType modifiers) -> bool;

  /** Parses a string representing an accelerator.
   *
   * The format looks like “<Control>a” or “<Shift><Alt>F1”.
   *
   * The parser is fairly liberal and allows lower or upper case, and also
   * abbreviations such as “<Ctl>” and “<Ctrl>”. Key names are parsed using
   * gdk_keyval_from_name(). For character keys the name is not the symbol,
   * but the lowercase name, e.g. one would use “<Ctrl>minus” instead of
   * “<Ctrl>-”.
   *
   * If the parse fails, @a accelerator_key and @a accelerator_mods will
   * be set to 0 (zero).
   *
   * @param accelerator See the Gtk::AccelKey constructor for the format.
   * @param[out] accelerator_key Accelerator keyval.
   * @param[out] accelerator_mods Accelerator modifier mask.
   * @return <tt>true</tt> if parsing succeeded.
   */
  GTKMM_API
  auto parse(const Glib::ustring& accelerator, guint& accelerator_key,
    Gdk::ModifierType& accelerator_mods) -> bool;

  /** Converts an accelerator keyval and modifier mask
   * into a string parseable by parse().
   *
   * For example, if you pass in 'q' and Gdk::ModifierType::CONTROL_MASK,
   * it returns "<Control>q".
   *
   * If you need to display accelerators in the user interface, see get_label().
   *
   * @param accelerator_key Accelerator keyval.
   * @param accelerator_mods Accelerator modifier mask.
   * @return The accelerator name.
   */
  GTKMM_API
  auto name(guint accelerator_key, Gdk::ModifierType accelerator_mods) -> Glib::ustring;

  /** Converts an accelerator keyval and modifier mask into a string
   * which can be used to represent the accelerator to the user.
   *
   * @param accelerator_key Accelerator keyval.
   * @param accelerator_mods Accelerator modifier mask.
   * @return A string representing the accelerator.
   */
  GTKMM_API
  auto get_label(guint accelerator_key, Gdk::ModifierType accelerator_mods) -> Glib::ustring;

  /** Gets the modifier mask.
   *
   * The modifier mask determines which modifiers are considered significant
   * for keyboard accelerators. This includes all keyboard modifiers except
   * for %GDK_LOCK_MASK.
   *
   * @return The modifier mask for accelerators
   */
  GTKMM_API
  auto get_default_mod_mask() -> Gdk::ModifierType;

} // namespace Gtk
#endif /* _GTKMM_ACCELERATOR_H */
