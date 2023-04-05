// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ASSISTANT_P_H
#define _GTKMM_ASSISTANT_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/gtk/window_p.hxx>

  #include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Assistant_Class : public glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Assistant;
    using BaseObjectType = GtkAssistant;
    using BaseClassType = GtkAssistantClass;
    using CppClassParent = gtk::Window_Class;
    using BaseClassParent = GtkWindowClass;

    friend class Assistant;
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
