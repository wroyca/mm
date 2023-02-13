
#ifndef _GTKMM_LISTBASE_H
#define _GTKMM_LISTBASE_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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

#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/scrollable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListBase = struct _GtkListBase;
using GtkListBaseClass = struct _GtkListBaseClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ListBase_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


class GTKMM_API ListBase : public Widget, public Orientable, public Scrollable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ListBase CppObjectType;
  typedef ListBase_Class CppClassType;
  typedef GtkListBase BaseObjectType;
  typedef GtkListBaseClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ListBase(ListBase&& src) noexcept;
  auto operator=(ListBase&& src) noexcept -> ListBase&;

  // noncopyable
  ListBase(const ListBase&) = delete;
  auto operator=(const ListBase&) -> ListBase& = delete;

  ~ListBase() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ListBase_Class;
  static CppClassType listbase_class_;

protected:
  explicit ListBase(const Glib::ConstructParams& construct_params);
  explicit ListBase(GtkListBase* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkListBase*       { return reinterpret_cast<GtkListBase*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkListBase* { return reinterpret_cast<GtkListBase*>(gobject_); }

private:


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
   * @relates Gtk::ListBase
   */
  GTKMM_API
  auto wrap(GtkListBase* object, bool take_copy = false) -> Gtk::ListBase*;
} //namespace Glib


#endif /* _GTKMM_LISTBASE_H */

