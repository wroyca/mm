// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SINGLESELECTION_P_H
#define _GTKMM_SINGLESELECTION_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API SingleSelection_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SingleSelection;
    using BaseObjectType = GtkSingleSelection;
    using BaseClassType = GtkSingleSelectionClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class SingleSelection;
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
