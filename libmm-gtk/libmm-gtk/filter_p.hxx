
#ifndef _GTKMM_FILTER_P_H
#define _GTKMM_FILTER_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Filter_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Filter;
    using BaseObjectType = GtkFilter;
    using BaseClassType = GtkFilterClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Filter;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    match_vfunc_callback (GtkFilter* self, gpointer item) -> gboolean;
    static auto
    get_strictness_vfunc_callback (GtkFilter* self) -> GtkFilterMatch;
  };

} // namespace Gtk

#endif
