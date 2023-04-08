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
  wrap (AdwPasswordEntryRow* object, bool take_copy) -> adw::password_entry_row*
  {
    return dynamic_cast<adw::password_entry_row*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  password_entry_row_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_password_entry_row_get_type ();
    }

    return *this;
  }

  auto
  password_entry_row_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new password_entry_row ((AdwPasswordEntryRow*) (o)));
  }

  password_entry_row::password_entry_row (
      const glib::ConstructParams& construct_params)
    : adw::entry_row (construct_params)
  {
  }

  password_entry_row::password_entry_row (AdwPasswordEntryRow* castitem)
    : adw::entry_row ((AdwEntryRow*) (castitem))
  {
  }

  password_entry_row::password_entry_row (password_entry_row&& src) noexcept
    : adw::entry_row (std::move (src))
  {
  }

  auto
  password_entry_row::operator= (password_entry_row&& src) noexcept -> password_entry_row&
  {
    adw::entry_row::operator= (std::move (src));
    return *this;
  }

  password_entry_row::~password_entry_row () noexcept
  {
    destroy_ ();
  }

  password_entry_row::CppClassType password_entry_row::passwordentryrow_class_;

  auto
  password_entry_row::get_type () -> GType
  {
    return passwordentryrow_class_.init ().get_type ();
  }

  auto
  password_entry_row::get_base_type () -> GType
  {
    return adw_password_entry_row_get_type ();
  }

  password_entry_row::password_entry_row ()
    : glib::ObjectBase (nullptr),
      adw::entry_row (glib::ConstructParams (passwordentryrow_class_.init ()))
  {
  }

} // namespace adw
