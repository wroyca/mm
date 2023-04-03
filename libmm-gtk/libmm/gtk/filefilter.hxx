// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILEFILTER_H
#define _GTKMM_FILEFILTER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/buildable.hxx>
#include <libmm/gtk/filter.hxx>
#include <string>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileFilter = struct _GtkFileFilter;
using GtkFileFilterClass = struct _GtkFileFilterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT FileFilter_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT FileFilter : public Gtk::Filter,
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

    auto
    set_name (const Glib::ustring& name) -> void;

    auto
    get_name () const -> Glib::ustring;

    auto
    add_mime_type (const Glib::ustring& mime_type) -> void;

    auto
    add_pattern (const Glib::ustring& pattern) -> void;

    auto
    add_suffix (const std::string& suffix) -> void;

    auto
    add_pixbuf_formats () -> void;

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
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFileFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FileFilter>;
} // namespace Glib

#endif
