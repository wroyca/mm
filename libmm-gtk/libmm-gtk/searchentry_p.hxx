
#ifndef _GTKMM_SEARCHENTRY_P_H
#define _GTKMM_SEARCHENTRY_P_H

#include <libmm-gtk/entry_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API SearchEntry_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SearchEntry;
    using BaseObjectType = GtkSearchEntry;
    using BaseClassType = GtkSearchEntryClass;
    using CppClassParent = Entry_Class;
    using BaseClassParent = GtkEntryClass;

    friend class SearchEntry;
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
