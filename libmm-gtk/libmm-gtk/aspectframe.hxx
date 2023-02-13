
#ifndef _GTKMM_ASPECTFRAME_H
#define _GTKMM_ASPECTFRAME_H


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
using GtkAspectFrame = struct _GtkAspectFrame;
using GtkAspectFrameClass = struct _GtkAspectFrameClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API AspectFrame_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A frame that constrains its child to a particular aspect ratio.
 *
 * The %Gtk::AspectFrame is useful when you want pack a widget so that it can
 * resize but always retains the same aspect ratio.  For instance, one might
 * be drawing a small preview of a larger image. The frame
 * will be "shrink-wrapped" to the size of the child.
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API AspectFrame : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef AspectFrame CppObjectType;
  typedef AspectFrame_Class CppClassType;
  typedef GtkAspectFrame BaseObjectType;
  typedef GtkAspectFrameClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  AspectFrame(AspectFrame&& src) noexcept;
  auto operator=(AspectFrame&& src) noexcept -> AspectFrame&;

  // noncopyable
  AspectFrame(const AspectFrame&) = delete;
  auto operator=(const AspectFrame&) -> AspectFrame& = delete;

  ~AspectFrame() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class AspectFrame_Class;
  static CppClassType aspectframe_class_;

protected:
  explicit AspectFrame(const Glib::ConstructParams& construct_params);
  explicit AspectFrame(GtkAspectFrame* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkAspectFrame*       { return reinterpret_cast<GtkAspectFrame*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAspectFrame* { return reinterpret_cast<GtkAspectFrame*>(gobject_); }

private:


public:

  /** Constructor to create a new %AspectFrame object.
   * @param xalign Horizontal alignment of the child within the allocation of this
   *   %AspectFrame.  For possible values, see Gtk::Align.
   * @param yalign Vertical alignment of the child within the allocation of this
   *   %AspectFrame. For possible values, see Gtk::Align.
   * @param ratio The desired aspect ratio.
   * @param obey_child If <tt>true</tt>, @a ratio is ignored and the aspect ratio
   *   is taken from the requisition of the child.
   */
    explicit AspectFrame(Align xalign =  Gtk::Align::CENTER, Align yalign =  Gtk::Align::CENTER, float ratio =  1.0, bool obey_child =  false);


  /** Constructor to create a new %AspectFrame object.
   * @param xalign Horizontal alignment of the child within the allocation of this
   *   %AspectFrame.  This ranges from 0.0 (left aligned) to 1.0 (right aligned).
   * @param yalign Vertical alignment of the child within the allocation of this
   *   %AspectFrame. This ranges from 0.0 (top aligned) to 1.0 (bottom aligned).
   * @param ratio The desired aspect ratio.
   * @param obey_child If <tt>true</tt>, @a ratio is ignored and the aspect ratio
   *   is taken from the requisition of the child.
   */
    explicit AspectFrame(float xalign, float yalign, float ratio =  1.0, bool obey_child =  false);


  /** Sets the horizontal alignment of the child within the allocation
   * of this %AspectFrame.
   * @param xalign Horizontal alignment of the child within the allocation of
   *   this %AspectFrame. For possible values, see Gtk::Align.
   */
  void set_xalign(Align xalign);

  /** Sets the horizontal alignment of the child within the allocation
   * of the `Gtk::AspectFrame`.
   *
   * @param xalign Horizontal alignment, from 0.0 (left aligned) to 1.0 (right aligned).
   */
  void set_xalign(float xalign);

  /** Returns the horizontal alignment of the child within the
   * allocation of the `Gtk::AspectFrame`.
   *
   * @return The horizontal alignment.
   */
  auto get_xalign() const -> float;


  /** Sets the vertical alignment of the child within the allocation
   * of this %AspectFrame.
   * @param yalign Vertical alignment of the child within the allocation of
   *   this %AspectFrame. For possible values, see Gtk::Align.
   */
  void set_yalign(Align yalign);

  /** Sets the vertical alignment of the child within the allocation
   * of the `Gtk::AspectFrame`.
   *
   * @param yalign Horizontal alignment, from 0.0 (top aligned) to 1.0 (bottom aligned).
   */
  void set_yalign(float yalign);

  /** Returns the vertical alignment of the child within the
   * allocation of the `Gtk::AspectFrame`.
   *
   * @return The vertical alignment.
   */
  auto get_yalign() const -> float;

  /** Sets the desired aspect ratio of the child.
   *
   * @param ratio Aspect ratio of the child.
   */
  void set_ratio(float ratio);

  /** Returns the desired aspect ratio of the child.
   *
   * @return The desired aspect ratio.
   */
  auto get_ratio() const -> float;

  /** Sets whether the aspect ratio of the child's size
   * request should override the set aspect ratio of
   * the `Gtk::AspectFrame`.
   *
   * @param obey_child If <tt>true</tt>, @a ratio is ignored, and the aspect
   * ratio is taken from the requistion of the child.
   */
  void set_obey_child(bool obey_child =  true);

  /** Returns whether the child's size request should override
   * the set aspect ratio of the `Gtk::AspectFrame`.
   *
   * @return Whether to obey the child's size request.
   */
  auto get_obey_child() const -> bool;

  /** Sets the child widget of @a self.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a self.
   *
   * @return The child widget of self@.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a self.
   *
   * @return The child widget of self@.
   */
  auto get_child() const -> const Widget*;

  /** The horizontal alignment of the child.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() -> Glib::PropertyProxy< float > ;

/** The horizontal alignment of the child.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() const -> Glib::PropertyProxy_ReadOnly< float >;

  /** The vertical alignment of the child.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_yalign() -> Glib::PropertyProxy< float > ;

/** The vertical alignment of the child.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_yalign() const -> Glib::PropertyProxy_ReadOnly< float >;

  /** The aspect ratio to be used by the `Gtk::AspectFrame`.
   *
   * This property is only used if
   * property_obey_child() is set to <tt>false</tt>.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ratio() -> Glib::PropertyProxy< float > ;

/** The aspect ratio to be used by the `Gtk::AspectFrame`.
   *
   * This property is only used if
   * property_obey_child() is set to <tt>false</tt>.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ratio() const -> Glib::PropertyProxy_ReadOnly< float >;

  /** Whether the `Gtk::AspectFrame` should use the aspect ratio of its child.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_obey_child() -> Glib::PropertyProxy< bool > ;

/** Whether the `Gtk::AspectFrame` should use the aspect ratio of its child.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_obey_child() const -> Glib::PropertyProxy_ReadOnly< bool >;

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
   * @relates Gtk::AspectFrame
   */
  GTKMM_API
  auto wrap(GtkAspectFrame* object, bool take_copy = false) -> Gtk::AspectFrame*;
} //namespace Glib


#endif /* _GTKMM_ASPECTFRAME_H */

