// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MOUNTOPERATION_P_H
#define _GIOMM_MOUNTOPERATION_P_H

#include <gio/gio.h>
#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT MountOperation_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MountOperation;
    using BaseObjectType = GMountOperation;
    using BaseClassType = GMountOperationClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class MountOperation;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    ask_password_callback (GMountOperation* self,
                           const gchar* p0,
                           const gchar* p1,
                           const gchar* p2,
                           GAskPasswordFlags p3) -> void;
    static auto
    ask_question_callback (GMountOperation* self,
                           const gchar* p0,
                           const gchar** p1) -> void;
    static auto
    reply_callback (GMountOperation* self, GMountOperationResult p0) -> void;
    static auto
    aborted_callback (GMountOperation* self) -> void;
    static auto
    show_unmount_progress_callback (GMountOperation* self,
                                    const gchar* p0,
                                    gint64 p1,
                                    gint64 p2) -> void;
  };

} // namespace gio

#endif
