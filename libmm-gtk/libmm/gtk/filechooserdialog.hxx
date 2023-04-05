// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILECHOOSERDIALOG_H
#define _GTKMM_FILECHOOSERDIALOG_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/dialog.hxx>
  #include <libmm/gtk/filechooser.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileChooserDialog = struct _GtkFileChooserDialog;
using GtkFileChooserDialogClass = struct _GtkFileChooserDialogClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FileChooserDialog_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FileChooserDialog : public Dialog,
                                      public FileChooser
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef FileChooserDialog CppObjectType;
    typedef FileChooserDialog_Class CppClassType;
    typedef GtkFileChooserDialog BaseObjectType;
    typedef GtkFileChooserDialogClass BaseClassType;
  #endif

    FileChooserDialog (FileChooserDialog&& src) noexcept;
    auto
    operator= (FileChooserDialog&& src) noexcept -> FileChooserDialog&;

    FileChooserDialog (const FileChooserDialog&) = delete;
    auto
    operator= (const FileChooserDialog&) -> FileChooserDialog& = delete;

    ~FileChooserDialog () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class FileChooserDialog_Class;
    static CppClassType filechooserdialog_class_;

  protected:
    explicit FileChooserDialog (const glib::ConstructParams& construct_params);
    explicit FileChooserDialog (GtkFileChooserDialog* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkFileChooserDialog*
    {
      return reinterpret_cast<GtkFileChooserDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkFileChooserDialog*
    {
      return reinterpret_cast<GtkFileChooserDialog*> (gobject_);
    }

  private:
  public:
    FileChooserDialog (gtk::Window& parent,
                       const glib::ustring& title,
                       Action action = Action::OPEN,
                       bool use_header_bar = false);
    explicit FileChooserDialog (const glib::ustring& title,
                                Action action = Action::OPEN,
                                bool use_header_bar = false);

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFileChooserDialog* object, bool take_copy = false) -> gtk::FileChooserDialog*;
} // namespace glib

#endif

#endif
