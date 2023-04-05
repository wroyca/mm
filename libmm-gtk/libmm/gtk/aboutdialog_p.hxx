// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ABOUTDIALOG_P_H
#define _GTKMM_ABOUTDIALOG_P_H

#include <libmm/gtk/window_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT AboutDialog_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AboutDialog;
    using BaseObjectType = GtkAboutDialog;
    using BaseClassType = GtkAboutDialogClass;
    using CppClassParent = gtk::Window_Class;
    using BaseClassParent = GtkWindowClass;

    friend class AboutDialog;
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
