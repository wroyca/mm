// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSCERTIFICATE_P_H
#define _GIOMM_TLSCERTIFICATE_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT TlsCertificate_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TlsCertificate;
    using BaseObjectType = GTlsCertificate;
    using BaseClassType = GTlsCertificateClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class TlsCertificate;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    verify_vfunc_callback (GTlsCertificate* self,
                           GSocketConnectable* identity,
                           GTlsCertificate* trusted_ca) -> GTlsCertificateFlags;
  };

} // namespace gio

#endif
