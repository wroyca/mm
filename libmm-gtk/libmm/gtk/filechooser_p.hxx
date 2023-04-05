// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILECHOOSER_P_H
#define _GTKMM_FILECHOOSER_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/interface_p.hxx>

  #include <libmm/glib/interface_p.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FileChooser_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = FileChooser;
    using BaseObjectType = GtkFileChooser;
    using BaseClassType = GtkFileChooserClass;
    using CppClassParent = glib::Interface_Class;

    friend class FileChooser;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif

#endif
