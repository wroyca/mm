
#ifndef _GTKMM_SNAPSHOT_P_H
#define _GTKMM_SNAPSHOT_P_H

#include <libmm-gdk/snapshot_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Snapshot_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Snapshot;
    using BaseObjectType = GtkSnapshot;
    using BaseClassType = GtkSnapshotClass;
    using CppClassParent = Gdk::Snapshot_Class;
    using BaseClassParent = GdkSnapshotClass;

    friend class Snapshot;
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
