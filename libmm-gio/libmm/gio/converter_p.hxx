// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_CONVERTER_P_H
#define _GIOMM_CONVERTER_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Converter_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = Converter;
    using BaseObjectType = GConverter;
    using BaseClassType = GConverterIface;
    using CppClassParent = Interface_Class;

    friend class Converter;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    convert_vfunc_callback (GConverter* self,
                            const void* inbuf,
                            gsize inbuf_size,
                            void* outbuf,
                            gsize outbuf_size,
                            GConverterFlags flags,
                            gsize* bytes_read,
                            gsize* bytes_written,
                            GError** error) -> GConverterResult;
    static auto
    reset_vfunc_callback (GConverter* self) -> void;
  };

} // namespace gio

#endif
