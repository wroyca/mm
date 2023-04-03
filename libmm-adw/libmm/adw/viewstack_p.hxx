// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_VIEWSTACK_P_H
#define _LIBADWAITAMM_VIEWSTACK_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT ViewStack_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ViewStack;
    using BaseObjectType = AdwViewStack;
    using CppClassParent = Gtk::Widget_Class;

    friend class ViewStack;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
