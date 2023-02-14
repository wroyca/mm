// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_OBJECT_P_H
#define _GTKMM_OBJECT_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Object_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Object CppObjectType;
    typedef GObject BaseObjectType;
    typedef GObjectClass BaseClassType;
    typedef Glib::Object_Class CppClassParent;
    typedef GObjectClass BaseClassParent;

    friend class Object;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

} // namespace Gtk

#endif
