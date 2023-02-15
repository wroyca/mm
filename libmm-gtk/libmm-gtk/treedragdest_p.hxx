// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEDRAGDEST_P_H
#define _GTKMM_TREEDRAGDEST_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/interface_p.hxx>

  #include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API TreeDragDest_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = TreeDragDest;
    using BaseObjectType = GtkTreeDragDest;
    using BaseClassType = GtkTreeDragDestIface;
    using CppClassParent = Glib::Interface_Class;

    friend class TreeDragDest;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    drag_data_received_vfunc_callback (GtkTreeDragDest* self,
                                       GtkTreePath* dest,
                                       const GValue* value) -> gboolean;
    static auto
    row_drop_possible_vfunc_callback (GtkTreeDragDest* self,
                                      GtkTreePath* dest_path,
                                      const GValue* value) -> gboolean;
  };

} // namespace Gtk

#endif

#endif
