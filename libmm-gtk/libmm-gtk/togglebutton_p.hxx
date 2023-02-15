// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TOGGLEBUTTON_P_H
#define _GTKMM_TOGGLEBUTTON_P_H

#include <libmm-gtk/button_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ToggleButton_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ToggleButton;
    using BaseObjectType = GtkToggleButton;
    using BaseClassType = GtkToggleButtonClass;
    using CppClassParent = Gtk::Button_Class;
    using BaseClassParent = GtkButtonClass;

    friend class ToggleButton;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    toggled_callback (GtkToggleButton* self) -> void;
  };

} // namespace Gtk

#endif
