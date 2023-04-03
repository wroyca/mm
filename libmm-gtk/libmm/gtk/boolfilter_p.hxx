// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BOOLFILTER_P_H
#define _GTKMM_BOOLFILTER_P_H

#include <libmm/gtk/filter_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT BoolFilter_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = BoolFilter;
    using BaseObjectType = GtkBoolFilter;
    using BaseClassType = GtkBoolFilterClass;
    using CppClassParent = Gtk::Filter_Class;
    using BaseClassParent = GtkFilterClass;

    friend class BoolFilter;
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
