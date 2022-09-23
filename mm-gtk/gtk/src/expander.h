// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_EXPANDER_H
#define _GTKMM_EXPANDER_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2003 The gtkmm Development Team
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

#include <gtkmm/widget.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkExpander = struct _GtkExpander;
using GtkExpanderClass = struct _GtkExpanderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Expander_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A container which can hide its child.
 *
 * An Expander allows the user to hide or show its child by clicking on an
 * expander triangle similar to the triangles used in a Gtk::TreeView.
 *
 * Normally you use an expander as you would use a frame; you create
 * the child widget and use set_child() to add it to the
 * expander. When the expander is toggled, it will take care of showing
 * and hiding the child automatically.
 *
 * Special Usage: There are situations in which you may prefer to show and
 * hide the expanded widget yourself, such as when you want to
 * actually create the widget at expansion time.  In this case,
 * create an Expander but do not add a child to it.  The
 * expander widget has an <tt>expanded</tt> property
 * which can be used to monitor its expansion state.  You should
 * watch this property with a signal connection as follows:
 * @code
 * expander.property_expanded().signal_changed().connect(
 *   sigc::mem_fun(*this, &SomeClass::on_expander_changed)
 * );
 * @endcode
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API Expander : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Expander CppObjectType;
  typedef Expander_Class CppClassType;
  typedef GtkExpander BaseObjectType;
  typedef GtkExpanderClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Expander(Expander&& src) noexcept;
  Expander& operator=(Expander&& src) noexcept;

  // noncopyable
  Expander(const Expander&) = delete;
  Expander& operator=(const Expander&) = delete;

  ~Expander() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Expander_Class;
  static CppClassType expander_class_;

protected:
  explicit Expander(const Glib::ConstructParams& construct_params);
  explicit Expander(GtkExpander* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GtkExpander*       gobj()       { return reinterpret_cast<GtkExpander*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GtkExpander* gobj() const { return reinterpret_cast<GtkExpander*>(gobject_); }

private:

public:

  /** Creates a new Expander.
   *
   * The Expander has an empty label.
   *
   * @newin{2,4}
   */
  Expander();

  /** Creates a new Expander with a label.
   *
   * Creates a new expander using label as the text of the label. Settin @a mnemonic to true
   * will allow you to precede characters in the label with an underscore which will make them
   * underlined. If you need a literal underscore character in a label, use '__' (two underscores).
   * The first underlined character represents a keyboard accelerator called a mnemonic.
   * Pressing Alt and that key activates the button.
   *
   * @param label The string for the label describing the Expander.
   * @param mnemonic Wether the label may contain underscores to set up accelerators.

   * @newin{2,4}
   */
  explicit Expander(const Glib::ustring& label, bool mnemonic = false);
  

  /** Sets the state of the expander.
   * 
   * Set to <tt>true</tt>, if you want the child widget to be revealed,
   * and <tt>false</tt> if you want the child widget to be hidden.
   * 
   * @param expanded Whether the child widget is revealed.
   */
  void set_expanded(bool expanded =  true);
  
  /** Queries a `Gtk::Expander` and returns its current state.
   * 
   * @return The current state of the expander.
   */
  bool get_expanded() const;

  
  /** Sets the text of the label of the expander to @a label.
   * 
   * This will also clear any previously set labels.
   * 
   * @param label A string.
   */
  void set_label(const Glib::ustring& label);
  
  /** Fetches the text from a label widget.
   * 
   * This is including any embedded underlines indicating mnemonics and
   * Pango markup, as set by set_label(). If the label
   * text has not been set the return value will be <tt>nullptr</tt>. This will be the
   * case if you create an empty button with Gtk::Button::new() to use as a
   * container.
   * 
   * @return The text of the label widget. This string is owned
   * by the widget and must not be modified or freed.
   */
  Glib::ustring get_label() const;

  
  /** If true, an underline in the text indicates a mnemonic.
   * 
   * @param use_underline <tt>true</tt> if underlines in the text indicate mnemonics.
   */
  void set_use_underline(bool use_underline =  true);
  
  /** Returns whether an underline in the text indicates a mnemonic.
   * 
   * @return <tt>true</tt> if an embedded underline in the expander
   * label indicates the mnemonic accelerator keys.
   */
  bool get_use_underline() const;

  
  /** Sets whether the text of the label contains Pango markup.
   * 
   * @param use_markup <tt>true</tt> if the label’s text should be parsed for markup.
   */
  void set_use_markup(bool use_markup =  true);
  
  /** Returns whether the label’s text is interpreted as Pango markup.
   * 
   * @return <tt>true</tt> if the label’s text will be parsed for markup.
   */
  bool get_use_markup() const;

  
  /** Set the label widget for the expander.
   * 
   * This is the widget that will appear embedded alongside
   * the expander arrow.
   * 
   * @param label_widget The new label widget.
   */
  void set_label_widget(Widget& label_widget);
  
  /** Retrieves the label widget for the frame.
   * 
   * @return The label widget.
   */
  Widget* get_label_widget();
  
  /** Retrieves the label widget for the frame.
   * 
   * @return The label widget.
   */
  const Widget* get_label_widget() const;

  
  /** Sets whether the expander will resize the toplevel widget
   * containing the expander upon resizing and collpasing.
   * 
   * @param resize_toplevel Whether to resize the toplevel.
   */
  void set_resize_toplevel(bool resize_toplevel =  true);
  
  /** Returns whether the expander will resize the toplevel widget
   * containing the expander upon resizing and collpasing.
   * 
   * @return The “resize toplevel” setting.
   */
  bool get_resize_toplevel() const;

  
  /** Sets the child widget of @a expander.
   * 
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();
  
  /** Gets the child widget of @a expander.
   * 
   * @return The child widget of @a expander.
   */
  Widget* get_child();
  
  /** Gets the child widget of @a expander.
   * 
   * @return The child widget of @a expander.
   */
  const Widget* get_child() const;

   //keybinding

  /** Whether the expander has been opened to reveal the child.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_expanded() ;

/** Whether the expander has been opened to reveal the child.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_expanded() const;

  /** The text of the expanders label.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::ustring > property_label() ;

/** The text of the expanders label.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_label() const;

  /** Whether an underline in the text indicates a mnemonic.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_use_underline() ;

/** Whether an underline in the text indicates a mnemonic.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_use_underline() const;

  /** Whether the text in the label is Pango markup.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_use_markup() ;

/** Whether the text in the label is Pango markup.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_use_markup() const;

  /** A widget to display instead of the usual expander label.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Widget* > property_label_widget() ;

/** A widget to display instead of the usual expander label.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Widget* > property_label_widget() const;

  /** When this property is <tt>true</tt>, the expander will resize the toplevel
   * widget containing the expander upon expanding and collapsing.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_resize_toplevel() ;

/** When this property is <tt>true</tt>, the expander will resize the toplevel
   * widget containing the expander upon expanding and collapsing.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_resize_toplevel() const;

  /** The child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Widget* > property_child() ;

/** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Widget* > property_child() const;


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
   * @relates Gtk::Expander
   */
  GTKMM_API
  Gtk::Expander* wrap(GtkExpander* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_EXPANDER_H */

