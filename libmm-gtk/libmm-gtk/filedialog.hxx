// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILEDIALOG_H
#define _GTKMM_FILEDIALOG_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/file.hxx>
#include <libmm-gio/listmodel.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gtk/filefilter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API FileDialog_Class;
}
#endif

namespace Gtk
{
  class Window;

  class GTKMM_API FileDialog : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileDialog;
    using CppClassType = FileDialog_Class;
    using BaseObjectType = GtkFileDialog;
    using BaseClassType = GtkFileDialogClass;

    FileDialog (const FileDialog&) = delete;
    auto
    operator= (const FileDialog&) -> FileDialog& = delete;

  private:
    friend class FileDialog_Class;
    static CppClassType filedialog_class_;

  protected:
    explicit FileDialog (const Glib::ConstructParams& construct_params);
    explicit FileDialog (GtkFileDialog* castitem);

#endif

  public:
    FileDialog (FileDialog&& src) noexcept;
    auto
    operator= (FileDialog&& src) noexcept -> FileDialog&;

    ~FileDialog () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFileDialog*
    {
      return reinterpret_cast<GtkFileDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkFileDialog*
    {
      return reinterpret_cast<GtkFileDialog*> (gobject_);
    }

    auto
    gobj_copy () -> GtkFileDialog*;

  private:
  protected:
    FileDialog ();

  public:
    static auto
    create () -> Glib::RefPtr<FileDialog>;

    auto
    get_title () const -> Glib::ustring;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    get_modal () const -> bool;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_filters () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_filters () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    set_filters (const Glib::RefPtr<Gio::ListModel>& filters) -> void;

    auto
    get_default_filter () -> Glib::RefPtr<FileFilter>;

    auto
    get_default_filter () const -> Glib::RefPtr<const FileFilter>;

    auto
    set_default_filter (const Glib::RefPtr<FileFilter>& filter) -> void;

    auto
    get_initial_folder () -> Glib::RefPtr<Gio::File>;

    auto
    get_initial_folder () const -> Glib::RefPtr<const Gio::File>;

    auto
    set_initial_folder (const Glib::RefPtr<Gio::File>& folder) -> void;

    auto
    get_initial_name () const -> std::string;

    auto
    set_initial_name (const std::string& name) -> void;

    auto
    get_initial_file () -> Glib::RefPtr<Gio::File>;

    auto
    get_initial_file () const -> Glib::RefPtr<const Gio::File>;

    auto
    set_initial_file (const Glib::RefPtr<Gio::File>& file) -> void;

    auto
    get_accept_label () const -> Glib::ustring;

    auto
    set_accept_label (const Glib::ustring& accept_label) -> void;

    auto
    open (Window& parent,
          const Gio::SlotAsyncReady& slot,
          const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    open (const Gio::SlotAsyncReady& slot,
          const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    open_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> Glib::RefPtr<Gio::File>;

    auto
    select_folder (Window& parent,
                   const Gio::SlotAsyncReady& slot,
                   const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    select_folder (const Gio::SlotAsyncReady& slot,
                   const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    select_folder_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> Glib::RefPtr<Gio::File>;

    auto
    save (Window& parent,
          const Gio::SlotAsyncReady& slot,
          const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    save (const Gio::SlotAsyncReady& slot,
          const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    save_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> Glib::RefPtr<Gio::File>;

    auto
    open_multiple (Window& parent,
                   const Gio::SlotAsyncReady& slot,
                   const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    open_multiple (const Gio::SlotAsyncReady& slot,
                   const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    open_multiple_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> Glib::RefPtr<Gio::ListModel>;

    auto
    select_multiple_folders (
        Window& parent,
        const Gio::SlotAsyncReady& slot,
        const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    select_multiple_folders (
        const Gio::SlotAsyncReady& slot,
        const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    select_multiple_folders_finish (
        const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> Glib::RefPtr<Gio::ListModel>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_filters () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_filters () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_default_filter () -> Glib::PropertyProxy<Glib::RefPtr<FileFilter>>;

    auto
    property_default_filter () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FileFilter>>;

    auto
    property_initial_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>;

    auto
    property_initial_file () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>;

    auto
    property_initial_folder () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>;

    auto
    property_initial_folder () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>;

    auto
    property_initial_name () -> Glib::PropertyProxy<std::string>;

    auto
    property_initial_name () const -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_accept_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_accept_label () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkFileDialog* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FileDialog>;
} // namespace Glib

#endif
