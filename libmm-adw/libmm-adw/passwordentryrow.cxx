// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/passwordentryrow.hxx>
#include <libmm-adw/passwordentryrow_p.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwPasswordEntryRow* object, bool take_copy) -> Adw::PasswordEntryRow*
  {
    return dynamic_cast<Adw::PasswordEntryRow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  PasswordEntryRow_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_password_entry_row_get_type ();
    }

    return *this;
  }

  auto
  PasswordEntryRow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new PasswordEntryRow ((AdwPasswordEntryRow*) (o)));
  }

  PasswordEntryRow::PasswordEntryRow (
      const Glib::ConstructParams& construct_params)
    : Adw::EntryRow (construct_params)
  {
  }

  PasswordEntryRow::PasswordEntryRow (AdwPasswordEntryRow* castitem)
    : Adw::EntryRow ((AdwEntryRow*) (castitem))
  {
  }

  PasswordEntryRow::PasswordEntryRow (PasswordEntryRow&& src) noexcept
    : Adw::EntryRow (std::move (src))
  {
  }

  auto
  PasswordEntryRow::operator= (PasswordEntryRow&& src) noexcept -> PasswordEntryRow&
  {
    Adw::EntryRow::operator= (std::move (src));
    return *this;
  }

  PasswordEntryRow::~PasswordEntryRow () noexcept
  {
    destroy_ ();
  }

  PasswordEntryRow::CppClassType PasswordEntryRow::passwordentryrow_class_;

  auto
  PasswordEntryRow::get_type () -> GType
  {
    return passwordentryrow_class_.init ().get_type ();
  }

  auto
  PasswordEntryRow::get_base_type () -> GType
  {
    return adw_password_entry_row_get_type ();
  }

  PasswordEntryRow::PasswordEntryRow ()
    : Glib::ObjectBase (nullptr),
      Adw::EntryRow (Glib::ConstructParams (passwordentryrow_class_.init ()))
  {
  }

} // namespace Adw
