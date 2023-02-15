// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILECHOOSERNATIVE_H
#define _GTKMM_FILECHOOSERNATIVE_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-gtk/filechooser.hxx>
  #include <libmm-gtk/nativedialog.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API FileChooserNative_Class;
}
  #endif

namespace Gtk
{
  class GTKMM_API Window;

  class GTKMM_API FileChooserNative : public NativeDialog,
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
    explicit FileChooserNative (const Glib::ConstructParams& construct_params);
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

    FileChooserNative (const Glib::ustring& title,
                       Window& parent,
                       FileChooser::Action action,
                       const Glib::ustring& accept_label,
                       const Glib::ustring& cancel_label);

    FileChooserNative (const Glib::ustring& title,
                       FileChooser::Action action,
                       const Glib::ustring& accept_label,
                       const Glib::ustring& cancel_label);

  public:
    static auto
    create (const Glib::ustring& title,
            Window& parent,
            FileChooser::Action action,
            const Glib::ustring& accept_label = {},
            const Glib::ustring& cancel_label = {})
        -> Glib::RefPtr<FileChooserNative>;

    static auto
    create (const Glib::ustring& title,
            FileChooser::Action action,
            const Glib::ustring& accept_label = {},
            const Glib::ustring& cancel_label = {})
        -> Glib::RefPtr<FileChooserNative>;

    auto
    get_accept_label () const -> Glib::ustring;

    auto
    set_accept_label (const Glib::ustring& accept_label = {}) -> void;

    auto
    get_cancel_label () const -> Glib::ustring;

    auto
    set_cancel_label (const Glib::ustring& cancel_label = {}) -> void;

    auto
    property_accept_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_accept_label () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_cancel_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_cancel_label () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkFileChooserNative* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FileChooserNative>;
} // namespace Glib

#endif

#endif
