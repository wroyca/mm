// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ENTRYBUFFER_P_H
#define _GTKMM_ENTRYBUFFER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT EntryBuffer_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = EntryBuffer;
    using BaseObjectType = GtkEntryBuffer;
    using BaseClassType = GtkEntryBufferClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class EntryBuffer;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    inserted_text_callback (GtkEntryBuffer* self,
                            guint p0,
                            const gchar* p1,
                            guint p2) -> void;
    static auto
    deleted_text_callback (GtkEntryBuffer* self, guint p0, guint p1) -> void;
  };

} // namespace gtk

#endif
