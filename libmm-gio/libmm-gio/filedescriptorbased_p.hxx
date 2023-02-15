// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEDESCRIPTORBASED_P_H
#define _GIOMM_FILEDESCRIPTORBASED_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class GIOMM_API FileDescriptorBased_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = FileDescriptorBased;
    using BaseObjectType = GFileDescriptorBased;
    using BaseClassType = GFileDescriptorBasedIface;
    using CppClassParent = Interface_Class;

    friend class FileDescriptorBased;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    get_fd_vfunc_callback (GFileDescriptorBased* self) -> int;
  };

} // namespace Gio

#endif
