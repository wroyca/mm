// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ADJUSTMENT_P_H
#define _GTKMM_ADJUSTMENT_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Adjustment_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Adjustment;
    using BaseObjectType = GtkAdjustment;
    using BaseClassType = GtkAdjustmentClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Adjustment;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GtkAdjustment* self) -> void;
    static auto
    value_changed_callback (GtkAdjustment* self) -> void;
  };

} // namespace Gtk

#endif
