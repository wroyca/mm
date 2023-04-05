// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/passwordentryrow.hxx>
#include <libmm/adw/passwordentryrow_p.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwPasswordEntryRow* object, bool take_copy) -> adw::PasswordEntryRow*
  {
    return dynamic_cast<adw::PasswordEntryRow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  PasswordEntryRow_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_password_entry_row_get_type ();
    }

    return *this;
  }

  auto
  PasswordEntryRow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new PasswordEntryRow ((AdwPasswordEntryRow*) (o)));
  }

  PasswordEntryRow::PasswordEntryRow (
      const glib::ConstructParams& construct_params)
    : adw::EntryRow (construct_params)
  {
  }

  PasswordEntryRow::PasswordEntryRow (AdwPasswordEntryRow* castitem)
    : adw::EntryRow ((AdwEntryRow*) (castitem))
  {
  }

  PasswordEntryRow::PasswordEntryRow (PasswordEntryRow&& src) noexcept
    : adw::EntryRow (std::move (src))
  {
  }

  auto
  PasswordEntryRow::operator= (PasswordEntryRow&& src) noexcept -> PasswordEntryRow&
  {
    adw::EntryRow::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      adw::EntryRow (glib::ConstructParams (passwordentryrow_class_.init ()))
  {
  }

} // namespace adw
