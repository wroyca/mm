
#ifndef _GTKMM_BINLAYOUT_H
#define _GTKMM_BINLAYOUT_H


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

#include <libmm-gtk/layoutmanager.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API BinLayout_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A layout manager for bin-like widgets.
 *
 * %Gtk::BinLayout is a Gtk::LayoutManager subclass useful for creating "bins" of
 * widgets. %Gtk::BinLayout will stack each child of a widget on top of each
 * other, using Gtk::Widget::property_hexpand(), Gtk::Widget::property_vexpand(),
 * Gtk::Widget::property_halign(), and Gtk::Widget::property_valign() of each
 * child to determine where they should be positioned.
 *
 * @newin{3,96}
 */

class GTKMM_API BinLayout : public LayoutManager
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = BinLayout;
  using CppClassType = BinLayout_Class;
  using BaseObjectType = GtkBinLayout;
  using BaseClassType = GtkBinLayoutClass;

  // noncopyable
  BinLayout(const BinLayout&) = delete;
  auto operator=(const BinLayout&) -> BinLayout& = delete;

private:  friend class BinLayout_Class;
  static CppClassType binlayout_class_;

protected:
  explicit BinLayout(const Glib::ConstructParams& construct_params);
  explicit BinLayout(GtkBinLayout* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  BinLayout(BinLayout&& src) noexcept;
  auto operator=(BinLayout&& src) noexcept -> BinLayout&;

  ~BinLayout() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkBinLayout*       { return reinterpret_cast<GtkBinLayout*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkBinLayout* { return reinterpret_cast<GtkBinLayout*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkBinLayout*;

private:


protected:
  BinLayout();

public:

  static auto create() -> Glib::RefPtr<BinLayout>;


  // There are no signals, properties or vfuncs, and create() is the only method.


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
   * @relates Gtk::BinLayout
   */
  GTKMM_API
  auto wrap(GtkBinLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::BinLayout>;
}


#endif /* _GTKMM_BINLAYOUT_H */

