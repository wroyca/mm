
#ifndef _GTKMM_STACKPAGE_H
#define _GTKMM_STACKPAGE_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
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


#include <libmm-glib/object.hpp>
#include <libmm-glib/refptr.hpp>
#include <libmm-gtk/accessible.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStackPage = struct _GtkStackPage;
using GtkStackPageClass = struct _GtkStackPageClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API StackPage_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Widget;

/** Holds properties of a Gtk::Stack page.
 *
 * Use Gtk::Stack::get_page() to get a pointer to an %StackPage object.
 *
 * @see Stack
 * @newin{3,96}
 */

class GTKMM_API StackPage : public Glib::Object, public Accessible
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = StackPage;
  using CppClassType = StackPage_Class;
  using BaseObjectType = GtkStackPage;
  using BaseClassType = GtkStackPageClass;

  // noncopyable
  StackPage(const StackPage&) = delete;
  auto operator=(const StackPage&) -> StackPage& = delete;

private:  friend class StackPage_Class;
  static CppClassType stackpage_class_;

protected:
  explicit StackPage(const Glib::ConstructParams& construct_params);
  explicit StackPage(GtkStackPage* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  StackPage(StackPage&& src) noexcept;
  auto operator=(StackPage&& src) noexcept -> StackPage&;

  ~StackPage() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkStackPage*       { return reinterpret_cast<GtkStackPage*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkStackPage* { return reinterpret_cast<GtkStackPage*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkStackPage*;

private:


public:

  /** Returns the stack child to which @a self belongs.
   *
   * @return The child to which @a self belongs.
   */
  auto get_child() -> Widget*;

  /** Returns the stack child to which @a self belongs.
   *
   * @return The child to which @a self belongs.
   */
  auto get_child() const -> const Widget*;


  /** Returns whether @a page is visible in its `Gtk::Stack`.
   *
   * This is independent from the Gtk::Widget::property_visible()
   * property of its widget.
   *
   * @return <tt>true</tt> if @a page is visible.
   */
  auto get_visible() const -> bool;

  /** Sets whether @a page is visible in its `Gtk::Stack`.
   *
   * @param visible The new property value.
   */
  void set_visible(bool visible =  true);


  /** Returns whether the page is marked as “needs attention”.
   *
   * @return The value of the property_needs_attention()
   * property.
   */
  auto get_needs_attention() const -> bool;

  /** Sets whether the page is marked as “needs attention”.
   *
   * @param setting The new value to set.
   */
  void set_needs_attention(bool setting =  true);

  /** Gets whether underlines in the page title indicate mnemonics.
   *
   * @return The value of the property_use_underline() property.
   */
  auto get_use_underline() const -> bool;

  /** Sets whether underlines in the page title indicate mnemonics.
   *
   * @param setting The new value to set.
   */
  void set_use_underline(bool setting =  true);

  /** Returns the name of the page.
   *
   * @return The value of the property_name() property.
   */
  auto get_name() const -> Glib::ustring;

  /** Sets the name of the page.
   *
   * @param setting The new value to set.
   */
  void set_name(const Glib::ustring& setting);

  /** Gets the page title.
   *
   * @return The value of the property_title() property.
   */
  auto get_title() const -> Glib::ustring;

  /** Sets the page title.
   *
   * @param setting The new value to set.
   */
  void set_title(const Glib::ustring& setting);

  /** Returns the icon name of the page.
   *
   * @return The value of the property_icon_name() property.
   */
  auto get_icon_name() const -> Glib::ustring;

  /** Sets the icon name of the page.
   *
   * @param setting The new value to set.
   */
  void set_icon_name(const Glib::ustring& setting);

  /** The child that this page is for.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


  /** The name of the child page.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The name of the child page.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The title of the child page.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** The title of the child page.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The icon name of the child page.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The icon name of the child page.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether the page requires the user attention.
   *
   * This is used by the Gtk::StackSwitcher to change the
   * appearance of the corresponding button when a page needs
   * attention and it is not the current one.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_needs_attention() -> Glib::PropertyProxy< bool > ;

/** Whether the page requires the user attention.
   *
   * This is used by the Gtk::StackSwitcher to change the
   * appearance of the corresponding button when a page needs
   * attention and it is not the current one.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_needs_attention() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether this page is visible.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible() -> Glib::PropertyProxy< bool > ;

/** Whether this page is visible.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If set, an underline in the title indicates a mnemonic.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_underline() -> Glib::PropertyProxy< bool > ;

/** If set, an underline in the title indicates a mnemonic.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_underline() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::StackPage
   */
  GTKMM_API
  auto wrap(GtkStackPage* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StackPage>;
}


#endif /* _GTKMM_STACKPAGE_H */

