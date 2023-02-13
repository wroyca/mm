
#ifndef _GTKMM_TEXTBUFFER_P_H
#define _GTKMM_TEXTBUFFER_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API TextBuffer_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TextBuffer;
  using BaseObjectType = GtkTextBuffer;
  using BaseClassType = GtkTextBufferClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class TextBuffer;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto insert_text_callback (
    GtkTextBuffer *self, GtkTextIter *p0, const gchar *p1, gint p2) -> void;
  static auto insert_paintable_callback (
    GtkTextBuffer *self, GtkTextIter *p0, GdkPaintable *p1) -> void;
  static auto insert_child_anchor_callback (
    GtkTextBuffer *self, GtkTextIter *p0, GtkTextChildAnchor *p1) -> void;
  static auto delete_range_callback (GtkTextBuffer *self, GtkTextIter *p0, GtkTextIter *p1) -> void;
  static auto changed_callback (GtkTextBuffer *self) -> void;
  static auto modified_changed_callback (GtkTextBuffer *self) -> void;
  static auto mark_set_callback (
    GtkTextBuffer *self, const GtkTextIter *p0, GtkTextMark *p1) -> void;
  static auto mark_deleted_callback (GtkTextBuffer *self, GtkTextMark *p0) -> void;
  static auto apply_tag_callback (
    GtkTextBuffer *self, GtkTextTag *p0, const GtkTextIter *p1, const GtkTextIter *p2) -> void;
  static auto remove_tag_callback (
    GtkTextBuffer *self, GtkTextTag *p0, const GtkTextIter *p1, const GtkTextIter *p2) -> void;
  static auto begin_user_action_callback (GtkTextBuffer *self) -> void;
  static auto end_user_action_callback (GtkTextBuffer *self) -> void;
  static auto paste_done_callback (GtkTextBuffer *self, GdkClipboard *p0) -> void;
  static auto redo_callback (GtkTextBuffer *self) -> void;
  static auto undo_callback (GtkTextBuffer *self) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_TEXTBUFFER_P_H */

