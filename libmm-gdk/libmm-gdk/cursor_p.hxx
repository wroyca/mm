// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CURSOR_P_H
#define _GDKMM_CURSOR_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gdk
{

  class GDKMM_API Cursor_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Cursor;
    using BaseObjectType = GdkCursor;
    using CppClassParent = Glib::Object_Class;

    friend class Cursor;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gdk

#endif
