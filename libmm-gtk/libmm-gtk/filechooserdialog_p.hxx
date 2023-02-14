
#ifndef _GTKMM_FILECHOOSERDIALOG_P_H
#define _GTKMM_FILECHOOSERDIALOG_P_H

#include <libmm-gtk/dialog_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API FileChooserDialog_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileChooserDialog;
    using BaseObjectType = GtkFileChooserDialog;
    using BaseClassType = GtkFileChooserDialogClass;
    using CppClassParent = Dialog_Class;
    using BaseClassParent = GtkDialogClass;

    friend class FileChooserDialog;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
