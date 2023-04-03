// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTDIALOGBUTTON_P_H
#define _GTKMM_FONTDIALOGBUTTON_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT FontDialogButton_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FontDialogButton;
    using BaseObjectType = GtkFontDialogButton;
    using CppClassParent = Gtk::Widget_Class;

    friend class FontDialogButton;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
