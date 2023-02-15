// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CLAMPSCROLLABLE_P_H
#define _LIBADWAITAMM_CLAMPSCROLLABLE_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class ClampScrollable_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ClampScrollable;
    using BaseObjectType = AdwClampScrollable;
    using CppClassParent = Gtk::Widget_Class;

    friend class ClampScrollable;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
