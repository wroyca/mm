// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXTVIEW_P_H
#define _GTKMM_TEXTVIEW_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TextView_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TextView;
    using BaseObjectType = GtkTextView;
    using BaseClassType = GtkTextViewClass;
    using CppClassParent = gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class TextView;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    set_anchor_callback (GtkTextView* self) -> void;
    static auto
    insert_at_cursor_callback (GtkTextView* self, const gchar* p0) -> void;
  };

} // namespace gtk

#endif
