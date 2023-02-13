
#ifndef _GTKMM_CELLRENDERERPIXBUF_H
#define _GTKMM_CELLRENDERERPIXBUF_H


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

#include <libmm-gtk/cellrenderer.hxx>
#include <libmm-gdk/pixbuf.hxx>
#include <libmm-gdk/texture.hxx>
#include <libmm-gio/icon.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererPixbuf = struct _GtkCellRendererPixbuf;
using GtkCellRendererPixbufClass = struct _GtkCellRendererPixbufClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellRendererPixbuf_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Renders a pixbuf in a cell.
 * A CellRendererPixbuf can be used to render an image in a cell. It allows you to render either a
 * given Pixbuf (set via the pixbuf property) or a named icon (set via the icon_name property).
 *
 * To support the tree view, CellRendererPixbuf also supports rendering two alternative pixbufs, when
 * the is_expanded property is true. If the is_expanded property is true and the pixbuf_expander_open
 * property is set to a pixbuf, it renders that pixbuf. If the is_expanded property is false and the *
 * pixbuf_expander_closed property is set to a pixbuf, it renders that one.
 *
 * @ingroup TreeView
 */

class GTKMM_API CellRendererPixbuf : public CellRenderer
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellRendererPixbuf CppObjectType;
  typedef CellRendererPixbuf_Class CppClassType;
  typedef GtkCellRendererPixbuf BaseObjectType;
  typedef GtkCellRendererPixbufClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CellRendererPixbuf(CellRendererPixbuf&& src) noexcept;
  auto operator=(CellRendererPixbuf&& src) noexcept -> CellRendererPixbuf&;

  // noncopyable
  CellRendererPixbuf(const CellRendererPixbuf&) = delete;
  auto operator=(const CellRendererPixbuf&) -> CellRendererPixbuf& = delete;

  ~CellRendererPixbuf() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class CellRendererPixbuf_Class;
  static CppClassType cellrendererpixbuf_class_;

protected:
  explicit CellRendererPixbuf(const Glib::ConstructParams& construct_params);
  explicit CellRendererPixbuf(GtkCellRendererPixbuf* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellRendererPixbuf*       { return reinterpret_cast<GtkCellRendererPixbuf*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellRendererPixbuf* { return reinterpret_cast<GtkCellRendererPixbuf*>(gobject_); }

private:

public:

  CellRendererPixbuf();

  /**
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixbuf() -> Glib::PropertyProxy_WriteOnly< Glib::RefPtr<Gdk::Pixbuf> > ;


  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixbuf_expander_open() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixbuf_expander_open() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> >;

  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixbuf_expander_closed() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixbuf_expander_closed() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> >;

  /** The `Gtk::IconSize` value that specifies the size of the rendered icon.
   *
   * Default value: Gtk::IconSize::INHERIT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_size() -> Glib::PropertyProxy< Gtk::IconSize > ;

/** The `Gtk::IconSize` value that specifies the size of the rendered icon.
   *
   * Default value: Gtk::IconSize::INHERIT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_size() const -> Glib::PropertyProxy_ReadOnly< Gtk::IconSize >;

  /** The name of the themed icon to display.
   * This property only has an effect if not overridden by the "pixbuf" property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The name of the themed icon to display.
   * This property only has an effect if not overridden by the "pixbuf" property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The GIcon representing the icon to display.
   * If the icon theme is changed, the image will be updated
   * automatically.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gicon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> > ;

/** The GIcon representing the icon to display.
   * If the icon theme is changed, the image will be updated
   * automatically.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gicon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >;

  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_texture() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Texture> > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_texture() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Texture> >;


  auto _property_renderable() -> Glib::PropertyProxy_Base override;


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
   * @relates Gtk::CellRendererPixbuf
   */
  GTKMM_API
  auto wrap(GtkCellRendererPixbuf* object, bool take_copy = false) -> Gtk::CellRendererPixbuf*;
} //namespace Glib


#endif /* _GTKMM_CELLRENDERERPIXBUF_H */

