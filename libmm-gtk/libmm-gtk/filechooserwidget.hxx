// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILECHOOSERWIDGET_H
#define _GTKMM_FILECHOOSERWIDGET_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-gtk/filechooser.hxx>
  #include <libmm-gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileChooserWidget = struct _GtkFileChooserWidget;
using GtkFileChooserWidgetClass = struct _GtkFileChooserWidgetClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT FileChooserWidget_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT FileChooserWidget : public Widget,
                                      public FileChooser
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef FileChooserWidget CppObjectType;
    typedef FileChooserWidget_Class CppClassType;
    typedef GtkFileChooserWidget BaseObjectType;
    typedef GtkFileChooserWidgetClass BaseClassType;
  #endif

    FileChooserWidget (FileChooserWidget&& src) noexcept;
    auto
    operator= (FileChooserWidget&& src) noexcept -> FileChooserWidget&;

    FileChooserWidget (const FileChooserWidget&) = delete;
    auto
    operator= (const FileChooserWidget&) -> FileChooserWidget& = delete;

    ~FileChooserWidget () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class FileChooserWidget_Class;
    static CppClassType filechooserwidget_class_;

  protected:
    explicit FileChooserWidget (const Glib::ConstructParams& construct_params);
    explicit FileChooserWidget (GtkFileChooserWidget* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkFileChooserWidget*
    {
      return reinterpret_cast<GtkFileChooserWidget*> (gobject_);
    }

    auto
    gobj () const -> const GtkFileChooserWidget*
    {
      return reinterpret_cast<GtkFileChooserWidget*> (gobject_);
    }

  private:
  public:
    FileChooserWidget ();

    explicit FileChooserWidget (Action action);

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFileChooserWidget* object, bool take_copy = false) -> Gtk::FileChooserWidget*;
} // namespace Glib

#endif

#endif
