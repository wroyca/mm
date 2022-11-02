// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_TEXTVIEW_P_H
#define _GTKMM_TEXTVIEW_P_H


#include <mm/gtk/private/widget_p.h>

#include <mm/glib/class.h>

namespace Gtk
{

class GTKMM_API TextView_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TextView;
  using BaseObjectType = GtkTextView;
  using BaseClassType = GtkTextViewClass;
  using CppClassParent = Gtk::Widget_Class;
  using BaseClassParent = GtkWidgetClass;

  friend class TextView;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void set_anchor_callback(GtkTextView* self);
  static void insert_at_cursor_callback(GtkTextView* self, const gchar* p0);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_TEXTVIEW_P_H */
