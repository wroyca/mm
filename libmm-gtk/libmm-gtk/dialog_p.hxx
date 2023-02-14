
#ifndef _GTKMM_DIALOG_P_H
#define _GTKMM_DIALOG_P_H

#include <libmm-gtk/window_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Dialog_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Dialog;
    using BaseObjectType = GtkDialog;
    using BaseClassType = GtkDialogClass;
    using CppClassParent = Window_Class;
    using BaseClassParent = GtkWindowClass;

    friend class Dialog;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    response_callback (GtkDialog* self, gint p0) -> void;
  };

} // namespace Gtk

#endif
