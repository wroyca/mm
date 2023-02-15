// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_RANGE_P_H
#define _GTKMM_RANGE_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Range_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Range;
    using BaseObjectType = GtkRange;
    using BaseClassType = GtkRangeClass;
    using CppClassParent = Gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class Range;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    value_changed_callback (GtkRange* self) -> void;
    static auto
    adjust_bounds_callback (GtkRange* self, gdouble p0) -> void;
    static auto
    move_slider_callback (GtkRange* self, GtkScrollType p0) -> void;
    static auto
    change_value_callback (GtkRange* self, GtkScrollType p0, gdouble p1)
        -> gboolean;

    static auto
    get_range_border_vfunc_callback (GtkRange* self, GtkBorder* border) -> void;
  };

} // namespace Gtk

#endif
