// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DATAOUTPUTSTREAM_P_H
#define _GIOMM_DATAOUTPUTSTREAM_P_H

#include <libmm-gio/filteroutputstream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API DataOutputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = DataOutputStream;
    using BaseObjectType = GDataOutputStream;
    using BaseClassType = GDataOutputStreamClass;
    using CppClassParent = FilterOutputStream_Class;
    using BaseClassParent = GFilterOutputStreamClass;

    friend class DataOutputStream;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gio

#endif
