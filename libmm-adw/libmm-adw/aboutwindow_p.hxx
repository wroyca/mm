// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ABOUTWINDOW_P_H
#define _LIBADWAITAMM_ABOUTWINDOW_P_H

#include <libmm-adw/window_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT AboutWindow_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AboutWindow;
    using BaseObjectType = AdwAboutWindow;
    using CppClassParent = Adw::Window_Class;

    friend class AboutWindow;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
