
#ifndef _GTKMM_COLORCHOOSERDIALOG_P_H
#define _GTKMM_COLORCHOOSERDIALOG_P_H

#include <libmm-gtk/dialog_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API ColorChooserDialog_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ColorChooserDialog;
    using BaseObjectType = GtkColorChooserDialog;
    using BaseClassType = GtkColorChooserDialogClass;
    using CppClassParent = Dialog_Class;
    using BaseClassParent = GtkDialogClass;

    friend class ColorChooserDialog;
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
