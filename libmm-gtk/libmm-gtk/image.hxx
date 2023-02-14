// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_IMAGE_H
#define _GTKMM_IMAGE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/pixbuf.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkImage = struct _GtkImage;
using GtkImageClass = struct _GtkImageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Image_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Image : public Widget
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
    friend GTKMM_API class Image_Class;
    static CppClassType image_class_;

  protected:
    explicit Image (const Glib::ConstructParams& construct_params);
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

    explicit Image (const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);

    explicit Image (const Glib::RefPtr<Gdk::Paintable>& paintable);

    explicit Image (const Glib::RefPtr<Gio::Icon>& gicon);

    void
    set (const std::string& filename);

    void
    set_from_resource (const std::string& resource_path);

    void
    set (const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);

    void
    set (const Glib::RefPtr<Gdk::Paintable>& paintable);

    void
    set (const Glib::RefPtr<const Gio::Icon>& icon);

    void
    set_from_icon_name (const Glib::ustring& icon_name);

    void
    clear ();

    auto
    get_storage_type () const -> Type;

    auto
    get_paintable () -> Glib::RefPtr<Gdk::Paintable>;

    auto
    get_paintable () const -> Glib::RefPtr<const Gdk::Paintable>;

    void
    set_icon_size (IconSize icon_size);

    auto
    get_icon_size () const -> IconSize;

    auto
    get_gicon () -> Glib::RefPtr<Gio::Icon>;

    auto
    get_gicon () const -> Glib::RefPtr<const Gio::Icon>;

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    get_pixel_size () const -> int;

    void
    set_pixel_size (int pixel_size);

    auto
    property_file () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_file () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_icon_size () -> Glib::PropertyProxy<IconSize>;

    auto
    property_icon_size () const -> Glib::PropertyProxy_ReadOnly<IconSize>;

    auto
    property_pixel_size () -> Glib::PropertyProxy<int>;

    auto
    property_pixel_size () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_storage_type () const -> Glib::PropertyProxy_ReadOnly<Type>;

    auto
    property_gicon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>;

    auto
    property_gicon () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>;

    auto
    property_use_fallback () -> Glib::PropertyProxy<bool>;

    auto
    property_use_fallback () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_resource () -> Glib::PropertyProxy<std::string>;

    auto
    property_resource () const -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_paintable () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_paintable () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Image::Type>
    : public Glib::Value_Enum<Gtk::Image::Type>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkImage* object, bool take_copy = false) -> Gtk::Image*;
} // namespace Glib

#endif
