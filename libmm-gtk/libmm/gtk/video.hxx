// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_VIDEO_H
#define _GTKMM_VIDEO_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/file.hxx>
#include <libmm/gtk/mediastream.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Video_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Video : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Video CppObjectType;
    typedef Video_Class CppClassType;
    typedef GtkVideo BaseObjectType;
    typedef GtkVideoClass BaseClassType;
#endif

    Video (Video&& src) noexcept;
    auto
    operator= (Video&& src) noexcept -> Video&;

    Video (const Video&) = delete;
    auto
    operator= (const Video&) -> Video& = delete;

    ~Video () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Video_Class;
    static CppClassType video_class_;

  protected:
    explicit Video (const glib::ConstructParams& construct_params);
    explicit Video (GtkVideo* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkVideo*
    {
      return reinterpret_cast<GtkVideo*> (gobject_);
    }

    auto
    gobj () const -> const GtkVideo*
    {
      return reinterpret_cast<GtkVideo*> (gobject_);
    }

  private:
  public:
    Video ();

    explicit Video (const glib::RefPtr<MediaStream>& media_stream);

    explicit Video (const glib::RefPtr<gio::File>& file);

    explicit Video (const std::string& filename);

    auto
    get_media_stream () -> glib::RefPtr<MediaStream>;

    auto
    get_media_stream () const -> glib::RefPtr<const MediaStream>;

    auto
    set_media_stream (const glib::RefPtr<MediaStream>& stream) -> void;

    auto
    get_file () -> glib::RefPtr<gio::File>;

    auto
    get_file () const -> glib::RefPtr<const gio::File>;

    auto
    set_file (const glib::RefPtr<const gio::File>& file) -> void;

    auto
    set_filename (const std::string& filename) -> void;

    auto
    set_resource (const std::string& resource_path) -> void;

    auto
    get_autoplay () const -> bool;

    auto
    set_autoplay (bool autoplay = true) -> void;

    auto
    get_loop () const -> bool;

    auto
    set_loop (bool loop = true) -> void;

    auto
    property_media_stream () -> glib::PropertyProxy<glib::RefPtr<MediaStream>>;

    auto
    property_media_stream () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<MediaStream>>;

    auto
    property_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>;

    auto
    property_file () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>;

    auto
    property_autoplay () -> glib::PropertyProxy<bool>;

    auto
    property_autoplay () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_loop () -> glib::PropertyProxy<bool>;

    auto
    property_loop () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkVideo* object, bool take_copy = false) -> gtk::Video*;
} // namespace glib

#endif
