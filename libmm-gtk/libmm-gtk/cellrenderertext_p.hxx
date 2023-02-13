
#ifndef _GTKMM_CELLRENDERERTEXT_P_H
#define _GTKMM_CELLRENDERERTEXT_P_H


#include <libmm-gtk/cellrenderer_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

class GTKMM_API CellRendererText_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = CellRendererText;
  using BaseObjectType = GtkCellRendererText;
  using BaseClassType = GtkCellRendererTextClass;
  using CppClassParent = CellRenderer_Class;
  using BaseClassParent = GtkCellRendererClass;

  friend class CellRendererText;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto edited_callback (GtkCellRendererText *self, const gchar *p0, const gchar *p1) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_CELLRENDERERTEXT_P_H */

