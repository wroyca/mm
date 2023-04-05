// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ATCONTEXT_P_H
#define _GTKMM_ATCONTEXT_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ATContext_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ATContext;
    using BaseObjectType = GtkATContext;
    using CppClassParent = glib::Object_Class;

    friend class ATContext;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
