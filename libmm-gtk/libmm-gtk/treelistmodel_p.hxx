// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREELISTMODEL_P_H
#define _GTKMM_TREELISTMODEL_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API TreeListModel_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TreeListModel;
    using BaseObjectType = GtkTreeListModel;
    using BaseClassType = GtkTreeListModelClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class TreeListModel;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
