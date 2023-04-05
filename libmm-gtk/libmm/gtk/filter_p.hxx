// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILTER_P_H
#define _GTKMM_FILTER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Filter_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Filter;
    using BaseObjectType = GtkFilter;
    using BaseClassType = GtkFilterClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Filter;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    match_vfunc_callback (GtkFilter* self, gpointer item) -> gboolean;
    static auto
    get_strictness_vfunc_callback (GtkFilter* self) -> GtkFilterMatch;
  };

} // namespace gtk

#endif
