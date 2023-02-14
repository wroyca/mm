
#ifndef _GTKMM_TEXTVIEW_P_H
#define _GTKMM_TEXTVIEW_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API TextView_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TextView;
    using BaseObjectType = GtkTextView;
    using BaseClassType = GtkTextViewClass;
    using CppClassParent = Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class TextView;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    set_anchor_callback (GtkTextView* self) -> void;
    static auto
    insert_at_cursor_callback (GtkTextView* self, const gchar* p0) -> void;
  };

} // namespace Gtk

#endif
