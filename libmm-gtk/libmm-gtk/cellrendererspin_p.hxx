// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERSPIN_P_H
#define _GTKMM_CELLRENDERERSPIN_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-gtk/cellrenderertext_p.hxx>

  #include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API CellRendererSpin_Class : public Glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CellRendererSpin;
    using BaseObjectType = GtkCellRendererSpin;
    using BaseClassType = GtkCellRendererSpinClass;
    using CppClassParent = Gtk::CellRendererText_Class;
    using BaseClassParent = GtkCellRendererTextClass;

    friend class CellRendererSpin;
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

#endif
