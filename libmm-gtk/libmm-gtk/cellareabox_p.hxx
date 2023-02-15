// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLAREABOX_P_H
#define _GTKMM_CELLAREABOX_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-gtk/cellarea_p.hxx>

  #include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API CellAreaBox_Class : public Glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CellAreaBox;
    using BaseObjectType = GtkCellAreaBox;
    using BaseClassType = GtkCellAreaBoxClass;
    using CppClassParent = CellArea_Class;
    using BaseClassParent = GtkCellAreaClass;

    friend class CellAreaBox;
  #endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif

#endif
