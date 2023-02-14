
#ifndef _GTKMM_VOLUMEBUTTON_P_H
#define _GTKMM_VOLUMEBUTTON_P_H

#include <libmm-gtk/scalebutton_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API VolumeButton_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = VolumeButton;
    using BaseObjectType = GtkVolumeButton;
    using BaseClassType = GtkVolumeButtonClass;
    using CppClassParent = ScaleButton_Class;
    using BaseClassParent = GtkScaleButtonClass;

    friend class VolumeButton;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
