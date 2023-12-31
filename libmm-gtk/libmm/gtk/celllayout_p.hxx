// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLLAYOUT_P_H
#define _GTKMM_CELLLAYOUT_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/interface_p.hxx>

  #include <libmm/glib/interface_p.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CellLayout_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = CellLayout;
    using BaseObjectType = GtkCellLayout;
    using BaseClassType = GtkCellLayoutIface;
    using CppClassParent = glib::Interface_Class;

    friend class CellLayout;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    pack_start_vfunc_callback (GtkCellLayout* self,
                               GtkCellRenderer* cell,
                               gboolean expand) -> void;
    static auto
    pack_end_vfunc_callback (GtkCellLayout* self,
                             GtkCellRenderer* cell,
                             gboolean expand) -> void;
    static auto
    clear_vfunc_callback (GtkCellLayout* self) -> void;
    static auto
    add_attribute_vfunc_callback (GtkCellLayout* self,
                                  GtkCellRenderer* cell,
                                  const gchar* attribute,
                                  gint column) -> void;
    static auto
    clear_attributes_vfunc_callback (GtkCellLayout* self, GtkCellRenderer* cell)
        -> void;
    static auto
    reorder_vfunc_callback (GtkCellLayout* self,
                            GtkCellRenderer* cell,
                            gint position) -> void;
  };

} // namespace gtk

#endif

#endif
