
#ifndef _GTKMM_SCALE_P_H
#define _GTKMM_SCALE_P_H

#include <libmm-gtk/range_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Scale_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Scale;
    using BaseObjectType = GtkScale;
    using BaseClassType = GtkScaleClass;
    using CppClassParent = Range_Class;
    using BaseClassParent = GtkRangeClass;

    friend class Scale;
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
