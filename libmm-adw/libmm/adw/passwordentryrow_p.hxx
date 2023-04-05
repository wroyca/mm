// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PASSWORDENTRYROW_P_H
#define _LIBADWAITAMM_PASSWORDENTRYROW_P_H

#include <libmm/adw/entryrow_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT PasswordEntryRow_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PasswordEntryRow;
    using BaseObjectType = AdwPasswordEntryRow;
    using CppClassParent = adw::EntryRow_Class;

    friend class PasswordEntryRow;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
