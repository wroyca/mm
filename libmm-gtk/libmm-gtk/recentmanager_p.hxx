
#ifndef _GTKMM_RECENTMANAGER_P_H
#define _GTKMM_RECENTMANAGER_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API RecentManager_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = RecentManager;
    using BaseObjectType = GtkRecentManager;
    using BaseClassType = GtkRecentManagerClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class RecentManager;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GtkRecentManager* self) -> void;
  };

} // namespace Gtk

#endif
