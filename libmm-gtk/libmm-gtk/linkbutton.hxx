
#ifndef _GTKMM_LINKBUTTON_H
#define _GTKMM_LINKBUTTON_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2006 The gtkmm Development Team
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

#include <libmm-gtk/button.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLinkButton = struct _GtkLinkButton;
using GtkLinkButtonClass = struct _GtkLinkButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API LinkButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Create buttons bound to a URL.
 *
 * A Gtk::LinkButton is a Gtk::Button with a hyperlink, similar to the one
 * used by web browsers, which triggers an action when clicked. It is useful
 * to show quick links to resources.
 *
 * The URI bound to a Gtk::LinkButton can be set specifically using set_uri(),
 * and retrieved using get_uri().
 * By default, Gtk::LinkButton calls gtk_show_uri() when the button is clicked.
 * This behaviour can be overridden by connecting to the activate_link signal and
 * returning true from the signal handler.
 *
 * The LinkButton widget looks like this:
 * @image html linkbutton1.png
 *
 * @newin{2,10}
 * @ingroup Widgets
 */

class GTKMM_API LinkButton : public Button
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef LinkButton CppObjectType;
  typedef LinkButton_Class CppClassType;
  typedef GtkLinkButton BaseObjectType;
  typedef GtkLinkButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  LinkButton(LinkButton&& src) noexcept;
  auto operator=(LinkButton&& src) noexcept -> LinkButton&;

  // noncopyable
  LinkButton(const LinkButton&) = delete;
  auto operator=(const LinkButton&) -> LinkButton& = delete;

  ~LinkButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class LinkButton_Class;
  static CppClassType linkbutton_class_;

protected:
  explicit LinkButton(const Glib::ConstructParams& construct_params);
  explicit LinkButton(GtkLinkButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkLinkButton*       { return reinterpret_cast<GtkLinkButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkLinkButton* { return reinterpret_cast<GtkLinkButton*>(gobject_); }

private:

public:
  LinkButton();
  explicit LinkButton(const Glib::ustring& uri);

    explicit LinkButton(const Glib::ustring& uri, const Glib::ustring& label);


  /** Retrieves the URI of the `Gtk::LinkButton`.
   *
   * @return A valid URI. The returned string is owned by the link button
   * and should not be modified or freed.
   */
  auto get_uri() const -> Glib::ustring;

  /** Sets @a uri as the URI where the `Gtk::LinkButton` points.
   *
   * As a side-effect this unsets the “visited” state of the button.
   *
   * @param uri A valid URI.
   */
  void set_uri(const Glib::ustring& uri);


  /** Retrieves the “visited” state of the `Gtk::LinkButton`.
   *
   * The button becomes visited when it is clicked. If the URI
   * is changed on the button, the “visited” state is unset again.
   *
   * The state may also be changed using set_visited().
   *
   * @return <tt>true</tt> if the link has been visited, <tt>false</tt> otherwise.
   */
  auto get_visited() const -> bool;

  /** Sets the “visited” state of the `Gtk::LinkButton`.
   *
   * See get_visited() for more details.
   *
   * @param visited The new “visited” state.
   */
  void set_visited(bool visited =  true);

  /** The URI bound to this button.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_uri() -> Glib::PropertyProxy< Glib::ustring > ;

/** The URI bound to this button.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_uri() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The 'visited' state of this button.
   *
   * A visited link is drawn in a different color.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visited() -> Glib::PropertyProxy< bool > ;

/** The 'visited' state of this button.
   *
   * A visited link is drawn in a different color.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visited() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // no_default_handler because GtkLinkButtonClass is private.

  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%activate_link()</tt>
   *
   * Flags: Run Last
   *
   * Emitted each time the `Gtk::LinkButton` is clicked.
   *
   * The default handler will call gtk_show_uri() with the URI
   * stored inside the property_uri() property.
   *
   * To override the default behavior, you can connect to the
   * signal_activate_link() signal and stop the propagation of the signal
   * by returning <tt>true</tt> from your handler.
   *
   * @return <tt>true</tt> if the signal has been handled.
   */

  auto signal_activate_link() -> Glib::SignalProxy<bool()>;


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
   * @relates Gtk::LinkButton
   */
  GTKMM_API
  auto wrap(GtkLinkButton* object, bool take_copy = false) -> Gtk::LinkButton*;
} //namespace Glib


#endif /* _GTKMM_LINKBUTTON_H */
