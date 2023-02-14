
#ifndef _GTKMM_MEDIAFILE_H
#define _GTKMM_MEDIAFILE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mediastream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMediaFile = struct _GtkMediaFile;
using GtkMediaFileClass = struct _GtkMediaFileClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API MediaFile_Class;
}
#endif

namespace Gio
{
  class GTKMM_API File;
  class GTKMM_API InputStream;
} // namespace Gio

namespace Gtk
{

  class GTKMM_API MediaFile : public Gtk::MediaStream
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
    explicit MediaFile (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<MediaFile>;

    static auto
    create_for_filename (const std::string& filename)
        -> Glib::RefPtr<MediaFile>;

    static auto
    create_for_resource (const std::string& resource_path)
        -> Glib::RefPtr<MediaFile>;

    static auto
    create (const Glib::RefPtr<Gio::File>& file) -> Glib::RefPtr<MediaFile>;

    static auto
    create (const Glib::RefPtr<Gio::InputStream>& stream)
        -> Glib::RefPtr<MediaFile>;

    void
    clear ();

    void
    set_filename (const std::string& filename);

    void
    set_resource (const std::string& resource_path);

    void
    set_file (const Glib::RefPtr<Gio::File>& file);

    auto
    get_file () -> Glib::RefPtr<Gio::File>;

    auto
    get_file () const -> Glib::RefPtr<const Gio::File>;

    void
    set_input_stream (const Glib::RefPtr<Gio::InputStream>& stream);

    auto
    get_input_stream () -> Glib::RefPtr<Gio::InputStream>;

    auto
    get_input_stream () const -> Glib::RefPtr<const Gio::InputStream>;

    auto
    property_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>;

    auto
    property_file () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>;

    auto
    property_input_stream ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gio::InputStream>>;

    auto
    property_input_stream () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::InputStream>>;

  protected:
    virtual void
    open_vfunc ();

    virtual void
    close_vfunc ();

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkMediaFile* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MediaFile>;
} // namespace Glib

#endif
