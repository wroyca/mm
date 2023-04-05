// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_IMAGE_H
#define _GTKMM_IMAGE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/pixbuf.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkImage = struct _GtkImage;
using GtkImageClass = struct _GtkImageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Image_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Image : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Image CppObjectType;
    typedef Image_Class CppClassType;
    typedef GtkImage BaseObjectType;
    typedef GtkImageClass BaseClassType;
#endif

    Image (Image&& src) noexcept;
    auto
    operator= (Image&& src) noexcept -> Image&;

    Image (const Image&) = delete;
    auto
    operator= (const Image&) -> Image& = delete;

    ~Image () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Image_Class;
    static CppClassType image_class_;

  protected:
    explicit Image (const glib::ConstructParams& construct_params);
    explicit Image (GtkImage* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkImage*
    {
      return reinterpret_cast<GtkImage*> (gobject_);
    }

    auto
    gobj () const -> const GtkImage*
    {
      return reinterpret_cast<GtkImage*> (gobject_);
    }

  private:
  public:
    enum class Type
    {
      EMPTY,
      ICON_NAME,
      GICON,
      PAINTABLE
    };

    Image ();

    explicit Image (const std::string& file);

    explicit Image (const glib::RefPtr<gdk::Pixbuf>& pixbuf);

    explicit Image (const glib::RefPtr<gdk::Paintable>& paintable);

    explicit Image (const glib::RefPtr<gio::Icon>& gicon);

    auto
    set (const std::string& filename) -> void;

    auto
    set_from_resource (const std::string& resource_path) -> void;

    auto
    set (const glib::RefPtr<gdk::Pixbuf>& pixbuf) -> void;

    auto
    set (const glib::RefPtr<gdk::Paintable>& paintable) -> void;

    auto
    set (const glib::RefPtr<const gio::Icon>& icon) -> void;

    auto
    set_from_icon_name (const glib::ustring& icon_name) -> void;

    auto
    clear () -> void;

    auto
    get_storage_type () const -> Type;

    auto
    get_paintable () -> glib::RefPtr<gdk::Paintable>;

    auto
    get_paintable () const -> glib::RefPtr<const gdk::Paintable>;

    auto
    set_icon_size (IconSize icon_size) -> void;

    auto
    get_icon_size () const -> IconSize;

    auto
    get_gicon () -> glib::RefPtr<gio::Icon>;

    auto
    get_gicon () const -> glib::RefPtr<const gio::Icon>;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_pixel_size () const -> int;

    auto
    set_pixel_size (int pixel_size) -> void;

    auto
    property_file () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_file () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_icon_size () -> glib::PropertyProxy<IconSize>;

    auto
    property_icon_size () const -> glib::PropertyProxy_ReadOnly<IconSize>;

    auto
    property_pixel_size () -> glib::PropertyProxy<int>;

    auto
    property_pixel_size () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_storage_type () const -> glib::PropertyProxy_ReadOnly<Type>;

    auto
    property_gicon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>;

    auto
    property_gicon () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>;

    auto
    property_use_fallback () -> glib::PropertyProxy<bool>;

    auto
    property_use_fallback () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_resource () -> glib::PropertyProxy<std::string>;

    auto
    property_resource () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_paintable () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>;

    auto
    property_paintable () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Image::Type>
    : public glib::Value_Enum<gtk::Image::Type>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkImage* object, bool take_copy = false) -> gtk::Image*;
} // namespace glib

#endif
