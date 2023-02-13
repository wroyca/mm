
#ifndef _GTKMM_FONTCHOOSER_P_H
#define _GTKMM_FONTCHOOSER_P_H


#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

class GTKMM_API FontChooser_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = FontChooser;
  using BaseObjectType = GtkFontChooser;
  using BaseClassType = GtkFontChooserIface;
  using CppClassParent = Interface_Class;

  friend class FontChooser;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto font_activated_callback (GtkFontChooser *self, const gchar *p0) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_FONTCHOOSER_P_H */

