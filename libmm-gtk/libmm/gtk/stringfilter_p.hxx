// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STRINGFILTER_P_H
#define _GTKMM_STRINGFILTER_P_H

#include <libmm/gtk/filter_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT StringFilter_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = StringFilter;
    using BaseObjectType = GtkStringFilter;
    using BaseClassType = GtkStringFilterClass;
    using CppClassParent = gtk::Filter_Class;
    using BaseClassParent = GtkFilterClass;

    friend class StringFilter;
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
