// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTCHOOSERWIDGET_P_H
#define _GTKMM_FONTCHOOSERWIDGET_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/gtk/widget_p.hxx>

  #include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FontChooserWidget_Class : public glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FontChooserWidget;
    using BaseObjectType = GtkFontChooserWidget;
    using BaseClassType = GtkFontChooserWidgetClass;
    using CppClassParent = gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class FontChooserWidget;
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

#endif
