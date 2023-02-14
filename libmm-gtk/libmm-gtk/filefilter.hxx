// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILEFILTER_H
#define _GTKMM_FILEFILTER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/buildable.hxx>
#include <libmm-gtk/filter.hxx>
#include <string>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileFilter = struct _GtkFileFilter;
using GtkFileFilterClass = struct _GtkFileFilterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API FileFilter_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API FileFilter : public Gtk::Filter,
                               public Buildable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileFilter;
    using CppClassType = FileFilter_Class;
    using BaseObjectType = GtkFileFilter;
    using BaseClassType = GtkFileFilterClass;

    FileFilter (const FileFilter&) = delete;
    auto
    operator= (const FileFilter&) -> FileFilter& = delete;

  private:
    friend class FileFilter_Class;
    static CppClassType filefilter_class_;

  protected:
    explicit FileFilter (const Glib::ConstructParams& construct_params);
    explicit FileFilter (GtkFileFilter* castitem);

#endif

  public:
    FileFilter (FileFilter&& src) noexcept;
    auto
    operator= (FileFilter&& src) noexcept -> FileFilter&;

    ~FileFilter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFileFilter*
    {
      return reinterpret_cast<GtkFileFilter*> (gobject_);
    }

    auto
    gobj () const -> const GtkFileFilter*
    {
      return reinterpret_cast<GtkFileFilter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkFileFilter*;

  private:
  protected:
    FileFilter ();

  public:
    static auto
    create () -> Glib::RefPtr<FileFilter>;

    void
    set_name (const Glib::ustring& name);

    auto
    get_name () const -> Glib::ustring;

    void
    add_mime_type (const Glib::ustring& mime_type);

    void
    add_pattern (const Glib::ustring& pattern);

    void
    add_suffix (const std::string& suffix);

    void
    add_pixbuf_formats ();

    auto
    property_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkFileFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FileFilter>;
} // namespace Glib

#endif
