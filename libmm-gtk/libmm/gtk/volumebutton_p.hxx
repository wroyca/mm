// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_VOLUMEBUTTON_P_H
#define _GTKMM_VOLUMEBUTTON_P_H

#include <libmm/gtk/scalebutton_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT VolumeButton_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = VolumeButton;
    using BaseObjectType = GtkVolumeButton;
    using BaseClassType = GtkVolumeButtonClass;
    using CppClassParent = gtk::ScaleButton_Class;
    using BaseClassParent = GtkScaleButtonClass;

    friend class VolumeButton;
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
