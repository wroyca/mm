
#ifndef _GTKMM_SEARCHENTRY_P_H
#define _GTKMM_SEARCHENTRY_P_H


#include <mm/gtk/private/entry_p.hpp>

#include <mm/glib/class.hpp>

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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_SEARCHENTRY_P_H */

