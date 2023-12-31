// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSPASSWORD_P_H
#define _GIOMM_TLSPASSWORD_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT TlsPassword_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TlsPassword;
    using BaseObjectType = GTlsPassword;
    using BaseClassType = GTlsPasswordClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class TlsPassword;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    get_value_vfunc_callback (GTlsPassword* self, gsize* length)
        -> const guchar*;
    static auto
    get_default_warning_vfunc_callback (GTlsPassword* self) -> const gchar*;
  };

} // namespace gio

#endif
