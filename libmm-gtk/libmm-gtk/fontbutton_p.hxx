// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTBUTTON_P_H
#define _GTKMM_FONTBUTTON_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-gtk/widget_p.hxx>

  #include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API FontButton_Class : public Glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FontButton;
    using BaseObjectType = GtkFontButton;
    using BaseClassType = GtkFontButtonClass;
    using CppClassParent = Gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class FontButton;
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
