// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREESTORE_P_H
#define _GTKMM_TREESTORE_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/object_p.hxx>

  #include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API TreeStore_Class : public Glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TreeStore;
    using BaseObjectType = GtkTreeStore;
    using BaseClassType = GtkTreeStoreClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class TreeStore;
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
