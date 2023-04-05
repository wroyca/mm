// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gtk/accelerator.hxx>
#include <libmm/gtk/accelkey.hxx>

namespace gtk
{

  AccelKey::AccelKey ()
    : key_ (GDK_KEY_VoidSymbol),
      mod_ ((gdk::ModifierType) 0)
  {
  }

  AccelKey::AccelKey (guint accel_key,
                      gdk::ModifierType accel_mods,
                      const glib::ustring& accel_path)
    : key_ (accel_key),
      mod_ (accel_mods),
      path_ (accel_path)
  {
  }

  AccelKey::AccelKey (const glib::ustring& accelerator,
                      const glib::ustring& accel_path)
    : path_ (accel_path)
  {
    Accelerator::parse (accelerator, key_, mod_);
  }

  AccelKey::AccelKey (const AccelKey& src)
  {
    key_ = src.key_;
    mod_ = src.mod_;
    path_ = src.path_;
  }

  auto
  AccelKey::operator= (const AccelKey& src) -> AccelKey&
  {
    key_ = src.key_;
    mod_ = src.mod_;
    path_ = src.path_;

    return *this;
  }

  auto
  AccelKey::get_key () const -> guint
  {
    return key_;
  }

  auto
  AccelKey::get_mod () const -> gdk::ModifierType
  {
    return mod_;
  }

  auto
  AccelKey::get_path () const -> glib::ustring
  {
    return path_;
  }

  auto
  AccelKey::is_null () const -> bool
  {
    return ((key_ == GDK_KEY_VoidSymbol) || !(get_key () > 0));
  }

  auto
  AccelKey::get_abbrev () const -> glib::ustring
  {
    return Accelerator::name (key_, mod_);
  }

} // namespace gtk
