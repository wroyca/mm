// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILENAMECOMPLETER_P_H
#define _GIOMM_FILENAMECOMPLETER_P_H

#include <gio/gio.h>
#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API FilenameCompleter_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FilenameCompleter;
    using BaseObjectType = GFilenameCompleter;
    using BaseClassType = GFilenameCompleterClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class FilenameCompleter;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    got_completion_data_callback (GFilenameCompleter* self) -> void;
  };

} // namespace Gio

#endif
