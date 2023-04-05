// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXTBUFFER_P_H
#define _GTKMM_TEXTBUFFER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TextBuffer_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TextBuffer;
    using BaseObjectType = GtkTextBuffer;
    using BaseClassType = GtkTextBufferClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class TextBuffer;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    insert_text_callback (GtkTextBuffer* self,
                          GtkTextIter* p0,
                          const gchar* p1,
                          gint p2) -> void;
    static auto
    insert_paintable_callback (GtkTextBuffer* self,
                               GtkTextIter* p0,
                               GdkPaintable* p1) -> void;
    static auto
    insert_child_anchor_callback (GtkTextBuffer* self,
                                  GtkTextIter* p0,
                                  GtkTextChildAnchor* p1) -> void;
    static auto
    delete_range_callback (GtkTextBuffer* self,
                           GtkTextIter* p0,
                           GtkTextIter* p1) -> void;
    static auto
    changed_callback (GtkTextBuffer* self) -> void;
    static auto
    modified_changed_callback (GtkTextBuffer* self) -> void;
    static auto
    mark_set_callback (GtkTextBuffer* self,
                       const GtkTextIter* p0,
                       GtkTextMark* p1) -> void;
    static auto
    mark_deleted_callback (GtkTextBuffer* self, GtkTextMark* p0) -> void;
    static auto
    apply_tag_callback (GtkTextBuffer* self,
                        GtkTextTag* p0,
                        const GtkTextIter* p1,
                        const GtkTextIter* p2) -> void;
    static auto
    remove_tag_callback (GtkTextBuffer* self,
                         GtkTextTag* p0,
                         const GtkTextIter* p1,
                         const GtkTextIter* p2) -> void;
    static auto
    begin_user_action_callback (GtkTextBuffer* self) -> void;
    static auto
    end_user_action_callback (GtkTextBuffer* self) -> void;
    static auto
    paste_done_callback (GtkTextBuffer* self, GdkClipboard* p0) -> void;
    static auto
    redo_callback (GtkTextBuffer* self) -> void;
    static auto
    undo_callback (GtkTextBuffer* self) -> void;
  };

} // namespace gtk

#endif
