// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCALE_P_H
#define _GTKMM_SCALE_P_H

#include <libmm/gtk/range_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Scale_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Scale;
    using BaseObjectType = GtkScale;
    using BaseClassType = GtkScaleClass;
    using CppClassParent = gtk::Range_Class;
    using BaseClassParent = GtkRangeClass;

    friend class Scale;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
