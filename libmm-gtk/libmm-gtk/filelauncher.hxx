// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILELAUNCHER_H
#define _GTKMM_FILELAUNCHER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/file.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT FileLauncher_Class;
}
#endif

namespace Gtk
{
  class Window;

  class LIBMM_GTK_SYMEXPORT FileLauncher : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileLauncher;
    using CppClassType = FileLauncher_Class;
    using BaseObjectType = GtkFileLauncher;
    using BaseClassType = GtkFileLauncherClass;

    FileLauncher (const FileLauncher&) = delete;
    auto
    operator= (const FileLauncher&) -> FileLauncher& = delete;

  private:
    friend class FileLauncher_Class;
    static CppClassType filelauncher_class_;

  protected:
    explicit FileLauncher (const Glib::ConstructParams& construct_params);
    explicit FileLauncher (GtkFileLauncher* castitem);

#endif

  public:
    FileLauncher (FileLauncher&& src) noexcept;
    auto
    operator= (FileLauncher&& src) noexcept -> FileLauncher&;

    ~FileLauncher () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFileLauncher*
    {
      return reinterpret_cast<GtkFileLauncher*> (gobject_);
    }

    auto
    gobj () const -> const GtkFileLauncher*
    {
      return reinterpret_cast<GtkFileLauncher*> (gobject_);
    }

    auto
    gobj_copy () -> GtkFileLauncher*;

  private:
  protected:
    explicit FileLauncher (const Glib::RefPtr<Gio::File>& file);

  public:
    static auto
    create (const Glib::RefPtr<Gio::File>& file = {})
        -> Glib::RefPtr<FileLauncher>;

    auto
    get_file () -> Glib::RefPtr<Gio::File>;

    auto
    get_file () const -> Glib::RefPtr<const Gio::File>;

    auto
    set_file (const Glib::RefPtr<Gio::File>& file) -> void;

    auto
    launch (Window& parent,
            const Gio::SlotAsyncReady& slot,
            const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    launch (const Gio::SlotAsyncReady& slot,
            const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    launch_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const -> bool;

    auto
    open_containing_folder (
        Window& parent,
        const Gio::SlotAsyncReady& slot,
        const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    open_containing_folder (
        const Gio::SlotAsyncReady& slot,
        const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    open_containing_folder_finish (
        const Glib::RefPtr<Gio::AsyncResult>& result) const -> bool;

    auto
    property_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>;

    auto
    property_file () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFileLauncher* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FileLauncher>;
} // namespace Glib

#endif
