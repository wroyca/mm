// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PICTURE_H
#define _GTKMM_PICTURE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/pixbuf.hxx>
#include <libmm/gio/file.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Picture_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Picture : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Picture CppObjectType;
    typedef Picture_Class CppClassType;
    typedef GtkPicture BaseObjectType;
    typedef GtkPictureClass BaseClassType;
#endif

    Picture (Picture&& src) noexcept;
    auto
    operator= (Picture&& src) noexcept -> Picture&;

    Picture (const Picture&) = delete;
    auto
    operator= (const Picture&) -> Picture& = delete;

    ~Picture () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Picture_Class;
    static CppClassType picture_class_;

  protected:
    explicit Picture (const glib::ConstructParams& construct_params);
    explicit Picture (GtkPicture* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPicture*
    {
      return reinterpret_cast<GtkPicture*> (gobject_);
    }

    auto
    gobj () const -> const GtkPicture*
    {
      return reinterpret_cast<GtkPicture*> (gobject_);
    }

  private:
  public:
    Picture ();

    explicit Picture (const glib::RefPtr<gdk::Paintable>& paintable);

    explicit Picture (const glib::RefPtr<gdk::Pixbuf>& pixbuf);

    explicit Picture (const glib::RefPtr<gio::File>& file);

    explicit Picture (const std::string& filename);

    auto
    set_paintable (const glib::RefPtr<gdk::Paintable>& paintable) -> void;

    auto
    get_paintable () -> glib::RefPtr<gdk::Paintable>;

    auto
    get_paintable () const -> glib::RefPtr<const gdk::Paintable>;

    auto
    set_file (const glib::RefPtr<const gio::File>& file) -> void;

    auto
    get_file () -> glib::RefPtr<gio::File>;

    auto
    get_file () const -> glib::RefPtr<const gio::File>;

    auto
    set_filename (const std::string& filename) -> void;

    auto
    set_resource (const std::string& resource_path) -> void;

    auto
    set_pixbuf (const glib::RefPtr<gdk::Pixbuf>& pixbuf) -> void;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    set_keep_aspect_ratio (bool keep_aspect_ratio = true) -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_keep_aspect_ratio () const -> bool;
#endif

    auto
    set_can_shrink (bool can_shrink = true) -> void;

    auto
    get_can_shrink () const -> bool;

    auto
    set_content_fit (ContentFit content_fit) -> void;

    auto
    get_content_fit () const -> ContentFit;

    auto
    set_alternative_text (const glib::ustring& alternative_text) -> void;

    auto
    get_alternative_text () const -> glib::ustring;

    auto
    property_paintable () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>;

    auto
    property_paintable () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>;

    auto
    property_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>;

    auto
    property_file () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>;

    auto
    property_alternative_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_alternative_text () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    property_keep_aspect_ratio () -> glib::PropertyProxy<bool>;

    auto
    property_keep_aspect_ratio () const -> glib::PropertyProxy_ReadOnly<bool>;

#endif

    auto
    property_can_shrink () -> glib::PropertyProxy<bool>;

    auto
    property_can_shrink () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_content_fit () -> glib::PropertyProxy<ContentFit>;

    auto
    property_content_fit () const -> glib::PropertyProxy_ReadOnly<ContentFit>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPicture* object, bool take_copy = false) -> gtk::Picture*;
} // namespace glib

#endif
