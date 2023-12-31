// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEVIEWCOLUMN_P_H
#define _GTKMM_TREEVIEWCOLUMN_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/gtk/object_p.hxx>

  #include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TreeViewColumn_Class : public glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TreeViewColumn;
    using BaseObjectType = GtkTreeViewColumn;
    using BaseClassType = GtkTreeViewColumnClass;
    using CppClassParent = Object_Class;
    using BaseClassParent = GObjectClass;

    friend class TreeViewColumn;
  #endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif

#endif
