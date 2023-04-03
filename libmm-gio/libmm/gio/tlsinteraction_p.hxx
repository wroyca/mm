// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSINTERACTION_P_H
#define _GIOMM_TLSINTERACTION_P_H

#include <gio/gio.h>
#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT TlsInteraction_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TlsInteraction;
    using BaseObjectType = GTlsInteraction;
    using BaseClassType = GTlsInteractionClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class TlsInteraction;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    ask_password_vfunc_callback (GTlsInteraction* self,
                                 GTlsPassword* password,
                                 GCancellable* cancellable,
                                 GError** error) -> GTlsInteractionResult;
    static auto
    ask_password_async_vfunc_callback (GTlsInteraction* self,
                                       GTlsPassword* password,
                                       GCancellable* cancellable,
                                       GAsyncReadyCallback callback,
                                       gpointer user_data) -> void;
    static auto
    ask_password_finish_vfunc_callback (GTlsInteraction* self,
                                        GAsyncResult* result,
                                        GError** error)
        -> GTlsInteractionResult;
  };

} // namespace Gio

#endif
