// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PASSWORDENTRYROW_H
#define _LIBADWAITAMM_PASSWORDENTRYROW_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-adw/preferencesrow.hxx>

#include <adwaita.h>
#include <libmm-adw/entryrow.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT PasswordEntryRow_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT PasswordEntryRow : public Adw::EntryRow
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PasswordEntryRow CppObjectType;
    typedef PasswordEntryRow_Class CppClassType;
    typedef AdwPasswordEntryRow BaseObjectType;
    typedef AdwPasswordEntryRowClass BaseClassType;
#endif

    PasswordEntryRow (PasswordEntryRow&& src) noexcept;
    auto
    operator= (PasswordEntryRow&& src) noexcept -> PasswordEntryRow&;

    PasswordEntryRow (const PasswordEntryRow&) = delete;
    auto
    operator= (const PasswordEntryRow&) -> PasswordEntryRow& = delete;

    ~PasswordEntryRow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class PasswordEntryRow_Class;
    static CppClassType passwordentryrow_class_;

  protected:
    explicit PasswordEntryRow (const Glib::ConstructParams& construct_params);
    explicit PasswordEntryRow (AdwPasswordEntryRow* castitem);

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
    PasswordEntryRow ();

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwPasswordEntryRow* object, bool take_copy = false) -> Adw::PasswordEntryRow*;
}

#endif
