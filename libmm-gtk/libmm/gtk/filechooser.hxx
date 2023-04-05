// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILECHOOSER_H
#define _GTKMM_FILECHOOSER_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <vector>

  #include <libmm/gio/file.hxx>
  #include <libmm/gio/listmodel.hxx>
  #include <libmm/gtk/filefilter.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileChooser = struct _GtkFileChooser;
using GtkFileChooserClass = struct _GtkFileChooserClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FileChooser_Class;
}
  #endif

namespace gtk
{

  class FileChooserError : public glib::Error
  {
  public:
    enum Code
    {
      NONEXISTENT,
      BAD_FILENAME,
      ALREADY_EXISTS,
      INCOMPLETE_HOSTNAME
    };

    LIBMM_GTK_SYMEXPORT
    FileChooserError (Code error_code, const glib::ustring& error_message);
    LIBMM_GTK_SYMEXPORT explicit FileChooserError (GError* gobject);
    LIBMM_GTK_SYMEXPORT auto
    code () const -> Code;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GTK_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GTK_SYMEXPORT auto
    wrap_init () -> void;

  #endif
  };

} // namespace gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::FileChooserError::Code>
    : public glib::Value_Enum<gtk::FileChooserError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FileChooser : public glib::Interface
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileChooser;
    using CppClassType = FileChooser_Class;
    using BaseObjectType = GtkFileChooser;
    using BaseClassType = GtkFileChooserClass;

    FileChooser (const FileChooser&) = delete;
    auto
    operator= (const FileChooser&) -> FileChooser& = delete;

  private:
    friend class FileChooser_Class;
    static CppClassType filechooser_class_;

  #endif
  protected:
    FileChooser ();

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit FileChooser (const glib::Interface_Class& interface_class);

  public:
    explicit FileChooser (GtkFileChooser* castitem);

  protected:
  #endif

  public:
    FileChooser (FileChooser&& src) noexcept;
    auto
    operator= (FileChooser&& src) noexcept -> FileChooser&;

    ~FileChooser () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkFileChooser*
    {
      return reinterpret_cast<GtkFileChooser*> (gobject_);
    }

    auto
    gobj () const -> const GtkFileChooser*
    {
      return reinterpret_cast<GtkFileChooser*> (gobject_);
    }

  private:
  public:
    enum class Action
    {
      OPEN,
      SAVE,
      SELECT_FOLDER
    };

    auto
    set_action (Action action) -> void;

    auto
    get_action () const -> Action;

    auto
    set_select_multiple (bool select_multiple = true) -> void;

    auto
    get_select_multiple () const -> bool;

    auto
    set_create_folders (bool create_folders = true) -> void;

    auto
    get_create_folders () const -> bool;

    auto
    set_current_name (const glib::ustring& name) -> void;

    auto
    get_current_name () const -> glib::ustring;

    auto
    set_file (const glib::RefPtr<const gio::File>& file) -> bool;

    auto
    get_files () -> glib::RefPtr<gio::ListModel>;

    auto
    get_files () const -> glib::RefPtr<const gio::ListModel>;

    auto
    set_current_folder (const glib::RefPtr<const gio::File>& file) -> bool;

    auto
    get_current_folder () -> glib::RefPtr<gio::File>;

    auto
    get_current_folder () const -> glib::RefPtr<const gio::File>;

    auto
    get_file () -> glib::RefPtr<gio::File>;

    auto
    get_file () const -> glib::RefPtr<const gio::File>;

    auto
    add_filter (const glib::RefPtr<FileFilter>& filter) -> void;

    auto
    remove_filter (const glib::RefPtr<FileFilter>& filter) -> void;

    auto
    get_filters () const -> glib::RefPtr<const gio::ListModel>;

    auto
    set_filter (const glib::RefPtr<FileFilter>& filter) -> void;

    auto
    get_filter () -> glib::RefPtr<FileFilter>;

    auto
    get_filter () const -> glib::RefPtr<const FileFilter>;

    auto
    add_shortcut_folder (const glib::RefPtr<gio::File>& folder) -> bool;

    auto
    remove_shortcut_folder (const glib::RefPtr<gio::File>& folder) -> bool;

    auto
    get_shortcut_folders () const -> glib::RefPtr<const gio::ListModel>;

    auto
    add_choice (const glib::ustring& id,
                const glib::ustring& label,
                const std::vector<glib::ustring>& options,
                const std::vector<glib::ustring>& option_labels) -> void;

    auto
    add_choice (const glib::ustring& id, const glib::ustring& label) -> void;

    auto
    remove_choice (const glib::ustring& id) -> void;

    auto
    set_choice (const glib::ustring& id, const glib::ustring& option) -> void;

    auto
    get_choice (const glib::ustring& id) const -> glib::ustring;

    auto
    property_action () -> glib::PropertyProxy<Action>;

    auto
    property_action () const -> glib::PropertyProxy_ReadOnly<Action>;

    auto
    property_filter () -> glib::PropertyProxy<glib::RefPtr<FileFilter>>;

    auto
    property_filter () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FileFilter>>;

    auto
    property_select_multiple () -> glib::PropertyProxy<bool>;

    auto
    property_select_multiple () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_filters () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_shortcut_folders () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_create_folders () -> glib::PropertyProxy<bool>;

    auto
    property_create_folders () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::FileChooser::Action>
    : public glib::Value_Enum<gtk::FileChooser::Action>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
  #endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFileChooser* object, bool take_copy = false) -> glib::RefPtr<gtk::FileChooser>;

} // namespace glib

#endif

#endif
