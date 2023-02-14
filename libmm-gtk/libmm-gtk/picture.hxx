
#ifndef _GTKMM_PICTURE_H
#define _GTKMM_PICTURE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/pixbuf.hxx>
#include <libmm-gio/file.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Picture_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Picture : public Widget
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
    friend GTKMM_API class Picture_Class;
    static CppClassType picture_class_;

  protected:
    explicit Picture (const Glib::ConstructParams& construct_params);
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

    explicit Picture (const Glib::RefPtr<Gdk::Paintable>& paintable);

    explicit Picture (const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);

    explicit Picture (const Glib::RefPtr<Gio::File>& file);

    explicit Picture (const std::string& filename);

    void
    set_paintable (const Glib::RefPtr<Gdk::Paintable>& paintable);

    auto
    get_paintable () -> Glib::RefPtr<Gdk::Paintable>;

    auto
    get_paintable () const -> Glib::RefPtr<const Gdk::Paintable>;

    void
    set_file (const Glib::RefPtr<const Gio::File>& file);

    auto
    get_file () -> Glib::RefPtr<Gio::File>;

    auto
    get_file () const -> Glib::RefPtr<const Gio::File>;

    void
    set_filename (const std::string& filename);

    void
    set_resource (const std::string& resource_path);

    void
    set_pixbuf (const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);

#ifndef GTKMM_DISABLE_DEPRECATED

    void
    set_keep_aspect_ratio (bool keep_aspect_ratio = true);
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_keep_aspect_ratio () const -> bool;
#endif

    void
    set_can_shrink (bool can_shrink = true);

    auto
    get_can_shrink () const -> bool;

    void
    set_content_fit (ContentFit content_fit);

    auto
    get_content_fit () const -> ContentFit;

    void
    set_alternative_text (const Glib::ustring& alternative_text);

    auto
    get_alternative_text () const -> Glib::ustring;

    auto
    property_paintable () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_paintable () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>;

    auto
    property_file () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>;

    auto
    property_alternative_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_alternative_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    property_keep_aspect_ratio () -> Glib::PropertyProxy<bool>;

    auto
    property_keep_aspect_ratio () const -> Glib::PropertyProxy_ReadOnly<bool>;

#endif

    auto
    property_can_shrink () -> Glib::PropertyProxy<bool>;

    auto
    property_can_shrink () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_content_fit () -> Glib::PropertyProxy<ContentFit>;

    auto
    property_content_fit () const -> Glib::PropertyProxy_ReadOnly<ContentFit>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPicture* object, bool take_copy = false) -> Gtk::Picture*;
} // namespace Glib

#endif
