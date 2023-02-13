
#ifndef _GTKMM_IMAGE_H
#define _GTKMM_IMAGE_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/widget.hpp>
#include <mm/gdk/pixbuf.hpp>
#include <mm/gio/icon.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkImage = struct _GtkImage;
using GtkImageClass = struct _GtkImageClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Image_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** A widget displaying an image.
 *
 * The %Gtk::Image widget displays an image. Various kinds of object can be
 * displayed as an image; most typically, you would load a Gdk::Texture (which
 * implements Gdk::Paintable) from a file, and then display that.
 *
 * The %Image widget looks like this:
 * @image html image1.png
 *
 * @ingroup Widgets
 */

class GTKMM_API Image : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Image CppObjectType;
  typedef Image_Class CppClassType;
  typedef GtkImage BaseObjectType;
  typedef GtkImageClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Image(Image&& src) noexcept;
  auto operator=(Image&& src) noexcept -> Image&;

  // noncopyable
  Image(const Image&) = delete;
  auto operator=(const Image&) -> Image& = delete;

  ~Image() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Image_Class;
  static CppClassType image_class_;

protected:
  explicit Image(const Glib::ConstructParams& construct_params);
  explicit Image(GtkImage* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkImage*       { return reinterpret_cast<GtkImage*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkImage* { return reinterpret_cast<GtkImage*>(gobject_); }

private:

public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Type EMPTY
   * There is no image displayed by the widget.
   *
   *  @var Type ICON_NAME
   * The widget contains a named icon.
   *
   *  @var Type GICON
   * The widget contains a `Gio::Icon`.
   *
   *  @var Type PAINTABLE
   * The widget contains a `Gdk::Paintable`.
   *
   *  @enum Type
   *
   * Describes the image data representation used by a Gtk::Image.
   *
   * If you want to get the image from the widget, you can only get the
   * currently-stored representation; for instance, if the Gtk::Image::get_storage_type()
   * returns Gtk::Image::Type::PAINTABLE, then you can call Gtk::Image::get_paintable().
   *
   * For empty images, you can request any storage type (call any of the "get"
   * functions), but they will all return <tt>nullptr</tt> values.
   *
   * @ingroup gtkmmEnums
   */
  enum class Type
  {
    EMPTY,
    ICON_NAME,
    GICON,
    PAINTABLE
  };


  Image();

  /** Creates an Image widget displaying the file @a filename.
   * If the file isn't found or can't be loaded, the resulting Gtk::Image will display a "broken image" icon.
   *
   * If you need to detect failures to load the file, use Gdk::Pixbuf::create_from_file() to load the file yourself,
   * then create the GtkImage from the pixbuf.
   *
   * The storage type (get_storage_type()) of the returned image is not defined.
   * It will be whatever is appropriate for displaying the file.
   */
    explicit Image(const std::string& file);


  // gtk_image_new_from_pixbuf() does more than just call g_object_new().
  // GtkImage has no "pixbuf" property.
  /** Creates a new Image widget displaying @a pixbuf.
   * Note that this just creates an GtkImage from the pixbuf. The Gtk::Image created will not react to state changes.
   * Should you want that, you should use the default constructor and set_from_icon_name().
   */
  explicit Image(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);


  /** Creates a new Gtk::Image displaying @a paintable.
   *
   * The Gtk::Image will track changes to the @a paintable and update
   * its size and contents in response to it.
   *
   * @newin{3,94}
   *
   * @param paintable A Gdk::Paintable, or an emtpy Glib::RefPtr.
   * @return A new Gtk::Image.
   */
    explicit Image(const Glib::RefPtr<Gdk::Paintable>& paintable);


  /** Creates a `Gtk::Image` displaying an icon from the current icon theme.
   *
   * If the icon name isn’t known, a “broken image” icon will be
   * displayed instead. If the current icon theme is changed, the icon
   * will be updated appropriately.
   *
   * @newin{3,24}
   *
   * @param icon An icon.
   * @return A new `Gtk::Image` displaying the themed icon.
   */

    explicit Image(const Glib::RefPtr<Gio::Icon>& gicon);


  // We don't wrap gtk_image_new_from_resource() and gtk_image_new_from_icon_name()
  // to avoid a clash with the from_filename constructor.
  // But we do wrap gtk_image_set_from_resource() and gtk_image_set_from_icon_name().


  /** See the Image::Image(const std::string& file) constructor for details.
   *
   * @param filename A filename.
   */
  void set(const std::string& filename);

  /** Sets a `Gtk::Image` to show a resource.
   *
   * See new_from_resource() for details.
   *
   * @param resource_path A resource path.
   */
  void set_from_resource(const std::string& resource_path);

  /** See the Image::Image(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf) constructor for details.
   *
   * @param pixbuf A #Gdk::Pixbuf.
   */
  void set(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);

  /** Sets a `Gtk::Image` to show a `Gdk::Paintable`.
   *
   * See new_from_paintable() for details.
   *
   * @param paintable A `Gdk::Paintable`.
   */
  void set(const Glib::RefPtr<Gdk::Paintable>& paintable);

  /** Sets a `Gtk::Image` to show a `Gio::Icon`.
   *
   * See new_from_gicon() for details.
   *
   * @param icon An icon.
   */
  void set(const Glib::RefPtr<const Gio::Icon>& icon);


  /** Causes the Image to display an icon from the current icon theme.
   * If the icon name isn't known, a "broken image" icon will be
   * displayed instead.  If the current icon theme is changed, the icon
   * will be updated appropriately.
   *
   * @newin{2,6}
   *
   * @param icon_name An icon name.
   */
  void set_from_icon_name(const Glib::ustring& icon_name);


  /** Resets the image to be empty.
   */
  void clear();


  /** Gets the type of representation being used by the `Gtk::Image`
   * to store image data.
   *
   * If the `Gtk::Image` has no image data, the return value will
   * be Gtk::Image::Type::EMPTY.
   *
   * @return Image representation being used.
   */
  auto get_storage_type() const -> Type;


  /** Gets the image `Gdk::Paintable` being displayed by the `Gtk::Image`.
   *
   * The storage type of the image must be Gtk::Image::Type::EMPTY or
   * Gtk::Image::Type::PAINTABLE (see get_storage_type()).
   * The caller of this function does not own a reference to the
   * returned paintable.
   *
   * @return The displayed paintable.
   */
  auto get_paintable() -> Glib::RefPtr<Gdk::Paintable>;

  /** Gets the image `Gdk::Paintable` being displayed by the `Gtk::Image`.
   *
   * The storage type of the image must be Gtk::Image::Type::EMPTY or
   * Gtk::Image::Type::PAINTABLE (see get_storage_type()).
   * The caller of this function does not own a reference to the
   * returned paintable.
   *
   * @return The displayed paintable.
   */
  auto get_paintable() const -> Glib::RefPtr<const Gdk::Paintable>;


  /** Suggests an icon size to the theme for named icons.
   *
   * @param icon_size The new icon size.
   */
  void set_icon_size(IconSize icon_size);

  /** Gets the icon size used by the @a image when rendering icons.
   *
   * @return The image size used by icons.
   */
  auto get_icon_size() const -> IconSize;


  /** Gets the `Gio::Icon` being displayed by the `Gtk::Image`.
   *
   * The storage type of the image must be Gtk::Image::Type::EMPTY or
   * Gtk::Image::Type::GICON (see get_storage_type()).
   * The caller of this function does not own a reference to the
   * returned `Gio::Icon`.
   *
   * @return A `Gio::Icon`.
   */
  auto get_gicon() -> Glib::RefPtr<Gio::Icon>;

  /** Gets the `Gio::Icon` being displayed by the `Gtk::Image`.
   *
   * The storage type of the image must be Gtk::Image::Type::EMPTY or
   * Gtk::Image::Type::GICON (see get_storage_type()).
   * The caller of this function does not own a reference to the
   * returned `Gio::Icon`.
   *
   * @return A `Gio::Icon`.
   */
  auto get_gicon() const -> Glib::RefPtr<const Gio::Icon>;

  /** Gets the icon name and size being displayed by the `Gtk::Image`.
   *
   * The storage type of the image must be Gtk::Image::Type::EMPTY or
   * Gtk::Image::Type::ICON_NAME (see get_storage_type()).
   * The returned string is owned by the `Gtk::Image` and should not
   * be freed.
   *
   * @return The icon name.
   */
  auto get_icon_name() const -> Glib::ustring;


  /** Gets the pixel size used for named icons.
   *
   * @return The pixel size used for named icons.
   */
  auto get_pixel_size() const -> int;

  /** Sets the pixel size to use for named icons.
   *
   * If the pixel size is set to a value != -1, it is used instead
   * of the icon size set by set_from_icon_name().
   *
   * @param pixel_size The new pixel size.
   */
  void set_pixel_size(int pixel_size);

  /** The `GFile to display.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() -> Glib::PropertyProxy< Glib::ustring > ;

/** The `GFile to display.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The symbolic size to display icons at.
   *
   * Default value: Gtk::IconSize::INHERIT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_size() -> Glib::PropertyProxy< IconSize > ;

/** The symbolic size to display icons at.
   *
   * Default value: Gtk::IconSize::INHERIT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_size() const -> Glib::PropertyProxy_ReadOnly< IconSize >;

  /** The size in pixels to display icons at.
   *
   * If set to a value != -1, this property overrides the
   * property_icon_size() property for images of type
   * `Gtk::Image::Type::ICON_NAME`.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixel_size() -> Glib::PropertyProxy< int > ;

/** The size in pixels to display icons at.
   *
   * If set to a value != -1, this property overrides the
   * property_icon_size() property for images of type
   * `Gtk::Image::Type::ICON_NAME`.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixel_size() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The name of the icon in the icon theme.
   *
   * If the icon theme is changed, the image will be updated automatically.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The name of the icon in the icon theme.
   *
   * If the icon theme is changed, the image will be updated automatically.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The representation being used for image data.
   *
   * Default value: Gtk::Image::Type::EMPTY
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_storage_type() const -> Glib::PropertyProxy_ReadOnly< Type >;


  /** The `Gio::Icon` displayed in the GtkImage.
   *
   * For themed icons, If the icon theme is changed, the image will be updated
   * automatically.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gicon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> > ;

/** The `Gio::Icon` displayed in the GtkImage.
   *
   * For themed icons, If the icon theme is changed, the image will be updated
   * automatically.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gicon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >;

  /** Whether the icon displayed in the `Gtk::Image` will use
   * standard icon names fallback.
   *
   * The value of this property is only relevant for images of type
   * Gtk::Image::Type::ICON_NAME and Gtk::Image::Type::GICON.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_fallback() -> Glib::PropertyProxy< bool > ;

/** Whether the icon displayed in the `Gtk::Image` will use
   * standard icon names fallback.
   *
   * The value of this property is only relevant for images of type
   * Gtk::Image::Type::ICON_NAME and Gtk::Image::Type::GICON.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_fallback() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** A path to a resource file to display.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resource() -> Glib::PropertyProxy< std::string > ;

/** A path to a resource file to display.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resource() const -> Glib::PropertyProxy_ReadOnly< std::string >;

  /** The `Gdk::Paintable` to display.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paintable() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Paintable> > ;

/** The `Gdk::Paintable` to display.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paintable() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Paintable> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Image::Type> : public Glib::Value_Enum<Gtk::Image::Type>
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
   * @relates Gtk::Image
   */
  GTKMM_API
  auto wrap(GtkImage* object, bool take_copy = false) -> Gtk::Image*;
} //namespace Glib


#endif /* _GTKMM_IMAGE_H */

