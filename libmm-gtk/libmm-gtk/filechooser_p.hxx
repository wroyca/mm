
#ifndef _GTKMM_FILECHOOSER_P_H
#define _GTKMM_FILECHOOSER_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API FileChooser_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = FileChooser;
    using BaseObjectType = GtkFileChooser;
    using BaseClassType = GtkFileChooserClass;
    using CppClassParent = Interface_Class;

    friend class FileChooser;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
