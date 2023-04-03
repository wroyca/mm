// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SIGNALLISTITEMFACTORY_P_H
#define _GTKMM_SIGNALLISTITEMFACTORY_P_H

#include <libmm/gtk/listitemfactory_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT SignalListItemFactory_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SignalListItemFactory;
    using BaseObjectType = GtkSignalListItemFactory;
    using BaseClassType = GtkSignalListItemFactoryClass;
    using CppClassParent = Gtk::ListItemFactory_Class;
    using BaseClassParent = GtkListItemFactoryClass;

    friend class SignalListItemFactory;
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
