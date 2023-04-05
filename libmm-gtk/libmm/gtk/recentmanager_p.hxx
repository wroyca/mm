// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_RECENTMANAGER_P_H
#define _GTKMM_RECENTMANAGER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT RecentManager_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = RecentManager;
    using BaseObjectType = GtkRecentManager;
    using BaseClassType = GtkRecentManagerClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class RecentManager;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GtkRecentManager* self) -> void;
  };

} // namespace gtk

#endif
