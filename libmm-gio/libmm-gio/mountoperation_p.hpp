
#ifndef _GIOMM_MOUNTOPERATION_P_H
#define _GIOMM_MOUNTOPERATION_P_H


#include <mm/glib/private/object_p.hpp>
#include <gio/gio.h>

#include <mm/glib/class.hpp>

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

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto ask_password_callback (
    GMountOperation *self, const gchar *p0, const gchar *p1, const gchar *p2,
    GAskPasswordFlags p3) -> void;
  static auto ask_question_callback (
    GMountOperation *self, const gchar *p0, const gchar **p1) -> void;
  static auto reply_callback (GMountOperation *self, GMountOperationResult p0) -> void;
  static auto aborted_callback (GMountOperation *self) -> void;
  static auto show_unmount_progress_callback (
    GMountOperation *self, const gchar *p0, gint64 p1, gint64 p2) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_MOUNTOPERATION_P_H */

