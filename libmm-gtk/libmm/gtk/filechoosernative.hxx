// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILECHOOSERNATIVE_H
#define _GTKMM_FILECHOOSERNATIVE_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/filechooser.hxx>
  #include <libmm/gtk/nativedialog.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FileChooserNative_Class;
}
  #endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Window;

  class LIBMM_GTK_SYMEXPORT FileChooserNative : public NativeDialog,
                                      public FileChooser
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileChooserNative;
    using CppClassType = FileChooserNative_Class;
    using BaseObjectType = GtkFileChooserNative;
    using BaseClassType = GtkFileChooserNativeClass;

    FileChooserNative (const FileChooserNative&) = delete;
    auto
    operator= (const FileChooserNative&) -> FileChooserNative& = delete;

  private:
    friend class FileChooserNative_Class;
    static CppClassType filechoosernative_class_;

  protected:
    explicit FileChooserNative (const glib::ConstructParams& construct_params);
    explicit FileChooserNative (GtkFileChooserNative* castitem);

  #endif

  public:
    FileChooserNative (FileChooserNative&& src) noexcept;
    auto
    operator= (FileChooserNative&& src) noexcept -> FileChooserNative&;

    ~FileChooserNative () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkFileChooserNative*
    {
      return reinterpret_cast<GtkFileChooserNative*> (gobject_);
    }

    auto
    gobj () const -> const GtkFileChooserNative*
    {
      return reinterpret_cast<GtkFileChooserNative*> (gobject_);
    }

    auto
    gobj_copy () -> GtkFileChooserNative*;

  private:
  protected:
    FileChooserNative ();

    FileChooserNative (const glib::ustring& title,
                       Window& parent,
                       FileChooser::Action action,
                       const glib::ustring& accept_label,
                       const glib::ustring& cancel_label);

    FileChooserNative (const glib::ustring& title,
                       FileChooser::Action action,
                       const glib::ustring& accept_label,
                       const glib::ustring& cancel_label);

  public:
    static auto
    create (const glib::ustring& title,
            Window& parent,
            FileChooser::Action action,
            const glib::ustring& accept_label = {},
            const glib::ustring& cancel_label = {})
        -> glib::RefPtr<FileChooserNative>;

    static auto
    create (const glib::ustring& title,
            FileChooser::Action action,
            const glib::ustring& accept_label = {},
            const glib::ustring& cancel_label = {})
        -> glib::RefPtr<FileChooserNative>;

    auto
    get_accept_label () const -> glib::ustring;

    auto
    set_accept_label (const glib::ustring& accept_label = {}) -> void;

    auto
    get_cancel_label () const -> glib::ustring;

    auto
    set_cancel_label (const glib::ustring& cancel_label = {}) -> void;

    auto
    property_accept_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_accept_label () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_cancel_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_cancel_label () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFileChooserNative* object, bool take_copy = false) -> glib::RefPtr<gtk::FileChooserNative>;
} // namespace glib

#endif

#endif
