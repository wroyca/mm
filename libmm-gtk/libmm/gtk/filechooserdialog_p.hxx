// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILECHOOSERDIALOG_P_H
#define _GTKMM_FILECHOOSERDIALOG_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/gtk/dialog_p.hxx>

  #include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FileChooserDialog_Class : public glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileChooserDialog;
    using BaseObjectType = GtkFileChooserDialog;
    using BaseClassType = GtkFileChooserDialogClass;
    using CppClassParent = gtk::Dialog_Class;
    using BaseClassParent = GtkDialogClass;

    friend class FileChooserDialog;
  #endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif

#endif
