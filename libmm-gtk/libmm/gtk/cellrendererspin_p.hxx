// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERSPIN_P_H
#define _GTKMM_CELLRENDERERSPIN_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/gtk/cellrenderertext_p.hxx>

  #include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CellRendererSpin_Class : public glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CellRendererSpin;
    using BaseObjectType = GtkCellRendererSpin;
    using BaseClassType = GtkCellRendererSpinClass;
    using CppClassParent = gtk::CellRendererText_Class;
    using BaseClassParent = GtkCellRendererTextClass;

    friend class CellRendererSpin;
  #endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif

#endif
