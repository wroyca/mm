// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESWINDOW_P_H
#define _LIBADWAITAMM_PREFERENCESWINDOW_P_H

#include <libmm/adw/window_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT preferences_window_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = preferences_window;
    using BaseObjectType = AdwPreferencesWindow;
    using BaseClassType = AdwPreferencesWindowClass;
    using CppClassParent = adw::window_class;
    using BaseClassParent = AdwWindowClass;

    friend class preferences_window;
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
