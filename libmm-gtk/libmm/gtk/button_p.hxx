// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BUTTON_P_H
#define _GTKMM_BUTTON_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Button_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Button;
    using BaseObjectType = GtkButton;
    using BaseClassType = GtkButtonClass;
    using CppClassParent = gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class Button;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    clicked_callback (GtkButton* self) -> void;
  };

} // namespace gtk

#endif
