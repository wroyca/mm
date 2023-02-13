
#ifndef _GTKMM_REQUISITION_H
#define _GTKMM_REQUISITION_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The gtkmm Development Team
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


#include <libmm-glib/value.hpp>
#include <gtk/gtk.h>


namespace Gtk
{

/** A %Gtk::Requisition represents the desired size of a widget.
 */
class GTKMM_API Requisition
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Requisition;
  using BaseObjectType = GtkRequisition;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Requisition(const Requisition& other) noexcept;
  auto operator=(const Requisition& other) noexcept -> Requisition&;

  Requisition(Requisition&& other) noexcept;
  auto operator=(Requisition&& other) noexcept -> Requisition&;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  Requisition();

  explicit Requisition(const GtkRequisition* gobject); // always takes a copy

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkRequisition*       { return &gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkRequisition* { return &gobject_; }

protected:
  GtkRequisition gobject_;

private:

public:

  /** Creates a new requisition instance with this size.
   */
  Requisition(int width, int height);

  auto get_width() const -> int;
  void set_width(const int& value);
  auto get_height() const -> int;
  void set_height(const int& value);


};

} // namespace Gtk


namespace Glib
{

/** @relates Gtk::Requisition
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GTKMM_API
auto wrap(GtkRequisition* object) -> Gtk::Requisition&;

/** @relates Gtk::Requisition
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GTKMM_API
auto wrap(const GtkRequisition* object) -> const Gtk::Requisition&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GTKMM_API Value<Gtk::Requisition> : public Glib::Value_Boxed<Gtk::Requisition>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_REQUISITION_H */

