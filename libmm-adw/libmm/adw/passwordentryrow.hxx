// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PASSWORDENTRYROW_H
#define _LIBADWAITAMM_PASSWORDENTRYROW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/preferencesrow.hxx>

#include <adwaita.h>
#include <libmm/adw/entryrow.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT password_entry_row_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT password_entry_row : public adw::entry_row
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef password_entry_row CppObjectType;
    typedef password_entry_row_class CppClassType;
    typedef AdwPasswordEntryRow BaseObjectType;
    typedef AdwPasswordEntryRowClass BaseClassType;
#endif

    password_entry_row (password_entry_row&& src) noexcept;
    auto
    operator= (password_entry_row&& src) noexcept -> password_entry_row&;

    password_entry_row (const password_entry_row&) = delete;
    auto
    operator= (const password_entry_row&) -> password_entry_row& = delete;

    ~password_entry_row () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class password_entry_row_class;
    static CppClassType passwordentryrow_class_;

  protected:
    explicit password_entry_row (const glib::ConstructParams& construct_params);
    explicit password_entry_row (AdwPasswordEntryRow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwPasswordEntryRow*
    {
      return reinterpret_cast<AdwPasswordEntryRow*> (gobject_);
    }

    auto
    gobj () const -> const AdwPasswordEntryRow*
    {
      return reinterpret_cast<AdwPasswordEntryRow*> (gobject_);
    }

  private:
  public:
    password_entry_row ();

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwPasswordEntryRow* object, bool take_copy = false) -> adw::password_entry_row*;
}

#endif
