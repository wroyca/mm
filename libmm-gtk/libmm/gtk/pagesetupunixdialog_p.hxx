// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PAGESETUPUNIXDIALOG_P_H
#define _GTKMM_PAGESETUPUNIXDIALOG_P_H

#include <libmm/gtk/dialog_p.hxx>

#include <libmm/glib/class.hxx>
#include <libmm/gtk/export.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT PageSetupUnixDialog_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PageSetupUnixDialog;
    using BaseObjectType = GtkPageSetupUnixDialog;
    using BaseClassType = GtkPageSetupUnixDialogClass;
    using CppClassParent = Gtk::Dialog_Class;
    using BaseClassParent = GtkDialogClass;

    friend class PageSetupUnixDialog;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
