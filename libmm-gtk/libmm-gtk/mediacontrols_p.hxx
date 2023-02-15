// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MEDIACONTROLS_P_H
#define _GTKMM_MEDIACONTROLS_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT MediaControls_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MediaControls;
    using BaseObjectType = GtkMediaControls;
    using BaseClassType = GtkMediaControlsClass;
    using CppClassParent = Gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class MediaControls;
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
