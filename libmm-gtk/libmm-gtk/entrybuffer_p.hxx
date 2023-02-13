
#ifndef _GTKMM_ENTRYBUFFER_P_H
#define _GTKMM_ENTRYBUFFER_P_H


#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

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

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto inserted_text_callback (
    GtkEntryBuffer *self, guint p0, const gchar *p1, guint p2) -> void;
  static auto deleted_text_callback (GtkEntryBuffer *self, guint p0, guint p1) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_ENTRYBUFFER_P_H */

