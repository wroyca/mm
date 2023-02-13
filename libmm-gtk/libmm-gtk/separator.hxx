
#ifndef _GTKMM_SEPARATOR_H
#define _GTKMM_SEPARATOR_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/orientable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSeparator = struct _GtkSeparator;
using GtkSeparatorClass = struct _GtkSeparatorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Separator_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A separator widget.
 *
 * Gtk::Separator is a horizontal or vertical separator widget, depending on the
 * value of the orientation property, used to group the widgets within a
 * window. It displays a line with a shadow to make it appear sunken into the
 * interface.
 */

class GTKMM_API Separator
 : public Widget,
   public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Separator CppObjectType;
  typedef Separator_Class CppClassType;
  typedef GtkSeparator BaseObjectType;
  typedef GtkSeparatorClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Separator(Separator&& src) noexcept;
  auto operator=(Separator&& src) noexcept -> Separator&;

  // noncopyable
  Separator(const Separator&) = delete;
  auto operator=(const Separator&) -> Separator& = delete;

  ~Separator() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Separator_Class;
  static CppClassType separator_class_;

protected:
  explicit Separator(const Glib::ConstructParams& construct_params);
  explicit Separator(GtkSeparator* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkSeparator*       { return reinterpret_cast<GtkSeparator*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSeparator* { return reinterpret_cast<GtkSeparator*>(gobject_); }

private:


public:

  //Note that we try to use the same default parameter value as the default property value.
    explicit Separator(Orientation orientation =  Orientation::HORIZONTAL);


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
   * @relates Gtk::Separator
   */
  GTKMM_API
  auto wrap(GtkSeparator* object, bool take_copy = false) -> Gtk::Separator*;
} //namespace Glib


#endif /* _GTKMM_SEPARATOR_H */
