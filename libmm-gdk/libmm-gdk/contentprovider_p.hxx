// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CONTENTPROVIDER_P_H
#define _GDKMM_CONTENTPROVIDER_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gdk
{

  class GDKMM_API ContentProvider_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ContentProvider;
    using BaseObjectType = GdkContentProvider;
    using BaseClassType = GdkContentProviderClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class ContentProvider;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    content_changed_callback (GdkContentProvider* self) -> void;
  };

} // namespace Gdk

#endif
