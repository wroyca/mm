// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SPLITBUTTON_P_H
#define _LIBADWAITAMM_SPLITBUTTON_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT SplitButton_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SplitButton;
    using BaseObjectType = AdwSplitButton;
    using CppClassParent = Gtk::Widget_Class;

    friend class SplitButton;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
