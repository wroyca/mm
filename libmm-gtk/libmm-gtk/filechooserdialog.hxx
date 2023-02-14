
#ifndef _GTKMM_FILECHOOSERDIALOG_H
#define _GTKMM_FILECHOOSERDIALOG_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/dialog.hxx>
#include <libmm-gtk/filechooser.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileChooserDialog = struct _GtkFileChooserDialog;
using GtkFileChooserDialogClass = struct _GtkFileChooserDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API FileChooserDialog_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API FileChooserDialog : public Dialog,
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
    friend GTKMM_API class FileChooserDialog_Class;
    static CppClassType filechooserdialog_class_;

  protected:
    explicit FileChooserDialog (const Glib::ConstructParams& construct_params);
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
    FileChooserDialog (Gtk::Window& parent,
                       const Glib::ustring& title,
                       Action action = Action::OPEN,
                       bool use_header_bar = false);
    explicit FileChooserDialog (const Glib::ustring& title,
                                Action action = Action::OPEN,
                                bool use_header_bar = false);

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkFileChooserDialog* object, bool take_copy = false) -> Gtk::FileChooserDialog*;
} // namespace Glib

#endif
