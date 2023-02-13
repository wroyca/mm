
#ifndef _GTKMM_BUILDERSCOPE_P_H
#define _GTKMM_BUILDERSCOPE_P_H


#include <libmm-glib/interface_p.hxx>
#include <gtk/gtk.h>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

class GTKMM_API BuilderScope_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = BuilderScope;
  using BaseObjectType = GtkBuilderScope;
  using BaseClassType = GtkBuilderScopeInterface;
  using CppClassParent = Interface_Class;

  friend class BuilderScope;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto get_type_from_name_vfunc_callback (
    GtkBuilderScope *self, GtkBuilder *builder, const char *type_name) -> GType;
  };


} // namespace Gtk


#endif /* _GTKMM_BUILDERSCOPE_P_H */

