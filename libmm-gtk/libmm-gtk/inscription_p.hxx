// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_INSCRIPTION_P_H
#define _GTKMM_INSCRIPTION_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Inscription_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Inscription;
    using BaseObjectType = GtkInscription;
    using CppClassParent = Gtk::Widget_Class;

    friend class Inscription;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
