
#ifndef _GTKMM_ASSISTANTPAGE_P_H
#define _GTKMM_ASSISTANTPAGE_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API AssistantPage_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AssistantPage;
    using BaseObjectType = GtkAssistantPage;
    using BaseClassType = GtkAssistantPageClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class AssistantPage;
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
