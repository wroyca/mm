
#ifndef _GTKMM_FRAME_H
#define _GTKMM_FRAME_H


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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFrame = struct _GtkFrame;
using GtkFrameClass = struct _GtkFrameClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Frame_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A Gtk::Widget with a decorative frame and optional label.
 *
 * The Frame widget surrounds its single child with a decorative frame and
 * an optional label.  If present, the label is drawn in a gap in the top
 * side of the frame. The position of the label can be controlled with
 * set_label_align().
 *
 * A Frame widget looks like this:
 * @image html frame1.png
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API Frame : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Frame CppObjectType;
  typedef Frame_Class CppClassType;
  typedef GtkFrame BaseObjectType;
  typedef GtkFrameClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Frame(Frame&& src) noexcept;
  auto operator=(Frame&& src) noexcept -> Frame&;

  // noncopyable
  Frame(const Frame&) = delete;
  auto operator=(const Frame&) -> Frame& = delete;

  ~Frame() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Frame_Class;
  static CppClassType frame_class_;

protected:
  explicit Frame(const Glib::ConstructParams& construct_params);
  explicit Frame(GtkFrame* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkFrame*       { return reinterpret_cast<GtkFrame*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFrame* { return reinterpret_cast<GtkFrame*>(gobject_); }

private:

public:

  Frame();
    explicit Frame(const Glib::ustring& label);


  /** Set the label to appear in the top edge of the frame.
   * Label alignment defaults to the upper left corner of the frame.
   */
  void set_label(const Glib::ustring& label);
  void unset_label();

  /** Returns the frame labels text.
   *
   * If the frame's label widget is not a `Gtk::Label`, <tt>nullptr</tt>
   * is returned.
   *
   * @return The text in the label, or <tt>nullptr</tt> if there
   * was no label widget or the label widget was not a `Gtk::Label`.
   * This string is owned by GTK and must not be modified or freed.
   */
  auto get_label() const -> Glib::ustring;


  /** Sets the label widget for the frame.
   *
   * This is the widget that will appear embedded in the top edge
   * of the frame as a title.
   *
   * @param label_widget The new label widget.
   */
  void set_label_widget(Widget& label_widget);

  /** Retrieves the label widget for the frame.
   *
   * @return The label widget.
   */
  auto get_label_widget() -> Widget*;

  /** Retrieves the label widget for the frame.
   *
   * @return The label widget.
   */
  auto get_label_widget() const -> const Widget*;


  /** Sets the X alignment of the frame widget’s label.
   *
   * The default value for a newly created frame is 0.0.
   *
   * @param xalign The position of the label along the top edge
   * of the widget. A value of 0.0 represents left alignment;
   * 1.0 represents right alignment.
   */
  void set_label_align(float xalign =  0.0);

  /** Sets the X alignment of the frame widget’s label. The
   * default values for a newly created frame is Gtk::Align::START.
   *
   * @param xalign The position of the label along the top edge
   * of the widget. A value of Gtk::Align::START represents left alignment;
   * Gtk::Align::END represents right alignment.
   */
  void set_label_align(Align xalign);


  /** Retrieves the X alignment of the frame’s label.
   *
   * @return The frames X alignment.
   */
  auto get_label_align() const -> float;


  /** Sets the child widget of @a frame.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a frame.
   *
   * @return The child widget of @a frame.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a frame.
   *
   * @return The child widget of @a frame.
   */
  auto get_child() const -> const Widget*;

  /** Text of the frame's label.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** Text of the frame's label.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The horizontal alignment of the label.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label_xalign() -> Glib::PropertyProxy< double > ;

/** The horizontal alignment of the label.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label_xalign() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Widget to display in place of the usual frame label.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label_widget() -> Glib::PropertyProxy< Widget* > ;

/** Widget to display in place of the usual frame label.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** The child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


protected:


    virtual void compute_child_allocation_vfunc(Allocation& allocation);


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
   * @relates Gtk::Frame
   */
  GTKMM_API
  auto wrap(GtkFrame* object, bool take_copy = false) -> Gtk::Frame*;
} //namespace Glib


#endif /* _GTKMM_FRAME_H */

