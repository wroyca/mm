// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILECHOOSER_H
#define _GTKMM_FILECHOOSER_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <vector>

  #include <libmm-gio/file.hxx>
  #include <libmm-gio/listmodel.hxx>
  #include <libmm-gtk/filefilter.hxx>
  #include <libmm-gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileChooser = struct _GtkFileChooser;
using GtkFileChooserClass = struct _GtkFileChooserClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API FileChooser_Class;
}
  #endif

namespace Gtk
{

  class FileChooserError : public Glib::Error
  {
  public:
    enum Code
    {
      NONEXISTENT,
      BAD_FILENAME,
      ALREADY_EXISTS,
      INCOMPLETE_HOSTNAME
    };

    GTKMM_API
    FileChooserError (Code error_code, const Glib::ustring& error_message);
    GTKMM_API explicit FileChooserError (GError* gobject);
    GTKMM_API auto
    code () const -> Code;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GTKMM_API static auto
    throw_func (GError* gobject) -> void;

    friend GTKMM_API auto
    wrap_init () -> void;

  #endif
  };

} // namespace Gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::FileChooserError::Code>
    : public Glib::Value_Enum<Gtk::FileChooserError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
  #endif

namespace Gtk
{

  class GTKMM_API FileChooser : public Glib::Interface
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

    explicit FileChooser (const Glib::Interface_Class& interface_class);

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
    set_current_name (const Glib::ustring& name) -> void;

    auto
    get_current_name () const -> Glib::ustring;

    auto
    set_file (const Glib::RefPtr<const Gio::File>& file) -> bool;

    auto
    get_files () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_files () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    set_current_folder (const Glib::RefPtr<const Gio::File>& file) -> bool;

    auto
    get_current_folder () -> Glib::RefPtr<Gio::File>;

    auto
    get_current_folder () const -> Glib::RefPtr<const Gio::File>;

    auto
    get_file () -> Glib::RefPtr<Gio::File>;

    auto
    get_file () const -> Glib::RefPtr<const Gio::File>;

    auto
    add_filter (const Glib::RefPtr<FileFilter>& filter) -> void;

    auto
    remove_filter (const Glib::RefPtr<FileFilter>& filter) -> void;

    auto
    get_filters () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    set_filter (const Glib::RefPtr<FileFilter>& filter) -> void;

    auto
    get_filter () -> Glib::RefPtr<FileFilter>;

    auto
    get_filter () const -> Glib::RefPtr<const FileFilter>;

    auto
    add_shortcut_folder (const Glib::RefPtr<Gio::File>& folder) -> bool;

    auto
    remove_shortcut_folder (const Glib::RefPtr<Gio::File>& folder) -> bool;

    auto
    get_shortcut_folders () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    add_choice (const Glib::ustring& id,
                const Glib::ustring& label,
                const std::vector<Glib::ustring>& options,
                const std::vector<Glib::ustring>& option_labels) -> void;

    auto
    add_choice (const Glib::ustring& id, const Glib::ustring& label) -> void;

    auto
    remove_choice (const Glib::ustring& id) -> void;

    auto
    set_choice (const Glib::ustring& id, const Glib::ustring& option) -> void;

    auto
    get_choice (const Glib::ustring& id) const -> Glib::ustring;

    auto
    property_action () -> Glib::PropertyProxy<Action>;

    auto
    property_action () const -> Glib::PropertyProxy_ReadOnly<Action>;

    auto
    property_filter () -> Glib::PropertyProxy<Glib::RefPtr<FileFilter>>;

    auto
    property_filter () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FileFilter>>;

    auto
    property_select_multiple () -> Glib::PropertyProxy<bool>;

    auto
    property_select_multiple () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_filters () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_shortcut_folders () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_create_folders () -> Glib::PropertyProxy<bool>;

    auto
    property_create_folders () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::FileChooser::Action>
    : public Glib::Value_Enum<Gtk::FileChooser::Action>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
  #endif

namespace Glib
{
  GTKMM_API auto
  wrap (GtkFileChooser* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FileChooser>;

} // namespace Glib

#endif

#endif
