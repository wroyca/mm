// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESGROUP_P_H
#define _LIBADWAITAMM_PREFERENCESGROUP_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT PreferencesGroup_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PreferencesGroup;
    using BaseObjectType = AdwPreferencesGroup;
    using BaseClassType = AdwPreferencesGroupClass;
    using CppClassParent = gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class PreferencesGroup;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
