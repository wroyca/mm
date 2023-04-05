// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CURSOR_P_H
#define _GDKMM_CURSOR_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Cursor_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Cursor;
    using BaseObjectType = GdkCursor;
    using CppClassParent = glib::Object_Class;

    friend class Cursor;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gdk

#endif
