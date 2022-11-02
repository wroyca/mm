// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_ENTRYBUFFER_P_H
#define _GTKMM_ENTRYBUFFER_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API EntryBuffer_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = EntryBuffer;
  using BaseObjectType = GtkEntryBuffer;
  using BaseClassType = GtkEntryBufferClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class EntryBuffer;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void inserted_text_callback(GtkEntryBuffer* self, guint p0, const gchar* p1, guint p2);
  static void deleted_text_callback(GtkEntryBuffer* self, guint p0, guint p1);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_ENTRYBUFFER_P_H */

