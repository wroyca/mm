// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PASSWORDENTRYROW_P_H
#define _LIBADWAITAMM_PASSWORDENTRYROW_P_H

#include <libmm/adw/entryrow_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT password_entry_row_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = password_entry_row;
    using BaseObjectType = AdwPasswordEntryRow;
    using CppClassParent = adw::entry_row_class;

    friend class password_entry_row;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
