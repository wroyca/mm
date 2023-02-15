// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ASSISTANT_P_H
#define _GTKMM_ASSISTANT_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-gtk/window_p.hxx>

  #include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Assistant_Class : public Glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Assistant;
    using BaseObjectType = GtkAssistant;
    using BaseClassType = GtkAssistantClass;
    using CppClassParent = Gtk::Window_Class;
    using BaseClassParent = GtkWindowClass;

    friend class Assistant;
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
