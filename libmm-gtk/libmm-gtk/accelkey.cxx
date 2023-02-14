

#include <libmm-gtk/accelerator.hxx>
#include <libmm-gtk/accelkey.hxx>

namespace Gtk
{

  AccelKey::AccelKey ()
    : key_ (GDK_KEY_VoidSymbol),
      mod_ ((Gdk::ModifierType) 0)
  {
  }

  AccelKey::AccelKey (const guint accel_key,
                      const Gdk::ModifierType accel_mods,
                      const Glib::ustring& accel_path)
    : key_ (accel_key),
      mod_ (accel_mods),
      path_ (accel_path)
  {
  }

  AccelKey::AccelKey (const Glib::ustring& accelerator,
                      const Glib::ustring& accel_path)
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
  AccelKey::operator= (const AccelKey& src) -> AccelKey& = default;

  auto
  AccelKey::get_key () const -> guint
  {
    return key_;
  }

  auto
  AccelKey::get_mod () const -> Gdk::ModifierType
  {
    return mod_;
  }

  auto
  AccelKey::get_path () const -> Glib::ustring
  {
    return path_;
  }

  auto
  AccelKey::is_null () const -> bool
  {
    return key_ == GDK_KEY_VoidSymbol || !(get_key () > 0);
  }

  auto
  AccelKey::get_abbrev () const -> Glib::ustring
  {
    return Accelerator::name (key_, mod_);
  }

} // namespace Gtk
