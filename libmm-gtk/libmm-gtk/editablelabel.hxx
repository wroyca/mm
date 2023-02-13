
#ifndef _GTKMM_EDITABLELABEL_H
#define _GTKMM_EDITABLELABEL_H


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

#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/widget.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API EditableLabel_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A label that can be edited.
 *
 * A %Gtk::EditableLabel is a Gtk::Label that allows users to
 * edit the text by switching the widget to an “edit mode”.
 *
 * %Gtk::EditableLabel does not have API of its own, but it
 * implements the Gtk::Editable interface.
 *
 * The default bindings for activating the edit mode is
 * to click or press the Enter key. The default bindings
 * for leaving the edit mode are the Enter key (to save
 * the results) or the Escape key (to cancel the editing).
 *
 * @see Editable, Label, Entry
 *
 * @ingroup Widgets
 *
 * @newin{3,98}
 */

class GTKMM_API EditableLabel : public Widget, public Editable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef EditableLabel CppObjectType;
  typedef EditableLabel_Class CppClassType;
  typedef GtkEditableLabel BaseObjectType;
  typedef GtkEditableLabelClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  EditableLabel(EditableLabel&& src) noexcept;
  auto operator=(EditableLabel&& src) noexcept -> EditableLabel&;

  // noncopyable
  EditableLabel(const EditableLabel&) = delete;
  auto operator=(const EditableLabel&) -> EditableLabel& = delete;

  ~EditableLabel() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class EditableLabel_Class;
  static CppClassType editablelabel_class_;

protected:
  explicit EditableLabel(const Glib::ConstructParams& construct_params);
  explicit EditableLabel(GtkEditableLabel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkEditableLabel*       { return reinterpret_cast<GtkEditableLabel*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEditableLabel* { return reinterpret_cast<GtkEditableLabel*>(gobject_); }

private:


public:
  EditableLabel();
  // The str parameter is renamed to text because that is the property name.
    explicit EditableLabel(const Glib::ustring& text);


  /** Returns whether the label is currently in “editing mode”.
   *
   * @return <tt>true</tt> if @a self is currently in editing mode.
   */
  auto get_editing() const -> bool;

  /** Switches the label into “editing mode”.
   */
  void start_editing();

  /** Switches the label out of “editing mode”.
   *
   * If @a commit is <tt>true</tt>, the resulting text is kept as the
   * Gtk::Editable::property_text() property value, otherwise the
   * resulting text is discarded and the label will keep its
   * previous Gtk::Editable::property_text() property value.
   *
   * @param commit Whether to set the edited text on the label.
   */
  void stop_editing(bool commit);

  /** This property is <tt>true</tt> while the widget is in edit mode.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editing() -> Glib::PropertyProxy< bool > ;

/** This property is <tt>true</tt> while the widget is in edit mode.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editing() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // EditableLabel has no signals nor vfuncs.


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
   * @relates Gtk::EditableLabel
   */
  GTKMM_API
  auto wrap(GtkEditableLabel* object, bool take_copy = false) -> Gtk::EditableLabel*;
} //namespace Glib


#endif /* _GTKMM_EDITABLELABEL_H */

