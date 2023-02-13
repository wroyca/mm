
#ifndef _GTKMM_CELLEDITABLE_P_H
#define _GTKMM_CELLEDITABLE_P_H


#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

class GTKMM_API CellEditable_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = CellEditable;
  using BaseObjectType = GtkCellEditable;
  using BaseClassType = GtkCellEditableIface;
  using CppClassParent = Interface_Class;

  friend class CellEditable;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto editing_done_callback (GtkCellEditable *self) -> void;
  static auto remove_widget_callback (GtkCellEditable *self) -> void;

  //Callbacks (virtual functions):
  static auto start_editing_vfunc_callback (GtkCellEditable *self, GdkEvent *event) -> void;
};


} // namespace Gtk


#endif /* _GTKMM_CELLEDITABLE_P_H */
