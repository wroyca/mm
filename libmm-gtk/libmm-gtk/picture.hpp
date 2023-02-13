
#ifndef _GTKMM_PICTURE_H
#define _GTKMM_PICTURE_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2018 The gtkmm Development Team
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

#include <mm/gtk/widget.hpp>
#include <mm/gdk/pixbuf.hpp>
#include <mm/gio/file.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Picture_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** A widget displaying a Gdk::Paintable.
 *
 * The %Gtk::Picture widget displays a Gdk::Paintable. Many convenience functions
 * are provided to make pictures simple to use. For example, if you want to load
 * an image from a file, and then display that, there’s a convenience method
 * to do this: set_filename() or the constructor taking a filename parameter.
 *
 * If the file isn’t loaded successfully, the picture will contain a
 * “broken image” icon similar to that used in many web browsers.
 * If you want to handle errors in loading the file yourself,
 * for example by displaying an error message, then load the file with
 * Gdk::Texture::create_from_file(), then create the %Gtk::Picture from the texture.
 *
 * Sometimes an application will want to avoid depending on external data
 * files, such as image files. See the documentation of Gio::Resource for details.
 * In this case, set_resource() should be used.
 *
 * @newin{3,94}
 *
 * @ingroup Widgets
 */

class GTKMM_API Picture : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Picture CppObjectType;
  typedef Picture_Class CppClassType;
  typedef GtkPicture BaseObjectType;
  typedef GtkPictureClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Picture(Picture&& src) noexcept;
  auto operator=(Picture&& src) noexcept -> Picture&;

  // noncopyable
  Picture(const Picture&) = delete;
  auto operator=(const Picture&) -> Picture& = delete;

  ~Picture() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Picture_Class;
  static CppClassType picture_class_;

