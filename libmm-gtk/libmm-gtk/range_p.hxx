
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
  using CppClassParent = Widget_Class;
  using BaseClassParent = GtkWidgetClass;

  friend class Range;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto value_changed_callback (GtkRange *self) -> void;
  static auto adjust_bounds_callback (GtkRange *self, gdouble p0) -> void;
  static auto move_slider_callback (GtkRange *self, GtkScrollType p0) -> void;
  static auto change_value_callback (GtkRange *self, GtkScrollType p0, gdouble p1) -> gboolean;

  //Callbacks (virtual functions):
  static auto get_range_border_vfunc_callback (GtkRange *self, GtkBorder *border) -> void;
};


} // namespace Gtk


#endif /* _GTKMM_RANGE_P_H */
