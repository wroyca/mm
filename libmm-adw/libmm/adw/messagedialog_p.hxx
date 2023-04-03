// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_MESSAGEDIALOG_P_H
#define _LIBADWAITAMM_MESSAGEDIALOG_P_H

#include <libmm/gtk/window_p.hxx>

#include <libmm/glib/class.hxx>

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT MessageDialog_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MessageDialog;
    using BaseObjectType = AdwMessageDialog;
    using BaseClassType = AdwMessageDialogClass;
    using CppClassParent = Gtk::Window_Class;
    using BaseClassParent = GtkWindowClass;

    friend class MessageDialog;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    response_callback (AdwMessageDialog* self, const gchar* p0) -> void;

    static auto
    response_vfunc_callback (AdwMessageDialog* self, const gchar* p0) -> void;
  };

} // namespace Adw

#endif