protected:
  explicit Picture(const Glib::ConstructParams& construct_params);
  explicit Picture(GtkPicture* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkPicture*       { return reinterpret_cast<GtkPicture*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPicture* { return reinterpret_cast<GtkPicture*>(gobject_); }

private:


public:
  Picture();

  /** Creates a new %Picture displaying @a paintable.
   *
   * The %Picture will track changes to the @a paintable and update
   * its size and contents in response to it.
   *
   * @param paintable A Gdk::Paintable or an empty Glib::RefPtr.
   */
    explicit Picture(const Glib::RefPtr<Gdk::Paintable>& paintable);


  // gtk_picture_new_for_pixbuf() does more than just call g_object_new().
  // GtkPicture has no "pixbuf" property.
  /** Creates a new %Picture widget displaying @a pixbuf.
   *
   * This constructor calls Picture(const Glib::RefPtr<Gdk::Paintable>& paintable).
   * See that constructor for details.
   *
   * The pixbuf must not be modified after passing it to this constructor.
   *
   * @param pixbuf A Gdk::Pixbuf or an empty Glib::RefPtr.
   */
  explicit Picture(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);


  /** Creates a new %Picture displaying the given @a file.
   *
   * If the file isn’t found or can’t be loaded, the resulting %Picture will be empty.
   *
   * If you need to detect failures in loading the file, use
   * Gdk::Texture::create_from_file() to load the file yourself, then create
   * the %Gtk::Picture from the texture.
   *
   * @param file A Gio::File or an empty Glib::RefPtr.
   */
    explicit Picture(const Glib::RefPtr<Gio::File>& file);


  // gtk_picture_new_for_filename() does more than just call g_object_new().
  // GtkPicture has no "filename" property.
  /** Creates a new %Picture displaying the file @a filename.
   *
   * This constructor calls Picture(const Glib::RefPtr<Gio::File>& file).
   * See that constructor for details.
   *
   * @param filename A filename or an empty string.
   */
  explicit Picture(const std::string& filename);


  // We don't wrap gtk_picture_new_for_resource() to avoid a clash with
  // the for_filename constructor. But we do wrap gtk_picture_set_resource().


  /** Makes @a self display the given @a paintable.
   *
   * If @a paintable is <tt>nullptr</tt>, nothing will be displayed.
   *
   * See new_for_paintable() for details.
   *
   * @param paintable A `Gdk::Paintable`.
   */
  void set_paintable(const Glib::RefPtr<Gdk::Paintable>& paintable);

  /** Gets the `Gdk::Paintable` being displayed by the `Gtk::Picture`.
   *
   * @return The displayed paintable.
   */
  auto get_paintable() -> Glib::RefPtr<Gdk::Paintable>;

  /** Gets the `Gdk::Paintable` being displayed by the `Gtk::Picture`.
   *
   * @return The displayed paintable.
   */
  auto get_paintable() const -> Glib::RefPtr<const Gdk::Paintable>;


  /** Makes @a self load and display @a file.
   *
   * See new_for_file() for details.
   *
   * @param file A `Gio::File`.
   */
  void set_file(const Glib::RefPtr<const Gio::File>& file);

  /** Gets the `Gio::File` currently displayed if @a self is displaying a file.
   *
   * If @a self is not displaying a file, for example when
   * set_paintable() was used, then <tt>nullptr</tt> is returned.
   *
   * @return The `Gio::File` displayed by @a self.
   */
  auto get_file() -> Glib::RefPtr<Gio::File>;

  /** Gets the `Gio::File` currently displayed if @a self is displaying a file.
   *
   * If @a self is not displaying a file, for example when
   * set_paintable() was used, then <tt>nullptr</tt> is returned.
   *
   * @return The `Gio::File` displayed by @a self.
   */
  auto get_file() const -> Glib::RefPtr<const Gio::File>;


  /** Makes @a self load and display the given @a filename.
   *
   * This is a utility function that calls set_file().
   *
   * @param filename The filename to play.
   */
  void set_filename(const std::string& filename);

  /** Makes @a self load and display the resource at the given
   *  @a resource_path.
   *
   * This is a utility function that calls set_file().
   *
   * @param resource_path The resource to set.
   */
  void set_resource(const std::string& resource_path);

  /** Sets a `Gtk::Picture` to show a `Gdk::Pixbuf`.
   *
   * See new_for_pixbuf() for details.
   *
   * This is a utility function that calls set_paintable().
   *
   * @param pixbuf A `Gdk::Pixbuf`.
   */
  void set_pixbuf(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);


#ifndef GTKMM_DISABLE_DEPRECATED

  /** If set to <tt>true</tt>, the @a self will render its contents according to
   * their aspect ratio.
   *
   * That means that empty space may show up at the top/bottom or
   * left/right of @a self.
   *
   * If set to <tt>false</tt> or if the contents provide no aspect ratio,
   * the contents will be stretched over the picture's whole area.
   *
   * Deprecated: 4.8: Use set_content_fit() instead. If still
   * used, this method will always set the property_content_fit()
   * property to `Gtk::ContentFit::CONTAIN` if @a keep_aspect_ratio is true,
   * otherwise it will set it to `Gtk::ContentFit::FILL`.
   *
   * @deprecated Use set_content_fit() instead.
   *
   * @param keep_aspect_ratio Whether to keep aspect ratio.
   */
  void set_keep_aspect_ratio(bool keep_aspect_ratio =  true);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns whether the `Gtk::Picture` preserves its contents aspect ratio.
   *
   * Deprecated: 4.8: Use get_content_fit() instead. This will
   * now return <tt>false</tt> only if property_content_fit() is
   * `Gtk::ContentFit::FILL`. Returns <tt>true</tt> otherwise.
   *
   * @deprecated Use get_content_fit() instead.
   *
   * @return <tt>true</tt> if the self tries to keep the contents' aspect ratio.
   */
  auto get_keep_aspect_ratio() const -> bool;
#endif // GTKMM_DISABLE_DEPRECATED


  /** If set to <tt>true</tt>, the @a self can be made smaller than its contents.
   *
   * The contents will then be scaled down when rendering.
   *
   * If you want to still force a minimum size manually, consider using
   * Gtk::Widget::set_size_request().
   *
   * Also of note is that a similar function for growing does not exist
   * because the grow behavior can be controlled via
   * Gtk::Widget::set_halign() and Gtk::Widget::set_valign().
   *
   * @param can_shrink If @a self can be made smaller than its contents.
   */
  void set_can_shrink(bool can_shrink =  true);

  /** Returns whether the `Gtk::Picture` respects its contents size.
   *
   * @return <tt>true</tt> if the picture can be made smaller than its contents.
   */
  auto get_can_shrink() const -> bool;


  /** Sets how the content should be resized to fit the `Gtk::Picture`.
   *
   * See Gtk::ContentFit for details.
   *
   * @newin{4,8}
   *
   * @param content_fit The content fit mode.
   */
  void set_content_fit(ContentFit content_fit);

  /** Returns the fit mode for the content of the `Gtk::Picture`.
   *
   * See Gtk::ContentFit for details.
   *
   * @newin{4,8}
   *
   * @return The content fit mode.
   */
  auto get_content_fit() const -> ContentFit;


  /** Sets an alternative textual description for the picture contents.
   *
   * It is equivalent to the "alt" attribute for images on websites.
   *
   * This text will be made available to accessibility tools.
   *
   * If the picture cannot be described textually, set this property to <tt>nullptr</tt>.
   *
   * @param alternative_text A textual description of the contents.
   */
  void set_alternative_text(const Glib::ustring& alternative_text);

  /** Gets the alternative textual description of the picture.
   *
   * The returned string will be <tt>nullptr</tt> if the picture cannot be described textually.
   *
   * @return The alternative textual description of @a self.
   */
  auto get_alternative_text() const -> Glib::ustring;

  /** The `Gdk::Paintable` to be displayed by this `Gtk::Picture`.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paintable() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Paintable> > ;

/** The `Gdk::Paintable` to be displayed by this `Gtk::Picture`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paintable() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Paintable> >;

  /** The `Gio::File` that is displayed or <tt>nullptr</tt> if none.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() -> Glib::PropertyProxy< Glib::RefPtr<Gio::File> > ;

/** The `Gio::File` that is displayed or <tt>nullptr</tt> if none.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::File> >;

  /** The alternative textual description for the picture.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_alternative_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The alternative textual description for the picture.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_alternative_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


#ifndef GTKMM_DISABLE_DEPRECATED

/** Whether the GtkPicture will render its contents trying to preserve the aspect
   * ratio.
   *
   * Deprecated: 4.8: Use property_content_fit() instead.
   *
   * @deprecated Use property_content_fit() instead.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_keep_aspect_ratio() -> Glib::PropertyProxy< bool > ;

/** Whether the GtkPicture will render its contents trying to preserve the aspect
   * ratio.
   *
   * Deprecated: 4.8: Use property_content_fit() instead.
   *
   * @deprecated Use property_content_fit() instead.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_keep_aspect_ratio() const -> Glib::PropertyProxy_ReadOnly< bool >;

#endif // GTKMM_DISABLE_DEPRECATED

  /** If the `Gtk::Picture` can be made smaller than the natural size of its contents.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_shrink() -> Glib::PropertyProxy< bool > ;

/** If the `Gtk::Picture` can be made smaller than the natural size of its contents.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_shrink() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** How the content should be resized to fit inside the `Gtk::Picture`.
   *
   * @newin{4,8}
   *
   * Default value: Gtk::ContentFit::CONTAIN
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content_fit() -> Glib::PropertyProxy< ContentFit > ;

/** How the content should be resized to fit inside the `Gtk::Picture`.
   *
   * @newin{4,8}
   *
   * Default value: Gtk::ContentFit::CONTAIN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content_fit() const -> Glib::PropertyProxy_ReadOnly< ContentFit >;


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
   * @relates Gtk::Picture
   */
  GTKMM_API
  auto wrap(GtkPicture* object, bool take_copy = false) -> Gtk::Picture*;
} //namespace Glib


#endif /* _GTKMM_PICTURE_H */

