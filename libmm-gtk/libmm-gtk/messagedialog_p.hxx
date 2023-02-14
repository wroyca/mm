
#ifndef _GTKMM_MESSAGEDIALOG_P_H
#define _GTKMM_MESSAGEDIALOG_P_H

#include <libmm-gtk/dialog_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API MessageDialog_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MessageDialog;
    using BaseObjectType = GtkMessageDialog;
    using BaseClassType = GtkMessageDialogClass;
    using CppClassParent = Dialog_Class;
    using BaseClassParent = GtkDialogClass;

    friend class MessageDialog;
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
