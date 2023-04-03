// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLORDIALOGBUTTON_P_H
#define _GTKMM_COLORDIALOGBUTTON_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ColorDialogButton_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ColorDialogButton;
    using BaseObjectType = GtkColorDialogButton;
    using CppClassParent = Gtk::Widget_Class;

    friend class ColorDialogButton;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
