// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PASSWORDENTRYROW_P_H
#define _LIBADWAITAMM_PASSWORDENTRYROW_P_H

#include <libmm-adw/entryrow_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class PasswordEntryRow_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PasswordEntryRow;
    using BaseObjectType = AdwPasswordEntryRow;
    using CppClassParent = Adw::EntryRow_Class;

    friend class PasswordEntryRow;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
