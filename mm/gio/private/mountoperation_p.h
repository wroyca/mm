// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_MOUNTOPERATION_P_H
#define _GIOMM_MOUNTOPERATION_P_H


#include <mm/glib/private/object_p.h>
#include <gio/gio.h>

#include <mm/glib/class.h>

namespace Gio
{

class GIOMM_API MountOperation_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = MountOperation;
  using BaseObjectType = GMountOperation;
  using BaseClassType = GMountOperationClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class MountOperation;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void ask_password_callback(GMountOperation* self, const gchar* p0, const gchar* p1, const gchar* p2, GAskPasswordFlags p3);
  static void ask_question_callback(GMountOperation* self, const gchar* p0, const gchar** p1);
  static void reply_callback(GMountOperation* self, GMountOperationResult p0);
  static void aborted_callback(GMountOperation* self);
  static void show_unmount_progress_callback(GMountOperation* self, const gchar* p0, gint64 p1, gint64 p2);

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_MOUNTOPERATION_P_H */
