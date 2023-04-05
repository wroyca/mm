// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILEDIALOG_H
#define _GTKMM_FILEDIALOG_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/file.hxx>
#include <libmm/gio/listmodel.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/filefilter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FileDialog_Class;
}
#endif

namespace gtk
{
  class Window;

  class LIBMM_GTK_SYMEXPORT FileDialog : public glib::Object
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
    explicit FileDialog (const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<FileDialog>;

    auto
    get_title () const -> glib::ustring;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    get_modal () const -> bool;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_filters () -> glib::RefPtr<gio::ListModel>;

    auto
    get_filters () const -> glib::RefPtr<const gio::ListModel>;

    auto
    set_filters (const glib::RefPtr<gio::ListModel>& filters) -> void;

    auto
    get_default_filter () -> glib::RefPtr<FileFilter>;

    auto
    get_default_filter () const -> glib::RefPtr<const FileFilter>;

    auto
    set_default_filter (const glib::RefPtr<FileFilter>& filter) -> void;

    auto
    get_initial_folder () -> glib::RefPtr<gio::File>;

    auto
    get_initial_folder () const -> glib::RefPtr<const gio::File>;

    auto
    set_initial_folder (const glib::RefPtr<gio::File>& folder) -> void;

    auto
    get_initial_name () const -> std::string;

    auto
    set_initial_name (const std::string& name) -> void;

    auto
    get_initial_file () -> glib::RefPtr<gio::File>;

    auto
    get_initial_file () const -> glib::RefPtr<const gio::File>;

    auto
    set_initial_file (const glib::RefPtr<gio::File>& file) -> void;

    auto
    get_accept_label () const -> glib::ustring;

    auto
    set_accept_label (const glib::ustring& accept_label) -> void;

    auto
    open (Window& parent,
          const gio::SlotAsyncReady& slot,
          const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    open (const gio::SlotAsyncReady& slot,
          const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    open_finish (const glib::RefPtr<gio::AsyncResult>& result) const
        -> glib::RefPtr<gio::File>;

    auto
    select_folder (Window& parent,
                   const gio::SlotAsyncReady& slot,
                   const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    select_folder (const gio::SlotAsyncReady& slot,
                   const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    select_folder_finish (const glib::RefPtr<gio::AsyncResult>& result) const
        -> glib::RefPtr<gio::File>;

    auto
    save (Window& parent,
          const gio::SlotAsyncReady& slot,
          const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    save (const gio::SlotAsyncReady& slot,
          const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    save_finish (const glib::RefPtr<gio::AsyncResult>& result) const
        -> glib::RefPtr<gio::File>;

    auto
    open_multiple (Window& parent,
                   const gio::SlotAsyncReady& slot,
                   const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    open_multiple (const gio::SlotAsyncReady& slot,
                   const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    open_multiple_finish (const glib::RefPtr<gio::AsyncResult>& result) const
        -> glib::RefPtr<gio::ListModel>;

    auto
    select_multiple_folders (
        Window& parent,
        const gio::SlotAsyncReady& slot,
        const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    select_multiple_folders (
        const gio::SlotAsyncReady& slot,
        const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    select_multiple_folders_finish (
        const glib::RefPtr<gio::AsyncResult>& result) const
        -> glib::RefPtr<gio::ListModel>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_modal () -> glib::PropertyProxy<bool>;

    auto
    property_modal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_filters () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>;

    auto
    property_filters () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_default_filter () -> glib::PropertyProxy<glib::RefPtr<FileFilter>>;

    auto
    property_default_filter () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FileFilter>>;

    auto
    property_initial_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>;

    auto
    property_initial_file () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>;

    auto
    property_initial_folder () -> glib::PropertyProxy<glib::RefPtr<gio::File>>;

    auto
    property_initial_folder () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>;

    auto
    property_initial_name () -> glib::PropertyProxy<std::string>;

    auto
    property_initial_name () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_accept_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_accept_label () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFileDialog* object, bool take_copy = false) -> glib::RefPtr<gtk::FileDialog>;
} // namespace glib

#endif
