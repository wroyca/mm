// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEDRAGSOURCE_P_H
#define _GTKMM_TREEDRAGSOURCE_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/interface_p.hxx>

  #include <libmm/glib/interface_p.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TreeDragSource_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = TreeDragSource;
    using BaseObjectType = GtkTreeDragSource;
    using BaseClassType = GtkTreeDragSourceIface;
    using CppClassParent = Glib::Interface_Class;

    friend class TreeDragSource;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    row_draggable_vfunc_callback (GtkTreeDragSource* self, GtkTreePath* path)
        -> gboolean;
    static auto
    drag_data_get_vfunc_callback (GtkTreeDragSource* self, GtkTreePath* path)
        -> GdkContentProvider*;
    static auto
    drag_data_delete_vfunc_callback (GtkTreeDragSource* self, GtkTreePath* path)
        -> gboolean;
  };

} // namespace Gtk

#endif

#endif
