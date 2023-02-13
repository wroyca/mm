
#ifndef _GTKMM_ASSISTANTPAGE_H
#define _GTKMM_ASSISTANTPAGE_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
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


#include <mm/glib/object.hpp>
#include <mm/glib/refptr.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAssistantPage = struct _GtkAssistantPage;
using GtkAssistantPageClass = struct _GtkAssistantPageClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API AssistantPage_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Widget;

/** Holds properties of a Gtk::Assistant page.
 *
 * Use Gtk::Assistant::get_page() to get a pointer to an %AssistantPage object.
 *
 * @see Assistant
 * @newin{3,96}
 */

class GTKMM_API AssistantPage : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = AssistantPage;
  using CppClassType = AssistantPage_Class;
  using BaseObjectType = GtkAssistantPage;
  using BaseClassType = GtkAssistantPageClass;

  // noncopyable
  AssistantPage(const AssistantPage&) = delete;
  auto operator=(const AssistantPage&) -> AssistantPage& = delete;

private:  friend class AssistantPage_Class;
  static CppClassType assistantpage_class_;

protected:
  explicit AssistantPage(const Glib::ConstructParams& construct_params);
  explicit AssistantPage(GtkAssistantPage* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  AssistantPage(AssistantPage&& src) noexcept;
  auto operator=(AssistantPage&& src) noexcept -> AssistantPage&;

  ~AssistantPage() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkAssistantPage*       { return reinterpret_cast<GtkAssistantPage*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAssistantPage* { return reinterpret_cast<GtkAssistantPage*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkAssistantPage*;

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Type CONTENT
   * The page has regular contents. Both the
   * Back and forward buttons will be shown.
   *
   *  @var Type INTRO
   * The page contains an introduction to the
   * assistant task. Only the Forward button will be shown if there is a
   * next page.
   *
   *  @var Type CONFIRM
   * The page lets the user confirm or deny the
   * changes. The Back and Apply buttons will be shown.
   *
   *  @var Type SUMMARY
   * The page informs the user of the changes
   * done. Only the Close button will be shown.
   *
   *  @var Type PROGRESS
   * Used for tasks that take a long time to
   * complete, blocks the assistant until the page is marked as complete.
   * Only the back button will be shown.
   *
   *  @var Type CUSTOM
   * Used for when other page types are not
   * appropriate. No buttons will be shown, and the application must
   * add its own buttons through Gtk::Assistant::add_action_widget().
   *
   *  @enum Type
   *
   * Determines the page role inside a `Gtk::Assistant`.
   *
   * The role is used to handle buttons sensitivity and visibility.
   *
   * Note that an assistant needs to end its page flow with a page of type
   * Gtk::AssistantPage::Type::CONFIRM, Gtk::AssistantPage::Type::SUMMARY or
   * Gtk::AssistantPage::Type::PROGRESS to be correct.
   *
   * The Cancel button will only be shown if the page isn’t “committed”.
   * See Gtk::Assistant::commit() for details.
   *
   * @ingroup gtkmmEnums
   */
  enum class Type
  {
    CONTENT,
    INTRO,
    CONFIRM,
    SUMMARY,
    PROGRESS,
    CUSTOM
  };


  /** Returns the child to which @a page belongs.
   *
   * @return The child to which @a page belongs.
   */
  auto get_child() -> Widget*;

  /** Returns the child to which @a page belongs.
   *
   * @return The child to which @a page belongs.
   */
  auto get_child() const -> const Widget*;

  /** The type of the assistant page.
   *
   * Default value: Gtk::AssistantPage::Type::CONTENT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page_type() -> Glib::PropertyProxy< Type > ;

/** The type of the assistant page.
   *
   * Default value: Gtk::AssistantPage::Type::CONTENT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page_type() const -> Glib::PropertyProxy_ReadOnly< Type >;

  /** The title of the page.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** The title of the page.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether all required fields are filled in.
   *
   * GTK uses this information to control the sensitivity
   * of the navigation buttons.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_complete() -> Glib::PropertyProxy< bool > ;

/** Whether all required fields are filled in.
   *
   * GTK uses this information to control the sensitivity
   * of the navigation buttons.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_complete() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


  // There are no signals or vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::AssistantPage::Type> : public Glib::Value_Enum<Gtk::AssistantPage::Type>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::AssistantPage
   */
  GTKMM_API
  auto wrap(GtkAssistantPage* object, bool take_copy = false) -> Glib::RefPtr<Gtk::AssistantPage>;
}


#endif /* _GTKMM_ASSISTANTPAGE_H */

