// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MEDIAFILE_H
#define _GTKMM_MEDIAFILE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mediastream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMediaFile = struct _GtkMediaFile;
using GtkMediaFileClass = struct _GtkMediaFileClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT MediaFile_Class;
}
#endif

namespace gio
{
  class LIBMM_GTK_SYMEXPORT File;
  class LIBMM_GTK_SYMEXPORT InputStream;
} // namespace gio

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT MediaFile : public gtk::MediaStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MediaFile;
    using CppClassType = MediaFile_Class;
    using BaseObjectType = GtkMediaFile;
    using BaseClassType = GtkMediaFileClass;

    MediaFile (const MediaFile&) = delete;
    auto
    operator= (const MediaFile&) -> MediaFile& = delete;

  private:
    friend class MediaFile_Class;
    static CppClassType mediafile_class_;

  protected:
    explicit MediaFile (const glib::ConstructParams& construct_params);
    explicit MediaFile (GtkMediaFile* castitem);

#endif

  public:
    MediaFile (MediaFile&& src) noexcept;
    auto
    operator= (MediaFile&& src) noexcept -> MediaFile&;

    ~MediaFile () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkMediaFile*
    {
      return reinterpret_cast<GtkMediaFile*> (gobject_);
    }

    auto
    gobj () const -> const GtkMediaFile*
    {
      return reinterpret_cast<GtkMediaFile*> (gobject_);
    }

    auto
    gobj_copy () -> GtkMediaFile*;

  private:
  protected:
    MediaFile ();

  public:
    static auto
    create () -> glib::RefPtr<MediaFile>;

    static auto
    create_for_filename (const std::string& filename)
        -> glib::RefPtr<MediaFile>;

    static auto
    create_for_resource (const std::string& resource_path)
        -> glib::RefPtr<MediaFile>;

    static auto
    create (const glib::RefPtr<gio::File>& file) -> glib::RefPtr<MediaFile>;

    static auto
    create (const glib::RefPtr<gio::InputStream>& stream)
        -> glib::RefPtr<MediaFile>;

    auto
    clear () -> void;

    auto
    set_filename (const std::string& filename) -> void;

    auto
    set_resource (const std::string& resource_path) -> void;

    auto
    set_file (const glib::RefPtr<gio::File>& file) -> void;

    auto
    get_file () -> glib::RefPtr<gio::File>;

    auto
    get_file () const -> glib::RefPtr<const gio::File>;

    auto
    set_input_stream (const glib::RefPtr<gio::InputStream>& stream) -> void;

    auto
    get_input_stream () -> glib::RefPtr<gio::InputStream>;

    auto
    get_input_stream () const -> glib::RefPtr<const gio::InputStream>;

    auto
    property_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>;

    auto
    property_file () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>;

    auto
    property_input_stream ()
        -> glib::PropertyProxy<glib::RefPtr<gio::InputStream>>;

    auto
    property_input_stream () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::InputStream>>;

  protected:
    virtual auto
    open_vfunc () -> void;

    virtual auto
    close_vfunc () -> void;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkMediaFile* object, bool take_copy = false) -> glib::RefPtr<gtk::MediaFile>;
} // namespace glib

#endif
