// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPCHOOSERBUTTON_P_H
#define _GTKMM_APPCHOOSERBUTTON_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-gtk/widget_p.hxx>

  #include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API AppChooserButton_Class : public Glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AppChooserButton;
    using BaseObjectType = GtkAppChooserButton;
    using BaseClassType = GtkAppChooserButtonClass;
    using CppClassParent = Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class AppChooserButton;
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

#endif
