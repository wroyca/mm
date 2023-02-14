// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LINKBUTTON_P_H
#define _GTKMM_LINKBUTTON_P_H

#include <libmm-gtk/button_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API LinkButton_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = LinkButton;
    using BaseObjectType = GtkLinkButton;
    using BaseClassType = GtkLinkButtonClass;
    using CppClassParent = Button_Class;
    using BaseClassParent = GtkButtonClass;

    friend class LinkButton;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
